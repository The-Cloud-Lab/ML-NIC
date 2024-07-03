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


header udp_t {
    bit<16> srcPort;
    bit<16> dstPort;
    bit<16> length_;
    bit<16> checksum;
}

header payload_t {
    bit<16> feature1;
    bit<16> feature2;
    bit<16> feature3;
    bit<16> feature4;
    bit<16> feature5;
    bit<16> feature6;
    bit<16> feature7;
    bit<16> feature8;
}

struct metadata {
    macAddr_t tmpDstMac;
    ip4Addr_t tmpDstIP;
    bit<16> class;
}

struct headers {
    ethernet_t ethernet;
    ipv4_t ipv4;
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
        transition select(hdr.ipv4.protocol) {
            0x11: parse_udp;
        }
    }    
    
    state parse_udp {
        packet.extract(hdr.udp);
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
        
        hdr.pload.feature2 = meta.class;
    }

    table ipv4_tbl {
        actions = {
            ipv4_forward;
        }
        default_action = ipv4_forward;
    }

    apply {
        if (hdr.pload.feature1 <= 4792) 
            if (hdr.pload.feature1 <= 2810) 
                if (hdr.pload.feature1 <= 2245) 
                    if (hdr.pload.feature7 <= 4096) 
                        if (hdr.pload.feature5 <= 4096) 
                            meta.class = 1;
                        else 
                            meta.class = 4;
                    else 
                        meta.class = 4;
                else 
                    if (hdr.pload.feature2 <= 5587) 
                        if (hdr.pload.feature3 <= 4096) 
                            if (hdr.pload.feature8 <= 4096) 
                                if (hdr.pload.feature1 <= 2318) 
                                    if (hdr.pload.feature7 <= 4096) 
                                        meta.class = 1;
                                    else 
                                        meta.class = 4;
                                else 
                                    meta.class = 1;
                            else 
                                if (hdr.pload.feature1 <= 2449) 
                                    meta.class = 1;
                                else 
                                    if (hdr.pload.feature2 <= 4841) 
                                        meta.class = 4;
                                    else 
                                        meta.class = 5;
                        else 
                            if (hdr.pload.feature2 <= 3351) 
                                if (hdr.pload.feature2 <= 1114) 
                                    meta.class = 1;
                                else 
                                    if (hdr.pload.feature1 <= 2392) 
                                        if (hdr.pload.feature1 <= 2310) 
                                            meta.class = 5;
                                        else 
                                            meta.class = 1;
                                    else 
                                        meta.class = 5;
                            else 
                                if (hdr.pload.feature1 <= 2769) 
                                    if (hdr.pload.feature2 <= 4096) 
                                        if (hdr.pload.feature1 <= 2761) 
                                            meta.class = 5;
                                        else 
                                            meta.class = 3;
                                    else 
                                        meta.class = 3;
                                else 
                                    meta.class = 4;
                    else 
                        if (hdr.pload.feature1 <= 2662) 
                            if (hdr.pload.feature1 <= 2359) 
                                if (hdr.pload.feature4 <= 4096) 
                                    meta.class = 1;
                                else 
                                    if (hdr.pload.feature1 <= 2310) 
                                        meta.class = 3;
                                    else 
                                        meta.class = 1;
                            else 
                                if (hdr.pload.feature6 <= 4096) 
                                    if (hdr.pload.feature1 <= 2613) 
                                        if (hdr.pload.feature1 <= 2449) 
                                            if (hdr.pload.feature7 <= 4096) 
                                                meta.class = 5;
                                            else 
                                                if (hdr.pload.feature1 <= 2425) 
                                                    meta.class = 5;
                                                else 
                                                    meta.class = 1;
                                        else 
                                            if (hdr.pload.feature5 <= 4096) 
                                                if (hdr.pload.feature1 <= 2515) 
                                                    if (hdr.pload.feature1 <= 2482) 
                                                        meta.class = 1;
                                                    else 
                                                        meta.class = 3;
                                                else 
                                                    if (hdr.pload.feature2 <= 7078) 
                                                        meta.class = 4;
                                                    else 
                                                        if (hdr.pload.feature2 <= 7823) 
                                                            if (hdr.pload.feature1 <= 2540) 
                                                                meta.class = 5;
                                                            else 
                                                                meta.class = 3;
                                                        else 
                                                            meta.class = 5;
                                            else 
                                                meta.class = 1;
                                    else 
                                        if (hdr.pload.feature2 <= 7078) 
                                            if (hdr.pload.feature1 <= 2638) 
                                                meta.class = 5;
                                            else 
                                                meta.class = 1;
                                        else 
                                            meta.class = 5;
                                else 
                                    if (hdr.pload.feature1 <= 2515) 
                                        meta.class = 1;
                                    else 
                                        meta.class = 4;
                        else 
                            if (hdr.pload.feature5 <= 4096) 
                                if (hdr.pload.feature1 <= 2744) 
                                    if (hdr.pload.feature1 <= 2687) 
                                        meta.class = 3;
                                    else 
                                        if (hdr.pload.feature4 <= 4096) 
                                            meta.class = 4;
                                        else 
                                            if (hdr.pload.feature1 <= 2712) 
                                                meta.class = 4;
                                            else 
                                                meta.class = 5;
                                else 
                                    if (hdr.pload.feature2 <= 7078) 
                                        meta.class = 3;
                                    else 
                                        if (hdr.pload.feature8 <= 4096) 
                                            meta.class = 3;
                                        else 
                                            meta.class = 4;
                            else 
                                meta.class = 5;
            else 
                if (hdr.pload.feature2 <= 6332) 
                    if (hdr.pload.feature4 <= 4096) 
                        if (hdr.pload.feature7 <= 4096) 
                            if (hdr.pload.feature1 <= 3629) 
                                if (hdr.pload.feature2 <= 1114) 
                                    if (hdr.pload.feature1 <= 3031) 
                                        meta.class = 1;
                                    else 
                                        if (hdr.pload.feature3 <= 4096) 
                                            meta.class = 4;
                                        else 
                                            meta.class = 3;
                                else 
                                    if (hdr.pload.feature2 <= 4096) 
                                        if (hdr.pload.feature1 <= 3056) 
                                            if (hdr.pload.feature3 <= 4096) 
                                                meta.class = 5;
                                            else 
                                                meta.class = 3;
                                        else 
                                            if (hdr.pload.feature5 <= 4096) 
                                                if (hdr.pload.feature1 <= 3482) 
                                                    if (hdr.pload.feature1 <= 3170) 
                                                        if (hdr.pload.feature1 <= 3138) 
                                                            meta.class = 4;
                                                        else 
                                                            meta.class = 3;
                                                    else 
                                                        meta.class = 4;
                                                else 
                                                    meta.class = 3;
                                            else 
                                                meta.class = 5;
                                    else 
                                        if (hdr.pload.feature1 <= 2859) 
                                            meta.class = 4;
                                        else 
                                            if (hdr.pload.feature1 <= 3301) 
                                                if (hdr.pload.feature1 <= 2875) 
                                                    meta.class = 3;
                                                else 
                                                    if (hdr.pload.feature2 <= 5587) 
                                                        if (hdr.pload.feature3 <= 4096) 
                                                            if (hdr.pload.feature1 <= 2900) 
                                                                meta.class = 5;
                                                            else 
                                                                if (hdr.pload.feature1 <= 3269) 
                                                                    if (hdr.pload.feature1 <= 3006) 
                                                                        if (hdr.pload.feature2 <= 4841) 
                                                                            meta.class = 4;
                                                                        else 
                                                                            meta.class = 3;
                                                                    else 
                                                                        meta.class = 3;
                                                                else 
                                                                    meta.class = 5;
                                                        else 
                                                            meta.class = 5;
                                                    else 
                                                        meta.class = 5;
                                            else 
                                                meta.class = 3;
                            else 
                                if (hdr.pload.feature2 <= 2605) 
                                    if (hdr.pload.feature3 <= 4096) 
                                        if (hdr.pload.feature1 <= 4588) 
                                            if (hdr.pload.feature2 <= 369) 
                                                if (hdr.pload.feature1 <= 4342) 
                                                    meta.class = 4;
                                                else 
                                                    meta.class = 5;
                                            else 
                                                if (hdr.pload.feature2 <= 1860) 
                                                    meta.class = 5;
                                                else 
                                                    if (hdr.pload.feature1 <= 3834) 
                                                        meta.class = 5;
                                                    else 
                                                        if (hdr.pload.feature1 <= 4211) 
                                                            meta.class = 3;
                                                        else 
                                                            meta.class = 5;
                                        else 
                                            meta.class = 3;
                                    else 
                                        if (hdr.pload.feature2 <= 369) 
                                            meta.class = 5;
                                        else 
                                            if (hdr.pload.feature1 <= 3752) 
                                                meta.class = 5;
                                            else 
                                                meta.class = 4;
                                else 
                                    if (hdr.pload.feature6 <= 4096) 
                                        meta.class = 3;
                                    else 
                                        meta.class = 5;
                        else 
                            if (hdr.pload.feature1 <= 3138) 
                                meta.class = 5;
                            else 
                                if (hdr.pload.feature2 <= 1860) 
                                    if (hdr.pload.feature1 <= 3785) 
                                        meta.class = 5;
                                    else 
                                        meta.class = 3;
                                else 
                                    if (hdr.pload.feature1 <= 4006) 
                                        meta.class = 3;
                                    else 
                                        meta.class = 2;
                    else 
                        if (hdr.pload.feature1 <= 2949) 
                            if (hdr.pload.feature1 <= 2867) 
                                meta.class = 5;
                            else 
                                meta.class = 3;
                        else 
                            if (hdr.pload.feature2 <= 1114) 
                                if (hdr.pload.feature1 <= 3924) 
                                    meta.class = 3;
                                else 
                                    if (hdr.pload.feature1 <= 4293) 
                                        meta.class = 4;
                                    else 
                                        meta.class = 3;
                            else 
                                if (hdr.pload.feature1 <= 3531) 
                                    if (hdr.pload.feature2 <= 4096) 
                                        if (hdr.pload.feature2 <= 2236) 
                                            if (hdr.pload.feature1 <= 3326) 
                                                meta.class = 3;
                                            else 
                                                meta.class = 5;
                                        else 
                                            meta.class = 5;
                                    else 
                                        if (hdr.pload.feature2 <= 5587) 
                                            meta.class = 4;
                                        else 
                                            if (hdr.pload.feature1 <= 3006) 
                                                meta.class = 4;
                                            else 
                                                meta.class = 2;
                                else 
                                    if (hdr.pload.feature2 <= 4096) 
                                        if (hdr.pload.feature1 <= 3760) 
                                            meta.class = 4;
                                        else 
                                            if (hdr.pload.feature2 <= 3351) 
                                                if (hdr.pload.feature1 <= 4030) 
                                                    meta.class = 4;
                                                else 
                                                    if (hdr.pload.feature2 <= 2605) 
                                                        if (hdr.pload.feature1 <= 4170) 
                                                            meta.class = 4;
                                                        else 
                                                            if (hdr.pload.feature2 <= 1860) 
                                                                if (hdr.pload.feature1 <= 4284) 
                                                                    meta.class = 2;
                                                                else 
                                                                    meta.class = 4;
                                                            else 
                                                                meta.class = 2;
                                                    else 
                                                        meta.class = 2;
                                            else 
                                                meta.class = 2;
                                    else 
                                        meta.class = 2;
                else 
                    if (hdr.pload.feature1 <= 3416) 
                        if (hdr.pload.feature1 <= 2933) 
                            meta.class = 3;
                        else 
                            if (hdr.pload.feature6 <= 4096) 
                                if (hdr.pload.feature4 <= 4096) 
                                    if (hdr.pload.feature2 <= 7447) 
                                        if (hdr.pload.feature8 <= 4096) 
                                            meta.class = 3;
                                        else 
                                            meta.class = 4;
                                    else 
                                        meta.class = 4;
                                else 
                                    meta.class = 2;
                            else 
                                meta.class = 5;
                    else 
                        meta.class = 2;
        else 
            if (hdr.pload.feature1 <= 5063) 
                if (hdr.pload.feature2 <= 3727) 
                    if (hdr.pload.feature2 <= 745) 
                        meta.class = 4;
                    else 
                        meta.class = 3;
                else 
                    meta.class = 2;
            else 
                if (hdr.pload.feature8 <= 4096) 
                    meta.class = 2;
                else 
                    if (hdr.pload.feature2 <= 1114) 
                        if (hdr.pload.feature2 <= 369) 
                            meta.class = 2;
                        else 
                            meta.class = 3;
                    else 
                        meta.class = 2;


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