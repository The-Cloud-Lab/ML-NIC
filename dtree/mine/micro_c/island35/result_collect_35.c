#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL result_signal1;
__visible __xread uint32_t result_xfer1[4];

__visible SIGNAL result_signal2;
__visible __xread uint32_t result_xfer2[4];

__visible SIGNAL result_signal3;
__visible __xread uint32_t result_xfer3[4];

__visible SIGNAL result_signal4;
__visible __xread uint32_t result_xfer4[4];

__visible SIGNAL result_signal5;
__visible __xread uint32_t result_xfer5[4];

__visible SIGNAL result_signal6;
__visible __xread uint32_t result_xfer6[4];

__visible SIGNAL result_signal7;
__visible __xread uint32_t result_xfer7[4];

__visible SIGNAL result_signal8;
__visible __xread uint32_t result_xfer8[4];

__remote SIGNAL complete_signal;
__remote __xread uint32_t complete_xfer;

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t results_gpr1[4];
    __gpr uint32_t results_gpr2[4];
    __gpr uint32_t results_gpr3[4];
    __gpr uint32_t results_gpr4[4];
    __gpr uint32_t results_gpr5[4];
    __gpr uint32_t results_gpr6[4];
    __gpr uint32_t results_gpr7[4];
    __gpr uint32_t results_gpr8[4];
    __xwrite uint32_t final_result_write;
    
    __lmem uint8_t path_class[] = {1, 4, 4, 1, 4, 1, 1, 4, 5, 1, 5, 1, 5, 5, 3, 3, 4, 1, 3, 1, 5, 5, 1, 1, 3, 4, 5, 3, 5, 1, 5, 1, 5, 1, 4, 3, 4, 4, 5, 3, 3, 4, 5, 1, 4, 3, 5, 3, 4, 3, 4, 3, 5, 4, 3, 5, 4, 3, 3, 5, 5, 5, 3, 4, 5, 5, 5, 3, 5, 3, 5, 5, 4, 3, 5, 5, 5, 3, 3, 2, 5, 3, 3, 4, 3, 3, 5, 5, 4, 4, 2, 4, 4, 4, 2, 4, 2, 2, 2, 2, 3, 3, 4, 4, 2, 5, 2, 4, 3, 2, 2, 2, 3, 2};    
    
    __assign_relative_register(&result_signal1, 2);
    __assign_relative_register(&result_signal2, 3);
    __assign_relative_register(&result_signal3, 4);
    __assign_relative_register(&result_signal4, 5);
    __assign_relative_register(&result_signal5, 6);
    __assign_relative_register(&result_signal6, 7);
    __assign_relative_register(&result_signal7, 8);
    __assign_relative_register(&result_signal8, 9);
    __assign_relative_register(&local_signal, 10);
    
    __implicit_write(&result_signal1, sizeof(result_signal1));
    __implicit_write(result_xfer1, sizeof(result_xfer1));
    
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
    
    __implicit_write(&result_signal8, sizeof(result_signal8));
    __implicit_write(result_xfer8, sizeof(result_xfer8));    
    
        
    for (;;) {
        __wait_for_all(&result_signal1, &result_signal2, &result_signal3, &result_signal4, &result_signal5, &result_signal6, &result_signal7, &result_signal8);
                
        // Collect all the possible paths
        reg_cp(results_gpr1, result_xfer1, sizeof(results_gpr1));
        reg_cp(results_gpr2, result_xfer2, sizeof(results_gpr2));
        reg_cp(results_gpr3, result_xfer3, sizeof(results_gpr3));
        reg_cp(results_gpr4, result_xfer4, sizeof(results_gpr4));
        reg_cp(results_gpr5, result_xfer5, sizeof(results_gpr5));
        reg_cp(results_gpr6, result_xfer6, sizeof(results_gpr6));
        reg_cp(results_gpr7, result_xfer7, sizeof(results_gpr7));
        reg_cp(results_gpr8, result_xfer8, sizeof(results_gpr8));
        
        // Compute final path
        results_gpr8[0] = results_gpr1[0] & results_gpr2[0] & results_gpr3[0] & results_gpr4[0] & results_gpr5[0] & results_gpr6[0] & results_gpr7[0] & results_gpr8[0];
        
        results_gpr8[1] = results_gpr1[1] & results_gpr2[1] & results_gpr3[1] & results_gpr4[1] & results_gpr5[1] & results_gpr6[1] & results_gpr7[1] & results_gpr8[1];
        
        results_gpr8[2] = results_gpr1[2] & results_gpr2[2] & results_gpr3[2] & results_gpr4[2] & results_gpr5[2] & results_gpr6[2] & results_gpr7[2] & results_gpr8[2];
        
        results_gpr8[3] = results_gpr1[3] & results_gpr2[3] & results_gpr3[3] & results_gpr4[3] & results_gpr5[3] & results_gpr6[3] & results_gpr7[3] & results_gpr8[3];
        
        // Calculate leaf node index
        if (results_gpr8[0] != 0)
            results_gpr8[0] = ffs(results_gpr8[0]) + 96;
        else if (results_gpr8[1] != 0)
            results_gpr8[0] = ffs(results_gpr8[1]) + 64;
        else if (results_gpr8[2] != 0)
            results_gpr8[0] = ffs(results_gpr8[2]) + 32;
        else
            results_gpr8[0] = ffs(results_gpr8[3]);
        
        // Get class prediction
        results_gpr8[0] = (uint32_t)(path_class[results_gpr8[0]]);
        reg_cp(&final_result_write, results_gpr8, sizeof(final_result_write));

        remote_me_reg_write_signal_remote(&final_result_write, 35, 0, 0, 
                                          __xfer_reg_number(&complete_xfer, __nfp_meid(35, 0)) + (__ctx() * 32), 
                                          sizeof(complete_xfer), &local_signal);    
    }
    
    return 0;
}
