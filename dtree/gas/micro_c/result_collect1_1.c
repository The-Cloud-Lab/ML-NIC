#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/cls.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>

__visible SIGNAL result_signal1;
__visible __xread uint32_t result_xfer1[8];

__visible SIGNAL result_signal2;
__visible __xread uint32_t result_xfer2[8];

__visible SIGNAL result_signal3;
__visible __xread uint32_t result_xfer3[8];

__visible SIGNAL result_signal4;
__visible __xread uint32_t result_xfer4[8];

__remote SIGNAL result_signal45;
__remote __xread uint32_t result_xfer45[8];

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t results_gpr1[8];
    __gpr uint32_t results_gpr2[8];
    __gpr uint32_t results_gpr3[8];
    __gpr uint32_t results_gpr4[8];
    __xwrite uint32_t interm_result_write[8];
    
    __assign_relative_register(&result_signal1, 2);
    __assign_relative_register(&result_signal2, 3);
    __assign_relative_register(&result_signal3, 4);
    __assign_relative_register(&result_signal4, 5);
    __assign_relative_register(&local_signal, 6);
    
    __implicit_write(&result_signal1, sizeof(result_signal1));
    __implicit_write(result_xfer1, sizeof(result_xfer1));
    
    __implicit_write(&result_signal2, sizeof(result_signal2));
    __implicit_write(result_xfer2, sizeof(result_xfer2));
    
    __implicit_write(&result_signal3, sizeof(result_signal3));
    __implicit_write(result_xfer3, sizeof(result_xfer3));
    
    __implicit_write(&result_signal4, sizeof(result_signal4));
    __implicit_write(result_xfer4, sizeof(result_xfer4));
        
    for (;;) {
        __wait_for_all(&result_signal1, &result_signal2, &result_signal3, &result_signal4);
        reg_cp(results_gpr1, result_xfer1, sizeof(results_gpr1));
        reg_cp(results_gpr2, result_xfer2, sizeof(results_gpr2));
        reg_cp(results_gpr3, result_xfer3, sizeof(results_gpr3));
        reg_cp(results_gpr4, result_xfer4, sizeof(results_gpr4));
        
        results_gpr4[0] = results_gpr1[0] & results_gpr2[0] & results_gpr3[0] & results_gpr4[0];
        results_gpr4[1] = results_gpr1[1] & results_gpr2[1] & results_gpr3[1] & results_gpr4[1];
        results_gpr4[2] = results_gpr1[2] & results_gpr2[2] & results_gpr3[2] & results_gpr4[2];
        results_gpr4[3] = results_gpr1[3] & results_gpr2[3] & results_gpr3[3] & results_gpr4[3];
        results_gpr4[4] = results_gpr1[4] & results_gpr2[4] & results_gpr3[4] & results_gpr4[4];
        results_gpr4[5] = results_gpr1[5] & results_gpr2[5] & results_gpr3[5] & results_gpr4[5];
        results_gpr4[6] = results_gpr1[6] & results_gpr2[6] & results_gpr3[6] & results_gpr4[6];
        results_gpr4[7] = results_gpr1[7] & results_gpr2[7] & results_gpr3[7] & results_gpr4[7];

        reg_cp(interm_result_write, results_gpr4, sizeof(interm_result_write));
        remote_me_reg_write_signal_remote(interm_result_write, 36, 8, 0, __xfer_reg_number(result_xfer45, __nfp_meid(36, 8)) + (__ctx() * 32), sizeof(result_xfer45), &local_signal);    
    }
    
    return 0;
}