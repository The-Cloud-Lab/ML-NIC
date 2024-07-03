#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal31;
__visible __xread uint32_t remote_xfer31;

__remote SIGNAL result_signal31;
__remote __xread uint32_t result_xfer31[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal31, 1);
    __assign_relative_register(&local_signal, 4);
    __implicit_write(&remote_signal31, sizeof(remote_signal31));
    __implicit_write(&remote_xfer31, sizeof(remote_xfer31));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal31);
        reg_cp(&feature, &remote_xfer31, sizeof(feature));
        feature >>= 16;
       
        // Decision Tree Logic
        if (!(feature <= 2458))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature <= 2458))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature <= 2458))
            result_gpr[1] &= ~(1 << 3);

        if (!(feature > 2458))
            result_gpr[1] &= ~(1 << 2);

        if (!(feature <= 1854))
            result_gpr[7] &= ~(1 << 15);

        if (!(feature > 1854))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature > 1854))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature > 1854))
            result_gpr[7] &= ~(1 << 18);

        if (!(feature > 1854))
            result_gpr[4] &= ~(1 << 29);

        if (!(feature > 1854))
            result_gpr[4] &= ~(1 << 30);

        if (!(feature > 1854))
            result_gpr[3] &= ~(1 << 14);

        if (!(feature > 1854))
            result_gpr[3] &= ~(1 << 15);

        if (!(feature > 1854))
            result_gpr[6] &= ~(1 << 7);

        if (!(feature > 1854))
            result_gpr[4] &= ~(1 << 7);

        if (!(feature > 1854))
            result_gpr[4] &= ~(1 << 8);

        if (!(feature <= 4915))
            result_gpr[0] &= ~(1 << 10);

        if (!(feature <= 4915))
            result_gpr[0] &= ~(1 << 11);

        if (!(feature <= 4915))
            result_gpr[0] &= ~(1 << 5);

        if (!(feature <= 4915))
            result_gpr[6] &= ~(1 << 12);

        if (!(feature <= 4915))
            result_gpr[7] &= ~(1 << 23);

        if (!(feature <= 4915))
            result_gpr[7] &= ~(1 << 24);

        if (!(feature <= 4915))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature <= 4915))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature <= 4915))
            result_gpr[4] &= ~(1 << 2);

        if (!(feature <= 4915))
            result_gpr[5] &= ~(1 << 1);

        if (!(feature <= 4915))
            result_gpr[5] &= ~(1 << 2);

        if (!(feature <= 4915))
            result_gpr[6] &= ~(1 << 13);

        if (!(feature <= 4915))
            result_gpr[7] &= ~(1 << 17);

        if (!(feature > 4915))
            result_gpr[0] &= ~(1 << 0);

        if (!(feature > 4915))
            result_gpr[0] &= ~(1 << 1);

        if (!(feature > 4915))
            result_gpr[5] &= ~(1 << 11);

        if (!(feature <= 6985))
            result_gpr[2] &= ~(1 << 6);

        if (!(feature > 6985))
            result_gpr[2] &= ~(1 << 7);

        if (!(feature <= 3665))
            result_gpr[3] &= ~(1 << 16);

        if (!(feature > 3665))
            result_gpr[3] &= ~(1 << 17);

        if (!(feature > 3665))
            result_gpr[3] &= ~(1 << 19);

        if (!(feature > 3665))
            result_gpr[3] &= ~(1 << 21);

        if (!(feature > 3665))
            result_gpr[3] &= ~(1 << 22);

        if (!(feature > 3665))
            result_gpr[3] &= ~(1 << 20);

        if (!(feature > 3665))
            result_gpr[3] &= ~(1 << 18);

        if (!(feature > 3665))
            result_gpr[2] &= ~(1 << 20);

        if (!(feature > 3665))
            result_gpr[2] &= ~(1 << 21);

        if (!(feature > 3665))
            result_gpr[2] &= ~(1 << 22);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 8, 0, __xfer_reg_number(result_xfer31, __nfp_meid(35, 8)) + (__ctx() * 32), sizeof(result_xfer31), &local_signal);
    }

    return 0;
}


