#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no * proximo;
} no;

typedef struct Lista {
    no * primeiro;
    no * ultimo;
    int quantidade;
} Lista;

void inicializar(Lista * l) {
    l -> quantidade = 0;
    l -> primeiro = NULL;
    l -> ultimo = NULL;
}

void inserirPrimeiro(Lista * l , int valor) {
    no * n = malloc(sizeof(no));
    n -> proximo = l -> primeiro;
    l -> primeiro = n;
    l -> quantidade + 1;
    if(l -> ultimo == NULL) {
        l -> ultimo =n;
    }
}

void inserirUltimo(Lista * l, int valor) {
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

void inserir(Lista * l, int valor, int posicao) {
    if (posicao == 0) {
        inserirPrimeiro(l, valor);
    } else if (posicao == l -> quantidade) {
        inserirUltimo(l, valor);
    } else {
        no * n = malloc(sizeof(no));
        n -> valor = valor;
    }
}

int main() {
    Lista lista1;
    inicializar(&lista1);

}