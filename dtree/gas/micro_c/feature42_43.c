#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal15;
__visible __xread uint32_t remote_xfer15[2];

__remote SIGNAL result_signal15;
__remote __xread uint32_t result_xfer15[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature42;
    __gpr uint32_t feature43;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal15, 1);
    __assign_relative_register(&local_signal, 4);
    __implicit_write(&remote_signal15, sizeof(remote_signal15));
    __implicit_write(&remote_xfer15, sizeof(remote_xfer15));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal15);
        reg_cp(&feature42, remote_xfer15, sizeof(feature42));
        reg_cp(&feature43, remote_xfer15+1, sizeof(feature43));

        feature42 &= 0xffff;
        // Decision Tree Logic
        if (!(feature42 <= 1))
            result_gpr[4] &= ~(1 << 21);

        if (!(feature42 <= 1))
            result_gpr[0] &= ~(1 << 24);

        if (!(feature42 <= 1))
            result_gpr[0] &= ~(1 << 25);

        if (!(feature42 <= 1))
            result_gpr[0] &= ~(1 << 26);

        if (!(feature42 <= 1))
            result_gpr[2] &= ~(1 << 5);

        if (!(feature42 <= 1))
            result_gpr[2] &= ~(1 << 6);

        if (!(feature42 > 1))
            result_gpr[4] &= ~(1 << 20);

        if (!(feature42 <= 0))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature42 > 0))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature42 > 0))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature42 > 0))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature42 > 0))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature42 > 0))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature42 > 0))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature42 > 0))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature42 <= 0))
            result_gpr[1] &= ~(1 << 15);

        if (!(feature42 <= 0))
            result_gpr[1] &= ~(1 << 16);

        if (!(feature42 <= 0))
            result_gpr[1] &= ~(1 << 14);

        if (!(feature42 <= 0))
            result_gpr[4] &= ~(1 << 18);

        if (!(feature42 > 0))
            result_gpr[2] &= ~(1 << 12);

        if (!(feature42 > 0))
            result_gpr[2] &= ~(1 << 13);


        feature43 >>= 16;
        // Decision Tree Logic
        if (!(feature43 <= 203))
            result_gpr[3] &= ~(1 << 2);

        if (!(feature43 > 203))
            result_gpr[3] &= ~(1 << 3);

        if (!(feature43 > 203))
            result_gpr[3] &= ~(1 << 4);
        
        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 0, 0, __xfer_reg_number(result_xfer15, __nfp_meid(36, 0)) + (__ctx() * 32), sizeof(result_xfer15), &local_signal);
    }

    return 0;
}


