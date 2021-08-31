#include <stdio.h>
#include <stdlib.h>

#define LEN 50 // lunghezza massima dei nomi

int main(void) {
    int n; // numero di alunni

    printf("Numero di alunni: ");
    scanf("%d", &n);
    printf("\n");

    char **nome = malloc(sizeof(char*) * n);
    if (nome == NULL) { // se è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(1); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    float *voto = malloc(sizeof(float) * n);
    if (voto == NULL) { // se è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(2); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    for (size_t i = 0; i < n; ++i) {
        nome[i] = malloc(sizeof(char) * LEN); // allochiamo 50 chars per l'elemento i dell'array
        if (nome[i] == NULL) { // se è NULL abbiamo avuto un errore
            printf("Errore durante l'allocazione del vettore\n");
            exit(3); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
        }
        printf("Nome del %zu° studente: ", i + 1);
        scanf(" %[^\n]s", nome[i]); // ignoriamo ogni whitespace e ogni "a capo"

        printf("Voto del %zu° studente: ", i + 1);
        scanf("%f", &voto[i]);

        printf("\n");
    }

    float tot = 0.0; // somma totale dei voti
    for (size_t i = 0; i < n; ++i)
        tot += voto[i];
    printf("Media dei voti: %.2f\n", tot / n);

    return 0;
}