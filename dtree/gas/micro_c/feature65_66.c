#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal20;
__visible __xread uint32_t remote_xfer20;

__remote SIGNAL result_signal20;
__remote __xread uint32_t result_xfer20[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature65;
    __gpr uint32_t feature66;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal20, 1);
    __assign_relative_register(&local_signal, 5);
    __implicit_write(&remote_signal20, sizeof(remote_signal20));
    __implicit_write(&remote_xfer20, sizeof(remote_xfer20));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal20);
        reg_cp(&feature65, &remote_xfer20, sizeof(feature65));
        reg_cp(&feature66, &remote_xfer20, sizeof(feature66));
        
        feature65 >>= 16;
        // Decision Tree Logic
        if (!(feature65 <= 79))
            result_gpr[7] &= ~(1 << 18);

        if (!(feature65 > 79))
            result_gpr[3] &= ~(1 << 31);

        if (!(feature65 > 79))
            result_gpr[2] &= ~(1 << 0);

        if (!(feature65 > 79))
            result_gpr[5] &= ~(1 << 10);

        if (!(feature65 > 79))
            result_gpr[4] &= ~(1 << 22);

        if (!(feature65 > 79))
            result_gpr[4] &= ~(1 << 23);

        if (!(feature65 > 79))
            result_gpr[5] &= ~(1 << 14);

        if (!(feature65 > 79))
            result_gpr[5] &= ~(1 << 15);

        if (!(feature65 > 79))
            result_gpr[5] &= ~(1 << 13);

        if (!(feature65 > 79))
            result_gpr[5] &= ~(1 << 28);

        if (!(feature65 > 79))
            result_gpr[5] &= ~(1 << 29);

        if (!(feature65 > 79))
            result_gpr[0] &= ~(1 << 14);

        if (!(feature65 > 79))
            result_gpr[0] &= ~(1 << 15);

        if (!(feature65 > 79))
            result_gpr[0] &= ~(1 << 13);

        if (!(feature65 > 79))
            result_gpr[4] &= ~(1 << 9);

        if (!(feature65 <= 165))
            result_gpr[4] &= ~(1 << 24);

        if (!(feature65 <= 165))
            result_gpr[4] &= ~(1 << 25);

        if (!(feature65 <= 165))
            result_gpr[7] &= ~(1 << 26);

        if (!(feature65 <= 165))
            result_gpr[7] &= ~(1 << 27);

        if (!(feature65 > 165))
            result_gpr[4] &= ~(1 << 12);

        if (!(feature65 > 165))
            result_gpr[4] &= ~(1 << 13);

        if (!(feature65 > 165))
            result_gpr[5] &= ~(1 << 7);

        if (!(feature65 > 165))
            result_gpr[3] &= ~(1 << 18);

        if (!(feature65 > 165))
            result_gpr[2] &= ~(1 << 20);

        if (!(feature65 > 165))
            result_gpr[2] &= ~(1 << 21);

        if (!(feature65 > 165))
            result_gpr[4] &= ~(1 << 31);

        if (!(feature65 <= 2372))
            result_gpr[2] &= ~(1 << 1);

        if (!(feature65 > 2372))
            result_gpr[2] &= ~(1 << 2);


        feature66 &= 0xffff;
        // Decision Tree Logic
        if (!(feature66 <= 136))
            result_gpr[7] &= ~(1 << 10);

        if (!(feature66 > 136))
            result_gpr[5] &= ~(1 << 3);

        if (!(feature66 > 136))
            result_gpr[5] &= ~(1 << 4);

        if (!(feature66 > 136))
            result_gpr[4] &= ~(1 << 6);

        if (!(feature66 > 136))
            result_gpr[4] &= ~(1 << 7);

        if (!(feature66 > 136))
            result_gpr[6] &= ~(1 << 29);

        if (!(feature66 <= 97))
            result_gpr[4] &= ~(1 << 21);

        if (!(feature66 > 97))
            result_gpr[0] &= ~(1 << 24);

        if (!(feature66 > 97))
            result_gpr[0] &= ~(1 << 25);

        if (!(feature66 > 97))
            result_gpr[0] &= ~(1 << 26);

        if (!(feature66 > 97))
            result_gpr[2] &= ~(1 << 5);

        if (!(feature66 > 97))
            result_gpr[2] &= ~(1 << 6);

        if (!(feature66 <= 566))
            result_gpr[6] &= ~(1 << 16);

        if (!(feature66 > 566))
            result_gpr[6] &= ~(1 << 17);

        if (!(feature66 <= 310))
            result_gpr[1] &= ~(1 << 8);

        if (!(feature66 > 310))
            result_gpr[1] &= ~(1 << 9);
        
        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 1, 0, __xfer_reg_number(result_xfer20, __nfp_meid(36, 1)) + (__ctx() * 32), sizeof(result_xfer20), &local_signal);
    }

    return 0;
}


