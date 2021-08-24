#include <stdio.h>

#define DIM 20

int main(void) {
    int a[DIM]; // array dove salveremo i valori
    
    printf("Inserisci %d valori interi positivi\n", DIM);
    for (size_t i = 0; i < DIM; ++i) { // qua carichiamo i nostri valori
        printf("Numero %zu: ", i + 1);
        scanf("%d", &a[i]);

        printf("\n"); // solo per separare un input dal successivo
    }

    int mag = 0; // contatore di quanti valori sono maggiori del primo valore
    int min = 0; // contatore di quanti valori sono minori dell'ultimo valore
    for (size_t i = 0; i < DIM; ++i) {
        if (a[i] > a[0]) ++mag;
        if (a[i] < a[DIM - 1]) ++min;
    }
    printf("%d valori sono maggiori del primo valore dell'array\n", mag);
    printf("%d valori sono minori dell'ultimo valore dell'array\n", min);

    return 0;
}