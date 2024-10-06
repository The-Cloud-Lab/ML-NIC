#include <nfp.h>
#include <nfp/remote_me.h>
#include <nfp/mem_bulk.h>
#include <nfp/cls.h>
#include <nfp6000/nfp_mac.h>


#include <std/reg_utils.h>
#include <pkt/pkt.h>
#include <stdint.h>

#include <net/csum.h>
#include <net/eth.h>
#include <net/ip.h>
#include <net/tcp.h>
#include <net/udp.h>
#include <net/icmp.h>
#include <net/hdr_ext.h>

#include "config.h"

/*
Read packet data from memory in xfer registers as a two byte
offset so that the payload get aligned to a word boundary. This
makes the header extraction code more efficient.
*/
#define PKT_START_OFF 2


/* A structure used for extracting, the different protocol header  */
struct pkt_hdr {
    struct eth_hdr  eth;
    struct ip4_hdr  ip4;
};

// Signals for interacting with other MEs
SIGNAL local_signal;

__remote SIGNAL remote_signal2;
__remote __xread uint32_t remote_xfer2;

__remote SIGNAL remote_signal3;
__remote __xread uint32_t remote_xfer3;

__remote SIGNAL remote_signal4;
__remote __xread uint32_t remote_xfer4;

__remote SIGNAL remote_signal6;
__remote __xread uint32_t remote_xfer6;

__remote SIGNAL remote_signal7;
__remote __xread uint32_t remote_xfer7;

__visible SIGNAL complete_signal;
__visible __xread uint32_t complete_xfer;


