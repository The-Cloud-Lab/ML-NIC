#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal38;
__visible __xread uint32_t remote_xfer38[2];

__remote SIGNAL result_signal38;
__remote __xread uint32_t result_xfer38[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature108;
    __gpr uint32_t feature109;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal38, 1);
    __assign_relative_register(&local_signal, 3);
    __implicit_write(&remote_signal38, sizeof(remote_signal38));
    __implicit_write(&remote_xfer38, sizeof(remote_xfer38));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal38);
        reg_cp(&feature108, remote_xfer38, sizeof(feature108));
        reg_cp(&feature109, remote_xfer38+1, sizeof(feature109));
        
        feature108 &= 0xffff;
        // Decision Tree Logic
        if (!(feature108 <= 1325))
            result_gpr[2] &= ~(1 << 1);

        if (!(feature108 <= 1325))
            result_gpr[2] &= ~(1 << 2);

        if (!(feature108 <= 1325))
            result_gpr[5] &= ~(1 << 6);

        if (!(feature108 <= 1325 && feature108 <= 1170))
            result_gpr[0] &= ~(1 << 30);

        if (!(feature108 <= 1325 && feature108 <= 1170))
            result_gpr[0] &= ~(1 << 31);

        if (!(feature108 <= 1325 && feature108 <= 1170))
            result_gpr[0] &= ~(1 << 5);

        if (!(feature108 <= 1325 && feature108 <= 1170))
            result_gpr[0] &= ~(1 << 6);

        if (!(feature108 <= 1325 && feature108 <= 1170))
            result_gpr[0] &= ~(1 << 7);

        if (!(feature108 <= 1325 && feature108 <= 1170))
            result_gpr[0] &= ~(1 << 8);

        if (!(feature108 <= 1325 && feature108 <= 1170))
            result_gpr[0] &= ~(1 << 9);

        if (!(feature108 <= 1325 && feature108 <= 1170))
            result_gpr[0] &= ~(1 << 4);

        if (!(feature108 <= 1325 && feature108 > 1170))
            result_gpr[0] &= ~(1 << 2);

        if (!(feature108 <= 1325 && feature108 > 1170))
            result_gpr[0] &= ~(1 << 3);

        if (!(feature108 <= 1325 && feature108 > 1170))
            result_gpr[0] &= ~(1 << 1);

        if (!(feature108 <= 1325))
            result_gpr[5] &= ~(1 << 5);

        if (!(feature108 <= 1325))
            result_gpr[6] &= ~(1 << 3);

        if (!(feature108 <= 1325))
            result_gpr[3] &= ~(1 << 23);

        if (!(feature108 <= 1325))
            result_gpr[3] &= ~(1 << 24);

        if (!(feature108 > 1325))
            result_gpr[6] &= ~(1 << 6);

        if (!(feature108 > 1325))
            result_gpr[2] &= ~(1 << 3);

        if (!(feature108 > 1325))
            result_gpr[2] &= ~(1 << 4);

        if (!(feature108 <= 723))
            result_gpr[2] &= ~(1 << 26);

        if (!(feature108 > 723))
            result_gpr[2] &= ~(1 << 27);
            
        
        feature109 >>= 16;
        // Decision Tree Logic
        if (!(feature109 <= 24))
            result_gpr[5] &= ~(1 << 28);

        if (!(feature109 <= 24))
            result_gpr[5] &= ~(1 << 29);

        if (!(feature109 > 24))
            result_gpr[0] &= ~(1 << 14);

        if (!(feature109 > 24))
            result_gpr[0] &= ~(1 << 15);

        if (!(feature109 > 24))
            result_gpr[0] &= ~(1 << 13);

        if (!(feature109 > 24))
            result_gpr[4] &= ~(1 << 9);

        

        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 6, 0, __xfer_reg_number(result_xfer38, __nfp_meid(36, 6)) + (__ctx() * 32), sizeof(result_xfer38), &local_signal);
    }

    return 0;
}


