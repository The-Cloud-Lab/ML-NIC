#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal21;
__visible __xread uint32_t remote_xfer21;

__remote SIGNAL result_signal21;
__remote __xread uint32_t result_xfer21[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature67;
    __gpr uint32_t feature68;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal21, 1);
    __assign_relative_register(&local_signal, 2);
    __implicit_write(&remote_signal21, sizeof(remote_signal21));
    __implicit_write(&remote_xfer21, sizeof(remote_xfer21));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal21);
        reg_cp(&feature67, &remote_xfer21, sizeof(feature67));
        reg_cp(&feature68, &remote_xfer21, sizeof(feature68));
        
        feature67 >>= 16;
        // Decision Tree Logic
        if (!(feature67 <= 180))
            result_gpr[4] &= ~(1 << 19);

        if (!(feature67 > 180))
            result_gpr[4] &= ~(1 << 21);

        if (!(feature67 > 180))
            result_gpr[0] &= ~(1 << 24);

        if (!(feature67 > 180))
            result_gpr[0] &= ~(1 << 25);

        if (!(feature67 > 180))
            result_gpr[0] &= ~(1 << 26);

        if (!(feature67 > 180))
            result_gpr[2] &= ~(1 << 5);

        if (!(feature67 > 180))
            result_gpr[2] &= ~(1 << 6);

        if (!(feature67 > 180))
            result_gpr[4] &= ~(1 << 20);
        
        feature68 &= 0xffff;
        // Decision Tree Logic
        if (!(feature68 <= 141))
            result_gpr[4] &= ~(1 << 29);

        if (!(feature68 <= 141))
            result_gpr[4] &= ~(1 << 30);

        if (!(feature68 <= 141))
            result_gpr[4] &= ~(1 << 5);

        if (!(feature68 <= 141))
            result_gpr[2] &= ~(1 << 22);

        if (!(feature68 <= 141))
            result_gpr[2] &= ~(1 << 23);

        if (!(feature68 <= 141))
            result_gpr[6] &= ~(1 << 18);

        if (!(feature68 <= 141))
            result_gpr[4] &= ~(1 << 16);

        if (!(feature68 <= 141))
            result_gpr[4] &= ~(1 << 17);

        if (!(feature68 <= 141))
            result_gpr[1] &= ~(1 << 17);

        if (!(feature68 <= 141))
            result_gpr[1] &= ~(1 << 18);

        if (!(feature68 <= 141))
            result_gpr[1] &= ~(1 << 19);

        if (!(feature68 <= 141))
            result_gpr[7] &= ~(1 << 28);

        if (!(feature68 <= 141))
            result_gpr[7] &= ~(1 << 18);

        if (!(feature68 <= 141))
            result_gpr[3] &= ~(1 << 31);

        if (!(feature68 <= 141))
            result_gpr[2] &= ~(1 << 0);

        if (!(feature68 <= 141))
            result_gpr[5] &= ~(1 << 10);

        if (!(feature68 <= 141))
            result_gpr[4] &= ~(1 << 22);

        if (!(feature68 <= 141))
            result_gpr[4] &= ~(1 << 23);

        if (!(feature68 <= 141))
            result_gpr[5] &= ~(1 << 14);

        if (!(feature68 <= 141))
            result_gpr[5] &= ~(1 << 15);

        if (!(feature68 <= 141))
            result_gpr[5] &= ~(1 << 13);

        if (!(feature68 <= 141))
            result_gpr[5] &= ~(1 << 28);

        if (!(feature68 <= 141))
            result_gpr[5] &= ~(1 << 29);

        if (!(feature68 <= 141))
            result_gpr[0] &= ~(1 << 14);

        if (!(feature68 <= 141))
            result_gpr[0] &= ~(1 << 15);

        if (!(feature68 <= 141))
            result_gpr[0] &= ~(1 << 13);

        if (!(feature68 <= 141))
            result_gpr[4] &= ~(1 << 9);

        if (!(feature68 <= 141))
            result_gpr[7] &= ~(1 << 5);

        if (!(feature68 > 141))
            result_gpr[4] &= ~(1 << 24);

        if (!(feature68 > 141))
            result_gpr[4] &= ~(1 << 25);

        if (!(feature68 > 141))
            result_gpr[7] &= ~(1 << 26);

        if (!(feature68 > 141))
            result_gpr[7] &= ~(1 << 27);

        if (!(feature68 > 141))
            result_gpr[4] &= ~(1 << 12);

        if (!(feature68 > 141))
            result_gpr[4] &= ~(1 << 13);

        if (!(feature68 > 141))
            result_gpr[5] &= ~(1 << 7);

        if (!(feature68 > 141))
            result_gpr[3] &= ~(1 << 18);

        if (!(feature68 > 141))
            result_gpr[2] &= ~(1 << 20);

        if (!(feature68 > 141))
            result_gpr[2] &= ~(1 << 21);

        if (!(feature68 > 141))
            result_gpr[4] &= ~(1 << 31);

        if (!(feature68 > 141))
            result_gpr[7] &= ~(1 << 10);

        if (!(feature68 > 141))
            result_gpr[5] &= ~(1 << 3);

        if (!(feature68 > 141))
            result_gpr[5] &= ~(1 << 4);

        if (!(feature68 > 141))
            result_gpr[4] &= ~(1 << 6);

        if (!(feature68 > 141))
            result_gpr[4] &= ~(1 << 7);

        if (!(feature68 > 141))
            result_gpr[6] &= ~(1 << 29);

        if (!(feature68 > 141))
            result_gpr[2] &= ~(1 << 9);

        if (!(feature68 > 141))
            result_gpr[2] &= ~(1 << 10);

        if (!(feature68 > 141))
            result_gpr[5] &= ~(1 << 11);

        if (!(feature68 > 141))
            result_gpr[5] &= ~(1 << 12);

        if (!(feature68 > 141))
            result_gpr[7] &= ~(1 << 11);

        if (!(feature68 <= 1313))
            result_gpr[2] &= ~(1 << 18);

        if (!(feature68 <= 1313))
            result_gpr[2] &= ~(1 << 19);

        if (!(feature68 <= 1313))
            result_gpr[4] &= ~(1 << 19);

        if (!(feature68 <= 1313))
            result_gpr[4] &= ~(1 << 21);

        if (!(feature68 <= 1313))
            result_gpr[0] &= ~(1 << 24);

        if (!(feature68 <= 1313))
            result_gpr[0] &= ~(1 << 25);

        if (!(feature68 <= 1313))
            result_gpr[0] &= ~(1 << 26);

        if (!(feature68 <= 1313))
            result_gpr[2] &= ~(1 << 5);

        if (!(feature68 <= 1313))
            result_gpr[2] &= ~(1 << 6);

        if (!(feature68 <= 1313))
            result_gpr[4] &= ~(1 << 20);

        if (!(feature68 <= 1313))
            result_gpr[6] &= ~(1 << 23);

        if (!(feature68 <= 1313))
            result_gpr[6] &= ~(1 << 24);

        if (!(feature68 > 1313))
            result_gpr[6] &= ~(1 << 16);

        if (!(feature68 > 1313))
            result_gpr[6] &= ~(1 << 17);

        if (!(feature68 <= 621))
            result_gpr[7] &= ~(1 << 23);

        if (!(feature68 > 621))
            result_gpr[6] &= ~(1 << 25);

        if (!(feature68 > 621))
            result_gpr[6] &= ~(1 << 26);

        if (!(feature68 <= 547))
            result_gpr[7] &= ~(1 << 20);

        if (!(feature68 <= 547))
            result_gpr[5] &= ~(1 << 16);

        if (!(feature68 <= 547))
            result_gpr[5] &= ~(1 << 17);

        if (!(feature68 <= 547))
            result_gpr[3] &= ~(1 << 2);

        if (!(feature68 <= 547))
            result_gpr[3] &= ~(1 << 3);

        if (!(feature68 <= 547))
            result_gpr[3] &= ~(1 << 4);

        if (!(feature68 > 547))
            result_gpr[5] &= ~(1 << 19);

        if (!(feature68 > 547))
            result_gpr[5] &= ~(1 << 20);

        if (!(feature68 > 547))
            result_gpr[5] &= ~(1 << 21);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 2, 0, __xfer_reg_number(result_xfer21, __nfp_meid(36, 2)) + (__ctx() * 32), sizeof(result_xfer21), &local_signal);
    }

    return 0;
}


