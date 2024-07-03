#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal1;
__visible __xread uint32_t remote_xfer1[2];

__remote SIGNAL result_signal1;
__remote __xread uint32_t result_xfer1[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature1;
    __gpr uint32_t feature2;
    __gpr uint32_t feature3;
    __gpr uint32_t feature4;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal1, 1);
    __assign_relative_register(&local_signal, 2);
    __implicit_write(&remote_signal1, sizeof(remote_signal1));
    __implicit_write(remote_xfer1, sizeof(remote_xfer1));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal1);
        reg_cp(&feature1, remote_xfer1, sizeof(feature1));
        reg_cp(&feature2, remote_xfer1, sizeof(feature2));
        reg_cp(&feature3, remote_xfer1+1, sizeof(feature3));
        reg_cp(&feature4, remote_xfer1+1, sizeof(feature4));
        
        feature1 >>= 16;
        // Decision Tree Logic
        if (!(feature1 <= 373))
            result_gpr[1] &= ~(1 << 17);

        if (!(feature1 <= 373))
            result_gpr[1] &= ~(1 << 18);

        if (!(feature1 <= 373))
            result_gpr[1] &= ~(1 << 19);

        if (!(feature1 > 373))
            result_gpr[7] &= ~(1 << 28);

        if (!(feature1 <= 200))
            result_gpr[3] &= ~(1 << 7);

        if (!(feature1 > 200))
            result_gpr[3] &= ~(1 << 8);

        if (!(feature1 > 200))
            result_gpr[1] &= ~(1 << 22);

        if (!(feature1 > 200))
            result_gpr[1] &= ~(1 << 23);

        if (!(feature1 > 200))
            result_gpr[1] &= ~(1 << 24);

        if (!(feature1 <= 652))
            result_gpr[4] &= ~(1 << 10);

        if (!(feature1 > 652))
            result_gpr[4] &= ~(1 << 11);

        if (!(feature1 <= 514))
            result_gpr[3] &= ~(1 << 19);

        if (!(feature1 <= 514))
            result_gpr[3] &= ~(1 << 20);

        if (!(feature1 > 514))
            result_gpr[7] &= ~(1 << 12);

        
        feature2 &= 0xffff;
        // Decision Tree Logic
        if (!(feature2 <= 14))
            result_gpr[4] &= ~(1 << 24);

        if (!(feature2 <= 14))
            result_gpr[4] &= ~(1 << 25);

        if (!(feature2 <= 14))
            result_gpr[7] &= ~(1 << 26);

        if (!(feature2 <= 14))
            result_gpr[7] &= ~(1 << 27);

        if (!(feature2 <= 14))
            result_gpr[4] &= ~(1 << 12);

        if (!(feature2 <= 14))
            result_gpr[4] &= ~(1 << 13);

        if (!(feature2 <= 14))
            result_gpr[5] &= ~(1 << 7);

        if (!(feature2 <= 14))
            result_gpr[3] &= ~(1 << 18);

        if (!(feature2 <= 14))
            result_gpr[2] &= ~(1 << 20);

        if (!(feature2 <= 14))
            result_gpr[2] &= ~(1 << 21);

        if (!(feature2 <= 14))
            result_gpr[4] &= ~(1 << 31);

        if (!(feature2 > 14))
            result_gpr[7] &= ~(1 << 10);

        if (!(feature2 > 14))
            result_gpr[5] &= ~(1 << 3);

        if (!(feature2 > 14))
            result_gpr[5] &= ~(1 << 4);

        if (!(feature2 > 14))
            result_gpr[4] &= ~(1 << 6);

        if (!(feature2 > 14))
            result_gpr[4] &= ~(1 << 7);

        if (!(feature2 > 14))
            result_gpr[6] &= ~(1 << 29);

        if (!(feature2 > 14))
            result_gpr[2] &= ~(1 << 9);

        if (!(feature2 > 14))
            result_gpr[2] &= ~(1 << 10);

        if (!(feature2 > 14))
            result_gpr[5] &= ~(1 << 11);

        if (!(feature2 > 14))
            result_gpr[5] &= ~(1 << 12);

        if (!(feature2 > 14))
            result_gpr[7] &= ~(1 << 11);

        if (!(feature2 <= 8))
            result_gpr[0] &= ~(1 << 5);

        if (!(feature2 <= 8))
            result_gpr[0] &= ~(1 << 6);

        if (!(feature2 > 8))
            result_gpr[0] &= ~(1 << 7);

        if (!(feature2 > 8))
            result_gpr[0] &= ~(1 << 8);

        if (!(feature2 > 8))
            result_gpr[0] &= ~(1 << 9);

        if (!(feature2 <= 15))
            result_gpr[0] &= ~(1 << 28);

        if (!(feature2 > 15))
            result_gpr[0] &= ~(1 << 29);
        
        
        feature3 >>= 16;
        // Decision Tree Logic
        if (!(feature3 <= 63))
            result_gpr[3] &= ~(1 << 31);

        if (!(feature3 <= 63))
            result_gpr[2] &= ~(1 << 0);

        if (!(feature3 > 63))
            result_gpr[5] &= ~(1 << 10);

        if (!(feature3 <= 4))
            result_gpr[0] &= ~(1 << 14);

        if (!(feature3 <= 4))
            result_gpr[0] &= ~(1 << 15);

        if (!(feature3 > 4))
            result_gpr[0] &= ~(1 << 13);

        if (!(feature3 <= 189))
            result_gpr[4] &= ~(1 << 12);

        if (!(feature3 > 189))
            result_gpr[4] &= ~(1 << 13);
        
        
        feature4 &= 0xffff;
        // Decision Tree Logic
        if (!(feature4 <= 129))
            result_gpr[7] &= ~(1 << 26);

        if (!(feature4 > 129))
            result_gpr[7] &= ~(1 << 27);
        
        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 9, 0, __xfer_reg_number(result_xfer1, __nfp_meid(35, 9)) + (__ctx() * 32), sizeof(result_xfer1), &local_signal);
    }

    return 0;
}


