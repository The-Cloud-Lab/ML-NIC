import sklearn
import numpy as np
from sklearn.metrics import precision_score, accuracy_score, f1_score, recall_score

dirt = "cicids"
model = "cpu"
groundTruth = []
preds = []

# Fill in prediction list
predFile = open(f"/home/admin1/netronome_tests/{dirt}/{model}_pred.txt", 'r')
for pred in predFile.readlines():
    preds.append(int(pred))


# Fill in groundTruth list
gtFile = open(f"/home/admin1/netronome_tests/{dirt}/trueLabels.txt", 'r')
for gt in gtFile.readlines():
    if (gt == 'benign\n'):
        groundTruth.append(0)
    elif (gt == 'dos_slowloris\n'):
        groundTruth.append(1)
    elif (gt == 'dos_slowhttptest\n'):
        groundTruth.append(2)
    elif (gt == 'dos_hulk\n'):
        groundTruth.append(3)
    elif (gt == 'dos_goldeneye\n'):
        groundTruth.append(4)
    elif (gt == 'wa_brute_force\n'):
        groundTruth.append(5)
    elif (gt == 'i_portscan\n'):
        groundTruth.append(6)

print(f"Accuracy Score: {accuracy_score(groundTruth, preds)}")
print(f"F1 Score (Macro): {f1_score(groundTruth, preds, average='macro')}")
print(f"Precision Score (Macro): {precision_score(groundTruth, preds, average='macro')}")
print(f"Recall Score (Macro): {recall_score(groundTruth, preds, average='macro')}")


time_decode = 5093.92
time_encode = 1699.682
latencies = []
latFile = open(f"/home/admin1/netronome_tests/{dirt}/{model}_lat.txt", 'r')
for lat in latFile.readlines():
    if (model == "cpu"):
        latencies.append(float(lat) - time_decode - time_encode)
    else:
        latencies.append(float(lat))


perc_50, perc_99, perc_99_9 = np.percentile(latencies, [50, 99, 99.9])

print(f"Average Latency: {perc_50}")
print(f"99th Percentile Latency: {perc_99}")
print(f"99.9th Percentile Latency: {perc_99_9}")
