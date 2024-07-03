#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal10;
__visible __xread uint32_t remote_xfer10[2];

__remote SIGNAL result_signal10;
__remote __xread uint32_t result_xfer10[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature28;
    __gpr uint32_t feature29;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal10, 1);
    __assign_relative_register(&local_signal, 3);
    __implicit_write(&remote_signal10, sizeof(remote_signal10));
    __implicit_write(&remote_xfer10, sizeof(remote_xfer10));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal10);
        reg_cp(&feature28, remote_xfer10, sizeof(feature28));
        reg_cp(&feature29, remote_xfer10+1, sizeof(feature29));
        
        feature28 &= 0xffff;
        // Decision Tree Logic
        if (!(feature28 <= 519))
            result_gpr[1] &= ~(1 << 3);

        if (!(feature28 <= 519))
            result_gpr[1] &= ~(1 << 8);

        if (!(feature28 <= 519))
            result_gpr[1] &= ~(1 << 9);

        if (!(feature28 <= 519))
            result_gpr[5] &= ~(1 << 18);

        if (!(feature28 <= 519))
            result_gpr[7] &= ~(1 << 29);

        if (!(feature28 <= 519))
            result_gpr[6] &= ~(1 << 12);

        if (!(feature28 <= 519))
            result_gpr[5] &= ~(1 << 8);

        if (!(feature28 <= 519))
            result_gpr[2] &= ~(1 << 26);

        if (!(feature28 <= 519))
            result_gpr[2] &= ~(1 << 27);

        if (!(feature28 <= 519))
            result_gpr[1] &= ~(1 << 1);

        if (!(feature28 <= 519))
            result_gpr[1] &= ~(1 << 2);

        if (!(feature28 <= 519))
            result_gpr[1] &= ~(1 << 20);

        if (!(feature28 <= 519))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature28 <= 519))
            result_gpr[0] &= ~(1 << 10);

        if (!(feature28 <= 519))
            result_gpr[0] &= ~(1 << 11);

        if (!(feature28 <= 519))
            result_gpr[0] &= ~(1 << 12);

        if (!(feature28 <= 519))
            result_gpr[7] &= ~(1 << 31);

        if (!(feature28 <= 519))
            result_gpr[6] &= ~(1 << 0);

        if (!(feature28 <= 519))
            result_gpr[4] &= ~(1 << 14);

        if (!(feature28 <= 519))
            result_gpr[4] &= ~(1 << 15);

        if (!(feature28 <= 519))
            result_gpr[7] &= ~(1 << 3);

        if (!(feature28 <= 519))
            result_gpr[5] &= ~(1 << 27);

        if (!(feature28 <= 519))
            result_gpr[2] &= ~(1 << 11);

        if (!(feature28 <= 519))
            result_gpr[1] &= ~(1 << 6);

        if (!(feature28 <= 519))
            result_gpr[1] &= ~(1 << 7);

        if (!(feature28 <= 519))
            result_gpr[5] &= ~(1 << 0);

        if (!(feature28 <= 519))
            result_gpr[0] &= ~(1 << 19);

        if (!(feature28 <= 519))
            result_gpr[0] &= ~(1 << 20);

        if (!(feature28 <= 519))
            result_gpr[0] &= ~(1 << 18);

        if (!(feature28 <= 519))
            result_gpr[3] &= ~(1 << 19);

        if (!(feature28 <= 519))
            result_gpr[3] &= ~(1 << 20);

        if (!(feature28 <= 519))
            result_gpr[7] &= ~(1 << 12);

        if (!(feature28 > 519))
            result_gpr[7] &= ~(1 << 2);

        if (!(feature28 > 519))
            result_gpr[7] &= ~(1 << 19);

        if (!(feature28 > 519))
            result_gpr[1] &= ~(1 << 12);

        if (!(feature28 > 519))
            result_gpr[1] &= ~(1 << 13);

        if (!(feature28 > 519))
            result_gpr[4] &= ~(1 << 2);

        
        feature29 >>= 16;
        // Decision Tree Logic
        if (!(feature29 <= 2251))
            result_gpr[6] &= ~(1 << 7);

        if (!(feature29 > 2251))
            result_gpr[6] &= ~(1 << 8);

        if (!(feature29 <= 33))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature29 > 33))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature29 <= 38))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature29 > 38))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature29 > 38))
            result_gpr[0] &= ~(1 << 0);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 11, 0, __xfer_reg_number(result_xfer10, __nfp_meid(35, 11)) + (__ctx() * 32), sizeof(result_xfer10), &local_signal);
    }

    return 0;
}


