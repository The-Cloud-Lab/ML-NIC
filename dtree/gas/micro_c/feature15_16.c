#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal6;
__visible __xread uint32_t remote_xfer6;

__remote SIGNAL result_signal6;
__remote __xread uint32_t result_xfer6[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature15;
    __gpr uint32_t feature16;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal6, 1);
    __assign_relative_register(&local_signal, 3);
    __implicit_write(&remote_signal6, sizeof(remote_signal6));
    __implicit_write(&remote_xfer6, sizeof(remote_xfer6));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal6);
        reg_cp(&feature15, &remote_xfer6, sizeof(feature15));
        reg_cp(&feature16, &remote_xfer6, sizeof(feature16));
        
        feature15 >>= 16;
        // Decision Tree Logic
        if (!(feature15 <= 7777))
            result_gpr[4] &= ~(1 << 22);

        if (!(feature15 <= 7777))
            result_gpr[4] &= ~(1 << 23);

        if (!(feature15 > 7777))
            result_gpr[5] &= ~(1 << 14);

        if (!(feature15 > 7777))
            result_gpr[5] &= ~(1 << 15);

        if (!(feature15 > 7777))
            result_gpr[5] &= ~(1 << 13);

        if (!(feature15 <= 7244))
            result_gpr[5] &= ~(1 << 6);

        if (!(feature15 <= 7244))
            result_gpr[0] &= ~(1 << 30);

        if (!(feature15 <= 7244))
            result_gpr[0] &= ~(1 << 31);

        if (!(feature15 <= 7244))
            result_gpr[0] &= ~(1 << 5);

        if (!(feature15 <= 7244))
            result_gpr[0] &= ~(1 << 6);

        if (!(feature15 <= 7244))
            result_gpr[0] &= ~(1 << 7);

        if (!(feature15 <= 7244))
            result_gpr[0] &= ~(1 << 8);

        if (!(feature15 <= 7244))
            result_gpr[0] &= ~(1 << 9);

        if (!(feature15 <= 7244))
            result_gpr[0] &= ~(1 << 4);

        if (!(feature15 <= 7244))
            result_gpr[0] &= ~(1 << 2);

        if (!(feature15 <= 7244))
            result_gpr[0] &= ~(1 << 3);

        if (!(feature15 <= 7244))
            result_gpr[0] &= ~(1 << 1);

        if (!(feature15 > 7244))
            result_gpr[5] &= ~(1 << 5);
        

        feature16 &= 0xffff;
        // Decision Tree Logic
        if (!(feature16 <= 7708))
            result_gpr[4] &= ~(1 << 5);

        if (!(feature16 <= 7708))
            result_gpr[2] &= ~(1 << 22);

        if (!(feature16 <= 7708))
            result_gpr[2] &= ~(1 << 23);

        if (!(feature16 > 7708))
            result_gpr[6] &= ~(1 << 18);

        if (!(feature16 <= 7657))
            result_gpr[4] &= ~(1 << 16);

        if (!(feature16 > 7657))
            result_gpr[4] &= ~(1 << 17);

        if (!(feature16 <= 7684))
            result_gpr[2] &= ~(1 << 9);

        if (!(feature16 > 7684))
            result_gpr[2] &= ~(1 << 10);

        if (!(feature16 <= 7378))
            result_gpr[7] &= ~(1 << 22);

        if (!(feature16 <= 7378))
            result_gpr[5] &= ~(1 << 25);

        if (!(feature16 <= 7378))
            result_gpr[5] &= ~(1 << 26);

        if (!(feature16 <= 7378))
            result_gpr[7] &= ~(1 << 25);

        if (!(feature16 <= 7378))
            result_gpr[5] &= ~(1 << 22);

        if (!(feature16 <= 7378))
            result_gpr[2] &= ~(1 << 28);

        if (!(feature16 <= 7378))
            result_gpr[2] &= ~(1 << 29);

        if (!(feature16 <= 7378))
            result_gpr[7] &= ~(1 << 9);

        if (!(feature16 <= 7378))
            result_gpr[2] &= ~(1 << 1);

        if (!(feature16 <= 7378))
            result_gpr[2] &= ~(1 << 2);

        if (!(feature16 <= 7378))
            result_gpr[5] &= ~(1 << 6);

        if (!(feature16 <= 7378))
            result_gpr[0] &= ~(1 << 30);

        if (!(feature16 <= 7378))
            result_gpr[0] &= ~(1 << 31);

        if (!(feature16 <= 7378))
            result_gpr[0] &= ~(1 << 5);

        if (!(feature16 <= 7378))
            result_gpr[0] &= ~(1 << 6);

        if (!(feature16 <= 7378))
            result_gpr[0] &= ~(1 << 7);

        if (!(feature16 <= 7378))
            result_gpr[0] &= ~(1 << 8);

        if (!(feature16 <= 7378))
            result_gpr[0] &= ~(1 << 9);

        if (!(feature16 <= 7378))
            result_gpr[0] &= ~(1 << 4);

        if (!(feature16 <= 7378))
            result_gpr[0] &= ~(1 << 2);

        if (!(feature16 <= 7378))
            result_gpr[0] &= ~(1 << 3);

        if (!(feature16 <= 7378))
            result_gpr[0] &= ~(1 << 1);

        if (!(feature16 <= 7378))
            result_gpr[5] &= ~(1 << 5);

        if (!(feature16 <= 7378))
            result_gpr[6] &= ~(1 << 3);

        if (!(feature16 <= 7378))
            result_gpr[3] &= ~(1 << 23);

        if (!(feature16 <= 7378))
            result_gpr[3] &= ~(1 << 24);

        if (!(feature16 <= 7378))
            result_gpr[6] &= ~(1 << 6);

        if (!(feature16 <= 7378))
            result_gpr[2] &= ~(1 << 3);

        if (!(feature16 <= 7378))
            result_gpr[2] &= ~(1 << 4);

        if (!(feature16 > 7378))
            result_gpr[7] &= ~(1 << 6);

        if (!(feature16 > 7378))
            result_gpr[3] &= ~(1 << 9);

        if (!(feature16 > 7378))
            result_gpr[3] &= ~(1 << 10);

        if (!(feature16 > 7378))
            result_gpr[3] &= ~(1 << 11);

        if (!(feature16 > 7378))
            result_gpr[2] &= ~(1 << 18);

        if (!(feature16 > 7378))
            result_gpr[2] &= ~(1 << 19);

        if (!(feature16 > 7378))
            result_gpr[4] &= ~(1 << 19);

        if (!(feature16 > 7378))
            result_gpr[4] &= ~(1 << 21);

        if (!(feature16 > 7378))
            result_gpr[0] &= ~(1 << 24);

        if (!(feature16 > 7378))
            result_gpr[0] &= ~(1 << 25);

        if (!(feature16 > 7378))
            result_gpr[0] &= ~(1 << 26);

        if (!(feature16 > 7378))
            result_gpr[2] &= ~(1 << 5);

        if (!(feature16 > 7378))
            result_gpr[2] &= ~(1 << 6);

        if (!(feature16 > 7378))
            result_gpr[4] &= ~(1 << 20);

        if (!(feature16 > 7378))
            result_gpr[6] &= ~(1 << 23);

        if (!(feature16 > 7378))
            result_gpr[6] &= ~(1 << 24);

        if (!(feature16 > 7378))
            result_gpr[6] &= ~(1 << 16);

        if (!(feature16 > 7378))
            result_gpr[6] &= ~(1 << 17);

        if (!(feature16 > 7378 && feature16 <= 7477))
            result_gpr[7] &= ~(1 << 23);

        if (!(feature16 > 7378 && feature16 <= 7477))
            result_gpr[6] &= ~(1 << 25);

        if (!(feature16 > 7378 && feature16 <= 7477))
            result_gpr[6] &= ~(1 << 26);

        if (!(feature16 > 7378 && feature16 <= 7477))
            result_gpr[3] &= ~(1 << 7);

        if (!(feature16 > 7378 && feature16 <= 7477))
            result_gpr[3] &= ~(1 << 8);

        if (!(feature16 > 7378 && feature16 <= 7477))
            result_gpr[1] &= ~(1 << 22);

        if (!(feature16 > 7378 && feature16 <= 7477))
            result_gpr[1] &= ~(1 << 23);

        if (!(feature16 > 7378 && feature16 <= 7477))
            result_gpr[1] &= ~(1 << 24);

        if (!(feature16 > 7378 && feature16 <= 7477))
            result_gpr[3] &= ~(1 << 6);

        if (!(feature16 > 7378 && feature16 <= 7477))
            result_gpr[3] &= ~(1 << 5);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[6] &= ~(1 << 14);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[6] &= ~(1 << 15);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[6] &= ~(1 << 4);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[6] &= ~(1 << 5);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[3] &= ~(1 << 25);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[3] &= ~(1 << 26);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[1] &= ~(1 << 0);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[2] &= ~(1 << 24);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[2] &= ~(1 << 25);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[5] &= ~(1 << 31);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[5] &= ~(1 << 9);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[6] &= ~(1 << 10);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[5] &= ~(1 << 23);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[5] &= ~(1 << 24);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[3] &= ~(1 << 0);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[3] &= ~(1 << 1);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[7] &= ~(1 << 13);

        if (!(feature16 > 7378 && feature16 > 7477))
            result_gpr[7] &= ~(1 << 14);

        if (!(feature16 > 7378))
            result_gpr[3] &= ~(1 << 16);

        if (!(feature16 > 7378))
            result_gpr[3] &= ~(1 << 17);

        if (!(feature16 > 7378))
            result_gpr[6] &= ~(1 << 21);

        if (!(feature16 > 7378))
            result_gpr[6] &= ~(1 << 22);

        if (!(feature16 > 7378))
            result_gpr[6] &= ~(1 << 2);

        if (!(feature16 > 7378))
            result_gpr[6] &= ~(1 << 19);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature16 > 7378))
            result_gpr[0] &= ~(1 << 0);

        if (!(feature16 > 7378))
            result_gpr[4] &= ~(1 << 26);

        if (!(feature16 > 7378))
            result_gpr[4] &= ~(1 << 0);

        if (!(feature16 > 7378))
            result_gpr[4] &= ~(1 << 1);

        if (!(feature16 > 7378))
            result_gpr[2] &= ~(1 << 16);

        if (!(feature16 > 7378))
            result_gpr[2] &= ~(1 << 17);

        if (!(feature16 > 7378))
            result_gpr[6] &= ~(1 << 11);

        if (!(feature16 > 7378))
            result_gpr[6] &= ~(1 << 30);

        if (!(feature16 > 7378))
            result_gpr[2] &= ~(1 << 7);

        if (!(feature16 > 7378))
            result_gpr[2] &= ~(1 << 8);

        if (!(feature16 > 7378))
            result_gpr[3] &= ~(1 << 21);

        if (!(feature16 > 7378))
            result_gpr[3] &= ~(1 << 22);

        if (!(feature16 > 7378))
            result_gpr[7] &= ~(1 << 17);

        if (!(feature16 > 7378))
            result_gpr[7] &= ~(1 << 4);

        if (!(feature16 > 7378))
            result_gpr[5] &= ~(1 << 30);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 15);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 16);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 14);

        if (!(feature16 > 7378))
            result_gpr[4] &= ~(1 << 18);

        if (!(feature16 > 7378))
            result_gpr[2] &= ~(1 << 12);

        if (!(feature16 > 7378))
            result_gpr[2] &= ~(1 << 13);

        if (!(feature16 > 7378))
            result_gpr[0] &= ~(1 << 28);

        if (!(feature16 > 7378))
            result_gpr[0] &= ~(1 << 29);

        if (!(feature16 > 7378))
            result_gpr[0] &= ~(1 << 27);

        if (!(feature16 > 7378))
            result_gpr[6] &= ~(1 << 9);

        if (!(feature16 > 7378))
            result_gpr[7] &= ~(1 << 7);

        if (!(feature16 > 7378))
            result_gpr[3] &= ~(1 << 29);

        if (!(feature16 > 7378))
            result_gpr[3] &= ~(1 << 30);

        if (!(feature16 > 7378))
            result_gpr[6] &= ~(1 << 20);

        if (!(feature16 > 7378))
            result_gpr[7] &= ~(1 << 21);

        if (!(feature16 > 7378))
            result_gpr[7] &= ~(1 << 8);

        if (!(feature16 > 7378))
            result_gpr[7] &= ~(1 << 24);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 10);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 11);

        if (!(feature16 > 7378))
            result_gpr[4] &= ~(1 << 8);

        if (!(feature16 > 7378))
            result_gpr[7] &= ~(1 << 30);

        if (!(feature16 > 7378))
            result_gpr[6] &= ~(1 << 27);

        if (!(feature16 > 7378))
            result_gpr[6] &= ~(1 << 28);

        if (!(feature16 > 7378))
            result_gpr[7] &= ~(1 << 20);

        if (!(feature16 > 7378))
            result_gpr[5] &= ~(1 << 16);

        if (!(feature16 > 7378))
            result_gpr[5] &= ~(1 << 17);

        if (!(feature16 > 7378))
            result_gpr[3] &= ~(1 << 2);

        if (!(feature16 > 7378))
            result_gpr[3] &= ~(1 << 3);

        if (!(feature16 > 7378))
            result_gpr[3] &= ~(1 << 4);

        if (!(feature16 > 7378))
            result_gpr[5] &= ~(1 << 19);

        if (!(feature16 > 7378))
            result_gpr[5] &= ~(1 << 20);

        if (!(feature16 > 7378))
            result_gpr[5] &= ~(1 << 21);

        if (!(feature16 > 7378))
            result_gpr[3] &= ~(1 << 27);

        if (!(feature16 > 7378))
            result_gpr[3] &= ~(1 << 28);

        if (!(feature16 > 7378))
            result_gpr[6] &= ~(1 << 13);

        if (!(feature16 > 7378))
            result_gpr[3] &= ~(1 << 12);

        if (!(feature16 > 7378))
            result_gpr[3] &= ~(1 << 13);

        if (!(feature16 > 7378))
            result_gpr[4] &= ~(1 << 10);

        if (!(feature16 > 7378))
            result_gpr[4] &= ~(1 << 11);

        if (!(feature16 > 7378))
            result_gpr[2] &= ~(1 << 14);

        if (!(feature16 > 7378))
            result_gpr[2] &= ~(1 << 15);

        if (!(feature16 > 7378))
            result_gpr[6] &= ~(1 << 31);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 3);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 8);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 9);

        if (!(feature16 > 7378))
            result_gpr[5] &= ~(1 << 18);

        if (!(feature16 > 7378))
            result_gpr[7] &= ~(1 << 29);

        if (!(feature16 > 7378))
            result_gpr[6] &= ~(1 << 12);

        if (!(feature16 > 7378))
            result_gpr[5] &= ~(1 << 8);

        if (!(feature16 > 7378))
            result_gpr[2] &= ~(1 << 26);

        if (!(feature16 > 7378))
            result_gpr[2] &= ~(1 << 27);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 1);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 2);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 20);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature16 > 7378))
            result_gpr[0] &= ~(1 << 10);

        if (!(feature16 > 7378))
            result_gpr[0] &= ~(1 << 11);

        if (!(feature16 > 7378))
            result_gpr[0] &= ~(1 << 12);

        if (!(feature16 > 7378))
            result_gpr[7] &= ~(1 << 31);

        if (!(feature16 > 7378))
            result_gpr[6] &= ~(1 << 0);

        if (!(feature16 > 7378))
            result_gpr[4] &= ~(1 << 14);

        if (!(feature16 > 7378))
            result_gpr[4] &= ~(1 << 15);

        if (!(feature16 > 7378))
            result_gpr[7] &= ~(1 << 3);

        if (!(feature16 > 7378))
            result_gpr[5] &= ~(1 << 27);

        if (!(feature16 > 7378))
            result_gpr[2] &= ~(1 << 11);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 6);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 7);

        if (!(feature16 > 7378))
            result_gpr[5] &= ~(1 << 0);

        if (!(feature16 > 7378))
            result_gpr[0] &= ~(1 << 19);

        if (!(feature16 > 7378))
            result_gpr[0] &= ~(1 << 20);

        if (!(feature16 > 7378))
            result_gpr[0] &= ~(1 << 18);

        if (!(feature16 > 7378))
            result_gpr[3] &= ~(1 << 19);

        if (!(feature16 > 7378))
            result_gpr[3] &= ~(1 << 20);

        if (!(feature16 > 7378))
            result_gpr[7] &= ~(1 << 12);

        if (!(feature16 > 7378))
            result_gpr[7] &= ~(1 << 2);

        if (!(feature16 > 7378))
            result_gpr[7] &= ~(1 << 19);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 12);

        if (!(feature16 > 7378))
            result_gpr[1] &= ~(1 << 13);

        if (!(feature16 > 7378))
            result_gpr[4] &= ~(1 << 2);


        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 10, 0, __xfer_reg_number(result_xfer6, __nfp_meid(35, 10)) + (__ctx() * 32), sizeof(result_xfer6), &local_signal);
    }

    return 0;
}


