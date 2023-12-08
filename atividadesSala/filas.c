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