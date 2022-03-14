#ifndef GENERATE_ISSUING_KEY_H_
#define GENERATE_ISSUING_KEY_H_
#include <cstdlib>

#include <pbc.h>
#include "../pbcwrapper/PBC.h"

namespace issue {

struct isk {
    int i;
    int x;
    int y[8];
};

struct share {
    int z;
    int x;
    int xx;
    int *s;
    int *ss;
    int *qual;
};

struct share generate_share(mpz_t p, int n, int t, element_t g, 
                            element_t h, int i, int m[3]);


}; // namespace issue

#endif // GENERATE_ISSUING_KEY_H_
