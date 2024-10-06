#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal2;
__visible __xread uint32_t remote_xfer2;

__remote SIGNAL result_signal2;
__remote __xread uint32_t result_xfer2[4];

SIGNAL local_signal;


// feature: ipv4 protocol
int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[4];
    __xwrite uint32_t result_write[4];
    
    __assign_relative_register(&remote_signal2, 1);
    __assign_relative_register(&local_signal, 2);
    __implicit_write(&remote_signal2, sizeof(remote_signal2));
    __implicit_write(&remote_xfer2, sizeof(remote_xfer2));
    
    for (;;) {
        reg_set(result_gpr, 0x3ffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        
        __wait_for_all(&remote_signal2);
        reg_cp(&feature, &remote_xfer2, sizeof(feature));
        feature >>= 16;
        feature &= 0xff;      
        
        // Decision Tree Logic
        if (!(feature <= 1))
            result_gpr[3] &= ~(1 << 29);

        if (!(feature <= 1))
            result_gpr[3] &= ~(1 << 30);

        if (!(feature > 1))
            result_gpr[1] &= ~(1 << 13);

        if (!(feature > 1))
            result_gpr[1] &= ~(1 << 14);

        if (!(feature > 1 && feature <= 11))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature > 1 && feature <= 11))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature > 1 && feature > 11))
            result_gpr[0] &= ~(1 << 20);

        if (!(feature > 1))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature > 1))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature > 1))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature > 1))
            result_gpr[1] &= ~(1 << 17);

        if (!(feature > 1))
            result_gpr[1] &= ~(1 << 16);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 32, 7, 0, 
                                          __xfer_reg_number(result_xfer2, __nfp_meid(32, 7)) + (__ctx() * 32), 
                                          sizeof(result_xfer2), &local_signal);    
    }
    
    return 0;
}
