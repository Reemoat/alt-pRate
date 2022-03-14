#include "generate_issuing_key.h"

#include <cmath>
#include <ctime>
#include <iostream>

long long int mulmod(long long int a, long long int b, long long int m) {
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
}

struct issue::share issue::generate_share(mpz_t p, int n, int t, element_t g,
                                   element_t h, int id, int m[3]) {
    int a[t];
    int b[t];
    long long int q;
    struct share key_share;
    bool dummy;

    srand(time(NULL));
    q = rand();

    while (q <= 3 || !is_prime(q)) {
        q = rand();
    }

    return key_share;
}
