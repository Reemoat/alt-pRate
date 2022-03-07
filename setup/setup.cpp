#include <cstdlib>
#include <fstream>
#include <iostream>

#include "../public/public_parameters.h"
using namespace std;
using namespace alt_prate;

int main() {
    int managers[3];
    int n;
    int t;
    int v;
    struct pairing_parameters pp;
    element_t g_1;
    element_t g_2;
    element_t u;
    FILE *fp;
    ofstream output_file;

    pp = initialize_pairing();
    n = 3;
    t = 1;

    for (int i=0; i < n; i++) {
        managers[i] = i + 1;
    }

    v = 5;
    element_init_G1(g_1, pp.e);
    element_init_G1(u, pp.e);
    element_init_G2(g_2, pp.e);
    element_random(g_1);
    element_random(u);
    element_random(g_2);
    output_file.open("../public_parameters");
    output_file << "m1:" << managers[0] << ", m2:" << managers[1]
        << ", m3:" << managers[2] << "\nn:" << n << "\nt:" << t << "\nv:" <<
        v << "\n";
    output_file.close();
    fp = fopen("../public_parameters", "a");
    element_fprintf(fp, "g1:%B\ng2:%B\nu:%B\n", g_1, g_2, u);
    fclose(fp);

    return 0;
}
