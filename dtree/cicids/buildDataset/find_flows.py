from scapy.all import *
import pandas as pd
from datetime import datetime
from zoneinfo import ZoneInfo

# Define flows as all packets with the same (bidirectionally) source IP, destination IP, source port, destination port, IP protocol
def extract_flows(pcap_in, label):
    df = pd.DataFrame(columns=["src IP", "dst IP", "src port", "dst port", "IP proto", "flow start time", "flow end time",
        "num fwd pkts", "num bwd pkts", "label"])

    pcap_reader = PcapReader(pcap_in)
    for pkt in pcap_reader:
        if (not pkt.haslayer(IP)):
            continue

        pkt_time = float(pkt.time)
        ip_src = pkt[IP].src
        ip_dst = pkt[IP].dst
        ip_proto = pkt[IP].proto
        src_port = 0 
        dst_port = 0 

        if (pkt.haslayer(TCP)):
            src_port = pkt[TCP].sport
            dst_port = pkt[TCP].dport

        elif (pkt.haslayer(UDP)):
            src_port = pkt[UDP].sport
            dst_port = pkt[UDP].dport
    

        idx_fwd = hash(f"{ip_src}-{ip_dst}-{src_port}-{dst_port}-{ip_proto}")
        idx_bwd = hash(f"{ip_dst}-{ip_src}-{dst_port}-{src_port}-{ip_proto}")

        if (idx_fwd in df.index):
            df.at[idx_fwd, 'num fwd pkts'] += 1
            df.at[idx_fwd, 'flow end time'] = pkt_time

        elif (idx_bwd in df.index):
            df.at[idx_bwd, 'num bwd pkts'] += 1
            df.at[idx_bwd, 'flow end time'] = pkt_time

        else:
            df.at[idx_fwd, "src IP"] = ip_src
            df.at[idx_fwd, "dst IP"] = ip_dst
            df.at[idx_fwd, "src port"] = src_port
            df.at[idx_fwd, "dst port"] = dst_port
            df.at[idx_fwd, "IP proto"] = ip_proto
            df.at[idx_fwd, "flow start time"] = pkt_time 
            df.at[idx_fwd, "flow end time"] = pkt_time
            df.at[idx_fwd, "num fwd pkts"] = 1
            df.at[idx_fwd, "num bwd pkts"] = 0
            df.at[idx_fwd, "label"] = label

    return df


# Extract flows for relevant attack classes
wedBenign = "/home/admin2/ML_NIC/datasets/cicids2017/wedBenign.pcap"
slowLoris = "/home/admin2/ML_NIC/datasets/cicids2017/slowLoris.pcap"
slowHttp = "/home/admin2/ML_NIC/datasets/cicids2017/slowHttp.pcap"
hulk = "/home/admin2/ML_NIC/datasets/cicids2017/hulk.pcap"
goldenEye = "/home/admin2/ML_NIC/datasets/cicids2017/goldenEye.pcap"
thurBenign = "/home/admin2/ML_NIC/datasets/cicids2017/thurBenign.pcap"
bruteForce = "/home/admin2/ML_NIC/datasets/cicids2017/bruteForce.pcap"
portScan = "/home/admin2/ML_NIC/datasets/cicids2017/portScan.pcap"

df1 = extract_flows(wedBenign, "benign")
print("wedBenign done")

df2 = extract_flows(slowLoris, "dos_slowloris")
print("slowLoris done")

df3 = extract_flows(slowHttp, "dos_slowhttptest")
print("slowHttp done")

df4 = extract_flows(hulk, "dos_hulk")
print("hulk done")

df5 = extract_flows(goldenEye, "dos_goldeneye")
print("goldenEye done")

df6 = extract_flows(thurBenign, "benign")
print("thurBenign done")

df7 = extract_flows(bruteForce, "wa_brute_force")
print("bruteForce done")

df8 = extract_flows(portScan, "i_portscan")
print("portScan done")

df = pd.concat([df1, df2, df3, df4, df5, df6, df7, df8])
df.to_csv("/home/admin2/ML_NIC/datasets/cicids2017/dataset_flows.csv", index=True)
