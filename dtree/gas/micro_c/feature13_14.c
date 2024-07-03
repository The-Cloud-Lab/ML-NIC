#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal5;
__visible __xread uint32_t remote_xfer5;

__remote SIGNAL result_signal5;
__remote __xread uint32_t result_xfer5[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature13;
    __gpr uint32_t feature14;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal5, 1);
    __assign_relative_register(&local_signal, 2);
    __implicit_write(&remote_signal5, sizeof(remote_signal5));
    __implicit_write(&remote_xfer5, sizeof(remote_xfer5));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal5);
        reg_cp(&feature13, &remote_xfer5, sizeof(feature13));
        reg_cp(&feature14, &remote_xfer5, sizeof(feature14));
        
        feature13 >>= 16;
        // Decision Tree Logic
        if (!(feature13 <= 778))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature13 <= 778))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature13 <= 778))
            result_gpr[1] &= ~(1 << 0);

        if (!(feature13 <= 778))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature13 <= 778))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature13 <= 778))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature13 <= 778))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature13 <= 778))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature13 <= 778))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature13 <= 778))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature13 <= 778))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature13 <= 778))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature13 <= 778))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature13 <= 778))
            result_gpr[2] &= ~(1 << 24);

        if (!(feature13 <= 778))
            result_gpr[2] &= ~(1 << 25);

        if (!(feature13 <= 778))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature13 <= 778))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature13 <= 778))
            result_gpr[5] &= ~(1 << 31);

        if (!(feature13 <= 778))
            result_gpr[5] &= ~(1 << 9);

        if (!(feature13 <= 778))
            result_gpr[6] &= ~(1 << 10);

        if (!(feature13 > 778))
            result_gpr[5] &= ~(1 << 23);

        if (!(feature13 > 778))
            result_gpr[5] &= ~(1 << 24);


        
        feature14 &= 0xffff;
        // Decision Tree Logic
        if (!(feature14 <= 6643))
            result_gpr[0] &= ~(1 << 30);

        if (!(feature14 <= 6643))
            result_gpr[0] &= ~(1 << 31);

        if (!(feature14 > 6643))
            result_gpr[0] &= ~(1 << 5);

        if (!(feature14 > 6643))
            result_gpr[0] &= ~(1 << 6);

        if (!(feature14 > 6643))
            result_gpr[0] &= ~(1 << 7);

        if (!(feature14 > 6643))
            result_gpr[0] &= ~(1 << 8);

        if (!(feature14 > 6643))
            result_gpr[0] &= ~(1 << 9);

        if (!(feature14 > 6643))
            result_gpr[0] &= ~(1 << 4);

        if (!(feature14 <= 7769))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature14 <= 7769))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature14 <= 7769))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature14 <= 7769))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature14 <= 7769))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature14 <= 7769))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature14 <= 7769))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature14 <= 7769))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature14 > 7769))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature14 > 7769))
            result_gpr[1] &= ~(1 << 27);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 10, 0, __xfer_reg_number(result_xfer5, __nfp_meid(35, 10)) + (__ctx() * 32), sizeof(result_xfer5), &local_signal);
    }

    return 0;
}


