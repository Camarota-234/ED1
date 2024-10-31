#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

int main() {
    int n, i, j, ordem[MAX], pilha[MAX], topo, vagao;
    bool possivel;

    while (scanf("%d", &n) && n != 0) {
        while (scanf("%d", &ordem[0]) && ordem[0] != 0) {
            
            for (i = 1; i < n; i++) {
                scanf("%d", &ordem[i]);
            }
            topo = 0;
            vagao = 1;
            possivel = true;

            for (i = 0; i < n; i++) {
                while (vagao <= ordem[i]) {
                    pilha[topo++] = vagao++;
                }
                if (pilha[--topo] != ordem[i]) {
                    possivel = false;
                    break;
                }
            }
            if (possivel) {
                printf("sim\n");
            } else {
                printf("nao\n");
            }
        }
        printf("\n");
    }

    return 0;
}
