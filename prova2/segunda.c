#include <stdio.h>

int main() {
    int A[10000], B[10000], S[20000];
    int numA = 0, numB = 0, posicao = 0, i;

    while (numA < 10000) {
        scanf("%d", &A[numA]);
        if (A[numA] == -1) break;
        numA++;
    }

    while (numB < 10000) {
        scanf("%d", &B[numB]);
        if (B[numB] == -1) break;
        numB++;
    }

    if (numA == 0 && numB == 0) {
        printf("-1\n");
        return 0;
    } else if (numA == 0) {
        for (i = 0; i < numB; i++) {
            S[posicao++] = B[i];
        }
        S[posicao++] = -1;
    } else if (numB == 0) {
        for (i = 0; i < numA; i++) {
            S[posicao++] = A[i];
        }
        S[posicao++] = -1;
    } else if (numA > numB) {
        for (i = 0; i < numA; i++) {
            S[posicao++] = A[i];
        }
        for (i = 0; i < numB; i++) {
            S[posicao++] = B[i];
        }
        S[posicao++] = -1;
    } else if (numB > numA) {
        for (i = 0; i < numB; i++) {
            S[posicao++] = B[i];
        }
        for (i = 0; i < numA; i++) {
            S[posicao++] = A[i];
        }
        S[posicao++] = -1;
    } else {
        for (i = 0; i < numA; i++) {
            S[posicao++] = A[i];
            S[posicao++] = B[i];
        }
        S[posicao++] = -1;
    }

    for (i = 0; i < posicao; i++) {
        if (i > 0) printf(" ");
        printf("%d", S[i]);
    }
    printf("\n");

    return 0;
}
