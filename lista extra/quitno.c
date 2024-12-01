#include <stdio.h>

int contaDigitos(int n, int k) {
    if (n == 0) return 0;
    return (n % 10 == k) + contaDigitos(n / 10, k);
}

int main() {
    int t, k, i, num;
    scanf("%d", &t);
    scanf("%d", &k);
    for (i = 0; i < t; i++) {
        scanf("%d", &num);
        printf("%d", contaDigitos(num, k));
        if (i < t - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
