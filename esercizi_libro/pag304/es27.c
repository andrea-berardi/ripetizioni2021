// es. 27, pag. 304

#include <stdio.h>

int main(void) {
    int n;
    printf("Numero di tappe: ");
    scanf("%d", &n);

    float tot = 0.0;
    for (size_t i = 0; i < n; ++i) {
        float tappa;
        printf("Distanza tappa %zu: ", i + 1);
        scanf("%f", &tappa);

        tot += tappa;
    }
    printf("Lunghezza totale percorso: %.2f\n", tot);

    return 0;
}