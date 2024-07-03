/* -*- P4_16 -*- */
#include <core.p4>
#include <v1model.p4>

/*************************************************************************
*********************** H E A D E R S  ***********************************
*************************************************************************/

typedef bit<48> macAddr_t;
typedef bit<32> ip4Addr_t;

header ethernet_t {
    macAddr_t dstAddr;
    macAddr_t srcAddr;
    bit<16>   etherType;
}

header ipv4_t {
    bit<4>    version;
    bit<4>    ihl;
    bit<8>    diffserv;
    bit<16>   totalLen;
    bit<16>   identification;
    bit<3>    flags;
    bit<13>   fragOffset;
    bit<8>    ttl;
    bit<8>    protocol;
    bit<16>   hdrChecksum;
    ip4Addr_t srcAddr;
    ip4Addr_t dstAddr;
}

header tcp_t {
    bit<16> srcPort;
    bit<16> dstPort;
    bit<32> seqNo;
    bit<32> ackNo;
    bit<4>  dataOffset;
    bit<3>  res;
    bit<3>  ecn;
    bit<6>  ctrl;
    bit<16> window;
    bit<16> checksum;
    bit<16> urgentPtr;
}

header udp_t {
    bit<16> srcPort;
    bit<16> dstPort;
    bit<16> length_;
    bit<16> checksum;
}

header icmp_t {
    bit<32> data;
}

header igmp_t {
    bit<32> data;
}

header payload_t {
    bit<32> data;
}

struct metadata {
    macAddr_t tmpDstMac;
    ip4Addr_t tmpDstIP;
    bit<8> ipProto;
    bit<16> pktSize;
    bit<3> ipFlags;
    bit<16> tcpDst;
    bit<6> tcpFlags;
    bit<32> class;
}

struct headers {
    ethernet_t ethernet;
    ipv4_t ipv4;
    icmp_t icmp;
    igmp_t igmp;
    tcp_t tcp;
    udp_t udp;
    payload_t pload;
}

/*************************************************************************
*********************** P A R S E R  ***********************************
*************************************************************************/

parser MyParser(packet_in packet,
                out headers hdr,
                inout metadata meta,
                inout standard_metadata_t standard_metadata) {

    state start {
        transition parse_ethernet;
    }

    state parse_ethernet {
        packet.extract(hdr.ethernet);
        meta.tmpDstMac = hdr.ethernet.dstAddr;
        transition select(hdr.ethernet.etherType) {
            0x4d49: parse_ipv4;
        }
    }
    
    state parse_ipv4 {
        packet.extract(hdr.ipv4);
        meta.tmpDstIP = hdr.ipv4.dstAddr;
        meta.ipProto = hdr.ipv4.protocol;
        meta.ipFlags= hdr.ipv4.flags;
        meta.pktSize = hdr.ipv4.totalLen;
        transition select(hdr.ipv4.protocol) {
            0x01: parse_icmp;
            0x02: parse_igmp;
            0x06: parse_tcp;
            0x11: parse_udp;
        }
    }    
    
    state parse_icmp {
        packet.extract(hdr.icmp);
        meta.tcpFlags = 0;
        meta.tcpDst = 0;
        transition parse_payload;
    }
    
    state parse_igmp {
        packet.extract(hdr.igmp);
        meta.tcpFlags = 0;
        meta.tcpDst = 0;
        transition parse_payload;
    }
    
    state parse_tcp {
        packet.extract(hdr.tcp);
        meta.tcpFlags = hdr.tcp.ctrl;
        meta.tcpDst = hdr.tcp.dstPort;
        transition parse_payload;
    }
    
    state parse_udp {
        packet.extract(hdr.udp);
        meta.tcpFlags = 0;
        meta.tcpDst = 0;
        transition parse_payload;
    }
    
    state parse_payload {
        packet.extract(hdr.pload);
        transition accept;
    }
}

/*************************************************************************
************   C H E C K S U M    V E R I F I C A T I O N   *************
*************************************************************************/

control MyVerifyChecksum(inout headers hdr, inout metadata meta) {
    apply {  }
}


/*************************************************************************
**************  I N G R E S S   P R O C E S S I N G   *******************
*************************************************************************/

