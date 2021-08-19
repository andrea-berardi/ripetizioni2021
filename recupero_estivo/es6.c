#include <stdio.h>
#include <stdlib.h>

#define DIM 50 // massimo numero di studenti, non obbligatorio ma meglio averlo
#define CHARS 20 // massima lunghezza dei nomi degli studenti
#define DURATA 6 // durata di un giorno di lezione, 6 ore per l'esercizio corrente

int main(void) {
    int n = 0; // numero di studenti, che chiederemo all'utente
    while (n <= 0 && n >= 0) { // continua a chiedere quanti sono gli studenti fino a che non abbiamo un numero fra 0 e DIM
        printf("Quanti sono gli studenti (fra 1 e %d)? ", DIM);
        scanf("%d", &n);
    }
    printf("\n");

    /*
        Definizione delle variabili (gli array paralleli, come da esplicita richiesta dell'esercizio)
    */
    char **nome = malloc(sizeof(char*) * n); // array dei nomi, di cui allochiamo n blocchi
    if (nome == NULL) { // se il vettore è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(1); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    int *giorni_assenza; // array dei giorni di assenza
    giorni_assenza = (int*)malloc(sizeof(int) * n); // allochiamo n blocchi di memoria di tipo int
    if (giorni_assenza == NULL) { // se il vettore è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(2); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    int *ore_assenza; // array delle ore di uscite anticipate ed entrate in ritardo
    ore_assenza = (int*)malloc(sizeof(int) * n); // allochiamo n blocchi di memoria di tipo int
    if (ore_assenza == NULL) { // se il vettore è NULL abbiamo avuto un errore
        printf("Errore durante l'allocazione del vettore\n");
        exit(3); // usciamo con un valore diverso da 0 per rendere chiaro che c'è stato un errore
    }

    /*
        In questo ciclo popoliamo i 3 array paralleli
    */
    for (size_t i = 0; i < n; ++i) {
        nome[i] = malloc(CHARS * sizeof(char)); // allochiamo 50 chars per l'elemento i dell'array
        printf("Inserisci il nome del %zu° studente (<50 caratteri): ", i + 1);
        scanf(" %[^\n]s", nome[i]); // ignoriamo ogni whitespace e ogni "a capo"

        printf("Immettere i giorni di assenza: ");
        scanf("%d", &giorni_assenza[i]);

        int tmp_ore_assenze; // variabile temporanea dove salveremo le ore di assenza
        printf("Immettere le ore di entrata in ritardo: ");
        scanf("%d", &tmp_ore_assenze);

        printf("Immettere le ore di uscita anticipata: ");
        scanf("%d", &ore_assenza[i]);
        ore_assenza[i] += tmp_ore_assenze;

        printf("\n"); // solo per separare un vino dal successivo
    }

    /*
        es. 1
    */
    int count = 0; // contatore dove salveremo quanti alunni hanno 0 assenze, 0 ritardi e 0 uscite anticipate
    for (size_t i = 0; i < n; ++i)
        if (giorni_assenza[i] == 0 && ore_assenza[i] == 0) // se le assenze, i ritardi e le uscite sono 0...
            ++count; // ...aumentiamo il contatore
    printf("Alunni senza assenze, ritardi e uscite: %d\n", count);

    /*
        es. 2
    */
    printf("ELENCO STUDENTI\n"); // caps perché sì
    for (size_t i = 0; i < n; ++i)
        printf("%zu) Nome: %-20s Ore totali assenze: %d\n", i, nome[i], giorni_assenza[i] * DURATA + ore_assenza[i]);

    /*
        es. 3
    */
    count = 0; // azzeriamo il contatore dove salveremo quanti alunni hanno 0 assenze
    for (size_t i = 0; i < n; ++i)
        if (giorni_assenza[i] == 0) // se le assenze sono 0...
            ++count; // ...aumentiamo il contatore
    printf("Alunni senza le sole assenze: %d\n", count);

    /*
        es. 4
    */
    count = 0; // azzeriamo il contatore dove salveremo quanti alunni hanno più di 15 assenze e 10 ore di ritardo e uscite
    for (size_t i = 0; i < n; ++i)
        if (giorni_assenza[i] > 15 && ore_assenza[i] > 10) // se le assenze sono più di 15 e le ore di assenza sono più di 10...
            ++count; // ...aumentiamo il contatore
    printf("Alunni con più 15 assenze e più di 10 ore di ritardi e uscite: %d\n", count);

    /*
        es. 5
    */
    float tot = 0; // totale ore di assenza con anche i giorni * DURATA
    for (size_t i = 0; i < n; ++i)
        tot += (giorni_assenza[i] * DURATA + ore_assenza[i]);
    printf("Ore di assenza media pro capite: %.2f\n", tot / n); // tot / n è il totale delle ore di assenza diviso il numero di studenti

    free(nome);
    nome = NULL;
    free(giorni_assenza);
    giorni_assenza = NULL;
    free(ore_assenza);
    ore_assenza = NULL;

    return 0;
}