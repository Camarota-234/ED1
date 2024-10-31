#include <stdio.h>
#include <string.h>

#define MAX 1000

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

int verificarExpressao(char *expressao) {
    Pilha p;
    inicializarPilha(&p);
    int i; 

    for (i = 0; i < strlen(expressao); i++) {
        if (expressao[i] == '(') {
            empilhar(&p, '(');
        } else if (expressao[i] == ')') {
            if (pilhaVazia(&p)) {
                return 0; 
            }
            desempilhar(&p);
        }
    }
    return pilhaVazia(&p);
}

int main() {
    char expressao[MAX];

    scanf("%[^\n]%*c", expressao);

    if (verificarExpressao(expressao)) {
        printf("correta\n");
    } else {
        printf("incorreta\n");
    }

    return 0;
}
