#include "generate_issuing_key.h"

#include <cmath>
#include <ctime>
#include <iostream>

/*long long int mulmod(long long int a, long long int b, long long int m) {
    long long int x = 0;
    long long int y = a % m;

    while (b > 0) {
       if (b % 2 == 1) {
          x = (x + y) % m;
       }

       y = (y * 2) % m;
       b /= 2;
    }

    return x % m;
}


long long int modulo(long long int base, long long int e, long long int m) {
    long long int x = 1;
    long long int y = base;

    while (e > 0) {
       if (e % 2 == 1)
          x = (x * y) % m;
          y = (y * y) % m;
          e = e / 2;
    }

    return x % m;
}

bool is_prime(long long int number) {
    if (number < 2) {
       return false;
    }

    if (number != 2 && number % 2 == 0) {
       return false;
    }

    long long int s = number - 1;

    while (s % 2 == 0) {
       s /= 2;
    }

    for (int i = 0; i < 10; i++) {
       long long int a = rand() % (number - 1) + 1;
       long long int temp = s;
       long long int mod = modulo(a, temp, number);

       while (temp != number - 1 && mod != 1 && mod != number - 1) {
          mod = mulmod(mod, mod, number);
          temp *= 2;
       }

       if (mod != number - 1 && temp % 2 == 0) {
          return false;
       }
    }
    return true;
}*/

struct issue::share issue::generate_share(mpz_t p, int n, int t, element_t g,
                                   element_t h, int id, int m[3]) {
    int a[t];
    int b[t];
    int zi;
    mpz_t c[t];
    mpz_t q;
    struct share key_share;
    bool dummy;
    mpz_t decrement_p;
    mpz_t mpz_g;
    mpz_t mpz_h;

    mpz_init(decrement_p);
    mpz_sub_ui(decrement_p, p, 1);
    mpz_init(q);
    mpz_cdiv_q_ui(q, decrement_p, 28); // prime number
    srand(time(NULL));

    for (int j = 0; j < t; j++) {
        a[j] = rand() % 10000; // Limited to 10000 for faster performance
        b[j] = rand() % 10000; // Theoretically, goes up to q
    }

    zi = a[0];
    mpz_init(mpz_g);
    mpz_init(mpz_h);
    element_to_mpz(mpz_g, g);
    element_to_mpz(mpz_h, h);

    for (int j = 0; j < t; j++) {
        mpz_init(c[j]);
        mpz_set_ui(c[j], 1);
        
        for (int i = 0; i < a[j]; i++) {
            mpz_mul(c[j], c[j], mpz_g);

            if (mpz_cmp(c[j], q) > 0) {
                mpz_cdiv_r(c[j], c[j], q);
            }
        }
        
        for (int i = 0; i < b[j]; i++) {
            mpz_mul(c[j], c[j], mpz_h);

            if (mpz_cmp(c[j], q) > 0) {
                mpz_cdiv_r(c[j], c[j], q);
            }
        }
    }

    return key_share;
}
