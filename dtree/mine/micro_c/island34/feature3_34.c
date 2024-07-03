#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal3;
__visible __xread uint32_t remote_xfer3;

__remote SIGNAL result_signal3;
__remote __xread uint32_t result_xfer3[4];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[4];
    __xwrite uint32_t result_write[4];
    
    __assign_relative_register(&remote_signal3, 1);
    __assign_relative_register(&local_signal, 4);
    __implicit_write(&remote_signal3, sizeof(remote_signal3));
    __implicit_write(&remote_xfer3, sizeof(remote_xfer3));
    
    for (;;) {
        reg_set(result_gpr, 0x3ffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        
        __wait_for_all(&remote_signal3);
        reg_cp(&feature, &remote_xfer3, sizeof(feature));
        feature >>= 16;
            
        // Decision Tree Logic
        if (!(feature <= 4096))
            result_gpr[3] &= ~(1 << 3);

        if (!(feature <= 4096))
            result_gpr[3] &= ~(1 << 4);

        if (!(feature <= 4096))
            result_gpr[3] &= ~(1 << 5);

        if (!(feature <= 4096))
            result_gpr[3] &= ~(1 << 6);

        if (!(feature <= 4096))
            result_gpr[3] &= ~(1 << 7);

        if (!(feature <= 4096))
            result_gpr[3] &= ~(1 << 8);

        if (!(feature > 4096))
            result_gpr[3] &= ~(1 << 9);

        if (!(feature > 4096))
            result_gpr[3] &= ~(1 << 10);

        if (!(feature > 4096))
            result_gpr[3] &= ~(1 << 11);

        if (!(feature > 4096))
            result_gpr[3] &= ~(1 << 12);

        if (!(feature > 4096))
            result_gpr[3] &= ~(1 << 13);

        if (!(feature > 4096))
            result_gpr[3] &= ~(1 << 14);

        if (!(feature > 4096))
            result_gpr[3] &= ~(1 << 15);

        if (!(feature > 4096))
            result_gpr[3] &= ~(1 << 16);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 12);

        if (!(feature > 4096))
            result_gpr[2] &= ~(1 << 13);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 14);

        if (!(feature > 4096))
            result_gpr[2] &= ~(1 << 15);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 23);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 24);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 25);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 26);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 27);

        if (!(feature > 4096))
            result_gpr[2] &= ~(1 << 28);

        if (!(feature <= 4096))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature <= 4096))
            result_gpr[1] &= ~(1 << 0);

        if (!(feature <= 4096))
            result_gpr[1] &= ~(1 << 1);

        if (!(feature <= 4096))
            result_gpr[1] &= ~(1 << 2);

        if (!(feature <= 4096))
            result_gpr[1] &= ~(1 << 3);

        if (!(feature <= 4096))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature <= 4096))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature > 4096))
            result_gpr[1] &= ~(1 << 6);

        if (!(feature > 4096))
            result_gpr[1] &= ~(1 << 7);

        if (!(feature > 4096))
            result_gpr[1] &= ~(1 << 8);
        
            
        reg_cp(&result_write, &result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(&result_write, 34, 9, 0, 
                                          __xfer_reg_number(&result_xfer3, __nfp_meid(34, 9)) + (__ctx() * 32), 
                                          sizeof(result_xfer3), &local_signal);    
    }
    
    return 0;
}
