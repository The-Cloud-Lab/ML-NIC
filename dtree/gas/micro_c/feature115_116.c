#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal41;
__visible __xread uint32_t remote_xfer41;

__remote SIGNAL result_signal41;
__remote __xread uint32_t result_xfer41[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature115;
    __gpr uint32_t feature116;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal41, 1);
    __assign_relative_register(&local_signal, 2);
    __implicit_write(&remote_signal41, sizeof(remote_signal41));
    __implicit_write(&remote_xfer41, sizeof(remote_xfer41));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal41);
        reg_cp(&feature115, &remote_xfer41, sizeof(feature115));
        reg_cp(&feature116, &remote_xfer41, sizeof(feature115));        
        
        feature115 >>= 16;
        // Decision Tree Logic
        if (!(feature115 <= 2902))
            result_gpr[0] &= ~(1 << 2);

        if (!(feature115 > 2902))
            result_gpr[0] &= ~(1 << 3);

        if (!(feature115 <= 1118))
            result_gpr[4] &= ~(1 << 0);

        if (!(feature115 > 1118))
            result_gpr[4] &= ~(1 << 1);
        
        
        feature116 &= 0xffff;
        // Decision Tree Logic
        if (!(feature116 <= 1750))
            result_gpr[4] &= ~(1 << 29);

        if (!(feature116 <= 1750))
            result_gpr[4] &= ~(1 << 30);

        if (!(feature116 <= 1750))
            result_gpr[4] &= ~(1 << 5);

        if (!(feature116 <= 1750))
            result_gpr[2] &= ~(1 << 22);

        if (!(feature116 <= 1750))
            result_gpr[2] &= ~(1 << 23);

        if (!(feature116 <= 1750))
            result_gpr[6] &= ~(1 << 18);

        if (!(feature116 <= 1750))
            result_gpr[4] &= ~(1 << 16);

        if (!(feature116 <= 1750))
            result_gpr[4] &= ~(1 << 17);

        if (!(feature116 <= 1750))
            result_gpr[1] &= ~(1 << 17);

        if (!(feature116 <= 1750))
            result_gpr[1] &= ~(1 << 18);

        if (!(feature116 <= 1750))
            result_gpr[1] &= ~(1 << 19);

        if (!(feature116 <= 1750))
            result_gpr[7] &= ~(1 << 28);

        if (!(feature116 <= 1750))
            result_gpr[7] &= ~(1 << 18);

        if (!(feature116 <= 1750))
            result_gpr[3] &= ~(1 << 31);

        if (!(feature116 <= 1750))
            result_gpr[2] &= ~(1 << 0);

        if (!(feature116 <= 1750))
            result_gpr[5] &= ~(1 << 10);

        if (!(feature116 <= 1750))
            result_gpr[4] &= ~(1 << 22);

        if (!(feature116 <= 1750))
            result_gpr[4] &= ~(1 << 23);

        if (!(feature116 <= 1750))
            result_gpr[5] &= ~(1 << 14);

        if (!(feature116 <= 1750))
            result_gpr[5] &= ~(1 << 15);

        if (!(feature116 <= 1750))
            result_gpr[5] &= ~(1 << 13);

        if (!(feature116 <= 1750))
            result_gpr[5] &= ~(1 << 28);

        if (!(feature116 <= 1750))
            result_gpr[5] &= ~(1 << 29);

        if (!(feature116 <= 1750))
            result_gpr[0] &= ~(1 << 14);

        if (!(feature116 <= 1750))
            result_gpr[0] &= ~(1 << 15);

        if (!(feature116 <= 1750))
            result_gpr[0] &= ~(1 << 13);

        if (!(feature116 <= 1750))
            result_gpr[4] &= ~(1 << 9);

        if (!(feature116 <= 1750))
            result_gpr[7] &= ~(1 << 5);

        if (!(feature116 <= 1750))
            result_gpr[4] &= ~(1 << 24);

        if (!(feature116 <= 1750))
            result_gpr[4] &= ~(1 << 25);

        if (!(feature116 <= 1750))
            result_gpr[7] &= ~(1 << 26);

        if (!(feature116 <= 1750))
            result_gpr[7] &= ~(1 << 27);

        if (!(feature116 <= 1750))
            result_gpr[4] &= ~(1 << 12);

        if (!(feature116 <= 1750))
            result_gpr[4] &= ~(1 << 13);

        if (!(feature116 <= 1750))
            result_gpr[5] &= ~(1 << 7);

        if (!(feature116 <= 1750))
            result_gpr[3] &= ~(1 << 18);

        if (!(feature116 <= 1750))
            result_gpr[2] &= ~(1 << 20);

        if (!(feature116 <= 1750))
            result_gpr[2] &= ~(1 << 21);

        if (!(feature116 <= 1750))
            result_gpr[4] &= ~(1 << 31);

        if (!(feature116 <= 1750))
            result_gpr[7] &= ~(1 << 10);

        if (!(feature116 <= 1750))
            result_gpr[5] &= ~(1 << 3);

        if (!(feature116 <= 1750))
            result_gpr[5] &= ~(1 << 4);

        if (!(feature116 <= 1750))
            result_gpr[4] &= ~(1 << 6);

        if (!(feature116 <= 1750))
            result_gpr[4] &= ~(1 << 7);

        if (!(feature116 <= 1750))
            result_gpr[6] &= ~(1 << 29);

        if (!(feature116 <= 1750))
            result_gpr[2] &= ~(1 << 9);

        if (!(feature116 <= 1750))
            result_gpr[2] &= ~(1 << 10);

        if (!(feature116 <= 1750))
            result_gpr[5] &= ~(1 << 11);

        if (!(feature116 <= 1750))
            result_gpr[5] &= ~(1 << 12);

        if (!(feature116 <= 1750))
            result_gpr[7] &= ~(1 << 11);

        if (!(feature116 <= 1750))
            result_gpr[6] &= ~(1 << 1);

        if (!(feature116 <= 1750))
            result_gpr[3] &= ~(1 << 14);

        if (!(feature116 <= 1750))
            result_gpr[3] &= ~(1 << 15);

        if (!(feature116 <= 1750))
            result_gpr[5] &= ~(1 << 1);

        if (!(feature116 <= 1750))
            result_gpr[5] &= ~(1 << 2);

        if (!(feature116 <= 1750))
            result_gpr[7] &= ~(1 << 16);

        if (!(feature116 <= 1750))
            result_gpr[7] &= ~(1 << 1);

        if (!(feature116 <= 1750))
            result_gpr[4] &= ~(1 << 27);

        if (!(feature116 <= 1750))
            result_gpr[4] &= ~(1 << 28);

        if (!(feature116 > 1750))
            result_gpr[7] &= ~(1 << 15);

        if (!(feature116 > 1750))
            result_gpr[6] &= ~(1 << 7);

        if (!(feature116 > 1750))
            result_gpr[6] &= ~(1 << 8);

        if (!(feature116 > 1750))
            result_gpr[7] &= ~(1 << 0);


        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 7, 0, __xfer_reg_number(result_xfer41, __nfp_meid(36, 7)) + (__ctx() * 32), sizeof(result_xfer41), &local_signal);
    }

    return 0;
}


