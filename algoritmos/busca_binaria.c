#include <stdio.h>



// Função para trocar dois elementos do vetor
void trocar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de ordenação crescente (bubble sort)
void ordenarCrescente(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)  { 
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                trocar(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

// Função de busca binária
int buscaBinaria(int vetor[], int tamanho, int busca)
{

    int inicio = 0;
    int fim = tamanho - 1;
    int meio = fim / 2;

    while (inicio < fim && vetor[meio] != busca)
    {
                
        if (busca > vetor[meio])
            inicio = meio + 1;

        if (busca < vetor[meio])
            fim = meio - 1;

        meio = (inicio + fim) / 2;
    }

    if (vetor[meio] == busca) {return meio; } 
    else {return -1; }
}


int main()
{

    int vetor[8] = {1, 5, 2, 6, 3, 8, 4, 9};

    // ordena vetor
    ordenarCrescente(vetor, 8);

    // realiza busca
    int resultado = buscaBinaria(vetor, 8, 6);

    // imprime posição no 
    if (resultado >= 0) {
        printf("Encontrado encontrado na posição %d", resultado);
    } else {printf("Não encontrado.");}
    


}