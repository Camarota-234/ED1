#include <stdio.h>

// Função para trocar dois elementos do vetor
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de ordenação crescente (bubble sort)
void ordenarCrescente(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                trocar(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

// Função de ordenação decrescente (bubble sort)
void ordenarDecrescente(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] < vetor[j + 1]) {
                trocar(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

int main() {
    int vetor[8] = {4, 2, 8, 7, 1, 5, 9, 3};
    int meio = 4; // Metade do tamanho do vetor

    // Ordena a primeira metade (valores pares) em ordem crescente
    ordenarCrescente(vetor, meio);

    // Ordena a segunda metade (valores ímpares) em ordem decrescente
    ordenarDecrescente(vetor + meio, meio);

    // Imprime o vetor reorganizado
    printf("Vetor reorganizado:\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}