#include <stdio.h>

int main() {
    int aux = 0;
    int n = 8;
    int vetor[] = {1,3,5,2,4,6,7,8};


    for (int i = 0; i < n - 1 ; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (vetor[j] > vetor[j+1]) {

                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;

            }   
        }
    }

    for (int i = 0; i < n - 1 ; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if ((vetor[j] % 2) != (j % 2)) {

                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;

            }   
        }
    }



    for (int i = 0; i < n; i++)
    {
        printf("%d", vetor[i]);
    }
    
    return 0;
}