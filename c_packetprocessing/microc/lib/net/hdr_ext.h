    /*
 * Copyright 2012-2016 Netronome, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file          lib/net/hdr_ext.h
 * @brief         Header extract
 *
 *
 * This header extract implementation extracts protocol headers from a
 * packet buffer and parses enough of the header to determine the type
 * of the next header (if any) and its offset.  This would normally be
 * a relatively trivial task (like overlaying a struct over some
 * memory containing the packet header), however to implement this
 * efficiently on the NFP is a little more complex.
 *
 * A packet buffer from which to extract a header from may be held in
 * different locations.  For example, one could try to extract certain
 * protocol headers directly from a buffer in DRAM.  This may lead to
 * a higher number of memory transactions than one might want to
 * perform.  Alternatively, one might want to read in chunks from the
 * start of a packet buffer from DRAM (or other memory) into local
 * registers and parse the packet header from there to extract the
 * various protocol headers.  This would reduce the number of memory
 * transactions performed per packet.  However, when extracting
 * certain protocol headers from (a portion of) the packet buffer
 * located in local register caution must be taken as different NFP
 * register types provide more or less flexibility in accessing arrays
 * at arbitrary indices (which is required to parse packet headers).
 *
 * A Ethernet frame may have a VLAN tag, in which case the next header
 * starts at offset 18Bytes while without VLAN header, the next header
 * starts at offset 14Bytes.  Likewise, IP headers may have option or
 * extension headers, resulting the next protocol header being located
 * at different offsets.  The offset of the next header can only be
 * determined at runtime.  On the NFP, arrays (such as packet buffers)
 * located in registers, may not be indexable by runtime values
 * *depending* on the register type.  Local Memory is fully indexable,
 * GPRs and NN registers are not at all (but one can use compile time
 * constants), Xfer are somewhat indexable by runtime values, but not
 * in a generic enough way that the C compiler could generate code for
 * it.
 *
 * The APIs defined in this header file are designed to hide this
 * complexity from the user.  Depending on the storage location of the
 * buffer, more or less efficient code is generated.
 */

#ifndef _HDR_EXT_H_
#define _HDR_EXT_H_

#include <nfp.h>
#include <assert.h>

#include <net/eth.h>
#include <net/icmp.h>
#include <net/ip.h>
#include <net/udp.h>
#include <net/tcp.h>
#include <net/sctp.h>

/*
 * All header extract functions follow the same pattern.  They all
 * require the following arguments:
 * - src_buf:    A pointer to the source buffer
 * - off:        A offset into the source buffer where the header starts
 * - dst:        A pointer to a buffer in which the header is stored.  The
 *               size/type of this buffer is depended on the protocol.
 *
 * @dst is expected to be 32bit aligned and being constant at compile
 * time, while the offset based on @src_buf and @off from which to extract
 * the header maybe arbitrarily aligned and may only be determined at
 * runtime.
 *
 * All functions return the following values:
 * - len:        Length of this header. Note this may include additional
 *               options/extension headers not extracted.
 * - next_proto: The type of the next protocol header if present and known.
 *
 * The result is encoded in a single unsigned int return value,
 * because we can't pass a pointer to a __gpr into a functions (sigh)
 *
 *
 * The header extract function only extract the standard header, i.e.,
 * if an application is interested in the content of optional fields,
 * such as in IPv4 options or IPv6 extensions header it is up to the
 * application to parse them.  The header extract function, do however
 * handle parsing of packet headers with optional fields.
 *
 * The pointers are 'void *' to allow the implementation to specialise
 * depending on the storage type.  As explained above different
 * storage types may be require different implementations, some of
 * which can not be automatically generated by the C compiler.
 * Hopefully, an error will be generated for unsupported combinations.
 *
 * All functions assume that the source buffer passed in is large
 * enough to contain the entire standard protocol header.  To help the
 * calling code to determine this, utility functions
 * (he_<proto>_fit()) are provided, which determine if a source buffer
 * of a given size, still has enough space from the current offset to
 * contain the protocol header.
 */


