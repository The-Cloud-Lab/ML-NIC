#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal30;
__visible __xread uint32_t remote_xfer30[2];

__remote SIGNAL result_signal30;
__remote __xread uint32_t result_xfer30[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature85;
    __gpr uint32_t feature87;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal30, 1);
    __assign_relative_register(&local_signal, 3);
    __implicit_write(&remote_signal30, sizeof(remote_signal30));
    __implicit_write(&remote_xfer30, sizeof(remote_xfer30));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal30);
        reg_cp(&feature85, remote_xfer30, sizeof(feature85));
        reg_cp(&feature87, remote_xfer30, sizeof(feature87));        
        
        feature85 >>= 16;
        // Decision Tree Logic
        if (!(feature85 <= 37))
            result_gpr[4] &= ~(1 << 5);

        if (!(feature85 > 37))
            result_gpr[2] &= ~(1 << 22);

        if (!(feature85 > 37))
            result_gpr[2] &= ~(1 << 23);

        if (!(feature85 <= 404))
            result_gpr[5] &= ~(1 << 22);

        if (!(feature85 > 404))
            result_gpr[2] &= ~(1 << 28);

        if (!(feature85 > 404))
            result_gpr[2] &= ~(1 << 29);

        if (!(feature85 <= 434))
            result_gpr[1] &= ~(1 << 3);

        if (!(feature85 <= 434))
            result_gpr[1] &= ~(1 << 8);

        if (!(feature85 <= 434))
            result_gpr[1] &= ~(1 << 9);

        if (!(feature85 > 434))
            result_gpr[5] &= ~(1 << 18);

        
        feature87 >>= 16;
        // Decision Tree Logic
        if (!(feature87 <= 7125))
            result_gpr[0] &= ~(1 << 25);

        if (!(feature87 > 7125))
            result_gpr[0] &= ~(1 << 26);


        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 4, 0, __xfer_reg_number(result_xfer30, __nfp_meid(36, 4)) + (__ctx() * 32), sizeof(result_xfer30), &local_signal);
    }

    return 0;
}


