#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/cls.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>

__visible SIGNAL result_signal56;
__visible __xread uint32_t result_xfer56[8];

__visible SIGNAL result_signal57;
__visible __xread uint32_t result_xfer57[8];

__visible SIGNAL result_signal58;
__visible __xread uint32_t result_xfer58[8];

__remote SIGNAL complete_signal;
__remote __xread uint32_t complete_xfer;

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t result_gpr56[8];
    __gpr uint32_t result_gpr57[8];
    __gpr uint32_t result_gpr58[8];
    __xwrite uint32_t final_result_write;
    
    __lmem uint8_t path_class[] = {3, 2, 2, 2, 6, 3, 4, 1, 5, 2, 5, 2, 5, 3, 2, 1, 2, 1, 3, 1, 5, 4, 1, 6, 4, 6, 4, 1, 5, 4, 6, 3, 1, 3, 4, 5, 1, 5, 1, 2, 1, 5, 3, 4, 4, 1, 6, 4, 4, 6, 1, 4, 1, 4, 5, 1, 5, 4, 2, 3, 4, 4, 2, 5, 1, 5, 3, 6, 4, 2, 3, 6, 5, 1, 1, 1, 4, 2, 3, 2, 4, 3, 4, 6, 6, 4, 5, 4, 6, 4, 5, 4, 2, 3, 6, 4, 4, 1, 5, 6, 1, 5, 6, 1, 1, 3, 2, 3, 4, 5, 4, 5, 5, 2, 1, 2, 1, 4, 2, 3, 6, 2, 4, 3, 5, 2, 6, 2, 1, 4, 5, 6, 3, 2, 6, 3, 3, 2, 6, 4, 1, 5, 4, 2, 5, 6, 3, 3, 2, 4, 6, 4, 2, 5, 2, 6, 4, 2, 5, 2, 3, 4, 6, 6, 5, 5, 4, 1, 3, 5, 4, 3, 6, 4, 3, 4, 5, 4, 2, 6, 6, 1, 3, 4, 4, 1, 4, 1, 1, 4, 1, 6, 4, 4, 1, 5, 1, 4, 1, 6, 1, 6, 3, 2, 2, 3, 4, 4, 6, 3, 2, 3, 4, 1, 5, 5, 3, 1, 4, 5, 2, 4, 1, 1, 4, 5, 5, 3, 2, 3, 5, 5, 5, 3, 1, 4, 1, 2, 2, 5, 4, 6, 1, 1, 4, 4, 6, 4, 5, 5, 1, 6, 4, 6, 5, 5, };
    
    __assign_relative_register(&result_signal56, 1);
    __assign_relative_register(&result_signal57, 2);
    __assign_relative_register(&result_signal58, 3);
    __assign_relative_register(&local_signal, 10);
    
    __implicit_write(&result_signal56, sizeof(result_signal56));
    __implicit_write(result_xfer56, sizeof(result_xfer56));
    
    __implicit_write(&result_signal57, sizeof(result_signal57));
    __implicit_write(result_xfer57, sizeof(result_xfer57));
    
    __implicit_write(&result_signal58, sizeof(result_signal58));
    __implicit_write(result_xfer58, sizeof(result_xfer58));
        
    for (;;) {
        __wait_for_all(&result_signal56, &result_signal57, &result_signal58);
        reg_cp(result_gpr56, result_xfer56, sizeof(result_gpr56));
        reg_cp(result_gpr57, result_xfer57, sizeof(result_gpr57));
        reg_cp(result_gpr58, result_xfer58, sizeof(result_gpr58));
        
        result_gpr58[0] = result_gpr56[0] & result_gpr57[0] & result_gpr58[0];
        result_gpr58[1] = result_gpr56[1] & result_gpr57[1] & result_gpr58[1];
        result_gpr58[2] = result_gpr56[2] & result_gpr57[2] & result_gpr58[2];
        result_gpr58[3] = result_gpr56[3] & result_gpr57[3] & result_gpr58[3];
        result_gpr58[4] = result_gpr56[4] & result_gpr57[4] & result_gpr58[4];
        result_gpr58[5] = result_gpr56[5] & result_gpr57[5] & result_gpr58[5];
        result_gpr58[6] = result_gpr56[6] & result_gpr57[6] & result_gpr58[6];
        result_gpr58[7] = result_gpr56[7] & result_gpr57[7] & result_gpr58[7];
        
        if (result_gpr58[0] != 0)
            result_gpr58[0] = ffs(result_gpr58[0]) + 224;
        else if (result_gpr58[1] != 0)
            result_gpr58[0] = ffs(result_gpr58[1]) + 192;
        else if (result_gpr58[2] != 0)
            result_gpr58[0] = ffs(result_gpr58[2]) + 160;
        else if (result_gpr58[3] != 0)
            result_gpr58[0] = ffs(result_gpr58[3]) + 128;
        else if (result_gpr58[4] != 0)
            result_gpr58[0] = ffs(result_gpr58[4]) + 96;
        else if (result_gpr58[5] != 0)
            result_gpr58[0] = ffs(result_gpr58[5]) + 64;
        else if (result_gpr58[6] != 0)
            result_gpr58[0] = ffs(result_gpr58[6]) + 32;
        else
            result_gpr58[0] = ffs(result_gpr58[7]);
        
        result_gpr58[0] = (uint32_t)(path_class[result_gpr58[0]]);
        reg_cp(&final_result_write, result_gpr58, sizeof(final_result_write));
        remote_me_reg_write_signal_remote(&final_result_write, 32, 0, 0, __xfer_reg_number(&complete_xfer, __nfp_meid(32, 0)) + (__ctx() * 32), sizeof(complete_xfer), &local_signal);    
    }
    
    return 0;
}