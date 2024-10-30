# ML-NIC: Accelerating Machine Learning Inference using Smart Network Interface Cards
This repository contains our implemention of the ML-NIC framework to map and compile trained machine learning models onto a Netronome SmartNIC.
The directory structure is as follows:
  - c_packetprocessing: a modified copy of the open-nfpsw/c_packetprocessing repository that contains essential functionality for our implemenetation. The modifications made were to correct for a bug in packet header parsing and add functionality to asynchronously communicate with other microengines on the Netronome SmartNIC. 
  - dtree: contains Python code to map and compile trained decision tree models for four machine learning tasks onto the Netronome in Micro-C. We also included the code used for our ablation study here. References to the datasets used for these tasks can be found in our paper. 
  - dtree_tests: contains Python test files uses to measure effectiveness and latency under different CPU loads/network link utilizations. 

To replicate our results for a particular machine learning task we used, please follow the setup described in our paper to link two servers (one containing the Netronome SmarNIC) together.
After completing the set up, our decision tree implementations for one of the four problems (i.e., mine, landsat, cicids, gas) can run by first compiling the Micro-C using the compile.sh file located in the corresponding directory. This assumes the user has corrected for any directory paths specific to their system. Then the firmware needs to be loaded onto the SmartNIC using the wire.sh file located in the init/ directory of each problem directory (i.e., dtree/mine/init/wire.sh). To do so, run "./init/wire.sh <filename>.fw" on your system. Assuming no errors up to this point, the firmware should be loaded onto the Netronome and ready to classify model inference packets. 


