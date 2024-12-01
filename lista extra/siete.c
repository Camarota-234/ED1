#include <stdio.h>
#include <string.h>

void insertionSort(char v[][101], int n, int ordem) {
    int i, j;
    char temp[101];
    for (i = 1; i < n; i++) {
        strcpy(temp, v[i]);
        j = i - 1;
        while (j >= 0 && ((ordem == 1 && strcmp(v[j], temp) > 0) || (ordem == -1 && strcmp(v[j], temp) < 0))) {
            strcpy(v[j + 1], v[j]);
            j--;
        }
        strcpy(v[j + 1], temp);
    }
}

int main() {
    char palavras[1000][101];
    char comando[10];
    int n = 0, i, ordem;

    while (1) {
        scanf(" %[^\n]", palavras[n]);
        if (strcmp(palavras[n], "ASC") == 0) {
            ordem = 1;
            break;
        }
        if (strcmp(palavras[n], "DESC") == 0) {
            ordem = -1;
            break;
        }
        n++;
    }

    insertionSort(palavras, n, ordem);

    for (i = 0; i < n; i++) {
        printf("%s\n", palavras[i]);
    }

    return 0;
}
