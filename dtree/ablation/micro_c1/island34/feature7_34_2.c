#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal7;
__visible __xread uint32_t remote_xfer7;

__remote SIGNAL result_signal7;
__remote __xread uint32_t result_xfer7;

SIGNAL local_signal;

// feature: tcp flags
int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr;
    __xwrite uint32_t result_write;
    
    __assign_relative_register(&remote_signal7, 1);
    __assign_relative_register(&local_signal, 4);
    __implicit_write(&remote_signal7, sizeof(remote_signal7));
    __implicit_write(&remote_xfer7, sizeof(remote_xfer7));
    
    for (;;) {
        reg_set(&result_gpr, 0xffff, sizeof(uint32_t));
        
        __wait_for_all(&remote_signal7);
        reg_cp(&feature, &remote_xfer7, sizeof(feature));
        feature >>= 16;
        feature &= 0x3f;       

        // Decision Tree Logic
        if (!(feature <= 10))
            result_gpr &= ~(1 << 2);

        if (!(feature > 10))
            result_gpr &= ~(1 << 3);

        if (!(feature <= 9))
            result_gpr &= ~(1 << 4);

        if (!(feature > 9 && feature <= 18 && feature <= 16))
            result_gpr &= ~(1 << 8);

        if (!(feature > 9 && feature <= 18 && feature > 16))
            result_gpr &= ~(1 << 9);

        if (!(feature > 9 && feature > 18))
            result_gpr &= ~(1 << 7);

        if (!(feature <= 20))
            result_gpr &= ~(1 << 13);

        if (!(feature > 20))
            result_gpr &= ~(1 << 14);

        if (!(feature > 20))
            result_gpr &= ~(1 << 15);
        
        
        reg_cp(&result_write, &result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(&result_write, 34, 9, 0, 
                                          __xfer_reg_number(&result_xfer7, __nfp_meid(34, 9)) + (__ctx() * 32), 
                                          sizeof(result_xfer7), &local_signal);    
    }
    
    return 0;
}
