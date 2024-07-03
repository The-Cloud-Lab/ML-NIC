#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal26;
__visible __xread uint32_t remote_xfer26[2];

__remote SIGNAL result_signal26;
__remote __xread uint32_t result_xfer26[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature77;
    __gpr uint32_t feature79;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal26, 1);
    __assign_relative_register(&local_signal, 3);
    __implicit_write(&remote_signal26, sizeof(remote_signal26));
    __implicit_write(&remote_xfer26, sizeof(remote_xfer26));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal26);
        reg_cp(&feature77, remote_xfer26, sizeof(feature77));
        reg_cp(&feature79, remote_xfer26+1, sizeof(feature79));
        
        feature77 >>= 16;
        // Decision Tree Logic
        if (!(feature77 <= 201))
            result_gpr[5] &= ~(1 << 3);

        if (!(feature77 > 201))
            result_gpr[5] &= ~(1 << 4);

        if (!(feature77 <= 685))
            result_gpr[7] &= ~(1 << 23);

        if (!(feature77 <= 685))
            result_gpr[6] &= ~(1 << 25);

        if (!(feature77 <= 685))
            result_gpr[6] &= ~(1 << 26);

        if (!(feature77 <= 685))
            result_gpr[3] &= ~(1 << 7);

        if (!(feature77 <= 685))
            result_gpr[3] &= ~(1 << 8);

        if (!(feature77 <= 685))
            result_gpr[1] &= ~(1 << 22);

        if (!(feature77 <= 685))
            result_gpr[1] &= ~(1 << 23);

        if (!(feature77 <= 685))
            result_gpr[1] &= ~(1 << 24);

        if (!(feature77 <= 685))
            result_gpr[3] &= ~(1 << 6);

        if (!(feature77 <= 685))
            result_gpr[3] &= ~(1 << 5);

        if (!(feature77 <= 685))
            result_gpr[6] &= ~(1 << 14);

        if (!(feature77 <= 685))
            result_gpr[6] &= ~(1 << 15);

        if (!(feature77 <= 685))
            result_gpr[6] &= ~(1 << 4);

        if (!(feature77 <= 685))
            result_gpr[6] &= ~(1 << 5);

        if (!(feature77 <= 685))
            result_gpr[3] &= ~(1 << 25);

        if (!(feature77 <= 685))
            result_gpr[3] &= ~(1 << 26);

        if (!(feature77 <= 685))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature77 <= 685 && feature77 <= 452))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature77 <= 685 && feature77 > 452))
            result_gpr[1] &= ~(1 << 0);

        if (!(feature77 <= 685))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature77 <= 685))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature77 <= 685))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature77 <= 685))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature77 <= 685))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature77 <= 685))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature77 <= 685))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature77 <= 685))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature77 <= 685))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature77 <= 685))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature77 <= 685))
            result_gpr[2] &= ~(1 << 24);

        if (!(feature77 <= 685))
            result_gpr[2] &= ~(1 << 25);

        if (!(feature77 <= 685))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature77 <= 685))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature77 <= 685))
            result_gpr[5] &= ~(1 << 31);

        if (!(feature77 <= 685))
            result_gpr[5] &= ~(1 << 9);

        if (!(feature77 <= 685))
            result_gpr[6] &= ~(1 << 10);

        if (!(feature77 <= 685))
            result_gpr[5] &= ~(1 << 23);

        if (!(feature77 <= 685))
            result_gpr[5] &= ~(1 << 24);

        if (!(feature77 <= 685))
            result_gpr[3] &= ~(1 << 0);

        if (!(feature77 <= 685))
            result_gpr[3] &= ~(1 << 1);

        if (!(feature77 <= 685))
            result_gpr[7] &= ~(1 << 13);

        if (!(feature77 <= 685))
            result_gpr[7] &= ~(1 << 14);

        if (!(feature77 > 685))
            result_gpr[3] &= ~(1 << 16);

        if (!(feature77 > 685))
            result_gpr[3] &= ~(1 << 17);

        if (!(feature77 > 685))
            result_gpr[6] &= ~(1 << 21);

        if (!(feature77 > 685))
            result_gpr[6] &= ~(1 << 22);

        if (!(feature77 > 685))
            result_gpr[6] &= ~(1 << 2);

        if (!(feature77 > 685))
            result_gpr[6] &= ~(1 << 19);

        if (!(feature77 > 685))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature77 > 685))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature77 > 685))
            result_gpr[0] &= ~(1 << 0);

        if (!(feature77 > 685))
            result_gpr[4] &= ~(1 << 26);

        if (!(feature77 > 685))
            result_gpr[4] &= ~(1 << 0);

        if (!(feature77 > 685))
            result_gpr[4] &= ~(1 << 1);

        if (!(feature77 > 685))
            result_gpr[2] &= ~(1 << 16);

        if (!(feature77 > 685))
            result_gpr[2] &= ~(1 << 17);

        if (!(feature77 > 685))
            result_gpr[6] &= ~(1 << 11);

        if (!(feature77 > 685))
            result_gpr[6] &= ~(1 << 30);

        if (!(feature77 > 685))
            result_gpr[2] &= ~(1 << 7);

        if (!(feature77 > 685))
            result_gpr[2] &= ~(1 << 8);

        if (!(feature77 <= 178))
            result_gpr[5] &= ~(1 << 30);

        if (!(feature77 <= 178))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature77 <= 178))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature77 > 178))
            result_gpr[1] &= ~(1 << 15);

        if (!(feature77 > 178))
            result_gpr[1] &= ~(1 << 16);

        if (!(feature77 > 178))
            result_gpr[1] &= ~(1 << 14);

        if (!(feature77 > 178))
            result_gpr[4] &= ~(1 << 18);

        if (!(feature77 > 178))
            result_gpr[2] &= ~(1 << 12);

        if (!(feature77 > 178))
            result_gpr[2] &= ~(1 << 13);

        if (!(feature77 <= 1042))
            result_gpr[7] &= ~(1 << 31);

        if (!(feature77 > 1042))
            result_gpr[6] &= ~(1 << 0);

        
        feature79 >>= 16;
        // Decision Tree Logic
        if (!(feature79 <= 7396))
            result_gpr[3] &= ~(1 << 7);

        if (!(feature79 <= 7396))
            result_gpr[3] &= ~(1 << 8);

        if (!(feature79 <= 7396))
            result_gpr[1] &= ~(1 << 22);

        if (!(feature79 <= 7396))
            result_gpr[1] &= ~(1 << 23);

        if (!(feature79 <= 7396))
            result_gpr[1] &= ~(1 << 24);

        if (!(feature79 > 7396))
            result_gpr[3] &= ~(1 << 6);
        
        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 3, 0, __xfer_reg_number(result_xfer26, __nfp_meid(36, 3)) + (__ctx() * 32), sizeof(result_xfer26), &local_signal);
    }

    return 0;
}


