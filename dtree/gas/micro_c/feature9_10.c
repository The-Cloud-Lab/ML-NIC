#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal3;
__visible __xread uint32_t remote_xfer3;

__remote SIGNAL result_signal3;
__remote __xread uint32_t result_xfer3[8];

SIGNAL local_signal;

int main(void) {
    __gpr uint32_t feature9;
    __gpr uint32_t feature10;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal3, 1);
    __assign_relative_register(&local_signal, 4);
    __implicit_write(&remote_signal3, sizeof(remote_signal3));
    __implicit_write(&remote_xfer3, sizeof(remote_xfer3));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal3);
        reg_cp(&feature9, &remote_xfer3, sizeof(feature9));
        reg_cp(&feature10, &remote_xfer3, sizeof(feature10));
                
        feature9 >>= 16;
        // Decision Tree Logic
        if (!(feature9 <= 1432))
            result_gpr[7] &= ~(1 << 22);

        if (!(feature9 <= 1432))
            result_gpr[5] &= ~(1 << 25);

        if (!(feature9 <= 1432))
            result_gpr[5] &= ~(1 << 26);

        if (!(feature9 <= 1432))
            result_gpr[7] &= ~(1 << 25);

        if (!(feature9 <= 1432))
            result_gpr[5] &= ~(1 << 22);

        if (!(feature9 <= 1432))
            result_gpr[2] &= ~(1 << 28);

        if (!(feature9 <= 1432))
            result_gpr[2] &= ~(1 << 29);

        if (!(feature9 <= 1432))
            result_gpr[7] &= ~(1 << 9);

        if (!(feature9 > 1432))
            result_gpr[2] &= ~(1 << 1);

        if (!(feature9 > 1432))
            result_gpr[2] &= ~(1 << 2);

        if (!(feature9 > 1432))
            result_gpr[5] &= ~(1 << 6);

        if (!(feature9 > 1432))
            result_gpr[0] &= ~(1 << 30);

        if (!(feature9 > 1432))
            result_gpr[0] &= ~(1 << 31);

        if (!(feature9 > 1432))
            result_gpr[0] &= ~(1 << 5);

        if (!(feature9 > 1432))
            result_gpr[0] &= ~(1 << 6);

        if (!(feature9 > 1432))
            result_gpr[0] &= ~(1 << 7);

        if (!(feature9 > 1432 && feature9 <= 1516))
            result_gpr[0] &= ~(1 << 8);

        if (!(feature9 > 1432 && feature9 > 1516))
            result_gpr[0] &= ~(1 << 9);

        if (!(feature9 > 1432))
            result_gpr[0] &= ~(1 << 4);

        if (!(feature9 > 1432))
            result_gpr[0] &= ~(1 << 2);

        if (!(feature9 > 1432))
            result_gpr[0] &= ~(1 << 3);

        if (!(feature9 > 1432))
            result_gpr[0] &= ~(1 << 1);

        if (!(feature9 > 1432))
            result_gpr[5] &= ~(1 << 5);

        if (!(feature9 > 1432))
            result_gpr[6] &= ~(1 << 3);

        if (!(feature9 > 1432))
            result_gpr[3] &= ~(1 << 23);

        if (!(feature9 > 1432))
            result_gpr[3] &= ~(1 << 24);

        if (!(feature9 > 1432))
            result_gpr[6] &= ~(1 << 6);

        if (!(feature9 > 1432))
            result_gpr[2] &= ~(1 << 3);

        if (!(feature9 > 1432))
            result_gpr[2] &= ~(1 << 4);

        if (!(feature9 <= 283))
            result_gpr[7] &= ~(1 << 6);

        if (!(feature9 > 283))
            result_gpr[3] &= ~(1 << 9);

        if (!(feature9 > 283))
            result_gpr[3] &= ~(1 << 10);

        if (!(feature9 > 283))
            result_gpr[3] &= ~(1 << 11);

        if (!(feature9 <= 698))
            result_gpr[6] &= ~(1 << 27);

        if (!(feature9 > 698))
            result_gpr[6] &= ~(1 << 28);

        
        feature10 &= 0xffff;
        // Decision Tree Logic
        if (!(feature10 <= 9))
            result_gpr[5] &= ~(1 << 14);

        if (!(feature10 > 9))
            result_gpr[5] &= ~(1 << 15);

        if (!(feature10 <= 16))
            result_gpr[7] &= ~(1 << 22);

        if (!(feature10 <= 16))
            result_gpr[5] &= ~(1 << 25);

        if (!(feature10 <= 16))
            result_gpr[5] &= ~(1 << 26);

        if (!(feature10 > 16))
            result_gpr[7] &= ~(1 << 25);

        if (!(feature10 > 16))
            result_gpr[5] &= ~(1 << 22);

        if (!(feature10 > 16))
            result_gpr[2] &= ~(1 << 28);

        if (!(feature10 > 16))
            result_gpr[2] &= ~(1 << 29);

        if (!(feature10 > 16))
            result_gpr[7] &= ~(1 << 9);

        if (!(feature10 <= 63))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature10 <= 63))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature10 <= 63))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature10 > 63))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature10 > 63))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature10 <= 60))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature10 <= 60))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature10 <= 60))
            result_gpr[0] &= ~(1 << 0);

        if (!(feature10 <= 60))
            result_gpr[4] &= ~(1 << 26);

        if (!(feature10 > 60))
            result_gpr[4] &= ~(1 << 0);

        if (!(feature10 > 60))
            result_gpr[4] &= ~(1 << 1);

        if (!(feature10 <= 3))
            result_gpr[3] &= ~(1 << 21);

        if (!(feature10 <= 3))
            result_gpr[3] &= ~(1 << 22);

        if (!(feature10 <= 3))
            result_gpr[7] &= ~(1 << 17);

        if (!(feature10 > 3))
            result_gpr[7] &= ~(1 << 4);

        if (!(feature10 > 3))
            result_gpr[5] &= ~(1 << 30);

        if (!(feature10 > 3))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature10 > 3))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature10 > 3))
            result_gpr[1] &= ~(1 << 15);

        if (!(feature10 > 3))
            result_gpr[1] &= ~(1 << 16);

        if (!(feature10 > 3))
            result_gpr[1] &= ~(1 << 14);

        if (!(feature10 > 3))
            result_gpr[4] &= ~(1 << 18);

        if (!(feature10 > 3))
            result_gpr[2] &= ~(1 << 12);

        if (!(feature10 > 3))
            result_gpr[2] &= ~(1 << 13);

        if (!(feature10 <= 18))
            result_gpr[3] &= ~(1 << 29);

        if (!(feature10 <= 18))
            result_gpr[3] &= ~(1 << 30);

        if (!(feature10 <= 18))
            result_gpr[6] &= ~(1 << 20);

        if (!(feature10 > 18))
            result_gpr[7] &= ~(1 << 21);

        if (!(feature10 <= 92))
            result_gpr[0] &= ~(1 << 19);

        if (!(feature10 > 92))
            result_gpr[0] &= ~(1 << 20);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 9, 0, __xfer_reg_number(result_xfer3, __nfp_meid(35, 9)) + (__ctx() * 32), sizeof(result_xfer3), &local_signal);
    }

    return 0;
}