control MyIngress(inout headers hdr,
                  inout metadata meta,
                  inout standard_metadata_t standard_metadata) {

    action ipv4_forward() {
        standard_metadata.egress_spec = standard_metadata.ingress_port;
        hdr.ethernet.dstAddr = hdr.ethernet.srcAddr;
        hdr.ethernet.srcAddr = meta.tmpDstMac;
        hdr.ethernet.etherType = 0x4d4f;
        
        hdr.ipv4.dstAddr = hdr.ipv4.srcAddr;
        hdr.ipv4.srcAddr = meta.tmpDstIP;
        
        hdr.pload.data = meta.class;
    }

    table ipv4_tbl {
        actions = {
            ipv4_forward;
        }
        default_action = ipv4_forward;
    }

    apply {
        if (meta.tcpDst <= 264) 
            if (meta.tcpDst <= 66) 
                if (meta.tcpFlags <= 32) 
                    if (meta.ipProto <= 1) 
                        if (meta.pktSize <= 124) 
                            meta.class = 0;
                        else 
                            meta.class = 6;
                    else 
                        if (meta.pktSize <= 41) 
                            meta.class = 0;
                        else 
                            meta.class = 0;
                else 
                    meta.class = 6;
            else 
                if (meta.pktSize <= 50) 
                    if (meta.tcpFlags <= 10) 
                        if (meta.pktSize <= 42) 
                            meta.class = 3;
                        else 
                            meta.class = 0;
                    else 
                        if (meta.tcpDst <= 137) 
                            if (meta.tcpDst <= 111) 
                                meta.class = 0;
                            else 
                                meta.class = 0;
                        else 
                            meta.class = 6;
                else 
                    if (meta.pktSize <= 54) 
                        if (meta.tcpFlags <= 9) 
                            if (meta.tcpDst <= 137) 
                                if (meta.tcpDst <= 111) 
                                    meta.class = 0;
                                else 
                                    meta.class = 0;
                            else 
                                meta.class = 6;
                        else 
                            if (meta.tcpFlags <= 18) 
                                if (meta.tcpFlags <= 16) 
                                    if (meta.tcpDst <= 84) 
                                        meta.class = 0;
                                    else 
                                        meta.class = 0;
                                else 
                                    if (meta.tcpDst <= 84) 
                                        meta.class = 0;
                                    else 
                                        meta.class = 0;
                            else 
                                meta.class = 3;
                    else 
                        if (meta.pktSize <= 455) 
                            if (meta.pktSize <= 339) 
                                if (meta.pktSize <= 282) 
                                    if (meta.tcpDst <= 84) 
                                        if (meta.tcpFlags <= 20) 
                                            if (meta.pktSize <= 62) 
                                                if (meta.tcpFlags <= 9) 
                                                    meta.class = 2;
                                                else 
                                                    meta.class = 0;
                                            else 
                                                meta.class = 0;
                                        else 
                                            if (meta.pktSize <= 60) 
                                                if (meta.pktSize <= 59) 
                                                    meta.class = 2;
                                                else 
                                                    meta.class = 1;
                                            else 
                                                if (meta.pktSize <= 75) 
                                                    meta.class = 2;
                                                else 
                                                    if (meta.tcpFlags <= 24) 
                                                        if (meta.pktSize <= 238) 
                                                            if (meta.pktSize <= 218) 
                                                                if (meta.pktSize <= 190) 
                                                                    meta.class = 0;
                                                                else 
                                                                    meta.class = 6;
                                                            else 
                                                                meta.class = 0;
                                                        else 
                                                            if (meta.pktSize <= 245) 
                                                                meta.class = 2;
                                                            else 
                                                                meta.class = 0;
                                                    else 
                                                        meta.class = 2;
                                    else 
                                        if (meta.pktSize <= 62) 
                                            if (meta.tcpDst <= 111) 
                                                meta.class = 0;
                                            else 
                                                meta.class = 6;
                                        else 
                                            meta.class = 0;
                                else 
                                    if (meta.pktSize <= 291) 
                                        meta.class = 1;
                                    else 
                                        meta.class = 0;
                            else 
                                if (meta.pktSize <= 430) 
                                    if (meta.tcpFlags <= 24) 
                                        if (meta.pktSize <= 352) 
                                            if (meta.tcpDst <= 84) 
                                                meta.class = 3;
                                            else 
                                                meta.class = 0;
                                        else 
                                            if (meta.pktSize <= 402) 
                                                meta.class = 3;
                                            else 
                                                if (meta.pktSize <= 403) 
                                                    meta.class = 2;
                                                else 
                                                    if (meta.pktSize <= 408) 
                                                        if (meta.pktSize <= 407) 
                                                            meta.class = 3;
                                                        else 
                                                            meta.class = 2;
                                                    else 
                                                        meta.class = 3;
                                    else 
                                        meta.class = 2;
                                else 
                                    if (meta.pktSize <= 432) 
                                        meta.class = 0;
                                    else 
                                        if (meta.pktSize <= 435) 
                                            if (meta.pktSize <= 434) 
                                                meta.class = 3;
                                            else 
                                                meta.class = 5;
                                        else 
                                            if (meta.pktSize <= 452) 
                                                meta.class = 4;
                                            else 
                                                if (meta.pktSize <= 453) 
                                                    meta.class = 5;
                                                else 
                                                    meta.class = 4;
                        else 
                            if (meta.pktSize <= 493) 
                                if (meta.pktSize <= 463) 
                                    meta.class = 0;
                                else 
                                    if (meta.pktSize <= 469) 
                                        meta.class = 0;
                                    else 
                                        meta.class = 0;
                            else 
                                if (meta.pktSize <= 657) 
                                    if (meta.pktSize <= 571) 
                                        if (meta.pktSize <= 510) 
                                            meta.class = 0;
                                        else 
                                            meta.class = 0;
                                    else 
                                        if (meta.pktSize <= 572) 
                                            meta.class = 2;
                                        else 
                                            if (meta.pktSize <= 653) 
                                                meta.class = 0;
                                            else 
                                                if (meta.pktSize <= 655) 
                                                    meta.class = 5;
                                                else 
                                                    meta.class = 0;
                                else 
                                    if (meta.pktSize <= 764) 
                                        meta.class = 0;
                                    else 
                                        meta.class = 0;
        else 
            if (meta.tcpFlags <= 33) 
                if (meta.tcpDst <= 1043) 
                    if (meta.tcpDst <= 745) 
                        if (meta.tcpDst <= 443) 
                            if (meta.pktSize <= 50) 
                                meta.class = 0;
                            else 
                                if (meta.pktSize <= 69) 
                                    meta.class = 0;
                                else 
                                    meta.class = 0;
                        else 
                            if (meta.tcpDst <= 455) 
                                if (meta.pktSize <= 95) 
                                    if (meta.pktSize <= 69) 
                                        if (meta.tcpFlags <= 18) 
                                            if (meta.tcpDst <= 444) 
                                                meta.class = 0;
                                            else 
                                                if (meta.tcpFlags <= 16) 
                                                    meta.class = 6;
                                                else 
                                                    if (meta.pktSize <= 46) 
                                                        meta.class = 6;
                                                    else 
                                                        meta.class = 0;
                                        else 
                                            meta.class = 0;
                                    else 
                                        meta.class = 6;
                                else 
                                    if (meta.pktSize <= 112) 
                                        meta.class = 0;
                                    else 
                                        if (meta.pktSize <= 129) 
                                            meta.class = 6;
                                        else 
                                            if (meta.pktSize <= 178) 
                                                if (meta.pktSize <= 156) 
                                                    if (meta.pktSize <= 153) 
                                                        meta.class = 0;
                                                    else 
                                                        meta.class = 6;
                                                else 
                                                    meta.class = 0;
                                            else 
                                                if (meta.pktSize <= 190) 
                                                    meta.class = 6;
                                                else 
                                                    if (meta.pktSize <= 1158) 
                                                        if (meta.pktSize <= 219) 
                                                            meta.class = 0;
                                                        else 
                                                            if (meta.pktSize <= 229) 
                                                                meta.class = 6;
                                                            else 
                                                                meta.class = 0;
                                                    else 
                                                        meta.class = 0;
                            else 
                                meta.class = 0;
                    else 
                        meta.class = 6;
                else 
                    if (meta.tcpFlags <= 3) 
                        if (meta.ipFlags <= 1) 
                            meta.class = 6;
                        else 
                            if (meta.pktSize <= 50) 
                                meta.class = 6;
                            else 
                                if (meta.pktSize <= 56) 
                                    if (meta.tcpDst <= 40335) 
                                        if (meta.tcpDst <= 11728) 
                                            meta.class = 0;
                                        else 
                                            meta.class = 6;
                                    else 
                                        meta.class = 0;
                                else 
                                    meta.class = 0;
                    else 
                        meta.class = 0;
            else 
                meta.class = 6;

            
        ipv4_tbl.apply();
    }
}

