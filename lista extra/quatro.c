#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FALHA -1
#define MAX 1000

typedef struct {
    int elementos[MAX];
    int inicio, fim, tamanho;
} Deque;

int criarDeque(Deque *d) {
    d->inicio = 0;
    d->fim = -1;
    d->tamanho = 0;
    return SUCESSO;
}

int pushEsquerda(Deque *d, int elem) {
    if (d->tamanho == MAX) return FALHA;
    d->inicio = (d->inicio - 1 + MAX) % MAX;
    d->elementos[d->inicio] = elem;
    d->tamanho++;
    return SUCESSO;
}

int pushDireita(Deque *d, int elem) {
    if (d->tamanho == MAX) return FALHA;
    d->fim = (d->fim + 1) % MAX;
    d->elementos[d->fim] = elem;
    d->tamanho++;
    return SUCESSO;
}

int popEsquerda(Deque *d) {
    int valor;
    if (d->tamanho == 0) return FALHA;
    valor = d->elementos[d->inicio];
    d->inicio = (d->inicio + 1) % MAX;
    d->tamanho--;
    return valor;
}

int popDireita(Deque *d) {
    int valor;
    if (d->tamanho == 0) return FALHA;
    valor = d->elementos[d->fim];
    d->fim = (d->fim - 1 + MAX) % MAX;
    d->tamanho--;
    return valor;
}

int listEsquerda(Deque *d) {
    int i, count;
    if (d->tamanho == 0) {
        printf("vazio\n");
        return SUCESSO;
    }
    for (i = 0, count = d->inicio; i < d->tamanho; i++, count = (count + 1) % MAX) {
        printf("%d", d->elementos[count]);
        if (i < d->tamanho - 1) printf(" ");
    }
    printf("\n");
    return SUCESSO;
}

int listDireita(Deque *d) {
    int i, count;
    if (d->tamanho == 0) {
        printf("vazio\n");
        return SUCESSO;
    }
    for (i = 0, count = d->fim; i < d->tamanho; i++, count = (count - 1 + MAX) % MAX) {
        printf("%d", d->elementos[count]);
        if (i < d->tamanho - 1) printf(" ");
    }
    printf("\n");
    return SUCESSO;
}

int main() {
    char operacao[30];
    Deque d;
    int elem, res;

    while (1) {
        scanf("%s", operacao);
        if (strcmp(operacao, "criarDeque(d)") == 0) {
            res = criarDeque(&d);
        } else if (strncmp(operacao, "pushEsquerda(d,", 15) == 0) {
            sscanf(operacao + 15, "%d)", &elem);
            res = pushEsquerda(&d, elem);
        } else if (strncmp(operacao, "pushDireita(d,", 14) == 0) {
            sscanf(operacao + 14, "%d)", &elem);
            res = pushDireita(&d, elem);
        } else if (strcmp(operacao, "popEsquerda(d)") == 0) {
            res = popEsquerda(&d);
            if (res != FALHA) printf("%d\n", res);
        } else if (strcmp(operacao, "popDireita(d)") == 0) {
            res = popDireita(&d);
            if (res != FALHA) printf("%d\n", res);
        } else if (strcmp(operacao, "listEsquerda(d)") == 0) {
            res = listEsquerda(&d);
        } else if (strcmp(operacao, "listDireita(d)") == 0) {
            res = listDireita(&d);
        } else if (strcmp(operacao, "fim") == 0) {
            break;
        } else {
            printf("falha\n");
            break;
        }
        if (res == FALHA) {
            printf("falha\n");
            break;
        }
    }
    return 0;
}
