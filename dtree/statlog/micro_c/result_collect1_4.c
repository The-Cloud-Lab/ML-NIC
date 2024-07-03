#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/cls.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>

__visible SIGNAL result_signal13;
__visible __xread uint32_t result_xfer13[8];

__visible SIGNAL result_signal14;
__visible __xread uint32_t result_xfer14[8];

__visible SIGNAL result_signal15;
__visible __xread uint32_t result_xfer15[8];

__visible SIGNAL result_signal16;
__visible __xread uint32_t result_xfer16[8];

__remote SIGNAL result_signal40;
__remote __xread uint32_t result_xfer40[8];

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t result_gpr13[8];
    __gpr uint32_t result_gpr14[8];
    __gpr uint32_t result_gpr15[8];
    __gpr uint32_t result_gpr16[8];
    __xwrite uint32_t interm_result_write[8];
    
    __assign_relative_register(&result_signal13, 2);
    __assign_relative_register(&result_signal14, 3);
    __assign_relative_register(&result_signal15, 4);
    __assign_relative_register(&result_signal16, 5);
    __assign_relative_register(&local_signal, 9);
    
    __implicit_write(&result_signal13, sizeof(result_signal13));
    __implicit_write(result_xfer13, sizeof(result_xfer13));
    
    __implicit_write(&result_signal14, sizeof(result_signal14));
    __implicit_write(result_xfer14, sizeof(result_xfer14));
    
    __implicit_write(&result_signal15, sizeof(result_signal15));
    __implicit_write(result_xfer15, sizeof(result_xfer15));
    
    __implicit_write(&result_signal16, sizeof(result_signal16));
    __implicit_write(result_xfer16, sizeof(result_xfer16));
        
    for (;;) {
        __wait_for_all(&result_signal13, &result_signal14, &result_signal15, &result_signal16);
        reg_cp(result_gpr13, result_xfer13, sizeof(result_gpr13));
        reg_cp(result_gpr14, result_xfer14, sizeof(result_gpr14));
        reg_cp(result_gpr15, result_xfer15, sizeof(result_gpr15));
        reg_cp(result_gpr16, result_xfer16, sizeof(result_gpr16));
        
        result_gpr16[0] = result_gpr13[0] & result_gpr14[0] & result_gpr15[0] & result_gpr16[0];
        result_gpr16[1] = result_gpr13[1] & result_gpr14[1] & result_gpr15[1] & result_gpr16[1];
        result_gpr16[2] = result_gpr13[2] & result_gpr14[2] & result_gpr15[2] & result_gpr16[2];
        result_gpr16[3] = result_gpr13[3] & result_gpr14[3] & result_gpr15[3] & result_gpr16[3];
        result_gpr16[4] = result_gpr13[4] & result_gpr14[4] & result_gpr15[4] & result_gpr16[4];
        result_gpr16[5] = result_gpr13[5] & result_gpr14[5] & result_gpr15[5] & result_gpr16[5];
        result_gpr16[6] = result_gpr13[6] & result_gpr14[6] & result_gpr15[6] & result_gpr16[6];
        result_gpr16[7] = result_gpr13[7] & result_gpr14[7] & result_gpr15[7] & result_gpr16[7];

        reg_cp(interm_result_write, result_gpr16, sizeof(interm_result_write));
        remote_me_reg_write_signal_remote(interm_result_write, 35, 10, 0, __xfer_reg_number(result_xfer40, __nfp_meid(35, 10)) + (__ctx() * 32), sizeof(result_xfer40), &local_signal);    
    }
    
    return 0;
}