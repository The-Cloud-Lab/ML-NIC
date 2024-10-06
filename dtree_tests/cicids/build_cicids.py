from scapy.all import *

in_file1 = "../dtree_tests/cicids/pcap/bruteForceTest.pcap"
in_file2 = "../dtree_tests/cicids/pcap/goldenEyeTest.pcap"
in_file3 = "../dtree_tests/cicids/pcap/hulkTest.pcap"
in_file4 = "../dtree_tests/cicids/pcap/portScanTest.pcap"
in_file5 = "../dtree_tests/cicids/pcap/slowHttpTest.pcap"
in_file6 = "../dtree_tests/cicids/pcap/slowLorisTest.pcap"
in_file7 = "../dtree_tests/cicids/pcap/thurBenignTest.pcap"
in_file8 = "../dtree_tests/cicids/pcap/wedBenignTest.pcap"

labels = ['wa_brute_force', 'dos_goldeneye', 'dos_hulk', 'i_portscan', 'dos_slowhttptest', 'dos_slowloris', 'benign', 'benign']

reader1 = PcapReader(in_file1)
reader2 = PcapReader(in_file2)
reader3 = PcapReader(in_file3)
reader4 = PcapReader(in_file4)
reader5 = PcapReader(in_file5)
reader6 = PcapReader(in_file6)
reader7 = PcapReader(in_file7)
reader8 = PcapReader(in_file8)
nicTest = PcapWriter("../dtree_tests/cicids/nicTest.pcap")
cpuTest = PcapWriter("../dtree_tests/cicids/cpuTest.pcap")


# Add packets for CPU & NIC latency measure
pkt_num = 0
for pkt in PcapReader(in_file8):
    if (pkt_num >= 1000):
        break

    if (not pkt.haslayer(IP)):
        print("We have a problem")

    if (pkt.haslayer(UDP)):
        pkt[Ether].dst = "<dst_mac>"
        pkt[Ether].src = "<src_mac>"
        pkt[IP].src = "10.0.0.1"
        pkt[IP].dst = "10.0.0.2"
        pkt[IP].options = []
        pkt[UDP].sport = 5005
        pkt[UDP].dport = 5005

        if (pkt[IP].len > len(pkt[IP])):
            zero_pad = b''
            gap = pkt[IP].len - len(pkt[IP])

            for i in range(gap):
                zero_pad += b'\x00'

            pkt.load += zero_pad


        del pkt.chksum
        pkt2 = pkt.__class__(bytes(pkt))

        cpuTest.write(pkt2)

        pkt2[Ether].type = 0x4d49
        nicTest.write(pkt2)

        pkt_num += 1



# Add packets for CPU & NIC effectiveness measure
pkt_num = 0
with open("../dtree_tests/cicids/trueLabels.txt", "w") as test_file:  # ground truth labels for test set
    for i, reader in enumerate([reader1, reader2, reader3, reader4, reader5, reader6, reader7, reader8]):
        for pkt in reader:

            if (pkt_num % 1000000 == 0):
                print(f"Made it through {pkt_num} packets")

            if (not pkt.haslayer(IP)):
                print("We have a problem")

            pkt[Ether].type = 0x4d49
            pkt[Ether].dst = "<dst_mac>"
            pkt[Ether].src = "<src_mac>"
            pkt[IP].src = "10.0.0.1"
            pkt[IP].dst = "10.0.0.2"
            pkt[IP].options = []

            nicTest.write(pkt)
            cpuTest.write(pkt)

            print("{}".format(labels[i]), file=test_file)
            pkt_num += 1                                                                                    
