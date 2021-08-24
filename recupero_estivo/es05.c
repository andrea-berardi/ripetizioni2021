#include <stdio.h>

#define DIM 20

int main(void) {
    float massa[DIM]; // array dei pesi, DIM è fisso perché fornito dal testo dell'esercizio

    for (size_t i = 0; i < DIM; ++i) {
        printf("Inserisci il peso del %zu° iscritto: ", i + 1);
        scanf("%f", &massa[i]);

        printf("\n"); // solo per separare un input dal successivo
    }

    /*
        es. 1
    */
    int c = 0; // contatore di quanti iscritti hanno una massa fra 80 e 100 Kg inclusi
    for (size_t i = 0; i < DIM; ++i)
        if (massa[i] >= 80 && massa[i] <= 100)
            ++c;
    printf("Ci sono %d iscritti con una massa fra 80 e 100 Kg inclusi\n", c);

    /*
        es. 2
    */
    c = 0; // contatore di quanti iscritti hanno una massa minore di 90 Kg, azzerando il precedente contatore
    for (size_t i = 0; i < DIM; ++i)
        if (massa[i] < 90)
            ++c;
    printf("Ci sono %d iscritti con una massa inferiore a 90 Kg\n", c);

    /*
        es. 3
    */
    float totale = 0.0; // variabile in cui salveremo il totale di tutti gli iscritti, per calcolare la media
    for (size_t i = 0; i < DIM; ++i)
        totale += massa[i];
    printf("La massa media degli iscritti è %.2f\n", totale / DIM);

    /*
        es. 4
    */
    totale = 0.0; // azzeriamo la variabile per salvarci la massa totale di chi è oltre 100 Kg
    c = 0; // azzeriamo il contatore di prima per riutilizzarlo, ci serve per calcolare la media
    for (size_t i = 0; i < DIM; ++i)
        if (massa[i] > 100)
            totale += massa[i], ++c;
    printf("La massa media degli iscritti con massa oltre 100Kg è %.2f\n", totale / c);

    return 0;
}