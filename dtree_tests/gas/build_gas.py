import sklearn
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import MinMaxScaler

import pandas as pd
import numpy as np
from scapy.all import *
import pickle


seed = 99

batch1 = pd.read_csv("../dtree_tests/gas/gas+sensor+array+drift+dataset/batch1.dat",
                    header=None, sep=' \d+:')

batch2 = pd.read_csv("../dtree_tests/gas/gas+sensor+array+drift+dataset/batch2.dat",
                    header=None, sep=' \d+:')

batch3 = pd.read_csv("../dtree_tests/gas/gas+sensor+array+drift+dataset/batch3.dat",
                    header=None, sep=' \d+:')

batch4 = pd.read_csv("../dtree_tests/gas/gas+sensor+array+drift+dataset/batch4.dat",
                    header=None, sep=' \d+:')

batch5 = pd.read_csv("../dtree_tests/gas/gas+sensor+array+drift+dataset/batch5.dat",
                    header=None, sep=' \d+:')

batch6 = pd.read_csv("../dtree_tests/gas/gas+sensor+array+drift+dataset/batch6.dat",
                    header=None, sep=' \d+:')

batch7 = pd.read_csv("../dtree_tests/gas/gas+sensor+array+drift+dataset/batch7.dat",
                    header=None, sep=' \d+:')

batch8 = pd.read_csv("../dtree_tests/gas/gas+sensor+array+drift+dataset/batch8.dat",
                    header=None, sep=' \d+:')

batch9 = pd.read_csv("../dtree_tests/gas/gas+sensor+array+drift+dataset/batch9.dat",
                    header=None, sep=' \d+:')

batch10 = pd.read_csv("../dtree_tests/gas/gas+sensor+array+drift+dataset/batch10.dat",
                    header=None, sep=' \d+:')


dataset = pd.concat([batch1, batch2, batch3, batch4, batch5,
                    batch6, batch7, batch8, batch9, batch10], ignore_index=True, axis=0)

features = dataset.drop(columns=[0])
labels = dataset[0]

X_train, X_test, y_train, y_test = train_test_split(features, labels, test_size=0.2, random_state=seed,
                                                   stratify=labels)

minmax = MinMaxScaler(feature_range=(0, 1), clip=True)
X_train = minmax.fit_transform(X_train)
X_test = minmax.transform(X_test)
y_test = y_test.to_numpy()

total_bits = 16
dec_bits = 13

def num_translate(number, total_bits, dec_bits):
    return round(number * (2**dec_bits))

hexTest = []
testLen = len(X_test)
for i in range(testLen):
    intData = [num_translate(feat, total_bits, dec_bits) for feat in X_test[i]]

    hexData = ""
    for feat in intData:
        hexFeat = "{:04x}".format(feat)
        hexData += hexFeat

    hexData = bytes.fromhex(hexData)
    hexTest.append(hexData)


nicTest = PcapWriter("../dtree_tests/gas/nicTest.pcap")
cpuTest = PcapWriter("../dtree_tests/gas/cpuTest.pcap")


### Add zero padding to make SmartNIC packets same size as CPU packets ###
padding = b'\x00'
for i in range(919):
    padding= padding + b'\x00'


with open("../dtree_tests/gas/trueLabels.txt", "w") as test_file:  # ground truth labels for test set
    print(f"Test Len: {testLen}")

    ethHdr = Ether(dst="<dst_mac>", src="<src_mac>", type=0x4d49)
    ipHdr = IP(src="10.0.0.1", dst="10.0.0.2")
    udpHdr = UDP(dport=5005, sport=5005)

    # Latency test
    i = 0
    testIndex = 0
    while (i < 1000):
        payload = Raw(load=hexTest[testIndex] + padding)
        pkt = ethHdr/ipHdr/udpHdr/payload
        nicTest.write(pkt)

        testIndex = (testIndex + 1) % testLen
        i += 1


    # Effectiveness test
    for testIndex in range(testLen):
        payload = Raw(load=hexTest[testIndex] + padding)

        pkt = ethHdr/ipHdr/udpHdr/payload
        nicTest.write(pkt)
        print("{}".format(y_test[testIndex]), file=test_file)




### Test set packets for CPU models ###
ethHdr = Ether(dst="<dst_mac>", src="<src_mac>", type=0x0800)
ipHdr = IP(src="10.0.0.1", dst="10.0.0.2")
udpHdr = UDP(dport=5005, sport=5005)

# Latency test
i = 0
testIndex = 0
while (i < 1000):
    payload = Raw(load=pickle.dumps(X_test[testIndex].reshape(1, -1)))
    pkt = ethHdr/ipHdr/udpHdr/payload
    cpuTest.write(pkt)

    testIndex = (testIndex + 1) % testLen
    i += 1


# Effectiveness test
for i in range(testLen):
    payload = Raw(load=pickle.dumps(X_test[i].reshape(1, -1)))
    pkt = ethHdr/ipHdr/udpHdr/payload
    cpuTest.write(pkt)
