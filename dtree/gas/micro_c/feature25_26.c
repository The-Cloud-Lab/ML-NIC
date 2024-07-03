#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal9;
__visible __xread uint32_t remote_xfer9;

__remote SIGNAL result_signal9;
__remote __xread uint32_t result_xfer9[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature25;
    __gpr uint32_t feature26;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal9, 1);
    __assign_relative_register(&local_signal, 2);
    __implicit_write(&remote_signal9, sizeof(remote_signal9));
    __implicit_write(&remote_xfer9, sizeof(remote_xfer9));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal9);
        reg_cp(&feature25, &remote_xfer9, sizeof(feature25));
        reg_cp(&feature26, &remote_xfer9, sizeof(feature26));        
        
        feature25 >>= 16;
        // Decision Tree Logic
        if (!(feature25 <= 2844))
            result_gpr[2] &= ~(1 << 16);

        if (!(feature25 > 2844))
            result_gpr[2] &= ~(1 << 17);

        if (!(feature25 <= 2681))
            result_gpr[3] &= ~(1 << 21);

        if (!(feature25 <= 2681))
            result_gpr[3] &= ~(1 << 22);

        if (!(feature25 <= 2681))
            result_gpr[7] &= ~(1 << 17);

        if (!(feature25 <= 2681))
            result_gpr[7] &= ~(1 << 4);

        if (!(feature25 <= 2681))
            result_gpr[5] &= ~(1 << 30);

        if (!(feature25 <= 2681))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature25 <= 2681))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature25 <= 2681))
            result_gpr[1] &= ~(1 << 15);

        if (!(feature25 <= 2681))
            result_gpr[1] &= ~(1 << 16);

        if (!(feature25 <= 2681))
            result_gpr[1] &= ~(1 << 14);

        if (!(feature25 <= 2681))
            result_gpr[4] &= ~(1 << 18);

        if (!(feature25 <= 2681))
            result_gpr[2] &= ~(1 << 12);

        if (!(feature25 <= 2681))
            result_gpr[2] &= ~(1 << 13);

        if (!(feature25 <= 2681))
            result_gpr[0] &= ~(1 << 28);

        if (!(feature25 <= 2681))
            result_gpr[0] &= ~(1 << 29);

        if (!(feature25 <= 2681))
            result_gpr[0] &= ~(1 << 27);

        if (!(feature25 <= 2681))
            result_gpr[6] &= ~(1 << 9);

        if (!(feature25 <= 2681))
            result_gpr[7] &= ~(1 << 7);

        if (!(feature25 <= 2681))
            result_gpr[3] &= ~(1 << 29);

        if (!(feature25 <= 2681))
            result_gpr[3] &= ~(1 << 30);

        if (!(feature25 <= 2681))
            result_gpr[6] &= ~(1 << 20);

        if (!(feature25 <= 2681))
            result_gpr[7] &= ~(1 << 21);

        if (!(feature25 > 2681))
            result_gpr[7] &= ~(1 << 8);

        if (!(feature25 > 2681))
            result_gpr[7] &= ~(1 << 24);

        if (!(feature25 > 2681))
            result_gpr[1] &= ~(1 << 10);

        if (!(feature25 > 2681))
            result_gpr[1] &= ~(1 << 11);

        if (!(feature25 > 2681))
            result_gpr[4] &= ~(1 << 8);

        if (!(feature25 > 2681))
            result_gpr[7] &= ~(1 << 30);

        if (!(feature25 > 2681))
            result_gpr[6] &= ~(1 << 27);

        if (!(feature25 > 2681))
            result_gpr[6] &= ~(1 << 28);

        if (!(feature25 <= 3390))
            result_gpr[5] &= ~(1 << 16);

        if (!(feature25 > 3390))
            result_gpr[5] &= ~(1 << 17);

        if (!(feature25 <= 4018))
            result_gpr[1] &= ~(1 << 3);

        if (!(feature25 <= 4018))
            result_gpr[1] &= ~(1 << 8);

        if (!(feature25 <= 4018))
            result_gpr[1] &= ~(1 << 9);

        if (!(feature25 <= 4018))
            result_gpr[5] &= ~(1 << 18);

        if (!(feature25 <= 4018))
            result_gpr[7] &= ~(1 << 29);

        if (!(feature25 <= 4018))
            result_gpr[6] &= ~(1 << 12);

        if (!(feature25 <= 4018))
            result_gpr[5] &= ~(1 << 8);

        if (!(feature25 <= 4018))
            result_gpr[2] &= ~(1 << 26);

        if (!(feature25 <= 4018))
            result_gpr[2] &= ~(1 << 27);

        if (!(feature25 <= 4018))
            result_gpr[1] &= ~(1 << 1);

        if (!(feature25 <= 4018))
            result_gpr[1] &= ~(1 << 2);

        if (!(feature25 <= 4018))
            result_gpr[1] &= ~(1 << 20);

        if (!(feature25 <= 4018))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature25 <= 4018))
            result_gpr[0] &= ~(1 << 10);

        if (!(feature25 <= 4018))
            result_gpr[0] &= ~(1 << 11);

        if (!(feature25 <= 4018))
            result_gpr[0] &= ~(1 << 12);

        if (!(feature25 > 4018))
            result_gpr[7] &= ~(1 << 31);

        if (!(feature25 > 4018))
            result_gpr[6] &= ~(1 << 0);

        if (!(feature25 > 4018))
            result_gpr[4] &= ~(1 << 14);

        if (!(feature25 > 4018))
            result_gpr[4] &= ~(1 << 15);

        if (!(feature25 > 4018))
            result_gpr[7] &= ~(1 << 3);

        
        feature26 &= 0xffff;
        // Decision Tree Logic
        if (!(feature26 <= 261))
            result_gpr[7] &= ~(1 << 25);

        if (!(feature26 <= 261))
            result_gpr[5] &= ~(1 << 22);

        if (!(feature26 <= 261))
            result_gpr[2] &= ~(1 << 28);

        if (!(feature26 <= 261))
            result_gpr[2] &= ~(1 << 29);

        if (!(feature26 > 261))
            result_gpr[7] &= ~(1 << 9);

        if (!(feature26 <= 302))
            result_gpr[3] &= ~(1 << 21);

        if (!(feature26 <= 302))
            result_gpr[3] &= ~(1 << 22);

        if (!(feature26 <= 302))
            result_gpr[7] &= ~(1 << 17);

        if (!(feature26 <= 302))
            result_gpr[7] &= ~(1 << 4);

        if (!(feature26 <= 302))
            result_gpr[5] &= ~(1 << 30);

        if (!(feature26 <= 302))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature26 <= 302))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature26 <= 302))
            result_gpr[1] &= ~(1 << 15);

        if (!(feature26 <= 302))
            result_gpr[1] &= ~(1 << 16);

        if (!(feature26 <= 302))
            result_gpr[1] &= ~(1 << 14);

        if (!(feature26 <= 302))
            result_gpr[4] &= ~(1 << 18);

        if (!(feature26 <= 302))
            result_gpr[2] &= ~(1 << 12);

        if (!(feature26 <= 302))
            result_gpr[2] &= ~(1 << 13);

        if (!(feature26 <= 302))
            result_gpr[0] &= ~(1 << 28);

        if (!(feature26 <= 302))
            result_gpr[0] &= ~(1 << 29);

        if (!(feature26 <= 302))
            result_gpr[0] &= ~(1 << 27);

        if (!(feature26 <= 302))
            result_gpr[6] &= ~(1 << 9);

        if (!(feature26 <= 302))
            result_gpr[7] &= ~(1 << 7);

        if (!(feature26 <= 302))
            result_gpr[3] &= ~(1 << 29);

        if (!(feature26 <= 302))
            result_gpr[3] &= ~(1 << 30);

        if (!(feature26 <= 302))
            result_gpr[6] &= ~(1 << 20);

        if (!(feature26 <= 302))
            result_gpr[7] &= ~(1 << 21);

        if (!(feature26 <= 302))
            result_gpr[7] &= ~(1 << 8);

        if (!(feature26 <= 302))
            result_gpr[7] &= ~(1 << 24);

        if (!(feature26 <= 302))
            result_gpr[1] &= ~(1 << 10);

        if (!(feature26 <= 302))
            result_gpr[1] &= ~(1 << 11);

        if (!(feature26 <= 302))
            result_gpr[4] &= ~(1 << 8);

        if (!(feature26 <= 302))
            result_gpr[7] &= ~(1 << 30);

        if (!(feature26 <= 302))
            result_gpr[6] &= ~(1 << 27);

        if (!(feature26 <= 302))
            result_gpr[6] &= ~(1 << 28);

        if (!(feature26 <= 302))
            result_gpr[7] &= ~(1 << 20);

        if (!(feature26 <= 302))
            result_gpr[5] &= ~(1 << 16);

        if (!(feature26 <= 302))
            result_gpr[5] &= ~(1 << 17);

        if (!(feature26 <= 302))
            result_gpr[3] &= ~(1 << 2);

        if (!(feature26 <= 302))
            result_gpr[3] &= ~(1 << 3);

        if (!(feature26 <= 302))
            result_gpr[3] &= ~(1 << 4);

        if (!(feature26 <= 302))
            result_gpr[5] &= ~(1 << 19);

        if (!(feature26 <= 302))
            result_gpr[5] &= ~(1 << 20);

        if (!(feature26 <= 302))
            result_gpr[5] &= ~(1 << 21);

        if (!(feature26 <= 302))
            result_gpr[3] &= ~(1 << 27);

        if (!(feature26 <= 302))
            result_gpr[3] &= ~(1 << 28);

        if (!(feature26 <= 302))
            result_gpr[6] &= ~(1 << 13);

        if (!(feature26 <= 302))
            result_gpr[3] &= ~(1 << 12);

        if (!(feature26 <= 302))
            result_gpr[3] &= ~(1 << 13);

        if (!(feature26 > 302))
            result_gpr[4] &= ~(1 << 10);

        if (!(feature26 > 302))
            result_gpr[4] &= ~(1 << 11);

        if (!(feature26 > 302))
            result_gpr[2] &= ~(1 << 14);

        if (!(feature26 > 302))
            result_gpr[2] &= ~(1 << 15);

        if (!(feature26 > 302))
            result_gpr[6] &= ~(1 << 31);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 11, 0, __xfer_reg_number(result_xfer9, __nfp_meid(35, 11)) + (__ctx() * 32), sizeof(result_xfer9), &local_signal);
    }

    return 0;
}


