#include <stdio.h>

int main() {
    int n, q, i, j, count;
    int cafes[1000], m;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &cafes[i]);
    }
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &m);
        count = 0;
        for (j = 0; j < n; j++) {
            if (cafes[j] <= m) {
                count++;
            }
        }
        printf("%d", count);
        for (j = 0; j < n; j++) {
            if (cafes[j] <= m) {
                printf(" %d", j + 1);
            }
        }
        printf("\n");
    }
    return 0;
}
