#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal3;
__visible __xread uint32_t remote_xfer3;

__remote SIGNAL result_signal3;
__remote __xread uint32_t result_xfer3[6];

SIGNAL local_signal;


// feature: ipv4 flags
int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[6];
    __xwrite uint32_t result_write[6];
    
    __assign_relative_register(&remote_signal3, 1);
    __assign_relative_register(&local_signal, 3);
    __implicit_write(&remote_signal3, sizeof(remote_signal3));
    __implicit_write(&remote_xfer3, sizeof(remote_xfer3));
    
    for (;;) {
        reg_set(result_gpr, 0xffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));

        
        __wait_for_all(&remote_signal3);
        reg_cp(&feature, &remote_xfer3, sizeof(feature));
        feature &= 0xffff;
        feature >>= 13; 
        
        // Decision Tree Logic
        if (!(feature <= 1))
            result_gpr[1] &= ~(1 << 7);

        if (!(feature > 1))
            result_gpr[1] &= ~(1 << 8);

        if (!(feature <= 1))
            result_gpr[5] &= ~(1 << 14);

        if (!(feature > 1))
            result_gpr[5] &= ~(1 << 21);

        if (!(feature > 1))
            result_gpr[4] &= ~(1 << 6);

        if (!(feature > 1))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature > 1))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature > 1))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature > 1))
            result_gpr[0] &= ~(1 << 14);

        if (!(feature > 1))
            result_gpr[0] &= ~(1 << 15);

        if (!(feature > 1))
            result_gpr[0] &= ~(1 << 13);

        if (!(feature > 1))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature > 1))
            result_gpr[0] &= ~(1 << 4);

        if (!(feature > 1))
            result_gpr[0] &= ~(1 << 5);

        if (!(feature > 1))
            result_gpr[0] &= ~(1 << 6);

        if (!(feature > 1))
            result_gpr[5] &= ~(1 << 30);
        
        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 7, 0, 
                                          __xfer_reg_number(result_xfer3, __nfp_meid(35, 7)) + (__ctx() * 32), 
                                          sizeof(result_xfer3), &local_signal);    
    }
    
    return 0;
}
