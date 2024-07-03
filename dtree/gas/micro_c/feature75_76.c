#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal25;
__visible __xread uint32_t remote_xfer25;

__remote SIGNAL result_signal25;
__remote __xread uint32_t result_xfer25[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature75;
    __gpr uint32_t feature76;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal25, 1);
    __assign_relative_register(&local_signal, 2);
    __implicit_write(&remote_signal25, sizeof(remote_signal25));
    __implicit_write(&remote_xfer25, sizeof(remote_xfer25));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal25);
        reg_cp(&feature75, &remote_xfer25, sizeof(feature75));
        reg_cp(&feature76, &remote_xfer25, sizeof(feature76));
        
        feature75 >>= 16;
        // Decision Tree Logic
        if (!(feature75 <= 194))
            result_gpr[5] &= ~(1 << 3);

        if (!(feature75 <= 194))
            result_gpr[5] &= ~(1 << 4);

        if (!(feature75 > 194))
            result_gpr[4] &= ~(1 << 6);

        if (!(feature75 > 194))
            result_gpr[4] &= ~(1 << 7);

        if (!(feature75 > 194))
            result_gpr[6] &= ~(1 << 29);

        if (!(feature75 <= 3988))
            result_gpr[5] &= ~(1 << 6);

        if (!(feature75 <= 3988))
            result_gpr[0] &= ~(1 << 30);

        if (!(feature75 <= 3988))
            result_gpr[0] &= ~(1 << 31);

        if (!(feature75 <= 3988))
            result_gpr[0] &= ~(1 << 5);

        if (!(feature75 <= 3988))
            result_gpr[0] &= ~(1 << 6);

        if (!(feature75 <= 3988))
            result_gpr[0] &= ~(1 << 7);

        if (!(feature75 <= 3988))
            result_gpr[0] &= ~(1 << 8);

        if (!(feature75 <= 3988))
            result_gpr[0] &= ~(1 << 9);

        if (!(feature75 <= 3988))
            result_gpr[0] &= ~(1 << 4);

        if (!(feature75 <= 3988))
            result_gpr[0] &= ~(1 << 2);

        if (!(feature75 <= 3988))
            result_gpr[0] &= ~(1 << 3);

        if (!(feature75 <= 3988))
            result_gpr[0] &= ~(1 << 1);

        if (!(feature75 <= 3988))
            result_gpr[5] &= ~(1 << 5);

        if (!(feature75 > 3988))
            result_gpr[6] &= ~(1 << 3);

        if (!(feature75 > 3988))
            result_gpr[3] &= ~(1 << 23);

        if (!(feature75 > 3988))
            result_gpr[3] &= ~(1 << 24);

        if (!(feature75 <= 53))
            result_gpr[3] &= ~(1 << 9);

        if (!(feature75 > 53))
            result_gpr[3] &= ~(1 << 10);

        if (!(feature75 > 53))
            result_gpr[3] &= ~(1 << 11);

        if (!(feature75 <= 541))
            result_gpr[7] &= ~(1 << 20);

        if (!(feature75 <= 541))
            result_gpr[5] &= ~(1 << 16);

        if (!(feature75 <= 541))
            result_gpr[5] &= ~(1 << 17);

        if (!(feature75 <= 541))
            result_gpr[3] &= ~(1 << 2);

        if (!(feature75 <= 541))
            result_gpr[3] &= ~(1 << 3);

        if (!(feature75 <= 541))
            result_gpr[3] &= ~(1 << 4);

        if (!(feature75 <= 541))
            result_gpr[5] &= ~(1 << 19);

        if (!(feature75 <= 541))
            result_gpr[5] &= ~(1 << 20);

        if (!(feature75 <= 541))
            result_gpr[5] &= ~(1 << 21);

        if (!(feature75 > 541))
            result_gpr[3] &= ~(1 << 27);

        if (!(feature75 > 541))
            result_gpr[3] &= ~(1 << 28);

        if (!(feature75 > 541))
            result_gpr[6] &= ~(1 << 13);

        if (!(feature75 > 541))
            result_gpr[3] &= ~(1 << 12);

        if (!(feature75 > 541))
            result_gpr[3] &= ~(1 << 13);

        
        feature76 &= 0xffff;
        // Decision Tree Logic
        if (!(feature76 <= 633))
            result_gpr[6] &= ~(1 << 25);

        if (!(feature76 > 633))
            result_gpr[6] &= ~(1 << 26);

        if (!(feature76 <= 304))
            result_gpr[6] &= ~(1 << 14);

        if (!(feature76 <= 304))
            result_gpr[6] &= ~(1 << 15);

        if (!(feature76 > 304))
            result_gpr[6] &= ~(1 << 4);

        if (!(feature76 > 304))
            result_gpr[6] &= ~(1 << 5);

        if (!(feature76 > 304))
            result_gpr[3] &= ~(1 << 25);

        if (!(feature76 > 304))
            result_gpr[3] &= ~(1 << 26);

        if (!(feature76 > 304))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature76 > 304))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature76 > 304))
            result_gpr[1] &= ~(1 << 0);

        if (!(feature76 > 304))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature76 > 304))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature76 > 304))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature76 > 304))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature76 > 304))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature76 > 304))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature76 > 304))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature76 > 304))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature76 > 304))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature76 > 304))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature76 > 304))
            result_gpr[2] &= ~(1 << 24);

        if (!(feature76 > 304))
            result_gpr[2] &= ~(1 << 25);

        if (!(feature76 > 304))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature76 > 304))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature76 > 304))
            result_gpr[5] &= ~(1 << 31);

        if (!(feature76 > 304))
            result_gpr[5] &= ~(1 << 9);

        if (!(feature76 > 304))
            result_gpr[6] &= ~(1 << 10);

        if (!(feature76 > 304))
            result_gpr[5] &= ~(1 << 23);

        if (!(feature76 > 304))
            result_gpr[5] &= ~(1 << 24);

        if (!(feature76 > 304))
            result_gpr[3] &= ~(1 << 0);

        if (!(feature76 > 304))
            result_gpr[3] &= ~(1 << 1);

        if (!(feature76 > 304))
            result_gpr[7] &= ~(1 << 13);

        if (!(feature76 > 304))
            result_gpr[7] &= ~(1 << 14);

        if (!(feature76 <= 359))
            result_gpr[0] &= ~(1 << 28);

        if (!(feature76 <= 359))
            result_gpr[0] &= ~(1 << 29);

        if (!(feature76 <= 359))
            result_gpr[0] &= ~(1 << 27);

        if (!(feature76 <= 359))
            result_gpr[6] &= ~(1 << 9);

        if (!(feature76 <= 359))
            result_gpr[7] &= ~(1 << 7);

        if (!(feature76 > 359))
            result_gpr[3] &= ~(1 << 29);

        if (!(feature76 > 359))
            result_gpr[3] &= ~(1 << 30);

        if (!(feature76 > 359))
            result_gpr[6] &= ~(1 << 20);

        if (!(feature76 > 359))
            result_gpr[7] &= ~(1 << 21);

        if (!(feature76 <= 757))
            result_gpr[2] &= ~(1 << 14);

        if (!(feature76 <= 757))
            result_gpr[2] &= ~(1 << 15);

        if (!(feature76 > 757))
            result_gpr[6] &= ~(1 << 31);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 3, 0, __xfer_reg_number(result_xfer25, __nfp_meid(36, 3)) + (__ctx() * 32), sizeof(result_xfer25), &local_signal);
    }

    return 0;
}


