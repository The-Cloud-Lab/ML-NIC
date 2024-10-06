#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL result_signal2;
__visible __xread uint32_t result_xfer2[5];

__visible SIGNAL result_signal3;
__visible __xread uint32_t result_xfer3[5];

__visible SIGNAL result_signal4;
__visible __xread uint32_t result_xfer4[5];

__visible SIGNAL result_signal5;
__visible __xread uint32_t result_xfer5[5];

__visible SIGNAL result_signal6;
__visible __xread uint32_t result_xfer6[5];

__visible SIGNAL result_signal7;
__visible __xread uint32_t result_xfer7[5];

__remote SIGNAL complete_signal;
__remote __xread uint32_t complete_xfer;

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t results_gpr2[5];
    __gpr uint32_t results_gpr3[5];
    __gpr uint32_t results_gpr4[5];
    __gpr uint32_t results_gpr5[5];
    __gpr uint32_t results_gpr6[5];
    __gpr uint32_t results_gpr7[5];
    __xwrite uint32_t final_result_write;
    
    __lmem uint8_t path_class[] = {3, 1, 0, 0, 2, 2, 2, 1, 6, 6, 0, 0, 0, 6, 0, 6, 0, 0, 2, 0, 3, 6, 6, 6, 6, 0, 0, 0, 6, 0, 2, 3, 2, 0, 2, 0, 0, 0, 0, 0, 6, 0, 0, 0, 6, 0, 3, 5, 5, 0, 2, 6, 3, 0, 0, 6, 6, 0, 0, 0, 0, 0, 5, 4, 0, 0, 6, 0, 0, 6, 4, 0, 0, 0, 6, 0, 0, 6, 0, 6, 6, 0, 6, 6, 6, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 0, 0, 6, 0, 0, 4, 0, 0, 6, 6, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 6, 0, 6, 4, 3, 4, 3, 4, 4, 4, 0, 0, 3, 3, 0, 6, 0, 0, 2, 0, 0, 6, 0, 3, 3, 0, 0, 6, };
        
        
    __assign_relative_register(&result_signal2, 2);
    __assign_relative_register(&result_signal3, 3);
    __assign_relative_register(&result_signal4, 4);
    __assign_relative_register(&result_signal5, 5);
    __assign_relative_register(&result_signal6, 6);
    __assign_relative_register(&result_signal7, 7);    
    __assign_relative_register(&local_signal, 8);
    
    __implicit_write(&result_signal2, sizeof(result_signal2));
    __implicit_write(result_xfer2, sizeof(result_xfer2));
    
    __implicit_write(&result_signal3, sizeof(result_signal3));
    __implicit_write(result_xfer3, sizeof(result_xfer3));       
    
    __implicit_write(&result_signal4, sizeof(result_signal4));
    __implicit_write(result_xfer4, sizeof(result_xfer4));       

    __implicit_write(&result_signal5, sizeof(result_signal5));
    __implicit_write(result_xfer5, sizeof(result_xfer5));

    __implicit_write(&result_signal6, sizeof(result_signal6));
    __implicit_write(result_xfer6, sizeof(result_xfer6));
    
    __implicit_write(&result_signal7, sizeof(result_signal7));
    __implicit_write(result_xfer7, sizeof(result_xfer7));
        
    for (;;) {
        __wait_for_all(&result_signal2, &result_signal3, &result_signal4, &result_signal5, &result_signal6, &result_signal7);
                
        // Collect all the possible paths
        reg_cp(results_gpr2, result_xfer2, sizeof(results_gpr2));
        reg_cp(results_gpr3, result_xfer3, sizeof(results_gpr3));
        reg_cp(results_gpr4, result_xfer4, sizeof(results_gpr4));
        reg_cp(results_gpr5, result_xfer5, sizeof(results_gpr5));
        reg_cp(results_gpr6, result_xfer6, sizeof(results_gpr6));
        reg_cp(results_gpr7, result_xfer7, sizeof(results_gpr7));

        // Compute final path
        results_gpr7[0] = results_gpr2[0] & results_gpr3[0] & results_gpr4[0] & results_gpr5[0] & results_gpr6[0] & results_gpr7[0];
        results_gpr7[1] = results_gpr2[1] & results_gpr3[1] & results_gpr4[1] & results_gpr5[1] & results_gpr6[1] & results_gpr7[1];
        results_gpr7[2] = results_gpr2[2] & results_gpr3[2] & results_gpr4[2] & results_gpr5[2] & results_gpr6[2] & results_gpr7[2];
        results_gpr7[3] = results_gpr2[3] & results_gpr3[3] & results_gpr4[3] & results_gpr5[3] & results_gpr6[3] & results_gpr7[3];
        results_gpr7[4] = results_gpr2[4] & results_gpr3[4] & results_gpr4[4] & results_gpr5[4] & results_gpr6[4] & results_gpr7[4];

        
        // Calculate leaf node index
        if (results_gpr7[0] != 0)
            results_gpr7[0] = ffs(results_gpr7[0]) + 128;
        else if (results_gpr7[1] != 0)
            results_gpr7[0] = ffs(results_gpr7[1]) + 96;
        else if (results_gpr7[2] != 0)
            results_gpr7[0] = ffs(results_gpr7[2]) + 64;
        else if (results_gpr7[3] != 0)
            results_gpr7[0] = ffs(results_gpr7[3]) + 32;        
        else
            results_gpr7[0] = ffs(results_gpr7[4]);        
        
        // Get class prediction
        results_gpr7[0] = (uint32_t)(path_class[results_gpr7[0]]);
        reg_cp(&final_result_write, results_gpr7, sizeof(final_result_write));

        remote_me_reg_write_signal_remote(&final_result_write, 36, 0, 0, 
                                          __xfer_reg_number(&complete_xfer, __nfp_meid(36, 0)) + (__ctx() * 32), 
                                          sizeof(complete_xfer), &local_signal);    
    }
    
    return 0;
}
