#include <stdio.h>

int main() {
    int n[10]; // Declarando um vetor de tamanho 10
    int i, j, temp;

    // Preenchendo o vetor com valores de 1 a 10
    for (i = 0; i < 10; i++) {
        n[i] = i + 1;
    }

    // Separando os números pares para a primeira metade do vetor
    j = 0;
    for (i = 0; i < 10; i++) {
        if (n[i] % 2 == 0) {
            temp = n[i];
            n[i] = n[j];
            n[j] = temp;
            j++;
        }
    }

    // Organizando a primeira metade do vetor (números pares) em ordem crescente
    for (i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            if (n[k] > n[k + 1]) {
                temp = n[k];
                n[k] = n[k + 1];
                n[k + 1] = temp;
            }
        }
    }

    // Organizando a segunda metade do vetor (números ímpares) em ordem decrescente
    for (i = 5; i < 9; i++) {
        for (int k = 5; k < 9; k++) {
            if (n[k] < n[k + 1]) {
                temp = n[k];
                n[k] = n[k + 1];
                n[k + 1] = temp;
            }
        }
    }

    // Imprimindo os valores organizados
    printf("Valores organizados: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", n[i]);
    }

    return 0;
}
