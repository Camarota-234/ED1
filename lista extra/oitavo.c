#include <stdio.h>

void geraMagicSquare(int n) {
    if (n == 2) {
        printf("nao existe\n");
        return;
    }

    int magicSquare[50][50] = {0};
    int i = 0, j = n / 2, num;

    for (num = 1; num <= n * n; num++) {
        magicSquare[i][j] = num;
        i--;
        j++;
        if (num % n == 0) {
            i += 2;
            j--;
        } else if (i < 0) {
            i = n - 1;
        } else if (j == n) {
            j = 0;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d", magicSquare[i][j]);
            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 2) {
        printf("nao existe\n");
    } else {
        geraMagicSquare(n);
    }
    return 0;
}
