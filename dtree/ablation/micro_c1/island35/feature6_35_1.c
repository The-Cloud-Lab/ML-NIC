#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal6;
__visible __xread uint32_t remote_xfer6;

__remote SIGNAL result_signal6;
__remote __xread uint32_t result_xfer6;

SIGNAL local_signal;


// feature: total packet length
int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr;
    __xwrite uint32_t result_write;
    
    __assign_relative_register(&remote_signal6, 1);
    __assign_relative_register(&local_signal, 3);
    __implicit_write(&remote_signal6, sizeof(remote_signal6));
    __implicit_write(&remote_xfer6, sizeof(remote_xfer6));
    
    for (;;) {
        reg_set(&result_gpr, 0xffff, sizeof(uint32_t));
        
        __wait_for_all(&remote_signal6);
        reg_cp(&feature, &remote_xfer6, sizeof(feature));
        feature &= 0xffff;       

        // Decision Tree Logic
        if (!(feature <= 50))
            result_gpr &= ~(1 << 2);

        if (!(feature <= 50))
            result_gpr &= ~(1 << 3);

        if (!(feature > 50 && feature <= 54))
            result_gpr &= ~(1 << 4);

        if (!(feature > 50 && feature <= 54))
            result_gpr &= ~(1 << 8);

        if (!(feature > 50 && feature <= 54))
            result_gpr &= ~(1 << 9);

        if (!(feature > 50 && feature <= 54))
            result_gpr &= ~(1 << 7);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282))
            result_gpr &= ~(1 << 13);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature <= 60))
            result_gpr &= ~(1 << 14);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 60))
            result_gpr &= ~(1 << 15);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282))
            result_gpr &= ~(1 << 12);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature <= 291))
            result_gpr &= ~(1 << 10);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature > 291))
            result_gpr &= ~(1 << 11);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339))
            result_gpr &= ~(1 << 6);

        if (!(feature > 50 && feature > 54 && feature > 455))
            result_gpr &= ~(1 << 5);
        
        
        reg_cp(&result_write, &result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(&result_write, 35, 4, 0, 
                                          __xfer_reg_number(&result_xfer6, __nfp_meid(35, 4)) + (__ctx() * 32), 
                                          sizeof(result_xfer6), &local_signal);    
    }
    
    return 0;
}
