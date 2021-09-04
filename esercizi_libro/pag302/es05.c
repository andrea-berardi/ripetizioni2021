// es. 5, pag. 302

#include <stdio.h>
#include <math.h>

int main(void) {
    float a, b, c;
    printf("Inserisci i lati del triangolo: ");
    scanf("%f%f%f", &a, &b, &c);

    float p = (a + b + c) / 2.0; // semiperimetro

    printf("Area: %.1f\n", sqrt(p * (p - a) * (p - b) * (p - c)));

    return 0;
}