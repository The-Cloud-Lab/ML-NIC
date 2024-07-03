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
    __gpr uint32_t feature;
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
        reg_cp(&feature, &remote_xfer32, sizeof(feature));
        feature &= 0xffff;
   
        // Decision Tree Logic
        if (!(feature <= 1856))
            result_gpr[4] &= ~(1 << 11);

        if (!(feature > 1856))
            result_gpr[4] &= ~(1 << 12);

        if (!(feature <= 3168))
            result_gpr[7] &= ~(1 << 12);

        if (!(feature <= 3168))
            result_gpr[0] &= ~(1 << 30);

        if (!(feature <= 3168))
            result_gpr[0] &= ~(1 << 31);

        if (!(feature <= 3168))
            result_gpr[3] &= ~(1 << 9);

        if (!(feature <= 3168))
            result_gpr[3] &= ~(1 << 10);

        if (!(feature <= 3168))
            result_gpr[6] &= ~(1 << 23);

        if (!(feature <= 3168))
            result_gpr[1] &= ~(1 << 10);

        if (!(feature <= 3168))
            result_gpr[1] &= ~(1 << 11);

        if (!(feature > 3168))
            result_gpr[2] &= ~(1 << 28);

        if (!(feature > 3168))
            result_gpr[2] &= ~(1 << 29);

        if (!(feature > 3168))
            result_gpr[6] &= ~(1 << 16);

        if (!(feature <= 1952))
            result_gpr[3] &= ~(1 << 7);

        if (!(feature > 1952))
            result_gpr[3] &= ~(1 << 8);

        if (!(feature <= 3680))
            result_gpr[1] &= ~(1 << 24);

        if (!(feature <= 3680))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature <= 3680))
            result_gpr[4] &= ~(1 << 9);

        if (!(feature <= 3680))
            result_gpr[4] &= ~(1 << 10);

        if (!(feature > 3680))
            result_gpr[7] &= ~(1 << 1);

        if (!(feature <= 2816))
            result_gpr[3] &= ~(1 << 12);

        if (!(feature > 2816))
            result_gpr[3] &= ~(1 << 13);

        if (!(feature <= 2336))
            result_gpr[5] &= ~(1 << 22);

        if (!(feature > 2336))
            result_gpr[5] &= ~(1 << 23);

        if (!(feature <= 3296))
            result_gpr[3] &= ~(1 << 23);

        if (!(feature <= 3296))
            result_gpr[3] &= ~(1 << 24);

        if (!(feature > 3296))
            result_gpr[6] &= ~(1 << 10);

        if (!(feature > 3296))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature > 3296))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature <= 3392))
            result_gpr[5] &= ~(1 << 1);

        if (!(feature > 3392))
            result_gpr[5] &= ~(1 << 2);


        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 8, 0, __xfer_reg_number(result_xfer32, __nfp_meid(35, 8)) + (__ctx() * 32), sizeof(result_xfer32), &local_signal);
    }

    return 0;
}


