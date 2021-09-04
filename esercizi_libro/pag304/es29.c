// es. 29, pag. 304

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50 // lunghezza massima dei nomi e delle categorie

int main(void) {
    int n; // numero di partecipanti

    printf("Numero di partecipanti: ");
    scanf("%d", &n);
    printf("\n");

    char **nome = malloc(sizeof(char*) * n);
    if (nome == NULL) { // se è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(1); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    char **categoria = malloc(sizeof(char*) * n);
    if (categoria == NULL) { // se è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(2); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    float *tempo = malloc(sizeof(float) * n);
    if (tempo == NULL) { // se è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(3); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    for (size_t i = 0; i < n; ++i) {
        nome[i] = malloc(sizeof(char) * LEN); // allochiamo 50 chars per l'elemento i dell'array
        if (nome[i] == NULL) { // se è NULL abbiamo avuto un errore
            printf("Errore durante l'allocazione del vettore\n");
            exit(4); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
        }
        printf("Nome del %zu° partecipante: ", i + 1);
        scanf(" %[^\n]s", nome[i]); // ignoriamo ogni whitespace e ogni "a capo"

        categoria[i] = malloc(sizeof(char) * LEN); // allochiamo 50 chars per l'elemento i dell'array
        if (categoria[i] == NULL) { // se è NULL abbiamo avuto un errore
            printf("Errore durante l'allocazione del vettore\n");
            exit(5); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
        }
        printf("Categoria del %zu° partecipante: ", i + 1);
        scanf(" %[^\n]s", categoria[i]); // ignoriamo ogni whitespace e ogni "a capo"

        printf("Tempo del %zu° partecipante: ", i + 1);
        scanf("%f", &tempo[i]);

        printf("\n");
    }

    float min; // tempo minimo della cateogria "allievi"
    for (size_t i = 0; i < n; ++i)
        if (!strcmp(categoria[i], "allievi")) { // !strcmp() perchè se ritorna 0 sono uguali, ma 0 è false in C
            min = tempo[i];
            break;
        }
    
    for (size_t i = 0; i < n; ++i)
        if (!strcmp(categoria[i], "allievi") && tempo[i] < min) // !strcmp() perchè se ritorna 0 sono uguali, ma 0 è false in C
            min = tempo[i];
    printf("Tempo minimo fra i partecipanti della categoria \"allievi\": %.2f\n", min);

    return 0;
}