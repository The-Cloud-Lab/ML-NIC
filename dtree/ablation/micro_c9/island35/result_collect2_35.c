#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL result_signal6;
__visible __xread uint32_t result_xfer6[8];

__visible SIGNAL result_signal7;
__visible __xread uint32_t result_xfer7[8];

__visible SIGNAL result_signal8;
__visible __xread uint32_t result_xfer8[8];

__remote SIGNAL complete_signal;
__remote __xread uint32_t complete_xfer;

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t results_gpr6[8];
    __gpr uint32_t results_gpr7[8];
    __gpr uint32_t results_gpr8[8];
    __xwrite uint32_t final_result_write;
    
    __lmem uint8_t path_class[] = {3, 0, 2, 2, 2, 1, 6, 6, 0, 0, 0, 6, 0, 2, 0, 6, 6, 6, 0, 0, 6, 0, 2, 3, 2, 0, 2, 0, 0, 0, 0, 6, 0, 0, 0, 3, 5, 5, 2, 6, 3, 0, 0, 6, 6, 0, 0, 0, 0, 5, 0, 6, 0, 6, 4, 0, 0, 6, 0, 0, 6, 0, 6, 6, 0, 6, 6, 6, 0, 0, 3, 0, 0, 0, 0, 0, 3, 3, 0, 0, 6, 0, 4, 0, 6, 0, 0, 0, 6, 0, 0, 0, 0, 6, 0, 4, 3, 4, 4, 4, 0, 3, 3, 0, 6, 0, 0, 2, 0, 6, 0, 3, 3, 0, 0, 6, 0, 0, 0, 3, 0, 3, 3, 3, 6, 0, 0, 4, 1, 0, 1, 0, 0, 6, 0, 6, 6, 6, 0, 0, 3, 3, 0, 6, 0, 4, 4, 4, 0, 3, 3, 0, 0, 6, 0, 0, 6, 0, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 6, 6, 0, 0, 0, 6, 0, 6, 0, 0, 4, 4, 0, 0, 0, 0, 6, 6, 0, 6, 6, 0, 0, 0, 6, 4, 0, 0, 0, 4, 4, 0, 0, 4, 4, 0, 0, 0, 0, 4, 0, 6, 6, 0, 0, 4, 0, 4, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
        
    __assign_relative_register(&result_signal6, 6);
    __assign_relative_register(&result_signal7, 7);    
    __assign_relative_register(&result_signal8, 8);    
    __assign_relative_register(&local_signal, 9);
    
    __implicit_write(&result_signal6, sizeof(result_signal6));
    __implicit_write(result_xfer6, sizeof(result_xfer6));
    
    __implicit_write(&result_signal7, sizeof(result_signal7));
    __implicit_write(result_xfer7, sizeof(result_xfer7));

    __implicit_write(&result_signal8, sizeof(result_signal8));
    __implicit_write(result_xfer8, sizeof(result_xfer8));

    for (;;) {
        __wait_for_all(&result_signal6, &result_signal7, &result_signal8);
                
        // Collect all the possible paths
        reg_cp(results_gpr6, result_xfer6, sizeof(results_gpr6));
        reg_cp(results_gpr7, result_xfer7, sizeof(results_gpr7));
        reg_cp(results_gpr8, result_xfer8, sizeof(results_gpr8));

        // Compute final path
        results_gpr8[0] = results_gpr6[0] & results_gpr7[0] & results_gpr8[0];
        results_gpr8[1] = results_gpr6[1] & results_gpr7[1] & results_gpr8[1];
        results_gpr8[2] = results_gpr6[2] & results_gpr7[2] & results_gpr8[2];
        results_gpr8[3] = results_gpr6[3] & results_gpr7[3] & results_gpr8[3];
        results_gpr8[4] = results_gpr6[4] & results_gpr7[4] & results_gpr8[4];
        results_gpr8[5] = results_gpr6[5] & results_gpr7[5] & results_gpr8[5];
        results_gpr8[6] = results_gpr6[6] & results_gpr7[6] & results_gpr8[6];
        results_gpr8[7] = results_gpr6[7] & results_gpr7[7] & results_gpr8[7];

        
        // Calculate leaf node index
        if (results_gpr8[0] != 0)
            results_gpr8[0] = ffs(results_gpr8[0]) + 224;
        else if (results_gpr8[1] != 0)
            results_gpr8[0] = ffs(results_gpr8[1]) + 192;
        else if (results_gpr8[2] != 0)
            results_gpr8[0] = ffs(results_gpr8[2]) + 160;
        else if (results_gpr8[3] != 0)
            results_gpr8[0] = ffs(results_gpr8[3]) + 128;        
        else if (results_gpr8[4] != 0)
            results_gpr8[0] = ffs(results_gpr8[4]) + 96;        
        else if (results_gpr8[5] != 0)
            results_gpr8[0] = ffs(results_gpr8[5]) + 64;        
        else if (results_gpr8[6] != 0)
            results_gpr8[0] = ffs(results_gpr8[6]) + 32;        
        else
            results_gpr8[0] = ffs(results_gpr8[7]);        
        
        // Get class prediction
        results_gpr8[0] = (uint32_t)(path_class[results_gpr8[0]]);
        reg_cp(&final_result_write, results_gpr8, sizeof(final_result_write));

        remote_me_reg_write_signal_remote(&final_result_write, 35, 0, 0, 
                                          __xfer_reg_number(&complete_xfer, __nfp_meid(35, 0)) + (__ctx() * 32), 
                                          sizeof(complete_xfer), &local_signal);    
    }
    
    return 0;
}
