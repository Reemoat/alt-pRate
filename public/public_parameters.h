#ifndef ALTPRATE_PUBLIC_PUBLIC_PARAMETERS_H_
#define ALTPRATE_PUBLIC_PUBLIC_PARAMETERS_H_
#include <gmpxx.h>
#include <pbc.h>
#include "../pbcwrapper/PBC.h"

namespace alt_prate {

struct pairing_parameters {
    char param[1024];
    pairing_t e;
};

struct pairing_parameters initialize_pairing();
void extract_element(element_t g, char name[2], pairing_t e);
int extract_int(char name);
void get_order(mpz_t order);

} // alt_prate

#endif  // ALTPRATE_PUBLIC_PUBLIC_PARAMETERSS_H_


