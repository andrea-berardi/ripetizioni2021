#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 50

int main(void) {
    int n = 0; // numero di vini comprati
    while (n <= 0 || n > MAX_DIM) { // continua a chiedere quanti vini ha preso fino a che non abbiamo un numero fra 0 e MAX_DIM
        printf("Quanti vini hai acquistato? ");
        scanf("%d", &n);

        if (n <= 0 || n > MAX_DIM)
            printf("Immetti un valore maggiore di 0 e minore o uguale a 50\n");
    }

    /*
        alloco un array di dimensione n per i vini
    */
    float *vini; // array dei prezzi dei vini
    vini = (float*)malloc(sizeof(float) * n); // allochiamo n blocchi di memoria di tipo float
    if (vini == NULL) { // se il vettore è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(1); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    /*
        popoliamo l'array chiedendo n volte il prezzo di ogni vino,
        siccome ogni vino può avere un prezzo diverso dall'altro
    */
    for (size_t i = 0; i < n; ++i) {
        printf("Immetti il prezzo del %zu° vino: ", i + 1); // +1 perché noi contiamo da 1, non da 0
        scanf("%f", &vini[i]);

        printf("\n"); // solo per separare un input dal successivo
    }

    /*
        es. 1
    */
    float totale = 0.0; // prezzo totale di tutti i vini
    for (size_t i = 0; i < n; ++i)
        totale += vini[i];
    printf("La spesa totale è: %.2f€\n", totale);

    /*
        es. 2
    */
    int contatore = 0; // contatore di quanti vini costano oltre la media del prezzo di tutti i vini
    for (size_t i = 0; i < n; ++i)
        if (vini[i] > totale / n) // se il vino all'indice i ha un costo oltre la media (costo totale / numero di vini)
            ++contatore;
    printf("Vini che costano oltre la media di %.2f€: %d\n", totale / n, contatore);

    /*
        es. 3
    */
    contatore = 0; // azzeriamo il contatore precedente per riutilizzarlo senza allocare ulteriore memoria
    for (size_t i = 0; i < n; ++i) // scorriamo l'array di vini per controllarli uno a uno
        if (vini[i] > 50.0) // se il vino costa più di 50€ aumentiamo il contatore
            ++contatore;

    if (contatore > 0) // se il contatore è maggiore di 0 abbiamo almeno un vino che costa oltre 50€
        printf("Ci sono %d vini che costano più di 50€\n", contatore);
    else
        printf("Non ci sono vini che costano più di 50€\n");

    /*
        Pulizia finale, non necessaria in questo caso, ma è buona pratica
    */
    free(vini); // è buona regola deallocare la memoria che non si usa più, dopo aver usato malloc()
    vini = NULL; // segniamo anche la variabile come NULL

    return 0;
}