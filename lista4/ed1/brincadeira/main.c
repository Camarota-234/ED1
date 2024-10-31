#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 31

typedef struct Crianca {
    char nome[MAX_NOME];
    int valorFicha;
    struct Crianca* prox;
    struct Crianca* ant;
} Crianca;

Crianca* adicionarCrianca(Crianca* ultimo, const char* nome, int valor) {
    Crianca* novaCrianca = (Crianca*)malloc(sizeof(Crianca));
    if (novaCrianca == NULL) {
        printf("Erro ao alocar memória para nova criança.\n");
        exit(1);
    }
    strncpy(novaCrianca->nome, nome, MAX_NOME - 1);
    novaCrianca->nome[MAX_NOME - 1] = '\0';
    novaCrianca->valorFicha = valor;

    if (ultimo == NULL) {
        novaCrianca->prox = novaCrianca;
        novaCrianca->ant = novaCrianca;
    } else {
        novaCrianca->prox = ultimo->prox;
        novaCrianca->ant = ultimo;
        ultimo->prox->ant = novaCrianca;
        ultimo->prox = novaCrianca;
    }
    return novaCrianca;
}

void removerCrianca(Crianca** inicio, Crianca* aRemover) {
    if (aRemover == aRemover->prox) {
        *inicio = NULL;
    } else {
        if (*inicio == aRemover) {
            *inicio = aRemover->prox;
        }
        aRemover->ant->prox = aRemover->prox;
        aRemover->prox->ant = aRemover->ant;
    }
    free(aRemover);
}

void determinarVencedor(Crianca* inicio) {
    Crianca* atual = inicio;
    int tamanho = 1;
    Crianca* temp = inicio;

    while (temp->prox != inicio) {
        tamanho++;
        temp = temp->prox;
    }

    while (tamanho > 1) {
        int passos = atual->valorFicha % tamanho;
        if (passos == 0) passos = tamanho;

        if (atual->valorFicha % 2 == 0) {
            while (passos--) {
                atual = atual->prox;
            }
        } else {
            while (passos--) {
                atual = atual->ant;
            }
        }
        
        Crianca* prox = atual->prox;
        removerCrianca(&inicio, atual);
        atual = prox;
        tamanho--;
    }

    printf("%s\n", inicio->nome);
    free(inicio);
}

int main() {
    int n, i;
    scanf("%d", &n);

    Crianca* inicio = NULL;
    Crianca* ultimo = NULL;

    for (i = 0; i < n; i++) {
        char nome[MAX_NOME];
        int valor;
        scanf("%s %d", nome, &valor);
        ultimo = adicionarCrianca(ultimo, nome, valor);
        if (inicio == NULL) {
            inicio = ultimo;
        }
    }

    determinarVencedor(inicio);

    return 0;
}
