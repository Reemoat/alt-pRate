#include "generate_issuing_key.h"

#include <cstdlib>
#include <iostream>
#include <fstream>

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
    int n;
    int t;
    char m[2];
    mpz_t p;
    isk isk_i;

    pp = initialize_pairing();
    mpz_init(p);
    get_order(p);
    extract_element(g2, element_name, pp.e);
    element_init_G2(h, pp.e);
    element_random(h);
    v = extract_int('v');
    n = extract_int('n');
    t = extract_int('t');
    m[0] = 'm';

    int manager[n];

    for (int i = 1; i <= n; i++) {
        m[1] = '0' + i;
        manager[i-1] = extract_int(m);
    }

    return 0;
}
