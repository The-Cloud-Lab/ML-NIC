#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal4;
__visible __xread uint32_t remote_xfer4;

__remote SIGNAL result_signal4;
__remote __xread uint32_t result_xfer4[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature11;
    __gpr uint32_t feature12;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal4, 1);
    __assign_relative_register(&local_signal, 5);
    __implicit_write(&remote_signal4, sizeof(remote_signal4));
    __implicit_write(&remote_xfer4, sizeof(remote_xfer4));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal4);
        reg_cp(&feature11, &remote_xfer4, sizeof(feature11));
        reg_cp(&feature12, &remote_xfer4, sizeof(feature12));
        
        feature11 >>= 16;
        // Decision Tree Logic
        if (!(feature11 <= 103))
            result_gpr[3] &= ~(1 << 21);

        if (!(feature11 > 103))
            result_gpr[3] &= ~(1 << 22);

        
        feature12 &= 0xffff;
        // Decision Tree Logic
        if (!(feature12 <= 3513))
            result_gpr[6] &= ~(1 << 6);

        if (!(feature12 > 3513))
            result_gpr[2] &= ~(1 << 3);

        if (!(feature12 > 3513))
            result_gpr[2] &= ~(1 << 4);

        if (!(feature12 <= 757 && feature12 <= 443))
            result_gpr[3] &= ~(1 << 21);

        if (!(feature12 <= 757 && feature12 <= 443))
            result_gpr[3] &= ~(1 << 22);

        if (!(feature12 <= 757 && feature12 <= 443))
            result_gpr[7] &= ~(1 << 17);

        if (!(feature12 <= 757 && feature12 <= 443))
            result_gpr[7] &= ~(1 << 4);

        if (!(feature12 <= 757 && feature12 <= 443))
            result_gpr[5] &= ~(1 << 30);

        if (!(feature12 <= 757 && feature12 <= 443))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature12 <= 757 && feature12 <= 443))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature12 <= 757 && feature12 <= 443))
            result_gpr[1] &= ~(1 << 15);

        if (!(feature12 <= 757 && feature12 <= 443))
            result_gpr[1] &= ~(1 << 16);

        if (!(feature12 <= 757 && feature12 <= 443))
            result_gpr[1] &= ~(1 << 14);

        if (!(feature12 <= 757 && feature12 <= 443))
            result_gpr[4] &= ~(1 << 18);

        if (!(feature12 <= 757 && feature12 <= 443))
            result_gpr[2] &= ~(1 << 12);

        if (!(feature12 <= 757 && feature12 <= 443))
            result_gpr[2] &= ~(1 << 13);

        if (!(feature12 <= 757 && feature12 > 443 && feature12 <= 452))
            result_gpr[0] &= ~(1 << 28);

        if (!(feature12 <= 757 && feature12 > 443 && feature12 <= 452))
            result_gpr[0] &= ~(1 << 29);

        if (!(feature12 <= 757 && feature12 > 443 && feature12 > 452))
            result_gpr[0] &= ~(1 << 27);

        if (!(feature12 <= 757 && feature12 > 443))
            result_gpr[6] &= ~(1 << 9);

        if (!(feature12 <= 757 && feature12 > 443))
            result_gpr[7] &= ~(1 << 7);

        if (!(feature12 <= 757 && feature12 > 443))
            result_gpr[3] &= ~(1 << 29);

        if (!(feature12 <= 757 && feature12 > 443))
            result_gpr[3] &= ~(1 << 30);

        if (!(feature12 <= 757 && feature12 > 443))
            result_gpr[6] &= ~(1 << 20);

        if (!(feature12 <= 757 && feature12 > 443))
            result_gpr[7] &= ~(1 << 21);

        if (!(feature12 <= 757))
            result_gpr[7] &= ~(1 << 8);

        if (!(feature12 <= 757))
            result_gpr[7] &= ~(1 << 24);

        if (!(feature12 <= 757))
            result_gpr[1] &= ~(1 << 10);

        if (!(feature12 <= 757))
            result_gpr[1] &= ~(1 << 11);

        if (!(feature12 <= 757))
            result_gpr[4] &= ~(1 << 8);

        if (!(feature12 <= 757))
            result_gpr[7] &= ~(1 << 30);

        if (!(feature12 <= 757))
            result_gpr[6] &= ~(1 << 27);

        if (!(feature12 <= 757))
            result_gpr[6] &= ~(1 << 28);

        if (!(feature12 > 757))
            result_gpr[7] &= ~(1 << 20);

        if (!(feature12 > 757))
            result_gpr[5] &= ~(1 << 16);

        if (!(feature12 > 757))
            result_gpr[5] &= ~(1 << 17);

        if (!(feature12 > 757))
            result_gpr[3] &= ~(1 << 2);

        if (!(feature12 > 757))
            result_gpr[3] &= ~(1 << 3);

        if (!(feature12 > 757))
            result_gpr[3] &= ~(1 << 4);

        if (!(feature12 > 757))
            result_gpr[5] &= ~(1 << 19);

        if (!(feature12 > 757))
            result_gpr[5] &= ~(1 << 20);

        if (!(feature12 > 757))
            result_gpr[5] &= ~(1 << 21);

        if (!(feature12 > 757))
            result_gpr[3] &= ~(1 << 27);

        if (!(feature12 > 757))
            result_gpr[3] &= ~(1 << 28);

        if (!(feature12 > 757))
            result_gpr[6] &= ~(1 << 13);

        if (!(feature12 > 757 && feature12 <= 831))
            result_gpr[3] &= ~(1 << 12);

        if (!(feature12 > 757 && feature12 > 831))
            result_gpr[3] &= ~(1 << 13);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 9, 0, __xfer_reg_number(result_xfer4, __nfp_meid(35, 9)) + (__ctx() * 32), sizeof(result_xfer4), &local_signal);
    }

    return 0;
}