__intrinsic void proc_pkt(__mem40 char *buf_addr, __gpr uint32_t buf_off) {
        
    // Extract the headers only
    __xread uint32_t pkt_buf[16]; 
    __xwrite uint32_t data_out[16];
    __lmem uint32_t src_buf[16];
    __gpr struct pkt_hdr eh;
    __gpr uint32_t csum_prepend;
    __gpr int src_off = buf_off;
    __gpr int res;
    
    // Extract the packet
    mem_read64(pkt_buf, buf_addr + buf_off - PKT_START_OFF, sizeof(pkt_buf));

    /* Copy xfer register to a Local Memory buffer for easier extraction */
    reg_cp(src_buf, pkt_buf, 64);
    src_off = PKT_START_OFF;

    /*
     * Handle the checksum prepend if configured
     */
#ifdef CFG_RX_CSUM_PREPEND
    /* read the MAC parsing info for CSUM (first 2B are garbage and next 4B are timestamp) */
    csum_prepend = pkt_csum_read(pkt_buf, PKT_START_OFF + 4);
    src_off += MAC_PREPEND_BYTES;  // move past checksum and timestamp
    
    if (NFP_MAC_RX_CSUM_L3_SUM_of(csum_prepend) ==
        NFP_MAC_RX_CSUM_L3_IPV4_FAIL) {
        /* L3 checksum is wrong */
        return;
    }

    if ((NFP_MAC_RX_CSUM_L4_SUM_of(csum_prepend) ==
         NFP_MAC_RX_CSUM_L4_TCP_FAIL) ||
        (NFP_MAC_RX_CSUM_L4_SUM_of(csum_prepend) ==
         NFP_MAC_RX_CSUM_L4_UDP_FAIL)){
        /* L4 checksum is wrong */
        return;
    }
#endif

    // Layer 2 Extraction
    res = he_eth(src_buf, src_off, &eh.eth);
    src_off += HE_RES_LEN_of(res);
    
    // Check if ethernet header is correct
    if (((__gpr uint16_t *)&eh.eth.dst)[0] == 0x0015
        && ((__gpr uint16_t *)&eh.eth.dst)[1] == 0x4d13
        && ((__gpr uint16_t *)&eh.eth.dst)[2] == 0x79ac
        && net_eth_is_uc_addr(&eh.eth.src) 
        && eh.eth.type == 0x4d49) {
        
        
        // Edit Ethernet Header
        ((__lmem struct eth_hdr *)((__lmem char *)src_buf+10))->dst = eh.eth.src;
        ((__lmem struct eth_hdr *)((__lmem char *)src_buf+10))->src = eh.eth.dst;
        ((__lmem struct eth_hdr *)((__lmem char *)src_buf+10))->type = 0x4d4f;
                    
        // Edit IP Header
        res = he_ip4(src_buf, src_off, &eh.ip4);
        src_off += HE_RES_LEN_of(res);
        ((__lmem struct ip4_hdr *)(src_buf+6))->dst = eh.ip4.src;
        ((__lmem struct ip4_hdr *)(src_buf+6))->src = eh.ip4.dst;
        
        
        // Feature values depend whether UDP, TCP, ICMP, or IGMP
        if (eh.ip4.proto == 0x6) {  // dealing with TCP
            reg_cp(data_out, src_buf+1, 60);
            

            // Inform ME 1 that data is ready (ipv4 protocol)
            remote_me_reg_write_signal_remote(data_out+7, 33, 1, 0, 
                                              __xfer_reg_number(&remote_xfer2, __nfp_meid(33, 1)) + (__ctx() * 32), 
                                              sizeof(remote_xfer2), &local_signal);

            // Inform ME 2 that data is ready (ipv4 flags)
            remote_me_reg_write_signal_remote(data_out+6, 33, 2, 0, 
                                              __xfer_reg_number(&remote_xfer3, __nfp_meid(33, 2)) + (__ctx() * 32), 
                                              sizeof(remote_xfer3), &local_signal);

            // Inform ME 3 that data is ready (tcp destination port)
            remote_me_reg_write_signal_remote(data_out+10, 33, 3, 0, 
                                              __xfer_reg_number(&remote_xfer4, __nfp_meid(33, 3)) + (__ctx() * 32), 
                                              sizeof(remote_xfer4), &local_signal);     
            
            // Inform ME 4 that data is ready (ipv4 total packet length)
            remote_me_reg_write_signal_remote(data_out+5, 33, 4, 0, 
                                              __xfer_reg_number(&remote_xfer6, __nfp_meid(33, 4)) + (__ctx() * 32), 
                                              sizeof(remote_xfer6), &local_signal); 
            
            // Inform ME 5 that data is ready (tcp flags)
            remote_me_reg_write_signal_remote(data_out+13, 33, 5, 0, 
                                              __xfer_reg_number(&remote_xfer7, __nfp_meid(33, 5)) + (__ctx() * 32), 
                                              sizeof(remote_xfer7), &local_signal); 
            
            // Wait for ME 6 to finish
            __wait_for_all(&complete_signal);
            reg_cp(data_out+15, &complete_xfer, sizeof(complete_xfer));
            mem_write64(data_out, buf_addr + buf_off + PKT_START_OFF, 64);                
            
        } else if (eh.ip4.proto == 0x11) {  // dealing with a udp packet
            reg_cp(data_out, src_buf+2, 44);
            reg_zero(data_out+11, 4);

            // Inform ME 1 that data is ready (ipv4 protocol)
            remote_me_reg_write_signal_remote(data_out+6, 33, 1, 0, 
                                              __xfer_reg_number(&remote_xfer2, __nfp_meid(33, 1)) + (__ctx() * 32), 
                                              sizeof(remote_xfer2), &local_signal);

            // Inform ME 2 that data is ready (ipv4 flags)
            remote_me_reg_write_signal_remote(data_out+5, 33, 2, 0, 
                                              __xfer_reg_number(&remote_xfer3, __nfp_meid(33, 2)) + (__ctx() * 32), 
                                              sizeof(remote_xfer3), &local_signal);

            // Inform ME 3 that data is ready (tcp destination port)
            remote_me_reg_write_signal_remote(data_out+11, 33, 3, 0, 
                                              __xfer_reg_number(&remote_xfer4, __nfp_meid(33, 3)) + (__ctx() * 32), 
                                              sizeof(remote_xfer4), &local_signal);     
            
            // Inform ME 4 that data is ready (ipv4 total packet length)
            remote_me_reg_write_signal_remote(data_out+4, 33, 4, 0, 
                                              __xfer_reg_number(&remote_xfer6, __nfp_meid(33, 4)) + (__ctx() * 32), 
                                              sizeof(remote_xfer6), &local_signal); 
            
            // Inform ME 5 that data is ready (tcp flags)
            remote_me_reg_write_signal_remote(data_out+11, 33, 5, 0, 
                                              __xfer_reg_number(&remote_xfer7, __nfp_meid(33, 5)) + (__ctx() * 32), 
                                              sizeof(remote_xfer7), &local_signal); 
            
            // Wait for ME 6 to finish
            __wait_for_all(&complete_signal);
            reg_cp(data_out+11, &complete_xfer, sizeof(complete_xfer));
            mem_write64(data_out, buf_addr + buf_off + 6, 48);    
            
        } else if (eh.ip4.proto == 0x1 || eh.ip4.proto == 0x2) {  // dealing with ICMP or IGMP packet
            reg_cp(data_out, src_buf+1, 44);
            reg_zero(data_out+11, 4);

            // Inform ME 1 that data is ready (ipv4 protocol)
            remote_me_reg_write_signal_remote(data_out+7, 33, 1, 0, 
                                              __xfer_reg_number(&remote_xfer2, __nfp_meid(33, 1)) + (__ctx() * 32), 
                                              sizeof(remote_xfer2), &local_signal);

            // Inform ME 2 that data is ready (ipv4 flags)
            remote_me_reg_write_signal_remote(data_out+6, 33, 2, 0, 
                                              __xfer_reg_number(&remote_xfer3, __nfp_meid(33, 2)) + (__ctx() * 32), 
                                              sizeof(remote_xfer3), &local_signal);

            // Inform ME 3 that data is ready (tcp destination port)
            remote_me_reg_write_signal_remote(data_out+11, 33, 3, 0, 
                                              __xfer_reg_number(&remote_xfer4, __nfp_meid(33, 3)) + (__ctx() * 32), 
                                              sizeof(remote_xfer4), &local_signal);     
            
            // Inform ME 4 that data is ready (ipv4 total packet length)
            remote_me_reg_write_signal_remote(data_out+5, 33, 4, 0, 
                                              __xfer_reg_number(&remote_xfer6, __nfp_meid(33, 4)) + (__ctx() * 32), 
                                              sizeof(remote_xfer6), &local_signal); 
            
            // Inform ME 5 that data is ready (tcp flags)
            remote_me_reg_write_signal_remote(data_out+11, 33, 5, 0, 
                                              __xfer_reg_number(&remote_xfer7, __nfp_meid(33, 5)) + (__ctx() * 32), 
                                              sizeof(remote_xfer7), &local_signal); 
            
            // Wait for ME 6 to finish
            __wait_for_all(&complete_signal);
            reg_cp(data_out+11, &complete_xfer, sizeof(complete_xfer));
            mem_write64(data_out, buf_addr + buf_off + PKT_START_OFF, 48);    
        }
    }    
}

