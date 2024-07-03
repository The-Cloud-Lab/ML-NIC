from sklearn.model_selection import train_test_split
import pandas as pd
import numpy as np
import random
from scapy.all import *
from datetime import datetime
from zoneinfo import ZoneInfo

flow_csv = "/home/admin2/ML_NIC/datasets/cicids2017/dataset_flows.csv" 
flow_df = pd.read_csv(flow_csv)
flow_df = flow_df.set_index(['Unnamed: 0'])

benignFlows = flow_df[flow_df['label'] == "benign"]
slowlorisFlows = flow_df[flow_df['label'] == "dos_slowloris"]
slowhttpFlows = flow_df[flow_df['label'] == "dos_slowhttptest"]
hulkFlows = flow_df[flow_df['label'] == "dos_hulk"]
goldeneyeFlows = flow_df[flow_df['label'] == "dos_goldeneye"]
bforceFlows = flow_df[flow_df['label'] == "wa_brute_force"]
portscanFlows = flow_df[flow_df['label'] == "i_portscan"]

# Extract flows with at least five relevant packets in it
# for attack classes, these are packets from attacker to victim
benignFlows = benignFlows[benignFlows["num fwd pkts"] + benignFlows["num bwd pkts"] >= 5]
slowlorisFlows = slowlorisFlows[(slowlorisFlows['src IP'] == '172.16.0.1') & (slowlorisFlows['num fwd pkts'] >= 5)]
slowhttpFlows = slowhttpFlows[(slowhttpFlows['src IP'] == '172.16.0.1') & (slowhttpFlows['num fwd pkts'] >= 5)]
hulkFlows = hulkFlows[(hulkFlows['src IP'] == '172.16.0.1') & (hulkFlows['num fwd pkts'] >= 5)]
goldeneyeFlows = goldeneyeFlows[(goldeneyeFlows['src IP'] == '172.16.0.1') & (goldeneyeFlows['num fwd pkts'] >= 5)]
bforceFlows = bforceFlows[(bforceFlows['src IP'] == '172.16.0.1') & (bforceFlows['num fwd pkts'] >= 5)]
portscanFlows = portscanFlows[(portscanFlows['src IP'] == '192.168.10.8') & (portscanFlows['num fwd pkts'] >= 5)]

useFlows = pd.concat([benignFlows, slowlorisFlows, slowhttpFlows, hulkFlows, goldeneyeFlows, bforceFlows, portscanFlows])
y = useFlows['label']

trainFlows, testFlows = train_test_split(useFlows, train_size=100000, test_size=100000, random_state=99, stratify=y)

trainFlows.to_csv("/home/admin2/ML_NIC/datasets/cicids2017/dataset_trainFlows.csv", index=True)
testFlows.to_csv("/home/admin2/ML_NIC/datasets/cicids2017/dataset_testFlows.csv", index=True)
