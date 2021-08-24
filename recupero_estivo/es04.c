#include <stdio.h>

int main(void) {
    int età; // qua salviamo l'età della persona

    do {
        printf("Inserisci età: ");
        scanf("%d", &età);

        if (età < 0)
            printf("Inserisci un'età valida (>=0)\n");
    } while (età < 0); // se l'età è minore di 0, chiediamo ancora l'età

    while (1) {
        int scelta;

        printf("\n"); // solo per separare un input dal successivo
        printf("VALUTAZIONE ETÀ\n");
        printf("1) Maggiorenne o Minorenne?\n");
        printf("2) Bambino, Adolescente, Adulto o Anziano?\n");
        printf("3) Per cosa può votare?\n");
        printf("4) Esci\n");
        printf("SCELTA: ");

        scanf("%d", &scelta);

        switch (scelta) {
            case 1: // controlliamo se è maggiorenne o minorenne
                if (età >= 18)
                    printf("-> Maggiorenne\n");
                else
                    printf("-> Minorenne\n");

                break;

            case 2: // diciamo se è bambino, adolescente, adulto o anziano
                if (età < 10) // il controllo iniziale dell'età ci garantisce che non sarà minore di 0
                    printf("-> Bambino\n");
                else if (età >= 10 && età <= 25)
                    printf("-> Adolescente\n");
                else if (età > 25 && età <= 70)
                    printf("-> Adulto\n");
                else // if (età > 70)
                    printf("-> Anziano\n");

                break;

            case 3: // diciamo per cosa può votare
                if (età < 18)
                    printf("-> Non può votare\n");
                if (età >= 18)
                    printf("-> Può votare per la Camera dei Deputati\n");
                if (età >= 25)
                    printf("-> Può votare per il Senato della Repubblica\n");

                break;

            case 4: // usciamo dal programma
                printf("Grazie per aver usato il programma\n");

                return 0;

            default:
                printf("Scelta non riconosciuta, riprovare\n");

                break;
        }
    }

    return 0;
}