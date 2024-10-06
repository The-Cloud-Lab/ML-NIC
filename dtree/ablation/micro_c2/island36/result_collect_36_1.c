#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL result_signal3;
__visible __xread uint32_t result_xfer3[2];

__visible SIGNAL result_signal4;
__visible __xread uint32_t result_xfer4[2];

__visible SIGNAL result_signal6;
__visible __xread uint32_t result_xfer6[2];

__visible SIGNAL result_signal7;
__visible __xread uint32_t result_xfer7[2];

__remote SIGNAL complete_signal;
__remote __xread uint32_t complete_xfer;

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t results_gpr3[2];
    __gpr uint32_t results_gpr4[2];
    __gpr uint32_t results_gpr6[2];
    __gpr uint32_t results_gpr7[2];
    __xwrite uint32_t final_result_write;
    
    __lmem uint8_t path_class[] = {0, 0, 3, 0, 1, 0, 0, 0, 0, 2, 0, 3, 2, 2, 2, 1, 0, 6, 2, 0, 6, 6, 0, 0, 0, 0, 0, 6, 6, 0, 0, 4, 0, 0, 6, 0, 0, 0, 0, 2, 0, 3, };  
    
    __assign_relative_register(&result_signal3, 2);
    __assign_relative_register(&result_signal4, 3);
    __assign_relative_register(&result_signal6, 4);
    __assign_relative_register(&result_signal7, 5);    
    __assign_relative_register(&local_signal, 6);
    
    __implicit_write(&result_signal3, sizeof(result_signal3));
    __implicit_write(result_xfer3, sizeof(result_xfer3));       
    
    __implicit_write(&result_signal4, sizeof(result_signal4));
    __implicit_write(result_xfer4, sizeof(result_xfer4));       
    
    __implicit_write(&result_signal6, sizeof(result_signal6));
    __implicit_write(result_xfer6, sizeof(result_xfer6));
    
    __implicit_write(&result_signal7, sizeof(result_signal7));
    __implicit_write(result_xfer7, sizeof(result_xfer7));
        
    for (;;) {
        __wait_for_all(&result_signal3, &result_signal4, &result_signal6, &result_signal7);
                
        // Collect all the possible paths
        reg_cp(results_gpr3, result_xfer3, sizeof(results_gpr3));
        reg_cp(results_gpr4, result_xfer4, sizeof(results_gpr4));
        reg_cp(results_gpr6, result_xfer6, sizeof(results_gpr6));
        reg_cp(results_gpr7, result_xfer7, sizeof(results_gpr7));

        // Compute final path
        results_gpr7[0] = results_gpr3[0] & results_gpr4[0] & results_gpr6[0] & results_gpr7[0];
        results_gpr7[1] = results_gpr3[1] & results_gpr4[1] & results_gpr6[1] & results_gpr7[1];
        
        // Calculate leaf node index
        if (results_gpr7[0] != 0)
            results_gpr7[0] = ffs(results_gpr7[0]) + 32;
        else
            results_gpr7[0] = ffs(results_gpr7[1]);       
        
        // Get class prediction
        results_gpr7[0] = (uint32_t)(path_class[results_gpr7[0]]);
        reg_cp(&final_result_write, results_gpr7, sizeof(final_result_write));

        remote_me_reg_write_signal_remote(&final_result_write, 36, 0, 0, 
                                          __xfer_reg_number(&complete_xfer, __nfp_meid(36, 0)) + (__ctx() * 32), 
                                          sizeof(complete_xfer), &local_signal);    
    }
    
    return 0;
}
