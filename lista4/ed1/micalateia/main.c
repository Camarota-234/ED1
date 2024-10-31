#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[21];
    char telefone[10];
    int ligacoes;
    int ordemInsercao;
} Contato;

void inserirContato(Contato contatos[], int *tamanho, char nome[], char telefone[], int ligacoes, int ordem) {
    strcpy(contatos[*tamanho].nome, nome);
    strcpy(contatos[*tamanho].telefone, telefone);
    contatos[*tamanho].ligacoes = ligacoes;
    contatos[*tamanho].ordemInsercao = ordem;
    (*tamanho)++;
}

void removerContato(Contato contatos[], int *tamanho, char nome[]) {
    int i, j;
    for (i = 0; i < *tamanho; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            for (j = i; j < *tamanho - 1; j++) {
                contatos[j] = contatos[j + 1];
            }
            (*tamanho)--;
            break;
        }
    }
}

void registrarLigacao(Contato contatos[], int tamanho, char nome[]) {
    int i;
    for (i = 0; i < tamanho; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            contatos[i].ligacoes++;
            break;
        }
    }
}

void ordenarContatos(Contato contatos[], int tamanho) {
    int i, j;
    Contato temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = i + 1; j < tamanho; j++) {
            if (contatos[j].ligacoes > contatos[i].ligacoes || 
               (contatos[j].ligacoes == contatos[i].ligacoes && contatos[j].ordemInsercao < contatos[i].ordemInsercao)) {
                temp = contatos[i];
                contatos[i] = contatos[j];
                contatos[j] = temp;
            }
        }
    }
}

void listarContatos(Contato contatos[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%s - %s %d\n", contatos[i].nome, contatos[i].telefone, contatos[i].ligacoes);
    }
}

int main() {
    Contato contatos[MAX];
    int tamanho = 0, ordemInsercao = 0;
    char operacao, nome[21], telefone[10];
    int ligacoes;

    while (1) {
        scanf(" %c", &operacao);
        if (operacao == 'F') break;
        if (operacao == 'I') {
            scanf("%s %s %d", nome, telefone, &ligacoes);
            inserirContato(contatos, &tamanho, nome, telefone, ligacoes, ordemInsercao++);
        } else if (operacao == 'R') {
            scanf("%s", nome);
            removerContato(contatos, &tamanho, nome);
        } else if (operacao == 'L') {
            scanf("%s", nome);
            registrarLigacao(contatos, tamanho, nome);
        }
    }

    ordenarContatos(contatos, tamanho);
    listarContatos(contatos, tamanho);

    return 0;
}
