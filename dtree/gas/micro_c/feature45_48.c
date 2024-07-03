#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal16;
__visible __xread uint32_t remote_xfer16[2];

__remote SIGNAL result_signal16;
__remote __xread uint32_t result_xfer16[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature45;
    __gpr uint32_t feature46;
    __gpr uint32_t feature48;    
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal16, 1);
    __assign_relative_register(&local_signal, 5);
    __implicit_write(&remote_signal16, sizeof(remote_signal16));
    __implicit_write(&remote_xfer16, sizeof(remote_xfer16));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal16);
        reg_cp(&feature45, remote_xfer16, sizeof(feature45));
        reg_cp(&feature46, remote_xfer16, sizeof(feature46));
        reg_cp(&feature48, remote_xfer16+1, sizeof(feature48));
        
        feature45 >>= 16;
        // Decision Tree Logic
        if (!(feature45 <= 132))
            result_gpr[0] &= ~(1 << 2);

        if (!(feature45 <= 132))
            result_gpr[0] &= ~(1 << 3);

        if (!(feature45 > 132))
            result_gpr[0] &= ~(1 << 1);

        
        feature46 &= 0xffff;
        // Decision Tree Logic
        if (!(feature46 <= 6499))
            result_gpr[2] &= ~(1 << 14);

        if (!(feature46 > 6499))
            result_gpr[2] &= ~(1 << 15);

        if (!(feature46 <= 5009))
            result_gpr[7] &= ~(1 << 31);

        if (!(feature46 <= 5009))
            result_gpr[6] &= ~(1 << 0);

        if (!(feature46 > 5009))
            result_gpr[4] &= ~(1 << 14);

        if (!(feature46 > 5009))
            result_gpr[4] &= ~(1 << 15);
        
        
        feature48 &= 0xffff;
        // Decision Tree Logic
        if (!(feature48 <= 8072))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature48 > 8072))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature48 <= 8030))
            result_gpr[7] &= ~(1 << 29);

        if (!(feature48 > 8030))
            result_gpr[6] &= ~(1 << 12);

        if (!(feature48 > 8030))
            result_gpr[5] &= ~(1 << 8);

        if (!(feature48 > 8030))
            result_gpr[2] &= ~(1 << 26);

        if (!(feature48 > 8030))
            result_gpr[2] &= ~(1 << 27);

        if (!(feature48 > 8030))
            result_gpr[1] &= ~(1 << 1);

        if (!(feature48 > 8030))
            result_gpr[1] &= ~(1 << 2);

        if (!(feature48 > 8030))
            result_gpr[1] &= ~(1 << 20);

        if (!(feature48 > 8030))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature48 > 8030))
            result_gpr[0] &= ~(1 << 10);

        if (!(feature48 > 8030))
            result_gpr[0] &= ~(1 << 11);

        if (!(feature48 > 8030))
            result_gpr[0] &= ~(1 << 12);
            
        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 0, 0, __xfer_reg_number(result_xfer16, __nfp_meid(36, 0)) + (__ctx() * 32), sizeof(result_xfer16), &local_signal);
    }

    return 0;
}


