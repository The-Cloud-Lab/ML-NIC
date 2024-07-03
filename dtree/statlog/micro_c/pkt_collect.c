#include <nfp.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>
#include <nfp/mem_bulk.h>
#include <nfp6000/nfp_mac.h>

#include <std/reg_utils.h>
#include <pkt/pkt.h>
#include <stdint.h>

#include <net/csum.h>
#include <net/eth.h>
#include <net/ip.h>
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

__remote SIGNAL remote_signal1;
__remote __xread uint32_t remote_xfer1;

__remote SIGNAL remote_signal2;
__remote __xread uint32_t remote_xfer2;

__remote SIGNAL remote_signal3;
__remote __xread uint32_t remote_xfer3;

__remote SIGNAL remote_signal4;
__remote __xread uint32_t remote_xfer4;

__remote SIGNAL remote_signal5;
__remote __xread uint32_t remote_xfer5;

__remote SIGNAL remote_signal6;
__remote __xread uint32_t remote_xfer6;

__remote SIGNAL remote_signal7;
__remote __xread uint32_t remote_xfer7;

__remote SIGNAL remote_signal8;
__remote __xread uint32_t remote_xfer8;

__remote SIGNAL remote_signal9;
__remote __xread uint32_t remote_xfer9;

__remote SIGNAL remote_signal10;
__remote __xread uint32_t remote_xfer10;

__remote SIGNAL remote_signal11;
__remote __xread uint32_t remote_xfer11;

__remote SIGNAL remote_signal12;
__remote __xread uint32_t remote_xfer12;

__remote SIGNAL remote_signal13;
__remote __xread uint32_t remote_xfer13;

__remote SIGNAL remote_signal14;
__remote __xread uint32_t remote_xfer14;

__remote SIGNAL remote_signal15;
__remote __xread uint32_t remote_xfer15;

__remote SIGNAL remote_signal16;
__remote __xread uint32_t remote_xfer16;

__remote SIGNAL remote_signal17;
__remote __xread uint32_t remote_xfer17;

__remote SIGNAL remote_signal18;
__remote __xread uint32_t remote_xfer18;

__remote SIGNAL remote_signal19;
__remote __xread uint32_t remote_xfer19;

__remote SIGNAL remote_signal20;
__remote __xread uint32_t remote_xfer20;

__remote SIGNAL remote_signal21;
__remote __xread uint32_t remote_xfer21;

__remote SIGNAL remote_signal22;
__remote __xread uint32_t remote_xfer22;

__remote SIGNAL remote_signal23;
__remote __xread uint32_t remote_xfer23;

__remote SIGNAL remote_signal24;
__remote __xread uint32_t remote_xfer24;

__remote SIGNAL remote_signal25;
__remote __xread uint32_t remote_xfer25;

__remote SIGNAL remote_signal26;
__remote __xread uint32_t remote_xfer26;

__remote SIGNAL remote_signal27;
__remote __xread uint32_t remote_xfer27;

__remote SIGNAL remote_signal28;
__remote __xread uint32_t remote_xfer28;

__remote SIGNAL remote_signal29;
__remote __xread uint32_t remote_xfer29;

__remote SIGNAL remote_signal30;
__remote __xread uint32_t remote_xfer30;

__remote SIGNAL remote_signal31;
__remote __xread uint32_t remote_xfer31;

__remote SIGNAL remote_signal32;
__remote __xread uint32_t remote_xfer32;

__remote SIGNAL remote_signal33;
__remote __xread uint32_t remote_xfer33;

__remote SIGNAL remote_signal34;
__remote __xread uint32_t remote_xfer34;

__remote SIGNAL remote_signal35;
__remote __xread uint32_t remote_xfer35;

__remote SIGNAL remote_signal36;
__remote __xread uint32_t remote_xfer36;

__visible SIGNAL complete_signal;
__visible __xread uint32_t complete_xfer;


