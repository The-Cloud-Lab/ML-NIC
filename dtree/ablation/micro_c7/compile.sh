rm -f *.obj
rm -f *.list
rm -f *.fw
rm -f *.map

# --- Building blm.list
nfas -t -W3 -R -lm 0 -C -chip nfp-4xxx-b0  -DBLM_CUSTOM_CONFIG -DNFP_LIB_ANY_NFAS_VERSION -I. -I/c_packetprocessing/microc/blocks -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -I/components/standardlibrary/microcode/src -DBLM_CUSTOM_CONFIG -DSINGLE_NBI -DPKT_NBI_OFFSET= -DBLM_BLQ_EMEM_TYPE=emem -DNBII=8 -DBLM_INSTANCE_ID=0 -DBLM_INIT_EMU_RINGS -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/blocks/blm/ -I/c_packetprocessing/microc/blocks/blm/_h -I/c_packetprocessing/microc/blocks/blm/_uc -o blm.list /c_packetprocessing/microc/blocks/blm/blm_main.uc


### Island 32 ####
# --- Building pkt_collect.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fepkt_collect_32.list /dtree/ablation/micro_c7/island32/pkt_collect_32.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /c_packetprocessing/microc/lib/pkt/libpkt.c /c_packetprocessing/microc/lib/net/libnet.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature2.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature2_32.list /dtree/ablation/micro_c7/island32/feature2_32.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature3.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature3_32.list /dtree/ablation/micro_c7/island32/feature3_32.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature4.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature4_32.list /dtree/ablation/micro_c7/island32/feature4_32.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature5.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature5_32.list /dtree/ablation/micro_c7/island32/feature5_32.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature6.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature6_32.list /dtree/ablation/micro_c7/island32/feature6_32.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature7.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature7_32.list /dtree/ablation/micro_c7/island32/feature7_32.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build result_collect1.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Feresult_collect1_32.list /dtree/ablation/micro_c7/island32/result_collect1_32.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build result_collect2.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Feresult_collect2_32.list /dtree/ablation/micro_c7/island32/result_collect2_32.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c


### Island 33 ####
# --- Building pkt_collect.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fepkt_collect_33.list /dtree/ablation/micro_c7/island33/pkt_collect_33.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /c_packetprocessing/microc/lib/pkt/libpkt.c /c_packetprocessing/microc/lib/net/libnet.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature2.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature2_33.list /dtree/ablation/micro_c7/island33/feature2_33.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature3.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature3_33.list /dtree/ablation/micro_c7/island33/feature3_33.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature4.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature4_33.list /dtree/ablation/micro_c7/island33/feature4_33.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature5.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature5_33.list /dtree/ablation/micro_c7/island33/feature5_33.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature6.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature6_33.list /dtree/ablation/micro_c7/island33/feature6_33.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature7.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature7_33.list /dtree/ablation/micro_c7/island33/feature7_33.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build result_collect1.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Feresult_collect1_33.list /dtree/ablation/micro_c7/island33/result_collect1_33.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build result_collect2.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Feresult_collect2_33.list /dtree/ablation/micro_c7/island33/result_collect2_33.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c


### Island 34 ####
# --- Building pkt_collect.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fepkt_collect_34.list /dtree/ablation/micro_c7/island34/pkt_collect_34.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /c_packetprocessing/microc/lib/pkt/libpkt.c /c_packetprocessing/microc/lib/net/libnet.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature2.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature2_34.list /dtree/ablation/micro_c7/island34/feature2_34.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature3.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature3_34.list /dtree/ablation/micro_c7/island34/feature3_34.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature4.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature4_34.list /dtree/ablation/micro_c7/island34/feature4_34.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature5.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature5_34.list /dtree/ablation/micro_c7/island34/feature5_34.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature6.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature6_34.list /dtree/ablation/micro_c7/island34/feature6_34.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature7.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature7_34.list /dtree/ablation/micro_c7/island34/feature7_34.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build result_collect1.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Feresult_collect1_34.list /dtree/ablation/micro_c7/island34/result_collect1_34.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build result_collect2.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Feresult_collect2_34.list /dtree/ablation/micro_c7/island34/result_collect2_34.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c


