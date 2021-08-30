#include <stdio.h>

int main(void) {
    int age; // qua salviamo l'age della persona

    do {
        printf("Inserisci age: ");
        scanf("%d", &age);

        if (age < 0)
            printf("Inserisci un'age valida (>=0)\n");
    } while (age < 0); // se l'age è minore di 0, chiediamo ancora l'age

    while (1) {
        int scelta;

        printf("\n"); // solo per separare un input dal successivo
        printf("VALUTAZIONE age\n");
        printf("1) Maggiorenne o Minorenne?\n");
        printf("2) Bambino, Adolescente, Adulto o Anziano?\n");
        printf("3) Per cosa può votare?\n");
        printf("4) Esci\n");
        printf("SCELTA: ");

        scanf("%d", &scelta);

        switch (scelta) {
            case 1: // controlliamo se è maggiorenne o minorenne
                if (age >= 18)
                    printf("-> Maggiorenne\n");
                else
                    printf("-> Minorenne\n");

                break;

            case 2: // diciamo se è bambino, adolescente, adulto o anziano
                if (age < 10) // il controllo iniziale dell'age ci garantisce che non sarà minore di 0
                    printf("-> Bambino\n");
                else if (age >= 10 && age <= 25)
                    printf("-> Adolescente\n");
                else if (age > 25 && age <= 70)
                    printf("-> Adulto\n");
                else // if (age > 70)
                    printf("-> Anziano\n");

                break;

            case 3: // diciamo per cosa può votare
                if (age < 18)
                    printf("-> Non può votare\n");
                if (age >= 18)
                    printf("-> Può votare per la Camera dei Deputati\n");
                if (age >= 25)
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