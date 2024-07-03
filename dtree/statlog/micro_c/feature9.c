#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal9;
__visible __xread uint32_t remote_xfer9;

__remote SIGNAL result_signal9;
__remote __xread uint32_t result_xfer9[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal9, 1);
    __assign_relative_register(&local_signal, 2);
    __implicit_write(&remote_signal9, sizeof(remote_signal9));
    __implicit_write(&remote_xfer9, sizeof(remote_xfer9));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal9);
        reg_cp(&feature, &remote_xfer9, sizeof(feature));
        feature >>= 16;
     
        // Decision Tree Logic
        if (!(feature <= 448))
            result_gpr[4] &= ~(1 << 9);

        if (!(feature > 448))
            result_gpr[4] &= ~(1 << 10);

        if (!(feature <= 3264))
            result_gpr[1] &= ~(1 << 6);

        if (!(feature <= 3264))
            result_gpr[1] &= ~(1 << 7);

        if (!(feature > 3264))
            result_gpr[2] &= ~(1 << 0);

        if (!(feature > 3264))
            result_gpr[2] &= ~(1 << 1);

        if (!(feature <= 4416))
            result_gpr[6] &= ~(1 << 31);

        if (!(feature <= 4416))
            result_gpr[5] &= ~(1 << 0);

        if (!(feature > 4416))
            result_gpr[7] &= ~(1 << 13);

        if (!(feature <= 2816))
            result_gpr[3] &= ~(1 << 30);

        if (!(feature > 2816))
            result_gpr[3] &= ~(1 << 31);

        if (!(feature <= 5888))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature > 5888))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature <= 5504))
            result_gpr[5] &= ~(1 << 1);

        if (!(feature <= 5504))
            result_gpr[5] &= ~(1 << 2);

        if (!(feature > 5504))
            result_gpr[6] &= ~(1 << 13);


        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 3, 0, __xfer_reg_number(result_xfer9, __nfp_meid(35, 3)) + (__ctx() * 32), sizeof(result_xfer9), &local_signal);
    }

    return 0;
}


