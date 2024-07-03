#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal32;
__visible __xread uint32_t remote_xfer32;

__remote SIGNAL result_signal32;
__remote __xread uint32_t result_xfer32[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature95;
    __gpr uint32_t feature96;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal32, 1);
    __assign_relative_register(&local_signal, 5);
    __implicit_write(&remote_signal32, sizeof(remote_signal32));
    __implicit_write(&remote_xfer32, sizeof(remote_xfer32));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal32);
        reg_cp(&feature95, &remote_xfer32, sizeof(feature95));
        reg_cp(&feature95, &remote_xfer32, sizeof(feature95));
        
        feature95 >>= 16;
        // Decision Tree Logic
        if (!(feature95 <= 7217))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature95 <= 7217))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature95 > 7217))
            result_gpr[5] &= ~(1 << 31);

        if (!(feature95 <= 6451))
            result_gpr[4] &= ~(1 << 14);

        if (!(feature95 > 6451))
            result_gpr[4] &= ~(1 << 15);
        
        
        feature96 &= 0xffff;
        // Decision Tree Logic
        if (!(feature96 <= 7929))
            result_gpr[5] &= ~(1 << 25);

        if (!(feature96 > 7929))
            result_gpr[5] &= ~(1 << 26);

        if (!(feature96 <= 7990))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature96 > 7990))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature96 <= 7807))
            result_gpr[5] &= ~(1 << 23);

        if (!(feature96 > 7807))
            result_gpr[5] &= ~(1 << 24);
        

        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 4, 0, __xfer_reg_number(result_xfer32, __nfp_meid(36, 4)) + (__ctx() * 32), sizeof(result_xfer32), &local_signal);
    }

    return 0;
}


