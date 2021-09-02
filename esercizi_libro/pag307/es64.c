#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TYPE_LEN 50
#define DESC_LEN 100

typedef struct {
    char tipo[TYPE_LEN];
    char descrizione[DESC_LEN];
    float prezzo;
} Computer;

int main(void) {
    int n; // numero di computer
    printf("Numero di computer: ");
    scanf("%d", &n);

    Computer *computer = malloc(sizeof(Computer) * n);
    if (computer == NULL) { // se il vettore è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(1); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    for (size_t i = 0; i < n; ++i) {
        printf("Tipologia del %zu° computer: ", i + 1);
        scanf(" %[^\n]s", computer[i].tipo);

        printf("Descrizione del %zu° computer: ", i + 1);
        scanf(" %[^\n]s", computer[i].descrizione);

        printf("Prezzo del %zu° computer: ", i + 1);
        scanf("%f", &computer[i].prezzo);

        printf("\n");
    }

    char scelta[TYPE_LEN];
    printf("Tipologia dei computer da visualizzare: ");
    scanf(" %[^\n]s", scelta);

    float tot = 0.0; // qui salveremo il costo totale dei computer del tipo scelto
    int count = 0; // numero di computer trovati della tipologia scelta

    printf("Elenco computer della tipologia \"%s\"\n", scelta);
    for (size_t i = 0; i < n; ++i)
        if (!strcmp(computer[i].tipo, scelta)) {
            tot += computer[i].prezzo;
            ++count;

            printf("%d) %s, prezzo: %.2f€\n", count, computer[i].descrizione, computer[i].prezzo);
        }
    printf("\n");
    printf("Prezzo medio dei computer di tipo \"%s\": %.2f€\n", scelta, tot / count);

    return 0;
}