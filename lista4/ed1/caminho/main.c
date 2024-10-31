#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
#define MAX_INSTRUCOES 10
#define MAX_CAR 21
 
typedef struct {
    char direcao[MAX_CAR];
    char rua[MAX_CAR];
} Instrucao;
 
int main() {
    Instrucao instrucoes[MAX_INSTRUCOES];
    int count = 0;
    int i;
    
    
    while (1) {
        scanf("%s", instrucoes[count].direcao);
        scanf("%s", instrucoes[count].rua);
        
        if (strcmp(instrucoes[count].rua, "ESCOLA") == 0) {
            
            break;
        }
        count++; 
    }
    
    for (i = count; i >= 0; i--) {
        if (strcmp(instrucoes[i].rua, "ESCOLA") != 0) {
            if (strcmp(instrucoes[i+1].direcao, "DIREITA") == 0) {
                printf("Vire a ESQUERDA na rua %s.\n", instrucoes[i].rua);
            } else if(strcmp(instrucoes[i+1].direcao, "ESQUERDA") == 0){
                printf("Vire a DIREITA na rua %s.\n", instrucoes[i].rua);
            } else {
                printf("erro\n");
            }
        }
    }
    
    if (strcmp(instrucoes[0].direcao, "DIREITA") == 0) {
        printf("Vire a ESQUERDA para chegar em CASA.\n");
    } else {
        printf("Vire a DIREITA para chegar em CASA.\n");
    }
    
    return 0;
}