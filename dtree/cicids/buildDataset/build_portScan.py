from sklearn.model_selection import train_test_split
import pandas as pd
import numpy as np
import random
from scapy.all import *
from datetime import datetime
from zoneinfo import ZoneInfo

random.seed(99)
portscan_pcap = "/home/admin2/ML_NIC/datasets/cicids2017/portScan.pcap"
train_csv = "/home/admin2/ML_NIC/datasets/cicids2017/dataset_trainFlows.csv"
test_csv = "/home/admin2/ML_NIC/datasets/cicids2017/dataset_testFlows.csv"

trainFlows = pd.read_csv(train_csv, index_col=0)
testFlows = pd.read_csv(test_csv, index_col=0)

trainFlows['flow start time'] = trainFlows['flow start time'].apply(lambda x : datetime.fromtimestamp(x, ZoneInfo("Canada/Atlantic")))
trainFlows['flow end time'] = trainFlows['flow end time'].apply(lambda x : datetime.fromtimestamp(x, ZoneInfo("Canada/Atlantic")))

testFlows['flow start time'] = testFlows['flow start time'].apply(lambda x : datetime.fromtimestamp(x, ZoneInfo("Canada/Atlantic")))
testFlows['flow end time'] = testFlows['flow end time'].apply(lambda x : datetime.fromtimestamp(x, ZoneInfo("Canada/Atlantic")))

portScanTrain = trainFlows[trainFlows['label'] == "i_portscan"].reset_index().drop(columns=['Unnamed: 0'])
portScanTest = testFlows[testFlows['label'] == "i_portscan"].reset_index().drop(columns=['Unnamed: 0'])

train_df = pd.DataFrame(columns=["etherType", "ipProto", "ipFlags", "tcpDst", "udpDst", "pktSize", "tcpFlags", "label"]) 
test_df = pd.DataFrame(columns=["etherType", "ipProto", "ipFlags", "tcpDst", "udpDst", "pktSize", "tcpFlags", "label"])
test_pcap = "/home/admin2/ML_NIC/datasets/cicids2017/portScanTest.pcap"

test_writer = PcapWriter(test_pcap)
pcap_reader = PcapReader(portscan_pcap)
train_collect = {i:[] for i in range(len(portScanTrain))}
test_index = 0
for pkt in pcap_reader:
    tt = datetime.fromtimestamp(float(pkt.time), ZoneInfo("Canada/Atlantic"))
    if (not pkt.haslayer(IP) or pkt[IP].src != "192.168.10.8"):
        continue

    etherType = pkt[Ether].type
    ipSrc = pkt[IP].src
    ipDst = pkt[IP].dst
    ipProto = pkt[IP].proto
    ipFlags = int(pkt[IP].flags)
    pktSize = pkt[IP].len
    tcpSrc = 0
    tcpDst = 0
    udpSrc = 0
    udpDst = 0
    tcpFlags = 0

    if (pkt.haslayer(TCP)):
        tcpSrc = pkt[TCP].sport
        tcpDst = pkt[TCP].dport
        tcpFlags = int(pkt[TCP].flags) & 0x3F  # Extract URG, ACK, PSH, RST, SYN, FIN, flags

    elif (pkt.haslayer(UDP)):
        udpSrc = pkt[UDP].sport
        udpDst = pkt[UDP].dport

    src_port = tcpSrc + udpSrc
    dst_port = tcpDst + udpDst
    trainMatch = portScanTrain[(tt >= portScanTrain['flow start time']) & (tt <= portScanTrain['flow end time']) & (portScanTrain['src port'] == src_port) & (portScanTrain['dst port'] == dst_port) & (portScanTrain['IP proto'] == ipProto) & (portScanTrain['dst IP'] == ipDst)]
    testMatch = portScanTest[(tt >= portScanTest['flow start time']) & (tt <= portScanTest['flow end time']) & (portScanTest['src port'] == src_port) & (portScanTest['dst port'] == dst_port) & (portScanTest['IP proto'] == ipProto) & (portScanTest['dst IP'] == ipDst)]

    if (len(trainMatch) == 1):
        train_collect[trainMatch.index[0]].append([etherType, ipProto, ipFlags, tcpDst, udpDst, pktSize, tcpFlags])

    elif (len(testMatch) == 1):
        test_df.at[test_index, "etherType"] = etherType
        test_df.at[test_index, "ipProto"] = ipProto
        test_df.at[test_index, "ipFlags"] = ipFlags
        test_df.at[test_index, "tcpDst"] = tcpDst
        test_df.at[test_index, "udpDst"] = udpDst
        test_df.at[test_index, "pktSize"] = pktSize
        test_df.at[test_index, "tcpFlags"] = tcpFlags
        test_df.at[test_index, "label"] = "i_portscan"
        test_writer.write(pkt)
        test_index += 1


