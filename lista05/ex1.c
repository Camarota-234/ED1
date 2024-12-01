#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int k, d = 1, n, pos = 0;
    scanf("%d", &k);
    while (k != 0) {
        pos = 0;
        for (d = 1; pos < k; d++) {
            for (n = 0; n <= d; n++) {
                if (gcd(n, d) == 1) {
                    pos++;
                    if (pos == k) {
                        printf("%d/%d\n", n, d);
                        break;
                    }
                }
            }
        }
        scanf("%d", &k);
    }
    return 0;
}
