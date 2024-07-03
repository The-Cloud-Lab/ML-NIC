#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal8;
__visible __xread uint32_t remote_xfer8;

__remote SIGNAL result_signal8;
__remote __xread uint32_t result_xfer8[4];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[4];
    __xwrite uint32_t result_write[4];
    
    __assign_relative_register(&remote_signal8, 1);
    __assign_relative_register(&local_signal, 9);
    __implicit_write(&remote_signal8, sizeof(remote_signal8));
    __implicit_write(&remote_xfer8, sizeof(remote_xfer8));
    
    for (;;) {
        reg_set(result_gpr, 0x3ffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        
        __wait_for_all(&remote_signal8);
        reg_cp(&feature, &remote_xfer8, sizeof(feature));
        feature &= 0xffff;
        
        // Decision Tree Logic
        if (!(feature <= 4096))
            result_gpr[3] &= ~(1 << 3);

        if (!(feature <= 4096))
            result_gpr[3] &= ~(1 << 4);

        if (!(feature <= 4096))
            result_gpr[3] &= ~(1 << 5);

        if (!(feature > 4096))
            result_gpr[3] &= ~(1 << 6);

        if (!(feature > 4096))
            result_gpr[3] &= ~(1 << 7);

        if (!(feature > 4096))
            result_gpr[3] &= ~(1 << 8);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 8);

        if (!(feature > 4096))
            result_gpr[2] &= ~(1 << 9);

        if (!(feature <= 4096))
            result_gpr[0] &= ~(1 << 5);

        if (!(feature > 4096))
            result_gpr[0] &= ~(1 << 6);

        if (!(feature <= 4096))
            result_gpr[0] &= ~(1 << 14);

        if (!(feature > 4096))
            result_gpr[0] &= ~(1 << 15);

        if (!(feature > 4096))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature > 4096))
            result_gpr[0] &= ~(1 << 17);
        
        
        reg_cp(&result_write, &result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(&result_write, 36, 9, 0, 
                                          __xfer_reg_number(&result_xfer8, __nfp_meid(36, 9)) + (__ctx() * 32), 
                                          sizeof(result_xfer8), &local_signal);    
    }
    
    return 0;
}
