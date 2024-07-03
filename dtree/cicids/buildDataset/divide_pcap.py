from scapy.all import *
from datetime import datetime
from zoneinfo import ZoneInfo

# Wednesday Pcap Files
wed_pcap = "/home/admin2/ML_NIC/datasets/cicids2017/Wednesday-workingHours.pcap"
wedBenign = "/home/admin2/ML_NIC/datasets/cicids2017/wedBenign.pcap"
slowLoris = "/home/admin2/ML_NIC/datasets/cicids2017/slowLoris.pcap"
slowHttp = "/home/admin2/ML_NIC/datasets/cicids2017/slowHttp.pcap"
hulk = "/home/admin2/ML_NIC/datasets/cicids2017/hulk.pcap"
goldenEye = "/home/admin2/ML_NIC/datasets/cicids2017/goldenEye.pcap"
heartBleed = "/home/admin2/ML_NIC/datasets/cicids2017/heartBleed.pcap"

read_wed = PcapReader(wed_pcap)
write_wedBenign = PcapWriter(wedBenign)
write_slowLoris = PcapWriter(slowLoris)
write_slowHttp = PcapWriter(slowHttp)
write_hulk = PcapWriter(hulk)
write_goldenEye = PcapWriter(goldenEye)
write_heartBleed = PcapWriter(heartBleed)


wed_count = 0
pkt_list = {"wedBenign":0, "slowLoris":0, "slowHttp":0, "hulk":0, "goldenEye":0, "heartBleed":0}


# Attack packet timestamps
slowLoris_start = datetime.fromisoformat("2017-07-05T09:47:00").replace(tzinfo=ZoneInfo("Canada/Atlantic"))
slowLoris_end = datetime.fromisoformat("2017-07-05T10:10:59").replace(tzinfo=ZoneInfo("Canada/Atlantic"))

slowHttp_start = datetime.fromisoformat("2017-07-05T10:14:00").replace(tzinfo=ZoneInfo("Canada/Atlantic"))
slowHttp_end = datetime.fromisoformat("2017-07-05T10:35:59").replace(tzinfo=ZoneInfo("Canada/Atlantic"))

hulk_start = datetime.fromisoformat("2017-07-05T10:43:00").replace(tzinfo=ZoneInfo("Canada/Atlantic"))
hulk_end = datetime.fromisoformat("2017-07-05T11:00:59").replace(tzinfo=ZoneInfo("Canada/Atlantic"))

goldenEye_start = datetime.fromisoformat("2017-07-05T11:10:00").replace(tzinfo=ZoneInfo("Canada/Atlantic"))
goldenEye_end = datetime.fromisoformat("2017-07-05T11:23:59").replace(tzinfo=ZoneInfo("Canada/Atlantic"))

heartBleed_start = datetime.fromisoformat("2017-07-05T15:12:00").replace(tzinfo=ZoneInfo("Canada/Atlantic"))
heartBleed_end = datetime.fromisoformat("2017-07-05T15:32:59").replace(tzinfo=ZoneInfo("Canada/Atlantic"))


# Begin sorting wednesday packets
for wed_pkt in read_wed:
    if (not wed_pkt.haslayer(IP)):
        continue

    # Collect packet timestamp for labelling (pcap timezone is Atlantic Standard Time)
    tt = datetime.fromtimestamp(float(wed_pkt.time), ZoneInfo("Canada/Atlantic"))

    # Sort packets based on attack class
    # DoS slowloris (9:47 – 10:10 a.m.)
    if (((wed_pkt[IP].src == "172.16.0.1" and wed_pkt[IP].dst == "192.168.10.50") 
        or (wed_pkt[IP].src == "192.168.10.50" and wed_pkt[IP].dst == "172.16.0.1")) 
            and (tt >= slowLoris_start) and (tt <= slowLoris_end)): 
        write_slowLoris.write(wed_pkt)
        pkt_list["slowLoris"] += 1

    # DoS Slowhttptest (10:14 – 10:35 a.m.)
    elif (((wed_pkt[IP].src == "172.16.0.1" and wed_pkt[IP].dst == "192.168.10.50") 
        or (wed_pkt[IP].src == "192.168.10.50" and wed_pkt[IP].dst == "172.16.0.1")) 
            and (tt >= slowHttp_start) and (tt <= slowHttp_end)):
        write_slowHttp.write(wed_pkt)
        pkt_list["slowHttp"] += 1

    # DoS Hulk (10:43 – 11 a.m.)
    elif (((wed_pkt[IP].src == "172.16.0.1" and wed_pkt[IP].dst == "192.168.10.50") 
        or (wed_pkt[IP].src == "192.168.10.50" and wed_pkt[IP].dst == "172.16.0.1")) 
            and (tt >= hulk_start) and (tt <= hulk_end)):
        write_hulk.write(wed_pkt)
        pkt_list["hulk"] += 1

    # DoS GoldenEye (11:10 – 11:23 a.m.)
    elif (((wed_pkt[IP].src == "172.16.0.1" and wed_pkt[IP].dst == "192.168.10.50") 
        or (wed_pkt[IP].src == "192.168.10.50" and wed_pkt[IP].dst == "172.16.0.1")) 
            and (tt >= goldenEye_start) and (tt <= goldenEye_end)):
        write_goldenEye.write(wed_pkt)
        pkt_list["goldenEye"] += 1

    # Heartbleed Port 444 (15:12 - 15:32)
    elif (((wed_pkt[IP].src == "172.16.0.1" and wed_pkt[IP].dst == "192.168.10.51") 
        or (wed_pkt[IP].src == "192.168.10.51" and wed_pkt[IP].dst == "172.16.0.1")) 
            and (tt >= heartBleed_start) and (tt <= heartBleed_end)):
        write_heartBleed.write(wed_pkt)
        pkt_list["heartBleed"] += 1

    # Benign
    else:
        write_wedBenign.write(wed_pkt)
        pkt_list["wedBenign"] += 1


    wed_count += 1
    if (wed_count % 50000 == 0):
        print("Time: {}, Packets: {}\n{}\n".format(tt, wed_count, pkt_list))


