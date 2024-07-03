#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal15;
__visible __xread uint32_t remote_xfer15;

__remote SIGNAL result_signal15;
__remote __xread uint32_t result_xfer15[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal15, 1);
    __assign_relative_register(&local_signal, 4);
    __implicit_write(&remote_signal15, sizeof(remote_signal15));
    __implicit_write(&remote_xfer15, sizeof(remote_xfer15));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal15);
        reg_cp(&feature, &remote_xfer15, sizeof(feature));
        feature >>= 16;       

        // Decision Tree Logic
        if (!(feature <= 2805))
            result_gpr[5] &= ~(1 << 18);

        if (!(feature > 2805))
            result_gpr[5] &= ~(1 << 19);

        if (!(feature <= 3473))
            result_gpr[5] &= ~(1 << 28);

        if (!(feature <= 3473))
            result_gpr[4] &= ~(1 << 0);

        if (!(feature <= 3473))
            result_gpr[4] &= ~(1 << 1);

        if (!(feature > 3473))
            result_gpr[5] &= ~(1 << 27);

        if (!(feature <= 4096))
            result_gpr[6] &= ~(1 << 9);

        if (!(feature <= 4096))
            result_gpr[3] &= ~(1 << 7);

        if (!(feature <= 4096))
            result_gpr[3] &= ~(1 << 8);

        if (!(feature <= 4096))
            result_gpr[6] &= ~(1 << 28);

        if (!(feature <= 4096))
            result_gpr[6] &= ~(1 << 29);

        if (!(feature <= 4096))
            result_gpr[1] &= ~(1 << 18);

        if (!(feature <= 4096))
            result_gpr[1] &= ~(1 << 19);

        if (!(feature <= 4096))
            result_gpr[7] &= ~(1 << 22);

        if (!(feature <= 4096))
            result_gpr[4] &= ~(1 << 20);

        if (!(feature <= 4096))
            result_gpr[4] &= ~(1 << 21);

        if (!(feature <= 4096))
            result_gpr[6] &= ~(1 << 11);

        if (!(feature > 4096))
            result_gpr[2] &= ~(1 << 16);

        if (!(feature > 4096))
            result_gpr[2] &= ~(1 << 17);

        if (!(feature <= 3918))
            result_gpr[0] &= ~(1 << 10);

        if (!(feature <= 3918))
            result_gpr[0] &= ~(1 << 11);

        if (!(feature <= 3918))
            result_gpr[0] &= ~(1 << 5);

        if (!(feature > 3918))
            result_gpr[6] &= ~(1 << 12);

        if (!(feature <= 3606))
            result_gpr[2] &= ~(1 << 8);

        if (!(feature > 3606))
            result_gpr[2] &= ~(1 << 9);


        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 4, 0, __xfer_reg_number(result_xfer15, __nfp_meid(35, 4)) + (__ctx() * 32), sizeof(result_xfer15), &local_signal);
    }

    return 0;
}


