#include <stdio.h>
//Prova 1 questão 3, semestre 2023/2
//Código pronto e funcional, diferentemente do original.
//Áreas comentadas são trechos do código da maneira como foi entregue na prova.
int main() {

    int aux = 0;
    int n = 8;
    int vetor[] = {10,3,5,1,4,6,7,12};


    for (int i = 0; i < n - 1 ; i++) {
    //for (int i = 0; i <; i++) {
        
        for (int j = 0; j < n - i - 1; j++) { 
        //for (int j = 0; j < n; j++) { 

            if (vetor[j] > vetor[j+1]) {

                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;

            }   
        }
    }
    printf("Vetor ordenado:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d", vetor[i]);
    }

    for (int i = 0; i < n - 1 ; i++) {
    //for (int i = 0; i <; i++) {
        
        for (int j = 0; j < n - i - 1; j++) { 
        //for (int j = 0; j < n; j++) {

            if ((vetor[j] % 2) != (j % 2)) {
            
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;

            }   
        }
    }


printf("\nVetor reorganizado:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    
    return 0;
}