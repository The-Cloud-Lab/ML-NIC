#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal11;
__visible __xread uint32_t remote_xfer11;

__remote SIGNAL result_signal11;
__remote __xread uint32_t result_xfer11[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature31;
    __gpr uint32_t feature32;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal11, 1);
    __assign_relative_register(&local_signal, 4);
    __implicit_write(&remote_signal11, sizeof(remote_signal11));
    __implicit_write(&remote_xfer11, sizeof(remote_xfer11));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal11);
        reg_cp(&feature31, &remote_xfer11, sizeof(feature31));
        reg_cp(&feature32, &remote_xfer11, sizeof(feature32));
        
        feature31 >>= 16;
        // Decision Tree Logic
        if (!(feature31 <= 7964))
            result_gpr[1] &= ~(1 << 6);

        if (!(feature31 > 7964))
            result_gpr[1] &= ~(1 << 7);

        
        feature32 &= 0xffff;
        // Decision Tree Logic
        if (!(feature32<= 8140))
            result_gpr[4] &= ~(1 << 29);

        if (!(feature32> 8140))
            result_gpr[4] &= ~(1 << 30);

        if (!(feature32<= 8171))
            result_gpr[0] &= ~(1 << 24);

        if (!(feature32<= 8171))
            result_gpr[0] &= ~(1 << 25);

        if (!(feature32<= 8171))
            result_gpr[0] &= ~(1 << 26);

        if (!(feature32> 8171))
            result_gpr[2] &= ~(1 << 5);

        if (!(feature32> 8171))
            result_gpr[2] &= ~(1 << 6);

        if (!(feature32<= 8136))
            result_gpr[6] &= ~(1 << 30);

        if (!(feature32> 8136))
            result_gpr[2] &= ~(1 << 7);

        if (!(feature32> 8136))
            result_gpr[2] &= ~(1 << 8);
        

        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 11, 0, __xfer_reg_number(result_xfer11, __nfp_meid(35, 11)) + (__ctx() * 32), sizeof(result_xfer11), &local_signal);
    }

    return 0;
}


