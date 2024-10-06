import sklearn
import numpy as np
from sklearn.metrics import precision_score, accuracy_score, f1_score, recall_score

dirt = "gas"
model = "mC"
util = "N99"
groundTruth = []
preds = []


# Fill in prediction list
predFile = open(f"../dtree_tests/{dirt}/{model}_pred.txt", 'r')
for pred in predFile.readlines():
    preds.append(int(pred))


# Fill in groundTruth list
gtFile = open(f"../dtree_tests/{dirt}/trueLabels.txt", 'r')
for gt in gtFile.readlines():
    groundTruth.append(int(gt))

print(f"Accuracy Score: {accuracy_score(groundTruth, preds)}")
print(f"F1 Score (Macro): {f1_score(groundTruth, preds, average='macro')}")
print(f"Precision Score (Macro): {precision_score(groundTruth, preds, average='macro')}")
print(f"Recall Score (Macro): {recall_score(groundTruth, preds, average='macro')}")


time_decode = 9508.506
time_encode = 1212.492
latencies = []
latFile = open(f"../dtree_tests/{dirt}/{model}_lat{util}.txt", 'r')
for lat in latFile.readlines():
    if (model == "cpu"):
        latencies.append(float(lat) - time_decode - time_encode)
    else:
        latencies.append(float(lat))

perc_50, perc_99, perc_99_9 = np.percentile(latencies, [50, 99, 99.9])

print(f"Average Latency: {perc_50}")
print(f"99th Percentile Latency: {perc_99}")
print(f"99.9th Percentile Latency: {perc_99_9}")