train_index = 0
for pkts in train_collect.values():
    samples = random.sample(pkts, 5)

    train_df.at[train_index, "etherType"] = samples[0][0]
    train_df.at[train_index, "ipProto"] = samples[0][1]
    train_df.at[train_index, "ipFlags"] = samples[0][2]
    train_df.at[train_index, "tcpDst"] = samples[0][3]
    train_df.at[train_index, "udpDst"] = samples[0][4]
    train_df.at[train_index, "pktSize"] = samples[0][5]
    train_df.at[train_index, "tcpFlags"] = samples[0][6]
    train_df.at[train_index, "label"] = "i_portscan"
    train_index += 1

    train_df.at[train_index, "etherType"] = samples[1][0]
    train_df.at[train_index, "ipProto"] = samples[1][1]
    train_df.at[train_index, "ipFlags"] = samples[1][2]
    train_df.at[train_index, "tcpDst"] = samples[1][3]
    train_df.at[train_index, "udpDst"] = samples[1][4]
    train_df.at[train_index, "pktSize"] = samples[1][5]
    train_df.at[train_index, "tcpFlags"] = samples[1][6]
    train_df.at[train_index, "label"] = "i_portscan"
    train_index += 1

    train_df.at[train_index, "etherType"] = samples[2][0]
    train_df.at[train_index, "ipProto"] = samples[2][1]
    train_df.at[train_index, "ipFlags"] = samples[2][2]
    train_df.at[train_index, "tcpDst"] = samples[2][3]
    train_df.at[train_index, "udpDst"] = samples[2][4]
    train_df.at[train_index, "pktSize"] = samples[2][5]
    train_df.at[train_index, "tcpFlags"] = samples[2][6]
    train_df.at[train_index, "label"] = "i_portscan"
    train_index += 1

    train_df.at[train_index, "etherType"] = samples[3][0]
    train_df.at[train_index, "ipProto"] = samples[3][1]
    train_df.at[train_index, "ipFlags"] = samples[3][2]
    train_df.at[train_index, "tcpDst"] = samples[3][3]
    train_df.at[train_index, "udpDst"] = samples[3][4]
    train_df.at[train_index, "pktSize"] = samples[3][5]
    train_df.at[train_index, "tcpFlags"] = samples[3][6]
    train_df.at[train_index, "label"] = "i_portscan"
    train_index += 1

    train_df.at[train_index, "etherType"] = samples[4][0]
    train_df.at[train_index, "ipProto"] = samples[4][1]
    train_df.at[train_index, "ipFlags"] = samples[4][2]
    train_df.at[train_index, "tcpDst"] = samples[4][3]
    train_df.at[train_index, "udpDst"] = samples[4][4]
    train_df.at[train_index, "pktSize"] = samples[4][5]
    train_df.at[train_index, "tcpFlags"] = samples[4][6]
    train_df.at[train_index, "label"] = "i_portscan"
    train_index += 1


train_df.to_csv("/home/admin2/ML_NIC/datasets/cicids2017/portScanTrain.csv", index=False)
test_df.to_csv("/home/admin2/ML_NIC/datasets/cicids2017/portScanTest.csv", index=False)
