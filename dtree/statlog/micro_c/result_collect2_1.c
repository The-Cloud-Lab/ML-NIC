#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/cls.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>

__visible SIGNAL result_signal37;
__visible __xread uint32_t result_xfer37[8];

__visible SIGNAL result_signal38;
__visible __xread uint32_t result_xfer38[8];

__visible SIGNAL result_signal39;
__visible __xread uint32_t result_xfer39[8];

__visible SIGNAL result_signal40;
__visible __xread uint32_t result_xfer40[8];

__remote SIGNAL result_signal46;
__remote __xread uint32_t result_xfer46[8];

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t result_gpr37[8];
    __gpr uint32_t result_gpr38[8];
    __gpr uint32_t result_gpr39[8];
    __gpr uint32_t result_gpr40[8];
    __xwrite uint32_t interm_result_write[8];
    
    __assign_relative_register(&result_signal37, 6);
    __assign_relative_register(&result_signal38, 7);
    __assign_relative_register(&result_signal39, 8);
    __assign_relative_register(&result_signal40, 9);
    __assign_relative_register(&local_signal, 2);
    
    __implicit_write(&result_signal37, sizeof(result_signal37));
    __implicit_write(result_xfer37, sizeof(result_xfer37));
    
    __implicit_write(&result_signal38, sizeof(result_signal38));
    __implicit_write(result_xfer38, sizeof(result_xfer38));
    
    __implicit_write(&result_signal39, sizeof(result_signal39));
    __implicit_write(result_xfer39, sizeof(result_xfer39));
    
    __implicit_write(&result_signal40, sizeof(result_signal40));
    __implicit_write(result_xfer40, sizeof(result_xfer40));
        
    for (;;) {
        __wait_for_all(&result_signal37, &result_signal38, &result_signal39, &result_signal40);
        reg_cp(result_gpr37, result_xfer37, sizeof(result_gpr37));
        reg_cp(result_gpr38, result_xfer38, sizeof(result_gpr38));
        reg_cp(result_gpr39, result_xfer39, sizeof(result_gpr39));
        reg_cp(result_gpr40, result_xfer40, sizeof(result_gpr40));
        
        result_gpr40[0] = result_gpr37[0] & result_gpr38[0] & result_gpr39[0] & result_gpr40[0];
        result_gpr40[1] = result_gpr37[1] & result_gpr38[1] & result_gpr39[1] & result_gpr40[1];
        result_gpr40[2] = result_gpr37[2] & result_gpr38[2] & result_gpr39[2] & result_gpr40[2];
        result_gpr40[3] = result_gpr37[3] & result_gpr38[3] & result_gpr39[3] & result_gpr40[3];
        result_gpr40[4] = result_gpr37[4] & result_gpr38[4] & result_gpr39[4] & result_gpr40[4];
        result_gpr40[5] = result_gpr37[5] & result_gpr38[5] & result_gpr39[5] & result_gpr40[5];
        result_gpr40[6] = result_gpr37[6] & result_gpr38[6] & result_gpr39[6] & result_gpr40[6];
        result_gpr40[7] = result_gpr37[7] & result_gpr38[7] & result_gpr39[7] & result_gpr40[7];

        reg_cp(interm_result_write, result_gpr40, sizeof(interm_result_write));
        remote_me_reg_write_signal_remote(interm_result_write, 36, 0, 0, __xfer_reg_number(result_xfer46, __nfp_meid(36, 0)) + (__ctx() * 32), sizeof(result_xfer46), &local_signal);    
    }
    
    return 0;
}