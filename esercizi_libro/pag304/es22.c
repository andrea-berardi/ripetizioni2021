#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n; // numero di prodotti

    printf("Numero di prodotti: ");
    scanf("%d", &n);

    float *prezzo = malloc(sizeof(float) * n);
    if (prezzo == NULL) { // se è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(1); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    for (size_t i = 0; i < n; ++i) {
        printf("Prezzo del %zu° prodotto: ", i + 1);
        scanf("%f", &prezzo[i]);
    }
    printf("\n");

    float max = prezzo[0];
    for (size_t i = 0; i < n; ++i)
        if (prezzo[i] > max)
            max = prezzo[i];
    printf("Prezzo maggiore: %.2f\n", max);

    return 0;
}