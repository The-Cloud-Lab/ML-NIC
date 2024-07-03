#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal4;
__visible __xread uint32_t remote_xfer4;

__remote SIGNAL result_signal4;
__remote __xread uint32_t result_xfer4[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal4, 1);
    __assign_relative_register(&local_signal, 5);
    __implicit_write(&remote_signal4, sizeof(remote_signal4));
    __implicit_write(&remote_xfer4, sizeof(remote_xfer4));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal4);
        reg_cp(&feature, &remote_xfer4, sizeof(feature));
        feature &= 0xffff;

        // Decision Tree Logic
        if (!(feature <= 1862))
            result_gpr[3] &= ~(1 << 5);

        if (!(feature > 1862))
            result_gpr[3] &= ~(1 << 6);

        if (!(feature <= 2505))
            result_gpr[3] &= ~(1 << 14);

        if (!(feature > 2505))
            result_gpr[3] &= ~(1 << 15);

        if (!(feature <= 2539))
            result_gpr[6] &= ~(1 << 21);

        if (!(feature <= 2539))
            result_gpr[6] &= ~(1 << 22);

        if (!(feature <= 2539))
            result_gpr[7] &= ~(1 << 25);

        if (!(feature <= 2539))
            result_gpr[0] &= ~(1 << 28);

        if (!(feature <= 2539))
            result_gpr[0] &= ~(1 << 29);

        if (!(feature > 2539))
            result_gpr[6] &= ~(1 << 31);

        if (!(feature > 2539))
            result_gpr[5] &= ~(1 << 0);

        if (!(feature > 2539))
            result_gpr[7] &= ~(1 << 13);

        if (!(feature > 2539))
            result_gpr[4] &= ~(1 << 25);

        if (!(feature > 2539))
            result_gpr[4] &= ~(1 << 26);

        if (!(feature > 2539))
            result_gpr[7] &= ~(1 << 10);

        if (!(feature > 2539))
            result_gpr[3] &= ~(1 << 30);

        if (!(feature > 2539))
            result_gpr[3] &= ~(1 << 31);

        if (!(feature > 2539))
            result_gpr[1] &= ~(1 << 20);

        if (!(feature > 2539))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature > 2539))
            result_gpr[7] &= ~(1 << 6);

        if (!(feature > 2539))
            result_gpr[1] &= ~(1 << 22);

        if (!(feature > 2539))
            result_gpr[1] &= ~(1 << 23);

        if (!(feature > 2539))
            result_gpr[6] &= ~(1 << 14);

        if (!(feature > 2539))
            result_gpr[0] &= ~(1 << 3);

        if (!(feature > 2539))
            result_gpr[0] &= ~(1 << 4);

        if (!(feature > 2539))
            result_gpr[0] &= ~(1 << 2);

        if (!(feature > 2539))
            result_gpr[5] &= ~(1 << 7);

        if (!(feature > 2539))
            result_gpr[5] &= ~(1 << 8);

        if (!(feature > 2539))
            result_gpr[5] &= ~(1 << 9);

        if (!(feature > 2539))
            result_gpr[5] &= ~(1 << 10);

        if (!(feature <= 3554))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature <= 3554))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature > 3554))
            result_gpr[4] &= ~(1 << 2);

        if (!(feature <= 3385))
            result_gpr[1] &= ~(1 << 14);

        if (!(feature > 3385))
            result_gpr[1] &= ~(1 << 15);

        if (!(feature <= 4638))
            result_gpr[4] &= ~(1 << 23);

        if (!(feature > 4638))
            result_gpr[4] &= ~(1 << 24);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 1, 0, __xfer_reg_number(result_xfer4, __nfp_meid(35, 1)) + (__ctx() * 32), sizeof(result_xfer4), &local_signal);
    }

    return 0;
}


