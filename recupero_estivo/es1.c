#include <stdio.h>

#define DIM 10 // l'array sarà di 10 diplomati

int main(void) {
    int diplomati[DIM]; // lista voti diplomati

    /*
        Popoliamo l'array
    */
    for (size_t i = 0; i < DIM; ++i) { // ciclo per popolare l'array
        printf("Inserisci il voto del diplomato %zu: ", i + 1); // +1 perché normalmente contiamo da 1, non da 0
        scanf("%d", &diplomati[i]);
    }
    printf("\n");

    /*
        es. 1
    */
    int c_100 = 0; // contatore di diplomati con 100
    for (size_t i = 0; i < DIM; ++i) // ciclo che conta i diplomati con 100
        if (diplomati[i] == 100) // se un diplomato ha 100, aumentiamo il contatore
            ++c_100;
    printf("I diplomati con 100 sono: %d\n", c_100);

    /*
        es. 2
    */
    int c_70 = 0; // contatore di diplomati con 70 meno
    for (size_t i = 0; i < DIM; ++i) // ciclo che conta i diplomati con 70 o meno
        if (diplomati[i] <= 70) // se un diplomato ha 70 o meno, aumentiamo il contatore
            ++c_70;
    printf("I diplomati con 70 o meno sono: %d\n", c_70);

    /*
        es. 3
    */
    int c_90_99 = 0; // contatore di diplomati con voto da 90 a 99. Non fino a 100 perché sommiamo c_100
    for (size_t i = 0; i < DIM; ++i) // ciclo che conta i diplomati con 100
        if (diplomati[i] >= 90 && diplomati[i] < 100) // se un diplomato ha da 99 a 100 ESCLUSO, aumentiamo il contatore
            ++c_90_99;
    printf("I diplomati con voto da 90 a 100 sono: %d\n", c_90_99 + c_100); // sommando i due contatori abbiamo i diplomati da 90 a 100

    /*
        es. 4
    */
    float media = 0.0; // dato che conterrà la media di tutti i voti dei diplomati
    for (size_t i = 0; i < DIM; ++i)
        media += diplomati[i]; // a media sommo il voto del diplomato all'indice i
    media /= DIM; // la media è la somma dei valori diviso il numero di valori, e qui questo facciamo
    printf("La media dei voti dei diplomati è: %.1f\n", media);

    /*
        es. 5
    */
    float media_over_80 = 0.0; // dato che conterrà la media dei voti dei diplomati con più di 80
    int contatore = 0; // contiamo quanti hanno preso più di 80 per poter calcolare la media
    for (size_t i = 0; i < DIM; ++i)
        if (diplomati[i] >= 80) // se il diplomato ha preso più di 80, aggiorna il contatore
            media_over_80 += diplomati[i], ++contatore; // a media sommo il voto del diplomato all'indice i

    if (contatore > 0) { // se c'è almeno uno studente con più di 80, calcola la media
        media_over_80 /= contatore; // la media è la somma dei valori diviso il numero di valori, e qui questo facciamo
        printf("La media dei voti dei diplomati con voto maggiore a 80 è: %.1f\n\n", media_over_80);
    } else { // altrimenti informa che non ci sono studenti con voto maggiore a 80
        printf("Non ci sono studenti con voto maggiore o uguale a 80\n");
    }

    /*
        Stampiamo l'array
    */
    for (size_t i = 0; i < DIM; ++i)
        printf("Diplomato %zu, con voto %d\n", i + 1, diplomati[i]);

    return 0; // usciamo dal programma senza errori
}