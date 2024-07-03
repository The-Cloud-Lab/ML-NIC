#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal34;
__visible __xread uint32_t remote_xfer34;

__remote SIGNAL result_signal34;
__remote __xread uint32_t result_xfer34[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal34, 1);
    __assign_relative_register(&local_signal, 3);
    __implicit_write(&remote_signal34, sizeof(remote_signal34));
    __implicit_write(&remote_xfer34, sizeof(remote_xfer34));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal34);
        reg_cp(&feature, &remote_xfer34, sizeof(feature));
        feature &= 0xffff;
    
        // Decision Tree Logic
        if (!(feature <= 2823))
            result_gpr[3] &= ~(1 << 25);

        if (!(feature <= 2823))
            result_gpr[3] &= ~(1 << 26);

        if (!(feature <= 2823))
            result_gpr[7] &= ~(1 << 14);

        if (!(feature <= 2823))
            result_gpr[5] &= ~(1 << 18);

        if (!(feature <= 2823))
            result_gpr[5] &= ~(1 << 19);

        if (!(feature > 2823))
            result_gpr[7] &= ~(1 << 20);

        if (!(feature > 2823))
            result_gpr[5] &= ~(1 << 28);

        if (!(feature > 2823))
            result_gpr[4] &= ~(1 << 0);

        if (!(feature > 2823))
            result_gpr[4] &= ~(1 << 1);

        if (!(feature > 2823))
            result_gpr[5] &= ~(1 << 27);

        if (!(feature > 2823))
            result_gpr[5] &= ~(1 << 16);

        if (!(feature > 2823))
            result_gpr[5] &= ~(1 << 17);

        if (!(feature > 2823))
            result_gpr[4] &= ~(1 << 11);

        if (!(feature > 2823))
            result_gpr[4] &= ~(1 << 12);

        if (!(feature > 2823))
            result_gpr[7] &= ~(1 << 27);

        if (!(feature > 2823))
            result_gpr[7] &= ~(1 << 26);

        if (!(feature <= 4215))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature <= 4215))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature <= 4215))
            result_gpr[1] &= ~(1 << 3);

        if (!(feature <= 4215))
            result_gpr[1] &= ~(1 << 2);

        if (!(feature > 4215))
            result_gpr[0] &= ~(1 << 24);

        if (!(feature > 4215))
            result_gpr[0] &= ~(1 << 25);

        if (!(feature <= 5369))
            result_gpr[6] &= ~(1 << 28);

        if (!(feature <= 5369))
            result_gpr[6] &= ~(1 << 29);

        if (!(feature > 5369))
            result_gpr[1] &= ~(1 << 18);

        if (!(feature > 5369))
            result_gpr[1] &= ~(1 << 19);

        if (!(feature <= 2585))
            result_gpr[7] &= ~(1 << 4);

        if (!(feature > 2585))
            result_gpr[7] &= ~(1 << 30);

        if (!(feature > 2585))
            result_gpr[7] &= ~(1 << 31);

        if (!(feature > 2585))
            result_gpr[3] &= ~(1 << 1);

        if (!(feature > 2585))
            result_gpr[3] &= ~(1 << 2);

        if (!(feature <= 5130))
            result_gpr[1] &= ~(1 << 22);

        if (!(feature > 5130))
            result_gpr[1] &= ~(1 << 23);

        if (!(feature <= 5846))
            result_gpr[4] &= ~(1 << 15);

        if (!(feature > 5846))
            result_gpr[4] &= ~(1 << 16);

        if (!(feature <= 5090))
            result_gpr[4] &= ~(1 << 19);

        if (!(feature > 5090))
            result_gpr[0] &= ~(1 << 26);

        if (!(feature > 5090))
            result_gpr[0] &= ~(1 << 27);

        if (!(feature <= 6402))
            result_gpr[3] &= ~(1 << 19);

        if (!(feature <= 6402))
            result_gpr[3] &= ~(1 << 21);

        if (!(feature <= 6402))
            result_gpr[3] &= ~(1 << 22);

        if (!(feature <= 6402))
            result_gpr[3] &= ~(1 << 20);

        if (!(feature > 6402))
            result_gpr[3] &= ~(1 << 18);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 9, 0, __xfer_reg_number(result_xfer34, __nfp_meid(35, 9)) + (__ctx() * 32), sizeof(result_xfer34), &local_signal);
    }

    return 0;
}


