#include <stdio.h>
#include <math.h>

int a, b;

int ehprimo(int n) {

    int i;
    
    if (n <= 1) {
        return 0;
    }

    if (n <= 3) {
        return 1;
    }

    if ((n % 2 == 0) || (n % 3 == 0)) {
        return 0;
    }

    for (i = 5; i * i <= n; i += 6) {
        if ((n % i == 0) || (n % (i + 2) == 0)) {
            return 0;
        }
    }

    return 1;
}

int main() {

    int n = 1, mersenne, temp = 0;
    
    scanf("%d %d", &a, &b);
    
    mersenne = pow(2, n) - 1;

    while (mersenne <= b) {

        if ((mersenne >= a) && (ehprimo(mersenne))) {
            temp++;
        }

        n++;

        mersenne = pow(2, n) - 1;
    }
    
    printf("%d\n", temp);

    return 0;
}
