#include <stdio.h>

int main()
{
    int matriz[3][3];
    int n = 5;
    for (int i = 1; i < n; i++)
    {
        int p = matriz[i][i];

        for (int j = i; j < n + 1; j++)
        {
            matriz[i][j] = (1 / p) * matriz[j][j];
        }

        for (int k = i + 1; k < n; k++)
        {
            int q = matriz[k][i];

            for (int j = i; j < n + 1; j++)
            {

                matriz[k][j] = matriz[k][j] - q * matriz[i][j];
            }
        }
    }
}
