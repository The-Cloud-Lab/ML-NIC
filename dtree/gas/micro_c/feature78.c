#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal27;
__visible __xread uint32_t remote_xfer27;

__remote SIGNAL result_signal27;
__remote __xread uint32_t result_xfer27[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature78;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal27, 1);
    __assign_relative_register(&local_signal, 4);
    __implicit_write(&remote_signal27, sizeof(remote_signal27));
    __implicit_write(&remote_xfer27, sizeof(remote_xfer27));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal27);
        reg_cp(&feature78, &remote_xfer27, sizeof(feature78));
        
        feature78 &= 0xffff;
        // Decision Tree Logic
        if (!(feature78 <= 7812))
            result_gpr[7] &= ~(1 << 23);

        if (!(feature78 <= 7812))
            result_gpr[6] &= ~(1 << 25);

        if (!(feature78 <= 7812))
            result_gpr[6] &= ~(1 << 26);

        if (!(feature78 <= 7812))
            result_gpr[3] &= ~(1 << 7);

        if (!(feature78 <= 7812))
            result_gpr[3] &= ~(1 << 8);

        if (!(feature78 <= 7812))
            result_gpr[1] &= ~(1 << 22);

        if (!(feature78 <= 7812))
            result_gpr[1] &= ~(1 << 23);

        if (!(feature78 <= 7812))
            result_gpr[1] &= ~(1 << 24);

        if (!(feature78 <= 7812))
            result_gpr[3] &= ~(1 << 6);

        if (!(feature78 <= 7812))
            result_gpr[3] &= ~(1 << 5);

        if (!(feature78 <= 7812))
            result_gpr[6] &= ~(1 << 14);

        if (!(feature78 <= 7812))
            result_gpr[6] &= ~(1 << 15);

        if (!(feature78 <= 7812))
            result_gpr[6] &= ~(1 << 4);

        if (!(feature78 <= 7812))
            result_gpr[6] &= ~(1 << 5);

        if (!(feature78 <= 7812))
            result_gpr[3] &= ~(1 << 25);

        if (!(feature78 <= 7812))
            result_gpr[3] &= ~(1 << 26);

        if (!(feature78 <= 7812 && feature78 <= 7461))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature78 <= 7812 && feature78 > 7461))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature78 <= 7812 && feature78 > 7461))
            result_gpr[1] &= ~(1 << 0);

        if (!(feature78 <= 7812))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature78 <= 7812))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature78 <= 7812))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature78 <= 7812))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature78 <= 7812))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature78 <= 7812))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature78 <= 7812))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature78 <= 7812))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature78 <= 7812))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature78 <= 7812))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature78 <= 7812))
            result_gpr[2] &= ~(1 << 24);

        if (!(feature78 <= 7812))
            result_gpr[2] &= ~(1 << 25);

        if (!(feature78 <= 7812))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature78 <= 7812))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature78 <= 7812))
            result_gpr[5] &= ~(1 << 31);

        if (!(feature78 <= 7812))
            result_gpr[5] &= ~(1 << 9);

        if (!(feature78 <= 7812))
            result_gpr[6] &= ~(1 << 10);

        if (!(feature78 <= 7812))
            result_gpr[5] &= ~(1 << 23);

        if (!(feature78 <= 7812))
            result_gpr[5] &= ~(1 << 24);

        if (!(feature78 <= 7812))
            result_gpr[3] &= ~(1 << 0);

        if (!(feature78 <= 7812))
            result_gpr[3] &= ~(1 << 1);

        if (!(feature78 <= 7812))
            result_gpr[7] &= ~(1 << 13);

        if (!(feature78 <= 7812))
            result_gpr[7] &= ~(1 << 14);

        if (!(feature78 <= 7812))
            result_gpr[3] &= ~(1 << 16);

        if (!(feature78 <= 7812))
            result_gpr[3] &= ~(1 << 17);

        if (!(feature78 <= 7812))
            result_gpr[6] &= ~(1 << 21);

        if (!(feature78 <= 7812))
            result_gpr[6] &= ~(1 << 22);

        if (!(feature78 <= 7812))
            result_gpr[6] &= ~(1 << 2);

        if (!(feature78 <= 7812))
            result_gpr[6] &= ~(1 << 19);

        if (!(feature78 <= 7812))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature78 <= 7812))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature78 <= 7812))
            result_gpr[0] &= ~(1 << 0);

        if (!(feature78 <= 7812))
            result_gpr[4] &= ~(1 << 26);

        if (!(feature78 <= 7812))
            result_gpr[4] &= ~(1 << 0);

        if (!(feature78 <= 7812))
            result_gpr[4] &= ~(1 << 1);

        if (!(feature78 <= 7812))
            result_gpr[2] &= ~(1 << 16);

        if (!(feature78 <= 7812))
            result_gpr[2] &= ~(1 << 17);

        if (!(feature78 <= 7812))
            result_gpr[6] &= ~(1 << 11);

        if (!(feature78 <= 7812))
            result_gpr[6] &= ~(1 << 30);

        if (!(feature78 <= 7812))
            result_gpr[2] &= ~(1 << 7);

        if (!(feature78 <= 7812))
            result_gpr[2] &= ~(1 << 8);

        if (!(feature78 > 7812))
            result_gpr[3] &= ~(1 << 21);

        if (!(feature78 > 7812))
            result_gpr[3] &= ~(1 << 22);

        if (!(feature78 > 7812))
            result_gpr[7] &= ~(1 << 17);

        if (!(feature78 > 7812))
            result_gpr[7] &= ~(1 << 4);

        if (!(feature78 > 7812))
            result_gpr[5] &= ~(1 << 30);

        if (!(feature78 > 7812))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature78 > 7812))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature78 > 7812))
            result_gpr[1] &= ~(1 << 15);

        if (!(feature78 > 7812))
            result_gpr[1] &= ~(1 << 16);

        if (!(feature78 > 7812))
            result_gpr[1] &= ~(1 << 14);

        if (!(feature78 > 7812))
            result_gpr[4] &= ~(1 << 18);

        if (!(feature78 > 7812))
            result_gpr[2] &= ~(1 << 12);

        if (!(feature78 > 7812))
            result_gpr[2] &= ~(1 << 13);

        if (!(feature78 > 7812))
            result_gpr[0] &= ~(1 << 28);

        if (!(feature78 > 7812))
            result_gpr[0] &= ~(1 << 29);

        if (!(feature78 > 7812))
            result_gpr[0] &= ~(1 << 27);

        if (!(feature78 > 7812))
            result_gpr[6] &= ~(1 << 9);

        if (!(feature78 > 7812))
            result_gpr[7] &= ~(1 << 7);

        if (!(feature78 > 7812))
            result_gpr[3] &= ~(1 << 29);

        if (!(feature78 > 7812))
            result_gpr[3] &= ~(1 << 30);

        if (!(feature78 > 7812))
            result_gpr[6] &= ~(1 << 20);

        if (!(feature78 > 7812))
            result_gpr[7] &= ~(1 << 21);

        if (!(feature78 > 7812))
            result_gpr[7] &= ~(1 << 8);

        if (!(feature78 > 7812))
            result_gpr[7] &= ~(1 << 24);

        if (!(feature78 > 7812))
            result_gpr[1] &= ~(1 << 10);

        if (!(feature78 > 7812))
            result_gpr[1] &= ~(1 << 11);

        if (!(feature78 > 7812))
            result_gpr[4] &= ~(1 << 8);

        if (!(feature78 > 7812))
            result_gpr[7] &= ~(1 << 30);

        if (!(feature78 > 7812))
            result_gpr[6] &= ~(1 << 27);

        if (!(feature78 > 7812))
            result_gpr[6] &= ~(1 << 28);

        if (!(feature78 > 7812 && feature78 <= 7919))
            result_gpr[7] &= ~(1 << 20);

        if (!(feature78 > 7812 && feature78 <= 7919))
            result_gpr[5] &= ~(1 << 16);

        if (!(feature78 > 7812 && feature78 <= 7919))
            result_gpr[5] &= ~(1 << 17);

        if (!(feature78 > 7812 && feature78 > 7919))
            result_gpr[3] &= ~(1 << 2);

        if (!(feature78 > 7812 && feature78 > 7919))
            result_gpr[3] &= ~(1 << 3);

        if (!(feature78 > 7812 && feature78 > 7919))
            result_gpr[3] &= ~(1 << 4);

        if (!(feature78 > 7812))
            result_gpr[5] &= ~(1 << 19);

        if (!(feature78 > 7812))
            result_gpr[5] &= ~(1 << 20);

        if (!(feature78 > 7812))
            result_gpr[5] &= ~(1 << 21);

        if (!(feature78 > 7812))
            result_gpr[3] &= ~(1 << 27);

        if (!(feature78 > 7812))
            result_gpr[3] &= ~(1 << 28);

        if (!(feature78 > 7812))
            result_gpr[6] &= ~(1 << 13);

        if (!(feature78 > 7812))
            result_gpr[3] &= ~(1 << 12);

        if (!(feature78 > 7812))
            result_gpr[3] &= ~(1 << 13);

        if (!(feature78 > 7812))
            result_gpr[4] &= ~(1 << 10);

        if (!(feature78 > 7812))
            result_gpr[4] &= ~(1 << 11);

        if (!(feature78 > 7812))
            result_gpr[2] &= ~(1 << 14);

        if (!(feature78 > 7812))
            result_gpr[2] &= ~(1 << 15);

        if (!(feature78 > 7812))
            result_gpr[6] &= ~(1 << 31);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 3, 0, __xfer_reg_number(result_xfer27, __nfp_meid(36, 3)) + (__ctx() * 32), sizeof(result_xfer27), &local_signal);
    }

    return 0;
}


