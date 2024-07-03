#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal43;
__visible __xread uint32_t remote_xfer43[2];

__remote SIGNAL result_signal43;
__remote __xread uint32_t result_xfer43[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature119;
    __gpr uint32_t feature120;
    __gpr uint32_t feature121;
    __gpr uint32_t feature122;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal43, 1);
    __assign_relative_register(&local_signal, 4);
    __implicit_write(&remote_signal43, sizeof(remote_signal43));
    __implicit_write(&remote_xfer43, sizeof(remote_xfer43));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal43);
        reg_cp(&feature119, remote_xfer43, sizeof(feature119));
        reg_cp(&feature120, remote_xfer43, sizeof(feature120));
        reg_cp(&feature121, remote_xfer43+1, sizeof(feature121));
        reg_cp(&feature122, remote_xfer43+1, sizeof(feature122));        
        
        feature119 >>= 16;
        // Decision Tree Logic
        if (!(feature119 <= 5816))
            result_gpr[2] &= ~(1 << 7);

        if (!(feature119 > 5816))
            result_gpr[2] &= ~(1 << 8);
        
        
        feature120 &= 0xffff;
        // Decision Tree Logic
        if (!(feature120 <= 7872))
            result_gpr[1] &= ~(1 << 10);

        if (!(feature120 <= 7872))
            result_gpr[1] &= ~(1 << 11);

        if (!(feature120 > 7872))
            result_gpr[4] &= ~(1 << 8);
        
        
        feature121 >>= 16;
        // Decision Tree Logic
        if (!(feature121 <= 1501))
            result_gpr[6] &= ~(1 << 1);

        if (!(feature121 > 1501))
            result_gpr[3] &= ~(1 << 14);

        if (!(feature121 > 1501))
            result_gpr[3] &= ~(1 << 15);

        if (!(feature121 <= 3005))
            result_gpr[3] &= ~(1 << 19);

        if (!(feature121 > 3005))
            result_gpr[3] &= ~(1 << 20);
        
        
        feature122 &= 0xffff;
        // Decision Tree Logic
        if (!(feature122 <= 118))
            result_gpr[4] &= ~(1 << 29);

        if (!(feature122 <= 118))
            result_gpr[4] &= ~(1 << 30);

        if (!(feature122 <= 118))
            result_gpr[4] &= ~(1 << 5);

        if (!(feature122 <= 118))
            result_gpr[2] &= ~(1 << 22);

        if (!(feature122 <= 118))
            result_gpr[2] &= ~(1 << 23);

        if (!(feature122 <= 118))
            result_gpr[6] &= ~(1 << 18);

        if (!(feature122 > 118))
            result_gpr[4] &= ~(1 << 16);

        if (!(feature122 > 118))
            result_gpr[4] &= ~(1 << 17);

        if (!(feature122 <= 379))
            result_gpr[2] &= ~(1 << 20);

        if (!(feature122 > 379))
            result_gpr[2] &= ~(1 << 21);

        if (!(feature122 <= 855))
            result_gpr[2] &= ~(1 << 18);

        if (!(feature122 <= 855))
            result_gpr[2] &= ~(1 << 19);

        if (!(feature122 <= 855))
            result_gpr[4] &= ~(1 << 19);

        if (!(feature122 <= 855))
            result_gpr[4] &= ~(1 << 21);

        if (!(feature122 <= 855 && feature122 <= 811))
            result_gpr[0] &= ~(1 << 24);

        if (!(feature122 <= 855 && feature122 > 811))
            result_gpr[0] &= ~(1 << 25);

        if (!(feature122 <= 855 && feature122 > 811))
            result_gpr[0] &= ~(1 << 26);

        if (!(feature122 <= 855))
            result_gpr[2] &= ~(1 << 5);

        if (!(feature122 <= 855))
            result_gpr[2] &= ~(1 << 6);

        if (!(feature122 <= 855))
            result_gpr[4] &= ~(1 << 20);

        if (!(feature122 > 855))
            result_gpr[6] &= ~(1 << 23);

        if (!(feature122 > 855))
            result_gpr[6] &= ~(1 << 24);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 7, 0, __xfer_reg_number(result_xfer43, __nfp_meid(36, 7)) + (__ctx() * 32), sizeof(result_xfer43), &local_signal);
    }

    return 0;
}


