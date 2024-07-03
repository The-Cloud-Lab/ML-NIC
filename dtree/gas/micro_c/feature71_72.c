#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal23;
__visible __xread uint32_t remote_xfer23;

__remote SIGNAL result_signal23;
__remote __xread uint32_t result_xfer23[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature71;
    __gpr uint32_t feature72;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal23, 1);
    __assign_relative_register(&local_signal, 4);
    __implicit_write(&remote_signal23, sizeof(remote_signal23));
    __implicit_write(&remote_xfer23, sizeof(remote_xfer23));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal23);
        reg_cp(&feature71, &remote_xfer23, sizeof(feature71));
        reg_cp(&feature72, &remote_xfer23, sizeof(feature72));

        feature71 >>= 16;
        // Decision Tree Logic
        if (!(feature71 <= 7653))
            result_gpr[7] &= ~(1 << 24);

        if (!(feature71 > 7653))
            result_gpr[1] &= ~(1 << 10);

        if (!(feature71 > 7653))
            result_gpr[1] &= ~(1 << 11);

        if (!(feature71 > 7653))
            result_gpr[4] &= ~(1 << 8);

        if (!(feature71 <= 7739))
            result_gpr[1] &= ~(1 << 3);

        if (!(feature71 <= 7739))
            result_gpr[1] &= ~(1 << 8);

        if (!(feature71 <= 7739))
            result_gpr[1] &= ~(1 << 9);

        if (!(feature71 <= 7739))
            result_gpr[5] &= ~(1 << 18);

        if (!(feature71 <= 7739))
            result_gpr[7] &= ~(1 << 29);

        if (!(feature71 <= 7739))
            result_gpr[6] &= ~(1 << 12);

        if (!(feature71 <= 7739))
            result_gpr[5] &= ~(1 << 8);

        if (!(feature71 <= 7739))
            result_gpr[2] &= ~(1 << 26);

        if (!(feature71 <= 7739))
            result_gpr[2] &= ~(1 << 27);

        if (!(feature71 <= 7739))
            result_gpr[1] &= ~(1 << 1);

        if (!(feature71 <= 7739))
            result_gpr[1] &= ~(1 << 2);

        if (!(feature71 <= 7739))
            result_gpr[1] &= ~(1 << 20);

        if (!(feature71 <= 7739))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature71 <= 7739))
            result_gpr[0] &= ~(1 << 10);

        if (!(feature71 <= 7739))
            result_gpr[0] &= ~(1 << 11);

        if (!(feature71 <= 7739))
            result_gpr[0] &= ~(1 << 12);

        if (!(feature71 <= 7739))
            result_gpr[7] &= ~(1 << 31);

        if (!(feature71 <= 7739))
            result_gpr[6] &= ~(1 << 0);

        if (!(feature71 <= 7739))
            result_gpr[4] &= ~(1 << 14);

        if (!(feature71 <= 7739))
            result_gpr[4] &= ~(1 << 15);

        if (!(feature71 <= 7739))
            result_gpr[7] &= ~(1 << 3);

        if (!(feature71 <= 7739))
            result_gpr[5] &= ~(1 << 27);

        if (!(feature71 <= 7739))
            result_gpr[2] &= ~(1 << 11);

        if (!(feature71 <= 7739))
            result_gpr[1] &= ~(1 << 6);

        if (!(feature71 <= 7739))
            result_gpr[1] &= ~(1 << 7);

        if (!(feature71 <= 7739))
            result_gpr[5] &= ~(1 << 0);

        if (!(feature71 <= 7739))
            result_gpr[0] &= ~(1 << 19);

        if (!(feature71 <= 7739))
            result_gpr[0] &= ~(1 << 20);

        if (!(feature71 <= 7739))
            result_gpr[0] &= ~(1 << 18);

        if (!(feature71 > 7739))
            result_gpr[3] &= ~(1 << 19);

        if (!(feature71 > 7739))
            result_gpr[3] &= ~(1 << 20);

        if (!(feature71 > 7739))
            result_gpr[7] &= ~(1 << 12);


        feature72 &= 0xffff;
        // Decision Tree Logic
        if (!(feature72 <= 7477))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature72 <= 7477))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature72 <= 7477))
            result_gpr[1] &= ~(1 << 0);

        if (!(feature72 > 7477))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature72 > 7477))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature72 > 7477))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature72 > 7477))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature72 > 7477))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature72 > 7477))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature72 > 7477))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature72 > 7477))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature72 > 7477))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature72 > 7477))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature72 <= 7613))
            result_gpr[3] &= ~(1 << 29);

        if (!(feature72 <= 7613))
            result_gpr[3] &= ~(1 << 30);

        if (!(feature72 > 7613))
            result_gpr[6] &= ~(1 << 20);
        
        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 2, 0, __xfer_reg_number(result_xfer23, __nfp_meid(36, 2)) + (__ctx() * 32), sizeof(result_xfer23), &local_signal);
    }

    return 0;
}


