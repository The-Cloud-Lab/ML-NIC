#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal13;
__visible __xread uint32_t remote_xfer13;

__remote SIGNAL result_signal13;
__remote __xread uint32_t result_xfer13[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature35;
    __gpr uint32_t feature36;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal13, 1);
    __assign_relative_register(&local_signal, 2);
    __implicit_write(&remote_signal13, sizeof(remote_signal13));
    __implicit_write(&remote_xfer13, sizeof(remote_xfer13));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal13);
        reg_cp(&feature35, &remote_xfer13, sizeof(feature35));
        reg_cp(&feature36, &remote_xfer13, sizeof(feature36));
        
        feature35 >>= 16;
        // Decision Tree Logic
        if (!(feature35 <= 312))
            result_gpr[7] &= ~(1 << 20);

        if (!(feature35 > 312))
            result_gpr[5] &= ~(1 << 16);

        if (!(feature35 > 312))
            result_gpr[5] &= ~(1 << 17);

       
        feature36 &= 0xffff;
        // Decision Tree Logic
        if (!(feature36 <= 94))
            result_gpr[7] &= ~(1 << 6);

        if (!(feature36 <= 94))
            result_gpr[3] &= ~(1 << 9);

        if (!(feature36 <= 94))
            result_gpr[3] &= ~(1 << 10);

        if (!(feature36 <= 94))
            result_gpr[3] &= ~(1 << 11);

        if (!(feature36 <= 94))
            result_gpr[2] &= ~(1 << 18);

        if (!(feature36 <= 94))
            result_gpr[2] &= ~(1 << 19);

        if (!(feature36 <= 94))
            result_gpr[4] &= ~(1 << 19);

        if (!(feature36 <= 94))
            result_gpr[4] &= ~(1 << 21);

        if (!(feature36 <= 94))
            result_gpr[0] &= ~(1 << 24);

        if (!(feature36 <= 94))
            result_gpr[0] &= ~(1 << 25);

        if (!(feature36 <= 94))
            result_gpr[0] &= ~(1 << 26);

        if (!(feature36 <= 94))
            result_gpr[2] &= ~(1 << 5);

        if (!(feature36 <= 94))
            result_gpr[2] &= ~(1 << 6);

        if (!(feature36 <= 94))
            result_gpr[4] &= ~(1 << 20);

        if (!(feature36 <= 94))
            result_gpr[6] &= ~(1 << 23);

        if (!(feature36 <= 94))
            result_gpr[6] &= ~(1 << 24);

        if (!(feature36 <= 94))
            result_gpr[6] &= ~(1 << 16);

        if (!(feature36 <= 94))
            result_gpr[6] &= ~(1 << 17);

        if (!(feature36 > 94))
            result_gpr[7] &= ~(1 << 23);

        if (!(feature36 > 94))
            result_gpr[6] &= ~(1 << 25);

        if (!(feature36 > 94))
            result_gpr[6] &= ~(1 << 26);

        if (!(feature36 > 94))
            result_gpr[3] &= ~(1 << 7);

        if (!(feature36 > 94))
            result_gpr[3] &= ~(1 << 8);

        if (!(feature36 > 94))
            result_gpr[1] &= ~(1 << 22);

        if (!(feature36 > 94))
            result_gpr[1] &= ~(1 << 23);

        if (!(feature36 > 94))
            result_gpr[1] &= ~(1 << 24);

        if (!(feature36 > 94))
            result_gpr[3] &= ~(1 << 6);

        if (!(feature36 > 94))
            result_gpr[3] &= ~(1 << 5);

        if (!(feature36 > 94))
            result_gpr[6] &= ~(1 << 14);

        if (!(feature36 > 94))
            result_gpr[6] &= ~(1 << 15);

        if (!(feature36 > 94))
            result_gpr[6] &= ~(1 << 4);

        if (!(feature36 > 94))
            result_gpr[6] &= ~(1 << 5);

        if (!(feature36 > 94 && feature36 <= 138))
            result_gpr[3] &= ~(1 << 25);

        if (!(feature36 > 94 && feature36 <= 138))
            result_gpr[3] &= ~(1 << 26);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[1] &= ~(1 << 0);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[2] &= ~(1 << 24);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[2] &= ~(1 << 25);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[5] &= ~(1 << 31);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[5] &= ~(1 << 9);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[6] &= ~(1 << 10);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[5] &= ~(1 << 23);

        if (!(feature36 > 94 && feature36 > 138))
            result_gpr[5] &= ~(1 << 24);

        if (!(feature36 > 94))
            result_gpr[3] &= ~(1 << 0);

        if (!(feature36 > 94))
            result_gpr[3] &= ~(1 << 1);

        if (!(feature36 > 94))
            result_gpr[7] &= ~(1 << 13);

        if (!(feature36 > 94))
            result_gpr[7] &= ~(1 << 14);

        if (!(feature36 > 94))
            result_gpr[3] &= ~(1 << 16);

        if (!(feature36 > 94))
            result_gpr[3] &= ~(1 << 17);

        if (!(feature36 > 94))
            result_gpr[6] &= ~(1 << 21);

        if (!(feature36 > 94))
            result_gpr[6] &= ~(1 << 22);

        if (!(feature36 > 94))
            result_gpr[6] &= ~(1 << 2);

        if (!(feature36 > 94))
            result_gpr[6] &= ~(1 << 19);

        if (!(feature36 > 94))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature36 > 94))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature36 > 94))
            result_gpr[0] &= ~(1 << 0);

        if (!(feature36 > 94))
            result_gpr[4] &= ~(1 << 26);

        if (!(feature36 > 94))
            result_gpr[4] &= ~(1 << 0);

        if (!(feature36 > 94))
            result_gpr[4] &= ~(1 << 1);

        if (!(feature36 > 94))
            result_gpr[2] &= ~(1 << 16);

        if (!(feature36 > 94))
            result_gpr[2] &= ~(1 << 17);

        if (!(feature36 > 94))
            result_gpr[6] &= ~(1 << 11);

        if (!(feature36 > 94))
            result_gpr[6] &= ~(1 << 30);

        if (!(feature36 > 94))
            result_gpr[2] &= ~(1 << 7);

        if (!(feature36 > 94))
            result_gpr[2] &= ~(1 << 8);

        if (!(feature36 > 94))
            result_gpr[3] &= ~(1 << 21);

        if (!(feature36 > 94))
            result_gpr[3] &= ~(1 << 22);

        if (!(feature36 > 94))
            result_gpr[7] &= ~(1 << 17);

        if (!(feature36 > 94))
            result_gpr[7] &= ~(1 << 4);

        if (!(feature36 > 94))
            result_gpr[5] &= ~(1 << 30);

        if (!(feature36 > 94))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature36 > 94))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature36 > 94 && feature36 <= 280))
            result_gpr[1] &= ~(1 << 15);

        if (!(feature36 > 94 && feature36 <= 280))
            result_gpr[1] &= ~(1 << 16);

        if (!(feature36 > 94 && feature36 <= 280))
            result_gpr[1] &= ~(1 << 14);

        if (!(feature36 > 94 && feature36 > 280))
            result_gpr[4] &= ~(1 << 18);

        if (!(feature36 > 94))
            result_gpr[2] &= ~(1 << 12);

        if (!(feature36 > 94))
            result_gpr[2] &= ~(1 << 13);

        if (!(feature36 > 94))
            result_gpr[0] &= ~(1 << 28);

        if (!(feature36 > 94))
            result_gpr[0] &= ~(1 << 29);

        if (!(feature36 > 94))
            result_gpr[0] &= ~(1 << 27);

        if (!(feature36 > 94))
            result_gpr[6] &= ~(1 << 9);

        if (!(feature36 > 94))
            result_gpr[7] &= ~(1 << 7);

        if (!(feature36 > 94))
            result_gpr[3] &= ~(1 << 29);

        if (!(feature36 > 94))
            result_gpr[3] &= ~(1 << 30);

        if (!(feature36 > 94))
            result_gpr[6] &= ~(1 << 20);

        if (!(feature36 > 94))
            result_gpr[7] &= ~(1 << 21);

        if (!(feature36 > 94 && feature36 <= 119))
            result_gpr[7] &= ~(1 << 8);

        if (!(feature36 > 94 && feature36 > 119))
            result_gpr[7] &= ~(1 << 24);

        if (!(feature36 > 94 && feature36 > 119))
            result_gpr[1] &= ~(1 << 10);

        if (!(feature36 > 94 && feature36 > 119))
            result_gpr[1] &= ~(1 << 11);

        if (!(feature36 > 94 && feature36 > 119))
            result_gpr[4] &= ~(1 << 8);

        if (!(feature36 > 94 && feature36 > 119))
            result_gpr[7] &= ~(1 << 30);

        if (!(feature36 > 94 && feature36 > 119))
            result_gpr[6] &= ~(1 << 27);

        if (!(feature36 > 94 && feature36 > 119))
            result_gpr[6] &= ~(1 << 28);

        if (!(feature36 > 94))
            result_gpr[7] &= ~(1 << 20);

        if (!(feature36 > 94))
            result_gpr[5] &= ~(1 << 16);

        if (!(feature36 > 94))
            result_gpr[5] &= ~(1 << 17);

        if (!(feature36 > 94))
            result_gpr[3] &= ~(1 << 2);

        if (!(feature36 > 94))
            result_gpr[3] &= ~(1 << 3);

        if (!(feature36 > 94))
            result_gpr[3] &= ~(1 << 4);

        if (!(feature36 > 94 && feature36 <= 239))
            result_gpr[5] &= ~(1 << 19);

        if (!(feature36 > 94 && feature36 > 239))
            result_gpr[5] &= ~(1 << 20);

        if (!(feature36 > 94 && feature36 > 239))
            result_gpr[5] &= ~(1 << 21);

        if (!(feature36 > 94))
            result_gpr[3] &= ~(1 << 27);

        if (!(feature36 > 94))
            result_gpr[3] &= ~(1 << 28);

        if (!(feature36 > 94))
            result_gpr[6] &= ~(1 << 13);

        if (!(feature36 > 94))
            result_gpr[3] &= ~(1 << 12);

        if (!(feature36 > 94))
            result_gpr[3] &= ~(1 << 13);

        if (!(feature36 > 94))
            result_gpr[4] &= ~(1 << 10);

        if (!(feature36 > 94))
            result_gpr[4] &= ~(1 << 11);

        if (!(feature36 > 94))
            result_gpr[2] &= ~(1 << 14);

        if (!(feature36 > 94))
            result_gpr[2] &= ~(1 << 15);

        if (!(feature36 > 94))
            result_gpr[6] &= ~(1 << 31);
        
        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 0, 0, __xfer_reg_number(result_xfer13, __nfp_meid(36, 0)) + (__ctx() * 32), sizeof(result_xfer13), &local_signal);
    }

    return 0;
}