/* Macros to encode and decode the result value */
#define HE_RES(_np, _l)      ((((_np) & 0xffff) << 16) | ((_l) & 0xffff))
#define HE_RES_LEN_of(_x)    (((_x) & 0xffff))
#define HE_RES_PROTO_of(_x)  (((unsigned int)_x) >> 16)


/**
 * Indication of the protocol in the next header
 *
 * The IPv6 extension header are arranged such that one can simply can
 * check with @HE_IP6_EXT (ie bit 8 set) for any of the header, if one
 * wants to skip them.
 */
enum he_proto {
    HE_NONE =        0x0,   /**  0: No more headers, just data */
    HE_ETHER,               /**  1: Ethernet header */
    HE_8021Q,               /**  2: 802.1Q (VLAN) header */
    HE_ARP,                 /**  3: ARP header */
    HE_IP4,                 /**  4: IPv4 header */
    HE_IP6,                 /**  5: IPv6 header */
    HE_TCP,                 /**  6: TCP header */
    HE_UDP,                 /**  7: UDP header */
    HE_GRE,                 /**  8: GRE header */
    HE_VXLAN,               /**  9: VXLAN header */
    HE_ESP,                 /** 10: ESP header */
    HE_MPLS,                /** 11: MPLS header */
    HE_ICMP,                /** 12: ICMP/ICMPV6 header */
    HE_SCTP,                /** 13: SCTP header */
    HE_AH,                  /** 14: AH header */

    HE_IP6_EXT =     0x100, /** IPv6 Extension header */
    HE_IP6_HBH =     0x101, /** IPv6 Hop-by-Hop Options header */
    HE_IP6_RT =      0x102, /** IPv6 Routing Extension header */
    HE_IP6_FRAG =    0x103, /** IPv6 Fragmentation header */
    HE_IP6_NONE =    0x104, /** IPv6 No Next Header header */
    HE_IP6_DST =     0x105, /** IPv6 Destination Options header */
    HE_IP6_MOB =     0x106, /** IPv6 Mobility Extension header */
    HE_IP6_HOST_ID = 0x107, /** IPv6 Host Identity Extension header */
    HE_IP6_SHIM6 =   0x108, /** IPv6 Shim6 Extension header */

    HE_NON_PROTO =   0x8000, /** Start of non-proto return vals */

    HE_ERROR =              0xe000, /** General error */
    HE_ERROR_IP4_BAD_VER =  0xe001, /** Invalid IP version */
    HE_ERROR_IP4_BAD_HL =   0xe002, /** Invalid header length */
    HE_ERROR_IP4_BAD_TTL =  0xe003, /** Invalid TTL */

    HE_ERROR_IP6_BAD_VER =          0xe010, /** Invalid IP version */
    HE_ERROR_IP6_BAD_HOP_LIMIT =    0xe011, /** Invalid Hop Limit */

    HE_UNKNOWN =     0xffff, /** Unknown/unhandled header */

    /* MAX he_proto value is 16 bits */
};

#define HE_RESULT_IS_PROTO(res)         (((res) & 0x80000000) == 0)
#define HE_RESULT_IS_ERROR(res)         (((res) >> 28) == 0xe)
#define HE_RESULT_IS_UNKNOWN(res)       (((res) >> 28) == 0xf)
#define HE_RESULT_IS_UNK_OR_ERR(res)    (((res) >> 29) == 0x7)

#define HE_PROTO_IS_PROTO(proto)        (((proto) & 0x8000) == 0)
#define HE_PROTO_IS_ERROR(proto)        (((proto) >> 12) == 0xe)
#define HE_PROTO_IS_UNKNOWN(proto)      (((proto) >> 12) == 0xf)
#define HE_PROTO_IS_UNK_OR_ERR(proto)   (((proto) >> 13) == 0x7)

/**
 * Check if the buffer of size @sz with current offset @off has
 * enough space to contain a Ethernet header.
 */
