#include <stdio.h>

#define MESI 12 // numero di mesi su cui svolgeremo i calcoli
#define PROVVIGIONE 10 // percentuale della provvigione (10%)

int main(void) {
    float fatturati[MESI]; // array dove salveremo il fatturato dell'agente di commercio

    // carichiamo i dati nell'array
    for (size_t i = 0; i < MESI; ++i) {
        printf("Inserisci il fatturato del %zu° mese: ", i + 1);
        scanf("%f", &fatturati[i]);
    }

    while (1) {
        int scelta;

        printf("\n"); // solo per separare un input dal successivo
        printf("ELABORAZIONE FATTURATI\n");
        printf("1) Volte in cui l'agente fatturato >5000€ al mese\n");
        printf("2) Totale annuo fatturato e provvigioni\n");
        printf("3) Elenco provvigioni di ogni mese\n");
        printf("4) Fatturato medio primi 6 mesi\n");
        printf("5) Esci\n");
        printf("SCELTA: ");

        scanf("%d", &scelta);

        switch (scelta) {
            case 1: // volte in cui l'agente fatturato >5000€ al mese
                { // scope creato per poter dichiarare una variabile ()
                    int c = 0; // contatore
                    for (size_t i = 0; i < MESI; ++i)
                        if (fatturati[i] > 5000.0)
                            ++c;
                    printf("L'agente ha fatturato oltre 5000€ per %d volte\n", c);
                }

                break;

            case 2: // totale annuo fatturato e provvigioni
                { // scope creato per poter dichiarare una variabile ()
                    float tot = 0.0; // totale annuo
                    float provv = 0.0; // totale provvigioni
                    for (size_t i = 0; i < MESI; ++i) {
                        tot += fatturati[i];
                        provv += ((fatturati[i] / 100) * PROVVIGIONE); // calcoliamo il 10% di ogni fatturato mensile
                    }
                    printf("Fatturato totale: %.2f€\nTotale provvigioni: %.2f€\n", tot, provv);
                }

                break;

            case 3: // elenco provvigioni mensili
                printf("ELENCO PROVVIGIONI MENSILI\n");
                for (size_t i = 0; i < MESI; ++i)
                    printf("%zu) %.2f€\n", i + 1, (fatturati[i] / 100) * PROVVIGIONE);
                break;

            case 4: // fatturato medio dei primi 6 mesi
                { // scope creato per poter dichiarare una variabile ()
                    float tot = 0.0;
                    for (size_t i = 0; i < 6; ++i)
                        tot += fatturati[i];
                    printf("Fatturato dei primi 6 mesi: %.2f€\n", tot);
                }

                break;

            case 5:
                printf("Grazie per aver usato l'app\n");

                return 0;
        
            default:
                printf("Scelta non riconosciuta, riprovare\n");

                break;
        }
    }

    return 0;
}