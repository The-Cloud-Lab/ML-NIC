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

__visible SIGNAL result_signal48;
__visible __xread uint32_t result_xfer48[8];

__remote SIGNAL result_signal56;
__remote __xread uint32_t result_xfer56[8];

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t result_gpr45[8];
    __gpr uint32_t result_gpr46[8];
    __gpr uint32_t result_gpr47[8];
    __gpr uint32_t result_gpr48[8];
    __xwrite uint32_t interm_result_write[8];
    
    __assign_relative_register(&result_signal45, 6);
    __assign_relative_register(&result_signal46, 7);
    __assign_relative_register(&result_signal47, 8);
    __assign_relative_register(&result_signal48, 9);
    __assign_relative_register(&local_signal, 1);
    
    __implicit_write(&result_signal45, sizeof(result_signal45));
    __implicit_write(result_xfer45, sizeof(result_xfer45));
    
    __implicit_write(&result_signal46, sizeof(result_signal46));
    __implicit_write(result_xfer46, sizeof(result_xfer46));
    
    __implicit_write(&result_signal47, sizeof(result_signal47));
    __implicit_write(result_xfer47, sizeof(result_xfer47));
    
    __implicit_write(&result_signal48, sizeof(result_signal48));
    __implicit_write(result_xfer48, sizeof(result_xfer48));
        
    for (;;) {
        __wait_for_all(&result_signal45, &result_signal46, &result_signal47, &result_signal48);
        reg_cp(result_gpr45, result_xfer45, sizeof(result_gpr45));
        reg_cp(result_gpr46, result_xfer46, sizeof(result_gpr46));
        reg_cp(result_gpr47, result_xfer47, sizeof(result_gpr47));
        reg_cp(result_gpr48, result_xfer48, sizeof(result_gpr48));
        
        result_gpr48[0] = result_gpr45[0] & result_gpr46[0] & result_gpr47[0] & result_gpr48[0];
        result_gpr48[1] = result_gpr45[1] & result_gpr46[1] & result_gpr47[1] & result_gpr48[1];
        result_gpr48[2] = result_gpr45[2] & result_gpr46[2] & result_gpr47[2] & result_gpr48[2];
        result_gpr48[3] = result_gpr45[3] & result_gpr46[3] & result_gpr47[3] & result_gpr48[3];
        result_gpr48[4] = result_gpr45[4] & result_gpr46[4] & result_gpr47[4] & result_gpr48[4];
        result_gpr48[5] = result_gpr45[5] & result_gpr46[5] & result_gpr47[5] & result_gpr48[5];
        result_gpr48[6] = result_gpr45[6] & result_gpr46[6] & result_gpr47[6] & result_gpr48[6];
        result_gpr48[7] = result_gpr45[7] & result_gpr46[7] & result_gpr47[7] & result_gpr48[7];

        reg_cp(interm_result_write, result_gpr48, sizeof(interm_result_write));
        remote_me_reg_write_signal_remote(interm_result_write, 36, 11, 0, __xfer_reg_number(result_xfer56, __nfp_meid(36, 11)) + (__ctx() * 32), sizeof(result_xfer56), &local_signal);    
    }
    
    return 0;
}