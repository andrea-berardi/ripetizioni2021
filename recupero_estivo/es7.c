#include <stdio.h>

#define CST_GIORNALIERO 35 // l'auto sostitutiva costa 35€ al giorno
#define PRZ_AL_KM 0.15 // 15c ogni Km percorso

int main(void) {
    float costo_pezzi; // costo pezzi di ricambio
    float costo_manodopera; // costo della manodopera
    int giorni; // giorni necessari per la riparazione
    float km; // Km percorsi con l'auto sostitutiva

    printf("Costo dei pezzi di ricambio: ");
    scanf("%f", &costo_pezzi);
    printf("Costo della manodopera: ");
    scanf("%f", &costo_manodopera);
    printf("Giorni necessari alla riparazione: ");
    scanf("%d", &giorni);
    printf("Km percorsi con l'auto sostitutiva: ");
    scanf("%f", &km);

    printf("Costo della riparazione (pezzi + manodopera): %.2f€\n", costo_pezzi + costo_manodopera);
    printf("Costo del noleggio: %.2f€\n", giorni * CST_GIORNALIERO + km * PRZ_AL_KM);
    printf("Costo totale (i due valori sommati): %.2f€\n", giorni * CST_GIORNALIERO + km * PRZ_AL_KM + costo_pezzi + costo_manodopera);

    return 0;
}