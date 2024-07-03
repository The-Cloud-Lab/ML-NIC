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
    bit<16> feature37;
    bit<16> feature38;
    bit<16> feature39;
    bit<16> feature40;
    bit<16> feature41;
    bit<16> feature42;
    bit<16> feature43;
    bit<16> feature44;
    bit<16> feature45;
    bit<16> feature46;
    bit<16> feature47;
    bit<16> feature48;
    bit<16> feature49;
    bit<16> feature50;
    bit<16> feature51;
    bit<16> feature52;
    bit<16> feature53;
    bit<16> feature54;
    bit<16> feature55;
    bit<16> feature56;
    bit<16> feature57;
    bit<16> feature58;
    bit<16> feature59;
    bit<16> feature60;
    bit<16> feature61;
    bit<16> feature62;
    bit<16> feature63;
    bit<16> feature64;
    bit<16> feature65;
    bit<16> feature66;
    bit<16> feature67;
    bit<16> feature68;
    bit<16> feature69;
    bit<16> feature70;
    bit<16> feature71;
    bit<16> feature72;
    bit<16> feature73;
    bit<16> feature74;
    bit<16> feature75;
    bit<16> feature76;
    bit<16> feature77;
    bit<16> feature78;
    bit<16> feature79;
    bit<16> feature80;
    bit<16> feature81;
    bit<16> feature82;
    bit<16> feature83;
    bit<16> feature84;
    bit<16> feature85;
    bit<16> feature86;
    bit<16> feature87;
    bit<16> feature88;
    bit<16> feature89;
    bit<16> feature90;
    bit<16> feature91;
    bit<16> feature92;
    bit<16> feature93;
    bit<16> feature94;
    bit<16> feature95;
    bit<16> feature96;
    bit<16> feature97;
    bit<16> feature98;
    bit<16> feature99;
    bit<16> feature100;
    bit<16> feature101;
    bit<16> feature102;
    bit<16> feature103;
    bit<16> feature104;
    bit<16> feature105;
    bit<16> feature106;
    bit<16> feature107;
    bit<16> feature108;
    bit<16> feature109;
    bit<16> feature110;
    bit<16> feature111;
    bit<16> feature112;
    bit<16> feature113;
    bit<16> feature114;
    bit<16> feature115;
    bit<16> feature116;
    bit<16> feature117;
    bit<16> feature118;
    bit<16> feature119;
    bit<16> feature120;
    bit<16> feature121;
    bit<16> feature122;
    bit<16> feature123;
    bit<16> feature124;
    bit<16> feature125;
    bit<16> feature126;
    bit<16> feature127;
    bit<16> feature128;
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
    if (hdr.pload.feature69 <= 196) 
        if (hdr.pload.feature116 <= 1753) 
            if (hdr.pload.feature105 <= 2097) 
                if (hdr.pload.feature68 <= 139) 
                    if (hdr.pload.feature82 <= 262) 
                        if (hdr.pload.feature33 <= 1064) 
                            if (hdr.pload.feature122 <= 114) 
                                if (hdr.pload.feature18 <= 147) 
                                    if (hdr.pload.feature32 <= 8142) 
                                        meta.class = 2;
                                    else 
                                        meta.class = 6;
                                else 
                                    if (hdr.pload.feature16 <= 7708) 
                                        if (hdr.pload.feature85 <= 40) 
                                            meta.class = 5;
                                        else 
                                            if (hdr.pload.feature91 <= 229) 
                                                meta.class = 3;
                                            else 
                                                meta.class = 4;
                                    else 
                                        meta.class = 1;
                            else 
                                if (hdr.pload.feature16 <= 7659) 
                                    meta.class = 5;
                                else 
                                    meta.class = 2;
                        else 
                            if (hdr.pload.feature1 <= 368) 
                                if (hdr.pload.feature23 <= 7757) 
                                    meta.class = 3;
                                else 
                                    if (hdr.pload.feature102 <= 7938) 
                                        meta.class = 2;
                                    else 
                                        meta.class = 3;
                            else 
                                meta.class = 5;
                    else 
                        if (hdr.pload.feature106 <= 2072) 
                            if (hdr.pload.feature65 <= 81) 
                                meta.class = 3;
                            else 
                                if (hdr.pload.feature92 <= 98) 
                                    if (hdr.pload.feature3 <= 65) 
                                        if (hdr.pload.feature62 <= 7987) 
                                            meta.class = 2;
                                        else 
                                            meta.class = 3;
                                    else 
                                        meta.class = 1;
                                else 
                                    if (hdr.pload.feature104 <= 8069) 
                                        if (hdr.pload.feature15 <= 7774) 
                                            if (hdr.pload.feature23 <= 7725) 
                                                meta.class = 2;
                                            else 
                                                meta.class = 3;
                                        else 
                                            if (hdr.pload.feature111 <= 7708) 
                                                if (hdr.pload.feature10 <= 8) 
                                                    meta.class = 3;
                                                else 
                                                    meta.class = 2;
                                            else 
                                                meta.class = 2;
                                    else 
                                        if (hdr.pload.feature109 <= 24) 
                                            if (hdr.pload.feature97 <= 1392) 
                                                meta.class = 2;
                                            else 
                                                meta.class = 3;
                                        else 
                                            if (hdr.pload.feature23 <= 7757) 
                                                if (hdr.pload.feature3 <= 8) 
                                                    if (hdr.pload.feature106 <= 704) 
                                                        meta.class = 2;
                                                    else 
                                                        meta.class = 5;
                                                else 
                                                    meta.class = 2;
                                            else 
                                                meta.class = 3;
                        else 
                            meta.class = 3;
                else 
                    if (hdr.pload.feature2 <= 16) 
                        if (hdr.pload.feature65 <= 163) 
                            if (hdr.pload.feature114 <= 81) 
                                if (hdr.pload.feature61 <= 278) 
                                    meta.class = 6;
                                else 
                                    meta.class = 2;
                            else 
                                if (hdr.pload.feature4 <= 131) 
                                    meta.class = 4;
                                else 
                                    meta.class = 1;
                        else 
                            if (hdr.pload.feature50 <= 0) 
                                if (hdr.pload.feature100 <= 466) 
                                    if (hdr.pload.feature3 <= 188) 
                                        meta.class = 4;
                                    else 
                                        meta.class = 5;
                                else 
                                    meta.class = 6;
                            else 
                                if (hdr.pload.feature18 <= 991) 
                                    if (hdr.pload.feature50 <= 0) 
                                        meta.class = 3;
                                    else 
                                        if (hdr.pload.feature122 <= 376) 
                                            meta.class = 6;
                                        else 
                                            meta.class = 1;
                                else 
                                    meta.class = 2;
                    else 
                        if (hdr.pload.feature82 <= 294) 
                            if (hdr.pload.feature66 <= 139) 
                                meta.class = 5;
                            else 
                                if (hdr.pload.feature75 <= 196) 
                                    if (hdr.pload.feature77 <= 204) 
                                        meta.class = 6;
                                    else 
                                        meta.class = 4;
                                else 
                                    if (hdr.pload.feature20 <= 40) 
                                        if (hdr.pload.feature124 <= 32) 
                                            meta.class = 6;
                                        else 
                                            meta.class = 1;
                                    else 
                                        meta.class = 4;
                        else 
                            if (hdr.pload.feature17 <= 2654) 
                                if (hdr.pload.feature34 <= 32) 
                                    if (hdr.pload.feature16 <= 7684) 
                                        meta.class = 5;
                                    else 
                                        meta.class = 4;
                                else 
                                    if (hdr.pload.feature17 <= 2482) 
                                        meta.class = 1;
                                    else 
                                        meta.class = 4;
                            else 
                                meta.class = 2;
            else 
                if (hdr.pload.feature113 <= 1875) 
                    if (hdr.pload.feature114 <= 1736) 
                        if (hdr.pload.feature105 <= 2301) 
                            if (hdr.pload.feature121 <= 1499) 
                                meta.class = 3;
                            else 
                                if (hdr.pload.feature59 <= 835) 
                                    meta.class = 4;
                                else 
                                    meta.class = 2;
                        else 
                            if (hdr.pload.feature37 <= 16) 
                                meta.class = 5;
                            else 
                                meta.class = 3;
                    else 
                        meta.class = 2;
                else 
                    if (hdr.pload.feature105 <= 3203) 
                        meta.class = 2;
                    else 
                        if (hdr.pload.feature40 <= 8126) 
                            meta.class = 3;
                        else 
                            meta.class = 5;
        else 
            if (hdr.pload.feature106 <= 4407) 
                if (hdr.pload.feature49 <= 2277) 
                    meta.class = 1;
                else 
                    if (hdr.pload.feature29 <= 2252) 
                        meta.class = 2;
                    else 
                        meta.class = 1;
            else 
                meta.class = 3;
    else 
        if (hdr.pload.feature16 <= 7380) 
            if (hdr.pload.feature9 <= 1433) 
                if (hdr.pload.feature10 <= 16) 
                    if (hdr.pload.feature6 <= 7716) 
                        meta.class = 1;
                    else 
                        if (hdr.pload.feature96 <= 7929) 
                            meta.class = 4;
                        else 
                            meta.class = 5;
                else 
                    if (hdr.pload.feature26 <= 262) 
                        if (hdr.pload.feature81 <= 1343) 
                            meta.class = 6;
                        else 
                            if (hdr.pload.feature85 <= 401) 
                                meta.class = 5;
                            else 
                                if (hdr.pload.feature104 <= 7995) 
                                    meta.class = 1;
                                else 
                                    meta.class = 4;
                    else 
                        meta.class = 2;
            else 
                if (hdr.pload.feature108 <= 1327) 
                    if (hdr.pload.feature57 <= 2138) 
                        if (hdr.pload.feature65 <= 2375) 
                            meta.class = 4;
                        else 
                            meta.class = 6;
                    else 
                        if (hdr.pload.feature75 <= 3989) 
                            if (hdr.pload.feature15 <= 7241) 
                                if (hdr.pload.feature5 <= 16) 
                                    meta.class = 3;
                                else 
                                    if (hdr.pload.feature108 <= 1171) 
                                        if (hdr.pload.feature14 <= 6643) 
                                            if (hdr.pload.feature33 <= 2113) 
                                                meta.class = 5;
                                            else 
                                                meta.class = 5;
                                        else 
                                            if (hdr.pload.feature90 <= 1482) 
                                                if (hdr.pload.feature2 <= 8) 
                                                    if (hdr.pload.feature104 <= 8069) 
                                                        meta.class = 3;
                                                    else 
                                                        meta.class = 5;
                                                else 
                                                    if (hdr.pload.feature39 <= 7733) 
                                                        meta.class = 5;
                                                    else 
                                                        if (hdr.pload.feature9 <= 1515) 
                                                            meta.class = 5;
                                                        else 
                                                            meta.class = 3;
                                            else 
                                                meta.class = 2;
                                    else 
                                        if (hdr.pload.feature45 <= 131) 
                                            if (hdr.pload.feature115 <= 2899) 
                                                meta.class = 5;
                                            else 
                                                meta.class = 3;
                                        else 
                                            meta.class = 5;
                            else 
                                meta.class = 2;
                        else 
                            if (hdr.pload.feature6 <= 3629) 
                                meta.class = 5;
                            else 
                                if (hdr.pload.feature106 <= 4104) 
                                    meta.class = 4;
                                else 
                                    meta.class = 2;
                else 
                    if (hdr.pload.feature12 <= 3514) 
                        meta.class = 1;
                    else 
                        if (hdr.pload.feature91 <= 5226) 
                            meta.class = 6;
                        else 
                            meta.class = 5;
        else 
            if (hdr.pload.feature101 <= 352) 
                if (hdr.pload.feature36 <= 90) 
                    if (hdr.pload.feature17 <= 2179) 
                        if (hdr.pload.feature9 <= 286) 
                            meta.class = 4;
                        else 
                            if (hdr.pload.feature75 <= 49) 
                                meta.class = 2;
                            else 
                                if (hdr.pload.feature104 <= 8126) 
                                    meta.class = 6;
                                else 
                                    meta.class = 4;
                    else 
                        if (hdr.pload.feature68 <= 1310) 
                            if (hdr.pload.feature122 <= 851) 
                                if (hdr.pload.feature73 <= 221) 
                                    if (hdr.pload.feature128 <= 7905) 
                                        meta.class = 2;
                                    else 
                                        meta.class = 6;
                                else 
                                    if (hdr.pload.feature67 <= 180) 
                                        meta.class = 2;
                                    else 
                                        if (hdr.pload.feature42 <= 0) 
                                            if (hdr.pload.feature66 <= 98) 
                                                meta.class = 4;
                                            else 
                                                if (hdr.pload.feature32 <= 8167) 
                                                    if (hdr.pload.feature122 <= 811) 
                                                        meta.class = 5;
                                                    else 
                                                        if (hdr.pload.feature87 <= 7127) 
                                                            meta.class = 5;
                                                        else 
                                                            meta.class = 1;
                                                else 
                                                    if (hdr.pload.feature99 <= 286) 
                                                        meta.class = 5;
                                                    else 
                                                        meta.class = 4;
                                        else 
                                            meta.class = 1;
                            else 
                                if (hdr.pload.feature81 <= 1753) 
                                    meta.class = 1;
                                else 
                                    meta.class = 5;
                        else 
                            if (hdr.pload.feature66 <= 565) 
                                meta.class = 4;
                            else 
                                meta.class = 6;
                else 
                    if (hdr.pload.feature78 <= 7815) 
                        if (hdr.pload.feature77 <= 688) 
                            if (hdr.pload.feature16 <= 7479) 
                                if (hdr.pload.feature39 <= 7634) 
                                    if (hdr.pload.feature68 <= 622) 
                                        meta.class = 6;
                                    else 
                                        if (hdr.pload.feature76 <= 630) 
                                            meta.class = 4;
                                        else 
                                            meta.class = 2;
                                else 
                                    if (hdr.pload.feature74 <= 385) 
                                        if (hdr.pload.feature79 <= 7397) 
                                            if (hdr.pload.feature1 <= 196) 
                                                meta.class = 3;
                                            else 
                                                if (hdr.pload.feature69 <= 401) 
                                                    meta.class = 3;
                                                else 
                                                    if (hdr.pload.feature6 <= 8192) 
                                                        meta.class = 5;
                                                    else 
                                                        if (hdr.pload.feature83 <= 1130) 
                                                            meta.class = 5;
                                                        else 
                                                            meta.class = 3;
                                        else 
                                            meta.class = 6;
                                    else 
                                        meta.class = 2;
                            else 
                                if (hdr.pload.feature76 <= 303) 
                                    if (hdr.pload.feature103 <= 7643) 
                                        meta.class = 6;
                                    else 
                                        meta.class = 4;
                                else 
                                    if (hdr.pload.feature34 <= 81) 
                                        if (hdr.pload.feature104 <= 8101) 
                                            if (hdr.pload.feature105 <= 1466) 
                                                if (hdr.pload.feature126 <= 7847) 
                                                    meta.class = 1;
                                                else 
                                                    meta.class = 5;
                                            else 
                                                if (hdr.pload.feature36 <= 139) 
                                                    if (hdr.pload.feature50 <= 8) 
                                                        meta.class = 5;
                                                    else 
                                                        meta.class = 2;
                                                else 
                                                    if (hdr.pload.feature13 <= 778) 
                                                        if (hdr.pload.feature97 <= 3915) 
                                                            if (hdr.pload.feature56 <= 7888) 
                                                                if (hdr.pload.feature111 <= 7634) 
                                                                    if (hdr.pload.feature69 <= 729) 
                                                                        if (hdr.pload.feature72 <= 7479) 
                                                                            if (hdr.pload.feature78 <= 7462) 
                                                                                meta.class = 1;
                                                                            else 
                                                                                if (hdr.pload.feature77 <= 450) 
                                                                                    meta.class = 6;
                                                                                else 
                                                                                    meta.class = 4;
                                                                        else 
                                                                            if (hdr.pload.feature14 <= 7766) 
                                                                                if (hdr.pload.feature42 <= 0) 
                                                                                    meta.class = 1;
                                                                                else 
                                                                                    if (hdr.pload.feature18 <= 1802) 
                                                                                        if (hdr.pload.feature10 <= 65) 
                                                                                            if (hdr.pload.feature8 <= 7634) 
                                                                                                meta.class = 4;
                                                                                            else 
                                                                                                if (hdr.pload.feature29 <= 32) 
                                                                                                    meta.class = 6;
                                                                                                else 
                                                                                                    meta.class = 4;
                                                                                        else 
                                                                                            if (hdr.pload.feature62 <= 7315) 
                                                                                                meta.class = 4;
                                                                                            else 
                                                                                                meta.class = 6;
                                                                                    else 
                                                                                        if (hdr.pload.feature33 <= 3301) 
                                                                                            meta.class = 2;
                                                                                        else 
                                                                                            meta.class = 4;
                                                                            else 
                                                                                if (hdr.pload.feature34 <= 32) 
                                                                                    meta.class = 4;
                                                                                else 
                                                                                    meta.class = 5;
                                                                    else 
                                                                        if (hdr.pload.feature112 <= 8019) 
                                                                            meta.class = 4;
                                                                        else 
                                                                            meta.class = 1;
                                                                else 
                                                                    if (hdr.pload.feature95 <= 7217) 
                                                                        if (hdr.pload.feature96 <= 7987) 
                                                                            meta.class = 6;
                                                                        else 
                                                                            meta.class = 1;
                                                                    else 
                                                                        meta.class = 4;
                                                            else 
                                                                meta.class = 1;
                                                        else 
                                                            meta.class = 3;
                                                    else 
                                                        if (hdr.pload.feature96 <= 7806) 
                                                            meta.class = 4;
                                                        else 
                                                            meta.class = 6;
                                        else 
                                            if (hdr.pload.feature69 <= 540) 
                                                meta.class = 1;
                                            else 
                                                meta.class = 4;
                                    else 
                                        if (hdr.pload.feature39 <= 7348) 
                                            meta.class = 3;
                                        else 
                                            meta.class = 2;
                        else 
                            if (hdr.pload.feature124 <= 172) 
                                if (hdr.pload.feature20 <= 65) 
                                    if (hdr.pload.feature106 <= 991) 
                                        meta.class = 5;
                                    else 
                                        meta.class = 6;
                                else 
                                    if (hdr.pload.feature117 <= 180) 
                                        meta.class = 4;
                                    else 
                                        meta.class = 5;
                            else 
                                if (hdr.pload.feature20 <= 204) 
                                    if (hdr.pload.feature112 <= 7979) 
                                        meta.class = 4;
                                    else 
                                        if (hdr.pload.feature6 <= 5627) 
                                            meta.class = 4;
                                        else 
                                            if (hdr.pload.feature6 <= 7856) 
                                                if (hdr.pload.feature10 <= 57) 
                                                    if (hdr.pload.feature84 <= 1433) 
                                                        if (hdr.pload.feature29 <= 40) 
                                                            meta.class = 1;
                                                        else 
                                                            if (hdr.pload.feature98 <= 1572) 
                                                                meta.class = 1;
                                                            else 
                                                                meta.class = 4;
                                                    else 
                                                        meta.class = 4;
                                                else 
                                                    if (hdr.pload.feature115 <= 1122) 
                                                        meta.class = 4;
                                                    else 
                                                        meta.class = 1;
                                            else 
                                                if (hdr.pload.feature25 <= 2842) 
                                                    meta.class = 5;
                                                else 
                                                    meta.class = 4;
                                else 
                                    if (hdr.pload.feature106 <= 2654) 
                                        meta.class = 4;
                                    else 
                                        if (hdr.pload.feature32 <= 8134) 
                                            meta.class = 2;
                                        else 
                                            if (hdr.pload.feature119 <= 5816) 
                                                meta.class = 1;
                                            else 
                                                meta.class = 3;
                    else 
                        if (hdr.pload.feature26 <= 303) 
                            if (hdr.pload.feature12 <= 753) 
                                if (hdr.pload.feature25 <= 2678) 
                                    if (hdr.pload.feature12 <= 442) 
                                        if (hdr.pload.feature10 <= 0) 
                                            if (hdr.pload.feature33 <= 843) 
                                                if (hdr.pload.feature11 <= 106) 
                                                    meta.class = 4;
                                                else 
                                                    meta.class = 6;
                                            else 
                                                meta.class = 1;
                                        else 
                                            if (hdr.pload.feature83 <= 204) 
                                                meta.class = 6;
                                            else 
                                                if (hdr.pload.feature77 <= 180) 
                                                    if (hdr.pload.feature51 <= 516) 
                                                        meta.class = 6;
                                                    else 
                                                        if (hdr.pload.feature48 <= 8069) 
                                                            meta.class = 1;
                                                        else 
                                                            meta.class = 4;
                                                else 
                                                    if (hdr.pload.feature42 <= 0) 
                                                        if (hdr.pload.feature36 <= 278) 
                                                            if (hdr.pload.feature84 <= 229) 
                                                                if (hdr.pload.feature102 <= 7577) 
                                                                    meta.class = 4;
                                                                else 
                                                                    meta.class = 6;
                                                            else 
                                                                meta.class = 4;
                                                        else 
                                                            meta.class = 1;
                                                    else 
                                                        if (hdr.pload.feature60 <= 237) 
                                                            meta.class = 6;
                                                        else 
                                                            meta.class = 4;
                                    else 
                                        if (hdr.pload.feature76 <= 360) 
                                            if (hdr.pload.feature100 <= 753) 
                                                if (hdr.pload.feature73 <= 483) 
                                                    if (hdr.pload.feature12 <= 450) 
                                                        if (hdr.pload.feature2 <= 16) 
                                                            meta.class = 4;
                                                        else 
                                                            meta.class = 6;
                                                    else 
                                                        meta.class = 6;
                                                else 
                                                    meta.class = 5;
                                            else 
                                                meta.class = 1;
                                        else 
                                            if (hdr.pload.feature10 <= 16) 
                                                if (hdr.pload.feature72 <= 7610) 
                                                    if (hdr.pload.feature58 <= 0) 
                                                        meta.class = 2;
                                                    else 
                                                        meta.class = 5;
                                                else 
                                                    meta.class = 1;
                                            else 
                                                meta.class = 4;
                                else 
                                    if (hdr.pload.feature36 <= 114) 
                                        meta.class = 5;
                                    else 
                                        if (hdr.pload.feature34 <= 57) 
                                            if (hdr.pload.feature71 <= 7651) 
                                                meta.class = 4;
                                            else 
                                                if (hdr.pload.feature120 <= 7872) 
                                                    if (hdr.pload.feature117 <= 704) 
                                                        meta.class = 3;
                                                    else 
                                                        meta.class = 2;
                                                else 
                                                    meta.class = 1;
                                        else 
                                            if (hdr.pload.feature51 <= 753) 
                                                meta.class = 6;
                                            else 
                                                if (hdr.pload.feature9 <= 696) 
                                                    meta.class = 3;
                                                else 
                                                    meta.class = 4;
                            else 
                                if (hdr.pload.feature75 <= 540) 
                                    if (hdr.pload.feature68 <= 548) 
                                        if (hdr.pload.feature78 <= 7921) 
                                            if (hdr.pload.feature35 <= 311) 
                                                meta.class = 5;
                                            else 
                                                if (hdr.pload.feature25 <= 3391) 
                                                    meta.class = 4;
                                                else 
                                                    meta.class = 3;
                                        else 
                                            if (hdr.pload.feature43 <= 204) 
                                                meta.class = 5;
                                            else 
                                                if (hdr.pload.feature18 <= 679) 
                                                    meta.class = 6;
                                                else 
                                                    meta.class = 3;
                                    else 
                                        if (hdr.pload.feature36 <= 237) 
                                            meta.class = 6;
                                        else 
                                            if (hdr.pload.feature6 <= 8019) 
                                                meta.class = 6;
                                            else 
                                                meta.class = 4;
                                else 
                                    if (hdr.pload.feature118 <= 7905) 
                                        if (hdr.pload.feature7 <= 7233) 
                                            if (hdr.pload.feature103 <= 7602) 
                                                meta.class = 6;
                                            else 
                                                meta.class = 4;
                                        else 
                                            meta.class = 1;
                                    else 
                                        if (hdr.pload.feature12 <= 827) 
                                            meta.class = 1;
                                        else 
                                            meta.class = 5;
                        else 
                            if (hdr.pload.feature6 <= 8110) 
                                if (hdr.pload.feature1 <= 655) 
                                    meta.class = 2;
                                else 
                                    meta.class = 3;
                            else 
                                if (hdr.pload.feature76 <= 753) 
                                    if (hdr.pload.feature46 <= 6496) 
                                        meta.class = 3;
                                    else 
                                        meta.class = 4;
                                else 
                                    meta.class = 5;
            else 
                if (hdr.pload.feature28 <= 516) 
                    if (hdr.pload.feature71 <= 7741) 
                        if (hdr.pload.feature101 <= 466) 
                            if (hdr.pload.feature25 <= 4014) 
                                if (hdr.pload.feature124 <= 286) 
                                    if (hdr.pload.feature85 <= 434) 
                                        if (hdr.pload.feature89 <= 1343) 
                                            meta.class = 5;
                                        else 
                                            if (hdr.pload.feature66 <= 311) 
                                                meta.class = 1;
                                            else 
                                                meta.class = 6;
                                    else 
                                        meta.class = 4;
                                else 
                                    if (hdr.pload.feature48 <= 8028) 
                                        meta.class = 4;
                                    else 
                                        if (hdr.pload.feature125 <= 622) 
                                            meta.class = 4;
                                        else 
                                            if (hdr.pload.feature98 <= 499) 
                                                meta.class = 5;
                                            else 
                                                if (hdr.pload.feature112 <= 7987) 
                                                    if (hdr.pload.feature108 <= 720) 
                                                        meta.class = 4;
                                                    else 
                                                        meta.class = 1;
                                                else 
                                                    if (hdr.pload.feature100 <= 761) 
                                                        if (hdr.pload.feature118 <= 7200) 
                                                            meta.class = 4;
                                                        else 
                                                            meta.class = 1;
                                                    else 
                                                        if (hdr.pload.feature37 <= 73) 
                                                            if (hdr.pload.feature73 <= 860) 
                                                                meta.class = 4;
                                                            else 
                                                                meta.class = 1;
                                                        else 
                                                            if (hdr.pload.feature19 <= 1040) 
                                                                meta.class = 1;
                                                            else 
                                                                if (hdr.pload.feature125 <= 974) 
                                                                    meta.class = 4;
                                                                else 
                                                                    meta.class = 1;
                            else 
                                if (hdr.pload.feature92 <= 2441) 
                                    if (hdr.pload.feature46 <= 5005) 
                                        if (hdr.pload.feature77 <= 1040) 
                                            meta.class = 3;
                                        else 
                                            meta.class = 1;
                                    else 
                                        if (hdr.pload.feature95 <= 6447) 
                                            meta.class = 4;
                                        else 
                                            meta.class = 5;
                                else 
                                    meta.class = 2;
                        else 
                            if (hdr.pload.feature117 <= 598) 
                                if (hdr.pload.feature8 <= 7593) 
                                    if (hdr.pload.feature106 <= 1753) 
                                        meta.class = 4;
                                    else 
                                        if (hdr.pload.feature73 <= 385) 
                                            meta.class = 3;
                                        else 
                                            if (hdr.pload.feature31 <= 7962) 
                                                meta.class = 1;
                                            else 
                                                meta.class = 6;
                                else 
                                    meta.class = 1;
                            else 
                                if (hdr.pload.feature125 <= 1032) 
                                    if (hdr.pload.feature10 <= 90) 
                                        meta.class = 1;
                                    else 
                                        meta.class = 4;
                                else 
                                    meta.class = 1;
                    else 
                        if (hdr.pload.feature1 <= 516) 
                            if (hdr.pload.feature121 <= 3006) 
                                meta.class = 3;
                            else 
                                meta.class = 2;
                        else 
                            meta.class = 5;
                else 
                    if (hdr.pload.feature97 <= 4866) 
                        meta.class = 2;
                    else 
                        if (hdr.pload.feature70 <= 8019) 
                            meta.class = 1;
                        else 
                            if (hdr.pload.feature61 <= 1400) 
                                if (hdr.pload.feature55 <= 5685) 
                                    meta.class = 2;
                                else 
                                    meta.class = 3;
                            else 
                                meta.class = 5;

                        
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