__intrinsic int he_eth_fit(sz, off);

/**
 * Extract an Ethernet header starting from an offset in the buffer.
 * @param src_buf  Source buffer
 * @param off      Byte offset within the @src_buf where the Ethernet
 *                 header starts
 * @param dst      Pointer to buffer in to which to return the extracted header
 * @return         Length and next protocol header indication.
 *
 * @dst must point to a struct eth_hdr or larger.
 * The length encoded in the return value is: sizeof(struct eth_hdr).
 * The next protocol encoded in the return value is one of HE_8021Q,
 * HE_IP4, HE_IP6, HE_MPLS or HE_UNKNOWN.
 */
__intrinsic unsigned int he_eth(void *src_buf, int off, void *dst);

/**
 * Check if the buffer of size @sz with current offset @off has
 * enough space to contain a 802.1Q (VLAN) header.
 */
__intrinsic int he_vlan_fit(sz, off);

/**
 * Extract an 802.1Q (VLAN) header starting from an offset in the buffer.
 * @param src_buf  Source buffer
 * @param off      Byte offset within @src_buf where the VLAN header starts
 * @param dst      Pointer to buffer in to which to return the extracted header
 * @return         Length and next protocol header indication.
 *
 * @dst must point to a struct vlan_hdr or larger.
 * The length encoded in the return value is: sizeof(struct vlan_hdr).
 * The next protocol encoded in the return value is one of HE_IP4,
 * HE_IP6, HE_MPLS or HE_UNKNOWN.
 */
__intrinsic unsigned int he_vlan(void *src_buf, int off, void *dst);

/**
 * Check if a buffer of size @sz with current offset @off has
 * enough space to contain an ARP header.
 */
__intrinsic int he_arp_fit(sz, off);

/**
 * Extract a ARP header starting from an offset in the buffer.
 * @param src_buf  Source buffer
 * @param off      Byte offset within @src_buf where the ARP header starts
 * @param dst      Pointer to buffer in to which to return the extracted header
 * @return         Length and next protocol header indication.
 *
 * @dst must point to a struct arp_hdr or larger.
 * The next protocol encoded in the return value is HE_NONE
 * The length encoded in the return value is sizeof(struct arp_hdr).
 */
__intrinsic unsigned int he_arp(void *src_buf, int off, void *dst);


/**
 * Check if the buffer of size @sz with current offset @off has
 * enough space to contain a IPv4 header.
 */
__intrinsic int he_ip4_fit(sz, off);

/**
 * Extract an IPv4 header starting from an offset in the buffer.
 * @param src_buf  Source buffer
 * @param off      Byte offset within @src_buf where the IPv4 header starts
 * @param dst      Pointer to buffer in to which to return the extracted header
 * @return         Length and next protocol header indication.
 *
 * @dst must point to a struct ip4_hdr or larger.
 * The length encoded in the return value is: sizeof(struct ip4_hdr) + options.
 * The next protocol encoded in the return value is one of HE_TCP,
 * HE_UDP, HE_GRE, HE_ESP or HE_UNKNOWN.
 *
 * If the IP packet is fragmented and is from the middle of a packet,
 * ie the MF bit is set, this function returns HE_UNKNOWN as the IP
 * payload does not contain any further protocol headers.
 */
__intrinsic unsigned int he_ip4(void *src_buf, int off, void *dst);


/**
 * Check if the buffer of size @sz with current offset @off has
 * enough space to contain a IPv6 header.
 */
__intrinsic int he_ip6_fit(sz, off);

/**
 * Extract an IPv6 header starting from an offset in the buffer.
 * @param src_buf  Source buffer
 * @param off      Byte offset within @src_buf where the IPv6 header starts
 * @param dst      Pointer to buffer in to which to return the extracted header
 * @return         Length and next protocol header indication.
 *
 * @dst must point to a struct ip6_hdr or larger.
 * The length encoded in the return value is: sizeof(struct ip6_hdr).
 * The next protocol encoded in the return value is one of HE_TCP,
 * HE_UDP, HE_GRE, HE_ESP, HE_IP6_HBH, HE_IP6_RT, HE_IP6_FRAG,
 * HE_IP6_NONE, HE_IP6_DST, or HE_UNKNOWN.
 */
