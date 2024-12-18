#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal34;
__visible __xread uint32_t remote_xfer34;

__remote SIGNAL result_signal34;
__remote __xread uint32_t result_xfer34[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature99;
    __gpr uint32_t feature100;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal34, 1);
    __assign_relative_register(&local_signal, 3);
    __implicit_write(&remote_signal34, sizeof(remote_signal34));
    __implicit_write(&remote_xfer34, sizeof(remote_xfer34));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal34);
        reg_cp(&feature99, &remote_xfer34, sizeof(feature99));
        reg_cp(&feature100, &remote_xfer34, sizeof(feature100));        
        
        feature99 >>= 16;
        // Decision Tree Logic
        if (!(feature99 <= 283))
            result_gpr[2] &= ~(1 << 5);

        if (!(feature99 > 283))
            result_gpr[2] &= ~(1 << 6);
        
        
        feature100 &= 0xffff;
        // Decision Tree Logic
        if (!(feature100 <= 464))
            result_gpr[4] &= ~(1 << 12);

        if (!(feature100 <= 464))
            result_gpr[4] &= ~(1 << 13);

        if (!(feature100 > 464))
            result_gpr[5] &= ~(1 << 7);

        if (!(feature100 <= 756))
            result_gpr[0] &= ~(1 << 28);

        if (!(feature100 <= 756))
            result_gpr[0] &= ~(1 << 29);

        if (!(feature100 <= 756))
            result_gpr[0] &= ~(1 << 27);

        if (!(feature100 <= 756))
            result_gpr[6] &= ~(1 << 9);

        if (!(feature100 > 756))
            result_gpr[7] &= ~(1 << 7);

        if (!(feature100 <= 764))
            result_gpr[1] &= ~(1 << 1);

        if (!(feature100 <= 764))
            result_gpr[1] &= ~(1 << 2);

        if (!(feature100 > 764))
            result_gpr[1] &= ~(1 << 20);

        if (!(feature100 > 764))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature100 > 764))
            result_gpr[0] &= ~(1 << 10);

        if (!(feature100 > 764))
            result_gpr[0] &= ~(1 << 11);

        if (!(feature100 > 764))
            result_gpr[0] &= ~(1 << 12);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 5, 0, __xfer_reg_number(result_xfer34, __nfp_meid(36, 5)) + (__ctx() * 32), sizeof(result_xfer34), &local_signal);
    }

    return 0;
}


