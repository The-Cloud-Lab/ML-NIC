#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/cls.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>

__visible SIGNAL result_signal45;
__visible __xread uint32_t result_xfer45[8];

__visible SIGNAL result_signal46;
__visible __xread uint32_t result_xfer46[8];

__visible SIGNAL result_signal47;
__visible __xread uint32_t result_xfer47[8];

__remote SIGNAL complete_signal;
__remote __xread uint32_t complete_xfer;

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t result_gpr45[8];
    __gpr uint32_t result_gpr46[8];
    __gpr uint32_t result_gpr47[8];
    __xwrite uint32_t final_result_write;
    
    __lmem uint8_t path_class[] = {2, 1, 1, 1, 2, 3, 2, 5, 1, 2, 7, 3, 5, 7, 5, 5, 2, 7, 7, 1, 5, 4, 7, 7, 7, 4, 4, 4, 7, 7, 1, 5, 2, 5, 7, 4, 7, 5, 3, 7, 4, 4, 4, 3, 7, 4, 7, 7, 7, 5, 3, 7, 1, 4, 7, 4, 4, 1, 3, 1, 7, 4, 3, 2, 4, 3, 4, 2, 7, 4, 3, 4, 3, 1, 3, 3, 7, 4, 4, 3, 5, 1, 7, 2, 7, 1, 2, 1, 3, 1, 5, 5, 5, 3, 3, 2, 4, 7, 7, 4, 3, 7, 5, 7, 4, 5, 2, 4, 7, 3, 3, 3, 4, 3, 4, 3, 4, 7, 1, 3, 1, 5, 4, 1, 4, 7, 4, 5, 1, 5, 1, 5, 5, 7, 5, 4, 7, 7, 4, 4, 1, 5, 5, 4, 7, 3, 3, 3, 3, 3, 4, 7, 2, 7, 5, 4, 3, 4, 3, 4, 5, 1, 3, 7, 2, 5, 3, 1, 7, 3, 1, 1, 5, 2, 4, 3, 7, 4, 5, 1, 4, 4, 3, 4, 4, 3, 1, 4, 5, 4, 7, 4, 3, 4, 5, 7, 5, 7, 5, 1, 5, 1, 5, 7, 4, 4, 4, 3, 7, 3, 7, 4, 1, 3, 4, 7, 2, 4, 7, 3, 7, 2, 4, 3, 7, 3, 3, 3, 7, 4, 1, 5, 4, 3, 7, 4, 3, 7, 3, 4, 4, 5, 7, 4, 1, 3, 7, 1, 4, 7, 1, 4, 1, 5, 2, 4};
    
    __assign_relative_register(&result_signal45, 1);
    __assign_relative_register(&result_signal46, 2);
    __assign_relative_register(&result_signal47, 3);
    __assign_relative_register(&local_signal, 10);
    
    __implicit_write(&result_signal45, sizeof(result_signal45));
    __implicit_write(result_xfer45, sizeof(result_xfer45));
    
    __implicit_write(&result_signal46, sizeof(result_signal46));
    __implicit_write(result_xfer46, sizeof(result_xfer46));
    
    __implicit_write(&result_signal47, sizeof(result_signal47));
    __implicit_write(result_xfer47, sizeof(result_xfer47));
        
    for (;;) {
        __wait_for_all(&result_signal45, &result_signal46, &result_signal47);
        reg_cp(result_gpr45, result_xfer45, sizeof(result_gpr45));
        reg_cp(result_gpr46, result_xfer46, sizeof(result_gpr46));
        reg_cp(result_gpr47, result_xfer47, sizeof(result_gpr47));
        
        result_gpr47[0] = result_gpr45[0] & result_gpr46[0] & result_gpr47[0];
        result_gpr47[1] = result_gpr45[1] & result_gpr46[1] & result_gpr47[1];
        result_gpr47[2] = result_gpr45[2] & result_gpr46[2] & result_gpr47[2];
        result_gpr47[3] = result_gpr45[3] & result_gpr46[3] & result_gpr47[3];
        result_gpr47[4] = result_gpr45[4] & result_gpr46[4] & result_gpr47[4];
        result_gpr47[5] = result_gpr45[5] & result_gpr46[5] & result_gpr47[5];
        result_gpr47[6] = result_gpr45[6] & result_gpr46[6] & result_gpr47[6];
        result_gpr47[7] = result_gpr45[7] & result_gpr46[7] & result_gpr47[7];
        
        if (result_gpr47[0] != 0)
            result_gpr47[0] = ffs(result_gpr47[0]) + 224;
        else if (result_gpr47[1] != 0)
            result_gpr47[0] = ffs(result_gpr47[1]) + 192;
        else if (result_gpr47[2] != 0)
            result_gpr47[0] = ffs(result_gpr47[2]) + 160;
        else if (result_gpr47[3] != 0)
            result_gpr47[0] = ffs(result_gpr47[3]) + 128;
        else if (result_gpr47[4] != 0)
            result_gpr47[0] = ffs(result_gpr47[4]) + 96;
        else if (result_gpr47[5] != 0)
            result_gpr47[0] = ffs(result_gpr47[5]) + 64;
        else if (result_gpr47[6] != 0)
            result_gpr47[0] = ffs(result_gpr47[6]) + 32;
        else
            result_gpr47[0] = ffs(result_gpr47[7]);
        
        result_gpr47[0] = (uint32_t)(path_class[result_gpr47[0]]);
        reg_cp(&final_result_write, result_gpr47, sizeof(final_result_write));
        remote_me_reg_write_signal_remote(&final_result_write, 32, 0, 0, __xfer_reg_number(&complete_xfer, __nfp_meid(32, 0)) + (__ctx() * 32), sizeof(complete_xfer), &local_signal);    
    }
    
    return 0;
}