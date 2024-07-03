#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal2;
__visible __xread uint32_t remote_xfer2[2];

__remote SIGNAL result_signal2;
__remote __xread uint32_t result_xfer2[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature5;
    __gpr uint32_t feature6;
    __gpr uint32_t feature7;
    __gpr uint32_t feature8;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal2, 1);
    __assign_relative_register(&local_signal, 3);
    __implicit_write(&remote_signal2, sizeof(remote_signal2));
    __implicit_write(remote_xfer2, sizeof(remote_xfer2));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal2);
        reg_cp(&feature5, remote_xfer2, sizeof(feature5));
        reg_cp(&feature6, remote_xfer2, sizeof(feature6));
        reg_cp(&feature7, remote_xfer2+1, sizeof(feature7));
        reg_cp(&feature8, remote_xfer2+1, sizeof(feature8));
        
        feature5 >>= 16;
        // Decision Tree Logic
        if (!(feature5 <= 17))
            result_gpr[5] &= ~(1 << 6);

        if (!(feature5 > 17))
            result_gpr[0] &= ~(1 << 30);

        if (!(feature5 > 17))
            result_gpr[0] &= ~(1 << 31);

        if (!(feature5 > 17))
            result_gpr[0] &= ~(1 << 5);

        if (!(feature5 > 17))
            result_gpr[0] &= ~(1 << 6);

        if (!(feature5 > 17))
            result_gpr[0] &= ~(1 << 7);

        if (!(feature5 > 17))
            result_gpr[0] &= ~(1 << 8);

        if (!(feature5 > 17))
            result_gpr[0] &= ~(1 << 9);

        if (!(feature5 > 17))
            result_gpr[0] &= ~(1 << 4);

        if (!(feature5 > 17))
            result_gpr[0] &= ~(1 << 2);

        if (!(feature5 > 17))
            result_gpr[0] &= ~(1 << 3);

        if (!(feature5 > 17))
            result_gpr[0] &= ~(1 << 1);

        
        feature6 &= 0xffff;
        // Decision Tree Logic
        if (!(feature6 <= 7717))
            result_gpr[7] &= ~(1 << 22);

        if (!(feature6 > 7717))
            result_gpr[5] &= ~(1 << 25);

        if (!(feature6 > 7717))
            result_gpr[5] &= ~(1 << 26);

        if (!(feature6 <= 3632))
            result_gpr[6] &= ~(1 << 3);

        if (!(feature6 > 3632))
            result_gpr[3] &= ~(1 << 23);

        if (!(feature6 > 3632))
            result_gpr[3] &= ~(1 << 24);

        if (!(feature6 <= 8192))
            result_gpr[1] &= ~(1 << 22);

        if (!(feature6 > 8192))
            result_gpr[1] &= ~(1 << 23);

        if (!(feature6 > 8192))
            result_gpr[1] &= ~(1 << 24);

        if (!(feature6 <= 5631))
            result_gpr[6] &= ~(1 << 19);

        if (!(feature6 > 5631 && feature6 <= 7855))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature6 > 5631 && feature6 <= 7855))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature6 > 5631 && feature6 <= 7855))
            result_gpr[0] &= ~(1 << 0);

        if (!(feature6 > 5631 && feature6 <= 7855))
            result_gpr[4] &= ~(1 << 26);

        if (!(feature6 > 5631 && feature6 <= 7855))
            result_gpr[4] &= ~(1 << 0);

        if (!(feature6 > 5631 && feature6 <= 7855))
            result_gpr[4] &= ~(1 << 1);

        if (!(feature6 > 5631 && feature6 > 7855))
            result_gpr[2] &= ~(1 << 16);

        if (!(feature6 > 5631 && feature6 > 7855))
            result_gpr[2] &= ~(1 << 17);

        if (!(feature6 <= 8023))
            result_gpr[5] &= ~(1 << 20);

        if (!(feature6 > 8023))
            result_gpr[5] &= ~(1 << 21);

        if (!(feature6 <= 8112))
            result_gpr[4] &= ~(1 << 10);

        if (!(feature6 <= 8112))
            result_gpr[4] &= ~(1 << 11);

        if (!(feature6 > 8112))
            result_gpr[2] &= ~(1 << 14);

        if (!(feature6 > 8112))
            result_gpr[2] &= ~(1 << 15);

        if (!(feature6 > 8112))
            result_gpr[6] &= ~(1 << 31);
        
        
        feature7 >>= 16;
        // Decision Tree Logic
        if (!(feature7 <= 7234))
            result_gpr[3] &= ~(1 << 27);

        if (!(feature7 <= 7234))
            result_gpr[3] &= ~(1 << 28);

        if (!(feature7 > 7234))
            result_gpr[6] &= ~(1 << 13);
        
        
        feature8 &= 0xffff;
        // Decision Tree Logic
        if (!(feature8 <= 7637))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature8 > 7637))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature8 > 7637))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature8 <= 7597))
            result_gpr[5] &= ~(1 << 27);

        if (!(feature8 <= 7597))
            result_gpr[2] &= ~(1 << 11);

        if (!(feature8 <= 7597))
            result_gpr[1] &= ~(1 << 6);

        if (!(feature8 <= 7597))
            result_gpr[1] &= ~(1 << 7);

        if (!(feature8 > 7597))
            result_gpr[5] &= ~(1 << 0);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 9, 0, __xfer_reg_number(result_xfer2, __nfp_meid(35, 9)) + (__ctx() * 32), sizeof(result_xfer2), &local_signal);
    }

    return 0;
}


