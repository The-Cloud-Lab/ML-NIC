#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal36;
__visible __xread uint32_t remote_xfer36;

__remote SIGNAL result_signal36;
__remote __xread uint32_t result_xfer36[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature103;
    __gpr uint32_t feature104;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal36, 1);
    __assign_relative_register(&local_signal, 5);
    __implicit_write(&remote_signal36, sizeof(remote_signal36));
    __implicit_write(&remote_xfer36, sizeof(remote_xfer36));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal36);
        reg_cp(&feature103, &remote_xfer36, sizeof(feature103));
        reg_cp(&feature104, &remote_xfer36, sizeof(feature104));        
        
        feature103 >>= 16;
        // Decision Tree Logic
        if (!(feature103 <= 7644))
            result_gpr[6] &= ~(1 << 14);

        if (!(feature103 > 7644))
            result_gpr[6] &= ~(1 << 15);

        if (!(feature103 <= 7600))
            result_gpr[3] &= ~(1 << 27);

        if (!(feature103 > 7600))
            result_gpr[3] &= ~(1 << 28);
        
        
        feature104 &= 0xffff;
        // Decision Tree Logic
        if (!(feature104 <= 8069))
            result_gpr[4] &= ~(1 << 22);

        if (!(feature104 <= 8069))
            result_gpr[4] &= ~(1 << 23);

        if (!(feature104 <= 8069))
            result_gpr[5] &= ~(1 << 14);

        if (!(feature104 <= 8069))
            result_gpr[5] &= ~(1 << 15);

        if (!(feature104 <= 8069))
            result_gpr[5] &= ~(1 << 13);

        if (!(feature104 > 8069))
            result_gpr[5] &= ~(1 << 28);

        if (!(feature104 > 8069))
            result_gpr[5] &= ~(1 << 29);

        if (!(feature104 > 8069))
            result_gpr[0] &= ~(1 << 14);

        if (!(feature104 > 8069))
            result_gpr[0] &= ~(1 << 15);

        if (!(feature104 > 8069))
            result_gpr[0] &= ~(1 << 13);

        if (!(feature104 > 8069))
            result_gpr[4] &= ~(1 << 9);

        if (!(feature104 <= 7995))
            result_gpr[2] &= ~(1 << 28);

        if (!(feature104 > 7995))
            result_gpr[2] &= ~(1 << 29);

        if (!(feature104 <= 8070))
            result_gpr[0] &= ~(1 << 5);

        if (!(feature104 > 8070))
            result_gpr[0] &= ~(1 << 6);

        if (!(feature104 <= 8127))
            result_gpr[3] &= ~(1 << 10);

        if (!(feature104 > 8127))
            result_gpr[3] &= ~(1 << 11);

        if (!(feature104 <= 8103))
            result_gpr[6] &= ~(1 << 4);

        if (!(feature104 <= 8103))
            result_gpr[6] &= ~(1 << 5);

        if (!(feature104 <= 8103))
            result_gpr[3] &= ~(1 << 25);

        if (!(feature104 <= 8103))
            result_gpr[3] &= ~(1 << 26);

        if (!(feature104 <= 8103))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature104 <= 8103))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature104 <= 8103))
            result_gpr[1] &= ~(1 << 0);

        if (!(feature104 <= 8103))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature104 <= 8103))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature104 <= 8103))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature104 <= 8103))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature104 <= 8103))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature104 <= 8103))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature104 <= 8103))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature104 <= 8103))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature104 <= 8103))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature104 <= 8103))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature104 <= 8103))
            result_gpr[2] &= ~(1 << 24);

        if (!(feature104 <= 8103))
            result_gpr[2] &= ~(1 << 25);

        if (!(feature104 <= 8103))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature104 <= 8103))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature104 <= 8103))
            result_gpr[5] &= ~(1 << 31);

        if (!(feature104 <= 8103))
            result_gpr[5] &= ~(1 << 9);

        if (!(feature104 <= 8103))
            result_gpr[6] &= ~(1 << 10);

        if (!(feature104 <= 8103))
            result_gpr[5] &= ~(1 << 23);

        if (!(feature104 <= 8103))
            result_gpr[5] &= ~(1 << 24);

        if (!(feature104 > 8103))
            result_gpr[3] &= ~(1 << 0);

        if (!(feature104 > 8103))
            result_gpr[3] &= ~(1 << 1);


        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 5, 0, __xfer_reg_number(result_xfer36, __nfp_meid(36, 5)) + (__ctx() * 32), sizeof(result_xfer36), &local_signal);
    }

    return 0;
}


