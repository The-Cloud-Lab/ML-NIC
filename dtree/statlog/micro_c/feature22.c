#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal22;
__visible __xread uint32_t remote_xfer22;

__remote SIGNAL result_signal22;
__remote __xread uint32_t result_xfer22[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal22, 1);
    __assign_relative_register(&local_signal, 3);
    __implicit_write(&remote_signal22, sizeof(remote_signal22));
    __implicit_write(&remote_xfer22, sizeof(remote_xfer22));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal22);
        reg_cp(&feature, &remote_xfer22, sizeof(feature));
        feature &= 0xffff;
      
        // Decision Tree Logic
        if (!(feature <= 2903))
            result_gpr[6] &= ~(1 << 1);

        if (!(feature > 2903))
            result_gpr[6] &= ~(1 << 2);

        if (!(feature <= 3460))
            result_gpr[2] &= ~(1 << 28);

        if (!(feature > 3460))
            result_gpr[2] &= ~(1 << 29);

        if (!(feature <= 4573))
            result_gpr[4] &= ~(1 << 7);

        if (!(feature > 4573))
            result_gpr[4] &= ~(1 << 8);

        if (!(feature <= 5886))
            result_gpr[3] &= ~(1 << 1);

        if (!(feature > 5886))
            result_gpr[3] &= ~(1 << 2);


        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 6, 0, __xfer_reg_number(result_xfer22, __nfp_meid(35, 6)) + (__ctx() * 32), sizeof(result_xfer22), &local_signal);
    }

    return 0;
}


