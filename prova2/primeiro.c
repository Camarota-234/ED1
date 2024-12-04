#include <stdio.h>

int main()
{
    int entrada[100];
    int saida[100];
    int n, i, j;

    for (n = 0; n < 100; n++) {

        scanf("%d", &entrada[n]);
        if (entrada[n] == -1) {
            break;
        }
            
    }

    int primo;
    int conta = 0;
    for (i = 0; i < n; i++) {

        if (entrada[i] < 2) {
            continue;
        }
            
        primo = 1;
        for (j = 2; j * j <= entrada[i]; j++) {

            if (entrada[i] % j == 0) {
                primo = 0;
                break;
            }
        }
        if (primo) {
            for (j = 0; j < conta; j++) {
                if (saida[j] == entrada[i])
                    break;
            }
            if (j == conta) {
                saida[conta++] = entrada[i];
            }
        }
    }
    if (conta == 0) {
        printf("-1\n");
    }
    else {

        int x, y, temp2;
        for (x = 0; x < conta - 1; x++) {
            for (y = x + 1; y < conta; y++) {
                if (saida[x] > saida[y]) {
                    temp2 = saida[x];
                    saida[x] = saida[y];
                    saida[y] = temp2;
                }
            }
        }

        for (i = 0; i < conta; i++) {
            
            printf("%d ", saida[i]);
        }
        printf("\n");
    }
    return 0;
}
