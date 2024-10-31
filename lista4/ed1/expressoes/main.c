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

int verificarCadeia(char *cadeia) {
    Pilha p;
    inicializarPilha(&p);
    int i;

    for (i = 0; i < strlen(cadeia); i++) {
        if (cadeia[i] == '(' || cadeia[i] == '[' || cadeia[i] == '{') {
            empilhar(&p, cadeia[i]);
        } else if (cadeia[i] == ')' || cadeia[i] == ']' || cadeia[i] == '}') {
            if (pilhaVazia(&p)) return 0;
            char topo = desempilhar(&p);
            if ((cadeia[i] == ')' && topo != '(') || (cadeia[i] == ']' && topo != '[') || (cadeia[i] == '}' && topo != '{'))
                return 0;
        }
    }
    return pilhaVazia(&p);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char cadeia[MAX];
        scanf("%s", cadeia);
        if (verificarCadeia(cadeia)) {
            printf("bem-formada\n");
        } else {
            printf("mal-formada\n");
        }
    }

    return 0;
}
