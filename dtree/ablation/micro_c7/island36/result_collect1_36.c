#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL result_signal2;
__visible __xread uint32_t result_xfer2[6];

__visible SIGNAL result_signal3;
__visible __xread uint32_t result_xfer3[6];

__visible SIGNAL result_signal4;
__visible __xread uint32_t result_xfer4[6];

__visible SIGNAL result_signal5;
__visible __xread uint32_t result_xfer5[6];

__remote SIGNAL result_signal8;
__remote __xread uint32_t result_xfer8[6];

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t results_gpr2[6];
    __gpr uint32_t results_gpr3[6];
    __gpr uint32_t results_gpr4[6];
    __gpr uint32_t results_gpr5[6];
    __xwrite uint32_t result_write[6];
                    
    __assign_relative_register(&result_signal2, 2);
    __assign_relative_register(&result_signal3, 3);
    __assign_relative_register(&result_signal4, 4);
    __assign_relative_register(&result_signal5, 5);
    __assign_relative_register(&local_signal, 8);
    
    __implicit_write(&result_signal2, sizeof(result_signal2));
    __implicit_write(result_xfer2, sizeof(result_xfer2));
    
    __implicit_write(&result_signal3, sizeof(result_signal3));
    __implicit_write(result_xfer3, sizeof(result_xfer3));       
    
    __implicit_write(&result_signal4, sizeof(result_signal4));
    __implicit_write(result_xfer4, sizeof(result_xfer4));       

    __implicit_write(&result_signal5, sizeof(result_signal5));
    __implicit_write(result_xfer5, sizeof(result_xfer5));
        
    for (;;) {
        __wait_for_all(&result_signal2, &result_signal3, &result_signal4, &result_signal5);
                
        // Collect all the possible paths
        reg_cp(results_gpr2, result_xfer2, sizeof(results_gpr2));
        reg_cp(results_gpr3, result_xfer3, sizeof(results_gpr3));
        reg_cp(results_gpr4, result_xfer4, sizeof(results_gpr4));
        reg_cp(results_gpr5, result_xfer5, sizeof(results_gpr5));

        // Compute intermediate path
        results_gpr5[0] = results_gpr2[0] & results_gpr3[0] & results_gpr4[0] & results_gpr5[0];
        results_gpr5[1] = results_gpr2[1] & results_gpr3[1] & results_gpr4[1] & results_gpr5[1];
        results_gpr5[2] = results_gpr2[2] & results_gpr3[2] & results_gpr4[2] & results_gpr5[2];
        results_gpr5[3] = results_gpr2[3] & results_gpr3[3] & results_gpr4[3] & results_gpr5[3];
        results_gpr5[4] = results_gpr2[4] & results_gpr3[4] & results_gpr4[4] & results_gpr5[4];
        results_gpr5[5] = results_gpr2[5] & results_gpr3[5] & results_gpr4[5] & results_gpr5[5];

        reg_cp(result_write, results_gpr5, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 8, 0, 
                                          __xfer_reg_number(result_xfer8, __nfp_meid(36, 8)) + (__ctx() * 32), 
                                          sizeof(result_xfer8), &local_signal);    
    }
    
    return 0;
}
