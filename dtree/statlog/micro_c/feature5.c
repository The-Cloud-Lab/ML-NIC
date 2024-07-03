#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal5;
__visible __xread uint32_t remote_xfer5;

__remote SIGNAL result_signal5;
__remote __xread uint32_t result_xfer5[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal5, 1);
    __assign_relative_register(&local_signal, 2);
    __implicit_write(&remote_signal5, sizeof(remote_signal5));
    __implicit_write(&remote_xfer5, sizeof(remote_xfer5));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal5);
        reg_cp(&feature, &remote_xfer5, sizeof(feature));
        feature >>= 16;
    
        // Decision Tree Logic
        if (!(feature <= 3501))
            result_gpr[5] &= ~(1 << 20);

        if (!(feature <= 3501))
            result_gpr[5] &= ~(1 << 21);

        if (!(feature > 3501))
            result_gpr[6] &= ~(1 << 24);

        if (!(feature <= 3237))
            result_gpr[4] &= ~(1 << 27);

        if (!(feature <= 3237))
            result_gpr[4] &= ~(1 << 28);

        if (!(feature > 3237))
            result_gpr[7] &= ~(1 << 7);

        if (!(feature > 3237))
            result_gpr[2] &= ~(1 << 26);

        if (!(feature > 3237))
            result_gpr[2] &= ~(1 << 27);

        if (!(feature > 3237))
            result_gpr[6] &= ~(1 << 15);

        if (!(feature <= 3369))
            result_gpr[6] &= ~(1 << 31);

        if (!(feature > 3369))
            result_gpr[5] &= ~(1 << 0);


        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 2, 0, __xfer_reg_number(result_xfer5, __nfp_meid(35, 2)) + (__ctx() * 32), sizeof(result_xfer5), &local_signal);
    }

    return 0;
}


