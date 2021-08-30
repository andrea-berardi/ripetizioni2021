#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50 // lunghezza massima dei nomi dei proprietari

typedef struct appartamento {
    char nome[LEN]; // nome del proprietario
    float dim; // dimensione dell'appartamento in mq
} Appartamento;

void swap(float *x, float *y) {
    float tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(void) {
    int n; // numero degli appartamenti
    printf("Digita il numero di appartamenti: ");
    scanf("%d", &n);

    Appartamento *condominio; // il condominio è un insieme di appartamenti
    condominio = malloc(sizeof(Appartamento) * n); // allochiamo il vettore, n blocchi di dimensione Appartamento
    if (condominio == NULL) { // se il vettore è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(1); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    for (size_t i = 0; i < n; ++i) {
        printf("Nome del proprietario %zu: ", i + 1);
        scanf(" %[^\n]50s", condominio[i].nome); // ignoriamo ogni whitespace e ogni "a capo"

        printf("Inserisci mq dell'appartamento %zu: ", i + 1);
        scanf("%f", &condominio[i].dim);

        printf("\n"); // solo per separare un input dal successivo
    }

    /*
        es. 1
    */
    float max = condominio[0].dim;
    float min = condominio[0].dim;
    for (size_t i = 0; i < n; ++i) {
        if (condominio[i].dim > max)
            max = condominio[i].dim;
        if (condominio[i].dim < min)
            min = condominio[i].dim;
    }
    printf("Dimensioni appartamento più grande: %.2f\n", max);
    printf("Dimensioni appartamento più piccolo: %.2f\n", min);

    /*
        es. 2
    */
    float tot = 0.0; // qui salveremo la metratura totale del condominio
    for (size_t i = 0; i < n; ++i)
        tot += condominio[i].dim;
    printf("Dimensione totale condominio: %.2fmq\n", tot);

    /*
        es. 3
    */
    float x, y; // gli estremi del nostro intervallo, X sarà il maggiore, Y il minore
    int count = 0; // contatore degli appartamenti con dimensioni fra X e Y

    printf("Determinare il numero di appartamenti con dimensione compresa tra due valori X e Y\n");
    printf("Inserisci X: ");
    scanf("%f", &x);
    printf("Inserisci Y: ");
    scanf("%f", &y);

    if (x < y) {
        printf("Il programma assume che X sia maggiore di Y\n");
        printf("Non essendo vero in questo caso, X e Y verranno invertiti\n");
        swap(&x, &y);
    }

    for (size_t i = 0; i < n; ++i)
        // qui potevamo fare così, ma è poco intuitivo e pure poco bello da vedere
        // if (condominio[i].dim >= x && condominio[i].dim <= y 
        // || condominio[i].dim >= y && condominio[i].dim <= y)
        if (condominio[i].dim >= y && condominio[i].dim <= x)
            ++count;
    printf("Numero di condomini con dimensioni comprese fra %.2fmq e %.2fmq: %d\n", x, y, count);

    /*
        es. 4
    */
    printf("ELENCO APPARTAMENTI\n");
    for (size_t i = 0; i < n; ++i)
        printf("Proprietario: %-50s Appartamento: %.2fmq\n", condominio[i].nome, condominio[i].dim);

    /*
        es. 5
    */
    printf("I proprietari con appartamenti più grandi di 100mq sono:\n");
    for (size_t i = 0; i < n; ++i)
        if (condominio[i].dim > 100.0)
            printf("- %s\n", condominio[i].nome);

    /*
        es. 6
    */
    printf("ELENCO SPESE CONDOMINIALI\n");
    for (size_t i = 0; i < n; ++i)
        printf("Il Sig. %s deve pagare %.2f€\n", condominio[i].nome, condominio[i].dim * 1.5);

    /*
        Pulizia finale
    */    
    free(condominio);
    condominio = NULL;

    return 0;
}