#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal8;
__visible __xread uint32_t remote_xfer8[3];

__remote SIGNAL result_signal8;
__remote __xread uint32_t result_xfer8[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature19;
    __gpr uint32_t feature20;
    __gpr uint32_t feature23;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal8, 1);
    __assign_relative_register(&local_signal, 5);
    __implicit_write(&remote_signal8, sizeof(remote_signal8));
    __implicit_write(&remote_xfer8, sizeof(remote_xfer8));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal8);
        reg_cp(&feature19, remote_xfer8, sizeof(feature19));
        reg_cp(&feature20, remote_xfer8, sizeof(feature20));
        reg_cp(&feature23, remote_xfer8+2, sizeof(feature23));     
        
        feature19 >>= 16;
        // Decision Tree Logic
        if (!(feature19 <= 1042))
            result_gpr[0] &= ~(1 << 10);

        if (!(feature19 > 1042))
            result_gpr[0] &= ~(1 << 11);

        if (!(feature19 > 1042))
            result_gpr[0] &= ~(1 << 12);
        
        
        feature20 &= 0xffff;
        // Decision Tree Logic
        if (!(feature20 <= 38))
            result_gpr[4] &= ~(1 << 6);

        if (!(feature20 <= 38))
            result_gpr[4] &= ~(1 << 7);

        if (!(feature20 > 38))
            result_gpr[6] &= ~(1 << 29);

        if (!(feature20 <= 64))
            result_gpr[3] &= ~(1 << 16);

        if (!(feature20 <= 64))
            result_gpr[3] &= ~(1 << 17);

        if (!(feature20 > 64))
            result_gpr[6] &= ~(1 << 21);

        if (!(feature20 > 64))
            result_gpr[6] &= ~(1 << 22);

        if (!(feature20 <= 202))
            result_gpr[6] &= ~(1 << 2);

        if (!(feature20 <= 202))
            result_gpr[6] &= ~(1 << 19);

        if (!(feature20 <= 202))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature20 <= 202))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature20 <= 202))
            result_gpr[0] &= ~(1 << 0);

        if (!(feature20 <= 202))
            result_gpr[4] &= ~(1 << 26);

        if (!(feature20 <= 202))
            result_gpr[4] &= ~(1 << 0);

        if (!(feature20 <= 202))
            result_gpr[4] &= ~(1 << 1);

        if (!(feature20 <= 202))
            result_gpr[2] &= ~(1 << 16);

        if (!(feature20 <= 202))
            result_gpr[2] &= ~(1 << 17);

        if (!(feature20 > 202))
            result_gpr[6] &= ~(1 << 11);

        if (!(feature20 > 202))
            result_gpr[6] &= ~(1 << 30);

        if (!(feature20 > 202))
            result_gpr[2] &= ~(1 << 7);

        if (!(feature20 > 202))
            result_gpr[2] &= ~(1 << 8);


        feature23 >>= 16;
        // Decision Tree Logic
        if (!(feature23 <= 7757))
            result_gpr[1] &= ~(1 << 17);

        if (!(feature23 > 7757))
            result_gpr[1] &= ~(1 << 18);

        if (!(feature23 > 7757))
            result_gpr[1] &= ~(1 << 19);

        if (!(feature23 <= 7727))
            result_gpr[4] &= ~(1 << 22);

        if (!(feature23 > 7727))
            result_gpr[4] &= ~(1 << 23);

        if (!(feature23 <= 7756))
            result_gpr[0] &= ~(1 << 14);

        if (!(feature23 <= 7756))
            result_gpr[0] &= ~(1 << 15);

        if (!(feature23 <= 7756))
            result_gpr[0] &= ~(1 << 13);

        if (!(feature23 > 7756))
            result_gpr[4] &= ~(1 << 9);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 10, 0, __xfer_reg_number(result_xfer8, __nfp_meid(35, 10)) + (__ctx() * 32), sizeof(result_xfer8), &local_signal);
    }

    return 0;
}