### Island 35 ####
# --- Building pkt_collect.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fepkt_collect_35.list /dtree/ablation/micro_c7/island35/pkt_collect_35.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /c_packetprocessing/microc/lib/pkt/libpkt.c /c_packetprocessing/microc/lib/net/libnet.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature2.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature2_35.list /dtree/ablation/micro_c7/island35/feature2_35.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature3.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature3_35.list /dtree/ablation/micro_c7/island35/feature3_35.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature4.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature4_35.list /dtree/ablation/micro_c7/island35/feature4_35.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature5.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature5_35.list /dtree/ablation/micro_c7/island35/feature5_35.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature6.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature6_35.list /dtree/ablation/micro_c7/island35/feature6_35.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature7.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature7_35.list /dtree/ablation/micro_c7/island35/feature7_35.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build result_collect1.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Feresult_collect1_35.list /dtree/ablation/micro_c7/island35/result_collect1_35.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build result_collect2.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Feresult_collect2_35.list /dtree/ablation/micro_c7/island35/result_collect2_35.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c


### Island 36 ####
# --- Building pkt_collect.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fepkt_collect_36.list /dtree/ablation/micro_c7/island36/pkt_collect_36.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /c_packetprocessing/microc/lib/pkt/libpkt.c /c_packetprocessing/microc/lib/net/libnet.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature2.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature2_36.list /dtree/ablation/micro_c7/island36/feature2_36.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature3.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature3_36.list /dtree/ablation/micro_c7/island36/feature3_36.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature4.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature4_36.list /dtree/ablation/micro_c7/island36/feature4_36.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature5.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature5_36.list /dtree/ablation/micro_c7/island36/feature5_36.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature6.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature6_36.list /dtree/ablation/micro_c7/island36/feature6_36.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build feature7.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Fefeature7_36.list /dtree/ablation/micro_c7/island36/feature7_36.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build result_collect1.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Feresult_collect1_36.list /dtree/ablation/micro_c7/island36/result_collect1_36.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c

# --- Build result_collect2.list
nfcc -W3 -chip nfp-4xxx-b0 -Qspill=7 -Qnn_mode=1 -Qno_decl_volatile -single_dram_signal -Qnctx_mode=8 -FI config.h  -DBLM_CUSTOM_CONFIG -I. -I/dtree/land_mine/micro_c -I/c_packetprocessing/microc/include -I/c_packetprocessing/microc/lib -I/c_packetprocessing/microc/blocks/blm -I/c_packetprocessing/microc/blocks/blm/_h -I/components/standardlibrary/include -I/components/standardlibrary/microcode/include -Feresult_collect2_36.list /dtree/ablation/micro_c7/island36/result_collect2_36.c /c_packetprocessing/microc/lib/nfp/libnfp.c /c_packetprocessing/microc/lib/std/libstd.c /components/standardlibrary/microc/src/rtl.c


 # --- Link code
nfld -chip nfp-4xxx-b0 -mip -rtsyms -o cicids.fw -map cicids.map -u i32.me0 -l pkt_collect_32.list -u i32.me1 -l feature2_32.list -u i32.me2 -l feature3_32.list -u i32.me3 -l feature4_32.list -u i32.me4 -l feature5_32.list -u i32.me5 -l feature6_32.list -u i32.me6 -l feature7_32.list -u i32.me7 -l result_collect1_32.list -u i32.me8 -l result_collect2_32.list -u i33.me0 -l pkt_collect_33.list -u i33.me1 -l feature2_33.list -u i33.me2 -l feature3_33.list -u i33.me3 -l feature4_33.list -u i33.me4 -l feature5_33.list -u i33.me5 -l feature6_33.list -u i33.me6 -l feature7_33.list -u i33.me7 -l result_collect1_33.list -u i33.me8 -l result_collect2_33.list -u i34.me0 -l pkt_collect_34.list -u i34.me1 -l feature2_34.list -u i34.me2 -l feature3_34.list -u i34.me3 -l feature4_34.list -u i34.me4 -l feature5_34.list -u i34.me5 -l feature6_34.list -u i34.me6 -l feature7_34.list -u i34.me7 -l result_collect1_34.list -u i34.me8 -l result_collect2_34.list -u i35.me0 -l pkt_collect_35.list -u i35.me1 -l feature2_35.list -u i35.me2 -l feature3_35.list -u i35.me3 -l feature4_35.list -u i35.me4 -l feature5_35.list -u i35.me5 -l feature6_35.list -u i35.me6 -l feature7_35.list -u i35.me7 -l result_collect1_35.list -u i35.me8 -l result_collect2_35.list -u i36.me0 -l pkt_collect_36.list -u i36.me1 -l feature2_36.list -u i36.me2 -l feature3_36.list -u i36.me3 -l feature4_36.list -u i36.me4 -l feature5_36.list -u i36.me5 -l feature6_36.list -u i36.me6 -l feature7_36.list -u i36.me7 -l result_collect1_36.list -u i36.me8 -l result_collect2_36.list -u ila0.me0 -l blm.list -i i8 -e /components/standardlibrary/picocode/nfp6000/catamaran/catamaran.npfw
