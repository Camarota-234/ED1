#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

typedef struct fila {
    No *primeiro;
    No *ultimo;
    int quantidade;
} Fila;

int primeiro(Fila *f) {
    return f->primeiro->valor;
}

int quantidade_fila(Fila *f) {
    return f->quantidade;
}

int vazia_fila(Fila *f) {
    return (f->primeiro==NULL && f->ultimo==NULL);
}

void inicializar_fila(Fila *f){
    f->primeiro = NULL;
    f->ultimo = NULL;
    f->quantidade = 0;

}

void enfilerar(Fila *f, int valor) {
    No *n = malloc(sizeof(No));
    n->valor = valor;
    n->proximo = NULL;

    if (f->ultimo == NULL) {
        f->primeiro = n;
    } else {
        f->ultimo->proximo = n;
    }
    f->ultimo = n;
    f->quantidade++;
}


int main() {
    Fila f;
    inicializar_fila(&f);
}