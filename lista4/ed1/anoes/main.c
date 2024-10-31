#include <stdio.h>
#include <stdlib.h>

#define MAX_CORES 10001

typedef struct {
    int cor;
    int contagem;
} Cor;

int comparar(const void* a, const void* b) {
    return ((Cor*)b)->contagem - ((Cor*)a)->contagem;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, c, i;
        scanf("%d %d", &n, &c);

        int* toucas = (int*)malloc(n * sizeof(int));
        for (i = 0; i < n; i++) {
            scanf("%d", &toucas[i]);
        }

        int m;
        scanf("%d", &m);

        while (m--) {
            int a, b;
            scanf("%d %d", &a, &b);
            a--;
            b--;

            int tamanho = b - a + 1;
            int limite = tamanho / 2;
            int contagens[MAX_CORES] = {0};

            for (i = a; i <= b; i++) {
                contagens[toucas[i]]++;
            }

            Cor cores[MAX_CORES];
            int numCores = 0;

            
            for (i = 1; i <= c; i++) {
                if (contagens[i] > 0) {
                    cores[numCores].cor = i;
                    cores[numCores].contagem = contagens[i];
                    numCores++;
                }
            }

            qsort(cores, numCores, sizeof(Cor), comparar);

            if (numCores > 0 && cores[0].contagem > limite) {
                printf("bonita %d\n", cores[0].cor);
            } else {
                printf("feia\n");
            }
        }

        free(toucas);
    }

    return 0;
}
