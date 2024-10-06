#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL result_signal4;
__visible __xread uint32_t result_xfer4;

__visible SIGNAL result_signal6;
__visible __xread uint32_t result_xfer6;

__visible SIGNAL result_signal7;
__visible __xread uint32_t result_xfer7;

__remote SIGNAL complete_signal;
__remote __xread uint32_t complete_xfer;

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t results_gpr4;
    __gpr uint32_t results_gpr6;
    __gpr uint32_t results_gpr7;
    __xwrite uint32_t final_result_write;
    
    __lmem uint8_t path_class[] = {0, 0, 3, 0, 0, 0, 3, 3, 0, 0, 1, 0, 0, 2, 1, 2};
    
    __assign_relative_register(&result_signal4, 2);
    __assign_relative_register(&result_signal6, 3);
    __assign_relative_register(&result_signal7, 4);    
    __assign_relative_register(&local_signal, 5);
    
    __implicit_write(&result_signal4, sizeof(result_signal4));
    __implicit_write(&result_xfer4, sizeof(result_xfer4));       
    
    __implicit_write(&result_signal6, sizeof(result_signal6));
    __implicit_write(&result_xfer6, sizeof(result_xfer6));
    
    __implicit_write(&result_signal7, sizeof(result_signal7));
    __implicit_write(&result_xfer7, sizeof(result_xfer7));
        
    for (;;) {
        __wait_for_all(&result_signal4, &result_signal6, &result_signal7);
                
        // Collect all the possible paths
        reg_cp(&results_gpr4, &result_xfer4, sizeof(results_gpr4));
        reg_cp(&results_gpr6, &result_xfer6, sizeof(results_gpr6));
        reg_cp(&results_gpr7, &result_xfer7, sizeof(results_gpr7));

        // Compute final path
        results_gpr7 = results_gpr4 & results_gpr6 & results_gpr7;
        
        // Calculate leaf node index
        results_gpr7 = ffs(results_gpr7);        
        
        // Get class prediction
        results_gpr7 = (uint32_t)(path_class[results_gpr7]);
        reg_cp(&final_result_write, &results_gpr7, sizeof(final_result_write));

        remote_me_reg_write_signal_remote(&final_result_write, 32, 0, 0, 
                                          __xfer_reg_number(&complete_xfer, __nfp_meid(32, 0)) + (__ctx() * 32), 
                                          sizeof(complete_xfer), &local_signal);    
    }
    
    return 0;
}
