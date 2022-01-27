#include <pbc.h>
#include "pbcwrapper/PBC.h"

#ifndef ALTPRATE_HEADERS_ALTPRATE_H_
#define ALTPRATE_HEADERS_ALTPRATE_H_

namespace public_param {
    struct public_parameters {
        int n;
        int t;
        int v;
        mpz_t p;
        pairing_t e;
        element_t g_1;
        element_t g_2;
        element_t u;
    };
} // namespace public_param

#endif // ALTPRATE_HEADERS_ALTPRATE_H_
