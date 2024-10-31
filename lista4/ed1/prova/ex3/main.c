#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ordem;
    double elementos[20][20];
} Matriz;

double calculafator(Matriz *M) {

    int i, j;
    double fator = 0.0;

    for (i = 0; i < M->ordem; i++) {
        
        for (j = 0; j < M->ordem; j++) {

            double kij = pow(-1, i + j) * M->elementos[i][j];

            fator += kij;
        }
    }
    return fator;
}

int main() {

    int i, j;
    Matriz M;

    scanf("%d", &M.ordem);

    for (i = 0; i < M.ordem; i++) {

        for (j = 0; j < M.ordem; j++) {

            scanf("%lf", &M.elementos[i][j]);
        }
    }
    // for (i = 0; i < M.ordem; i++) {
    //     for (j = 0; j < M.ordem; j++) {
    //         scanf("%lf", &M.elementos[i][j]);
    //     }
    // }
    
    double fator = calculafator(&M);
    
    printf("%.1lf\n", fator);

    return 0;
}
