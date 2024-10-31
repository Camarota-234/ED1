#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int empilhar(Pilha *p, char valor) {
    if (p->topo < MAX - 1) {
        p->dados[++p->topo] = valor;
        return 1;
    }
    return 0;
}

char desempilhar(Pilha *p) {
    if (!pilhaVazia(p)) {
        return p->dados[p->topo--];
    }
    return '\0';
}

char topo(Pilha *p) {
    if (!pilhaVazia(p)) {
        return p->dados[p->topo];
    }
    return '\0';
}

int precedencia(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void converterParaPosfixa(char *expressao) {
    Pilha p;
    inicializarPilha(&p);
    int i;

    for (i = 0; i < strlen(expressao); i++) {
        if (isalpha(expressao[i]) || isdigit(expressao[i])) {
            printf("%c ", expressao[i]);
        } else if (expressao[i] == '(') {
            empilhar(&p, '(');
        } else if (expressao[i] == ')') {
            while (!pilhaVazia(&p) && topo(&p) != '(') {
                printf("%c ", desempilhar(&p));
            }
            desempilhar(&p);
        } else if (strchr("+-*/^", expressao[i])) {
            while (!pilhaVazia(&p) && precedencia(topo(&p)) >= precedencia(expressao[i])) {
                printf("%c ", desempilhar(&p));
            }
            empilhar(&p, expressao[i]);
        }
    }

    while (!pilhaVazia(&p)) {
        printf("%c ", desempilhar(&p));
    }
    printf("\n");
}

int main() {
    int t;
    char expressao[MAX];

    scanf("%d", &t);
    while (t--) {
        scanf(" %[^\n]", expressao);
        converterParaPosfixa(expressao);
    }

    return 0;
}
