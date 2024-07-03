#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/cls.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>

__visible SIGNAL result_signal21;
__visible __xread uint32_t result_xfer21[8];

__visible SIGNAL result_signal22;
__visible __xread uint32_t result_xfer22[8];

__visible SIGNAL result_signal23;
__visible __xread uint32_t result_xfer23[8];

__visible SIGNAL result_signal24;
__visible __xread uint32_t result_xfer24[8];

__remote SIGNAL result_signal50;
__remote __xread uint32_t result_xfer50[8];

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t result_gpr21[8];
    __gpr uint32_t result_gpr22[8];
    __gpr uint32_t result_gpr23[8];
    __gpr uint32_t result_gpr24[8];
    __xwrite uint32_t interm_result_write[8];
    
    __assign_relative_register(&result_signal21, 2);
    __assign_relative_register(&result_signal22, 3);
    __assign_relative_register(&result_signal23, 4);
    __assign_relative_register(&result_signal24, 5);
    __assign_relative_register(&local_signal, 7);
    
    __implicit_write(&result_signal21, sizeof(result_signal21));
    __implicit_write(result_xfer21, sizeof(result_xfer21));
    
    __implicit_write(&result_signal22, sizeof(result_signal22));
    __implicit_write(result_xfer22, sizeof(result_xfer22));
    
    __implicit_write(&result_signal23, sizeof(result_signal23));
    __implicit_write(result_xfer23, sizeof(result_xfer23));
    
    __implicit_write(&result_signal24, sizeof(result_signal24));
    __implicit_write(result_xfer24, sizeof(result_xfer24));
        
    for (;;) {
        __wait_for_all(&result_signal21, &result_signal22, &result_signal23, &result_signal24);
        reg_cp(result_gpr21, result_xfer21, sizeof(result_gpr21));
        reg_cp(result_gpr22, result_xfer22, sizeof(result_gpr22));
        reg_cp(result_gpr23, result_xfer23, sizeof(result_gpr23));
        reg_cp(result_gpr24, result_xfer24, sizeof(result_gpr24));
        
        result_gpr24[0] = result_gpr21[0] & result_gpr22[0] & result_gpr23[0] & result_gpr24[0];
        result_gpr24[1] = result_gpr21[1] & result_gpr22[1] & result_gpr23[1] & result_gpr24[1];
        result_gpr24[2] = result_gpr21[2] & result_gpr22[2] & result_gpr23[2] & result_gpr24[2];
        result_gpr24[3] = result_gpr21[3] & result_gpr22[3] & result_gpr23[3] & result_gpr24[3];
        result_gpr24[4] = result_gpr21[4] & result_gpr22[4] & result_gpr23[4] & result_gpr24[4];
        result_gpr24[5] = result_gpr21[5] & result_gpr22[5] & result_gpr23[5] & result_gpr24[5];
        result_gpr24[6] = result_gpr21[6] & result_gpr22[6] & result_gpr23[6] & result_gpr24[6];
        result_gpr24[7] = result_gpr21[7] & result_gpr22[7] & result_gpr23[7] & result_gpr24[7];

        reg_cp(interm_result_write, result_gpr24, sizeof(interm_result_write));
        remote_me_reg_write_signal_remote(interm_result_write, 36, 9, 0, __xfer_reg_number(result_xfer50, __nfp_meid(36, 9)) + (__ctx() * 32), sizeof(result_xfer50), &local_signal);    
    }
    
    return 0;
}