print(f"Wednesday Count: {wed_count}")
print("Wednesday Division")
print(pkt_list)
print()


# Thursday Pcap Files
thur_pcap = "/home/admin2/ML_NIC/datasets/cicids2017/Thursday-WorkingHours.pcap"
thurBenign = "/home/admin2/ML_NIC/datasets/cicids2017/thurBenign.pcap"
bruteForce = "/home/admin2/ML_NIC/datasets/cicids2017/bruteForce.pcap"
xss = "/home/admin2/ML_NIC/datasets/cicids2017/xss.pcap"
sql = "/home/admin2/ML_NIC/datasets/cicids2017/sql.pcap"
meta = "/home/admin2/ML_NIC/datasets/cicids2017/meta.pcap"
cdisk = "/home/admin2/ML_NIC/datasets/cicids2017/cdisk.pcap"
dropbox = "/home/admin2/ML_NIC/datasets/cicids2017/dropbox.pcap"
portScan = "/home/admin2/ML_NIC/datasets/cicids2017/portScan.pcap"


read_thur = PcapReader(thur_pcap)
write_thurBenign = PcapWriter(thurBenign)
write_bruteForce = PcapWriter(bruteForce)
write_xss = PcapWriter(xss)
write_sql = PcapWriter(sql)
write_meta = PcapWriter(meta)
write_cdisk = PcapWriter(cdisk)
write_dropbox = PcapWriter(dropbox)
write_portScan = PcapWriter(portScan)

thur_count = 0
pkt_list = {"thurBenign":0, "bruteForce":0, "xss":0, "sql":0, "meta":0, "cdisk":0, "dropbox":0, "portScan":0}


# Attack packet timestamps
bruteForce_start = datetime.fromisoformat("2017-07-06T09:20:00").replace(tzinfo=ZoneInfo("Canada/Atlantic"))
bruteForce_end = datetime.fromisoformat("2017-07-06T10:00:59").replace(tzinfo=ZoneInfo("Canada/Atlantic"))

xss_start = datetime.fromisoformat("2017-07-06T10:15:00").replace(tzinfo=ZoneInfo("Canada/Atlantic"))
xss_end = datetime.fromisoformat("2017-07-06T10:35:59").replace(tzinfo=ZoneInfo("Canada/Atlantic"))

sql_start = datetime.fromisoformat("2017-07-06T10:40:00").replace(tzinfo=ZoneInfo("Canada/Atlantic"))
sql_end = datetime.fromisoformat("2017-07-06T10:42:59").replace(tzinfo=ZoneInfo("Canada/Atlantic"))

meta_start1 = datetime.fromisoformat("2017-07-06T14:19:00").replace(tzinfo=ZoneInfo("Canada/Atlantic"))
meta_end1 = datetime.fromisoformat("2017-07-06T14:19:59").replace(tzinfo=ZoneInfo("Canada/Atlantic"))
meta_start2 = datetime.fromisoformat("2017-07-06T14:20:00").replace(tzinfo=ZoneInfo("Canada/Atlantic"))
meta_end2 = datetime.fromisoformat("2017-07-06T14:21:59").replace(tzinfo=ZoneInfo("Canada/Atlantic"))
meta_start3 = datetime.fromisoformat("2017-07-06T14:33:00").replace(tzinfo=ZoneInfo("Canada/Atlantic"))
meta_end3 = datetime.fromisoformat("2017-07-06T14:35:59").replace(tzinfo=ZoneInfo("Canada/Atlantic"))

cdisk_start = datetime.fromisoformat("2017-07-06T14:53:00").replace(tzinfo=ZoneInfo("Canada/Atlantic"))
cdisk_end = datetime.fromisoformat("2017-07-06T15:00:59").replace(tzinfo=ZoneInfo("Canada/Atlantic"))

