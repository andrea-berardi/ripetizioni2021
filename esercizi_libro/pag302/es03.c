// es. 3, pag. 302

#include <stdio.h>
#include <math.h>

int main(void) {
    float r;
    printf("Raggio del cerchio: ");
    scanf("%f", &r);
    printf("C = %.2f\nA = %.2f\n", 2.0 * r * M_PI, r * r * M_PI);

    return 0;
}