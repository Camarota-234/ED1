#include <stdio.h>

int main() {
    int t, n, k, i, j, l, maxL;
    char grid[1000][1000];
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf(" %c", &grid[i][j]);
            }
        }
        maxL = 0;
        for (i = 0; i < n; i++) {
            int caught[1000] = {0};
            for (j = 0; j < n; j++) {
                if (grid[i][j] == 'P') {
                    for (l = j - k; l <= j + k && l < n; l++) {
                        if (l >= 0 && grid[i][l] == 'L' && !caught[l]) {
                            maxL++;
                            caught[l] = 1;
                            break;
                        }
                    }
                }
            }
        }
        printf("%d\n", maxL);
    }
    return 0;
}
