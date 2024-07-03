#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal24;
__visible __xread uint32_t remote_xfer24;

__remote SIGNAL result_signal24;
__remote __xread uint32_t result_xfer24[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal24, 1);
    __assign_relative_register(&local_signal, 5);
    __implicit_write(&remote_signal24, sizeof(remote_signal24));
    __implicit_write(&remote_xfer24, sizeof(remote_xfer24));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal24);
        reg_cp(&feature, &remote_xfer24, sizeof(feature));
        feature &= 0xffff;

        // Decision Tree Logic
        if (!(feature <= 2916))
            result_gpr[3] &= ~(1 << 9);

        if (!(feature <= 2916))
            result_gpr[3] &= ~(1 << 10);

        if (!(feature > 2916))
            result_gpr[6] &= ~(1 << 23);

        if (!(feature > 2916))
            result_gpr[1] &= ~(1 << 10);

        if (!(feature > 2916))
            result_gpr[1] &= ~(1 << 11);

        if (!(feature <= 2949))
            result_gpr[2] &= ~(1 << 28);

        if (!(feature <= 2949))
            result_gpr[2] &= ~(1 << 29);

        if (!(feature > 2949))
            result_gpr[6] &= ~(1 << 16);

        if (!(feature <= 2490))
            result_gpr[0] &= ~(1 << 18);

        if (!(feature > 2490))
            result_gpr[0] &= ~(1 << 19);

        if (!(feature <= 2785))
            result_gpr[6] &= ~(1 << 21);

        if (!(feature > 2785))
            result_gpr[6] &= ~(1 << 22);

        if (!(feature <= 3539))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature > 3539))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature <= 3867))
            result_gpr[5] &= ~(1 << 30);

        if (!(feature <= 3867))
            result_gpr[1] &= ~(1 << 12);

        if (!(feature <= 3867))
            result_gpr[1] &= ~(1 << 14);

        if (!(feature <= 3867))
            result_gpr[1] &= ~(1 << 15);

        if (!(feature <= 3867))
            result_gpr[1] &= ~(1 << 13);

        if (!(feature > 3867))
            result_gpr[5] &= ~(1 << 29);

        if (!(feature <= 3834))
            result_gpr[2] &= ~(1 << 14);

        if (!(feature > 3834))
            result_gpr[2] &= ~(1 << 15);

        if (!(feature <= 2884))
            result_gpr[2] &= ~(1 << 23);

        if (!(feature > 2884))
            result_gpr[2] &= ~(1 << 24);

        if (!(feature > 2884))
            result_gpr[2] &= ~(1 << 25);


        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 6, 0, __xfer_reg_number(result_xfer24, __nfp_meid(35, 6)) + (__ctx() * 32), sizeof(result_xfer24), &local_signal);
    }

    return 0;
}


