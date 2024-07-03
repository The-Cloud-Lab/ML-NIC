#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal36;
__visible __xread uint32_t remote_xfer36;

__remote SIGNAL result_signal36;
__remote __xread uint32_t result_xfer36[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal36, 1);
    __assign_relative_register(&local_signal, 5);
    __implicit_write(&remote_signal36, sizeof(remote_signal36));
    __implicit_write(&remote_xfer36, sizeof(remote_xfer36));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal36);
        reg_cp(&feature, &remote_xfer36, sizeof(feature));
        feature &= 0xffff;
      
        // Decision Tree Logic
        if (!(feature <= 1312))
            result_gpr[7] &= ~(1 << 12);

        if (!(feature > 1312))
            result_gpr[0] &= ~(1 << 30);

        if (!(feature > 1312))
            result_gpr[0] &= ~(1 << 31);

        if (!(feature > 1312))
            result_gpr[3] &= ~(1 << 9);

        if (!(feature > 1312))
            result_gpr[3] &= ~(1 << 10);

        if (!(feature > 1312 && feature <= 2848))
            result_gpr[6] &= ~(1 << 23);

        if (!(feature > 1312 && feature > 2848))
            result_gpr[1] &= ~(1 << 10);

        if (!(feature > 1312 && feature > 2848))
            result_gpr[1] &= ~(1 << 11);

        if (!(feature <= 2080))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature <= 2080))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature > 2080))
            result_gpr[7] &= ~(1 << 18);

        if (!(feature <= 4032))
            result_gpr[3] &= ~(1 << 30);

        if (!(feature <= 4032))
            result_gpr[3] &= ~(1 << 31);

        if (!(feature > 4032))
            result_gpr[1] &= ~(1 << 20);

        if (!(feature > 4032))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature <= 3520))
            result_gpr[5] &= ~(1 << 13);

        if (!(feature > 3520))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature > 3520))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature <= 2976))
            result_gpr[7] &= ~(1 << 29);

        if (!(feature > 2976))
            result_gpr[6] &= ~(1 << 20);

        if (!(feature > 2976))
            result_gpr[2] &= ~(1 << 8);

        if (!(feature > 2976))
            result_gpr[2] &= ~(1 << 9);

        if (!(feature > 2976))
            result_gpr[3] &= ~(1 << 11);


        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 9, 0, __xfer_reg_number(result_xfer36, __nfp_meid(35, 9)) + (__ctx() * 32), sizeof(result_xfer36), &local_signal);
    }

    return 0;
}


