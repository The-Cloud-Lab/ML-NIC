#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal25;
__visible __xread uint32_t remote_xfer25;

__remote SIGNAL result_signal25;
__remote __xread uint32_t result_xfer25[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal25, 1);
    __assign_relative_register(&local_signal, 2);
    __implicit_write(&remote_signal25, sizeof(remote_signal25));
    __implicit_write(&remote_xfer25, sizeof(remote_xfer25));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal25);
        reg_cp(&feature, &remote_xfer25, sizeof(feature));
        feature >>= 16;

        // Decision Tree Logic
        if (!(feature <= 3776))
            result_gpr[0] &= ~(1 << 24);

        if (!(feature > 3776))
            result_gpr[0] &= ~(1 << 25);

        if (!(feature <= 4544))
            result_gpr[7] &= ~(1 << 4);

        if (!(feature <= 4544))
            result_gpr[7] &= ~(1 << 30);

        if (!(feature <= 4544))
            result_gpr[7] &= ~(1 << 31);

        if (!(feature <= 4544))
            result_gpr[3] &= ~(1 << 1);

        if (!(feature <= 4544))
            result_gpr[3] &= ~(1 << 2);

        if (!(feature <= 4544))
            result_gpr[4] &= ~(1 << 27);

        if (!(feature <= 4544))
            result_gpr[4] &= ~(1 << 28);

        if (!(feature <= 4544))
            result_gpr[7] &= ~(1 << 7);

        if (!(feature <= 4544))
            result_gpr[2] &= ~(1 << 26);

        if (!(feature <= 4544))
            result_gpr[2] &= ~(1 << 27);

        if (!(feature <= 4544))
            result_gpr[6] &= ~(1 << 15);

        if (!(feature <= 4544))
            result_gpr[3] &= ~(1 << 12);

        if (!(feature <= 4544))
            result_gpr[3] &= ~(1 << 13);

        if (!(feature <= 4544))
            result_gpr[1] &= ~(1 << 8);

        if (!(feature <= 4544))
            result_gpr[1] &= ~(1 << 9);

        if (!(feature <= 4544))
            result_gpr[5] &= ~(1 << 22);

        if (!(feature <= 4544))
            result_gpr[5] &= ~(1 << 23);

        if (!(feature <= 4544))
            result_gpr[1] &= ~(1 << 6);

        if (!(feature <= 4544))
            result_gpr[1] &= ~(1 << 7);

        if (!(feature <= 4544 && feature <= 4288))
            result_gpr[2] &= ~(1 << 0);

        if (!(feature <= 4544 && feature > 4288))
            result_gpr[2] &= ~(1 << 1);

        if (!(feature <= 4544))
            result_gpr[7] &= ~(1 << 21);

        if (!(feature <= 4544))
            result_gpr[7] &= ~(1 << 19);

        if (!(feature > 4544 && feature <= 5248))
            result_gpr[5] &= ~(1 << 26);

        if (!(feature > 4544 && feature > 5248))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature > 4544 && feature > 5248))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature > 4544))
            result_gpr[3] &= ~(1 << 23);

        if (!(feature > 4544))
            result_gpr[3] &= ~(1 << 24);

        if (!(feature > 4544))
            result_gpr[6] &= ~(1 << 10);

        if (!(feature > 4544))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature > 4544))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature > 4544))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature > 4544))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature > 4544 && feature <= 5760))
            result_gpr[2] &= ~(1 << 10);

        if (!(feature > 4544 && feature <= 5760))
            result_gpr[2] &= ~(1 << 11);

        if (!(feature > 4544 && feature > 5760))
            result_gpr[6] &= ~(1 << 26);

        if (!(feature > 4544 && feature > 5760))
            result_gpr[6] &= ~(1 << 27);

        if (!(feature <= 4160))
            result_gpr[6] &= ~(1 << 31);

        if (!(feature <= 4160))
            result_gpr[5] &= ~(1 << 0);

        if (!(feature <= 4160))
            result_gpr[7] &= ~(1 << 13);

        if (!(feature <= 4160))
            result_gpr[4] &= ~(1 << 25);

        if (!(feature <= 4160))
            result_gpr[4] &= ~(1 << 26);

        if (!(feature > 4160))
            result_gpr[7] &= ~(1 << 10);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 7, 0, __xfer_reg_number(result_xfer25, __nfp_meid(35, 7)) + (__ctx() * 32), sizeof(result_xfer25), &local_signal);
    }

    return 0;
}


