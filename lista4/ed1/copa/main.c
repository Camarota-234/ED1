#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int id;             
    struct No* prox; 
} No;


No* createNo(int id) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo != NULL) {
        novoNo->id = id;
        novoNo->prox = NULL;
    }
    return novoNo;
}


void freeList(No* inicio) {
    No* atual = inicio;
    while (atual != NULL) {
        No* prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

int main() {
    int n; 
    scanf("%d", &n);

   
    No* inicio = NULL;
    No* fim = NULL;
    int i = 0;
    for (i = 0; i < n; ++i) {
        int mi;
        scanf("%d", &mi);

        No* novoNo = createNo(mi);
        if (inicio == NULL) {
            inicio = novoNo;
            fim = novoNo;
        } else {
            fim->prox = novoNo;
            fim = novoNo;
        }
    }

   
    int s;
    scanf("%d", &s);

    for (i = 0; i < s; ++i) {
        int si;
        scanf("%d", &si);

        
        No* atual = inicio;
        No* anterior = NULL;

        while (atual != NULL && atual->id != si) {
            anterior = atual;
            atual = atual->prox;
        }

        
        if (atual != NULL) {
            if (anterior == NULL) {
               
                inicio = inicio->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual); 
        }
    }

    
    No* atual = inicio;
    while (atual != NULL) {
        printf("%d ", atual->id);
        atual = atual->prox;
    }
    printf("\n");

    
    freeList(inicio);

    return 0;
}
