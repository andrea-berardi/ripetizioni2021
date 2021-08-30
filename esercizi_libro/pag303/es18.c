#include <stdio.h>

int main(void) {
    float massa; // massa del pacco da spedire

    input:
    printf("Massa del pacco in Kg: ");
    scanf("%f", &massa);

    float costo; // costo della spedizione

    if (massa <= 3.0 && massa > 0.0)
        costo = 5.0;
    else if (massa > 3.0 && massa <= 10.0)
        costo = 8.0;
    else if (massa > 10.0)
        costo = 10.0;
    else {
        printf("La massa inserita non è valida\n");
        goto input; // solo a scopo didattico, è meglio non usarlo se non in cicli innestati
    }
    
    printf("Il costo della spedizione è %.2f€\n", costo);

    return 0;
}