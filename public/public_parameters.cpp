#include "public_parameters.h"

#include <fstream>
#include <string>

struct alt_prate::pairing_parameters alt_prate::initialize_pairing() {
    struct pairing_parameters pp;
    int output;
    FILE *fp = fopen("../pbc-0.5.14/param/f.param", "r");
    size_t count = fread(pp.param, 1, 1024, fp);

    if (!count) {
        pbc_die("input error");
    }

    pairing_init_set_buf(pp.e, pp.param, count);
    fclose(fp);

    return pp;
}

void alt_prate::extract_element(element_t g, char name[2], pairing_t e) {
    int i = 0;
    char previous;
    char current;
    char parameter[1024];
    ifstream public_parameters("../public_parameters");

    element_init_G2(g, e);
    public_parameters.get(previous);
    public_parameters.get(current);

    while (!(previous == name[0] && current == name[1])) {
        previous = current;
        public_parameters.get(current);
    }
    
    public_parameters.get(current);
    public_parameters.get(parameter[i]);
    
    while (parameter[i] != '\n') {
        i++;
        public_parameters.get(parameter[i]);
    }

    parameter[i] = '\0';
    element_set_str(g, parameter, 10);
    public_parameters.close();
}

int alt_prate::extract_int(char name) {
    int i = 0;
    char parameter[1024];
    int int_param;
    char current;
    ifstream public_parameters("../public_parameters");

    public_parameters.get(current);

    while (current != name) {
        public_parameters.get(current);
    }

    public_parameters.get(current);
    public_parameters.get(parameter[i]);

    while (parameter[i] != '\n') {
        i++;
        public_parameters.get(parameter[i]);
    }

    parameter[i] = '\0';
    int_param = strtol(parameter, NULL, 10);
    public_parameters.close();

    return int_param;
}

int alt_prate::extract_int(char name[2]) {
    int i = 0;
    char parameter[1024];
    int int_param;
    char previous;
    char current;
    ifstream public_parameters("../public_parameters");

    public_parameters.get(previous);
    public_parameters.get(current);

    while (!(previous == name[0] && current == name[1])) {
        previous = current;
        public_parameters.get(current);
    }

    public_parameters.get(current);
    public_parameters.get(parameter[i]);

    while (parameter[i] != '\n') {
        i++;
        public_parameters.get(parameter[i]);
    }

    parameter[i] = '\0';
    int_param = strtol(parameter, NULL, 10);
    public_parameters.close();

    return int_param;
}

void alt_prate::get_order(mpz_t order) {
    ifstream parameters("../pbc-0.5.14/param/f.param");
    char current;
    char r[1024];
    int i = 0;

    parameters.get(current);

    while (current != 'r') {
        parameters.get(current);
    }

    parameters.get(current);
    parameters.get(r[i]);

    while (r[i] != '\n') {
        i++;
        parameters.get(r[i]);
    }

    r[i] = '\0';
    mpz_set_str(order, r, 10);
    parameters.close();
}
