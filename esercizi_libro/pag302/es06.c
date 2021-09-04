// es. 6, pag. 302

#include <stdio.h>

#define N 3 // numero di oggetti, dato dall'esercizio

int main(void) {
    float peso[N];

    for (size_t i = 0; i < N; ++i) {
        printf("Peso del %zu° oggetto: ", i + 1);
        scanf("%f", &peso[i]);
    }
    printf("\n");

    float tot = 0.0; // totale pesi
    for (size_t i = 0; i < N; ++i)
        tot += peso[i];
    printf("Peso medio: %.2fKg\n", tot / N);

    return 0;
}