int main(void) {
    __mem40 char *pbuf;
    __xread struct nbi_meta_catamaran nbi_meta;
    __xread struct nbi_meta_pkt_info *pi = &nbi_meta.pkt_info;
    __gpr int in_port, pkt_off;
    __gpr struct pkt_ms_info msi;
    
    __assign_relative_register(&local_signal, 1);
    __assign_relative_register(&complete_signal, 7);
    __implicit_write(&complete_signal, sizeof(complete_signal));
    __implicit_write(&complete_xfer, sizeof(complete_xfer));
    
    for(;;) {
        /* Receive packet */
        pkt_nbi_recv(&nbi_meta, sizeof(nbi_meta)); 
        in_port = MAC_TO_PORT(nbi_meta.port);
        pbuf = pkt_ctm_ptr40(pi->isl, pi->pnum, 0);
        
        /* Collect features from pkt */
        pkt_off = PKT_NBI_OFFSET;
        proc_pkt(pbuf, pkt_off);
        
        /* Send packet */
        // Write the MAC egress CMD and adjust offset and len as needed
        pkt_off += MAC_PREPEND_BYTES;
        pkt_mac_egress_cmd_write(pbuf, pkt_off, 1, 1);
        
        pkt_off -= 4;
        msi = pkt_msd_write(pbuf, pkt_off);
        pkt_nbi_send(pi->isl, pi->pnum, &msi,
                    pi->len - MAC_PREPEND_BYTES + 4,
                    NBI, PORT_TO_TMQ(in_port),
                    nbi_meta.seqr, nbi_meta.seq, PKT_CTM_SIZE_256);
    }
    
    return 0;
}
