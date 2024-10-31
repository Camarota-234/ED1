#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    int lista[MAX];
    int tamanho;
} Lista;

void inserirInimigo(Lista *l, int pos, int inimigo) {
    int i;
    for (i = l->tamanho; i > pos; i--) {
        l->lista[i] = l->lista[i - 1];
    }
    l->lista[pos + 1] = inimigo;
    l->tamanho++;
}

void removerInimigo(Lista *l, int inimigo) {
    int i, j;
    for (i = 0; i < l->tamanho; i++) {
        if (l->lista[i] == inimigo) {
            for (j = i; j < l->tamanho - 1; j++) {
                l->lista[j] = l->lista[j + 1];
            }
            l->tamanho--;
            break;
        }
    }
}

int contarEntre(Lista *l, int a, int b) {
    int i, inicio = -1, fim = -1, contador = 0;
    for (i = 0; i < l->tamanho; i++) {
        if (l->lista[i] == a) inicio = i;
        if (l->lista[i] == b) fim = i;
    }
    if (inicio > fim) {
        int temp = inicio;
        inicio = fim;
        fim = temp;
    }
    for (i = inicio + 1; i < fim; i++) {
        contador++;
    }
    return contador;
}

void mostrarLista(Lista *l) {
    int i;
    if (l->tamanho == 0) {
        printf("lista vazia\n");
    } else {
        printf("lista");
        for (i = 0; i < l->tamanho; i++) {
            printf(" %d", l->lista[i]);
        }
        printf("\n");
    }
}

int main() {
    Lista l;
    l.tamanho = 0;
    int n, inimigo, i;
    char operacao;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &l.lista[i]);
    }
    l.tamanho = n;

    while (1) {
        scanf(" %c", &operacao);
        if (operacao == 'F') {
            printf("fim\n");
            break;
        } else if (operacao == 'I') {
            int p, e;
            scanf("%d %d", &p, &e);
            for (i = 0; i < l.tamanho; i++) {
                if (l.lista[i] == e) {
                    inserirInimigo(&l, i, p);
                    printf("inserido %d\n", p);
                    break;
                }
            }
        } else if (operacao == 'R') {
            scanf("%d", &inimigo);
            removerInimigo(&l, inimigo);
            printf("removido %d\n", inimigo);
        } else if (operacao == 'C') {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("quantidade %d\n", contarEntre(&l, a, b));
        } else if (operacao == 'M') {
            mostrarLista(&l);
        }
    }

    return 0;
}
