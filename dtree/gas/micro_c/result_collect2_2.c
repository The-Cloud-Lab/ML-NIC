#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/cls.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>

__visible SIGNAL result_signal49;
__visible __xread uint32_t result_xfer49[8];

__visible SIGNAL result_signal50;
__visible __xread uint32_t result_xfer50[8];

__visible SIGNAL result_signal51;
__visible __xread uint32_t result_xfer51[8];

__visible SIGNAL result_signal52;
__visible __xread uint32_t result_xfer52[8];

__remote SIGNAL result_signal57;
__remote __xread uint32_t result_xfer57[8];

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t result_gpr49[8];
    __gpr uint32_t result_gpr50[8];
    __gpr uint32_t result_gpr51[8];
    __gpr uint32_t result_gpr52[8];
    __xwrite uint32_t interm_result_write[8];
    
    __assign_relative_register(&result_signal49, 6);
    __assign_relative_register(&result_signal50, 7);
    __assign_relative_register(&result_signal51, 8);
    __assign_relative_register(&result_signal52, 9);
    __assign_relative_register(&local_signal, 2);
    
    __implicit_write(&result_signal49, sizeof(result_signal49));
    __implicit_write(result_xfer49, sizeof(result_xfer49));
    
    __implicit_write(&result_signal50, sizeof(result_signal50));
    __implicit_write(result_xfer50, sizeof(result_xfer50));
    
    __implicit_write(&result_signal51, sizeof(result_signal51));
    __implicit_write(result_xfer51, sizeof(result_xfer51));
    
    __implicit_write(&result_signal52, sizeof(result_signal52));
    __implicit_write(result_xfer52, sizeof(result_xfer52));
        
    for (;;) {
        __wait_for_all(&result_signal49, &result_signal50, &result_signal51, &result_signal52);
        reg_cp(result_gpr49, result_xfer49, sizeof(result_gpr49));
        reg_cp(result_gpr50, result_xfer50, sizeof(result_gpr50));
        reg_cp(result_gpr51, result_xfer51, sizeof(result_gpr51));
        reg_cp(result_gpr52, result_xfer52, sizeof(result_gpr52));
        
        result_gpr52[0] = result_gpr49[0] & result_gpr50[0] & result_gpr51[0] & result_gpr52[0];
        result_gpr52[1] = result_gpr49[1] & result_gpr50[1] & result_gpr51[1] & result_gpr52[1];
        result_gpr52[2] = result_gpr49[2] & result_gpr50[2] & result_gpr51[2] & result_gpr52[2];
        result_gpr52[3] = result_gpr49[3] & result_gpr50[3] & result_gpr51[3] & result_gpr52[3];
        result_gpr52[4] = result_gpr49[4] & result_gpr50[4] & result_gpr51[4] & result_gpr52[4];
        result_gpr52[5] = result_gpr49[5] & result_gpr50[5] & result_gpr51[5] & result_gpr52[5];
        result_gpr52[6] = result_gpr49[6] & result_gpr50[6] & result_gpr51[6] & result_gpr52[6];
        result_gpr52[7] = result_gpr49[7] & result_gpr50[7] & result_gpr51[7] & result_gpr52[7];

        reg_cp(interm_result_write, result_gpr52, sizeof(interm_result_write));
        remote_me_reg_write_signal_remote(interm_result_write, 36, 11, 0, __xfer_reg_number(result_xfer57, __nfp_meid(36, 11)) + (__ctx() * 32), sizeof(result_xfer57), &local_signal);    
    }
    
    return 0;
}