#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // ci serve per toupper()

#define LEN 50 // lunghezza massima dei titoli dei film

int main(void) {
    int n; // numero di film
    printf("Numero di film: ");
    scanf("%d", &n);

    float *prezzo;
    prezzo = malloc(sizeof(float) * n);
    if (prezzo == NULL) { // se il vettore è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(1); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    char **titolo = malloc(sizeof(char*) * n); // array dei titoli dei film, di cui allochiamo n blocchi
    if (titolo == NULL) { // se il vettore è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(2); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    char *genere; // array del genere dei film
    genere = malloc(sizeof(char) * n); // allochiamo n blocchi di memoria di tipo char
    if (genere == NULL) { // se il vettore è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(3); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    int *biglietti; // numero di biglietti venduti
    biglietti = malloc(sizeof(int) * n);
    if (biglietti == NULL) { // se il vettore è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(4); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    for (size_t i = 0; i < n; ++i) {
        printf("Inserisci il prezzo del %zu° film: ", i + 1);
        scanf("%f", &prezzo[i]);

        titolo[i] = malloc(LEN * sizeof(char)); // allochiamo 50 chars per l'elemento i dell'array
        if (titolo[i] == NULL) { // se è NULL abbiamo avuto un errore
            printf("Errore durante l'allocazione del vettore\n");
            exit(4); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
        }
        printf("Inserisci il titolo del %zu° film (<50 caratteri): ", i + 1);
        scanf(" %[^\n]50s", titolo[i]); // ignoriamo ogni whitespace e ogni "a capo"

        do { // usiamo un do-while perché vogliamo che il ciclo venga eseguito almeno una volta
            printf("Inserisci il genere del %zu° film\n", i + 1);
            printf("Legenda -> D: Drammatico, T: Thriller, C: Comico, H: Horror\n");
            printf("Genere: ");
            scanf(" %c", &genere[i]); // lo spazio prima di %c dice di ignorare tutti i whitespace (e simili) prima del char
            genere[i] = toupper(genere[i]); // rendiamo maiuscolo il char immesso così possiamo accettare maiuscole e minuscole
        } while (genere[i] != 'D' && genere[i] != 'T' && genere[i] != 'C' && genere[i] != 'H');

        printf("Numero di biglietti venduti del %zu° film: ", i + 1);
        scanf("%d", &biglietti[i]);

        printf("\n"); // solo per separare un input dal successivo
    }

    /*
        es. 1
    */
    float tot = 0.0; // incasso totale del mese
    for (size_t i = 0; i < n; ++i)
        tot += (prezzo[i] * biglietti[i]); // prezzo dei biglietti moltiplicato per il numero di biglietti venduti
    printf("Incasso totale: %.2f€\n", tot);

    /*
        es. 2
    */
    printf("FILM CHE HANNO VENDUTO PIÙ DI 2000 BIGLIETTI\n");
    for (size_t i = 0; i < n; ++i)
        if (biglietti[i] > 2000)
            printf("> \"%s\"\n", titolo[i]);

    /*
        es. 3
    */
    float max = prezzo[0] * biglietti[0]; // incasso film che ha venduto di più, trovato facendo prezzo per i biglietti venduti
    for (size_t i = 0; i < n; ++i)
        if (prezzo[i] * biglietti[i] > max)
            max = prezzo[i] * biglietti[i];

    printf("FILM CON INCASSO MAGGIORE\n");
    for (size_t i = 0; i < n; ++i)
        if (prezzo[i] * biglietti[i] >= max)
            printf("> %s", titolo[i]);
    printf("\n");

    /*
        es. 4
    */
    printf("ELENCO FILM DRAMMATICI\n");
    for (size_t i = 0; i < n; ++i)
        if (genere[i] == 'D')
            printf("Titolo: %-50s Biglietti venduti: %d\n", titolo[i], biglietti[i]);

    /*
        Pulizia finale
    */
    free(prezzo);
    prezzo = NULL;
    free(titolo);
    titolo = NULL;
    free(genere);
    genere = NULL;
    free(biglietti);
    biglietti = NULL;

    return 0;
}