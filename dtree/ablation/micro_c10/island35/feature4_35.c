#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal4;
__visible __xread uint32_t remote_xfer4;

__remote SIGNAL result_signal4;
__remote __xread uint32_t result_xfer4[8];

SIGNAL local_signal;

// feature: tcp destination port
int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];
    
    __assign_relative_register(&remote_signal4, 1);
    __assign_relative_register(&local_signal, 4);
    __implicit_write(&remote_signal4, sizeof(remote_signal4));
    __implicit_write(&remote_xfer4, sizeof(remote_xfer4));
    
    for (;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal4);
        reg_cp(&feature, &remote_xfer4, sizeof(feature));
        feature &= 0xffff;      

        // Decision Tree Logic
        if (!(feature <= 264 && feature <= 66))
            result_gpr[7] &= ~(1 << 18);

        if (!(feature <= 264 && feature <= 66))
            result_gpr[7] &= ~(1 << 19);

        if (!(feature <= 264 && feature <= 66 && feature <= 21))
            result_gpr[0] &= ~(1 << 28);

        if (!(feature <= 264 && feature <= 66 && feature <= 21))
            result_gpr[0] &= ~(1 << 29);

        if (!(feature <= 264 && feature <= 66 && feature > 21))
            result_gpr[2] &= ~(1 << 15);

        if (!(feature <= 264 && feature <= 66 && feature > 21))
            result_gpr[2] &= ~(1 << 16);

        if (!(feature <= 264 && feature <= 66))
            result_gpr[6] &= ~(1 << 18);

        if (!(feature <= 264 && feature <= 66))
            result_gpr[5] &= ~(1 << 13);

        if (!(feature <= 264 && feature <= 66))
            result_gpr[3] &= ~(1 << 28);

        if (!(feature <= 264 && feature <= 66))
            result_gpr[3] &= ~(1 << 29);

        if (!(feature <= 264 && feature <= 66))
            result_gpr[3] &= ~(1 << 27);

        if (!(feature <= 264 && feature <= 66))
            result_gpr[5] &= ~(1 << 12);

        if (!(feature <= 264 && feature <= 66))
            result_gpr[5] &= ~(1 << 0);

        if (!(feature <= 264 && feature <= 66))
            result_gpr[5] &= ~(1 << 1);

        if (!(feature <= 264 && feature <= 66))
            result_gpr[6] &= ~(1 << 31);

        if (!(feature <= 264 && feature <= 66))
            result_gpr[6] &= ~(1 << 20);

        if (!(feature <= 264 && feature <= 66))
            result_gpr[4] &= ~(1 << 1);

        if (!(feature <= 264 && feature <= 66))
            result_gpr[4] &= ~(1 << 2);

        if (!(feature <= 264 && feature <= 66))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature <= 264 && feature <= 66))
            result_gpr[7] &= ~(1 << 14);

        if (!(feature <= 264 && feature > 66))
            result_gpr[7] &= ~(1 << 13);

        if (!(feature <= 264 && feature > 66))
            result_gpr[4] &= ~(1 << 16);

        if (!(feature <= 264 && feature > 66))
            result_gpr[4] &= ~(1 << 17);

        if (!(feature <= 264 && feature > 66 && feature <= 137 && feature <= 111))
            result_gpr[7] &= ~(1 << 17);

        if (!(feature <= 264 && feature > 66 && feature <= 137 && feature > 111))
            result_gpr[4] &= ~(1 << 14);

        if (!(feature <= 264 && feature > 66 && feature <= 137 && feature > 111))
            result_gpr[4] &= ~(1 << 15);

        if (!(feature <= 264 && feature > 66 && feature > 137))
            result_gpr[7] &= ~(1 << 6);

        if (!(feature <= 264 && feature > 66 && feature <= 137 && feature <= 111))
            result_gpr[6] &= ~(1 << 12);

        if (!(feature <= 264 && feature > 66 && feature <= 137 && feature > 111))
            result_gpr[6] &= ~(1 << 13);

        if (!(feature <= 264 && feature > 66 && feature > 137))
            result_gpr[7] &= ~(1 << 15);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[2] &= ~(1 << 11);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[2] &= ~(1 << 12);

        if (!(feature <= 264 && feature > 66 && feature > 84))
            result_gpr[7] &= ~(1 << 1);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[7] &= ~(1 << 27);

        if (!(feature <= 264 && feature > 66 && feature > 84))
            result_gpr[7] &= ~(1 << 28);

        if (!(feature <= 264 && feature > 66))
            result_gpr[7] &= ~(1 << 0);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[7] &= ~(1 << 25);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[7] &= ~(1 << 26);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[5] &= ~(1 << 5);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[2] &= ~(1 << 6);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[2] &= ~(1 << 7);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[7] &= ~(1 << 4);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[7] &= ~(1 << 5);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[7] &= ~(1 << 3);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[4] &= ~(1 << 7);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[4] &= ~(1 << 8);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[5] &= ~(1 << 24);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[5] &= ~(1 << 25);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[2] &= ~(1 << 8);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[2] &= ~(1 << 9);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[2] &= ~(1 << 10);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[6] &= ~(1 << 11);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[6] &= ~(1 << 5);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[2] &= ~(1 << 22);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[2] &= ~(1 << 23);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[0] &= ~(1 << 24);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[0] &= ~(1 << 25);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[4] &= ~(1 << 25);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[5] &= ~(1 << 2);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[7] &= ~(1 << 12);

        if (!(feature <= 264 && feature > 66 && feature > 84 && feature <= 111))
            result_gpr[7] &= ~(1 << 10);

        if (!(feature <= 264 && feature > 66 && feature > 84 && feature > 111 && feature <= 137))
            result_gpr[0] &= ~(1 << 9);

        if (!(feature <= 264 && feature > 66 && feature > 84 && feature > 111 && feature > 137))
            result_gpr[0] &= ~(1 << 10);

        if (!(feature <= 264 && feature > 66 && feature > 84 && feature > 111))
            result_gpr[0] &= ~(1 << 5);

        if (!(feature <= 264 && feature > 66 && feature > 84))
            result_gpr[2] &= ~(1 << 25);

        if (!(feature <= 264 && feature > 66 && feature > 84))
            result_gpr[2] &= ~(1 << 26);

        if (!(feature <= 264 && feature > 66 && feature > 84))
            result_gpr[2] &= ~(1 << 24);

        if (!(feature <= 264 && feature > 66 && feature > 84 && feature <= 137))
            result_gpr[5] &= ~(1 << 19);

        if (!(feature <= 264 && feature > 66 && feature > 84 && feature > 137))
            result_gpr[5] &= ~(1 << 20);

        if (!(feature <= 264 && feature > 66 && feature > 84))
            result_gpr[5] &= ~(1 << 18);

        if (!(feature <= 264 && feature > 66))
            result_gpr[4] &= ~(1 << 26);

        if (!(feature <= 264 && feature > 66))
            result_gpr[4] &= ~(1 << 27);

        if (!(feature <= 264 && feature > 66))
            result_gpr[4] &= ~(1 << 28);

        if (!(feature <= 264 && feature > 66))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature <= 264 && feature > 66))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature <= 264 && feature > 66))
            result_gpr[2] &= ~(1 << 29);

        if (!(feature <= 264 && feature > 66))
            result_gpr[2] &= ~(1 << 27);

        if (!(feature <= 264 && feature > 66))
            result_gpr[2] &= ~(1 << 28);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 0);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 0);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 3);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 2);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 1);

        if (!(feature <= 264 && feature > 66))
            result_gpr[3] &= ~(1 << 4);

        if (!(feature <= 264 && feature > 66))
            result_gpr[3] &= ~(1 << 5);

        if (!(feature <= 264 && feature > 66))
            result_gpr[6] &= ~(1 << 21);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[1] &= ~(1 << 24);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature <= 264 && feature > 66 && feature > 84))
            result_gpr[6] &= ~(1 << 6);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[1] &= ~(1 << 18);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[0] &= ~(1 << 1);

        if (!(feature <= 264 && feature > 66 && feature <= 84))
            result_gpr[0] &= ~(1 << 2);

        if (!(feature <= 264 && feature > 66 && feature > 84))
            result_gpr[5] &= ~(1 << 11);

        if (!(feature <= 264 && feature > 66))
            result_gpr[5] &= ~(1 << 31);

        if (!(feature <= 264 && feature > 66))
            result_gpr[4] &= ~(1 << 0);

        if (!(feature <= 264 && feature > 66))
            result_gpr[5] &= ~(1 << 10);

        if (!(feature <= 264 && feature > 66))
            result_gpr[3] &= ~(1 << 15);

        if (!(feature <= 264 && feature > 66))
            result_gpr[3] &= ~(1 << 16);

        if (!(feature <= 264 && feature > 66))
            result_gpr[5] &= ~(1 << 9);

        if (!(feature <= 264 && feature > 66))
            result_gpr[7] &= ~(1 << 21);

        if (!(feature <= 264 && feature > 66))
            result_gpr[7] &= ~(1 << 22);

        if (!(feature <= 264 && feature > 66))
            result_gpr[7] &= ~(1 << 23);

        if (!(feature <= 264 && feature > 66))
            result_gpr[4] &= ~(1 << 9);

        if (!(feature <= 264 && feature > 66))
            result_gpr[4] &= ~(1 << 10);

        if (!(feature <= 264 && feature > 66))
            result_gpr[5] &= ~(1 << 3);

        if (!(feature <= 264 && feature > 66))
            result_gpr[5] &= ~(1 << 4);

        if (!(feature <= 264 && feature > 66))
            result_gpr[3] &= ~(1 << 6);

        if (!(feature <= 264 && feature > 66))
            result_gpr[3] &= ~(1 << 7);

        if (!(feature <= 264 && feature > 66))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature <= 264 && feature > 66))
            result_gpr[4] &= ~(1 << 5);

        if (!(feature <= 264 && feature > 66))
            result_gpr[2] &= ~(1 << 1);

        if (!(feature <= 264 && feature > 66))
            result_gpr[2] &= ~(1 << 2);

        if (!(feature <= 264 && feature > 66))
            result_gpr[6] &= ~(1 << 2);

        if (!(feature <= 264 && feature > 66))
            result_gpr[6] &= ~(1 << 3);

        if (!(feature <= 264 && feature > 66))
            result_gpr[5] &= ~(1 << 27);

        if (!(feature <= 264 && feature > 66))
            result_gpr[5] &= ~(1 << 28);

        if (!(feature <= 264 && feature > 66))
            result_gpr[5] &= ~(1 << 26);

        if (!(feature <= 264 && feature > 66))
            result_gpr[4] &= ~(1 << 20);

        if (!(feature <= 264 && feature > 66))
            result_gpr[4] &= ~(1 << 21);

        if (!(feature <= 264 && feature > 66))
            result_gpr[3] &= ~(1 << 11);

        if (!(feature <= 264 && feature > 66))
            result_gpr[3] &= ~(1 << 12);

        if (!(feature <= 264 && feature > 66))
            result_gpr[6] &= ~(1 << 14);

        if (!(feature <= 264 && feature > 66))
            result_gpr[2] &= ~(1 << 13);

        if (!(feature <= 264 && feature > 66))
            result_gpr[2] &= ~(1 << 14);

        if (!(feature <= 264 && feature > 66))
            result_gpr[6] &= ~(1 << 17);

        if (!(feature <= 264 && feature > 66))
            result_gpr[4] &= ~(1 << 18);

        if (!(feature <= 264 && feature > 66))
            result_gpr[4] &= ~(1 << 19);

        if (!(feature <= 264 && feature > 66))
            result_gpr[7] &= ~(1 << 31);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 7);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 8);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 9);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 6);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 20);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 22);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 23);

        if (!(feature <= 264 && feature > 66))
            result_gpr[4] &= ~(1 << 29);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 12);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 13);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 14);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 15);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 6);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 30);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 31);

        if (!(feature <= 264 && feature > 66))
            result_gpr[5] &= ~(1 << 29);

        if (!(feature <= 264 && feature > 66))
            result_gpr[5] &= ~(1 << 30);

        if (!(feature <= 264 && feature > 66))
            result_gpr[3] &= ~(1 << 30);

        if (!(feature <= 264 && feature > 66))
            result_gpr[3] &= ~(1 << 31);

        if (!(feature <= 264 && feature > 66))
            result_gpr[2] &= ~(1 << 0);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 16);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 17);

        if (!(feature <= 264 && feature > 66))
            result_gpr[7] &= ~(1 << 2);

        if (!(feature <= 264 && feature > 66))
            result_gpr[6] &= ~(1 << 19);

        if (!(feature <= 264 && feature > 66))
            result_gpr[4] &= ~(1 << 6);

        if (!(feature <= 264 && feature > 66))
            result_gpr[3] &= ~(1 << 23);

        if (!(feature <= 264 && feature > 66))
            result_gpr[3] &= ~(1 << 24);

        if (!(feature <= 264 && feature > 66))
            result_gpr[3] &= ~(1 << 25);

        if (!(feature <= 264 && feature > 66))
            result_gpr[3] &= ~(1 << 26);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 20);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 18);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 19);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 14);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 15);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature <= 264 && feature > 66))
            result_gpr[5] &= ~(1 << 14);

        if (!(feature <= 264 && feature > 66))
            result_gpr[5] &= ~(1 << 15);

        if (!(feature <= 264 && feature > 66))
            result_gpr[3] &= ~(1 << 13);

        if (!(feature <= 264 && feature > 66))
            result_gpr[3] &= ~(1 << 14);

        if (!(feature <= 264 && feature > 66))
            result_gpr[6] &= ~(1 << 4);

        if (!(feature <= 264 && feature > 66))
            result_gpr[2] &= ~(1 << 17);

        if (!(feature <= 264 && feature > 66))
            result_gpr[2] &= ~(1 << 18);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 26);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 27);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 3);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 4);

        if (!(feature <= 264 && feature > 66))
            result_gpr[1] &= ~(1 << 19);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 7);

        if (!(feature <= 264 && feature > 66))
            result_gpr[0] &= ~(1 << 8);

        if (!(feature <= 264 && feature > 66))
            result_gpr[7] &= ~(1 << 11);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature <= 443))
            result_gpr[5] &= ~(1 << 6);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature <= 443))
            result_gpr[5] &= ~(1 << 7);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature <= 443))
            result_gpr[5] &= ~(1 << 22);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature <= 443))
            result_gpr[5] &= ~(1 << 23);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature <= 443))
            result_gpr[5] &= ~(1 << 21);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature <= 443))
            result_gpr[4] &= ~(1 << 23);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature <= 443))
            result_gpr[4] &= ~(1 << 24);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455 && feature <= 444))
            result_gpr[6] &= ~(1 << 1);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455 && feature > 444))
            result_gpr[1] &= ~(1 << 10);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455 && feature > 444))
            result_gpr[1] &= ~(1 << 11);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455 && feature > 444))
            result_gpr[5] &= ~(1 << 16);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455 && feature > 444))
            result_gpr[5] &= ~(1 << 17);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455 && feature > 444))
            result_gpr[5] &= ~(1 << 8);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455 && feature > 444))
            result_gpr[6] &= ~(1 << 9);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455 && feature > 444))
            result_gpr[6] &= ~(1 << 10);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455))
            result_gpr[7] &= ~(1 << 20);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455 && feature <= 444))
            result_gpr[2] &= ~(1 << 20);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455 && feature <= 444))
            result_gpr[2] &= ~(1 << 21);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455 && feature > 444))
            result_gpr[2] &= ~(1 << 19);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455))
            result_gpr[7] &= ~(1 << 29);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455))
            result_gpr[7] &= ~(1 << 30);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455))
            result_gpr[4] &= ~(1 << 12);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455))
            result_gpr[4] &= ~(1 << 13);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455))
            result_gpr[4] &= ~(1 << 11);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455))
            result_gpr[6] &= ~(1 << 8);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455))
            result_gpr[6] &= ~(1 << 7);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455))
            result_gpr[0] &= ~(1 << 12);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455))
            result_gpr[0] &= ~(1 << 13);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455))
            result_gpr[0] &= ~(1 << 11);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455 && feature <= 444))
            result_gpr[4] &= ~(1 << 22);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455 && feature > 444))
            result_gpr[4] &= ~(1 << 30);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455 && feature > 444))
            result_gpr[4] &= ~(1 << 31);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455 && feature > 444))
            result_gpr[3] &= ~(1 << 0);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455))
            result_gpr[6] &= ~(1 << 16);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455))
            result_gpr[6] &= ~(1 << 24);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455))
            result_gpr[6] &= ~(1 << 25);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455))
            result_gpr[6] &= ~(1 << 26);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455))
            result_gpr[6] &= ~(1 << 27);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature <= 455))
            result_gpr[6] &= ~(1 << 15);

        if (!(feature > 264 && feature <= 1043 && feature <= 745 && feature > 443 && feature > 455))
            result_gpr[7] &= ~(1 << 8);

        if (!(feature > 264 && feature <= 1043 && feature > 745 && feature <= 1040 && feature <= 1037 && feature <= 1027))
            result_gpr[6] &= ~(1 << 28);

        if (!(feature > 264 && feature <= 1043 && feature > 745 && feature <= 1040 && feature <= 1037 && feature > 1027 && feature <= 1036))
            result_gpr[6] &= ~(1 << 29);

        if (!(feature > 264 && feature <= 1043 && feature > 745 && feature <= 1040 && feature <= 1037 && feature > 1027 && feature > 1036))
            result_gpr[6] &= ~(1 << 30);

        if (!(feature > 264 && feature <= 1043 && feature > 745 && feature <= 1040 && feature > 1037))
            result_gpr[6] &= ~(1 << 23);

        if (!(feature > 264 && feature <= 1043 && feature > 745 && feature > 1040))
            result_gpr[6] &= ~(1 << 22);

        if (!(feature > 264 && feature > 1043 && feature <= 34502 && feature <= 33924))
            result_gpr[2] &= ~(1 << 4);

        if (!(feature > 264 && feature > 1043 && feature <= 34502 && feature > 33924))
            result_gpr[2] &= ~(1 << 5);

        if (!(feature > 264 && feature > 1043 && feature > 34502))
            result_gpr[2] &= ~(1 << 3);

        if (!(feature > 264 && feature > 1043))
            result_gpr[7] &= ~(1 << 16);

        if (!(feature > 264 && feature > 1043 && feature <= 40335 && feature <= 11728))
            result_gpr[6] &= ~(1 << 0);

        if (!(feature > 264 && feature > 1043 && feature <= 40335 && feature > 11728 && feature <= 33845 && feature <= 22463 && feature <= 12701))
            result_gpr[3] &= ~(1 << 3);

        if (!(feature > 264 && feature > 1043 && feature <= 40335 && feature > 11728 && feature <= 33845 && feature <= 22463 && feature > 12701 && feature <= 16282 && feature <= 16107))
            result_gpr[3] &= ~(1 << 21);

        if (!(feature > 264 && feature > 1043 && feature <= 40335 && feature > 11728 && feature <= 33845 && feature <= 22463 && feature > 12701 && feature <= 16282 && feature > 16107))
            result_gpr[3] &= ~(1 << 22);

        if (!(feature > 264 && feature > 1043 && feature <= 40335 && feature > 11728 && feature <= 33845 && feature <= 22463 && feature > 12701 && feature > 16282))
            result_gpr[3] &= ~(1 << 20);

        if (!(feature > 264 && feature > 1043 && feature <= 40335 && feature > 11728 && feature <= 33845 && feature > 22463))
            result_gpr[3] &= ~(1 << 2);

        if (!(feature > 264 && feature > 1043 && feature <= 40335 && feature > 11728 && feature > 33845 && feature <= 39497 && feature <= 36019 && feature <= 35661))
            result_gpr[3] &= ~(1 << 18);

        if (!(feature > 264 && feature > 1043 && feature <= 40335 && feature > 11728 && feature > 33845 && feature <= 39497 && feature <= 36019 && feature > 35661))
            result_gpr[3] &= ~(1 << 19);

        if (!(feature > 264 && feature > 1043 && feature <= 40335 && feature > 11728 && feature > 33845 && feature <= 39497 && feature > 36019))
            result_gpr[3] &= ~(1 << 17);

        if (!(feature > 264 && feature > 1043 && feature <= 40335 && feature > 11728 && feature > 33845 && feature > 39497))
            result_gpr[3] &= ~(1 << 1);

        if (!(feature > 264 && feature > 1043 && feature > 40335 && feature <= 61076))
            result_gpr[3] &= ~(1 << 8);

        if (!(feature > 264 && feature > 1043 && feature > 40335 && feature > 61076 && feature <= 62072))
            result_gpr[3] &= ~(1 << 9);

        if (!(feature > 264 && feature > 1043 && feature > 40335 && feature > 61076 && feature > 62072))
            result_gpr[3] &= ~(1 << 10);

        if (!(feature > 264 && feature > 1043))
            result_gpr[7] &= ~(1 << 24);

        if (!(feature > 264 && feature > 1043))
            result_gpr[7] &= ~(1 << 9);

        if (!(feature > 264))
            result_gpr[7] &= ~(1 << 7);
        
        
        reg_cp(result_write, result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(result_write, 35, 7, 0, 
                                          __xfer_reg_number(result_xfer4, __nfp_meid(35, 7)) + (__ctx() * 32), 
                                          sizeof(result_xfer4), &local_signal);    
    }
    
    return 0;
}
