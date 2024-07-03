#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal1;
__visible __xread uint32_t remote_xfer1;

__remote SIGNAL result_signal1;
__remote __xread uint32_t result_xfer1[4];

SIGNAL local_signal;


int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[4];
    __xwrite uint32_t result_write[4];
    
    __assign_relative_register(&remote_signal1, 1);
    __assign_relative_register(&local_signal, 2);
    __implicit_write(&remote_signal1, sizeof(remote_signal1));
    __implicit_write(&remote_xfer1, sizeof(remote_xfer1));
        
    for (;;) {
        reg_set(result_gpr, 0x3ffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        
        __wait_for_all(&remote_signal1);
        reg_cp(&feature, &remote_xfer1, sizeof(feature));
        feature >>= 16;
        
        // Decision tree logic
        if (!(feature <= 4789 && feature <= 2810 && feature <= 2245))
            result_gpr[3] &= ~(1 << 0);

        if (!(feature <= 4789 && feature <= 2810 && feature <= 2245))
            result_gpr[3] &= ~(1 << 1);

        if (!(feature <= 4789 && feature <= 2810 && feature <= 2245))
            result_gpr[3] &= ~(1 << 2);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2315))
            result_gpr[3] &= ~(1 << 3);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2315))
            result_gpr[3] &= ~(1 << 4);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature > 2315))
            result_gpr[3] &= ~(1 << 5);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2446))
            result_gpr[3] &= ~(1 << 6);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature > 2446))
            result_gpr[3] &= ~(1 << 7);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature > 2446))
            result_gpr[3] &= ~(1 << 8);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245))
            result_gpr[3] &= ~(1 << 9);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2388 && feature <= 2314))
            result_gpr[3] &= ~(1 << 10);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2388 && feature > 2314))
            result_gpr[3] &= ~(1 << 11);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature > 2388))
            result_gpr[3] &= ~(1 << 12);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2771 && feature <= 2759))
            result_gpr[3] &= ~(1 << 13);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2771 && feature > 2759))
            result_gpr[3] &= ~(1 << 14);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2771))
            result_gpr[3] &= ~(1 << 15);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature > 2771))
            result_gpr[3] &= ~(1 << 16);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2661 && feature <= 2357))
            result_gpr[3] &= ~(1 << 17);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2661 && feature <= 2357 && feature <= 2314))
            result_gpr[3] &= ~(1 << 18);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2661 && feature <= 2357 && feature > 2314))
            result_gpr[3] &= ~(1 << 19);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2661 && feature > 2357 && feature <= 2611 && feature <= 2450))
            result_gpr[3] &= ~(1 << 20);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2661 && feature > 2357 && feature <= 2611 && feature <= 2450 && feature <= 2422))
            result_gpr[3] &= ~(1 << 21);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2661 && feature > 2357 && feature <= 2611 && feature <= 2450 && feature > 2422))
            result_gpr[3] &= ~(1 << 22);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2661 && feature > 2357 && feature <= 2611 && feature > 2450 && feature <= 2518 && feature <= 2481))
            result_gpr[3] &= ~(1 << 23);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2661 && feature > 2357 && feature <= 2611 && feature > 2450 && feature <= 2518 && feature > 2481))
            result_gpr[3] &= ~(1 << 24);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2661 && feature > 2357 && feature <= 2611 && feature > 2450 && feature > 2518))
            result_gpr[3] &= ~(1 << 25);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2661 && feature > 2357 && feature <= 2611 && feature > 2450 && feature > 2518 && feature <= 2537))
            result_gpr[3] &= ~(1 << 26);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2661 && feature > 2357 && feature <= 2611 && feature > 2450 && feature > 2518 && feature > 2537))
            result_gpr[3] &= ~(1 << 27);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2661 && feature > 2357 && feature <= 2611 && feature > 2450 && feature > 2518))
            result_gpr[3] &= ~(1 << 28);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2661 && feature > 2357 && feature <= 2611 && feature > 2450))
            result_gpr[3] &= ~(1 << 29);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2661 && feature > 2357 && feature > 2611 && feature <= 2636))
            result_gpr[3] &= ~(1 << 30);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2661 && feature > 2357 && feature > 2611 && feature > 2636))
            result_gpr[3] &= ~(1 << 31);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2661 && feature > 2357 && feature > 2611))
            result_gpr[2] &= ~(1 << 0);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2661 && feature > 2357 && feature <= 2518))
            result_gpr[2] &= ~(1 << 1);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature <= 2661 && feature > 2357 && feature > 2518))
            result_gpr[2] &= ~(1 << 2);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature > 2661 && feature <= 2740 && feature <= 2685))
            result_gpr[2] &= ~(1 << 3);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature > 2661 && feature <= 2740 && feature > 2685))
            result_gpr[2] &= ~(1 << 4);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature > 2661 && feature <= 2740 && feature > 2685 && feature <= 2710))
            result_gpr[2] &= ~(1 << 5);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature > 2661 && feature <= 2740 && feature > 2685 && feature > 2710))
            result_gpr[2] &= ~(1 << 6);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature > 2661 && feature > 2740))
            result_gpr[2] &= ~(1 << 7);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature > 2661 && feature > 2740))
            result_gpr[2] &= ~(1 << 8);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature > 2661 && feature > 2740))
            result_gpr[2] &= ~(1 << 9);

        if (!(feature <= 4789 && feature <= 2810 && feature > 2245 && feature > 2661))
            result_gpr[2] &= ~(1 << 10);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature <= 3033))
            result_gpr[2] &= ~(1 << 11);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature > 3033))
            result_gpr[2] &= ~(1 << 12);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature > 3033))
            result_gpr[2] &= ~(1 << 13);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature <= 3057))
            result_gpr[2] &= ~(1 << 14);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature <= 3057))
            result_gpr[2] &= ~(1 << 15);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature > 3057 && feature <= 3479 && feature <= 3172 && feature <= 3135))
            result_gpr[2] &= ~(1 << 16);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature > 3057 && feature <= 3479 && feature <= 3172 && feature > 3135))
            result_gpr[2] &= ~(1 << 17);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature > 3057 && feature <= 3479 && feature > 3172))
            result_gpr[2] &= ~(1 << 18);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature > 3057 && feature > 3479))
            result_gpr[2] &= ~(1 << 19);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature > 3057))
            result_gpr[2] &= ~(1 << 20);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature <= 2859))
            result_gpr[2] &= ~(1 << 21);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature > 2859 && feature <= 3304 && feature <= 2874))
            result_gpr[2] &= ~(1 << 22);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature > 2859 && feature <= 3304 && feature > 2874 && feature <= 2897))
            result_gpr[2] &= ~(1 << 23);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature > 2859 && feature <= 3304 && feature > 2874 && feature > 2897 && feature <= 3267 && feature <= 3007))
            result_gpr[2] &= ~(1 << 24);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature > 2859 && feature <= 3304 && feature > 2874 && feature > 2897 && feature <= 3267 && feature <= 3007))
            result_gpr[2] &= ~(1 << 25);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature > 2859 && feature <= 3304 && feature > 2874 && feature > 2897 && feature <= 3267 && feature > 3007))
            result_gpr[2] &= ~(1 << 26);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature > 2859 && feature <= 3304 && feature > 2874 && feature > 2897 && feature > 3267))
            result_gpr[2] &= ~(1 << 27);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature > 2859 && feature <= 3304 && feature > 2874))
            result_gpr[2] &= ~(1 << 28);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature > 2859 && feature <= 3304 && feature > 2874))
            result_gpr[2] &= ~(1 << 29);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3626 && feature > 2859 && feature > 3304))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature <= 4789 && feature > 2810 && feature > 3626 && feature <= 4591 && feature <= 4343))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature <= 4789 && feature > 2810 && feature > 3626 && feature <= 4591 && feature > 4343))
            result_gpr[1] &= ~(1 << 0);

        if (!(feature <= 4789 && feature > 2810 && feature > 3626 && feature <= 4591))
            result_gpr[1] &= ~(1 << 1);

        if (!(feature <= 4789 && feature > 2810 && feature > 3626 && feature <= 4591 && feature <= 3836))
            result_gpr[1] &= ~(1 << 2);

        if (!(feature <= 4789 && feature > 2810 && feature > 3626 && feature <= 4591 && feature > 3836 && feature <= 4207))
            result_gpr[1] &= ~(1 << 3);

        if (!(feature <= 4789 && feature > 2810 && feature > 3626 && feature <= 4591 && feature > 3836 && feature > 4207))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature <= 4789 && feature > 2810 && feature > 3626 && feature > 4591))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature <= 4789 && feature > 2810 && feature > 3626))
            result_gpr[1] &= ~(1 << 6);

        if (!(feature <= 4789 && feature > 2810 && feature > 3626 && feature <= 3750))
            result_gpr[1] &= ~(1 << 7);

        if (!(feature <= 4789 && feature > 2810 && feature > 3626 && feature > 3750))
            result_gpr[1] &= ~(1 << 8);

        if (!(feature <= 4789 && feature > 2810 && feature > 3626))
            result_gpr[1] &= ~(1 << 9);

        if (!(feature <= 4789 && feature > 2810 && feature > 3626))
            result_gpr[1] &= ~(1 << 10);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3134))
            result_gpr[1] &= ~(1 << 11);

        if (!(feature <= 4789 && feature > 2810 && feature > 3134 && feature <= 3783))
            result_gpr[1] &= ~(1 << 12);

        if (!(feature <= 4789 && feature > 2810 && feature > 3134 && feature > 3783))
            result_gpr[1] &= ~(1 << 13);

        if (!(feature <= 4789 && feature > 2810 && feature > 3134 && feature <= 4009))
            result_gpr[1] &= ~(1 << 14);

        if (!(feature <= 4789 && feature > 2810 && feature > 3134 && feature > 4009))
            result_gpr[1] &= ~(1 << 15);

        if (!(feature <= 4789 && feature > 2810 && feature <= 2945 && feature <= 2871))
            result_gpr[1] &= ~(1 << 16);

        if (!(feature <= 4789 && feature > 2810 && feature <= 2945 && feature > 2871))
            result_gpr[1] &= ~(1 << 17);

        if (!(feature <= 4789 && feature > 2810 && feature > 2945 && feature <= 3923))
            result_gpr[1] &= ~(1 << 18);

        if (!(feature <= 4789 && feature > 2810 && feature > 2945 && feature > 3923 && feature <= 4294))
            result_gpr[1] &= ~(1 << 19);

        if (!(feature <= 4789 && feature > 2810 && feature > 2945 && feature > 3923 && feature > 4294))
            result_gpr[1] &= ~(1 << 20);

        if (!(feature <= 4789 && feature > 2810 && feature > 2945 && feature <= 3527 && feature <= 3329))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature <= 4789 && feature > 2810 && feature > 2945 && feature <= 3527 && feature > 3329))
            result_gpr[1] &= ~(1 << 22);

        if (!(feature <= 4789 && feature > 2810 && feature > 2945 && feature <= 3527))
            result_gpr[1] &= ~(1 << 23);

        if (!(feature <= 4789 && feature > 2810 && feature > 2945 && feature <= 3527))
            result_gpr[1] &= ~(1 << 24);

        if (!(feature <= 4789 && feature > 2810 && feature > 2945 && feature <= 3527 && feature <= 3007))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature <= 4789 && feature > 2810 && feature > 2945 && feature <= 3527 && feature > 3007))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature <= 4789 && feature > 2810 && feature > 2945 && feature > 3527 && feature <= 3762))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature <= 4789 && feature > 2810 && feature > 2945 && feature > 3527 && feature > 3762 && feature <= 4034))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature <= 4789 && feature > 2810 && feature > 2945 && feature > 3527 && feature > 3762 && feature > 4034 && feature <= 4170))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature <= 4789 && feature > 2810 && feature > 2945 && feature > 3527 && feature > 3762 && feature > 4034 && feature > 4170 && feature <= 4282))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature <= 4789 && feature > 2810 && feature > 2945 && feature > 3527 && feature > 3762 && feature > 4034 && feature > 4170 && feature > 4282))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature <= 4789 && feature > 2810 && feature > 2945 && feature > 3527 && feature > 3762 && feature > 4034 && feature > 4170))
            result_gpr[0] &= ~(1 << 0);

        if (!(feature <= 4789 && feature > 2810 && feature > 2945 && feature > 3527 && feature > 3762 && feature > 4034))
            result_gpr[0] &= ~(1 << 1);

        if (!(feature <= 4789 && feature > 2810 && feature > 2945 && feature > 3527 && feature > 3762))
            result_gpr[0] &= ~(1 << 2);

        if (!(feature <= 4789 && feature > 2810 && feature > 2945 && feature > 3527))
            result_gpr[0] &= ~(1 << 3);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3417 && feature <= 2931))
            result_gpr[0] &= ~(1 << 4);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3417 && feature > 2931))
            result_gpr[0] &= ~(1 << 5);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3417 && feature > 2931))
            result_gpr[0] &= ~(1 << 6);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3417 && feature > 2931))
            result_gpr[0] &= ~(1 << 7);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3417 && feature > 2931))
            result_gpr[0] &= ~(1 << 8);

        if (!(feature <= 4789 && feature > 2810 && feature <= 3417 && feature > 2931))
            result_gpr[0] &= ~(1 << 9);

        if (!(feature <= 4789 && feature > 2810 && feature > 3417))
            result_gpr[0] &= ~(1 << 10);

        if (!(feature > 4789 && feature <= 5061))
            result_gpr[0] &= ~(1 << 11);

        if (!(feature > 4789 && feature <= 5061))
            result_gpr[0] &= ~(1 << 12);

        if (!(feature > 4789 && feature <= 5061))
            result_gpr[0] &= ~(1 << 13);

        if (!(feature > 4789 && feature > 5061))
            result_gpr[0] &= ~(1 << 14);

        if (!(feature > 4789 && feature > 5061))
            result_gpr[0] &= ~(1 << 15);

        if (!(feature > 4789 && feature > 5061))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature > 4789 && feature > 5061))
            result_gpr[0] &= ~(1 << 17);
        
        
        reg_cp(&result_write, &result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(&result_write, 34, 9, 0, 
                                          __xfer_reg_number(&result_xfer1, __nfp_meid(34, 9)) + (__ctx() * 32), 
                                          sizeof(result_xfer1), &local_signal);    
    }
    
    return 0;
}
