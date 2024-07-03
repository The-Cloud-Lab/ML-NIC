#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/cls.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>

__visible SIGNAL result_signal29;
__visible __xread uint32_t result_xfer29[8];

__visible SIGNAL result_signal30;
__visible __xread uint32_t result_xfer30[8];

__visible SIGNAL result_signal31;
__visible __xread uint32_t result_xfer31[8];

__visible SIGNAL result_signal32;
__visible __xread uint32_t result_xfer32[8];

__remote SIGNAL result_signal44;
__remote __xread uint32_t result_xfer44[8];

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t result_gpr29[8];
    __gpr uint32_t result_gpr30[8];
    __gpr uint32_t result_gpr31[8];
    __gpr uint32_t result_gpr32[8];
    __xwrite uint32_t interm_result_write[8];
    
    __assign_relative_register(&result_signal29, 2);
    __assign_relative_register(&result_signal30, 3);
    __assign_relative_register(&result_signal31, 4);
    __assign_relative_register(&result_signal32, 5);
    __assign_relative_register(&local_signal, 9);
    
    __implicit_write(&result_signal29, sizeof(result_signal29));
    __implicit_write(result_xfer29, sizeof(result_xfer29));
    
    __implicit_write(&result_signal30, sizeof(result_signal30));
    __implicit_write(result_xfer30, sizeof(result_xfer30));
    
    __implicit_write(&result_signal31, sizeof(result_signal31));
    __implicit_write(result_xfer31, sizeof(result_xfer31));
    
    __implicit_write(&result_signal32, sizeof(result_signal32));
    __implicit_write(result_xfer32, sizeof(result_xfer32));
        
    for (;;) {
        __wait_for_all(&result_signal29, &result_signal30, &result_signal31, &result_signal32);
        reg_cp(result_gpr29, result_xfer29, sizeof(result_gpr29));
        reg_cp(result_gpr30, result_xfer30, sizeof(result_gpr30));
        reg_cp(result_gpr31, result_xfer31, sizeof(result_gpr31));
        reg_cp(result_gpr32, result_xfer32, sizeof(result_gpr32));
        
        result_gpr32[0] = result_gpr29[0] & result_gpr30[0] & result_gpr31[0] & result_gpr32[0];
        result_gpr32[1] = result_gpr29[1] & result_gpr30[1] & result_gpr31[1] & result_gpr32[1];
        result_gpr32[2] = result_gpr29[2] & result_gpr30[2] & result_gpr31[2] & result_gpr32[2];
        result_gpr32[3] = result_gpr29[3] & result_gpr30[3] & result_gpr31[3] & result_gpr32[3];
        result_gpr32[4] = result_gpr29[4] & result_gpr30[4] & result_gpr31[4] & result_gpr32[4];
        result_gpr32[5] = result_gpr29[5] & result_gpr30[5] & result_gpr31[5] & result_gpr32[5];
        result_gpr32[6] = result_gpr29[6] & result_gpr30[6] & result_gpr31[6] & result_gpr32[6];
        result_gpr32[7] = result_gpr29[7] & result_gpr30[7] & result_gpr31[7] & result_gpr32[7];

        reg_cp(interm_result_write, result_gpr32, sizeof(interm_result_write));
        remote_me_reg_write_signal_remote(interm_result_write, 35, 11, 0, __xfer_reg_number(result_xfer44, __nfp_meid(35, 11)) + (__ctx() * 32), sizeof(result_xfer44), &local_signal);    
    }
    
    return 0;
}