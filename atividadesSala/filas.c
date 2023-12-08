#include <stdlib.h>
#include <stdio.h>

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

void enfileirar(Fila *f, int valor) {
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

int desenfileirar(Fila *f) {
    if (vazia_fila(f)) {
        return 0;
    }
    No* aux = f->primeiro;
    f->primeiro = aux->proximo;

    if(f->primeiro == NULL) {
        f->ultimo = NULL;
    }
    f->quantidade--;
    int valor = aux->valor;
    free(aux);
    return valor;
}



int main() {
    Fila f;
    inicializar_fila(&f);
    printf("Qtd: %d\n", quantidade_fila(&f));
    enfileirar(&f, 10);
    enfileirar(&f, 11);
    enfileirar(&f, 20);
    enfileirar(&f, 21);
    enfileirar(&f, 22);
    printf("Qtd: %d\n", quantidade_fila(&f));

}