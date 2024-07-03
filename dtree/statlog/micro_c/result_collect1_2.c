#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/cls.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>

__visible SIGNAL result_signal5;
__visible __xread uint32_t result_xfer5[8];

__visible SIGNAL result_signal6;
__visible __xread uint32_t result_xfer6[8];

__visible SIGNAL result_signal7;
__visible __xread uint32_t result_xfer7[8];

__visible SIGNAL result_signal8;
__visible __xread uint32_t result_xfer8[8];

__remote SIGNAL result_signal38;
__remote __xread uint32_t result_xfer38[8];

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t result_gpr5[8];
    __gpr uint32_t result_gpr6[8];
    __gpr uint32_t result_gpr7[8];
    __gpr uint32_t result_gpr8[8];
    __xwrite uint32_t interm_result_write[8];
    
    __assign_relative_register(&result_signal5, 2);
    __assign_relative_register(&result_signal6, 3);
    __assign_relative_register(&result_signal7, 4);
    __assign_relative_register(&result_signal8, 5);
    __assign_relative_register(&local_signal, 7);
    
    __implicit_write(&result_signal5, sizeof(result_signal5));
    __implicit_write(result_xfer5, sizeof(result_xfer5));
    
    __implicit_write(&result_signal6, sizeof(result_signal6));
    __implicit_write(result_xfer6, sizeof(result_xfer6));
    
    __implicit_write(&result_signal7, sizeof(result_signal7));
    __implicit_write(result_xfer7, sizeof(result_xfer7));
    
    __implicit_write(&result_signal8, sizeof(result_signal8));
    __implicit_write(result_xfer8, sizeof(result_xfer8));
        
    for (;;) {
        __wait_for_all(&result_signal5, &result_signal6, &result_signal7, &result_signal8);
        reg_cp(result_gpr5, result_xfer5, sizeof(result_gpr5));
        reg_cp(result_gpr6, result_xfer6, sizeof(result_gpr6));
        reg_cp(result_gpr7, result_xfer7, sizeof(result_gpr7));
        reg_cp(result_gpr8, result_xfer8, sizeof(result_gpr8));
        
        result_gpr8[0] = result_gpr5[0] & result_gpr6[0] & result_gpr7[0] & result_gpr8[0];
        result_gpr8[1] = result_gpr5[1] & result_gpr6[1] & result_gpr7[1] & result_gpr8[1];
        result_gpr8[2] = result_gpr5[2] & result_gpr6[2] & result_gpr7[2] & result_gpr8[2];
        result_gpr8[3] = result_gpr5[3] & result_gpr6[3] & result_gpr7[3] & result_gpr8[3];
        result_gpr8[4] = result_gpr5[4] & result_gpr6[4] & result_gpr7[4] & result_gpr8[4];
        result_gpr8[5] = result_gpr5[5] & result_gpr6[5] & result_gpr7[5] & result_gpr8[5];
        result_gpr8[6] = result_gpr5[6] & result_gpr6[6] & result_gpr7[6] & result_gpr8[6];
        result_gpr8[7] = result_gpr5[7] & result_gpr6[7] & result_gpr7[7] & result_gpr8[7];

        reg_cp(interm_result_write, result_gpr8, sizeof(interm_result_write));
        remote_me_reg_write_signal_remote(interm_result_write, 35, 10, 0, __xfer_reg_number(result_xfer38, __nfp_meid(35, 10)) + (__ctx() * 32), sizeof(result_xfer38), &local_signal);    
    }
    
    return 0;
}