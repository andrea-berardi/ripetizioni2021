#include <stdio.h>

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(void) {
    int m, n;
    printf("Inserisci due numeri interi: ");
    scanf("%d%d", &m, &n);
    printf("M: %d\nN: %d\nSCAMBIO\n", m, n);
    swap(&m, &n);
    printf("M: %d\nN: %d\n", m, n);

    return 0;
}