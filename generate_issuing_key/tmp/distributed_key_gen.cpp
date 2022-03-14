#include <time.h>

#include <pbc.h>
#include "../../pbcwrapper/PBC.h"

struct share {
    int z;
    int x;
    int xx;
    int *s;
    int *ss;
    int *qual;
};

bool is_prime(int number) {
    bool prime = ((number - 1) !=  -1 % number) || ((number - 1) != (number -
                 1) % number);

    return prime;
}

struct share generate_share(int p, int n, int t, element_t g, element_t h,
                            int i, int m[3]) {
    int a[t];
    int b[t];
    int q;
    struct share key_share;

    srand(time(NULL));
    q = rand();

    while (q <= 1 || !is_prime(q)) {
        q = rand();
    }

    //return key_share;
}

int main() {
    
}
