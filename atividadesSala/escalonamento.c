#include <stdio.h>

int main()
{
    int matriz[2][3] = {{1,1,10} , {5,10,90}} ;
    int n = 3;

    printf(" %d %d %d \n %d %d %d \n\n ", matriz[0][0], matriz[0][1], matriz[0][2], matriz[1][0], matriz[1][1], matriz[1][2]);

    for (int i = 1; i < n; i++) {

        int p = matriz[i][i];

        for (int j = i; j < n + 1; j++) {
            matriz[i][j] = (1 / p) * matriz[i][j];
        }

        for (int k = i + 1; k < n; k++){

            int q = matriz[k][i]; 

            for (int j = i; j < n + 1; j++) {
                matriz[k][j] = matriz[k][j] - q * matriz[i][j];
            }

        }
    }

    printf("%d %d %d \n %d %d %d ", matriz[0][0], matriz[0][1], matriz[0][2], matriz[1][0], matriz[1][1], matriz[1][2]);

}
