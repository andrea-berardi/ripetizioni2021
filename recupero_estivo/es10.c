#include <stdio.h>

#define GIORNI 31 // gennaio ha 31 giorni

int main(void) {
    float incasso[GIORNI]; // qui salveremo gli incassi del mese

    for (size_t i = 0; i < GIORNI; ++i) {
        printf("Inserisci l'incasso del giorno %zu: ", i + 1);
        scanf("%f", &incasso[i]);

        printf("\n"); // solo per separare un input dal successivo
    }

    /*
        es. 1
    */
    float tot = 0.0; // qui salveremo l'incasso totale
    for (size_t i = 0; i < GIORNI; ++i)
        tot += incasso[i];
    printf("L'incasso totale è: %.2f€\n", tot);

    /*
        es. 2
    */
    int count = 0; // contatore di quanti giorni con l'incasso fra 200 e 500
    for (size_t i = 0; i < GIORNI; ++i)
        if (incasso[i] >= 200 && incasso[i] <= 500)
            ++count;
    printf("L'incasso è stato fra 200 e 500 per %d volte\n", count);

    /*
        es. 3
    */
    count = 0; // azzeriamo il contatore, e salveremo il numero di giorni con incasso nullo
    for (size_t i = 0; i < GIORNI; ++i)
        if (incasso[i] == 0)
            ++count;
    printf("L'incasso è stato nullo per %d volte\n", count);

    /*
        es. 4
    */
    float max = incasso[0]; // qui salviamo l'incasso massimo
    float min = incasso[0]; // qui salviamo l'incasso minimo
    for (size_t i = 0; i < GIORNI; ++i) {
        if (incasso[i] > max) // se l'incasso del giorni i è maggiore del max...
            max = incasso[i]; // ...salvalo nel max
        if (incasso[i] < min) // se l'incasso del giorni i è minore del min...
            min = incasso[i]; // ...salvalo nel min
    }
    printf("L'incasso massimo è %.2f€, l'incasso minimo è %.2f€\n", max, min);

    /*
        es. finale (stampare i giorni con più di 1000€ di incasso)
    */
   printf("ELENCO GIORNI CON INCASSO >1000 EURO\n");
    for (size_t i = 0; i < GIORNI; ++i)
        if (incasso[i] > 1000)
            printf("%zu\n", i + 1);

    return 0;
}