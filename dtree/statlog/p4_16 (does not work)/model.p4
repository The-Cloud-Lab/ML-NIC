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
    bit<16> feature9;
    bit<16> feature10;
    bit<16> feature11;
    bit<16> feature12;
    bit<16> feature13;
    bit<16> feature14;
    bit<16> feature15;
    bit<16> feature16;
    bit<16> feature17;
    bit<16> feature18;
    bit<16> feature19;
    bit<16> feature20;
    bit<16> feature21;
    bit<16> feature22;
    bit<16> feature23;
    bit<16> feature24;
    bit<16> feature25;
    bit<16> feature26;
    bit<16> feature27;
    bit<16> feature28;
    bit<16> feature29;
    bit<16> feature30;
    bit<16> feature31;
    bit<16> feature32;
    bit<16> feature33;
    bit<16> feature34;
    bit<16> feature35;
    bit<16> feature36;
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
        if (hdr.pload.feature17 <= 5054) 
            if (hdr.pload.feature20 <= 2629) 
                if (hdr.pload.feature18 <= 2744) 
                    if (hdr.pload.feature1 <= 892) 
                        meta.class = 2;
                    else 
                        if (hdr.pload.feature18 <= 2588) 
                            meta.class = 5;
                        else 
                            if (hdr.pload.feature1 <= 1409) 
                                if (hdr.pload.feature23 <= 2048) 
                                    meta.class = 7;
                                else 
                                    meta.class = 1;
                            else 
                                if (hdr.pload.feature20 <= 1564) 
                                    if (hdr.pload.feature4 <= 1859) 
                                        meta.class = 7;
                                    else 
                                        meta.class = 5;
                                else 
                                    meta.class = 5;
                else 
                    if (hdr.pload.feature16 <= 2252) 
                        if (hdr.pload.feature34 <= 2826) 
                            if (hdr.pload.feature3 <= 1703) 
                                if (hdr.pload.feature35 <= 3276) 
                                    meta.class = 7;
                                else 
                                    meta.class = 5;
                            else 
                                if (hdr.pload.feature18 <= 3538) 
                                    meta.class = 5;
                                else 
                                    if (hdr.pload.feature15 <= 2801) 
                                        meta.class = 7;
                                    else 
                                        meta.class = 2;
                        else 
                            if (hdr.pload.feature20 <= 2293) 
                                if (hdr.pload.feature8 <= 1343) 
                                    meta.class = 5;
                                else 
                                    if (hdr.pload.feature15 <= 3473) 
                                        if (hdr.pload.feature17 <= 2236) 
                                            meta.class = 5;
                                        else 
                                            if (hdr.pload.feature1 <= 1597) 
                                                meta.class = 4;
                                            else 
                                                meta.class = 7;
                                    else 
                                        meta.class = 5;
                            else 
                                if (hdr.pload.feature12 <= 3997) 
                                    if (hdr.pload.feature6 <= 3497) 
                                        if (hdr.pload.feature16 <= 2048) 
                                            meta.class = 5;
                                        else 
                                            meta.class = 1;
                                    else 
                                        if (hdr.pload.feature2 <= 4505) 
                                            if (hdr.pload.feature32 <= 1859) 
                                                meta.class = 4;
                                            else 
                                                meta.class = 7;
                                        else 
                                            meta.class = 4;
                                else 
                                    meta.class = 4;
                    else 
                        if (hdr.pload.feature17 <= 2498) 
                            if (hdr.pload.feature21 <= 2334) 
                                meta.class = 1;
                            else 
                                if (hdr.pload.feature2 <= 3162) 
                                    meta.class = 5;
                                else 
                                    meta.class = 1;
                        else 
                            if (hdr.pload.feature18 <= 4374) 
                                if (hdr.pload.feature18 <= 3620) 
                                    if (hdr.pload.feature27 <= 2498) 
                                        if (hdr.pload.feature19 <= 2859) 
                                            if (hdr.pload.feature22 <= 2899) 
                                                meta.class = 5;
                                            else 
                                                meta.class = 7;
                                        else 
                                            meta.class = 2;
                                    else 
                                        if (hdr.pload.feature7 <= 3235) 
                                            if (hdr.pload.feature34 <= 4218) 
                                                if (hdr.pload.feature31 <= 2457) 
                                                    if (hdr.pload.feature29 <= 3588) 
                                                        if (hdr.pload.feature28 <= 2523) 
                                                            meta.class = 5;
                                                        else 
                                                            meta.class = 7;
                                                    else 
                                                        meta.class = 7;
                                                else 
                                                    meta.class = 5;
                                            else 
                                                if (hdr.pload.feature25 <= 3776) 
                                                    meta.class = 4;
                                                else 
                                                    meta.class = 7;
                                        else 
                                            if (hdr.pload.feature14 <= 2957) 
                                                meta.class = 2;
                                            else 
                                                meta.class = 7;
                                else 
                                    if (hdr.pload.feature32 <= 3170) 
                                        if (hdr.pload.feature36 <= 1310) 
                                            meta.class = 5;
                                        else 
                                            if (hdr.pload.feature10 <= 2269) 
                                                if (hdr.pload.feature19 <= 2760) 
                                                    meta.class = 2;
                                                else 
                                                    meta.class = 4;
                                            else 
                                                if (hdr.pload.feature24 <= 2916) 
                                                    if (hdr.pload.feature28 <= 3719) 
                                                        meta.class = 7;
                                                    else 
                                                        meta.class = 4;
                                                else 
                                                    if (hdr.pload.feature36 <= 2850) 
                                                        meta.class = 4;
                                                    else 
                                                        if (hdr.pload.feature28 <= 2285) 
                                                            meta.class = 5;
                                                        else 
                                                            meta.class = 7;
                                    else 
                                        if (hdr.pload.feature24 <= 2949) 
                                            if (hdr.pload.feature22 <= 3457) 
                                                meta.class = 5;
                                            else 
                                                meta.class = 4;
                                        else 
                                            meta.class = 7;
                            else 
                                if (hdr.pload.feature23 <= 3325) 
                                    if (hdr.pload.feature23 <= 1777) 
                                        meta.class = 3;
                                    else 
                                        if (hdr.pload.feature31 <= 1851) 
                                            meta.class = 5;
                                        else 
                                            if (hdr.pload.feature1 <= 4931) 
                                                if (hdr.pload.feature26 <= 4603) 
                                                    if (hdr.pload.feature36 <= 2080) 
                                                        if (hdr.pload.feature6 <= 4022) 
                                                            meta.class = 7;
                                                        else 
                                                            meta.class = 4;
                                                    else 
                                                        meta.class = 7;
                                                else 
                                                    if (hdr.pload.feature26 <= 5160) 
                                                        if (hdr.pload.feature13 <= 4292) 
                                                            meta.class = 7;
                                                        else 
                                                            meta.class = 4;
                                                    else 
                                                        if (hdr.pload.feature6 <= 3801) 
                                                            if (hdr.pload.feature4 <= 2506) 
                                                                meta.class = 5;
                                                            else 
                                                                meta.class = 4;
                                                        else 
                                                            meta.class = 7;
                                            else 
                                                if (hdr.pload.feature22 <= 4571) 
                                                    meta.class = 7;
                                                else 
                                                    meta.class = 4;
                                else 
                                    if (hdr.pload.feature3 <= 2875) 
                                        if (hdr.pload.feature14 <= 4841) 
                                            meta.class = 7;
                                        else 
                                            if (hdr.pload.feature24 <= 2490) 
                                                meta.class = 7;
                                            else 
                                                meta.class = 4;
                                    else 
                                        if (hdr.pload.feature15 <= 4096) 
                                            if (hdr.pload.feature10 <= 4497) 
                                                if (hdr.pload.feature27 <= 3391) 
                                                    if (hdr.pload.feature23 <= 3457) 
                                                        meta.class = 4;
                                                    else 
                                                        if (hdr.pload.feature32 <= 1949) 
                                                            meta.class = 4;
                                                        else 
                                                            meta.class = 7;
                                                else 
                                                    if (hdr.pload.feature34 <= 5365) 
                                                        if (hdr.pload.feature19 <= 2957) 
                                                            meta.class = 7;
                                                        else 
                                                            meta.class = 4;
                                                    else 
                                                        if (hdr.pload.feature23 <= 4325) 
                                                            meta.class = 7;
                                                        else 
                                                            meta.class = 4;
                                            else 
                                                if (hdr.pload.feature14 <= 4251) 
                                                    meta.class = 7;
                                                else 
                                                    if (hdr.pload.feature10 <= 5447) 
                                                        if (hdr.pload.feature2 <= 5103) 
                                                            meta.class = 4;
                                                        else 
                                                            meta.class = 7;
                                                    else 
                                                        meta.class = 3;
                                        else 
                                            if (hdr.pload.feature29 <= 4792) 
                                                meta.class = 7;
                                            else 
                                                meta.class = 4;
            else 
                if (hdr.pload.feature18 <= 3022) 
                    if (hdr.pload.feature20 <= 3760) 
                        if (hdr.pload.feature28 <= 4538) 
                            if (hdr.pload.feature8 <= 4349) 
                                if (hdr.pload.feature29 <= 1327) 
                                    if (hdr.pload.feature13 <= 1851) 
                                        meta.class = 1;
                                    else 
                                        meta.class = 5;
                                else 
                                    meta.class = 5;
                            else 
                                if (hdr.pload.feature27 <= 3956) 
                                    meta.class = 2;
                                else 
                                    meta.class = 5;
                        else 
                            meta.class = 2;
                    else 
                        if (hdr.pload.feature18 <= 2588) 
                            meta.class = 2;
                        else 
                            if (hdr.pload.feature6 <= 1638) 
                                meta.class = 2;
                            else 
                                if (hdr.pload.feature10 <= 5087) 
                                    meta.class = 5;
                                else 
                                    meta.class = 2;
                else 
                    if (hdr.pload.feature21 <= 4284) 
                        if (hdr.pload.feature10 <= 3137) 
                            if (hdr.pload.feature10 <= 1949) 
                                if (hdr.pload.feature32 <= 3678) 
                                    if (hdr.pload.feature27 <= 2965) 
                                        if (hdr.pload.feature33 <= 3325) 
                                            meta.class = 2;
                                        else 
                                            meta.class = 4;
                                    else 
                                        if (hdr.pload.feature9 <= 450) 
                                            meta.class = 5;
                                        else 
                                            meta.class = 2;
                                else 
                                    meta.class = 1;
                            else 
                                if (hdr.pload.feature33 <= 2113) 
                                    meta.class = 1;
                                else 
                                    if (hdr.pload.feature2 <= 3645) 
                                        if (hdr.pload.feature11 <= 1982) 
                                            meta.class = 7;
                                        else 
                                            meta.class = 5;
                                    else 
                                        if (hdr.pload.feature3 <= 3751) 
                                            if (hdr.pload.feature5 <= 3497) 
                                                if (hdr.pload.feature16 <= 3022) 
                                                    meta.class = 7;
                                                else 
                                                    meta.class = 1;
                                            else 
                                                meta.class = 4;
                                        else 
                                            if (hdr.pload.feature12 <= 2818) 
                                                if (hdr.pload.feature23 <= 3227) 
                                                    meta.class = 3;
                                                else 
                                                    meta.class = 7;
                                            else 
                                                meta.class = 5;
                        else 
                            if (hdr.pload.feature25 <= 4546) 
                                if (hdr.pload.feature26 <= 2990) 
                                    if (hdr.pload.feature34 <= 2588) 
                                        meta.class = 2;
                                    else 
                                        if (hdr.pload.feature13 <= 1916) 
                                            if (hdr.pload.feature12 <= 3997) 
                                                meta.class = 1;
                                            else 
                                                meta.class = 5;
                                        else 
                                            if (hdr.pload.feature22 <= 5881) 
                                                meta.class = 5;
                                            else 
                                                meta.class = 1;
                                else 
                                    if (hdr.pload.feature12 <= 2785) 
                                        if (hdr.pload.feature5 <= 3235) 
                                            if (hdr.pload.feature17 <= 4227) 
                                                meta.class = 1;
                                            else 
                                                meta.class = 4;
                                        else 
                                            if (hdr.pload.feature18 <= 4055) 
                                                meta.class = 5;
                                            else 
                                                if (hdr.pload.feature33 <= 3907) 
                                                    if (hdr.pload.feature21 <= 3276) 
                                                        meta.class = 1;
                                                    else 
                                                        meta.class = 4;
                                                else 
                                                    meta.class = 7;
                                    else 
                                        if (hdr.pload.feature2 <= 2826) 
                                            if (hdr.pload.feature32 <= 2818) 
                                                meta.class = 1;
                                            else 
                                                meta.class = 5;
                                        else 
                                            if (hdr.pload.feature30 <= 3080) 
                                                if (hdr.pload.feature26 <= 3620) 
                                                    meta.class = 5;
                                                else 
                                                    meta.class = 1;
                                            else 
                                                if (hdr.pload.feature33 <= 4030) 
                                                    if (hdr.pload.feature32 <= 2334) 
                                                        meta.class = 2;
                                                    else 
                                                        meta.class = 1;
                                                else 
                                                    if (hdr.pload.feature10 <= 5365) 
                                                        if (hdr.pload.feature17 <= 3907) 
                                                            if (hdr.pload.feature9 <= 3260) 
                                                                if (hdr.pload.feature10 <= 3858) 
                                                                    meta.class = 5;
                                                                else 
                                                                    meta.class = 1;
                                                            else 
                                                                if (hdr.pload.feature25 <= 4284) 
                                                                    meta.class = 5;
                                                                else 
                                                                    meta.class = 1;
                                                        else 
                                                            meta.class = 4;
                                                    else 
                                                        meta.class = 1;
                            else 
                                if (hdr.pload.feature28 <= 3719) 
                                    if (hdr.pload.feature18 <= 4218) 
                                        if (hdr.pload.feature25 <= 5251) 
                                            meta.class = 5;
                                        else 
                                            if (hdr.pload.feature1 <= 4734) 
                                                meta.class = 7;
                                            else 
                                                meta.class = 2;
                                    else 
                                        if (hdr.pload.feature32 <= 3293) 
                                            if (hdr.pload.feature26 <= 5832) 
                                                meta.class = 7;
                                            else 
                                                meta.class = 2;
                                        else 
                                            if (hdr.pload.feature18 <= 5013) 
                                                meta.class = 4;
                                            else 
                                                if (hdr.pload.feature2 <= 4694) 
                                                    meta.class = 7;
                                                else 
                                                    meta.class = 3;
                                else 
                                    if (hdr.pload.feature10 <= 3899) 
                                        if (hdr.pload.feature14 <= 5120) 
                                            meta.class = 4;
                                        else 
                                            meta.class = 5;
                                    else 
                                        if (hdr.pload.feature25 <= 5758) 
                                            if (hdr.pload.feature26 <= 5398) 
                                                meta.class = 1;
                                            else 
                                                meta.class = 1;
                                        else 
                                            if (hdr.pload.feature8 <= 4096) 
                                                meta.class = 3;
                                            else 
                                                meta.class = 1;
                    else 
                        if (hdr.pload.feature20 <= 3661) 
                            if (hdr.pload.feature18 <= 5529) 
                                if (hdr.pload.feature4 <= 2539) 
                                    if (hdr.pload.feature35 <= 5644) 
                                        if (hdr.pload.feature8 <= 3293) 
                                            if (hdr.pload.feature24 <= 2785) 
                                                meta.class = 4;
                                            else 
                                                meta.class = 7;
                                        else 
                                            meta.class = 4;
                                    else 
                                        if (hdr.pload.feature16 <= 3366) 
                                            meta.class = 1;
                                        else 
                                            meta.class = 5;
                                else 
                                    if (hdr.pload.feature11 <= 4571) 
                                        if (hdr.pload.feature26 <= 4530) 
                                            if (hdr.pload.feature25 <= 4161) 
                                                if (hdr.pload.feature6 <= 4505) 
                                                    if (hdr.pload.feature9 <= 4415) 
                                                        if (hdr.pload.feature5 <= 3366) 
                                                            meta.class = 2;
                                                        else 
                                                            meta.class = 4;
                                                    else 
                                                        meta.class = 7;
                                                else 
                                                    if (hdr.pload.feature14 <= 3383) 
                                                        meta.class = 5;
                                                    else 
                                                        meta.class = 4;
                                            else 
                                                meta.class = 7;
                                        else 
                                            if (hdr.pload.feature36 <= 4030) 
                                                if (hdr.pload.feature9 <= 2818) 
                                                    meta.class = 3;
                                                else 
                                                    meta.class = 4;
                                            else 
                                                if (hdr.pload.feature19 <= 4489) 
                                                    meta.class = 1;
                                                else 
                                                    meta.class = 3;
                                    else 
                                        if (hdr.pload.feature14 <= 2088) 
                                            meta.class = 2;
                                        else 
                                            if (hdr.pload.feature28 <= 2965) 
                                                if (hdr.pload.feature21 <= 4792) 
                                                    if (hdr.pload.feature34 <= 5128) 
                                                        meta.class = 4;
                                                    else 
                                                        meta.class = 7;
                                                else 
                                                    if (hdr.pload.feature26 <= 4923) 
                                                        meta.class = 7;
                                                    else 
                                                        if (hdr.pload.feature17 <= 4931) 
                                                            if (hdr.pload.feature7 <= 4358) 
                                                                meta.class = 3;
                                                            else 
                                                                meta.class = 7;
                                                        else 
                                                            meta.class = 3;
                                            else 
                                                if (hdr.pload.feature6 <= 5251) 
                                                    if (hdr.pload.feature11 <= 4743) 
                                                        meta.class = 4;
                                                    else 
                                                        meta.class = 3;
                                                else 
                                                    if (hdr.pload.feature16 <= 3162) 
                                                        meta.class = 1;
                                                    else 
                                                        meta.class = 3;
                            else 
                                if (hdr.pload.feature29 <= 4792) 
                                    if (hdr.pload.feature30 <= 6045) 
                                        if (hdr.pload.feature36 <= 3522) 
                                            meta.class = 4;
                                        else 
                                            if (hdr.pload.feature24 <= 3538) 
                                                meta.class = 4;
                                            else 
                                                meta.class = 3;
                                    else 
                                        meta.class = 1;
                                else 
                                    if (hdr.pload.feature7 <= 3317) 
                                        meta.class = 4;
                                    else 
                                        if (hdr.pload.feature13 <= 6012) 
                                            meta.class = 3;
                                        else 
                                            meta.class = 4;
                        else 
                            if (hdr.pload.feature18 <= 5881) 
                                if (hdr.pload.feature16 <= 3989) 
                                    if (hdr.pload.feature17 <= 4669) 
                                        meta.class = 1;
                                    else 
                                        meta.class = 3;
                                else 
                                    if (hdr.pload.feature10 <= 5767) 
                                        meta.class = 5;
                                    else 
                                        meta.class = 1;
                            else 
                                if (hdr.pload.feature13 <= 5545) 
                                    if (hdr.pload.feature2 <= 3907) 
                                        meta.class = 3;
                                    else 
                                        meta.class = 1;
                                else 
                                    meta.class = 3;
        else 
            if (hdr.pload.feature18 <= 5529) 
                if (hdr.pload.feature11 <= 4358) 
                    if (hdr.pload.feature31 <= 4915) 
                        if (hdr.pload.feature30 <= 4907) 
                            if (hdr.pload.feature15 <= 3915) 
                                if (hdr.pload.feature27 <= 3440) 
                                    if (hdr.pload.feature20 <= 2899) 
                                        meta.class = 7;
                                    else 
                                        meta.class = 4;
                                else 
                                    meta.class = 4;
                            else 
                                meta.class = 7;
                        else 
                            if (hdr.pload.feature35 <= 4915) 
                                if (hdr.pload.feature19 <= 4489) 
                                    if (hdr.pload.feature2 <= 4243) 
                                        meta.class = 7;
                                    else 
                                        if (hdr.pload.feature23 <= 3227) 
                                            meta.class = 7;
                                        else 
                                            if (hdr.pload.feature4 <= 3555) 
                                                if (hdr.pload.feature9 <= 5890) 
                                                    meta.class = 4;
                                                else 
                                                    meta.class = 3;
                                            else 
                                                meta.class = 7;
                                else 
                                    if (hdr.pload.feature9 <= 5505) 
                                        if (hdr.pload.feature32 <= 3391) 
                                            meta.class = 3;
                                        else 
                                            meta.class = 4;
                                    else 
                                        meta.class = 4;
                            else 
                                meta.class = 7;
                    else 
                        if (hdr.pload.feature14 <= 5472) 
                            if (hdr.pload.feature28 <= 3547) 
                                meta.class = 7;
                            else 
                                meta.class = 3;
                        else 
                            meta.class = 3;
                else 
                    if (hdr.pload.feature27 <= 3907) 
                        if (hdr.pload.feature28 <= 1982) 
                            meta.class = 3;
                        else 
                            meta.class = 7;
                    else 
                        if (hdr.pload.feature8 <= 3072) 
                            if (hdr.pload.feature27 <= 5038) 
                                meta.class = 4;
                            else 
                                meta.class = 3;
                        else 
                            if (hdr.pload.feature36 <= 2973) 
                                meta.class = 7;
                            else 
                                if (hdr.pload.feature21 <= 5038) 
                                    meta.class = 1;
                                else 
                                    if (hdr.pload.feature7 <= 5734) 
                                        if (hdr.pload.feature15 <= 3604) 
                                            meta.class = 7;
                                        else 
                                            meta.class = 3;
                                    else 
                                        meta.class = 4;
            else 
                if (hdr.pload.feature33 <= 5824) 
                    if (hdr.pload.feature16 <= 4546) 
                        if (hdr.pload.feature3 <= 3948) 
                            if (hdr.pload.feature23 <= 4964) 
                                if (hdr.pload.feature16 <= 3301) 
                                    if (hdr.pload.feature12 <= 3358) 
                                        meta.class = 7;
                                    else 
                                        if (hdr.pload.feature27 <= 3719) 
                                            meta.class = 3;
                                        else 
                                            meta.class = 4;
                                else 
                                    meta.class = 4;
                            else 
                                if (hdr.pload.feature35 <= 5472) 
                                    meta.class = 3;
                                else 
                                    meta.class = 7;
                        else 
                            if (hdr.pload.feature12 <= 3874) 
                                if (hdr.pload.feature2 <= 5693) 
                                    if (hdr.pload.feature12 <= 3522) 
                                        if (hdr.pload.feature27 <= 4562) 
                                            if (hdr.pload.feature10 <= 5529) 
                                                if (hdr.pload.feature2 <= 5324) 
                                                    if (hdr.pload.feature16 <= 3088) 
                                                        meta.class = 4;
                                                    else 
                                                        meta.class = 3;
                                                else 
                                                    meta.class = 4;
                                            else 
                                                if (hdr.pload.feature30 <= 5881) 
                                                    meta.class = 3;
                                                else 
                                                    meta.class = 4;
                                        else 
                                            if (hdr.pload.feature21 <= 5611) 
                                                meta.class = 3;
                                            else 
                                                if (hdr.pload.feature30 <= 5799) 
                                                    if (hdr.pload.feature30 <= 5554) 
                                                        meta.class = 3;
                                                    else 
                                                        meta.class = 4;
                                                else 
                                                    if (hdr.pload.feature6 <= 5619) 
                                                        meta.class = 3;
                                                    else 
                                                        if (hdr.pload.feature34 <= 5849) 
                                                            meta.class = 3;
                                                        else 
                                                            meta.class = 4;
                                    else 
                                        meta.class = 3;
                                else 
                                    if (hdr.pload.feature1 <= 6078) 
                                        if (hdr.pload.feature24 <= 3866) 
                                            if (hdr.pload.feature14 <= 5636) 
                                                meta.class = 3;
                                            else 
                                                if (hdr.pload.feature33 <= 5570) 
                                                    meta.class = 4;
                                                else 
                                                    if (hdr.pload.feature16 <= 3645) 
                                                        if (hdr.pload.feature4 <= 3383) 
                                                            meta.class = 4;
                                                        else 
                                                            meta.class = 3;
                                                    else 
                                                        meta.class = 4;
                                        else 
                                            meta.class = 3;
                                    else 
                                        if (hdr.pload.feature30 <= 4579) 
                                            meta.class = 7;
                                        else 
                                            if (hdr.pload.feature17 <= 5693) 
                                                if (hdr.pload.feature18 <= 6160) 
                                                    if (hdr.pload.feature3 <= 6094) 
                                                        if (hdr.pload.feature14 <= 6103) 
                                                            meta.class = 3;
                                                        else 
                                                            if (hdr.pload.feature7 <= 5259) 
                                                                meta.class = 4;
                                                            else 
                                                                meta.class = 3;
                                                    else 
                                                        meta.class = 7;
                                                else 
                                                    if (hdr.pload.feature24 <= 3833) 
                                                        meta.class = 4;
                                                    else 
                                                        meta.class = 3;
                                            else 
                                                if (hdr.pload.feature24 <= 2883) 
                                                    meta.class = 4;
                                                else 
                                                    if (hdr.pload.feature2 <= 5808) 
                                                        meta.class = 4;
                                                    else 
                                                        meta.class = 3;
                            else 
                                if (hdr.pload.feature29 <= 3973) 
                                    if (hdr.pload.feature34 <= 5087) 
                                        meta.class = 3;
                                    else 
                                        if (hdr.pload.feature21 <= 5357) 
                                            meta.class = 1;
                                        else 
                                            meta.class = 4;
                                else 
                                    if (hdr.pload.feature20 <= 4628) 
                                        if (hdr.pload.feature4 <= 4636) 
                                            meta.class = 3;
                                        else 
                                            meta.class = 1;
                                    else 
                                        meta.class = 1;
                    else 
                        if (hdr.pload.feature29 <= 5799) 
                            meta.class = 1;
                        else 
                            if (hdr.pload.feature31 <= 6987) 
                                meta.class = 3;
                            else 
                                meta.class = 1;
                else 
                    if (hdr.pload.feature17 <= 5955) 
                        if (hdr.pload.feature31 <= 3661) 
                            meta.class = 7;
                        else 
                            if (hdr.pload.feature2 <= 5619) 
                                meta.class = 3;
                            else 
                                if (hdr.pload.feature11 <= 4784) 
                                    if (hdr.pload.feature34 <= 6406) 
                                        if (hdr.pload.feature26 <= 5947) 
                                            meta.class = 3;
                                        else 
                                            if (hdr.pload.feature33 <= 6332) 
                                                if (hdr.pload.feature19 <= 4538) 
                                                    meta.class = 3;
                                                else 
                                                    meta.class = 4;
                                            else 
                                                meta.class = 3;
                                    else 
                                        meta.class = 3;
                                else 
                                    if (hdr.pload.feature7 <= 4571) 
                                        meta.class = 4;
                                    else 
                                        if (hdr.pload.feature35 <= 4571) 
                                            meta.class = 4;
                                        else 
                                            meta.class = 3;
                    else 
                        meta.class = 3;
                        
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