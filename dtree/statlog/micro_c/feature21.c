#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal21;
__visible __xread uint32_t remote_xfer21;

__remote SIGNAL result_signal21;
__remote __xread uint32_t result_xfer21[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal21, 1);
    __assign_relative_register(&local_signal, 2);
    __implicit_write(&remote_signal21, sizeof(remote_signal21));
    __implicit_write(&remote_xfer21, sizeof(remote_xfer21));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal21);
        reg_cp(&feature, &remote_xfer21, sizeof(feature));
        feature >>= 16;

        // Decision Tree Logic
        if (!(feature <= 2332))
            result_gpr[7] &= ~(1 << 2);

        if (!(feature > 2332))
            result_gpr[2] &= ~(1 << 18);

        if (!(feature > 2332))
            result_gpr[2] &= ~(1 << 19);

        if (!(feature <= 4285))
            result_gpr[1] &= ~(1 << 24);

        if (!(feature <= 4285))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature <= 4285))
            result_gpr[4] &= ~(1 << 9);

        if (!(feature <= 4285))
            result_gpr[4] &= ~(1 << 10);

        if (!(feature <= 4285))
            result_gpr[7] &= ~(1 << 1);

        if (!(feature <= 4285))
            result_gpr[7] &= ~(1 << 8);

        if (!(feature <= 4285))
            result_gpr[4] &= ~(1 << 5);

        if (!(feature <= 4285))
            result_gpr[4] &= ~(1 << 6);

        if (!(feature <= 4285))
            result_gpr[5] &= ~(1 << 20);

        if (!(feature <= 4285))
            result_gpr[5] &= ~(1 << 21);

        if (!(feature <= 4285))
            result_gpr[6] &= ~(1 << 24);

        if (!(feature <= 4285))
            result_gpr[0] &= ~(1 << 12);

        if (!(feature <= 4285))
            result_gpr[0] &= ~(1 << 13);

        if (!(feature <= 4285))
            result_gpr[6] &= ~(1 << 5);

        if (!(feature <= 4285))
            result_gpr[7] &= ~(1 << 4);

        if (!(feature <= 4285))
            result_gpr[7] &= ~(1 << 30);

        if (!(feature <= 4285))
            result_gpr[7] &= ~(1 << 31);

        if (!(feature <= 4285))
            result_gpr[3] &= ~(1 << 1);

        if (!(feature <= 4285))
            result_gpr[3] &= ~(1 << 2);

        if (!(feature <= 4285))
            result_gpr[4] &= ~(1 << 27);

        if (!(feature <= 4285))
            result_gpr[4] &= ~(1 << 28);

        if (!(feature <= 4285))
            result_gpr[7] &= ~(1 << 7);

        if (!(feature <= 4285 && feature <= 3277))
            result_gpr[2] &= ~(1 << 26);

        if (!(feature <= 4285 && feature > 3277))
            result_gpr[2] &= ~(1 << 27);

        if (!(feature <= 4285))
            result_gpr[6] &= ~(1 << 15);

        if (!(feature <= 4285))
            result_gpr[3] &= ~(1 << 12);

        if (!(feature <= 4285))
            result_gpr[3] &= ~(1 << 13);

        if (!(feature <= 4285))
            result_gpr[1] &= ~(1 << 8);

        if (!(feature <= 4285))
            result_gpr[1] &= ~(1 << 9);

        if (!(feature <= 4285))
            result_gpr[5] &= ~(1 << 22);

        if (!(feature <= 4285))
            result_gpr[5] &= ~(1 << 23);

        if (!(feature <= 4285))
            result_gpr[1] &= ~(1 << 6);

        if (!(feature <= 4285))
            result_gpr[1] &= ~(1 << 7);

        if (!(feature <= 4285))
            result_gpr[2] &= ~(1 << 0);

        if (!(feature <= 4285))
            result_gpr[2] &= ~(1 << 1);

        if (!(feature <= 4285))
            result_gpr[7] &= ~(1 << 21);

        if (!(feature <= 4285))
            result_gpr[7] &= ~(1 << 19);

        if (!(feature <= 4285))
            result_gpr[5] &= ~(1 << 26);

        if (!(feature <= 4285))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature <= 4285))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature <= 4285))
            result_gpr[3] &= ~(1 << 23);

        if (!(feature <= 4285))
            result_gpr[3] &= ~(1 << 24);

        if (!(feature <= 4285))
            result_gpr[6] &= ~(1 << 10);

        if (!(feature <= 4285))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature <= 4285))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature <= 4285))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature <= 4285))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature <= 4285))
            result_gpr[2] &= ~(1 << 10);

        if (!(feature <= 4285))
            result_gpr[2] &= ~(1 << 11);

        if (!(feature <= 4285))
            result_gpr[6] &= ~(1 << 26);

        if (!(feature <= 4285))
            result_gpr[6] &= ~(1 << 27);

        if (!(feature > 4285))
            result_gpr[6] &= ~(1 << 21);

        if (!(feature > 4285))
            result_gpr[6] &= ~(1 << 22);

        if (!(feature > 4285))
            result_gpr[7] &= ~(1 << 25);

        if (!(feature > 4285))
            result_gpr[0] &= ~(1 << 28);

        if (!(feature > 4285))
            result_gpr[0] &= ~(1 << 29);

        if (!(feature > 4285))
            result_gpr[6] &= ~(1 << 31);

        if (!(feature > 4285))
            result_gpr[5] &= ~(1 << 0);

        if (!(feature > 4285))
            result_gpr[7] &= ~(1 << 13);

        if (!(feature > 4285))
            result_gpr[4] &= ~(1 << 25);

        if (!(feature > 4285))
            result_gpr[4] &= ~(1 << 26);

        if (!(feature > 4285))
            result_gpr[7] &= ~(1 << 10);

        if (!(feature > 4285))
            result_gpr[3] &= ~(1 << 30);

        if (!(feature > 4285))
            result_gpr[3] &= ~(1 << 31);

        if (!(feature > 4285))
            result_gpr[1] &= ~(1 << 20);

        if (!(feature > 4285))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature > 4285))
            result_gpr[7] &= ~(1 << 6);

        if (!(feature > 4285 && feature <= 4789))
            result_gpr[1] &= ~(1 << 22);

        if (!(feature > 4285 && feature <= 4789))
            result_gpr[1] &= ~(1 << 23);

        if (!(feature > 4285 && feature > 4789))
            result_gpr[6] &= ~(1 << 14);

        if (!(feature > 4285 && feature > 4789))
            result_gpr[0] &= ~(1 << 3);

        if (!(feature > 4285 && feature > 4789))
            result_gpr[0] &= ~(1 << 4);

        if (!(feature > 4285 && feature > 4789))
            result_gpr[0] &= ~(1 << 2);

        if (!(feature > 4285))
            result_gpr[5] &= ~(1 << 7);

        if (!(feature > 4285))
            result_gpr[5] &= ~(1 << 8);

        if (!(feature > 4285))
            result_gpr[5] &= ~(1 << 9);

        if (!(feature > 4285))
            result_gpr[5] &= ~(1 << 10);

        if (!(feature > 4285))
            result_gpr[5] &= ~(1 << 13);

        if (!(feature > 4285))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature > 4285))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature > 4285))
            result_gpr[6] &= ~(1 << 25);

        if (!(feature > 4285))
            result_gpr[3] &= ~(1 << 27);

        if (!(feature > 4285))
            result_gpr[3] &= ~(1 << 28);

        if (!(feature > 4285))
            result_gpr[3] &= ~(1 << 29);

        if (!(feature > 4285))
            result_gpr[0] &= ~(1 << 20);

        if (!(feature > 4285))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature > 4285))
            result_gpr[4] &= ~(1 << 31);

        if (!(feature > 4285))
            result_gpr[3] &= ~(1 << 0);

        if (!(feature > 4285))
            result_gpr[5] &= ~(1 << 24);

        if (!(feature > 4285))
            result_gpr[5] &= ~(1 << 25);

        if (!(feature > 4285))
            result_gpr[7] &= ~(1 << 11);

        if (!(feature <= 5041))
            result_gpr[6] &= ~(1 << 20);

        if (!(feature > 5041))
            result_gpr[2] &= ~(1 << 8);

        if (!(feature > 5041))
            result_gpr[2] &= ~(1 << 9);

        if (!(feature > 5041))
            result_gpr[3] &= ~(1 << 11);

        if (!(feature <= 5608))
            result_gpr[4] &= ~(1 << 13);

        if (!(feature > 5608))
            result_gpr[4] &= ~(1 << 17);

        if (!(feature > 5608))
            result_gpr[4] &= ~(1 << 18);

        if (!(feature > 5608))
            result_gpr[4] &= ~(1 << 14);

        if (!(feature > 5608))
            result_gpr[4] &= ~(1 << 15);

        if (!(feature > 5608))
            result_gpr[4] &= ~(1 << 16);

        if (!(feature <= 5356))
            result_gpr[0] &= ~(1 << 26);

        if (!(feature > 5356))
            result_gpr[0] &= ~(1 << 27);


        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 6, 0, __xfer_reg_number(result_xfer21, __nfp_meid(35, 6)) + (__ctx() * 32), sizeof(result_xfer21), &local_signal);
    }

    return 0;
}


