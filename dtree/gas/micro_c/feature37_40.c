#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal14;
__visible __xread uint32_t remote_xfer14[2];

__remote SIGNAL result_signal14;
__remote __xread uint32_t result_xfer14[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature37;
    __gpr uint32_t feature39;
    __gpr uint32_t feature40;    
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal14, 1);
    __assign_relative_register(&local_signal, 3);
    __implicit_write(&remote_signal14, sizeof(remote_signal14));
    __implicit_write(&remote_xfer14, sizeof(remote_xfer14));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal14);
        reg_cp(&feature37, remote_xfer14, sizeof(feature37));
        reg_cp(&feature39, remote_xfer14+1, sizeof(feature39));
        reg_cp(&feature40, remote_xfer14+1, sizeof(feature40));
        
        feature37 >>= 16;
        // Decision Tree Logic
        if (!(feature37 <= 15))
            result_gpr[5] &= ~(1 << 1);

        if (!(feature37 > 15))
            result_gpr[5] &= ~(1 << 2);

        if (!(feature37 <= 75))
            result_gpr[1] &= ~(1 << 20);

        if (!(feature37 <= 75))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature37 > 75))
            result_gpr[0] &= ~(1 << 10);

        if (!(feature37 > 75))
            result_gpr[0] &= ~(1 << 11);

        if (!(feature37 > 75))
            result_gpr[0] &= ~(1 << 12);

        
        feature39 >>= 16;
        // Decision Tree Logic
        if (!(feature39 <= 7735))
            result_gpr[0] &= ~(1 << 7);

        if (!(feature39 > 7735))
            result_gpr[0] &= ~(1 << 8);

        if (!(feature39 > 7735))
            result_gpr[0] &= ~(1 << 9);

        if (!(feature39 <= 7635))
            result_gpr[7] &= ~(1 << 23);

        if (!(feature39 <= 7635))
            result_gpr[6] &= ~(1 << 25);

        if (!(feature39 <= 7635))
            result_gpr[6] &= ~(1 << 26);

        if (!(feature39 > 7635))
            result_gpr[3] &= ~(1 << 7);

        if (!(feature39 > 7635))
            result_gpr[3] &= ~(1 << 8);

        if (!(feature39 > 7635))
            result_gpr[1] &= ~(1 << 22);

        if (!(feature39 > 7635))
            result_gpr[1] &= ~(1 << 23);

        if (!(feature39 > 7635))
            result_gpr[1] &= ~(1 << 24);

        if (!(feature39 > 7635))
            result_gpr[3] &= ~(1 << 6);

        if (!(feature39 > 7635))
            result_gpr[3] &= ~(1 << 5);

        if (!(feature39 <= 7349))
            result_gpr[7] &= ~(1 << 13);

        if (!(feature39 > 7349))
            result_gpr[7] &= ~(1 << 14);
        
        
        feature40 &= 0xffff;
        // Decision Tree Logic
        if (!(feature40 <= 8122))
            result_gpr[4] &= ~(1 << 27);

        if (!(feature40 > 8122))
            result_gpr[4] &= ~(1 << 28);
        
        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 0, 0, __xfer_reg_number(result_xfer14, __nfp_meid(36, 0)) + (__ctx() * 32), sizeof(result_xfer14), &local_signal);
    }

    return 0;
}


