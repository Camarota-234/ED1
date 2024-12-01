#include <stdio.h>
#include <string.h>

int main() {
    int t, i, j, temp;
    char s[10001];
    char vogal[] = "AEIOUaeiou";
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%s", s);
        temp = 0;
        for (j = 0; s[j] != '\0'; j++) {
            if (strchr(vogal, s[j]) != NULL) {
                temp++;
            }
        }
        printf("%d\n", temp);
    }
    return 0;
}
