#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal17;
__visible __xread uint32_t remote_xfer17[2];

__remote SIGNAL result_signal17;
__remote __xread uint32_t result_xfer17[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature49;
    __gpr uint32_t feature50;
    __gpr uint32_t feature51;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal17, 1);
    __assign_relative_register(&local_signal, 2);
    __implicit_write(&remote_signal17, sizeof(remote_signal17));
    __implicit_write(&remote_xfer17, sizeof(remote_xfer17));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal17);
        reg_cp(&feature49, remote_xfer17, sizeof(feature49));
        reg_cp(&feature50, remote_xfer17, sizeof(feature50));
        reg_cp(&feature51, remote_xfer17+1, sizeof(feature51));
        
        feature49 >>= 16;
        // Decision Tree Logic
        if (!(feature49 <= 2281))
            result_gpr[7] &= ~(1 << 15);

        if (!(feature49 > 2281))
            result_gpr[6] &= ~(1 << 7);

        if (!(feature49 > 2281))
            result_gpr[6] &= ~(1 << 8);
        
        
        feature50 &= 0xffff;
        // Decision Tree Logic
        if (!(feature50 <= 2))
            result_gpr[4] &= ~(1 << 12);

        if (!(feature50 <= 2))
            result_gpr[4] &= ~(1 << 13);

        if (!(feature50 <= 2))
            result_gpr[5] &= ~(1 << 7);

        if (!(feature50 > 2 && feature50 <= 2))
            result_gpr[3] &= ~(1 << 18);

        if (!(feature50 > 2 && feature50 > 2))
            result_gpr[2] &= ~(1 << 20);

        if (!(feature50 > 2 && feature50 > 2))
            result_gpr[2] &= ~(1 << 21);

        if (!(feature50 > 2))
            result_gpr[4] &= ~(1 << 31);

        if (!(feature50 <= 5))
            result_gpr[3] &= ~(1 << 25);

        if (!(feature50 > 5))
            result_gpr[3] &= ~(1 << 26);

        
        feature51 >>= 16;
        // Decision Tree Logic
        if (!(feature51 <= 518))
            result_gpr[5] &= ~(1 << 30);

        if (!(feature51 > 518))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature51 > 518))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature51 <= 752))
            result_gpr[7] &= ~(1 << 30);

        if (!(feature51 > 752))
            result_gpr[6] &= ~(1 << 27);

        if (!(feature51 > 752))
            result_gpr[6] &= ~(1 << 28);
        
        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 1, 0, __xfer_reg_number(result_xfer17, __nfp_meid(36, 1)) + (__ctx() * 32), sizeof(result_xfer17), &local_signal);
    }

    return 0;
}


