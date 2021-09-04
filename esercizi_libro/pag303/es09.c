// es. 9, pag. 303

#include <stdio.h>

typedef struct {
    float x;
    float y;
} Punto;

int main(void) {
    Punto A, B, M;

    printf("Coordinata X di A: ");
    scanf("%f", &A.x);
    printf("Coordinata Y di A: ");
    scanf("%f", &A.y);
    printf("Coordinata X di B: ");
    scanf("%f", &B.x);
    printf("Coordinata Y di B: ");
    scanf("%f", &B.y);

    M.x = (A.x + B.y) / 2.0;
    M.y = (A.x + B.y) / 2.0;

    printf("Coordinate punto medio M(%.1f, %.1f)\n", M.x, M.y);

    return 0;
}