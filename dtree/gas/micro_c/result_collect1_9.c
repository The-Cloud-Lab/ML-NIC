#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/cls.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>

__visible SIGNAL result_signal33;
__visible __xread uint32_t result_xfer33[8];

__visible SIGNAL result_signal34;
__visible __xread uint32_t result_xfer34[8];

__visible SIGNAL result_signal35;
__visible __xread uint32_t result_xfer35[8];

__visible SIGNAL result_signal36;
__visible __xread uint32_t result_xfer36[8];

__remote SIGNAL result_signal53;
__remote __xread uint32_t result_xfer53[8];

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t result_gpr33[8];
    __gpr uint32_t result_gpr34[8];
    __gpr uint32_t result_gpr35[8];
    __gpr uint32_t result_gpr36[8];
    __xwrite uint32_t interm_result_write[8];
    
    __assign_relative_register(&result_signal33, 2);
    __assign_relative_register(&result_signal34, 3);
    __assign_relative_register(&result_signal35, 4);
    __assign_relative_register(&result_signal36, 5);
    __assign_relative_register(&local_signal, 6);
    
    __implicit_write(&result_signal33, sizeof(result_signal33));
    __implicit_write(result_xfer33, sizeof(result_xfer33));
    
    __implicit_write(&result_signal34, sizeof(result_signal34));
    __implicit_write(result_xfer34, sizeof(result_xfer34));
    
    __implicit_write(&result_signal35, sizeof(result_signal35));
    __implicit_write(result_xfer35, sizeof(result_xfer35));
    
    __implicit_write(&result_signal36, sizeof(result_signal36));
    __implicit_write(result_xfer36, sizeof(result_xfer36));
        
    for (;;) {
        __wait_for_all(&result_signal33, &result_signal34, &result_signal35, &result_signal36);
        reg_cp(result_gpr33, result_xfer33, sizeof(result_gpr33));
        reg_cp(result_gpr34, result_xfer34, sizeof(result_gpr34));
        reg_cp(result_gpr35, result_xfer35, sizeof(result_gpr35));
        reg_cp(result_gpr36, result_xfer36, sizeof(result_gpr36));
        
        result_gpr36[0] = result_gpr33[0] & result_gpr34[0] & result_gpr35[0] & result_gpr36[0];
        result_gpr36[1] = result_gpr33[1] & result_gpr34[1] & result_gpr35[1] & result_gpr36[1];
        result_gpr36[2] = result_gpr33[2] & result_gpr34[2] & result_gpr35[2] & result_gpr36[2];
        result_gpr36[3] = result_gpr33[3] & result_gpr34[3] & result_gpr35[3] & result_gpr36[3];
        result_gpr36[4] = result_gpr33[4] & result_gpr34[4] & result_gpr35[4] & result_gpr36[4];
        result_gpr36[5] = result_gpr33[5] & result_gpr34[5] & result_gpr35[5] & result_gpr36[5];
        result_gpr36[6] = result_gpr33[6] & result_gpr34[6] & result_gpr35[6] & result_gpr36[6];
        result_gpr36[7] = result_gpr33[7] & result_gpr34[7] & result_gpr35[7] & result_gpr36[7];

        reg_cp(interm_result_write, result_gpr36, sizeof(interm_result_write));
        remote_me_reg_write_signal_remote(interm_result_write, 36, 10, 0, __xfer_reg_number(result_xfer53, __nfp_meid(36, 10)) + (__ctx() * 32), sizeof(result_xfer53), &local_signal);    
    }
    
    return 0;
}