__intrinsic unsigned int he_ip6(void *src_buf, int off, void *dst);


/**
 * Check if the buffer of size @sz with current offset @off has
 * enough space to contain a TCP header.
 */
__intrinsic int he_tcp_fit(sz, off);

/**
 * Extract an TCP header starting from an offset in the buffer.
 * @param src_buf  Source buffer
 * @param off      Byte offset within @src_buf where the TCP header starts
 * @param dst      Pointer to buffer in to which to return the extracted header
 * @return         Length and next protocol header indication.
 *
 * @dst must point to a struct tcp_hdr or larger.
 * The length encoded in the return value is: sizeof(struct tcp_hdr) + options.
 * The next protocol encoded in the return value is one of HE_NONE, HE_UNKNOWN.
 */
__intrinsic unsigned int he_tcp(void *src_buf, int off, void *dst);


/**
 * Check if the buffer of size @sz with current offset @off has
 * enough space to contain a UDP header.
 */
__intrinsic int he_udp_fit(sz, off);

/**
 * Extract an UDP header starting from an offset in the buffer.
 * @param src_buf   Source buffer
 * @param off       Byte offset within @src_buf where the UDP header starts
 * @param dst       Pointer to buffer in to which to return the extracted header
 * @param vxln_prt  UDP port that VXLAN uses, 0 for no VXLAN checking
 * @return          Length and next protocol header indication.
 *
 * @dst must point to a struct udp_hdr or larger.
 * The length encoded in the return value is: sizeof(struct udp_hdr).
 * The next protocol encoded in the return value is one of HE_VXLAN or HE_NONE.
 * (depending on the dst port being passed in the VXLAN port)
 *
 * Note: the VXLAN RFC defines UDP dst port 4789 while Linux uses 8472 by
 * default. This library call is configurable to accommodate any port.
 */
__intrinsic unsigned int he_udp(void *src_buf, int off,
                                void *dst, unsigned int vxln_prt);


/**
 * Check if a buffer of size @sz with current offset @off has
 * enough space to contain a full GRE header with all optional fields.
 */
__intrinsic int he_gre_fit(sz, off);

/**
 * Extract a GRE header starting from an offset in the buffer.
 * @param src_buf  Source buffer
 * @param off      Byte offset within @src_buf where the GRE header starts
 * @param dst      Pointer to buffer in to which to return the extracted header
 * @return         Length and next protocol header indication.
 *
 * @dst must point to a struct gre_hdr or larger.
 * The next protocol encoded in the return value is one of HE_ETHER or
 * HE_IP4, HE_IP6, HE_MPLS or HE_UNKNOWN.
 * The length encoded in the return value is the complete GRE header.
 * Note this function only extracts the mandatory struct gre_hdr. Those
 * interested in the optional header fields should either use one of the
 * functions provided or extract it manually.
 */
__intrinsic unsigned int he_gre(void *src_buf, int off, void *dst);

/**
 * Extract a NVGRE extension header starting from an offset in the buffer.
 * @param src_buf  Source buffer
 * @param off      Byte offset within @src_buf where the GRE header starts
 * @param dst      Pointer to buffer in to which to return the extracted header
 *
 * @dst must point to a struct nvgre_ext_hdr or larger.
 */
__intrinsic void he_gre_nvgre(void *src_buf, int off, void *dst);


/**
 * Check if a buffer of size @sz with current offset @off has
 * enough space to contain a VXLAN header.
 */
__intrinsic int he_vxlan_fit(sz, off);

