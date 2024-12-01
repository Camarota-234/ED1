#include <stdio.h>

int buscaBinaria(int v[], int esquerda, int direita, int chave) {
    int meio;
    if (esquerda > direita) return -1;
    meio = (esquerda + direita) / 2;
    if (v[meio] == chave) return meio;
    if (v[meio] > chave) return buscaBinaria(v, esquerda, meio - 1, chave);
    return buscaBinaria(v, meio + 1, direita, chave);
}

int main() {
    int t, i, j, tamanho, chave, resultado, vetor[10000], valor;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        j = 0;
        scanf("%d", &chave);
        while (1) {
            scanf("%d", &valor);
            if (valor == -1) break;
            vetor[j++] = valor;
        }
        tamanho = j;
        resultado = buscaBinaria(vetor, 0, tamanho - 1, chave);
        if (resultado == -1) {
            printf("ausente\n");
        } else {
            printf("%d\n", resultado);
        }
    }
    return 0;
}
