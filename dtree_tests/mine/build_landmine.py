import sklearn
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import MinMaxScaler, OneHotEncoder

import pandas as pd
import numpy as np
import pickle
from scapy.all import *


seed = 99

### Import Data ###
dataset = pd.read_excel("/home/admin1/netronome_tests/land_mine/land+mines-1/Mine_Dataset.xls",
                        sheet_name="Normalized_Data", names=['Voltage', 'Height', 'Soil Type', 'Mine Type'])

dataset_features = dataset.drop(columns=['Mine Type'])
dataset_labels = dataset['Mine Type']

### Build Train and Test Sets ###
X_train, X_test, y_train, y_test = train_test_split(dataset_features, dataset_labels,
                                                    random_state=seed, test_size=0.2,
                                                    stratify=dataset_labels)

X_train = X_train.to_numpy()
X_test = X_test.to_numpy()
y_test = y_test.to_numpy()


one_hot = OneHotEncoder(handle_unknown='ignore')
X_train = np.hstack((np.delete(X_train, 2, 1), one_hot.fit_transform(X_train[:, 2].reshape(-1, 1)).toarray()))
X_test = np.hstack((np.delete(X_test, 2, 1), one_hot.transform(X_test[:, 2].reshape(-1, 1)).toarray()))


### Data Translation for SmartNIC Models ###
total_bits = 16
dec_bits = 13

def num_translate1(number, total_bits, dec_bits):
    ret_val = 0
    for i in range(total_bits-1, -1, -1):
        comp_val = 2**(i - dec_bits)

        if (number - comp_val >= 0):
            ret_val += 2**i
            number -= comp_val

    return ret_val

def num_translate2(number, total_bits, dec_bits):
    return round(number * (2**dec_bits))

hexTest = []
testLen = len(X_test)
for i in range(testLen):
    intData = [num_translate2(feat, total_bits, dec_bits) for feat in X_test[i]]
    
    hexData = ""
    for feat in intData:
        hexFeat = "{:04x}".format(feat)
        hexData += hexFeat

    hexData = bytes.fromhex(hexData)
    hexTest.append(hexData)


nicTest = PcapWriter("/home/admin1/netronome_tests/land_mine/nicTest.pcap")
cpuTest = PcapWriter("/home/admin1/netronome_tests/land_mine/cpuTest.pcap")


### Add zero padding to make SmartNIC packets same size as CPU packets ###
padding = b'\x00'
for i in range(196):
    padding= padding + b'\x00'


### Test set too small, so repeat 1000 times for latency measure ###
with open("/home/admin1/netronome_tests/land_mine/trueLabels.txt", "w") as test_file:  # ground truth labels for test set
    print(f"Test Len: {testLen}")
    
    ethHdr = Ether(dst="00:15:4d:13:79:ac", src="08:c0:eb:a6:de:3d", type=0x4d49)
    ipHdr = IP(src="10.0.0.1", dst="10.0.0.2")
    udpHdr = UDP(dport=5005, sport=5005)
    for i in range(testLen):
        payload = Raw(load=hexTest[i] + padding)
        pkt = ethHdr/ipHdr/udpHdr/payload
        nicTest.write(pkt)
        print("{}".format(y_test[i]), file=test_file)



    i = 0
    testIndex = 0
    while (i < 1000):
        payload = Raw(load=hexTest[testIndex] + padding)
        pkt = ethHdr/ipHdr/udpHdr/payload
        nicTest.write(pkt)

        testIndex = (testIndex + 1) % testLen
        i += 1


### Best test set packets for CPU models ###
ethHdr = Ether(dst="00:15:4d:13:79:ac", src="08:c0:eb:a6:de:3d", type=0x0800)
ipHdr = IP(src="10.0.0.1", dst="10.0.0.2")
udpHdr = UDP(dport=5005, sport=5005)
for i in range(testLen):
    payload = Raw(load=pickle.dumps(X_test[i].reshape(1, -1)))
    pkt = ethHdr/ipHdr/udpHdr/payload
    cpuTest.write(pkt)



i = 0
testIndex = 0
while (i < 1000):
    payload = Raw(load=pickle.dumps(X_test[testIndex].reshape(1, -1)))
    pkt = ethHdr/ipHdr/udpHdr/payload
    cpuTest.write(pkt)

    testIndex = (testIndex + 1) % testLen
    i += 1