/**
 * Extract a VXLAN header starting from an offset in the buffer.
 * @param src_buf  Source buffer
 * @param off      Byte offset within @src_buf where the VXLAN header starts
 * @param dst      Pointer to buffer in to which to return the extracted header
 * @return         Length and next protocol header indication.
 *
 * @dst must point to a struct vxlan_hdr or larger.
 * The next protocol encoded in the return value is HE_ETHER
 * The length encoded in the return value is: sizeof(struct vxlan_hdr)
 */
__intrinsic unsigned int he_vxlan(void *src_buf, int off, void *dst);


/**
 * Check if a buffer of size @sz with current offset @off has
 * enough space to contain a MPLS header.
 */
__intrinsic int he_mpls_fit(sz, off);

/**
 * Extract a MPLS header starting from an offset in the buffer.
 * @param src_buf  Source buffer
 * @param off      Byte offset within @src_buf where the MPLS header starts
 * @param dst      Pointer to buffer in to which to return the extracted header
 * @return         Length and next protocol header indication.
 *
 * @dst must point to a struct mpls_hdr or larger.
 * The next protocol encoded in the return value is HE_NONE
 * The length encoded in the return value is: sizeof(struct mpls_hdr)
 */
__intrinsic unsigned int he_mpls(void *src_buf, int off, void *dst);


/**
 * Check if the buffer of size @sz with current offset @off has
 * enough space to contain a SCTP header.
 */
__intrinsic int he_sctp_fit(sz, off);

/**
 * Extract an SCTP header starting from an offset in the buffer.
 * @param src_buf  Source buffer
 * @param off      Byte offset within the @src_buf where the SCTP
 *                 header starts
 * @param dst      Pointer to buffer in to which to return the extracted header
 * @return         Length and next protocol header indication.
 *
 * @dst must point to a struct sctp_hdr or larger.
 * The length encoded in the return value is: sizeof(struct sctp_hdr).
 */
__intrinsic unsigned int he_sctp(void *src_buf, int off, void *dst);


/**
 * Check if the buffer of size @sz with current offset @off has
 * enough space to contain a ICMP or ICMPv6 header.
 */
__intrinsic int he_icmp_fit(sz, off);

/**
 * Extract an ICMP or ICMPv6 header starting from an offset in the buffer.
 * @param src_buf  Source buffer
 * @param off      Byte offset within the @src_buf where the ICMP
 *                 header starts
 * @param dst      Pointer to buffer in to which to return the extracted header
 * @return         Length and next protocol header indication.
 *
 * @dst must point to a struct icmp_hdr or larger.
 * The length encoded in the return value is: sizeof(struct icmp_hdr).
 */
__intrinsic unsigned int he_icmp(void *src_buf, int off, void *dst);

/**
 * Check if the buffer of size @sz with current offset @off has
 * enough space to contain a ESP header.
 */
__intrinsic int he_esp_fit(sz, off);

/**
 * Extract an ESP header starting from an offset in the buffer.
 * @param src_buf  Source buffer
 * @param off      Byte offset within the @src_buf where the ESP
 *                 header starts
 * @param dst      Pointer to buffer in to which to return the extracted header
 * @return         Length and next protocol header indication.
 *
 * @dst must point to a struct esp_hdr or larger.
 * The length encoded in the return value is: sizeof(struct esp_hdr).
 */
__intrinsic unsigned int he_esp(void *src_buf, int off, void *dst);

/**
 * Check if the buffer of size @sz with current offset @off has
 * enough space to contain a AH header.
 */
__intrinsic int he_ah_fit(sz, off);

/**
 * Extract an AH header starting from an offset in the buffer.
 * @param src_buf  Source buffer
 * @param off      Byte offset within the @src_buf where the AH
 *                 header starts
 * @param dst      Pointer to buffer in to which to return the extracted header
 * @return         Length and next protocol header indication.
 *
 * @dst must point to a struct ah_hdr or larger.
 * The length encoded in the return value is: sizeof(struct ah_hdr).
 */
__intrinsic unsigned int he_ah(void *src_buf, int off, void *dst);

#endif /* _HDR_EXT_H_ */
