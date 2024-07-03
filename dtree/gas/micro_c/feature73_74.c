#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>


__visible SIGNAL remote_signal24;
__visible __xread uint32_t remote_xfer24;

__remote SIGNAL result_signal24;
__remote __xread uint32_t result_xfer24[8];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature73;
    __gpr uint32_t feature74;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];

    __assign_relative_register(&remote_signal24, 1);
    __assign_relative_register(&local_signal, 5);
    __implicit_write(&remote_signal24, sizeof(remote_signal24));
    __implicit_write(&remote_xfer24, sizeof(remote_xfer24));

    for(;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal24);
        reg_cp(&feature73, &remote_xfer24, sizeof(feature73));
        reg_cp(&feature74, &remote_xfer24, sizeof(feature74));
        
        feature73 >>= 16;
        // Decision Tree Logic
        if (!(feature73 <= 223))
            result_gpr[2] &= ~(1 << 18);

        if (!(feature73 <= 223))
            result_gpr[2] &= ~(1 << 19);

        if (!(feature73 > 223))
            result_gpr[4] &= ~(1 << 19);

        if (!(feature73 > 223))
            result_gpr[4] &= ~(1 << 21);

        if (!(feature73 > 223))
            result_gpr[0] &= ~(1 << 24);

        if (!(feature73 > 223))
            result_gpr[0] &= ~(1 << 25);

        if (!(feature73 > 223))
            result_gpr[0] &= ~(1 << 26);

        if (!(feature73 > 223))
            result_gpr[2] &= ~(1 << 5);

        if (!(feature73 > 223))
            result_gpr[2] &= ~(1 << 6);

        if (!(feature73 > 223))
            result_gpr[4] &= ~(1 << 20);

        if (!(feature73 <= 486))
            result_gpr[0] &= ~(1 << 28);

        if (!(feature73 <= 486))
            result_gpr[0] &= ~(1 << 29);

        if (!(feature73 <= 486))
            result_gpr[0] &= ~(1 << 27);

        if (!(feature73 > 486))
            result_gpr[6] &= ~(1 << 9);

        if (!(feature73 <= 860))
            result_gpr[1] &= ~(1 << 20);

        if (!(feature73 > 860))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature73 <= 383))
            result_gpr[2] &= ~(1 << 11);

        if (!(feature73 > 383))
            result_gpr[1] &= ~(1 << 6);

        if (!(feature73 > 383))
            result_gpr[1] &= ~(1 << 7);

        
        feature74 &= 0xffff;
        // Decision Tree Logic
        if (!(feature74 <= 384))
            result_gpr[3] &= ~(1 << 7);

        if (!(feature74 <= 384))
            result_gpr[3] &= ~(1 << 8);

        if (!(feature74 <= 384))
            result_gpr[1] &= ~(1 << 22);

        if (!(feature74 <= 384))
            result_gpr[1] &= ~(1 << 23);

        if (!(feature74 <= 384))
            result_gpr[1] &= ~(1 << 24);

        if (!(feature74 <= 384))
            result_gpr[3] &= ~(1 << 6);

        if (!(feature74 > 384))
            result_gpr[3] &= ~(1 << 5);
        
        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 36, 2, 0, __xfer_reg_number(result_xfer24, __nfp_meid(36, 2)) + (__ctx() * 32), sizeof(result_xfer24), &local_signal);
    }

    return 0;
}


