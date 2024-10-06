#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal7;
__visible __xread uint32_t remote_xfer7;

__remote SIGNAL result_signal7;
__remote __xread uint32_t result_xfer7[2];

SIGNAL local_signal;

// feature: tcp flags
int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[2];
    __xwrite uint32_t result_write[2];
    
    __assign_relative_register(&remote_signal7, 1);
    __assign_relative_register(&local_signal, 5);
    __implicit_write(&remote_signal7, sizeof(remote_signal7));
    __implicit_write(&remote_xfer7, sizeof(remote_xfer7));
    
    for (;;) {
        reg_set(result_gpr, 0x3ff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        
        __wait_for_all(&remote_signal7);
        reg_cp(&feature, &remote_xfer7, sizeof(feature));
        feature >>= 16;
        feature &= 0x3f;       

        // Decision Tree Logic
        if (!(feature <= 10 && feature <= 3))
            result_gpr[0] &= ~(1 << 8);

        if (!(feature <= 10 && feature > 3))
            result_gpr[0] &= ~(1 << 9);

        if (!(feature > 10))
            result_gpr[1] &= ~(1 << 16);

        if (!(feature > 10))
            result_gpr[1] &= ~(1 << 17);

        if (!(feature <= 9))
            result_gpr[1] &= ~(1 << 1);

        if (!(feature > 9 && feature <= 18 && feature <= 16))
            result_gpr[1] &= ~(1 << 6);

        if (!(feature > 9 && feature <= 18 && feature <= 16))
            result_gpr[1] &= ~(1 << 7);

        if (!(feature > 9 && feature <= 18 && feature > 16))
            result_gpr[1] &= ~(1 << 3);

        if (!(feature > 9 && feature > 18))
            result_gpr[1] &= ~(1 << 2);

        if (!(feature <= 20))
            result_gpr[1] &= ~(1 << 18);

        if (!(feature <= 20))
            result_gpr[1] &= ~(1 << 19);

        if (!(feature > 20))
            result_gpr[1] &= ~(1 << 14);

        if (!(feature > 20))
            result_gpr[1] &= ~(1 << 15);

        if (!(feature > 20))
            result_gpr[1] &= ~(1 << 13);

        if (!(feature > 20 && feature <= 24))
            result_gpr[0] &= ~(1 << 6);

        if (!(feature > 20 && feature > 24))
            result_gpr[0] &= ~(1 << 7);

        if (!(feature <= 24))
            result_gpr[1] &= ~(1 << 11);

        if (!(feature > 24))
            result_gpr[1] &= ~(1 << 12);

        if (!(feature <= 33))
            result_gpr[1] &= ~(1 << 22);

        if (!(feature <= 33))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature <= 33))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature <= 33))
            result_gpr[1] &= ~(1 << 23);

        if (!(feature <= 33))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature <= 33 && feature <= 3))
            result_gpr[0] &= ~(1 << 2);

        if (!(feature <= 33 && feature <= 3))
            result_gpr[0] &= ~(1 << 3);

        if (!(feature <= 33 && feature > 3))
            result_gpr[1] &= ~(1 << 24);

        if (!(feature > 33))
            result_gpr[1] &= ~(1 << 20);
        
        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(&result_write, 33, 11, 0, 
                                          __xfer_reg_number(result_xfer7, __nfp_meid(33, 11)) + (__ctx() * 32), 
                                          sizeof(result_xfer7), &local_signal);    
    }
    
    return 0;
}
