#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal19;
__visible __xread uint32_t remote_xfer19[3];

__remote SIGNAL result_signal19;
__remote __xread uint32_t result_xfer19[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature57;
    __gpr uint32_t feature58;
    __gpr uint32_t feature59;
    __gpr uint32_t feature60;
    __gpr uint32_t feature61;
    __gpr uint32_t feature62;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal19, 1);
    __assign_relative_register(&local_signal, 4);
    __implicit_write(&remote_signal19, sizeof(remote_signal19));
    __implicit_write(&remote_xfer19, sizeof(remote_xfer19));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal19);
        reg_cp(&feature57, remote_xfer19, sizeof(feature57));
        reg_cp(&feature58, remote_xfer19, sizeof(feature58));
        reg_cp(&feature59, remote_xfer19+1, sizeof(feature59));
        reg_cp(&feature60, remote_xfer19+1, sizeof(feature60));
        reg_cp(&feature61, remote_xfer19+2, sizeof(feature61));
        reg_cp(&feature62, remote_xfer19+2, sizeof(feature62));
        
        
        feature57 >>= 16;
        // Decision Tree Logic
        if (!(feature57 <= 2136))
            result_gpr[2] &= ~(1 << 1);

        if (!(feature57 <= 2136))
            result_gpr[2] &= ~(1 << 2);

        if (!(feature57 > 2136))
            result_gpr[5] &= ~(1 << 6);

        if (!(feature57 > 2136))
            result_gpr[0] &= ~(1 << 30);

        if (!(feature57 > 2136))
            result_gpr[0] &= ~(1 << 31);

        if (!(feature57 > 2136))
            result_gpr[0] &= ~(1 << 5);

        if (!(feature57 > 2136))
            result_gpr[0] &= ~(1 << 6);

        if (!(feature57 > 2136))
            result_gpr[0] &= ~(1 << 7);

        if (!(feature57 > 2136))
            result_gpr[0] &= ~(1 << 8);

        if (!(feature57 > 2136))
            result_gpr[0] &= ~(1 << 9);

        if (!(feature57 > 2136))
            result_gpr[0] &= ~(1 << 4);

        if (!(feature57 > 2136))
            result_gpr[0] &= ~(1 << 2);

        if (!(feature57 > 2136))
            result_gpr[0] &= ~(1 << 3);

        if (!(feature57 > 2136))
            result_gpr[0] &= ~(1 << 1);

        if (!(feature57 > 2136))
            result_gpr[5] &= ~(1 << 5);

        if (!(feature57 > 2136))
            result_gpr[6] &= ~(1 << 3);

        if (!(feature57 > 2136))
            result_gpr[3] &= ~(1 << 23);

        if (!(feature57 > 2136))
            result_gpr[3] &= ~(1 << 24);


        
        feature58 &= 0xffff;
        // Decision Tree Logic
        if (!(feature58 <= 1))
            result_gpr[3] &= ~(1 << 29);

        if (!(feature58 > 1))
            result_gpr[3] &= ~(1 << 30);

        
        feature59 >>= 16;
        // Decision Tree Logic
        if (!(feature59 <= 835))
            result_gpr[3] &= ~(1 << 14);

        if (!(feature59 > 835))
            result_gpr[3] &= ~(1 << 15);

        
        feature60 &= 0xffff;
        // Decision Tree Logic
        if (!(feature60 <= 237))
            result_gpr[2] &= ~(1 << 12);

        if (!(feature60 > 237))
            result_gpr[2] &= ~(1 << 13);
        
        
        feature61 >>= 16;
        // Decision Tree Logic
        if (!(feature61 <= 277))
            result_gpr[4] &= ~(1 << 24);

        if (!(feature61 > 277))
            result_gpr[4] &= ~(1 << 25);

        if (!(feature61 <= 1400))
            result_gpr[1] &= ~(1 << 12);

        if (!(feature61 <= 1400))
            result_gpr[1] &= ~(1 << 13);

        if (!(feature61 > 1400))
            result_gpr[4] &= ~(1 << 2);
        
        
        feature62 &= 0xffff;
        // Decision Tree Logic
        if (!(feature62 <= 7986))
            result_gpr[3] &= ~(1 << 31);

        if (!(feature62 > 7986))
            result_gpr[2] &= ~(1 << 0);

        if (!(feature62 <= 7315))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature62 > 7315))
            result_gpr[0] &= ~(1 << 17);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 1, 0, __xfer_reg_number(result_xfer19, __nfp_meid(36, 1)) + (__ctx() * 32), sizeof(result_xfer19), &local_signal);
    }

    return 0;
}


