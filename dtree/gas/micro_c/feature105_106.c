#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal37;
__visible __xread uint32_t remote_xfer37;

__remote SIGNAL result_signal37;
__remote __xread uint32_t result_xfer37[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature105;
    __gpr uint32_t feature106;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal37, 1);
    __assign_relative_register(&local_signal, 2);
    __implicit_write(&remote_signal37, sizeof(remote_signal37));
    __implicit_write(&remote_xfer37, sizeof(remote_xfer37));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal37);
        reg_cp(&feature105, &remote_xfer37, sizeof(feature105));
        reg_cp(&feature106, &remote_xfer37, sizeof(feature106));
        
        feature105 >>= 16;
        // Decision Tree Logic
        if (!(feature105 <= 2098))
            result_gpr[4] &= ~(1 << 29);

        if (!(feature105 <= 2098))
            result_gpr[4] &= ~(1 << 30);

        if (!(feature105 <= 2098))
            result_gpr[4] &= ~(1 << 5);

        if (!(feature105 <= 2098))
            result_gpr[2] &= ~(1 << 22);

        if (!(feature105 <= 2098))
            result_gpr[2] &= ~(1 << 23);

        if (!(feature105 <= 2098))
            result_gpr[6] &= ~(1 << 18);

        if (!(feature105 <= 2098))
            result_gpr[4] &= ~(1 << 16);

        if (!(feature105 <= 2098))
            result_gpr[4] &= ~(1 << 17);

        if (!(feature105 <= 2098))
            result_gpr[1] &= ~(1 << 17);

        if (!(feature105 <= 2098))
            result_gpr[1] &= ~(1 << 18);

        if (!(feature105 <= 2098))
            result_gpr[1] &= ~(1 << 19);

        if (!(feature105 <= 2098))
            result_gpr[7] &= ~(1 << 28);

        if (!(feature105 <= 2098))
            result_gpr[7] &= ~(1 << 18);

        if (!(feature105 <= 2098))
            result_gpr[3] &= ~(1 << 31);

        if (!(feature105 <= 2098))
            result_gpr[2] &= ~(1 << 0);

        if (!(feature105 <= 2098))
            result_gpr[5] &= ~(1 << 10);

        if (!(feature105 <= 2098))
            result_gpr[4] &= ~(1 << 22);

        if (!(feature105 <= 2098))
            result_gpr[4] &= ~(1 << 23);

        if (!(feature105 <= 2098))
            result_gpr[5] &= ~(1 << 14);

        if (!(feature105 <= 2098))
            result_gpr[5] &= ~(1 << 15);

        if (!(feature105 <= 2098))
            result_gpr[5] &= ~(1 << 13);

        if (!(feature105 <= 2098))
            result_gpr[5] &= ~(1 << 28);

        if (!(feature105 <= 2098))
            result_gpr[5] &= ~(1 << 29);

        if (!(feature105 <= 2098))
            result_gpr[0] &= ~(1 << 14);

        if (!(feature105 <= 2098))
            result_gpr[0] &= ~(1 << 15);

        if (!(feature105 <= 2098))
            result_gpr[0] &= ~(1 << 13);

        if (!(feature105 <= 2098))
            result_gpr[4] &= ~(1 << 9);

        if (!(feature105 <= 2098))
            result_gpr[7] &= ~(1 << 5);

        if (!(feature105 <= 2098))
            result_gpr[4] &= ~(1 << 24);

        if (!(feature105 <= 2098))
            result_gpr[4] &= ~(1 << 25);

        if (!(feature105 <= 2098))
            result_gpr[7] &= ~(1 << 26);

        if (!(feature105 <= 2098))
            result_gpr[7] &= ~(1 << 27);

        if (!(feature105 <= 2098))
            result_gpr[4] &= ~(1 << 12);

        if (!(feature105 <= 2098))
            result_gpr[4] &= ~(1 << 13);

        if (!(feature105 <= 2098))
            result_gpr[5] &= ~(1 << 7);

        if (!(feature105 <= 2098))
            result_gpr[3] &= ~(1 << 18);

        if (!(feature105 <= 2098))
            result_gpr[2] &= ~(1 << 20);

        if (!(feature105 <= 2098))
            result_gpr[2] &= ~(1 << 21);

        if (!(feature105 <= 2098))
            result_gpr[4] &= ~(1 << 31);

        if (!(feature105 <= 2098))
            result_gpr[7] &= ~(1 << 10);

        if (!(feature105 <= 2098))
            result_gpr[5] &= ~(1 << 3);

        if (!(feature105 <= 2098))
            result_gpr[5] &= ~(1 << 4);

        if (!(feature105 <= 2098))
            result_gpr[4] &= ~(1 << 6);

        if (!(feature105 <= 2098))
            result_gpr[4] &= ~(1 << 7);

        if (!(feature105 <= 2098))
            result_gpr[6] &= ~(1 << 29);

        if (!(feature105 <= 2098))
            result_gpr[2] &= ~(1 << 9);

        if (!(feature105 <= 2098))
            result_gpr[2] &= ~(1 << 10);

        if (!(feature105 <= 2098))
            result_gpr[5] &= ~(1 << 11);

        if (!(feature105 <= 2098))
            result_gpr[5] &= ~(1 << 12);

        if (!(feature105 <= 2098))
            result_gpr[7] &= ~(1 << 11);

        if (!(feature105 > 2098 && feature105 <= 2298))
            result_gpr[6] &= ~(1 << 1);

        if (!(feature105 > 2098 && feature105 <= 2298))
            result_gpr[3] &= ~(1 << 14);

        if (!(feature105 > 2098 && feature105 <= 2298))
            result_gpr[3] &= ~(1 << 15);

        if (!(feature105 > 2098 && feature105 > 2298))
            result_gpr[5] &= ~(1 << 1);

        if (!(feature105 > 2098 && feature105 > 2298))
            result_gpr[5] &= ~(1 << 2);

        if (!(feature105 > 2098))
            result_gpr[7] &= ~(1 << 16);

        if (!(feature105 > 2098 && feature105 <= 3204))
            result_gpr[7] &= ~(1 << 1);

        if (!(feature105 > 2098 && feature105 > 3204))
            result_gpr[4] &= ~(1 << 27);

        if (!(feature105 > 2098 && feature105 > 3204))
            result_gpr[4] &= ~(1 << 28);

        if (!(feature105 <= 1468))
            result_gpr[6] &= ~(1 << 4);

        if (!(feature105 <= 1468))
            result_gpr[6] &= ~(1 << 5);

        if (!(feature105 > 1468))
            result_gpr[3] &= ~(1 << 25);

        if (!(feature105 > 1468))
            result_gpr[3] &= ~(1 << 26);

        if (!(feature105 > 1468))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature105 > 1468))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature105 > 1468))
            result_gpr[1] &= ~(1 << 0);

        if (!(feature105 > 1468))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature105 > 1468))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature105 > 1468))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature105 > 1468))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature105 > 1468))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature105 > 1468))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature105 > 1468))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature105 > 1468))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature105 > 1468))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature105 > 1468))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature105 > 1468))
            result_gpr[2] &= ~(1 << 24);

        if (!(feature105 > 1468))
            result_gpr[2] &= ~(1 << 25);

        if (!(feature105 > 1468))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature105 > 1468))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature105 > 1468))
            result_gpr[5] &= ~(1 << 31);

        if (!(feature105 > 1468))
            result_gpr[5] &= ~(1 << 9);

        if (!(feature105 > 1468))
            result_gpr[6] &= ~(1 << 10);

        if (!(feature105 > 1468))
            result_gpr[5] &= ~(1 << 23);

        if (!(feature105 > 1468))
            result_gpr[5] &= ~(1 << 24);
        
        
        feature106 &= 0xffff;
        // Decision Tree Logic
        if (!(feature106 <= 2076))
            result_gpr[7] &= ~(1 << 18);

        if (!(feature106 <= 2076))
            result_gpr[3] &= ~(1 << 31);

        if (!(feature106 <= 2076))
            result_gpr[2] &= ~(1 << 0);

        if (!(feature106 <= 2076))
            result_gpr[5] &= ~(1 << 10);

        if (!(feature106 <= 2076))
            result_gpr[4] &= ~(1 << 22);

        if (!(feature106 <= 2076))
            result_gpr[4] &= ~(1 << 23);

        if (!(feature106 <= 2076))
            result_gpr[5] &= ~(1 << 14);

        if (!(feature106 <= 2076))
            result_gpr[5] &= ~(1 << 15);

        if (!(feature106 <= 2076))
            result_gpr[5] &= ~(1 << 13);

        if (!(feature106 <= 2076))
            result_gpr[5] &= ~(1 << 28);

        if (!(feature106 <= 2076))
            result_gpr[5] &= ~(1 << 29);

        if (!(feature106 <= 2076 && feature106 <= 708))
            result_gpr[0] &= ~(1 << 14);

        if (!(feature106 <= 2076 && feature106 > 708))
            result_gpr[0] &= ~(1 << 15);

        if (!(feature106 <= 2076))
            result_gpr[0] &= ~(1 << 13);

        if (!(feature106 <= 2076))
            result_gpr[4] &= ~(1 << 9);

        if (!(feature106 > 2076))
            result_gpr[7] &= ~(1 << 5);

        if (!(feature106 <= 4404))
            result_gpr[7] &= ~(1 << 15);

        if (!(feature106 <= 4404))
            result_gpr[6] &= ~(1 << 7);

        if (!(feature106 <= 4404))
            result_gpr[6] &= ~(1 << 8);

        if (!(feature106 > 4404))
            result_gpr[7] &= ~(1 << 0);

        if (!(feature106 <= 4107))
            result_gpr[3] &= ~(1 << 23);

        if (!(feature106 > 4107))
            result_gpr[3] &= ~(1 << 24);

        if (!(feature106 <= 991))
            result_gpr[3] &= ~(1 << 16);

        if (!(feature106 > 991))
            result_gpr[3] &= ~(1 << 17);

        if (!(feature106 <= 2656))
            result_gpr[6] &= ~(1 << 11);

        if (!(feature106 > 2656))
            result_gpr[6] &= ~(1 << 30);

        if (!(feature106 > 2656))
            result_gpr[2] &= ~(1 << 7);

        if (!(feature106 > 2656))
            result_gpr[2] &= ~(1 << 8);

        if (!(feature106 <= 1752))
            result_gpr[5] &= ~(1 << 27);

        if (!(feature106 > 1752))
            result_gpr[2] &= ~(1 << 11);

        if (!(feature106 > 1752))
            result_gpr[1] &= ~(1 << 6);

        if (!(feature106 > 1752))
            result_gpr[1] &= ~(1 << 7);


        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 6, 0, __xfer_reg_number(result_xfer37, __nfp_meid(36, 6)) + (__ctx() * 32), sizeof(result_xfer37), &local_signal);
    }

    return 0;
}


