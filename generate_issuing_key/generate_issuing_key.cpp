#include "generate_issuing_key.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

#include <pbc.h>
#include "../pbcwrapper/PBC.h"

#include "../public/public_parameters.h"
using namespace issue;
using namespace std;
using namespace alt_prate;

int main() {
    struct pairing_parameters pp;
    element_t h;
    element_t g2;
    char element_name[] = "g2";
    int v;
    mpz_t p;
    isk isk_i;

    pp = initialize_pairing();
    mpz_init(p);
    get_order(p);
    extract_element(g2, element_name, pp.e);
    element_init_G2(h, pp.e);
    element_random(h);
    v = extract_int('v');

    return 0;
}
