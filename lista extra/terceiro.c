#include <stdio.h>

int ehPrimo(int n) {
    int j;
    if (n < 2) return 0;
    for (j = 2; j * j <= n; j++) {
        if (n % j == 0) return 0;
    }
    return 1;
}

int contaPrimos(int x, int y) {
    int i, contador = 0;
    for (i = x; i <= y; i++) {
        if (ehPrimo(i)) {
            contador++;
        }
    }
    return contador;
}

int main() {
    int x, y, resultado;
    scanf("%d %d", &x, &y);
    resultado = contaPrimos(x, y);
    printf("%d\n", resultado);
    return 0;
}
