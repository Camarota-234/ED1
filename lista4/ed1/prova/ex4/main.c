#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para aplicar a função de redução em um elemento
double funcao(double x) {
    return pow(x, 5) - pow(x, 4) + pow(x, 3) - pow(x, 2) + x - 1;
}

// Função recursiva para aplicar a redução no vetor
double reduce(double *v, int n, double acumulador) {
    if (n == 0) return acumulador;
    return reduce(v, n - 1, acumulador + funcao(v[n - 1]));
}

int main() {
    int n, i;
    double acumulador;
    double *v;

    // Entrada do número de elementos e valor inicial do acumulador
    scanf("%d", &n);
    scanf("%lf", &acumulador);

    // Aloca o vetor dinamicamente
    v = (double *)malloc(n * sizeof(double));
    if (v == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    // Entrada dos elementos do vetor
    for (i = 0; i < n; i++) {
        scanf("%lf", &v[i]);
    }

    // Chama a função reduce e imprime o resultado com uma casa decimal
    double resultado = reduce(v, n, acumulador);
    printf("%.1lf\n", resultado);

    // Libera a memória alocada
    free(v);

    return 0;
}
