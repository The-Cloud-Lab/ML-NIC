#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal13;
__visible __xread uint32_t remote_xfer13;

__remote SIGNAL result_signal13;
__remote __xread uint32_t result_xfer13[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal13, 1);
    __assign_relative_register(&local_signal, 2);
    __implicit_write(&remote_signal13, sizeof(remote_signal13));
    __implicit_write(&remote_xfer13, sizeof(remote_xfer13));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal13);
        reg_cp(&feature, &remote_xfer13, sizeof(feature));
        feature >>= 16;

        // Decision Tree Logic
        if (!(feature <= 4294))
            result_gpr[4] &= ~(1 << 29);

        if (!(feature > 4294))
            result_gpr[4] &= ~(1 << 30);

        if (!(feature <= 1850))
            result_gpr[0] &= ~(1 << 6);

        if (!(feature > 1850))
            result_gpr[0] &= ~(1 << 7);

        if (!(feature <= 1916))
            result_gpr[7] &= ~(1 << 30);

        if (!(feature <= 1916))
            result_gpr[7] &= ~(1 << 31);

        if (!(feature > 1916))
            result_gpr[3] &= ~(1 << 1);

        if (!(feature > 1916))
            result_gpr[3] &= ~(1 << 2);

        if (!(feature <= 6012))
            result_gpr[3] &= ~(1 << 28);

        if (!(feature > 6012))
            result_gpr[3] &= ~(1 << 29);

        if (!(feature <= 5549))
            result_gpr[5] &= ~(1 << 24);

        if (!(feature <= 5549))
            result_gpr[5] &= ~(1 << 25);

        if (!(feature > 5549))
            result_gpr[7] &= ~(1 << 11);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 4, 0, __xfer_reg_number(result_xfer13, __nfp_meid(35, 4)) + (__ctx() * 32), sizeof(result_xfer13), &local_signal);
    }

    return 0;
}


