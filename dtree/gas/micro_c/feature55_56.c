#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal18;
__visible __xread uint32_t remote_xfer18;

__remote SIGNAL result_signal18;
__remote __xread uint32_t result_xfer18[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature55;
    __gpr uint32_t feature56;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal18, 1);
    __assign_relative_register(&local_signal, 3);
    __implicit_write(&remote_signal18, sizeof(remote_signal18));
    __implicit_write(&remote_xfer18, sizeof(remote_xfer18));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal18);
        reg_cp(&feature55, &remote_xfer18, sizeof(feature55));
        reg_cp(&feature56, &remote_xfer18, sizeof(feature56));        
        
        feature55 >>= 16;
        // Decision Tree Logic
        if (!(feature55 <= 5687))
            result_gpr[1] &= ~(1 << 12);

        if (!(feature55 > 5687))
            result_gpr[1] &= ~(1 << 13);

        
        feature56 &= 0xffff;
        // Decision Tree Logic
        if (!(feature56 <= 7893))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature56 <= 7893))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature56 <= 7893))
            result_gpr[1] &= ~(1 << 0);

        if (!(feature56 <= 7893))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature56 <= 7893))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature56 <= 7893))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature56 <= 7893))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature56 <= 7893))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature56 <= 7893))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature56 <= 7893))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature56 <= 7893))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature56 <= 7893))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature56 <= 7893))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature56 <= 7893))
            result_gpr[2] &= ~(1 << 24);

        if (!(feature56 <= 7893))
            result_gpr[2] &= ~(1 << 25);

        if (!(feature56 <= 7893))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature56 <= 7893))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature56 <= 7893))
            result_gpr[5] &= ~(1 << 31);

        if (!(feature56 > 7893))
            result_gpr[5] &= ~(1 << 9);
        
        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 1, 0, __xfer_reg_number(result_xfer18, __nfp_meid(36, 1)) + (__ctx() * 32), sizeof(result_xfer18), &local_signal);
    }

    return 0;
}


