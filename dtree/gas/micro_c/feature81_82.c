#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal28;
__visible __xread uint32_t remote_xfer28;

__remote SIGNAL result_signal28;
__remote __xread uint32_t result_xfer28[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature81;
    __gpr uint32_t feature82;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal28, 1);
    __assign_relative_register(&local_signal, 5);
    __implicit_write(&remote_signal28, sizeof(remote_signal28));
    __implicit_write(&remote_xfer28, sizeof(remote_xfer28));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal28);
        reg_cp(&feature81, &remote_xfer28, sizeof(feature81));
        reg_cp(&feature82, &remote_xfer28, sizeof(feature82));
        
        feature81 >>= 16;
        // Decision Tree Logic
        if (!(feature81 <= 1343))
            result_gpr[7] &= ~(1 << 25);

        if (!(feature81 > 1343))
            result_gpr[5] &= ~(1 << 22);

        if (!(feature81 > 1343))
            result_gpr[2] &= ~(1 << 28);

        if (!(feature81 > 1343))
            result_gpr[2] &= ~(1 << 29);

        if (!(feature81 <= 1749))
            result_gpr[6] &= ~(1 << 23);

        if (!(feature81 > 1749))
            result_gpr[6] &= ~(1 << 24);

        
        feature82 &= 0xffff;
        // Decision Tree Logic
        if (!(feature82 <= 264))
            result_gpr[4] &= ~(1 << 29);

        if (!(feature82 <= 264))
            result_gpr[4] &= ~(1 << 30);

        if (!(feature82 <= 264))
            result_gpr[4] &= ~(1 << 5);

        if (!(feature82 <= 264))
            result_gpr[2] &= ~(1 << 22);

        if (!(feature82 <= 264))
            result_gpr[2] &= ~(1 << 23);

        if (!(feature82 <= 264))
            result_gpr[6] &= ~(1 << 18);

        if (!(feature82 <= 264))
            result_gpr[4] &= ~(1 << 16);

        if (!(feature82 <= 264))
            result_gpr[4] &= ~(1 << 17);

        if (!(feature82 <= 264))
            result_gpr[1] &= ~(1 << 17);

        if (!(feature82 <= 264))
            result_gpr[1] &= ~(1 << 18);

        if (!(feature82 <= 264))
            result_gpr[1] &= ~(1 << 19);

        if (!(feature82 <= 264))
            result_gpr[7] &= ~(1 << 28);

        if (!(feature82 > 264))
            result_gpr[7] &= ~(1 << 18);

        if (!(feature82 > 264))
            result_gpr[3] &= ~(1 << 31);

        if (!(feature82 > 264))
            result_gpr[2] &= ~(1 << 0);

        if (!(feature82 > 264))
            result_gpr[5] &= ~(1 << 10);

        if (!(feature82 > 264))
            result_gpr[4] &= ~(1 << 22);

        if (!(feature82 > 264))
            result_gpr[4] &= ~(1 << 23);

        if (!(feature82 > 264))
            result_gpr[5] &= ~(1 << 14);

        if (!(feature82 > 264))
            result_gpr[5] &= ~(1 << 15);

        if (!(feature82 > 264))
            result_gpr[5] &= ~(1 << 13);

        if (!(feature82 > 264))
            result_gpr[5] &= ~(1 << 28);

        if (!(feature82 > 264))
            result_gpr[5] &= ~(1 << 29);

        if (!(feature82 > 264))
            result_gpr[0] &= ~(1 << 14);

        if (!(feature82 > 264))
            result_gpr[0] &= ~(1 << 15);

        if (!(feature82 > 264))
            result_gpr[0] &= ~(1 << 13);

        if (!(feature82 > 264))
            result_gpr[4] &= ~(1 << 9);

        if (!(feature82 > 264))
            result_gpr[7] &= ~(1 << 5);

        if (!(feature82 <= 296))
            result_gpr[7] &= ~(1 << 10);

        if (!(feature82 <= 296))
            result_gpr[5] &= ~(1 << 3);

        if (!(feature82 <= 296))
            result_gpr[5] &= ~(1 << 4);

        if (!(feature82 <= 296))
            result_gpr[4] &= ~(1 << 6);

        if (!(feature82 <= 296))
            result_gpr[4] &= ~(1 << 7);

        if (!(feature82 <= 296))
            result_gpr[6] &= ~(1 << 29);

        if (!(feature82 > 296))
            result_gpr[2] &= ~(1 << 9);

        if (!(feature82 > 296))
            result_gpr[2] &= ~(1 << 10);

        if (!(feature82 > 296))
            result_gpr[5] &= ~(1 << 11);

        if (!(feature82 > 296))
            result_gpr[5] &= ~(1 << 12);

        if (!(feature82 > 296))
            result_gpr[7] &= ~(1 << 11);
        

        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 3, 0, __xfer_reg_number(result_xfer28, __nfp_meid(36, 3)) + (__ctx() * 32), sizeof(result_xfer28), &local_signal);
    }

    return 0;
}


