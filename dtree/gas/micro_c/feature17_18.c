#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal7;
__visible __xread uint32_t remote_xfer7;

__remote SIGNAL result_signal7;
__remote __xread uint32_t result_xfer7[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature17;
    __gpr uint32_t feature18;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal7, 1);
    __assign_relative_register(&local_signal, 4);
    __implicit_write(&remote_signal7, sizeof(remote_signal7));
    __implicit_write(&remote_xfer7, sizeof(remote_xfer7));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal7);
        reg_cp(&feature17, &remote_xfer7, sizeof(feature17));
        reg_cp(&feature18, &remote_xfer7, sizeof(feature18));
        
        feature17 >>= 16;
        // Decision Tree Logic
        if (!(feature17 <= 2653))
            result_gpr[2] &= ~(1 << 9);

        if (!(feature17 <= 2653))
            result_gpr[2] &= ~(1 << 10);

        if (!(feature17 <= 2653 && feature17 <= 2484))
            result_gpr[5] &= ~(1 << 11);

        if (!(feature17 <= 2653 && feature17 > 2484))
            result_gpr[5] &= ~(1 << 12);

        if (!(feature17 > 2653))
            result_gpr[7] &= ~(1 << 11);

        if (!(feature17 <= 2179))
            result_gpr[7] &= ~(1 << 6);

        if (!(feature17 <= 2179))
            result_gpr[3] &= ~(1 << 9);

        if (!(feature17 <= 2179))
            result_gpr[3] &= ~(1 << 10);

        if (!(feature17 <= 2179))
            result_gpr[3] &= ~(1 << 11);

        if (!(feature17 > 2179))
            result_gpr[2] &= ~(1 << 18);

        if (!(feature17 > 2179))
            result_gpr[2] &= ~(1 << 19);

        if (!(feature17 > 2179))
            result_gpr[4] &= ~(1 << 19);

        if (!(feature17 > 2179))
            result_gpr[4] &= ~(1 << 21);

        if (!(feature17 > 2179))
            result_gpr[0] &= ~(1 << 24);

        if (!(feature17 > 2179))
            result_gpr[0] &= ~(1 << 25);

        if (!(feature17 > 2179))
            result_gpr[0] &= ~(1 << 26);

        if (!(feature17 > 2179))
            result_gpr[2] &= ~(1 << 5);

        if (!(feature17 > 2179))
            result_gpr[2] &= ~(1 << 6);

        if (!(feature17 > 2179))
            result_gpr[4] &= ~(1 << 20);

        if (!(feature17 > 2179))
            result_gpr[6] &= ~(1 << 23);

        if (!(feature17 > 2179))
            result_gpr[6] &= ~(1 << 24);

        if (!(feature17 > 2179))
            result_gpr[6] &= ~(1 << 16);

        if (!(feature17 > 2179))
            result_gpr[6] &= ~(1 << 17);

        
        
        feature18 &= 0xffff;
        // Decision Tree Logic
        if (!(feature18 <= 147))
            result_gpr[4] &= ~(1 << 29);

        if (!(feature18 <= 147))
            result_gpr[4] &= ~(1 << 30);

        if (!(feature18 > 147))
            result_gpr[4] &= ~(1 << 5);

        if (!(feature18 > 147))
            result_gpr[2] &= ~(1 << 22);

        if (!(feature18 > 147))
            result_gpr[2] &= ~(1 << 23);

        if (!(feature18 > 147))
            result_gpr[6] &= ~(1 << 18);

        if (!(feature18 <= 992))
            result_gpr[3] &= ~(1 << 18);

        if (!(feature18 <= 992))
            result_gpr[2] &= ~(1 << 20);

        if (!(feature18 <= 992))
            result_gpr[2] &= ~(1 << 21);

        if (!(feature18 > 992))
            result_gpr[4] &= ~(1 << 31);

        if (!(feature18 <= 1799))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature18 <= 1799))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature18 <= 1799))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature18 <= 1799))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature18 <= 1799))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature18 > 1799))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature18 > 1799))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature18 <= 680))
            result_gpr[3] &= ~(1 << 3);

        if (!(feature18 > 680))
            result_gpr[3] &= ~(1 << 4);
   

        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 10, 0, __xfer_reg_number(result_xfer7, __nfp_meid(35, 10)) + (__ctx() * 32), sizeof(result_xfer7), &local_signal);
    }

    return 0;
}


