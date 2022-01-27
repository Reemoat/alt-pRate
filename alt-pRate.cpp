#include "headers/alt-pRate.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

//#include <pbc.h>
//#include "pbcwrapper/PBC.h"
using namespace std;
using namespace public_param;

/*struct public_parameters {
    int n;
    int t;
    int v;
    mpz_t p;
    pairing_t e;
    element_t g_1;
    element_t g_2;
    element_t u;
};*/

void extract_order(char param[], mpz_t p) {
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
}

int main() { //int argc, char *argv[]) {
    //char *ptr;
    //int v = strtol(argv[1], &ptr, 10);
    int i;
    public_parameters pp;
    FILE *fp;
    char param[1024];
    int output;
    fp = fopen("headers/pbc-0.5.14/param/f.param", "r");
    size_t count = fread(param, 1, 1024, fp);

    if (!count) {
        pbc_die("input error");
    }

    output = pairing_init_set_buf(pp.e, param, count);

    if (output != 0) {
      return EXIT_FAILURE;
    }

    mpz_init(pp.p);
    extract_order(param, pp.p);
    pp.n = 3;
    pp.t = 1;
    pp.v = 5;
    element_init_G1(pp.g_1, pp.e);
    element_init_G1(pp.u, pp.e);
    element_init_G2(pp.g_2, pp.e);
    srand(time(0));
    element_random(pp.g_1);
    element_random(pp.u);
    element_random(pp.g_2);
    fclose(fp);

    return 0;
}