__intrinsic void proc_pkt(__mem40 char *buf_addr, __gpr uint32_t buf_off) {
        
    // Extract the headers first before the payload
    __xread uint32_t pkt_buf[18];
    __xwrite uint32_t data_out[18];
    __lmem uint32_t src_buf[13];  // just store the headers
    __gpr struct pkt_hdr eh;
    __gpr uint32_t csum_prepend;
    __gpr int src_off = buf_off;
    __gpr int res;
    __gpr int len;

    // Extract the packet
    mem_read32(pkt_buf, buf_addr + buf_off - PKT_START_OFF, 52);

    /* Copy xfer register to a Local Memory buffer for easier extraction */
    reg_cp(src_buf, pkt_buf, sizeof(src_buf));
    src_off = PKT_START_OFF;

    /*
     * Handle the checksum prepend if configured
     */
#ifdef CFG_RX_CSUM_PREPEND
    /* read the MAC parsing info for CSUM (first 4B are timestamp) */
    csum_prepend = pkt_csum_read(pkt_buf, PKT_START_OFF + 4);
    src_off += MAC_PREPEND_BYTES;
    
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
    len = HE_RES_LEN_of(res);
    src_off += len;
    
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
        ((__lmem struct ip4_hdr *)(src_buf+6))->dst = eh.ip4.src;
        ((__lmem struct ip4_hdr *)(src_buf+6))->src = eh.ip4.dst;        
       

        // Retrieve payload from CTM and copy payload to data_out
        mem_read64(pkt_buf, buf_addr + buf_off + 50, 72);
        reg_cp(data_out, pkt_buf, 64);  // copy over feature 1 - 32
        reg_cp(data_out+16, pkt_buf+16, 8); // copy over features 33 - 36
        
        // Inform 32 - 1 that data is ready
        remote_me_reg_write_signal_remote(data_out, 32, 1, 0, 
                                          __xfer_reg_number(&remote_xfer1, __nfp_meid(32, 1)) + (__ctx() * 32), 
                                          sizeof(remote_xfer1), &local_signal); 
        
        // Inform 32 - 2 that data is ready
        remote_me_reg_write_signal_remote(data_out, 32, 2, 0, 
                                          __xfer_reg_number(&remote_xfer2, __nfp_meid(32, 2)) + (__ctx() * 32), 
                                          sizeof(remote_xfer2), &local_signal);
        
        // Inform 32 - 3 that data is ready
        remote_me_reg_write_signal_remote(data_out+1, 32, 3, 0, 
                                          __xfer_reg_number(&remote_xfer3, __nfp_meid(32, 3)) + (__ctx() * 32), 
                                          sizeof(remote_xfer3), &local_signal);
        
        // Inform 32 - 4 that data is ready
        remote_me_reg_write_signal_remote(data_out+1, 32, 4, 0, 
                                          __xfer_reg_number(&remote_xfer4, __nfp_meid(32, 4)) + (__ctx() * 32), 
                                          sizeof(remote_xfer4), &local_signal);
        
        // Inform 32 - 5 that data is ready
        remote_me_reg_write_signal_remote(data_out+2, 32, 5, 0, 
                                          __xfer_reg_number(&remote_xfer5, __nfp_meid(32, 5)) + (__ctx() * 32), 
                                          sizeof(remote_xfer5), &local_signal);
        
        // Inform 32 - 6 that data is ready
        remote_me_reg_write_signal_remote(data_out+2, 32, 6, 0, 
                                          __xfer_reg_number(&remote_xfer6, __nfp_meid(32, 6)) + (__ctx() * 32), 
                                          sizeof(remote_xfer6), &local_signal);
        
        // Inform 32 - 7 that data is ready
        remote_me_reg_write_signal_remote(data_out+3, 32, 7, 0, 
                                          __xfer_reg_number(&remote_xfer7, __nfp_meid(32, 7)) + (__ctx() * 32), 
                                          sizeof(remote_xfer7), &local_signal);
        
        // Inform 32 - 8 that data is ready
        remote_me_reg_write_signal_remote(data_out+3, 32, 8, 0, 
                                          __xfer_reg_number(&remote_xfer8, __nfp_meid(32, 8)) + (__ctx() * 32), 
                                          sizeof(remote_xfer8), &local_signal); 
        
        // Inform 32 - 9 that data is ready
        remote_me_reg_write_signal_remote(data_out+4, 32, 9, 0, 
                                          __xfer_reg_number(&remote_xfer9, __nfp_meid(32, 9)) + (__ctx() * 32), 
                                          sizeof(remote_xfer9), &local_signal);
        
        // Inform 32 - 10 that data is ready
        remote_me_reg_write_signal_remote(data_out+4, 32, 10, 0, 
                                          __xfer_reg_number(&remote_xfer10, __nfp_meid(32, 10)) + (__ctx() * 32), 
                                          sizeof(remote_xfer10), &local_signal);        
        
        // Inform 32 - 11 that data is ready
        remote_me_reg_write_signal_remote(data_out+5, 32, 11, 0, 
                                          __xfer_reg_number(&remote_xfer11, __nfp_meid(32, 11)) + (__ctx() * 32), 
                                          sizeof(remote_xfer11), &local_signal);
        
        // Inform 33 - 0 that data is ready
        remote_me_reg_write_signal_remote(data_out+5, 33, 0, 0, 
                                          __xfer_reg_number(&remote_xfer12, __nfp_meid(33, 0)) + (__ctx() * 32), 
                                          sizeof(remote_xfer12), &local_signal);         
        // Inform 33 - 1 that data is ready
        remote_me_reg_write_signal_remote(data_out+6, 33, 1, 0, 
                                          __xfer_reg_number(&remote_xfer13, __nfp_meid(33, 1)) + (__ctx() * 32), 
                                          sizeof(remote_xfer13), &local_signal); 
        
        // Inform 33 - 2 that data is ready
        remote_me_reg_write_signal_remote(data_out+6, 33, 2, 0, 
                                          __xfer_reg_number(&remote_xfer14, __nfp_meid(33, 2)) + (__ctx() * 32), 
                                          sizeof(remote_xfer14), &local_signal);
        
        // Inform 33 - 3 that data is ready
        remote_me_reg_write_signal_remote(data_out+7, 33, 3, 0, 
                                          __xfer_reg_number(&remote_xfer15, __nfp_meid(33, 3)) + (__ctx() * 32), 
                                          sizeof(remote_xfer15), &local_signal);
        
        // Inform 33 - 4 that data is ready
        remote_me_reg_write_signal_remote(data_out+7, 33, 4, 0, 
                                          __xfer_reg_number(&remote_xfer16, __nfp_meid(33, 4)) + (__ctx() * 32), 
                                          sizeof(remote_xfer16), &local_signal);
        
        // Inform 33 - 5 that data is ready
        remote_me_reg_write_signal_remote(data_out+8, 33, 5, 0, 
                                          __xfer_reg_number(&remote_xfer17, __nfp_meid(33, 5)) + (__ctx() * 32), 
                                          sizeof(remote_xfer17), &local_signal);
        
        // Inform 33 - 6 that data is ready
        remote_me_reg_write_signal_remote(data_out+8, 33, 6, 0, 
                                          __xfer_reg_number(&remote_xfer18, __nfp_meid(33, 6)) + (__ctx() * 32), 
                                          sizeof(remote_xfer18), &local_signal);
        
        // Inform 33 - 7 that data is ready
        remote_me_reg_write_signal_remote(data_out+9, 33, 7, 0, 
                                          __xfer_reg_number(&remote_xfer19, __nfp_meid(33, 7)) + (__ctx() * 32), 
                                          sizeof(remote_xfer19), &local_signal);
        
        // Inform 33 - 8 that data is ready
        remote_me_reg_write_signal_remote(data_out+9, 33, 8, 0, 
                                          __xfer_reg_number(&remote_xfer20, __nfp_meid(33, 8)) + (__ctx() * 32), 
                                          sizeof(remote_xfer20), &local_signal); 
        
        // Inform 33 - 9 that data is ready
        remote_me_reg_write_signal_remote(data_out+10, 33, 9, 0, 
                                          __xfer_reg_number(&remote_xfer21, __nfp_meid(33, 9)) + (__ctx() * 32), 
                                          sizeof(remote_xfer21), &local_signal);
        
        // Inform 33 - 10 that data is ready
        remote_me_reg_write_signal_remote(data_out+10, 33, 10, 0, 
                                          __xfer_reg_number(&remote_xfer22, __nfp_meid(33, 10)) + (__ctx() * 32), 
                                          sizeof(remote_xfer22), &local_signal);        
        
        // Inform 33 - 11 that data is ready
        remote_me_reg_write_signal_remote(data_out+11, 33, 11, 0, 
                                          __xfer_reg_number(&remote_xfer23, __nfp_meid(33, 11)) + (__ctx() * 32), 
                                          sizeof(remote_xfer23), &local_signal);      
        
        // Inform 34 - 0 that data is ready
        remote_me_reg_write_signal_remote(data_out+11, 34, 0, 0, 
                                          __xfer_reg_number(&remote_xfer24, __nfp_meid(34, 0)) + (__ctx() * 32), 
                                          sizeof(remote_xfer24), &local_signal);      
        
        // Inform 34 - 1 that data is ready
        remote_me_reg_write_signal_remote(data_out+12, 34, 1, 0, 
                                          __xfer_reg_number(&remote_xfer25, __nfp_meid(34, 1)) + (__ctx() * 32), 
                                          sizeof(remote_xfer25), &local_signal); 
        
        // Inform 34 - 2 that data is ready
        remote_me_reg_write_signal_remote(data_out+12, 34, 2, 0, 
                                          __xfer_reg_number(&remote_xfer26, __nfp_meid(34, 2)) + (__ctx() * 32), 
                                          sizeof(remote_xfer26), &local_signal);
        
        // Inform 34 - 3 that data is ready
        remote_me_reg_write_signal_remote(data_out+13, 34, 3, 0, 
                                          __xfer_reg_number(&remote_xfer27, __nfp_meid(34, 3)) + (__ctx() * 32), 
                                          sizeof(remote_xfer27), &local_signal);
        
        // Inform 34 - 4 that data is ready
        remote_me_reg_write_signal_remote(data_out+13, 34, 4, 0, 
                                          __xfer_reg_number(&remote_xfer28, __nfp_meid(34, 4)) + (__ctx() * 32), 
                                          sizeof(remote_xfer28), &local_signal);
        
        // Inform 34 - 5 that data is ready
        remote_me_reg_write_signal_remote(data_out+14, 34, 5, 0, 
                                          __xfer_reg_number(&remote_xfer29, __nfp_meid(34, 5)) + (__ctx() * 32), 
                                          sizeof(remote_xfer29), &local_signal);
        
        // Inform 34 - 6 that data is ready
        remote_me_reg_write_signal_remote(data_out+14, 34, 6, 0, 
                                          __xfer_reg_number(&remote_xfer30, __nfp_meid(34, 6)) + (__ctx() * 32), 
                                          sizeof(remote_xfer30), &local_signal);
        
        // Inform 34 - 7 that data is ready
        remote_me_reg_write_signal_remote(data_out+15, 34, 7, 0, 
                                          __xfer_reg_number(&remote_xfer31, __nfp_meid(34, 7)) + (__ctx() * 32), 
                                          sizeof(remote_xfer31), &local_signal);
        
        // Inform 34 - 8 that data is ready
        remote_me_reg_write_signal_remote(data_out+15, 34, 8, 0, 
                                          __xfer_reg_number(&remote_xfer32, __nfp_meid(34, 8)) + (__ctx() * 32), 
                                          sizeof(remote_xfer32), &local_signal);      
        
        // Inform 34 - 9 that data is ready
        remote_me_reg_write_signal_remote(data_out+16, 34, 9, 0, 
                                          __xfer_reg_number(&remote_xfer33, __nfp_meid(34, 9)) + (__ctx() * 32), 
                                          sizeof(remote_xfer33), &local_signal);
        
        // Inform 34 - 10 that data is ready
        remote_me_reg_write_signal_remote(data_out+16, 34, 10, 0, 
                                          __xfer_reg_number(&remote_xfer34, __nfp_meid(34, 10)) + (__ctx() * 32), 
                                          sizeof(remote_xfer34), &local_signal);        
        
        // Inform 34 - 11 that data is ready
        remote_me_reg_write_signal_remote(data_out+17, 34, 11, 0, 
                                          __xfer_reg_number(&remote_xfer35, __nfp_meid(34, 11)) + (__ctx() * 32), 
                                          sizeof(remote_xfer35), &local_signal); 
       
        // Inform 35 - 0 that data is ready
        remote_me_reg_write_signal_remote(data_out+17, 35, 0, 0, 
                                          __xfer_reg_number(&remote_xfer36, __nfp_meid(35, 0)) + (__ctx() * 32), 
                                          sizeof(remote_xfer36), &local_signal);  
        
        reg_cp(data_out, src_buf+2, 44);
        
        // Wait for 36 - 0 to finish
        __wait_for_all(&complete_signal);
        reg_cp(data_out+11, &complete_xfer, sizeof(complete_xfer));        
        mem_write64(data_out, buf_addr + buf_off + 6, 48);        
    }        
}

int main(void) {
    __mem40 char *pbuf;
    __xread struct nbi_meta_catamaran nbi_meta;
    __xread struct nbi_meta_pkt_info *pi = &nbi_meta.pkt_info;
    __gpr int in_port, out_port, pkt_off;
    __gpr struct pkt_ms_info msi;
    
    __assign_relative_register(&local_signal, 1);
    __assign_relative_register(&complete_signal, 10);
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
        out_port = in_port;
        pkt_nbi_send(pi->isl, pi->pnum, &msi,
                    pi->len - MAC_PREPEND_BYTES + 4,
                    NBI, PORT_TO_TMQ(out_port),
                    nbi_meta.seqr, nbi_meta.seq, PKT_CTM_SIZE_256);
    }
    
    return 0;
}