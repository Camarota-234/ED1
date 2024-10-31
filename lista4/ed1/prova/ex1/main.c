#include <stdio.h>
#include <math.h>

/* Declarações de variáveis antes do for */
int n;
double a;

/* Função de redução recursiva */
double reduce(double v[], int index) {
    if (index == n) return 0; // Caso base: fim do vetor
    double x = v[index];
    double f_x = pow(x, 5) - pow(x, 4) + pow(x, 3) - pow(x, 2) + x - 1;
    return f_x + reduce(v, index + 1);
}

int main() {
    /* Leitura dos dados de entrada */
    scanf("%d", &n);
    scanf("%lf", &a);
    double v[n];
    int i;
    for (i = 0; i < n; i++) {
        scanf("%lf", &v[i]);
    }

    /* Calcula o resultado */
    double result = a + reduce(v, 0);
    
    /* Impressão com precisão de uma casa decimal */
    printf("%.1f\n", floor(result * 10) / 10.0);

    return 0;
}
