#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no * proximo;
} no;

typedef struct lista {
    no * primeiro;
    no * ultimo;
    int quantidade;
} lista;

void inicializar(lista * l) {
    l -> quantidade = 0;
    l -> primeiro = NULL;
    l -> ultimo = NULL;
}

void inserirPrimeiro(lista * l , int valor) {
    no * n = malloc(sizeof(no));
    n -> proximo = l -> primeiro;
    l -> primeiro = n;
    l -> quantidade + 1;
    if(l -> ultimo == NULL) {
        l -> ultimo =n;
    }
}

void inserirUltimo(lista * l, int valor) {
    no * n = malloc(sizeof(no));
    n -> valor = valor;
    l -> quantidade++;
    n -> proximo = NULL;
    if(l -> ultimo == NULL) {
        l -> primeiro = n;
        l -> ultimo = n;
    } else {
        l -> ultimo -> proximo = n;
        l -> ultimo = n;
    }
}

void inserir(lista * l, int valor, int posicao) {
    if (posicao == 0) {
        inserirPrimeiro(l, valor);
    } else if (posicao == l -> quantidade) {
        inserirUltimo(l, valor);
    } else {
        no * n = malloc(sizeof(no));
        n -> valor = valor;
    }
}