#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal28;
__visible __xread uint32_t remote_xfer28;

__remote SIGNAL result_signal28;
__remote __xread uint32_t result_xfer28[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal28, 1);
    __assign_relative_register(&local_signal, 5);
    __implicit_write(&remote_signal28, sizeof(remote_signal28));
    __implicit_write(&remote_xfer28, sizeof(remote_xfer28));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal28);
        reg_cp(&feature, &remote_xfer28, sizeof(feature));
        feature &= 0xffff;

        
        // Decision Tree Logic
        if (!(feature <= 2526))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature > 2526))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature <= 3721))
            result_gpr[3] &= ~(1 << 9);

        if (!(feature > 3721))
            result_gpr[3] &= ~(1 << 10);

        if (!(feature <= 2287))
            result_gpr[1] &= ~(1 << 10);

        if (!(feature > 2287))
            result_gpr[1] &= ~(1 << 11);

        if (!(feature <= 4540))
            result_gpr[0] &= ~(1 << 6);

        if (!(feature <= 4540))
            result_gpr[0] &= ~(1 << 7);

        if (!(feature <= 4540))
            result_gpr[6] &= ~(1 << 17);

        if (!(feature <= 4540))
            result_gpr[2] &= ~(1 << 4);

        if (!(feature <= 4540))
            result_gpr[2] &= ~(1 << 5);

        if (!(feature > 4540))
            result_gpr[7] &= ~(1 << 0);

        if (!(feature <= 3721))
            result_gpr[5] &= ~(1 << 26);

        if (!(feature <= 3721))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature <= 3721))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature <= 3721))
            result_gpr[3] &= ~(1 << 23);

        if (!(feature <= 3721))
            result_gpr[3] &= ~(1 << 24);

        if (!(feature <= 3721))
            result_gpr[6] &= ~(1 << 10);

        if (!(feature <= 3721))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature <= 3721))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature > 3721))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature > 3721))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature > 3721))
            result_gpr[2] &= ~(1 << 10);

        if (!(feature > 3721))
            result_gpr[2] &= ~(1 << 11);

        if (!(feature > 3721))
            result_gpr[6] &= ~(1 << 26);

        if (!(feature > 3721))
            result_gpr[6] &= ~(1 << 27);

        if (!(feature <= 2970))
            result_gpr[1] &= ~(1 << 22);

        if (!(feature <= 2970))
            result_gpr[1] &= ~(1 << 23);

        if (!(feature <= 2970))
            result_gpr[6] &= ~(1 << 14);

        if (!(feature <= 2970))
            result_gpr[0] &= ~(1 << 3);

        if (!(feature <= 2970))
            result_gpr[0] &= ~(1 << 4);

        if (!(feature <= 2970))
            result_gpr[0] &= ~(1 << 2);

        if (!(feature > 2970))
            result_gpr[5] &= ~(1 << 7);

        if (!(feature > 2970))
            result_gpr[5] &= ~(1 << 8);

        if (!(feature > 2970))
            result_gpr[5] &= ~(1 << 9);

        if (!(feature > 2970))
            result_gpr[5] &= ~(1 << 10);

        if (!(feature <= 3550))
            result_gpr[0] &= ~(1 << 0);

        if (!(feature > 3550))
            result_gpr[0] &= ~(1 << 1);

        if (!(feature <= 1980))
            result_gpr[6] &= ~(1 << 18);

        if (!(feature > 1980))
            result_gpr[6] &= ~(1 << 19);


        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 7, 0, __xfer_reg_number(result_xfer28, __nfp_meid(35, 7)) + (__ctx() * 32), sizeof(result_xfer28), &local_signal);
    }

    return 0;
}


