#include <stdio.h>

int main(void) {
    int eta; // qua salviamo l'età della persona

    printf("Inserisci età: ");
    scanf("%d", &eta);

    while (1) {
        int scelta;

        printf("VALUTAZIONE ETÀ\n");
        printf("1) Maggiorenne o Minorenne?\n");
        printf("2) Bambino, Adolescente, Adulto o Anziano?\n");
        printf("3) Per cosa può votare?\n");
        printf("4) Esci\n");

        scanf("%d", &scelta);

        switch (scelta) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            return;
        
        default:
            printf("Scelta non riconosciuta, riprovare\n");
            break;
        }
    }

    return 0;
}