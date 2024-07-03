#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/cls.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>

__visible SIGNAL result_signal17;
__visible __xread uint32_t result_xfer17[8];

__visible SIGNAL result_signal18;
__visible __xread uint32_t result_xfer18[8];

__visible SIGNAL result_signal19;
__visible __xread uint32_t result_xfer19[8];

__visible SIGNAL result_signal20;
__visible __xread uint32_t result_xfer20[8];

__remote SIGNAL result_signal41;
__remote __xread uint32_t result_xfer41[8];

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t result_gpr17[8];
    __gpr uint32_t result_gpr18[8];
    __gpr uint32_t result_gpr19[8];
    __gpr uint32_t result_gpr20[8];
    __xwrite uint32_t interm_result_write[8];
    
    __assign_relative_register(&result_signal17, 2);
    __assign_relative_register(&result_signal18, 3);
    __assign_relative_register(&result_signal19, 4);
    __assign_relative_register(&result_signal20, 5);
    __assign_relative_register(&local_signal, 6);
    
    __implicit_write(&result_signal17, sizeof(result_signal17));
    __implicit_write(result_xfer17, sizeof(result_xfer17));
    
    __implicit_write(&result_signal18, sizeof(result_signal18));
    __implicit_write(result_xfer18, sizeof(result_xfer18));
    
    __implicit_write(&result_signal19, sizeof(result_signal19));
    __implicit_write(result_xfer19, sizeof(result_xfer19));
    
    __implicit_write(&result_signal20, sizeof(result_signal20));
    __implicit_write(result_xfer20, sizeof(result_xfer20));
        
    for (;;) {
        __wait_for_all(&result_signal17, &result_signal18, &result_signal19, &result_signal20);
        reg_cp(result_gpr17, result_xfer17, sizeof(result_gpr17));
        reg_cp(result_gpr18, result_xfer18, sizeof(result_gpr18));
        reg_cp(result_gpr19, result_xfer19, sizeof(result_gpr19));
        reg_cp(result_gpr20, result_xfer20, sizeof(result_gpr20));
        
        result_gpr20[0] = result_gpr17[0] & result_gpr18[0] & result_gpr19[0] & result_gpr20[0];
        result_gpr20[1] = result_gpr17[1] & result_gpr18[1] & result_gpr19[1] & result_gpr20[1];
        result_gpr20[2] = result_gpr17[2] & result_gpr18[2] & result_gpr19[2] & result_gpr20[2];
        result_gpr20[3] = result_gpr17[3] & result_gpr18[3] & result_gpr19[3] & result_gpr20[3];
        result_gpr20[4] = result_gpr17[4] & result_gpr18[4] & result_gpr19[4] & result_gpr20[4];
        result_gpr20[5] = result_gpr17[5] & result_gpr18[5] & result_gpr19[5] & result_gpr20[5];
        result_gpr20[6] = result_gpr17[6] & result_gpr18[6] & result_gpr19[6] & result_gpr20[6];
        result_gpr20[7] = result_gpr17[7] & result_gpr18[7] & result_gpr19[7] & result_gpr20[7];

        reg_cp(interm_result_write, result_gpr20, sizeof(interm_result_write));
        remote_me_reg_write_signal_remote(interm_result_write, 35, 11, 0, __xfer_reg_number(result_xfer41, __nfp_meid(35, 11)) + (__ctx() * 32), sizeof(result_xfer41), &local_signal);    
    }
    
    return 0;
}