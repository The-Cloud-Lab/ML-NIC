#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal29;
__visible __xread uint32_t remote_xfer29;

__remote SIGNAL result_signal29;
__remote __xread uint32_t result_xfer29[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature83;
    __gpr uint32_t feature84;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal29, 1);
    __assign_relative_register(&local_signal, 2);
    __implicit_write(&remote_signal29, sizeof(remote_signal29));
    __implicit_write(&remote_xfer29, sizeof(remote_xfer29));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal29);
        reg_cp(&feature83, &remote_xfer29, sizeof(feature83));
        reg_cp(&feature84, &remote_xfer29, sizeof(feature83));
        
        feature83 >>= 16;
        // Decision Tree Logic
        if (!(feature83 <= 1128))
            result_gpr[1] &= ~(1 << 23);

        if (!(feature83 > 1128))
            result_gpr[1] &= ~(1 << 24);

        if (!(feature83 <= 208))
            result_gpr[7] &= ~(1 << 4);

        if (!(feature83 > 208))
            result_gpr[5] &= ~(1 << 30);

        if (!(feature83 > 208))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature83 > 208))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature83 > 208))
            result_gpr[1] &= ~(1 << 15);

        if (!(feature83 > 208))
            result_gpr[1] &= ~(1 << 16);

        if (!(feature83 > 208))
            result_gpr[1] &= ~(1 << 14);

        if (!(feature83 > 208))
            result_gpr[4] &= ~(1 << 18);

        if (!(feature83 > 208))
            result_gpr[2] &= ~(1 << 12);

        if (!(feature83 > 208))
            result_gpr[2] &= ~(1 << 13);

        
        feature84 &= 0xffff;
        // Decision Tree Logic
         if (!(feature84 <= 1430))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature84 <= 1430))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature84 <= 1430))
            result_gpr[0] &= ~(1 << 0);

        if (!(feature84 > 1430))
            result_gpr[4] &= ~(1 << 26);

        if (!(feature84 <= 230))
            result_gpr[1] &= ~(1 << 15);

        if (!(feature84 <= 230))
            result_gpr[1] &= ~(1 << 16);

        if (!(feature84 > 230))
            result_gpr[1] &= ~(1 << 14);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 4, 0, __xfer_reg_number(result_xfer29, __nfp_meid(36, 4)) + (__ctx() * 32), sizeof(result_xfer29), &local_signal);
    }

    return 0;
}


