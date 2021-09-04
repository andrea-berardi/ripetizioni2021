// es. 2, pag. 302

#include <stdio.h>

const float φ = 2.598; // numero fisso dell'area dell'esagono (φ, Phi)

int main(void) {
    float l;
    printf("Lato dell'esagono: ");
    scanf("%f", &l);
    printf("2p = %.1f\nA = %.1f\n", l * 6, l * l * φ);

    return 0;
}