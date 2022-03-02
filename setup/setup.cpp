#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include <pbc.h>
#include "../pbcwrapper/PBC.h"
using namespace std;

/*void extract_order(char param[], mpz_t p) {
    int i = 0;
    int j = 0;
    int length = 0;
    int start;
    
    while (param[i] != 'r') {
        i++;
    }

    i += 2;
    start = i;

    while(param[i] != '\n') {
       length++;
       i++;
    }

    char order[length+1];

    order[length] = '\n';
    i = start;

    while (param[i] != '\n') {
        order[j] = param[i];
        i++;
        j++;
    }

    mpz_set_str(p, order, 10);
}*/

int main() { //int argc, char *argv[]) {
    //char *ptr;
    //int v = strtol(argv[1], &ptr, 10);
    //public_parameters pp;
    char param[1024];
    int managers[3];
    int n;
    int t;
    int v;
    //mpz_t p;
    pairing_t e;
    element_t g_1;
    element_t g_2;
    element_t u;
    int output;
    FILE *fp = fopen("../pbc-0.5.14/param/f.param", "r");
    size_t count = fread(param, 1, 1024, fp);
    ofstream output_file;

    if (!count) {
        pbc_die("input error");
    }

    output = pairing_init_set_buf(e, param, count);

    if (output != 0) {
      return EXIT_FAILURE;
    }

    //mpz_init(p);
    //extract_order(param, p);
    n = 3;
    t = 1;

    for (int i=0; i < n; i++) {
        managers[i] = i + 1;
    }

    v = 5;
    element_init_G1(g_1, e);
    element_init_G1(u, e);
    element_init_G2(g_2, e);
    element_random(g_1);
    element_random(u);
    element_random(g_2);
    fclose(fp);
    output_file.open("../public_parameters");
    output_file << "m1: " << managers[0] << ", m2: " << managers[1]
        << ", m3: " << managers[2] << "\nn:" << n << "\nt:" << t << "\nv:" <<
        v << "\n";
    output_file.close();
    fp = fopen("../public_parameters", "a");
    //gmp_fprintf(fp, "p: %Zd\n", p);
    element_fprintf(fp, "g1: %B\ng2: %B\nu: %B\n", g_1, g_2, u);

    return 0;
}
