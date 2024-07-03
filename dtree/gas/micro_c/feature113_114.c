#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal40;
__visible __xread uint32_t remote_xfer40;

__remote SIGNAL result_signal40;
__remote __xread uint32_t result_xfer40[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature113;
    __gpr uint32_t feature114;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal40, 1);
    __assign_relative_register(&local_signal, 5);
    __implicit_write(&remote_signal40, sizeof(remote_signal40));
    __implicit_write(&remote_xfer40, sizeof(remote_xfer40));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal40);
        reg_cp(&feature113, &remote_xfer40, sizeof(feature113));
        reg_cp(&feature114, &remote_xfer40, sizeof(feature114));
        
        feature113 >>= 16;
        // Decision Tree Logic
        if (!(feature113 <= 1875))
            result_gpr[6] &= ~(1 << 1);

        if (!(feature113 <= 1875))
            result_gpr[3] &= ~(1 << 14);

        if (!(feature113 <= 1875))
            result_gpr[3] &= ~(1 << 15);

        if (!(feature113 <= 1875))
            result_gpr[5] &= ~(1 << 1);

        if (!(feature113 <= 1875))
            result_gpr[5] &= ~(1 << 2);

        if (!(feature113 <= 1875))
            result_gpr[7] &= ~(1 << 16);

        if (!(feature113 > 1875))
            result_gpr[7] &= ~(1 << 1);

        if (!(feature113 > 1875))
            result_gpr[4] &= ~(1 << 27);

        if (!(feature113 > 1875))
            result_gpr[4] &= ~(1 << 28);

        
        feature114 &= 0xffff;
        // Decision Tree Logic
        if (!(feature114 <= 81))
            result_gpr[4] &= ~(1 << 24);

        if (!(feature114 <= 81))
            result_gpr[4] &= ~(1 << 25);

        if (!(feature114 > 81))
            result_gpr[7] &= ~(1 << 26);

        if (!(feature114 > 81))
            result_gpr[7] &= ~(1 << 27);

        if (!(feature114 <= 1733))
            result_gpr[6] &= ~(1 << 1);

        if (!(feature114 <= 1733))
            result_gpr[3] &= ~(1 << 14);

        if (!(feature114 <= 1733))
            result_gpr[3] &= ~(1 << 15);

        if (!(feature114 <= 1733))
            result_gpr[5] &= ~(1 << 1);

        if (!(feature114 <= 1733))
            result_gpr[5] &= ~(1 << 2);

        if (!(feature114 > 1733))
            result_gpr[7] &= ~(1 << 16);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 6, 0, __xfer_reg_number(result_xfer40, __nfp_meid(36, 6)) + (__ctx() * 32), sizeof(result_xfer40), &local_signal);
    }

    return 0;
}


