from scapy.all import *

in_file1 = "/home/admin1/netronome_tests/cicids/pcap/bruteForceTest.pcap"
in_file2 = "/home/admin1/netronome_tests/cicids/pcap/goldenEyeTest.pcap"
in_file3 = "/home/admin1/netronome_tests/cicids/pcap/hulkTest.pcap"
in_file4 = "/home/admin1/netronome_tests/cicids/pcap/portScanTest.pcap"
in_file5 = "/home/admin1/netronome_tests/cicids/pcap/slowHttpTest.pcap"
in_file6 = "/home/admin1/netronome_tests/cicids/pcap/slowLorisTest.pcap"
in_file7 = "/home/admin1/netronome_tests/cicids/pcap/thurBenignTest.pcap"
in_file8 = "/home/admin1/netronome_tests/cicids/pcap/wedBenignTest.pcap"

labels = ['wa_brute_force', 'dos_goldeneye', 'dos_hulk', 'i_portscan', 'dos_slowhttptest', 'dos_slowloris', 'benign', 'benign']

reader1 = PcapReader(in_file1)
reader2 = PcapReader(in_file2)
reader3 = PcapReader(in_file3)
reader4 = PcapReader(in_file4)
reader5 = PcapReader(in_file5)
reader6 = PcapReader(in_file6)
reader7 = PcapReader(in_file7)
reader8 = PcapReader(in_file8)
pktTest = PcapWriter("/home/admin1/netronome_tests/cicids/pktTest.pcap")

pkt_num = 0
with open("/home/admin1/netronome_tests/cicids/trueLabels.txt", "w") as test_file:  # ground truth labels for test set
    for i, reader in enumerate([reader1, reader2, reader3, reader4, reader5, reader6, reader7, reader8]):
        for pkt in reader:

            if (pkt_num % 1000000 == 0):
                print(f"Made it through {pkt_num} packets")

            pkt[Ether].dst = "00:15:4d:13:79:ac" 
            pkt[Ether].src = "08:c0:eb:a6:de:3d"
    
            if (not pkt.haslayer(IP)):
                print("We have a problem")

            pkt[IP].src = "10.0.0.1"
            pkt[IP].dst = "10.0.0.2"
            pkt[IP].options = []
            pkt[Ether].type = 0x4d49
    
            pktTest.write(pkt)
            print("{}".format(labels[i]), file=test_file)
            pkt_num += 1

print(pkt_num+1)


for i, pkt in enumerate(PcapReader(in_file1)):
    if (i >= 1000):
        break

    pkt[Ether].dst = "00:15:4d:13:79:ac"
    pkt[Ether].src = "08:c0:eb:a6:de:3d"

    if (not pkt.haslayer(IP)):
        print("We have a problem")

    pkt[IP].src = "10.0.0.1"
    pkt[IP].dst = "10.0.0.2"
    pkt[IP].options = []
    pkt[Ether].type = 0x4d49

    pktTest.write(pkt)

print(i)
