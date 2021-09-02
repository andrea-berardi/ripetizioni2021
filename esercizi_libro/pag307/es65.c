#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float peso;
    float volume;
} Oggetto;

int main(void) {
    int n; // numero di oggetti
    printf("Numero di oggetti: ");
    scanf("%d", &n);

    Oggetto *oggetti = malloc(sizeof(Oggetto) * n);
    if (oggetti == NULL) { // se il vettore è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(1); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    for (size_t i = 0; i < n; ++i) {
        printf("Peso del %zu° oggetto: ", i + 1);
        scanf("%f", &oggetti[i].peso);

        printf("Volume del %zu° oggetto: ", i + 1);
        scanf("%f", &oggetti[i].volume);

        printf("\n");
    }

    printf("Peso specifico oggetti\n");
    for (size_t i = 0; i < n; ++i)
        printf("%zu) %.2f N/m³\n", i + 1, oggetti[i].peso / oggetti[i].volume);
    printf("Totale oggetti: %d\n", n);

    return 0;
}