#include <stdio.h>

int main(void) {
    const float fino80 = 0.15; // costo al secondo per i primi 80 secondi
    const float oltre80 = 0.09; // costo al secondo dopo i primi 80 secondi
    const float scatto = 0.10; // costo fisso, scatto alla risposta
    int durata; // secondi di durata della chiamata

    printf("Durata della chiamata in secondi: ");
    scanf("%d", &durata);
    
    printf("Costo totale chiamata: %.2f€\n", durata <= 80 ? scatto + durata * fino80 : scatto + fino80 * 80.0 + (durata - 80) * oltre80);

    return 0;
}