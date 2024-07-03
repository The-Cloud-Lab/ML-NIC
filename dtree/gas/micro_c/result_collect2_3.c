#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/cls.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>

__visible SIGNAL result_signal53;
__visible __xread uint32_t result_xfer53[8];

__visible SIGNAL result_signal54;
__visible __xread uint32_t result_xfer54[8];

__visible SIGNAL result_signal55;
__visible __xread uint32_t result_xfer55[8];

__remote SIGNAL result_signal58;
__remote __xread uint32_t result_xfer58[8];

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t result_gpr53[8];
    __gpr uint32_t result_gpr54[8];
    __gpr uint32_t result_gpr55[8];
    __xwrite uint32_t interm_result_write[8];
    
    __assign_relative_register(&result_signal53, 6);
    __assign_relative_register(&result_signal54, 7);
    __assign_relative_register(&result_signal55, 8);
    __assign_relative_register(&local_signal, 3);
    
    __implicit_write(&result_signal53, sizeof(result_signal53));
    __implicit_write(result_xfer53, sizeof(result_xfer53));
    
    __implicit_write(&result_signal54, sizeof(result_signal54));
    __implicit_write(result_xfer54, sizeof(result_xfer54));
    
    __implicit_write(&result_signal55, sizeof(result_signal55));
    __implicit_write(result_xfer55, sizeof(result_xfer55));
    
        
    for (;;) {
        __wait_for_all(&result_signal53, &result_signal54, &result_signal55);
        reg_cp(result_gpr53, result_xfer53, sizeof(result_gpr53));
        reg_cp(result_gpr54, result_xfer54, sizeof(result_gpr54));
        reg_cp(result_gpr55, result_xfer55, sizeof(result_gpr55));
        
        result_gpr55[0] = result_gpr53[0] & result_gpr54[0] & result_gpr55[0];
        result_gpr55[1] = result_gpr53[1] & result_gpr54[1] & result_gpr55[1];
        result_gpr55[2] = result_gpr53[2] & result_gpr54[2] & result_gpr55[2];
        result_gpr55[3] = result_gpr53[3] & result_gpr54[3] & result_gpr55[3];
        result_gpr55[4] = result_gpr53[4] & result_gpr54[4] & result_gpr55[4];
        result_gpr55[5] = result_gpr53[5] & result_gpr54[5] & result_gpr55[5];
        result_gpr55[6] = result_gpr53[6] & result_gpr54[6] & result_gpr55[6];
        result_gpr55[7] = result_gpr53[7] & result_gpr54[7] & result_gpr55[7];

        reg_cp(interm_result_write, result_gpr55, sizeof(interm_result_write));
        remote_me_reg_write_signal_remote(interm_result_write, 36, 11, 0, __xfer_reg_number(result_xfer58, __nfp_meid(36, 11)) + (__ctx() * 32), sizeof(result_xfer58), &local_signal);    
    }
    
    return 0;
}