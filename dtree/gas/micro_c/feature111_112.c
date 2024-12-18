#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal39;
__visible __xread uint32_t remote_xfer39;

__remote SIGNAL result_signal39;
__remote __xread uint32_t result_xfer39[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature111;
    __gpr uint32_t feature112;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal39, 1);
    __assign_relative_register(&local_signal, 4);
    __implicit_write(&remote_signal39, sizeof(remote_signal39));
    __implicit_write(&remote_xfer39, sizeof(remote_xfer39));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal39);
        reg_cp(&feature111, &remote_xfer39, sizeof(feature111));
        reg_cp(&feature112, &remote_xfer39, sizeof(feature112));        
        
        feature111 >>= 16;
        // Decision Tree Logic
        if (!(feature111 <= 7710))
            result_gpr[5] &= ~(1 << 14);

        if (!(feature111 <= 7710))
            result_gpr[5] &= ~(1 << 15);

        if (!(feature111 > 7710))
            result_gpr[5] &= ~(1 << 13);

        if (!(feature111 <= 7636))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature111 <= 7636))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature111 <= 7636))
            result_gpr[1] &= ~(1 << 0);

        if (!(feature111 <= 7636))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature111 <= 7636))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature111 <= 7636))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature111 <= 7636))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature111 <= 7636))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature111 <= 7636))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature111 <= 7636))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature111 <= 7636))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature111 <= 7636))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature111 <= 7636))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature111 <= 7636))
            result_gpr[2] &= ~(1 << 24);

        if (!(feature111 <= 7636))
            result_gpr[2] &= ~(1 << 25);

        if (!(feature111 > 7636))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature111 > 7636))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature111 > 7636))
            result_gpr[5] &= ~(1 << 31);
        
        
       feature112 &= 0xffff;
        // Decision Tree Logic
        if (!(feature112 <= 8017))
            result_gpr[2] &= ~(1 << 24);

        if (!(feature112 > 8017))
            result_gpr[2] &= ~(1 << 25);

        if (!(feature112 <= 7978))
            result_gpr[6] &= ~(1 << 2);

        if (!(feature112 > 7978))
            result_gpr[6] &= ~(1 << 19);

        if (!(feature112 > 7978))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature112 > 7978))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature112 > 7978))
            result_gpr[0] &= ~(1 << 0);

        if (!(feature112 > 7978))
            result_gpr[4] &= ~(1 << 26);

        if (!(feature112 > 7978))
            result_gpr[4] &= ~(1 << 0);

        if (!(feature112 > 7978))
            result_gpr[4] &= ~(1 << 1);

        if (!(feature112 > 7978))
            result_gpr[2] &= ~(1 << 16);

        if (!(feature112 > 7978))
            result_gpr[2] &= ~(1 << 17);

        if (!(feature112 <= 7988))
            result_gpr[2] &= ~(1 << 26);

        if (!(feature112 <= 7988))
            result_gpr[2] &= ~(1 << 27);

        if (!(feature112 > 7988))
            result_gpr[1] &= ~(1 << 1);

        if (!(feature112 > 7988))
            result_gpr[1] &= ~(1 << 2);

        if (!(feature112 > 7988))
            result_gpr[1] &= ~(1 << 20);

        if (!(feature112 > 7988))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature112 > 7988))
            result_gpr[0] &= ~(1 << 10);

        if (!(feature112 > 7988))
            result_gpr[0] &= ~(1 << 11);

        if (!(feature112 > 7988))
            result_gpr[0] &= ~(1 << 12);

        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 6, 0, __xfer_reg_number(result_xfer39, __nfp_meid(36, 6)) + (__ctx() * 32), sizeof(result_xfer39), &local_signal);
    }

    return 0;
}


