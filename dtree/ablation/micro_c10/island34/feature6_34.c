#include <nfp.h>
#include <stdint.h>
#include <std/reg_utils.h>
#include <nfp/me.h>
#include <nfp/remote_me.h>
#include <nfp/cls.h>

__visible SIGNAL remote_signal6;
__visible __xread uint32_t remote_xfer6;

__remote SIGNAL result_signal6;
__remote __xread uint32_t result_xfer6[8];

SIGNAL local_signal;


// feature: total packet length
int main(void) {
    __gpr uint32_t feature;
    __gpr uint32_t result_gpr[8];
    __xwrite uint32_t result_write[8];
    
    __assign_relative_register(&remote_signal6, 1);
    __assign_relative_register(&local_signal, 6);
    __implicit_write(&remote_signal6, sizeof(remote_signal6));
    __implicit_write(&remote_xfer6, sizeof(remote_xfer6));
    
    for (;;) {
        reg_set(result_gpr, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+1, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+2, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+3, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+4, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+5, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+6, 0xffffffff, sizeof(uint32_t));
        reg_set(result_gpr+7, 0xffffffff, sizeof(uint32_t));

        __wait_for_all(&remote_signal6);
        reg_cp(&feature, &remote_xfer6, sizeof(feature));
        feature &= 0xffff;       

        // Decision Tree Logic
        if (!(feature <= 124))
            result_gpr[7] &= ~(1 << 18);

        if (!(feature > 124))
            result_gpr[7] &= ~(1 << 19);

        if (!(feature <= 41))
            result_gpr[0] &= ~(1 << 28);

        if (!(feature <= 41))
            result_gpr[0] &= ~(1 << 29);

        if (!(feature <= 41))
            result_gpr[2] &= ~(1 << 15);

        if (!(feature <= 41))
            result_gpr[2] &= ~(1 << 16);

        if (!(feature <= 41))
            result_gpr[6] &= ~(1 << 18);

        if (!(feature > 41 && feature <= 327))
            result_gpr[5] &= ~(1 << 13);

        if (!(feature > 41 && feature <= 327 && feature <= 56))
            result_gpr[3] &= ~(1 << 28);

        if (!(feature > 41 && feature <= 327 && feature > 56))
            result_gpr[3] &= ~(1 << 29);

        if (!(feature > 41 && feature <= 327))
            result_gpr[3] &= ~(1 << 27);

        if (!(feature > 41 && feature <= 327))
            result_gpr[5] &= ~(1 << 12);

        if (!(feature > 41 && feature > 327 && feature <= 328))
            result_gpr[5] &= ~(1 << 0);

        if (!(feature > 41 && feature > 327 && feature <= 328))
            result_gpr[5] &= ~(1 << 1);

        if (!(feature > 41 && feature > 327 && feature <= 328))
            result_gpr[6] &= ~(1 << 31);

        if (!(feature > 41 && feature > 327 && feature <= 328))
            result_gpr[6] &= ~(1 << 20);

        if (!(feature > 41 && feature > 327 && feature > 328 && feature <= 480))
            result_gpr[4] &= ~(1 << 1);

        if (!(feature > 41 && feature > 327 && feature > 328 && feature > 480 && feature <= 506))
            result_gpr[4] &= ~(1 << 2);

        if (!(feature > 41 && feature > 327 && feature > 328 && feature > 480 && feature > 506))
            result_gpr[4] &= ~(1 << 3);

        if (!(feature <= 50))
            result_gpr[7] &= ~(1 << 13);

        if (!(feature <= 50))
            result_gpr[4] &= ~(1 << 16);

        if (!(feature <= 50))
            result_gpr[4] &= ~(1 << 17);

        if (!(feature <= 50))
            result_gpr[7] &= ~(1 << 17);

        if (!(feature <= 50))
            result_gpr[4] &= ~(1 << 14);

        if (!(feature <= 50))
            result_gpr[4] &= ~(1 << 15);

        if (!(feature <= 50))
            result_gpr[7] &= ~(1 << 6);

        if (!(feature > 50 && feature <= 54))
            result_gpr[6] &= ~(1 << 12);

        if (!(feature > 50 && feature <= 54))
            result_gpr[6] &= ~(1 << 13);

        if (!(feature > 50 && feature <= 54))
            result_gpr[7] &= ~(1 << 15);

        if (!(feature > 50 && feature <= 54))
            result_gpr[2] &= ~(1 << 11);

        if (!(feature > 50 && feature <= 54))
            result_gpr[2] &= ~(1 << 12);

        if (!(feature > 50 && feature <= 54))
            result_gpr[7] &= ~(1 << 1);

        if (!(feature > 50 && feature <= 54))
            result_gpr[7] &= ~(1 << 27);

        if (!(feature > 50 && feature <= 54))
            result_gpr[7] &= ~(1 << 28);

        if (!(feature > 50 && feature <= 54))
            result_gpr[7] &= ~(1 << 0);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature <= 62))
            result_gpr[7] &= ~(1 << 25);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature <= 62))
            result_gpr[7] &= ~(1 << 26);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 62))
            result_gpr[5] &= ~(1 << 5);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 62 && feature <= 66))
            result_gpr[2] &= ~(1 << 6);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 62 && feature > 66))
            result_gpr[2] &= ~(1 << 7);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature <= 60 && feature <= 59))
            result_gpr[7] &= ~(1 << 4);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature <= 60 && feature > 59))
            result_gpr[7] &= ~(1 << 5);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 60 && feature <= 75))
            result_gpr[7] &= ~(1 << 3);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 60 && feature > 75 && feature <= 238 && feature <= 218 && feature <= 190 && feature <= 88))
            result_gpr[4] &= ~(1 << 7);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 60 && feature > 75 && feature <= 238 && feature <= 218 && feature <= 190 && feature > 88))
            result_gpr[4] &= ~(1 << 8);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 60 && feature > 75 && feature <= 238 && feature <= 218 && feature > 190 && feature <= 197))
            result_gpr[5] &= ~(1 << 24);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 60 && feature > 75 && feature <= 238 && feature <= 218 && feature > 190 && feature > 197 && feature <= 199))
            result_gpr[5] &= ~(1 << 25);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 60 && feature > 75 && feature <= 238 && feature <= 218 && feature > 190 && feature > 197 && feature > 199 && feature <= 201))
            result_gpr[2] &= ~(1 << 8);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 60 && feature > 75 && feature <= 238 && feature <= 218 && feature > 190 && feature > 197 && feature > 199 && feature > 201 && feature <= 212))
            result_gpr[2] &= ~(1 << 9);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 60 && feature > 75 && feature <= 238 && feature <= 218 && feature > 190 && feature > 197 && feature > 199 && feature > 201 && feature > 212))
            result_gpr[2] &= ~(1 << 10);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 60 && feature > 75 && feature <= 238 && feature > 218))
            result_gpr[6] &= ~(1 << 11);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 60 && feature > 75 && feature > 238 && feature <= 245))
            result_gpr[6] &= ~(1 << 5);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 60 && feature > 75 && feature > 238 && feature > 245 && feature <= 261 && feature <= 260 && feature <= 253 && feature <= 252))
            result_gpr[2] &= ~(1 << 22);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 60 && feature > 75 && feature > 238 && feature > 245 && feature <= 261 && feature <= 260 && feature <= 253 && feature > 252))
            result_gpr[2] &= ~(1 << 23);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 60 && feature > 75 && feature > 238 && feature > 245 && feature <= 261 && feature <= 260 && feature > 253 && feature <= 257))
            result_gpr[0] &= ~(1 << 24);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 60 && feature > 75 && feature > 238 && feature > 245 && feature <= 261 && feature <= 260 && feature > 253 && feature > 257))
            result_gpr[0] &= ~(1 << 25);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 60 && feature > 75 && feature > 238 && feature > 245 && feature <= 261 && feature > 260))
            result_gpr[4] &= ~(1 << 25);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 60 && feature > 75 && feature > 238 && feature > 245 && feature > 261))
            result_gpr[5] &= ~(1 << 2);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 60 && feature > 75))
            result_gpr[7] &= ~(1 << 12);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature <= 62))
            result_gpr[7] &= ~(1 << 10);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature <= 62))
            result_gpr[0] &= ~(1 << 9);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature <= 62))
            result_gpr[0] &= ~(1 << 10);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature <= 62))
            result_gpr[0] &= ~(1 << 5);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 62 && feature <= 198 && feature <= 81))
            result_gpr[2] &= ~(1 << 25);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 62 && feature <= 198 && feature <= 81))
            result_gpr[2] &= ~(1 << 26);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 62 && feature <= 198 && feature > 81))
            result_gpr[2] &= ~(1 << 24);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 62 && feature > 198 && feature <= 209))
            result_gpr[5] &= ~(1 << 19);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 62 && feature > 198 && feature <= 209))
            result_gpr[5] &= ~(1 << 20);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature <= 282 && feature > 62 && feature > 198 && feature > 209))
            result_gpr[5] &= ~(1 << 18);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature <= 291 && feature <= 283))
            result_gpr[4] &= ~(1 << 26);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature <= 291 && feature > 283 && feature <= 290))
            result_gpr[4] &= ~(1 << 27);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature <= 291 && feature > 283 && feature > 290))
            result_gpr[4] &= ~(1 << 28);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature > 291 && feature <= 337 && feature <= 330 && feature <= 307 && feature <= 299 && feature <= 295 && feature <= 292))
            result_gpr[2] &= ~(1 << 30);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature > 291 && feature <= 337 && feature <= 330 && feature <= 307 && feature <= 299 && feature <= 295 && feature > 292))
            result_gpr[2] &= ~(1 << 31);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature > 291 && feature <= 337 && feature <= 330 && feature <= 307 && feature <= 299 && feature > 295))
            result_gpr[2] &= ~(1 << 29);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature > 291 && feature <= 337 && feature <= 330 && feature <= 307 && feature > 299))
            result_gpr[2] &= ~(1 << 27);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature > 291 && feature <= 337 && feature <= 330 && feature > 307 && feature <= 311))
            result_gpr[2] &= ~(1 << 28);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature > 291 && feature <= 337 && feature <= 330 && feature > 307 && feature > 311 && feature <= 313))
            result_gpr[1] &= ~(1 << 0);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature > 291 && feature <= 337 && feature <= 330 && feature > 307 && feature > 311 && feature > 313 && feature <= 316 && feature <= 314))
            result_gpr[1] &= ~(1 << 31);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature > 291 && feature <= 337 && feature <= 330 && feature > 307 && feature > 311 && feature > 313 && feature <= 316 && feature > 314))
            result_gpr[0] &= ~(1 << 0);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature > 291 && feature <= 337 && feature <= 330 && feature > 307 && feature > 311 && feature > 313 && feature > 316 && feature <= 323 && feature <= 322 && feature <= 320))
            result_gpr[1] &= ~(1 << 3);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature > 291 && feature <= 337 && feature <= 330 && feature > 307 && feature > 311 && feature > 313 && feature > 316 && feature <= 323 && feature <= 322 && feature > 320))
            result_gpr[1] &= ~(1 << 4);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature > 291 && feature <= 337 && feature <= 330 && feature > 307 && feature > 311 && feature > 313 && feature > 316 && feature <= 323 && feature > 322))
            result_gpr[1] &= ~(1 << 2);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature > 291 && feature <= 337 && feature <= 330 && feature > 307 && feature > 311 && feature > 313 && feature > 316 && feature > 323))
            result_gpr[1] &= ~(1 << 1);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature > 291 && feature <= 337 && feature > 330 && feature <= 332))
            result_gpr[3] &= ~(1 << 4);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature > 291 && feature <= 337 && feature > 330 && feature > 332))
            result_gpr[3] &= ~(1 << 5);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature <= 339 && feature > 282 && feature > 291 && feature > 337))
            result_gpr[6] &= ~(1 << 21);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature <= 352 && feature <= 347 && feature <= 341))
            result_gpr[1] &= ~(1 << 26);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature <= 352 && feature <= 347 && feature > 341 && feature <= 343))
            result_gpr[1] &= ~(1 << 27);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature <= 352 && feature <= 347 && feature > 341 && feature > 343))
            result_gpr[1] &= ~(1 << 28);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature <= 352 && feature > 347 && feature <= 348))
            result_gpr[1] &= ~(1 << 24);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature <= 352 && feature > 347 && feature > 348))
            result_gpr[1] &= ~(1 << 25);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature <= 352))
            result_gpr[6] &= ~(1 << 6);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 352 && feature <= 402 && feature <= 380 && feature <= 375 && feature <= 361 && feature <= 358))
            result_gpr[1] &= ~(1 << 18);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 352 && feature <= 402 && feature <= 380 && feature <= 375 && feature <= 361 && feature > 358 && feature <= 359))
            result_gpr[0] &= ~(1 << 1);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 352 && feature <= 402 && feature <= 380 && feature <= 375 && feature <= 361 && feature > 358 && feature > 359))
            result_gpr[0] &= ~(1 << 2);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 352 && feature <= 402 && feature <= 380 && feature <= 375 && feature <= 361))
            result_gpr[5] &= ~(1 << 11);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 352 && feature <= 402 && feature <= 380 && feature <= 375 && feature > 361 && feature <= 371))
            result_gpr[5] &= ~(1 << 31);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 352 && feature <= 402 && feature <= 380 && feature <= 375 && feature > 361 && feature > 371))
            result_gpr[4] &= ~(1 << 0);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 352 && feature <= 402 && feature <= 380 && feature > 375))
            result_gpr[5] &= ~(1 << 10);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 352 && feature <= 402 && feature > 380 && feature <= 388 && feature <= 387))
            result_gpr[3] &= ~(1 << 15);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 352 && feature <= 402 && feature > 380 && feature <= 388 && feature > 387))
            result_gpr[3] &= ~(1 << 16);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 352 && feature <= 402 && feature > 380 && feature > 388))
            result_gpr[5] &= ~(1 << 9);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 352 && feature > 402 && feature <= 403))
            result_gpr[7] &= ~(1 << 21);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 352 && feature > 402 && feature > 403 && feature <= 408 && feature <= 407))
            result_gpr[7] &= ~(1 << 22);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 352 && feature > 402 && feature > 403 && feature <= 408 && feature > 407))
            result_gpr[7] &= ~(1 << 23);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 352 && feature > 402 && feature > 403 && feature > 408 && feature <= 415 && feature <= 412))
            result_gpr[4] &= ~(1 << 9);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 352 && feature > 402 && feature > 403 && feature > 408 && feature <= 415 && feature > 412))
            result_gpr[4] &= ~(1 << 10);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 352 && feature > 402 && feature > 403 && feature > 408 && feature > 415 && feature <= 420 && feature <= 419))
            result_gpr[5] &= ~(1 << 3);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 352 && feature > 402 && feature > 403 && feature > 408 && feature > 415 && feature <= 420 && feature > 419))
            result_gpr[5] &= ~(1 << 4);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 352 && feature > 402 && feature > 403 && feature > 408 && feature > 415 && feature > 420 && feature <= 427))
            result_gpr[3] &= ~(1 << 6);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 352 && feature > 402 && feature > 403 && feature > 408 && feature > 415 && feature > 420 && feature > 427))
            result_gpr[3] &= ~(1 << 7);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature <= 404))
            result_gpr[4] &= ~(1 << 4);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature <= 430 && feature > 404))
            result_gpr[4] &= ~(1 << 5);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature > 430 && feature <= 432))
            result_gpr[2] &= ~(1 << 1);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature > 430 && feature <= 432))
            result_gpr[2] &= ~(1 << 2);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature > 430 && feature > 432 && feature <= 435 && feature <= 434))
            result_gpr[6] &= ~(1 << 2);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature > 430 && feature > 432 && feature <= 435 && feature > 434))
            result_gpr[6] &= ~(1 << 3);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature > 430 && feature > 432 && feature > 435 && feature <= 452 && feature <= 443 && feature <= 441 && feature <= 436))
            result_gpr[5] &= ~(1 << 27);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature > 430 && feature > 432 && feature > 435 && feature <= 452 && feature <= 443 && feature <= 441 && feature > 436))
            result_gpr[5] &= ~(1 << 28);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature > 430 && feature > 432 && feature > 435 && feature <= 452 && feature <= 443 && feature > 441))
            result_gpr[5] &= ~(1 << 26);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature > 430 && feature > 432 && feature > 435 && feature <= 452 && feature > 443 && feature <= 445 && feature <= 444))
            result_gpr[4] &= ~(1 << 20);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature > 430 && feature > 432 && feature > 435 && feature <= 452 && feature > 443 && feature <= 445 && feature > 444))
            result_gpr[4] &= ~(1 << 21);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature > 430 && feature > 432 && feature > 435 && feature <= 452 && feature > 443 && feature > 445 && feature <= 446))
            result_gpr[3] &= ~(1 << 11);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature > 430 && feature > 432 && feature > 435 && feature <= 452 && feature > 443 && feature > 445 && feature > 446))
            result_gpr[3] &= ~(1 << 12);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature > 430 && feature > 432 && feature > 435 && feature > 452 && feature <= 453))
            result_gpr[6] &= ~(1 << 14);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature > 430 && feature > 432 && feature > 435 && feature > 452 && feature > 453 && feature <= 454))
            result_gpr[2] &= ~(1 << 13);

        if (!(feature > 50 && feature > 54 && feature <= 455 && feature > 339 && feature > 430 && feature > 432 && feature > 435 && feature > 452 && feature > 453 && feature > 454))
            result_gpr[2] &= ~(1 << 14);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature <= 493 && feature <= 463 && feature <= 460))
            result_gpr[6] &= ~(1 << 17);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature <= 493 && feature <= 463 && feature > 460 && feature <= 462))
            result_gpr[4] &= ~(1 << 18);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature <= 493 && feature <= 463 && feature > 460 && feature > 462))
            result_gpr[4] &= ~(1 << 19);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature <= 493 && feature > 463 && feature <= 469))
            result_gpr[7] &= ~(1 << 31);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature <= 493 && feature > 463 && feature > 469 && feature <= 475 && feature <= 474 && feature <= 471))
            result_gpr[1] &= ~(1 << 7);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature <= 493 && feature > 463 && feature > 469 && feature <= 475 && feature <= 474 && feature > 471 && feature <= 472))
            result_gpr[1] &= ~(1 << 8);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature <= 493 && feature > 463 && feature > 469 && feature <= 475 && feature <= 474 && feature > 471 && feature > 472))
            result_gpr[1] &= ~(1 << 9);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature <= 493 && feature > 463 && feature > 469 && feature <= 475 && feature > 474))
            result_gpr[1] &= ~(1 << 6);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature <= 493 && feature > 463 && feature > 469 && feature > 475 && feature <= 492 && feature <= 488 && feature <= 487))
            result_gpr[1] &= ~(1 << 20);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature <= 493 && feature > 463 && feature > 469 && feature > 475 && feature <= 492 && feature <= 488 && feature > 487))
            result_gpr[1] &= ~(1 << 21);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature <= 493 && feature > 463 && feature > 469 && feature > 475 && feature <= 492 && feature > 488 && feature <= 491))
            result_gpr[1] &= ~(1 << 22);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature <= 493 && feature > 463 && feature > 469 && feature > 475 && feature <= 492 && feature > 488 && feature > 491))
            result_gpr[1] &= ~(1 << 23);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature <= 493 && feature > 463 && feature > 469 && feature > 475 && feature > 492))
            result_gpr[4] &= ~(1 << 29);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature <= 571 && feature <= 510 && feature <= 502 && feature <= 499))
            result_gpr[1] &= ~(1 << 12);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature <= 571 && feature <= 510 && feature <= 502 && feature > 499 && feature <= 500))
            result_gpr[1] &= ~(1 << 13);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature <= 571 && feature <= 510 && feature <= 502 && feature > 499 && feature > 500 && feature <= 501))
            result_gpr[1] &= ~(1 << 14);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature <= 571 && feature <= 510 && feature <= 502 && feature > 499 && feature > 500 && feature > 501))
            result_gpr[1] &= ~(1 << 15);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature <= 571 && feature <= 510 && feature > 502 && feature <= 503))
            result_gpr[0] &= ~(1 << 6);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature <= 571 && feature <= 510 && feature > 502 && feature > 503 && feature <= 506))
            result_gpr[0] &= ~(1 << 30);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature <= 571 && feature <= 510 && feature > 502 && feature > 503 && feature > 506))
            result_gpr[0] &= ~(1 << 31);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature <= 571 && feature > 510 && feature <= 517 && feature <= 516))
            result_gpr[5] &= ~(1 << 29);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature <= 571 && feature > 510 && feature <= 517 && feature > 516))
            result_gpr[5] &= ~(1 << 30);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature <= 571 && feature > 510 && feature > 517 && feature <= 549 && feature <= 546))
            result_gpr[3] &= ~(1 << 30);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature <= 571 && feature > 510 && feature > 517 && feature <= 549 && feature > 546))
            result_gpr[3] &= ~(1 << 31);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature <= 571 && feature > 510 && feature > 517 && feature > 549 && feature <= 550))
            result_gpr[2] &= ~(1 << 0);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature <= 571 && feature > 510 && feature > 517 && feature > 549 && feature > 550 && feature <= 553))
            result_gpr[1] &= ~(1 << 5);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature <= 571 && feature > 510 && feature > 517 && feature > 549 && feature > 550 && feature > 553 && feature <= 554))
            result_gpr[1] &= ~(1 << 16);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature <= 571 && feature > 510 && feature > 517 && feature > 549 && feature > 550 && feature > 553 && feature > 554))
            result_gpr[1] &= ~(1 << 17);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature <= 572))
            result_gpr[7] &= ~(1 << 2);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature <= 573))
            result_gpr[6] &= ~(1 << 19);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature > 573 && feature <= 591 && feature <= 574))
            result_gpr[4] &= ~(1 << 6);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature > 573 && feature <= 591 && feature > 574 && feature <= 582 && feature <= 578))
            result_gpr[3] &= ~(1 << 23);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature > 573 && feature <= 591 && feature > 574 && feature <= 582 && feature > 578))
            result_gpr[3] &= ~(1 << 24);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature > 573 && feature <= 591 && feature > 574 && feature > 582 && feature <= 583))
            result_gpr[3] &= ~(1 << 25);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature > 573 && feature <= 591 && feature > 574 && feature > 582 && feature > 583))
            result_gpr[3] &= ~(1 << 26);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature > 573 && feature > 591 && feature <= 637 && feature <= 635 && feature <= 634 && feature <= 617 && feature <= 613))
            result_gpr[0] &= ~(1 << 20);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature > 573 && feature > 591 && feature <= 637 && feature <= 635 && feature <= 634 && feature <= 617 && feature > 613))
            result_gpr[0] &= ~(1 << 21);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature > 573 && feature > 591 && feature <= 637 && feature <= 635 && feature <= 634 && feature > 617 && feature <= 628 && feature <= 626 && feature <= 624))
            result_gpr[0] &= ~(1 << 16);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature > 573 && feature > 591 && feature <= 637 && feature <= 635 && feature <= 634 && feature > 617 && feature <= 628 && feature <= 626 && feature > 624))
            result_gpr[0] &= ~(1 << 17);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature > 573 && feature > 591 && feature <= 637 && feature <= 635 && feature <= 634 && feature > 617 && feature <= 628 && feature > 626 && feature <= 627))
            result_gpr[0] &= ~(1 << 18);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature > 573 && feature > 591 && feature <= 637 && feature <= 635 && feature <= 634 && feature > 617 && feature <= 628 && feature > 626 && feature > 627))
            result_gpr[0] &= ~(1 << 19);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature > 573 && feature > 591 && feature <= 637 && feature <= 635 && feature <= 634 && feature > 617 && feature > 628 && feature <= 629))
            result_gpr[0] &= ~(1 << 14);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature > 573 && feature > 591 && feature <= 637 && feature <= 635 && feature <= 634 && feature > 617 && feature > 628 && feature > 629))
            result_gpr[0] &= ~(1 << 15);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature > 573 && feature > 591 && feature <= 637 && feature <= 635 && feature > 634))
            result_gpr[1] &= ~(1 << 30);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature > 573 && feature > 591 && feature <= 637 && feature > 635))
            result_gpr[1] &= ~(1 << 29);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature > 573 && feature > 591 && feature > 637 && feature <= 643))
            result_gpr[5] &= ~(1 << 14);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature > 573 && feature > 591 && feature > 637 && feature > 643 && feature <= 648))
            result_gpr[5] &= ~(1 << 15);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature > 573 && feature > 591 && feature > 637 && feature > 643 && feature > 648 && feature <= 650))
            result_gpr[3] &= ~(1 << 13);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature <= 653 && feature > 573 && feature > 591 && feature > 637 && feature > 643 && feature > 648 && feature > 650))
            result_gpr[3] &= ~(1 << 14);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature > 653 && feature <= 655))
            result_gpr[6] &= ~(1 << 4);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature > 653 && feature > 655 && feature <= 656))
            result_gpr[2] &= ~(1 << 17);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature <= 657 && feature > 571 && feature > 572 && feature > 653 && feature > 655 && feature > 656))
            result_gpr[2] &= ~(1 << 18);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature > 657 && feature <= 764 && feature <= 677 && feature <= 671))
            result_gpr[0] &= ~(1 << 26);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature > 657 && feature <= 764 && feature <= 677 && feature > 671))
            result_gpr[0] &= ~(1 << 27);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature > 657 && feature <= 764 && feature > 677 && feature <= 687 && feature <= 685))
            result_gpr[0] &= ~(1 << 3);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature > 657 && feature <= 764 && feature > 677 && feature <= 687 && feature > 685))
            result_gpr[0] &= ~(1 << 4);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature > 657 && feature <= 764 && feature > 677 && feature > 687 && feature <= 695))
            result_gpr[1] &= ~(1 << 19);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature > 657 && feature <= 764 && feature > 677 && feature > 687 && feature > 695 && feature <= 707 && feature <= 697))
            result_gpr[0] &= ~(1 << 22);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature > 657 && feature <= 764 && feature > 677 && feature > 687 && feature > 695 && feature <= 707 && feature > 697))
            result_gpr[0] &= ~(1 << 23);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature > 657 && feature <= 764 && feature > 677 && feature > 687 && feature > 695 && feature > 707 && feature <= 761))
            result_gpr[0] &= ~(1 << 7);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature > 657 && feature <= 764 && feature > 677 && feature > 687 && feature > 695 && feature > 707 && feature > 761))
            result_gpr[0] &= ~(1 << 8);

        if (!(feature > 50 && feature > 54 && feature > 455 && feature > 493 && feature > 657 && feature > 764))
            result_gpr[7] &= ~(1 << 11);

        if (!(feature <= 50))
            result_gpr[5] &= ~(1 << 6);

        if (!(feature <= 50))
            result_gpr[5] &= ~(1 << 7);

        if (!(feature > 50 && feature <= 69 && feature <= 56))
            result_gpr[5] &= ~(1 << 22);

        if (!(feature > 50 && feature <= 69 && feature > 56))
            result_gpr[5] &= ~(1 << 23);

        if (!(feature > 50 && feature <= 69))
            result_gpr[5] &= ~(1 << 21);

        if (!(feature > 50 && feature > 69 && feature <= 71))
            result_gpr[4] &= ~(1 << 23);

        if (!(feature > 50 && feature > 69 && feature > 71))
            result_gpr[4] &= ~(1 << 24);

        if (!(feature <= 95 && feature <= 69))
            result_gpr[6] &= ~(1 << 1);

        if (!(feature <= 95 && feature <= 69 && feature <= 56 && feature <= 50))
            result_gpr[1] &= ~(1 << 10);

        if (!(feature <= 95 && feature <= 69 && feature <= 56 && feature > 50))
            result_gpr[1] &= ~(1 << 11);

        if (!(feature <= 95 && feature <= 69 && feature <= 56 && feature <= 40))
            result_gpr[5] &= ~(1 << 16);

        if (!(feature <= 95 && feature <= 69 && feature <= 56 && feature > 40))
            result_gpr[5] &= ~(1 << 17);

        if (!(feature <= 95 && feature <= 69 && feature > 56))
            result_gpr[5] &= ~(1 << 8);

        if (!(feature <= 95 && feature <= 69 && feature <= 46))
            result_gpr[6] &= ~(1 << 9);

        if (!(feature <= 95 && feature <= 69 && feature > 46))
            result_gpr[6] &= ~(1 << 10);

        if (!(feature <= 95 && feature <= 69))
            result_gpr[7] &= ~(1 << 20);

        if (!(feature <= 95 && feature > 69 && feature <= 90))
            result_gpr[2] &= ~(1 << 20);

        if (!(feature <= 95 && feature > 69 && feature > 90))
            result_gpr[2] &= ~(1 << 21);

        if (!(feature <= 95 && feature > 69))
            result_gpr[2] &= ~(1 << 19);

        if (!(feature > 95 && feature <= 112))
            result_gpr[7] &= ~(1 << 29);

        if (!(feature > 95 && feature > 112 && feature <= 129))
            result_gpr[7] &= ~(1 << 30);

        if (!(feature > 95 && feature > 112 && feature > 129 && feature <= 178 && feature <= 156 && feature <= 153 && feature <= 139 && feature <= 136))
            result_gpr[4] &= ~(1 << 12);

        if (!(feature > 95 && feature > 112 && feature > 129 && feature <= 178 && feature <= 156 && feature <= 153 && feature <= 139 && feature > 136))
            result_gpr[4] &= ~(1 << 13);

        if (!(feature > 95 && feature > 112 && feature > 129 && feature <= 178 && feature <= 156 && feature <= 153 && feature > 139))
            result_gpr[4] &= ~(1 << 11);

        if (!(feature > 95 && feature > 112 && feature > 129 && feature <= 178 && feature <= 156 && feature > 153))
            result_gpr[6] &= ~(1 << 8);

        if (!(feature > 95 && feature > 112 && feature > 129 && feature <= 178 && feature > 156))
            result_gpr[6] &= ~(1 << 7);

        if (!(feature > 95 && feature > 112 && feature > 129 && feature > 178 && feature <= 190 && feature <= 188 && feature <= 183))
            result_gpr[0] &= ~(1 << 12);

        if (!(feature > 95 && feature > 112 && feature > 129 && feature > 178 && feature <= 190 && feature <= 188 && feature > 183))
            result_gpr[0] &= ~(1 << 13);

        if (!(feature > 95 && feature > 112 && feature > 129 && feature > 178 && feature <= 190 && feature > 188))
            result_gpr[0] &= ~(1 << 11);

        if (!(feature > 95 && feature > 112 && feature > 129 && feature > 178 && feature > 190 && feature <= 1158 && feature <= 219))
            result_gpr[4] &= ~(1 << 22);

        if (!(feature > 95 && feature > 112 && feature > 129 && feature > 178 && feature > 190 && feature <= 1158 && feature <= 219 && feature <= 207))
            result_gpr[4] &= ~(1 << 30);

        if (!(feature > 95 && feature > 112 && feature > 129 && feature > 178 && feature > 190 && feature <= 1158 && feature <= 219 && feature > 207 && feature <= 210))
            result_gpr[4] &= ~(1 << 31);

        if (!(feature > 95 && feature > 112 && feature > 129 && feature > 178 && feature > 190 && feature <= 1158 && feature <= 219 && feature > 207 && feature > 210))
            result_gpr[3] &= ~(1 << 0);

        if (!(feature > 95 && feature > 112 && feature > 129 && feature > 178 && feature > 190 && feature <= 1158 && feature > 219 && feature <= 229))
            result_gpr[6] &= ~(1 << 16);

        if (!(feature > 95 && feature > 112 && feature > 129 && feature > 178 && feature > 190 && feature <= 1158 && feature > 219 && feature > 229 && feature <= 294))
            result_gpr[6] &= ~(1 << 24);

        if (!(feature > 95 && feature > 112 && feature > 129 && feature > 178 && feature > 190 && feature <= 1158 && feature > 219 && feature > 229 && feature > 294 && feature <= 314))
            result_gpr[6] &= ~(1 << 25);

        if (!(feature > 95 && feature > 112 && feature > 129 && feature > 178 && feature > 190 && feature <= 1158 && feature > 219 && feature > 229 && feature > 294 && feature > 314 && feature <= 604))
            result_gpr[6] &= ~(1 << 26);

        if (!(feature > 95 && feature > 112 && feature > 129 && feature > 178 && feature > 190 && feature <= 1158 && feature > 219 && feature > 229 && feature > 294 && feature > 314 && feature > 604))
            result_gpr[6] &= ~(1 << 27);

        if (!(feature > 95 && feature > 112 && feature > 129 && feature > 178 && feature > 190 && feature > 1158))
            result_gpr[6] &= ~(1 << 15);

        if (!(feature <= 50))
            result_gpr[7] &= ~(1 << 16);

        if (!(feature > 50 && feature <= 56))
            result_gpr[6] &= ~(1 << 0);

        if (!(feature > 50 && feature <= 56))
            result_gpr[3] &= ~(1 << 3);

        if (!(feature > 50 && feature <= 56))
            result_gpr[3] &= ~(1 << 21);

        if (!(feature > 50 && feature <= 56))
            result_gpr[3] &= ~(1 << 22);

        if (!(feature > 50 && feature <= 56))
            result_gpr[3] &= ~(1 << 20);

        if (!(feature > 50 && feature <= 56))
            result_gpr[3] &= ~(1 << 2);

        if (!(feature > 50 && feature <= 56))
            result_gpr[3] &= ~(1 << 18);

        if (!(feature > 50 && feature <= 56))
            result_gpr[3] &= ~(1 << 19);

        if (!(feature > 50 && feature <= 56))
            result_gpr[3] &= ~(1 << 17);

        if (!(feature > 50 && feature <= 56))
            result_gpr[3] &= ~(1 << 1);

        if (!(feature > 50 && feature <= 56))
            result_gpr[3] &= ~(1 << 8);

        if (!(feature > 50 && feature <= 56))
            result_gpr[3] &= ~(1 << 9);

        if (!(feature > 50 && feature <= 56))
            result_gpr[3] &= ~(1 << 10);

        if (!(feature > 50 && feature > 56))
            result_gpr[7] &= ~(1 << 24);
        
        
        reg_cp(&result_write, &result_gpr, sizeof(result_write));
        remote_me_reg_write_signal_remote(&result_write, 34, 8, 0, 
                                          __xfer_reg_number(&result_xfer6, __nfp_meid(34, 8)) + (__ctx() * 32), 
                                          sizeof(result_xfer6), &local_signal);    
    }
    
    return 0;
}
