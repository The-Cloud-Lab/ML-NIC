#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal5;
__visible __xread uint32_t remote_xfer5;

__remote SIGNAL result_signal5;
__remote __xread uint32_t result_xfer5[4];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[4];
    __xwrite uint32_t result_write[4];
    
    __assign_relative_register(&remote_signal5, 1);
    __assign_relative_register(&local_signal, 6);
    __implicit_write(&remote_signal5, sizeof(remote_signal5));
    __implicit_write(&remote_xfer5, sizeof(remote_xfer5));
    
    for (;;) {
        reg_set(result_gpr, 0x3ffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        
        __wait_for_all(&remote_signal5);
        reg_cp(&feature, &remote_xfer5, sizeof(feature));
        feature >>= 16;  
        
        // Decision Tree Logic
        if (!(feature <= 4096))
            result_gpr[3] &= ~(1 << 0);

        if (!(feature > 4096))
            result_gpr[3] &= ~(1 << 1);

        if (!(feature <= 4096))
            result_gpr[3] &= ~(1 << 23);

        if (!(feature <= 4096))
            result_gpr[3] &= ~(1 << 24);

        if (!(feature <= 4096))
            result_gpr[3] &= ~(1 << 25);

        if (!(feature <= 4096))
            result_gpr[3] &= ~(1 << 26);

        if (!(feature <= 4096))
            result_gpr[3] &= ~(1 << 27);

        if (!(feature <= 4096))
            result_gpr[3] &= ~(1 << 28);

        if (!(feature > 4096))
            result_gpr[3] &= ~(1 << 29);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 3);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 4);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 5);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 6);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 7);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 8);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 9);

        if (!(feature > 4096))
            result_gpr[2] &= ~(1 << 10);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 16);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 17);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 18);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 19);

        if (!(feature > 4096))
            result_gpr[2] &= ~(1 << 20);
        
            
        reg_cp(&result_write, &result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(&result_write, 32, 9, 0, 
                                          __xfer_reg_number(&result_xfer5, __nfp_meid(32, 9)) + (__ctx() * 32), 
                                          sizeof(result_xfer5), &local_signal);    
    }
    
    return 0;
}
