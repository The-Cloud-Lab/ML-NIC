#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/cls.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>

__visible SIGNAL result_signal9;
__visible __xread uint32_t result_xfer9[8];

__visible SIGNAL result_signal10;
__visible __xread uint32_t result_xfer10[8];

__visible SIGNAL result_signal11;
__visible __xread uint32_t result_xfer11[8];

__visible SIGNAL result_signal12;
__visible __xread uint32_t result_xfer12[8];

__remote SIGNAL result_signal47;
__remote __xread uint32_t result_xfer47[8];

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t result_gpr9[8];
    __gpr uint32_t result_gpr10[8];
    __gpr uint32_t result_gpr11[8];
    __gpr uint32_t result_gpr12[8];
    __xwrite uint32_t interm_result_write[8];
    
    __assign_relative_register(&result_signal9, 2);
    __assign_relative_register(&result_signal10, 3);
    __assign_relative_register(&result_signal11, 4);
    __assign_relative_register(&result_signal12, 5);
    __assign_relative_register(&local_signal, 8);
    
    __implicit_write(&result_signal9, sizeof(result_signal9));
    __implicit_write(result_xfer9, sizeof(result_xfer9));
    
    __implicit_write(&result_signal10, sizeof(result_signal10));
    __implicit_write(result_xfer10, sizeof(result_xfer10));
    
    __implicit_write(&result_signal11, sizeof(result_signal11));
    __implicit_write(result_xfer11, sizeof(result_xfer11));
    
    __implicit_write(&result_signal12, sizeof(result_signal12));
    __implicit_write(result_xfer12, sizeof(result_xfer12));
        
    for (;;) {
        __wait_for_all(&result_signal9, &result_signal10, &result_signal11, &result_signal12);
        reg_cp(result_gpr9, result_xfer9, sizeof(result_gpr9));
        reg_cp(result_gpr10, result_xfer10, sizeof(result_gpr10));
        reg_cp(result_gpr11, result_xfer11, sizeof(result_gpr11));
        reg_cp(result_gpr12, result_xfer12, sizeof(result_gpr12));
        
        result_gpr12[0] = result_gpr9[0] & result_gpr10[0] & result_gpr11[0] & result_gpr12[0];
        result_gpr12[1] = result_gpr9[1] & result_gpr10[1] & result_gpr11[1] & result_gpr12[1];
        result_gpr12[2] = result_gpr9[2] & result_gpr10[2] & result_gpr11[2] & result_gpr12[2];
        result_gpr12[3] = result_gpr9[3] & result_gpr10[3] & result_gpr11[3] & result_gpr12[3];
        result_gpr12[4] = result_gpr9[4] & result_gpr10[4] & result_gpr11[4] & result_gpr12[4];
        result_gpr12[5] = result_gpr9[5] & result_gpr10[5] & result_gpr11[5] & result_gpr12[5];
        result_gpr12[6] = result_gpr9[6] & result_gpr10[6] & result_gpr11[6] & result_gpr12[6];
        result_gpr12[7] = result_gpr9[7] & result_gpr10[7] & result_gpr11[7] & result_gpr12[7];

        reg_cp(interm_result_write, result_gpr12, sizeof(interm_result_write));
        remote_me_reg_write_signal_remote(interm_result_write, 36, 8, 0, __xfer_reg_number(result_xfer47, __nfp_meid(36, 8)) + (__ctx() * 32), sizeof(result_xfer47), &local_signal);    
    }
    
    return 0;
}