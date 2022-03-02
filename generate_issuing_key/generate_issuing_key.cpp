#include "generate_issuing_key.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

#include <pbc.h>
#include "../pbcwrapper/PBC.h"
using namespace issue;
using namespace std;

int main() {
    int i = 0;
    char param[1024];
    pairing_t e;
    int output;
    element_t h;
    isk isk_i;
    FILE *fp = fopen("../pbc-0.5.14/param/f.param", "r");
    size_t count = fread(param, 1, 1024, fp);

    if (!count) {
        pbc_die("input error");
    }

    output = pairing_init_set_buf(e, param, count);
 
    if (output != 0) {
        return EXIT_FAILURE;
    }

    /*ifstream public_parameters("../public_parameters");

    if (!public_parameters.is_open()) {
        cout << "Unable to open file";
        return EXIT_FAILURE;
    }

    param[i] = public_parameters.get();

    while (param[i] != 'm') {
        i++;
        param[i] = public_parameters.get();
    }

    param[i] = '\n';*/

    pairing_init_set_buf(e, param, count);
    element_init_G2(h, e);
    element_random(h);
    fclose(fp);
    //public_parameters.close();

    return 0;
}
