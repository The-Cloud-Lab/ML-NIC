# ML-NIC: Accelerating Machine Learning Inference using Smart Network Interface Cards
This repository contains our implementation of the ML-NIC framework, which maps and compiles trained machine learning models onto a Netronome SmartNIC.
The directory structure is as follows:
  - c_packetprocessing: a modified copy of the open-nfpsw/c_packetprocessing repository that contains essential functionality for our implementation. The modifications were made to correct a bug in packet header parsing and add functionality to communicate with other microengines on the Netronome SmartNIC asynchronously. 
  - dtree: contains Python code to map and compile trained decision tree models for four machine learning tasks and an ablation study onto the Netronome in Micro-C. In addition to our Micro-C implementations, we include code for our CPU and P4 baselines (where applicable). 
  - dtree_tests: contains Python test files that measure effectiveness and latency under different CPU loads and network link utilization. 

To replicate our results for a particular machine learning task that we used, please follow the setup described in our paper to link two servers (one containing the Netronome SmarNIC) together.

After completing the setup, our decision tree implementations for one of the four problems (i.e., mine, landsat, cicids, gas) can be run on the server hosting the Netronome SmartNIC by first compiling the Micro-C files using the compile.sh file located in the corresponding directory. This assumes the user has corrected for any directory paths specific to their system. Then, the firmware needs to be loaded onto the SmartNIC using the wire.sh file located in the init/ directory of each problem directory (i.e., dtree/mine/micro_c/init/wire.sh). To do so, run "./init/wire.sh <filename>.fw" on your system. Assuming no errors up to this point, the firmware should be loaded onto the Netronome and ready to classify model inference packets. 

On the other server, the packets for the corresponding task are created using the build_<task>.py file. Please note that to build the dataset we used for the cicids task, you need to label the raw dataset with the code found in dtree/cicids/buildDataset/. After running those steps, please return to dtree_tests/build_cicids.py to build the packets for the task. The other tasks do not require this. The effectiveness and latency raw data for our Micro-C implementation can be collected using the nicTransmit.c file. The compute_metrics.py file is then used to calculate the metrics used in our work. For more details on our experiments, please refer to our paper. 


