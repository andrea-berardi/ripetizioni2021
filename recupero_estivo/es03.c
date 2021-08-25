#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // ci serve per toupper()

#define DIM 50 // massimo numero di vini acquistati
#define CHARS 50 // massima lunghezza dei nomi dei vini

int main(void) {
    int n = 0; // numero di vini comprati
    while (n <= 0 || n > DIM) { // continua a chiedere quanti vini ha preso fino a che non abbiamo un numero fra 0 e MAX_DIM
        printf("Quanti vini hai acquistato (da 1 a %d)? ", DIM);
        scanf("%d", &n);
    }
    printf("\n");

    /*
        Definizione delle variabili (gli array paralleli, come da esplicita richiesta dell'esercizio)
    */
    char **nome = malloc(sizeof(char*) * n); // array dei nomi dei vini, di cui allochiamo n blocchi
    if (nome == NULL) { // se il vettore è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(1); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    char *tipo; // array del tipo dei vini
    tipo = malloc(sizeof(char) * n); // allochiamo n blocchi di memoria di tipo char
    if (tipo == NULL) { // se il vettore è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(2); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    float *prezzo; // array del prezzo dei vini
    prezzo = malloc(sizeof(float) * n); // allochiamo n blocchi di memoria di tipo float
    if (prezzo == NULL) { // se il vettore è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(3); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    /*
        In questo ciclo popoliamo i 3 array paralleli
    */
    for (size_t i = 0; i < n; ++i) {
        nome[i] = malloc(CHARS * sizeof(char)); // allochiamo 50 chars per l'elemento i dell'array
        printf("Inserisci il nome del %zu° vino (<50 caratteri): ", i + 1);
        scanf(" %[^\n]s", nome[i]); // ignoriamo ogni whitespace e ogni "a capo"

        do { // usiamo un do-while perché vogliamo che il ciclo venga eseguito almeno una volta
            printf("Inserisci il tipo del %zu° vino, B per Bianco e R per Rosso: ", i + 1);
            scanf(" %c", &tipo[i]); // lo spazio prima di %c dice di ignorare tutti i whitespace (e simili) prima del char
            tipo[i] = toupper(tipo[i]); // rendiamo maiuscolo il char immesso così possiamo accettare B/b e R/r
        } while (tipo[i] != 'R' && tipo[i] != 'B');

        printf("Inserisci il prezzo del %zu° vino: ", i + 1);
        scanf("%f", &prezzo[i]);

        printf("\n"); // solo per separare un input dal successivo
    }

    /*
        es. 1
    */
    float totale = 0.0; // qui salveremo il costo totale dei vini
    for (size_t i = 0; i < n; ++i)
        totale += prezzo[i];
    printf("Il costo totale dei vini è %.2f€\n", totale);

    /*
        es. 2
    */
    int n_vini_bianchi = 0; // numero di vini bianchi, ci serve per calcolare la media
    totale = 0.0; // azzeriamo il totale così riutilizziamo la stessa variabile
    for (size_t i = 0; i < n; ++i)
        if (tipo[i] == 'B')
            ++n_vini_bianchi, totale += prezzo[i];
    printf("Il costo medio dei vini bianchi è %.2f€\n", totale / n_vini_bianchi);

    /*
        es. 3
    */
    // il numero di vini bianchi lo abbiamo contato nell'es.2, e il totale di vini lo sappiamo già ed è n
    // quindi facendo n - n_vini_bianchi (ossia il totale - il numero di vini bianchi) sappiamo quanti sono i vini rossi
    printf("Sono stati acquistati %d vini bianchi e %d vini rossi.\n", n_vini_bianchi, n - n_vini_bianchi);

    /*
        es. 4
    */
    float prezzo_minore = prezzo[0]; // non ci interessa sapere se il primo vino ha davvero il costo più basso, nel caso verrà rimpiazzato
    for (size_t i = 0; i < n; ++i)
        if (prezzo[i] < prezzo_minore) // se il prezzo del vino attuale è più basso del prezzo minore registrato...
            prezzo_minore = prezzo[i]; // ...assegna il prezzo del vino come prezzo minore trovato
    printf("Il vino col costo minore costa %.2f€\n\n", prezzo_minore);

    /*
        Parte finale, che possiamo considerare un ipotetico es. 5
    */
    printf("ELENCO VINI ROSSI\n"); // caps perché sì
    for (size_t i = 0; i < n; ++i)
        if (tipo[i] == 'R')
            printf("%zu) Nome: %-50s Prezzo unitario: €%.2f\n", i + 1, nome[i], prezzo[i]);

    free(nome);
    nome = NULL;
    free(tipo);
    tipo = NULL;
    free(prezzo);
    prezzo = NULL;

    return 0;
}