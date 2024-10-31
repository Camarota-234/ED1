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
        exit(1);
    }
    strncpy(novaCrianca->nome, nome, MAX_NOME - 1);
    novaCrianca->nome[MAX_NOME - 1] = '\0';
    novaCrianca->valorFicha = valor;
    novaCrianca->prox = NULL;
    novaCrianca->ant = ultimo;
    if (ultimo != NULL) {
        ultimo->prox = novaCrianca;
    }
    return novaCrianca;
}

void removerCrianca(Crianca** inicio, Crianca* aRemover) {
    if (*inicio == NULL || aRemover == NULL) {
        return;  
    }
    if (*inicio == aRemover) {
        *inicio = aRemover->prox;
    }
    if (aRemover->prox != NULL) {
        aRemover->prox->ant = aRemover->ant;
    }
    if (aRemover->ant != NULL) {
        aRemover->ant->prox = aRemover->prox;
    }
    free(aRemover);
}

void determinarVencedor(int n, Crianca* inicio) {
    Crianca* atual = inicio;
    while (atual->prox != atual) {
        int passos = atual->valorFicha;
        int i;
        if (passos % 2 == 0) {
            
            for (i = 0; i < passos; i++) {
                atual = atual->prox;
            }
        } else {
            
            for (i = 0; i < passos; i++) {
                atual = atual->ant;
            }
        }
        Crianca* prox = atual->prox;
        removerCrianca(&inicio, atual);
        atual = prox;
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

    if (inicio != NULL && ultimo != NULL) {
        inicio->ant = ultimo;
        ultimo->prox = inicio;
    }

    determinarVencedor(n, inicio);

    return 0;
}
