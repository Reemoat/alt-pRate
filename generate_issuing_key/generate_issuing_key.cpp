#include "generate_issuing_key.h"

#include <iostream>
#include <fstream>

#include "../public/public_parameters.h"
using namespace issue;
using namespace std;
using namespace alt_prate;

int main(int argc, char* argv[]) {
    struct pairing_parameters pp;
    element_t h;
    element_t g2;
    char element_name[] = "g2";
    int id;
    int v;
    int n;
    int t;
    char m[2];
    mpz_t p;
    isk isk_i;
    struct share key_share;

    if (argc != 2) {
        cout << "Pass one integer as an argument" << endl;
        return EXIT_FAILURE;
    } else {
        id = argv[1][0] - '0';
    }

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

    key_share = generate_share(p, n, t, g2, h, id, manager);

    return 0;
}
