#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/cls.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>

__visible SIGNAL result_signal41;
__visible __xread uint32_t result_xfer41[8];

__visible SIGNAL result_signal42;
__visible __xread uint32_t result_xfer42[8];

__visible SIGNAL result_signal43;
__visible __xread uint32_t result_xfer43[8];

__visible SIGNAL result_signal44;
__visible __xread uint32_t result_xfer44[8];

__remote SIGNAL result_signal47;
__remote __xread uint32_t result_xfer47[8];

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t result_gpr41[8];
    __gpr uint32_t result_gpr42[8];
    __gpr uint32_t result_gpr43[8];
    __gpr uint32_t result_gpr44[8];
    __xwrite uint32_t interm_result_write[8];
    
    __assign_relative_register(&result_signal41, 6);
    __assign_relative_register(&result_signal42, 7);
    __assign_relative_register(&result_signal43, 8);
    __assign_relative_register(&result_signal44, 9);
    __assign_relative_register(&local_signal, 3);
    
    __implicit_write(&result_signal41, sizeof(result_signal41));
    __implicit_write(result_xfer41, sizeof(result_xfer41));
    
    __implicit_write(&result_signal42, sizeof(result_signal42));
    __implicit_write(result_xfer42, sizeof(result_xfer42));
    
    __implicit_write(&result_signal43, sizeof(result_signal43));
    __implicit_write(result_xfer43, sizeof(result_xfer43));
    
    __implicit_write(&result_signal44, sizeof(result_signal44));
    __implicit_write(result_xfer44, sizeof(result_xfer44));
        
    for (;;) {
        __wait_for_all(&result_signal41, &result_signal42, &result_signal43, &result_signal44);
        reg_cp(result_gpr41, result_xfer41, sizeof(result_gpr41));
        reg_cp(result_gpr42, result_xfer42, sizeof(result_gpr42));
        reg_cp(result_gpr43, result_xfer43, sizeof(result_gpr43));
        reg_cp(result_gpr44, result_xfer44, sizeof(result_gpr44));
        
        result_gpr44[0] = result_gpr41[0] & result_gpr42[0] & result_gpr43[0] & result_gpr44[0];
        result_gpr44[1] = result_gpr41[1] & result_gpr42[1] & result_gpr43[1] & result_gpr44[1];
        result_gpr44[2] = result_gpr41[2] & result_gpr42[2] & result_gpr43[2] & result_gpr44[2];
        result_gpr44[3] = result_gpr41[3] & result_gpr42[3] & result_gpr43[3] & result_gpr44[3];
        result_gpr44[4] = result_gpr41[4] & result_gpr42[4] & result_gpr43[4] & result_gpr44[4];
        result_gpr44[5] = result_gpr41[5] & result_gpr42[5] & result_gpr43[5] & result_gpr44[5];
        result_gpr44[6] = result_gpr41[6] & result_gpr42[6] & result_gpr43[6] & result_gpr44[6];
        result_gpr44[7] = result_gpr41[7] & result_gpr42[7] & result_gpr43[7] & result_gpr44[7];

        reg_cp(interm_result_write, result_gpr44, sizeof(interm_result_write));
        remote_me_reg_write_signal_remote(interm_result_write, 36, 0, 0, __xfer_reg_number(result_xfer47, __nfp_meid(36, 0)) + (__ctx() * 32), sizeof(result_xfer47), &local_signal);    
    }
    
    return 0;
}