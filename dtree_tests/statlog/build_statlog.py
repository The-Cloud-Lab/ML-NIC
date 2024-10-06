import sklearn
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import MinMaxScaler

import pandas as pd
import numpy as np
from scapy.all import *
import pickle


seed = 99

train_dataset = pd.read_csv("../dtree_tests/statlog/statlog+landsat+satellite/sat.trn", header=None,
                           sep=' ')
test_dataset = pd.read_csv("../dtree_tests/statlog/statlog+landsat+satellite/sat.tst", header=None,
                          sep=' ')

train_features = train_dataset.drop(columns=[36])
train_labels = train_dataset[36]

test_features = test_dataset.drop(columns=[36])
test_labels = test_dataset[36]

dataset_scaler = MinMaxScaler(feature_range=(0, 1), clip=True)
train_features = dataset_scaler.fit_transform(train_features)
test_features = dataset_scaler.transform(test_features)
test_labels = test_labels.to_numpy()

total_bits = 16
dec_bits = 13

### Add zero padding to make SmartNIC packets same size as CPU packets ###
padding = b'\x00'
for i in range(367):
    padding= padding + b'\x00'

with open("../dtree_tests/statlog/trueLabels.txt", "w") as test_file:  # ground truth labels for test set
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
        print("{}".format(test_labels[testIndex]), file=test_file)
      
### Test set packets for CPU models ###
ethHdr = Ether(dst="<dst_mac>", src="<src_mac>", type=0x0800)
ipHdr = IP(src="10.0.0.1", dst="10.0.0.2")
udpHdr = UDP(dport=5005, sport=5005)

# Latency test
i = 0
testIndex = 0
while (i < 1000):
    payload = Raw(load=pickle.dumps(test_features[testIndex].reshape(1, -1)))
    pkt = ethHdr/ipHdr/udpHdr/payload
    cpuTest.write(pkt)

    testIndex = (testIndex + 1) % testLen
    i += 1


# Effectiveness test
for i in range(testLen):
    payload = Raw(load=pickle.dumps(test_features[i].reshape(1, -1)))
    pkt = ethHdr/ipHdr/udpHdr/payload
    cpuTest.write(pkt)
