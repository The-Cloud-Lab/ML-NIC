#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal31;
__visible __xread uint32_t remote_xfer31[2];

__remote SIGNAL result_signal31;
__remote __xread uint32_t result_xfer31[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature89;
    __gpr uint32_t feature90;
    __gpr uint32_t feature91;
    __gpr uint32_t feature92;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal31, 1);
    __assign_relative_register(&local_signal, 4);
    __implicit_write(&remote_signal31, sizeof(remote_signal31));
    __implicit_write(&remote_xfer31, sizeof(remote_xfer31));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal31);
        reg_cp(&feature89, remote_xfer31, sizeof(feature89));
        reg_cp(&feature90, remote_xfer31, sizeof(feature90));
        reg_cp(&feature91, remote_xfer31+1, sizeof(feature91));
        reg_cp(&feature92, remote_xfer31+1, sizeof(feature92));
        
        feature89 >>= 16;
        // Decision Tree Logic
        if (!(feature89 <= 1343))
            result_gpr[1] &= ~(1 << 3);

        if (!(feature89 > 1343))
            result_gpr[1] &= ~(1 << 8);

        if (!(feature89 > 1343))
            result_gpr[1] &= ~(1 << 9);
        
        
        feature90 &= 0xffff;
        // Decision Tree Logic
        if (!(feature90 <= 1485))
            result_gpr[0] &= ~(1 << 5);

        if (!(feature90 <= 1485))
            result_gpr[0] &= ~(1 << 6);

        if (!(feature90 <= 1485))
            result_gpr[0] &= ~(1 << 7);

        if (!(feature90 <= 1485))
            result_gpr[0] &= ~(1 << 8);

        if (!(feature90 <= 1485))
            result_gpr[0] &= ~(1 << 9);

        if (!(feature90 > 1485))
            result_gpr[0] &= ~(1 << 4);
        
        
        feature91 >>= 16;
        // Decision Tree Logic
        if (!(feature91 <= 230))
            result_gpr[2] &= ~(1 << 22);

        if (!(feature91 > 230))
            result_gpr[2] &= ~(1 << 23);

        if (!(feature91 <= 5230))
            result_gpr[2] &= ~(1 << 3);

        if (!(feature91 > 5230))
            result_gpr[2] &= ~(1 << 4);

        
        
        feature92 &= 0xffff;
        // Decision Tree Logic
        if (!(feature92 <= 97))
            result_gpr[3] &= ~(1 << 31);

        if (!(feature92 <= 97))
            result_gpr[2] &= ~(1 << 0);

        if (!(feature92 <= 97))
            result_gpr[5] &= ~(1 << 10);

        if (!(feature92 > 97))
            result_gpr[4] &= ~(1 << 22);

        if (!(feature92 > 97))
            result_gpr[4] &= ~(1 << 23);

        if (!(feature92 > 97))
            result_gpr[5] &= ~(1 << 14);

        if (!(feature92 > 97))
            result_gpr[5] &= ~(1 << 15);

        if (!(feature92 > 97))
            result_gpr[5] &= ~(1 << 13);

        if (!(feature92 > 97))
            result_gpr[5] &= ~(1 << 28);

        if (!(feature92 > 97))
            result_gpr[5] &= ~(1 << 29);

        if (!(feature92 > 97))
            result_gpr[0] &= ~(1 << 14);

        if (!(feature92 > 97))
            result_gpr[0] &= ~(1 << 15);

        if (!(feature92 > 97))
            result_gpr[0] &= ~(1 << 13);

        if (!(feature92 > 97))
            result_gpr[4] &= ~(1 << 9);

        if (!(feature92 <= 2441))
            result_gpr[7] &= ~(1 << 31);

        if (!(feature92 <= 2441))
            result_gpr[6] &= ~(1 << 0);

        if (!(feature92 <= 2441))
            result_gpr[4] &= ~(1 << 14);

        if (!(feature92 <= 2441))
            result_gpr[4] &= ~(1 << 15);

        if (!(feature92 > 2441))
            result_gpr[7] &= ~(1 << 3);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 4, 0, __xfer_reg_number(result_xfer31, __nfp_meid(36, 4)) + (__ctx() * 32), sizeof(result_xfer31), &local_signal);
    }

    return 0;
}


