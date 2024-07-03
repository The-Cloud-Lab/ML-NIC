#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal35;
__visible __xread uint32_t remote_xfer35;

__remote SIGNAL result_signal35;
__remote __xread uint32_t result_xfer35[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature101;
    __gpr uint32_t feature102;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal35, 1);
    __assign_relative_register(&local_signal, 4);
    __implicit_write(&remote_signal35, sizeof(remote_signal35));
    __implicit_write(&remote_xfer35, sizeof(remote_xfer35));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal35);
        reg_cp(&feature101, &remote_xfer35, sizeof(feature101));
        reg_cp(&feature102, &remote_xfer35, sizeof(feature102));

        feature101 >>= 16;
        // Decision Tree Logic
        if (!(feature101 <= 349))
            result_gpr[7] &= ~(1 << 6);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 9);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 10);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 11);

        if (!(feature101 <= 349))
            result_gpr[2] &= ~(1 << 18);

        if (!(feature101 <= 349))
            result_gpr[2] &= ~(1 << 19);

        if (!(feature101 <= 349))
            result_gpr[4] &= ~(1 << 19);

        if (!(feature101 <= 349))
            result_gpr[4] &= ~(1 << 21);

        if (!(feature101 <= 349))
            result_gpr[0] &= ~(1 << 24);

        if (!(feature101 <= 349))
            result_gpr[0] &= ~(1 << 25);

        if (!(feature101 <= 349))
            result_gpr[0] &= ~(1 << 26);

        if (!(feature101 <= 349))
            result_gpr[2] &= ~(1 << 5);

        if (!(feature101 <= 349))
            result_gpr[2] &= ~(1 << 6);

        if (!(feature101 <= 349))
            result_gpr[4] &= ~(1 << 20);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 23);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 24);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 16);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 17);

        if (!(feature101 <= 349))
            result_gpr[7] &= ~(1 << 23);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 25);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 26);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 7);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 8);

        if (!(feature101 <= 349))
            result_gpr[1] &= ~(1 << 22);

        if (!(feature101 <= 349))
            result_gpr[1] &= ~(1 << 23);

        if (!(feature101 <= 349))
            result_gpr[1] &= ~(1 << 24);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 6);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 5);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 14);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 15);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 4);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 5);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 25);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 26);

        if (!(feature101 <= 349))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature101 <= 349))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature101 <= 349))
            result_gpr[1] &= ~(1 << 0);

        if (!(feature101 <= 349))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature101 <= 349))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature101 <= 349))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature101 <= 349))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature101 <= 349))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature101 <= 349))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature101 <= 349))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature101 <= 349))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature101 <= 349))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature101 <= 349))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature101 <= 349))
            result_gpr[2] &= ~(1 << 24);

        if (!(feature101 <= 349))
            result_gpr[2] &= ~(1 << 25);

        if (!(feature101 <= 349))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature101 <= 349))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature101 <= 349))
            result_gpr[5] &= ~(1 << 31);

        if (!(feature101 <= 349))
            result_gpr[5] &= ~(1 << 9);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 10);

        if (!(feature101 <= 349))
            result_gpr[5] &= ~(1 << 23);

        if (!(feature101 <= 349))
            result_gpr[5] &= ~(1 << 24);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 0);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 1);

        if (!(feature101 <= 349))
            result_gpr[7] &= ~(1 << 13);

        if (!(feature101 <= 349))
            result_gpr[7] &= ~(1 << 14);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 16);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 17);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 21);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 22);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 2);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 19);

        if (!(feature101 <= 349))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature101 <= 349))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature101 <= 349))
            result_gpr[0] &= ~(1 << 0);

        if (!(feature101 <= 349))
            result_gpr[4] &= ~(1 << 26);

        if (!(feature101 <= 349))
            result_gpr[4] &= ~(1 << 0);

        if (!(feature101 <= 349))
            result_gpr[4] &= ~(1 << 1);

        if (!(feature101 <= 349))
            result_gpr[2] &= ~(1 << 16);

        if (!(feature101 <= 349))
            result_gpr[2] &= ~(1 << 17);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 11);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 30);

        if (!(feature101 <= 349))
            result_gpr[2] &= ~(1 << 7);

        if (!(feature101 <= 349))
            result_gpr[2] &= ~(1 << 8);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 21);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 22);

        if (!(feature101 <= 349))
            result_gpr[7] &= ~(1 << 17);

        if (!(feature101 <= 349))
            result_gpr[7] &= ~(1 << 4);

        if (!(feature101 <= 349))
            result_gpr[5] &= ~(1 << 30);

        if (!(feature101 <= 349))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature101 <= 349))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature101 <= 349))
            result_gpr[1] &= ~(1 << 15);

        if (!(feature101 <= 349))
            result_gpr[1] &= ~(1 << 16);

        if (!(feature101 <= 349))
            result_gpr[1] &= ~(1 << 14);

        if (!(feature101 <= 349))
            result_gpr[4] &= ~(1 << 18);

        if (!(feature101 <= 349))
            result_gpr[2] &= ~(1 << 12);

        if (!(feature101 <= 349))
            result_gpr[2] &= ~(1 << 13);

        if (!(feature101 <= 349))
            result_gpr[0] &= ~(1 << 28);

        if (!(feature101 <= 349))
            result_gpr[0] &= ~(1 << 29);

        if (!(feature101 <= 349))
            result_gpr[0] &= ~(1 << 27);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 9);

        if (!(feature101 <= 349))
            result_gpr[7] &= ~(1 << 7);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 29);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 30);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 20);

        if (!(feature101 <= 349))
            result_gpr[7] &= ~(1 << 21);

        if (!(feature101 <= 349))
            result_gpr[7] &= ~(1 << 8);

        if (!(feature101 <= 349))
            result_gpr[7] &= ~(1 << 24);

        if (!(feature101 <= 349))
            result_gpr[1] &= ~(1 << 10);

        if (!(feature101 <= 349))
            result_gpr[1] &= ~(1 << 11);

        if (!(feature101 <= 349))
            result_gpr[4] &= ~(1 << 8);

        if (!(feature101 <= 349))
            result_gpr[7] &= ~(1 << 30);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 27);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 28);

        if (!(feature101 <= 349))
            result_gpr[7] &= ~(1 << 20);

        if (!(feature101 <= 349))
            result_gpr[5] &= ~(1 << 16);

        if (!(feature101 <= 349))
            result_gpr[5] &= ~(1 << 17);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 2);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 3);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 4);

        if (!(feature101 <= 349))
            result_gpr[5] &= ~(1 << 19);

        if (!(feature101 <= 349))
            result_gpr[5] &= ~(1 << 20);

        if (!(feature101 <= 349))
            result_gpr[5] &= ~(1 << 21);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 27);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 28);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 13);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 12);

        if (!(feature101 <= 349))
            result_gpr[3] &= ~(1 << 13);

        if (!(feature101 <= 349))
            result_gpr[4] &= ~(1 << 10);

        if (!(feature101 <= 349))
            result_gpr[4] &= ~(1 << 11);

        if (!(feature101 <= 349))
            result_gpr[2] &= ~(1 << 14);

        if (!(feature101 <= 349))
            result_gpr[2] &= ~(1 << 15);

        if (!(feature101 <= 349))
            result_gpr[6] &= ~(1 << 31);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[1] &= ~(1 << 3);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[1] &= ~(1 << 8);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[1] &= ~(1 << 9);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[5] &= ~(1 << 18);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[7] &= ~(1 << 29);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[6] &= ~(1 << 12);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[5] &= ~(1 << 8);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[2] &= ~(1 << 26);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[2] &= ~(1 << 27);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[1] &= ~(1 << 1);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[1] &= ~(1 << 2);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[1] &= ~(1 << 20);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[0] &= ~(1 << 10);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[0] &= ~(1 << 11);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[0] &= ~(1 << 12);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[7] &= ~(1 << 31);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[6] &= ~(1 << 0);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[4] &= ~(1 << 14);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[4] &= ~(1 << 15);

        if (!(feature101 > 349 && feature101 <= 466))
            result_gpr[7] &= ~(1 << 3);

        if (!(feature101 > 349 && feature101 > 466))
            result_gpr[5] &= ~(1 << 27);

        if (!(feature101 > 349 && feature101 > 466))
            result_gpr[2] &= ~(1 << 11);

        if (!(feature101 > 349 && feature101 > 466))
            result_gpr[1] &= ~(1 << 6);

        if (!(feature101 > 349 && feature101 > 466))
            result_gpr[1] &= ~(1 << 7);

        if (!(feature101 > 349 && feature101 > 466))
            result_gpr[5] &= ~(1 << 0);

        if (!(feature101 > 349 && feature101 > 466))
            result_gpr[0] &= ~(1 << 19);

        if (!(feature101 > 349 && feature101 > 466))
            result_gpr[0] &= ~(1 << 20);

        if (!(feature101 > 349 && feature101 > 466))
            result_gpr[0] &= ~(1 << 18);

        if (!(feature101 > 349))
            result_gpr[3] &= ~(1 << 19);

        if (!(feature101 > 349))
            result_gpr[3] &= ~(1 << 20);

        if (!(feature101 > 349))
            result_gpr[7] &= ~(1 << 12);

        if (!(feature101 > 349))
            result_gpr[7] &= ~(1 << 2);

        if (!(feature101 > 349))
            result_gpr[7] &= ~(1 << 19);

        if (!(feature101 > 349))
            result_gpr[1] &= ~(1 << 12);

        if (!(feature101 > 349))
            result_gpr[1] &= ~(1 << 13);

        if (!(feature101 > 349))
            result_gpr[4] &= ~(1 << 2);
        
        
        feature102 &= 0xffff;
        // Decision Tree Logic
        if (!(feature102 <= 7936))
            result_gpr[1] &= ~(1 << 18);

        if (!(feature102 > 7936))
            result_gpr[1] &= ~(1 << 19);

        if (!(feature102 <= 7580))
            result_gpr[1] &= ~(1 << 15);

        if (!(feature102 > 7580))
            result_gpr[1] &= ~(1 << 16);
        

        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 5, 0, __xfer_reg_number(result_xfer35, __nfp_meid(36, 5)) + (__ctx() * 32), sizeof(result_xfer35), &local_signal);
    }

    return 0;
}


