#include <stdio.h>
#include <stdlib.h>

int ehPrimo(int n) {
    int j;
    if (n < 2) return 0;
    for (j = 2; j * j <= n; j++) {
        if (n % j == 0) return 0;
    }
    return 1;
}

void geraPrimos(int n, int *primos, int *qtd) {
    int i, count = 0;
    for (i = 2; i <= n; i++) {
        if (ehPrimo(i)) {
            primos[count++] = i;
        }
    }
    *qtd = count;
}

int main() {
    int n, x, y, i, qtdPrimos;
    int primos[10000];
    scanf("%d", &n);
    scanf("%d %d", &x, &y);
    geraPrimos(n, primos, &qtdPrimos);
    for (i = x - 1; i < y; i++) {
        printf("%d", primos[i]);
        if (i < y - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
