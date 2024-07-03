#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/cls.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>

__visible SIGNAL result_signal25;
__visible __xread uint32_t result_xfer25[8];

__visible SIGNAL result_signal26;
__visible __xread uint32_t result_xfer26[8];

__visible SIGNAL result_signal27;
__visible __xread uint32_t result_xfer27[8];

__visible SIGNAL result_signal28;
__visible __xread uint32_t result_xfer28[8];

__remote SIGNAL result_signal43;
__remote __xread uint32_t result_xfer43[8];

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t result_gpr25[8];
    __gpr uint32_t result_gpr26[8];
    __gpr uint32_t result_gpr27[8];
    __gpr uint32_t result_gpr28[8];
    __xwrite uint32_t interm_result_write[8];
    
    __assign_relative_register(&result_signal25, 2);
    __assign_relative_register(&result_signal26, 3);
    __assign_relative_register(&result_signal27, 4);
    __assign_relative_register(&result_signal28, 5);
    __assign_relative_register(&local_signal, 8);
    
    __implicit_write(&result_signal25, sizeof(result_signal25));
    __implicit_write(result_xfer25, sizeof(result_xfer25));
    
    __implicit_write(&result_signal26, sizeof(result_signal26));
    __implicit_write(result_xfer26, sizeof(result_xfer26));
    
    __implicit_write(&result_signal27, sizeof(result_signal27));
    __implicit_write(result_xfer27, sizeof(result_xfer27));
    
    __implicit_write(&result_signal28, sizeof(result_signal28));
    __implicit_write(result_xfer28, sizeof(result_xfer28));
        
    for (;;) {
        __wait_for_all(&result_signal25, &result_signal26, &result_signal27, &result_signal28);
        reg_cp(result_gpr25, result_xfer25, sizeof(result_gpr25));
        reg_cp(result_gpr26, result_xfer26, sizeof(result_gpr26));
        reg_cp(result_gpr27, result_xfer27, sizeof(result_gpr27));
        reg_cp(result_gpr28, result_xfer28, sizeof(result_gpr28));
        
        result_gpr28[0] = result_gpr25[0] & result_gpr26[0] & result_gpr27[0] & result_gpr28[0];
        result_gpr28[1] = result_gpr25[1] & result_gpr26[1] & result_gpr27[1] & result_gpr28[1];
        result_gpr28[2] = result_gpr25[2] & result_gpr26[2] & result_gpr27[2] & result_gpr28[2];
        result_gpr28[3] = result_gpr25[3] & result_gpr26[3] & result_gpr27[3] & result_gpr28[3];
        result_gpr28[4] = result_gpr25[4] & result_gpr26[4] & result_gpr27[4] & result_gpr28[4];
        result_gpr28[5] = result_gpr25[5] & result_gpr26[5] & result_gpr27[5] & result_gpr28[5];
        result_gpr28[6] = result_gpr25[6] & result_gpr26[6] & result_gpr27[6] & result_gpr28[6];
        result_gpr28[7] = result_gpr25[7] & result_gpr26[7] & result_gpr27[7] & result_gpr28[7];

        reg_cp(interm_result_write, result_gpr28, sizeof(interm_result_write));
        remote_me_reg_write_signal_remote(interm_result_write, 35, 11, 0, __xfer_reg_number(result_xfer43, __nfp_meid(35, 11)) + (__ctx() * 32), sizeof(result_xfer43), &local_signal);    
    }
    
    return 0;
}