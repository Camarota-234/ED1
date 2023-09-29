#include <stdio.h>

int main() {
    printf("jg");
    int vetor[8] = {2,4,5,6,1,3,7,8};
    int t = 1;
    int aux;

    for(int i = 0; i < 8; i++) {

        if ((i /2) == 0) {

            while( t = 1) {
                t = 0;

                for(int j = 0; i < 4; i++) {

                    if (vetor[j] > vetor[j+1]) {
                        aux = vetor[j];
                        vetor[j] = vetor[j+1];
                        vetor[j+1] = vetor[j];

                        if (t == 0) { t = 1; }
                    }
                    
                }

            }

        }

        else {

            while( t = 1) {
                t = 0;

                for(int j = 3; i < 8; i++) {

                    if (vetor[j] > vetor[j+1]) {
                        aux = vetor[j];
                        vetor[j] = vetor[j+1];
                        vetor[j+1] = vetor[j];

                        if (t == 0) { t = 1; }
                    }
                    
                }

            }
        }
    }

    for (int k = 0; k < 8; k++) {
        printf("%d, ", vetor[k]);
    }

}