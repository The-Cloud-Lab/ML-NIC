#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal7;
__visible __xread uint32_t remote_xfer7;

__remote SIGNAL result_signal7;
__remote __xread uint32_t result_xfer7[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal7, 1);
    __assign_relative_register(&local_signal, 4);
    __implicit_write(&remote_signal7, sizeof(remote_signal7));
    __implicit_write(&remote_xfer7, sizeof(remote_xfer7));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal7);
        reg_cp(&feature, &remote_xfer7, sizeof(feature));
        feature >>= 16;

        // Decision Tree Logic
        if (!(feature <= 3234))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature <= 3234))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature <= 3234))
            result_gpr[1] &= ~(1 << 3);

        if (!(feature <= 3234))
            result_gpr[1] &= ~(1 << 2);

        if (!(feature <= 3234))
            result_gpr[0] &= ~(1 << 24);

        if (!(feature <= 3234))
            result_gpr[0] &= ~(1 << 25);

        if (!(feature > 3234))
            result_gpr[5] &= ~(1 << 3);

        if (!(feature > 3234))
            result_gpr[5] &= ~(1 << 4);

        if (!(feature <= 4355))
            result_gpr[0] &= ~(1 << 3);

        if (!(feature > 4355))
            result_gpr[0] &= ~(1 << 4);

        if (!(feature <= 3320))
            result_gpr[3] &= ~(1 << 27);

        if (!(feature > 3320))
            result_gpr[3] &= ~(1 << 28);

        if (!(feature > 3320))
            result_gpr[3] &= ~(1 << 29);

        if (!(feature <= 5734))
            result_gpr[2] &= ~(1 << 8);

        if (!(feature <= 5734))
            result_gpr[2] &= ~(1 << 9);

        if (!(feature > 5734))
            result_gpr[3] &= ~(1 << 11);

        if (!(feature <= 5260))
            result_gpr[0] &= ~(1 << 8);

        if (!(feature > 5260))
            result_gpr[0] &= ~(1 << 9);

        if (!(feature <= 4570))
            result_gpr[2] &= ~(1 << 20);

        if (!(feature > 4570))
            result_gpr[2] &= ~(1 << 21);

        if (!(feature > 4570))
            result_gpr[2] &= ~(1 << 22);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 2, 0, __xfer_reg_number(result_xfer7, __nfp_meid(35, 2)) + (__ctx() * 32), sizeof(result_xfer7), &local_signal);
    }

    return 0;
}


