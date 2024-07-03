import pandas as pd
from scapy.all import *
from time import sleep


# Verified: slowLoris, slowHttp, goldenEye, bruteForce, portScan, hulk, wedBenign, thurBenign
df = pd.read_csv("/home/admin2/ML_NIC/datasets/cicids2017/thurBenignTest.csv")
test_pcap = PcapReader("/home/admin2/ML_NIC/datasets/cicids2017/thurBenignTest.pcap")

for i, pkt in enumerate(test_pcap):
    
    etherType = pkt[Ether].type
    ipSrc = pkt[IP].src
    ipDst = pkt[IP].dst
    ipProto = pkt[IP].proto
    ipFlags = int(pkt[IP].flags)
    pktSize = pkt[IP].len
    tcpDst = 0
    udpDst = 0
    tcpFlags = 0

    if (pkt.haslayer(TCP)):
        tcpDst = pkt[TCP].dport
        tcpFlags = int(pkt[TCP].flags) & 0x3F  # Extract URG, ACK, PSH, RST, SYN, FIN, flags

    elif (pkt.haslayer(UDP)):
        udpDst = pkt[UDP].dport

    etherMatch = (etherType == df.at[i, "etherType"])
    protoMatch = (ipProto == df.at[i, "ipProto"])
    ipFlagsMatch = (ipFlags == df.at[i, "ipFlags"])
    sizeMatch = (pktSize == df.at[i, "pktSize"])
    tcpDstMatch = (tcpDst == df.at[i, "tcpDst"])
    udpDstMatch = (udpDst == df.at[i, "udpDst"])
    tcpFlagsMatch = (tcpFlags == df.at[i, "tcpFlags"])


    if (not etherMatch):
        print(f"Failed etherMatch at {i}")
        print(f"Pcap: {etherType}")
        print(f"DF: {df.at[i, 'etherType']}")
        print()

    if (not protoMatch):
        print(f"Failed protoMatch at {i}")
        print(f"Pcap: {ipProto}")
        print(f"DF: {df.at[i, 'ipProto']}")
        print()

    if (not ipFlagsMatch):
        print(f"Failed ipFlags at {i}")
        print(f"Pcap: {ipFlags}")
        print(f"DF: {df.at[i, 'ipFlags']}")
        print()

    if (not sizeMatch):
        print(f"Failed sizeMatch at {i}")
        print(f"Pcap: {pktSize}")
        print(f"DF: {df.at[i, 'pktSize']}")
        print()

    if (not tcpDstMatch):
        print(f"Failed tcpDstMatch at {i}")
        print(f"Pcap: {tcpDst}")
        print(f"DF: {df.at[i, 'tcpDst']}")
        print()

    if (not udpDstMatch):
        print(f"Failed udpDstMatch at {i}")
        print(f"Pcap: {udpDst}")
        print(f"DF: {df.at[i, 'udpDst']}")
        print()

    if (not tcpFlagsMatch):
        print(f"Failed tcpFlagsMatch at {i}")
        print(f"Pcap: {tcpFlags}")
        print(f"DF: {df.at[i, 'tcpFlags']}")
        print()
   

print(i+1)
print(len(df))
