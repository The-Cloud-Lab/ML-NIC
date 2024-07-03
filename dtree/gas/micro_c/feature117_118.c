#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal42;
__visible __xread uint32_t remote_xfer42;

__remote SIGNAL result_signal42;
__remote __xread uint32_t result_xfer42[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature117;
    __gpr uint32_t feature118;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal42, 1);
    __assign_relative_register(&local_signal, 3);
    __implicit_write(&remote_signal42, sizeof(remote_signal42));
    __implicit_write(&remote_xfer42, sizeof(remote_xfer42));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal42);
        reg_cp(&feature117, &remote_xfer42, sizeof(feature117));
        reg_cp(&feature118, &remote_xfer42, sizeof(feature118));        
        
        feature117 >>= 16;
        // Decision Tree Logic
        if (!(feature117 <= 181))
            result_gpr[6] &= ~(1 << 21);

        if (!(feature117 > 181))
            result_gpr[6] &= ~(1 << 22);

        if (!(feature117 <= 702))
            result_gpr[1] &= ~(1 << 10);

        if (!(feature117 > 702))
            result_gpr[1] &= ~(1 << 11);

        if (!(feature117 <= 597))
            result_gpr[5] &= ~(1 << 27);

        if (!(feature117 <= 597))
            result_gpr[2] &= ~(1 << 11);

        if (!(feature117 <= 597))
            result_gpr[1] &= ~(1 << 6);

        if (!(feature117 <= 597))
            result_gpr[1] &= ~(1 << 7);

        if (!(feature117 <= 597))
            result_gpr[5] &= ~(1 << 0);

        if (!(feature117 > 597))
            result_gpr[0] &= ~(1 << 19);

        if (!(feature117 > 597))
            result_gpr[0] &= ~(1 << 20);

        if (!(feature117 > 597))
            result_gpr[0] &= ~(1 << 18);

        
        feature118 &= 0xffff;
        // Decision Tree Logic
        if (!(feature118 <= 7909))
            result_gpr[3] &= ~(1 << 27);

        if (!(feature118 <= 7909))
            result_gpr[3] &= ~(1 << 28);

        if (!(feature118 <= 7909))
            result_gpr[6] &= ~(1 << 13);

        if (!(feature118 > 7909))
            result_gpr[3] &= ~(1 << 12);

        if (!(feature118 > 7909))
            result_gpr[3] &= ~(1 << 13);

        if (!(feature118 <= 7199))
            result_gpr[1] &= ~(1 << 1);

        if (!(feature118 > 7199))
            result_gpr[1] &= ~(1 << 2);


        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 7, 0, __xfer_reg_number(result_xfer42, __nfp_meid(36, 7)) + (__ctx() * 32), sizeof(result_xfer42), &local_signal);
    }

    return 0;
}


