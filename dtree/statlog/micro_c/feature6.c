#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal6;
__visible __xread uint32_t remote_xfer6;

__remote SIGNAL result_signal6;
__remote __xread uint32_t result_xfer6[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal6, 1);
    __assign_relative_register(&local_signal, 3);
    __implicit_write(&remote_signal6, sizeof(remote_signal6));
    __implicit_write(&remote_xfer6, sizeof(remote_xfer6));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal6);
        reg_cp(&feature, &remote_xfer6, sizeof(feature));
        feature &= 0xffff;
   
        // Decision Tree Logic
        if (!(feature <= 3500))
            result_gpr[5] &= ~(1 << 16);

        if (!(feature <= 3500))
            result_gpr[5] &= ~(1 << 17);

        if (!(feature > 3500))
            result_gpr[4] &= ~(1 << 11);

        if (!(feature > 3500))
            result_gpr[4] &= ~(1 << 12);

        if (!(feature > 3500))
            result_gpr[7] &= ~(1 << 27);

        if (!(feature <= 4022))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature > 4022))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature <= 3798))
            result_gpr[3] &= ~(1 << 14);

        if (!(feature <= 3798))
            result_gpr[3] &= ~(1 << 15);

        if (!(feature > 3798))
            result_gpr[6] &= ~(1 << 7);

        if (!(feature <= 1638))
            result_gpr[7] &= ~(1 << 16);

        if (!(feature > 1638))
            result_gpr[2] &= ~(1 << 12);

        if (!(feature > 1638))
            result_gpr[2] &= ~(1 << 13);

        if (!(feature <= 4506))
            result_gpr[6] &= ~(1 << 31);

        if (!(feature <= 4506))
            result_gpr[5] &= ~(1 << 0);

        if (!(feature <= 4506))
            result_gpr[7] &= ~(1 << 13);

        if (!(feature > 4506))
            result_gpr[4] &= ~(1 << 25);

        if (!(feature > 4506))
            result_gpr[4] &= ~(1 << 26);

        if (!(feature <= 5250))
            result_gpr[5] &= ~(1 << 7);

        if (!(feature <= 5250))
            result_gpr[5] &= ~(1 << 8);

        if (!(feature > 5250))
            result_gpr[5] &= ~(1 << 9);

        if (!(feature > 5250))
            result_gpr[5] &= ~(1 << 10);

        if (!(feature <= 5623))
            result_gpr[4] &= ~(1 << 14);

        if (!(feature > 5623))
            result_gpr[4] &= ~(1 << 15);

        if (!(feature > 5623))
            result_gpr[4] &= ~(1 << 16);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 2, 0, __xfer_reg_number(result_xfer6, __nfp_meid(35, 2)) + (__ctx() * 32), sizeof(result_xfer6), &local_signal);
    }

    return 0;
}


