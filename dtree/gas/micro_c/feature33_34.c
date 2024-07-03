#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal12;
__visible __xread uint32_t remote_xfer12;

__remote SIGNAL result_signal12;
__remote __xread uint32_t result_xfer12[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature33;
    __gpr uint32_t feature34;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal12, 1);
    __assign_relative_register(&local_signal, 5);
    __implicit_write(&remote_signal12, sizeof(remote_signal12));
    __implicit_write(&remote_xfer12, sizeof(remote_xfer12));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal12);
        reg_cp(&feature33, &remote_xfer12, sizeof(feature33));
        reg_cp(&feature34, &remote_xfer12, sizeof(feature34));        
        
        feature33 >>= 16;
        // Decision Tree Logic
        if (!(feature33 <= 1065))
            result_gpr[4] &= ~(1 << 29);

        if (!(feature33 <= 1065))
            result_gpr[4] &= ~(1 << 30);

        if (!(feature33 <= 1065))
            result_gpr[4] &= ~(1 << 5);

        if (!(feature33 <= 1065))
            result_gpr[2] &= ~(1 << 22);

        if (!(feature33 <= 1065))
            result_gpr[2] &= ~(1 << 23);

        if (!(feature33 <= 1065))
            result_gpr[6] &= ~(1 << 18);

        if (!(feature33 <= 1065))
            result_gpr[4] &= ~(1 << 16);

        if (!(feature33 <= 1065))
            result_gpr[4] &= ~(1 << 17);

        if (!(feature33 > 1065))
            result_gpr[1] &= ~(1 << 17);

        if (!(feature33 > 1065))
            result_gpr[1] &= ~(1 << 18);

        if (!(feature33 > 1065))
            result_gpr[1] &= ~(1 << 19);

        if (!(feature33 > 1065))
            result_gpr[7] &= ~(1 << 28);

        if (!(feature33 <= 2113))
            result_gpr[0] &= ~(1 << 30);

        if (!(feature33 > 2113))
            result_gpr[0] &= ~(1 << 31);

        if (!(feature33 <= 3298))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature33 > 3298))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature33 <= 846))
            result_gpr[3] &= ~(1 << 21);

        if (!(feature33 <= 846))
            result_gpr[3] &= ~(1 << 22);

        if (!(feature33 > 846))
            result_gpr[7] &= ~(1 << 17);

        
        feature34 &= 0xffff;
        // Decision Tree Logic
        if (!(feature34 <= 29))
            result_gpr[2] &= ~(1 << 9);

        if (!(feature34 <= 29))
            result_gpr[2] &= ~(1 << 10);

        if (!(feature34 > 29))
            result_gpr[5] &= ~(1 << 11);

        if (!(feature34 > 29))
            result_gpr[5] &= ~(1 << 12);

        if (!(feature34 <= 82))
            result_gpr[6] &= ~(1 << 4);

        if (!(feature34 <= 82))
            result_gpr[6] &= ~(1 << 5);

        if (!(feature34 <= 82))
            result_gpr[3] &= ~(1 << 25);

        if (!(feature34 <= 82))
            result_gpr[3] &= ~(1 << 26);

        if (!(feature34 <= 82))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature34 <= 82))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature34 <= 82))
            result_gpr[1] &= ~(1 << 0);

        if (!(feature34 <= 82))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature34 <= 82))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature34 <= 82))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature34 <= 82))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature34 <= 82))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature34 <= 82))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature34 <= 82))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature34 <= 82))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature34 <= 82 && feature34 <= 36))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature34 <= 82 && feature34 > 36))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature34 <= 82))
            result_gpr[2] &= ~(1 << 24);

        if (!(feature34 <= 82))
            result_gpr[2] &= ~(1 << 25);

        if (!(feature34 <= 82))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature34 <= 82))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature34 <= 82))
            result_gpr[5] &= ~(1 << 31);

        if (!(feature34 <= 82))
            result_gpr[5] &= ~(1 << 9);

        if (!(feature34 <= 82))
            result_gpr[6] &= ~(1 << 10);

        if (!(feature34 <= 82))
            result_gpr[5] &= ~(1 << 23);

        if (!(feature34 <= 82))
            result_gpr[5] &= ~(1 << 24);

        if (!(feature34 <= 82))
            result_gpr[3] &= ~(1 << 0);

        if (!(feature34 <= 82))
            result_gpr[3] &= ~(1 << 1);

        if (!(feature34 > 82))
            result_gpr[7] &= ~(1 << 13);

        if (!(feature34 > 82))
            result_gpr[7] &= ~(1 << 14);

        if (!(feature34 <= 57))
            result_gpr[7] &= ~(1 << 24);

        if (!(feature34 <= 57))
            result_gpr[1] &= ~(1 << 10);

        if (!(feature34 <= 57))
            result_gpr[1] &= ~(1 << 11);

        if (!(feature34 <= 57))
            result_gpr[4] &= ~(1 << 8);

        if (!(feature34 > 57))
            result_gpr[7] &= ~(1 << 30);

        if (!(feature34 > 57))
            result_gpr[6] &= ~(1 << 27);

        if (!(feature34 > 57))
            result_gpr[6] &= ~(1 << 28);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 11, 0, __xfer_reg_number(result_xfer12, __nfp_meid(35, 11)) + (__ctx() * 32), sizeof(result_xfer12), &local_signal);
    }

    return 0;
}


