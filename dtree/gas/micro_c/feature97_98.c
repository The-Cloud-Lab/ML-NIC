#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal33;
__visible __xread uint32_t remote_xfer33;

__remote SIGNAL result_signal33;
__remote __xread uint32_t result_xfer33[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature97;
    __gpr uint32_t feature98;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal33, 1);
    __assign_relative_register(&local_signal, 2);
    __implicit_write(&remote_signal33, sizeof(remote_signal33));
    __implicit_write(&remote_xfer33, sizeof(remote_xfer33));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal33);
        reg_cp(&feature97, &remote_xfer33, sizeof(feature97));
        reg_cp(&feature98, &remote_xfer33, sizeof(feature98));

        feature97 >>= 16;
        // Decision Tree Logic
        if (!(feature97 <= 1393))
            result_gpr[5] &= ~(1 << 28);

        if (!(feature97 > 1393))
            result_gpr[5] &= ~(1 << 29);

        if (!(feature97 <= 3912))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature97 <= 3912))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature97 <= 3912))
            result_gpr[1] &= ~(1 << 0);

        if (!(feature97 <= 3912))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature97 <= 3912))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature97 <= 3912))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature97 <= 3912))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature97 <= 3912))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature97 <= 3912))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature97 <= 3912))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature97 <= 3912))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature97 <= 3912))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature97 <= 3912))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature97 <= 3912))
            result_gpr[2] &= ~(1 << 24);

        if (!(feature97 <= 3912))
            result_gpr[2] &= ~(1 << 25);

        if (!(feature97 <= 3912))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature97 <= 3912))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature97 <= 3912))
            result_gpr[5] &= ~(1 << 31);

        if (!(feature97 <= 3912))
            result_gpr[5] &= ~(1 << 9);

        if (!(feature97 > 3912))
            result_gpr[6] &= ~(1 << 10);

        if (!(feature97 <= 4869))
            result_gpr[7] &= ~(1 << 2);

        if (!(feature97 > 4869))
            result_gpr[7] &= ~(1 << 19);

        if (!(feature97 > 4869))
            result_gpr[1] &= ~(1 << 12);

        if (!(feature97 > 4869))
            result_gpr[1] &= ~(1 << 13);

        if (!(feature97 > 4869))
            result_gpr[4] &= ~(1 << 2);

        
        
        feature98 &= 0xffff;
        // Decision Tree Logic
        if (!(feature98 <= 1574))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature98 > 1574))
            result_gpr[0] &= ~(1 << 0);

        if (!(feature98 <= 501))
            result_gpr[5] &= ~(1 << 8);

        if (!(feature98 > 501))
            result_gpr[2] &= ~(1 << 26);

        if (!(feature98 > 501))
            result_gpr[2] &= ~(1 << 27);

        if (!(feature98 > 501))
            result_gpr[1] &= ~(1 << 1);

        if (!(feature98 > 501))
            result_gpr[1] &= ~(1 << 2);

        if (!(feature98 > 501))
            result_gpr[1] &= ~(1 << 20);

        if (!(feature98 > 501))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature98 > 501))
            result_gpr[0] &= ~(1 << 10);

        if (!(feature98 > 501))
            result_gpr[0] &= ~(1 << 11);

        if (!(feature98 > 501))
            result_gpr[0] &= ~(1 << 12);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 5, 0, __xfer_reg_number(result_xfer33, __nfp_meid(36, 5)) + (__ctx() * 32), sizeof(result_xfer33), &local_signal);
    }

    return 0;
}


