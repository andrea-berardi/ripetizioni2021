#include <stdio.h>
#include <stdlib.h>

#define LEN 50 // massima lunghezza stringhe

int main(void) {
    int n; // numero di motocicli e ciclomotori

    printf("Numero di motocicli e ciclomotori: ");
    scanf("%d", &n);

    char **nome = malloc(sizeof(char*) * n);
    if (nome == NULL) { // se è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(1); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    int *cilindrata = malloc(sizeof(int) * n);
    if (cilindrata == NULL) { // se è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(2); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    float *prezzo = malloc(sizeof(float) * n);
    if (prezzo == NULL) { // se è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(3); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    for (size_t i = 0; i < n; ++i) {
        nome[i] = malloc(sizeof(char) * LEN); // allochiamo 50 chars per l'elemento i dell'array
        if (nome[i] == NULL) { // se è NULL abbiamo avuto un errore
            printf("Errore durante l'allocazione del vettore\n");
            exit(4); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
        }
        printf("Nome del %zu° ciclomotore/motociclo: ", i + 1);
        scanf(" %[^\n]s", nome[i]); // ignoriamo ogni whitespace e ogni "a capo"

        printf("Cilindrata del %zu° ciclomotore/motociclo: ", i + 1);
        scanf("%d", &cilindrata[i]);

        printf("Prezzo del %zu° ciclomotore/motociclo: ", i + 1);
        scanf("%f", &prezzo[i]);

        printf("\n");
    }

    float max; // prezzo massimo fra i modelli di cilindrata superiore a 50cc
    for (size_t i = 0; i < n; ++i)
        if (cilindrata[i] > 50) { // se la cilindrata è superiore a 50cc
            max = prezzo[i]; // assegnamo il prezzo del veicolo al max, come valore temporaneo
            break; // e usciamo dal ciclo, non ci serve continuare
        }

    for (size_t i = 0; i < n; ++i)
        if (cilindrata[i] > 50 && prezzo[i] > max)
            max = prezzo[i];
    printf("Prezzo massimo fra i modelli con cilindrata >50cc: %.2f€\n", max);

    return 0;
}