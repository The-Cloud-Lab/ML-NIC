#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal44;
__visible __xread uint32_t remote_xfer44[3];

__remote SIGNAL result_signal44;
__remote __xread uint32_t result_xfer44[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature124;
    __gpr uint32_t feature125;
    __gpr uint32_t feature126;
    __gpr uint32_t feature128;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal44, 1);
    __assign_relative_register(&local_signal, 5);
    __implicit_write(&remote_signal44, sizeof(remote_signal44));
    __implicit_write(&remote_xfer44, sizeof(remote_xfer44));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal44);
        reg_cp(&feature124, remote_xfer44, sizeof(feature124));
        reg_cp(&feature125, remote_xfer44+1, sizeof(feature125));
        reg_cp(&feature126, remote_xfer44+1, sizeof(feature126));
        reg_cp(&feature128, remote_xfer44+2, sizeof(feature128));

        feature124 &= 0xffff;
        // Decision Tree Logic
        if (!(feature124 <= 34))
            result_gpr[4] &= ~(1 << 6);

        if (!(feature124 > 34))
            result_gpr[4] &= ~(1 << 7);

        if (!(feature124 <= 172))
            result_gpr[3] &= ~(1 << 16);

        if (!(feature124 <= 172))
            result_gpr[3] &= ~(1 << 17);

        if (!(feature124 <= 172))
            result_gpr[6] &= ~(1 << 21);

        if (!(feature124 <= 172))
            result_gpr[6] &= ~(1 << 22);

        if (!(feature124 > 172))
            result_gpr[6] &= ~(1 << 2);

        if (!(feature124 > 172))
            result_gpr[6] &= ~(1 << 19);

        if (!(feature124 > 172))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature124 > 172))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature124 > 172))
            result_gpr[0] &= ~(1 << 0);

        if (!(feature124 > 172))
            result_gpr[4] &= ~(1 << 26);

        if (!(feature124 > 172))
            result_gpr[4] &= ~(1 << 0);

        if (!(feature124 > 172))
            result_gpr[4] &= ~(1 << 1);

        if (!(feature124 > 172))
            result_gpr[2] &= ~(1 << 16);

        if (!(feature124 > 172))
            result_gpr[2] &= ~(1 << 17);

        if (!(feature124 > 172))
            result_gpr[6] &= ~(1 << 11);

        if (!(feature124 > 172))
            result_gpr[6] &= ~(1 << 30);

        if (!(feature124 > 172))
            result_gpr[2] &= ~(1 << 7);

        if (!(feature124 > 172))
            result_gpr[2] &= ~(1 << 8);

        if (!(feature124 <= 285))
            result_gpr[1] &= ~(1 << 3);

        if (!(feature124 <= 285))
            result_gpr[1] &= ~(1 << 8);

        if (!(feature124 <= 285))
            result_gpr[1] &= ~(1 << 9);

        if (!(feature124 <= 285))
            result_gpr[5] &= ~(1 << 18);

        if (!(feature124 > 285))
            result_gpr[7] &= ~(1 << 29);

        if (!(feature124 > 285))
            result_gpr[6] &= ~(1 << 12);

        if (!(feature124 > 285))
            result_gpr[5] &= ~(1 << 8);

        if (!(feature124 > 285))
            result_gpr[2] &= ~(1 << 26);

        if (!(feature124 > 285))
            result_gpr[2] &= ~(1 << 27);

        if (!(feature124 > 285))
            result_gpr[1] &= ~(1 << 1);

        if (!(feature124 > 285))
            result_gpr[1] &= ~(1 << 2);

        if (!(feature124 > 285))
            result_gpr[1] &= ~(1 << 20);

        if (!(feature124 > 285))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature124 > 285))
            result_gpr[0] &= ~(1 << 10);

        if (!(feature124 > 285))
            result_gpr[0] &= ~(1 << 11);

        if (!(feature124 > 285))
            result_gpr[0] &= ~(1 << 12);

        
        
        feature125 >>= 16;
        // Decision Tree Logic
        if (!(feature125 <= 625))
            result_gpr[6] &= ~(1 << 12);

        if (!(feature125 > 625))
            result_gpr[5] &= ~(1 << 8);

        if (!(feature125 > 625))
            result_gpr[2] &= ~(1 << 26);

        if (!(feature125 > 625))
            result_gpr[2] &= ~(1 << 27);

        if (!(feature125 > 625))
            result_gpr[1] &= ~(1 << 1);

        if (!(feature125 > 625))
            result_gpr[1] &= ~(1 << 2);

        if (!(feature125 > 625))
            result_gpr[1] &= ~(1 << 20);

        if (!(feature125 > 625))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature125 > 625))
            result_gpr[0] &= ~(1 << 10);

        if (!(feature125 > 625 && feature125 <= 978))
            result_gpr[0] &= ~(1 << 11);

        if (!(feature125 > 625 && feature125 > 978))
            result_gpr[0] &= ~(1 << 12);

        if (!(feature125 <= 1030))
            result_gpr[0] &= ~(1 << 19);

        if (!(feature125 <= 1030))
            result_gpr[0] &= ~(1 << 20);

        if (!(feature125 > 1030))
            result_gpr[0] &= ~(1 << 18);
        
        
        feature126 &= 0xffff;
        // Decision Tree Logic
        if (!(feature126 <= 7848))
            result_gpr[6] &= ~(1 << 4);

        if (!(feature126 > 7848))
            result_gpr[6] &= ~(1 << 5);
        
        
        feature128 &= 0xffff;
        // Decision Tree Logic
        if (!(feature128 <= 7906))
            result_gpr[2] &= ~(1 << 18);

        if (!(feature128 > 7906))
            result_gpr[2] &= ~(1 << 19);


        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 7, 0, __xfer_reg_number(result_xfer44, __nfp_meid(36, 7)) + (__ctx() * 32), sizeof(result_xfer44), &local_signal);
    }

    return 0;
}