dropbox_start = datetime.fromisoformat("2017-07-06T15:04:00").replace(tzinfo=ZoneInfo("Canada/Atlantic"))
dropbox_end = datetime.fromisoformat("2017-07-06T15:45:59").replace(tzinfo=ZoneInfo("Canada/Atlantic"))

portScan_start = datetime.fromisoformat("2017-07-06T15:04:00").replace(tzinfo=ZoneInfo("Canada/Atlantic"))
portScan_end = datetime.fromisoformat("2017-07-06T15:45:59").replace(tzinfo=ZoneInfo("Canada/Atlantic"))


# Begin sorting thursday packets
for thur_pkt in read_thur:
    if (not thur_pkt.haslayer(IP)):
        continue

    # Get packet timestamp for labelling (pcap timezone is Atlantic Standard Time)
    tt = datetime.fromtimestamp(float(thur_pkt.time), ZoneInfo("Canada/Atlantic"))


    # Sort packets based on attack class
    # Web Attack – Brute Force (9:20 – 10 a.m.)
    if (((thur_pkt[IP].src == "172.16.0.1" and thur_pkt[IP].dst == "192.168.10.50") 
        or (thur_pkt[IP].src == "192.168.10.50" and thur_pkt[IP].dst == "172.16.0.1")) 
            and (tt >= bruteForce_start) and (tt <= bruteForce_end)):
        write_bruteForce.write(thur_pkt)
        pkt_list["bruteForce"] += 1

    # Web Attack – XSS (10:15 – 10:35 a.m.)
    elif (((thur_pkt[IP].src == "172.16.0.1" and thur_pkt[IP].dst == "192.168.10.50") 
        or (thur_pkt[IP].src == "192.168.10.50" and thur_pkt[IP].dst == "172.16.0.1")) 
            and (tt >= xss_start) and (tt <= xss_end)):
        write_xss.write(thur_pkt)
        pkt_list["xss"] += 1

    # Web Attack – Sql Injection (10:40 – 10:42 a.m.)
    elif (((thur_pkt[IP].src == "172.16.0.1" and thur_pkt[IP].dst == "192.168.10.50") 
        or (thur_pkt[IP].src == "192.168.10.50" and thur_pkt[IP].dst == "172.16.0.1")) 
            and (tt >= sql_start) and (tt <= sql_end)):
        write_sql.write(thur_pkt)
        pkt_list["sql"] += 1

    # Meta exploit Win Vista (14:19 and 14:20-14:21 p.m.) and (14:33 -14:35)
    elif (((thur_pkt[IP].src == "172.16.0.1" and thur_pkt[IP].dst == "192.168.10.8") 
        or (thur_pkt[IP].src == "192.168.10.8" and thur_pkt[IP].dst == "172.16.0.1")) 
            and (((tt >= meta_start1) and (tt <= meta_end1)) 
                or ((tt >= meta_start2) and (tt <= meta_end2)) 
                or ((tt >= meta_start3) and (tt <= meta_end3)))):
        write_meta.write(thur_pkt)
        pkt_list["meta"] += 1

    # Infiltration – Cool disk – MAC (14:53 p.m. – 15:00 p.m.)
    elif (((thur_pkt[IP].src == "172.16.0.1" and thur_pkt[IP].dst == "192.168.10.25") 
        or (thur_pkt[IP].src == "192.168.10.25" and thur_pkt[IP].dst == "172.16.0.1")) 
            and (tt >= cdisk_start) and (tt <= cdisk_end)):
        write_cdisk.write(thur_pkt)
        pkt_list["cdisk"] += 1

    # Infiltration – Dropbox download Win Vista (15:04 – 15:45 p.m.)
    elif (((thur_pkt[IP].src == "172.16.0.1" and thur_pkt[IP].dst == "192.168.10.8") 
        or (thur_pkt[IP].src == "192.168.10.8" and thur_pkt[IP].dst == "172.16.0.1")) 
            and (tt >= dropbox_start) and (tt <= dropbox_end)):
        write_dropbox.write(thur_pkt)
        pkt_list["dropbox"] += 1

    # Infiltration - PortScan (15:04 – 15:45 p.m.)
    elif ((thur_pkt[IP].src == "192.168.10.8" or thur_pkt[IP].dst == "192.168.10.8") 
            and (tt >= portScan_start) and (tt <= portScan_end)):
        write_portScan.write(thur_pkt)
        pkt_list["portScan"] += 1
    
    # Benign
    else:
        write_thurBenign.write(thur_pkt)
        pkt_list["thurBenign"] += 1

    thur_count += 1
    if (thur_count % 50000 == 0):
        print("Time: {}, Packets: {}\n{}\n".format(tt, thur_count, pkt_list))


print(f"Thursday Count: {thur_count}")
print("Packet Division")
print(pkt_list)

