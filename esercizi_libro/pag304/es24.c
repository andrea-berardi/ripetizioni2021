// es. 24, pag. 304

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n; // numero di veicoli

    printf("Numero di veicoli: ");
    scanf("%d", &n);

    float *km = malloc(sizeof(float) * n); // Km percorsi
    float *litri = malloc(sizeof(float) * n); // Litri usati

    for (size_t i = 0; i < n; ++i) {
        printf("Km percorsi dal %zu° veicolo: ", i + 1);
        scanf("%f", &km[i]);

        printf("Litri consumati dal %zu° veicolo: ", i + 1);
        scanf("%f", &litri[i]);

        printf("\n"); // per separare l'input di un veicolo dall'altro
    }

    printf("Consumo medio di carburante dei veicoli:\n");
    for (size_t i = 0; i < n; ++i) {
        printf("%zu) %.2f Km/l <=> %.2f l/Km\n", i + 1, km[i] / litri[i], litri[i] / km[i]);
    }

    return 0;
}