/*************************************************************************
****************  E G R E S S   P R O C E S S I N G   *******************
*************************************************************************/

control MyEgress(inout headers hdr,
                 inout metadata meta,
                 inout standard_metadata_t standard_metadata) {
    apply {  }
}

/*************************************************************************
*************   C H E C K S U M    C O M P U T A T I O N   **************
*************************************************************************/

control MyComputeChecksum(inout headers  hdr, inout metadata meta) {
    apply {
        update_checksum(
            hdr.ipv4.isValid(),
            { hdr.ipv4.version,
            hdr.ipv4.ihl,
            hdr.ipv4.diffserv,
            hdr.ipv4.totalLen,
            hdr.ipv4.identification,
            hdr.ipv4.flags,
            hdr.ipv4.fragOffset,
            hdr.ipv4.ttl,
            hdr.ipv4.protocol,
            hdr.ipv4.srcAddr,
            hdr.ipv4.dstAddr },
            hdr.ipv4.hdrChecksum,
            HashAlgorithm.csum16);
    }
}


/*************************************************************************
***********************  D E P A R S E R  *******************************
*************************************************************************/

control MyDeparser(packet_out packet, in headers hdr) {
    apply {
        packet.emit(hdr.ethernet);
        packet.emit(hdr.ipv4);
        packet.emit(hdr.icmp);
        packet.emit(hdr.igmp);
        packet.emit(hdr.tcp);
        packet.emit(hdr.udp);
        packet.emit(hdr.pload);
    }
}

/*************************************************************************
***********************  S W I T C H  *******************************
*************************************************************************/

V1Switch(
MyParser(),
MyVerifyChecksum(),
MyIngress(),
MyEgress(),
MyComputeChecksum(),
MyDeparser()
) main;