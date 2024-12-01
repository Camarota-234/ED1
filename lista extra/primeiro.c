#include <stdio.h>
#include <string.h>

char *unidades[] = {"", "UM", "DOIS", "TRES", "QUATRO", "CINCO", "SEIS", "SETE", "OITO", "NOVE"};
char *teens[] = {"DEZ", "ONZE", "DOZE", "TREZE", "CATORZE", "QUINZE", "DEZESSEIS", "DEZESSETE", "DEZOITO", "DEZENOVE"};
char *dezenas[] = {"", "", "VINTE", "TRINTA", "QUARENTA", "CINQUENTA", "SESSENTA", "SETENTA", "OITENTA", "NOVENTA"};
char *centenas[] = {"", "CENTO", "DUZENTOS", "TREZENTOS", "QUATROCENTOS", "QUINHENTOS", "SEISCENTOS", "SETECENTOS", "OITOCENTOS", "NOVECENTOS"};

void escreveExtenso(int valor, char *buffer, int isMil) {
    if (valor == 0) return;
    if (valor >= 100) {
        if (valor == 100) {
            strcat(buffer, "CEM");
        } else {
            strcat(buffer, centenas[valor / 100]);
        }
        valor %= 100;
        if (valor > 0) strcat(buffer, " E ");
    }
    if (valor >= 20) {
        strcat(buffer, dezenas[valor / 10]);
        valor %= 10;
        if (valor > 0) strcat(buffer, " E ");
    } else if (valor >= 10) {
        strcat(buffer, teens[valor - 10]);
        valor = 0;
    }
    if (valor > 0) {
        strcat(buffer, unidades[valor]);
    }
    if (isMil && strcmp(buffer, "UM") == 0) {
        strcpy(buffer, "MIL");
    }
}

void converteValor(double valor, char *saida) {
    int reais = (int)valor;
    int centavos = (int)((valor - reais) * 100);
    char parteReais[500] = "";
    char parteCentavos[500] = "";

    if (reais == 1000000) {
        strcpy(parteReais, "UM MILHAO DE REAIS");
    } else {
        if (reais >= 1000) {
            escreveExtenso(reais / 1000, parteReais, 1);
            strcat(parteReais, " MIL");
            reais %= 1000;
            if (reais > 0) strcat(parteReais, " ");
        }
        if (reais > 0) {
            escreveExtenso(reais, parteReais + strlen(parteReais), 0);
            strcat(parteReais, reais == 1 ? " REAL" : " REAIS");
        } else if (strlen(parteReais) > 0) {
            strcat(parteReais, " REAIS");
        }
    }

    if (centavos > 0) {
        escreveExtenso(centavos, parteCentavos, 0);
        strcat(parteCentavos, centavos == 1 ? " CENTAVO" : " CENTAVOS");
    }

    if (strlen(parteReais) > 0) {
        strcat(saida, parteReais);
    }
    if (strlen(parteCentavos) > 0) {
        if (strlen(parteReais) > 0) strcat(saida, " E ");
        strcat(saida, parteCentavos);
    }
}

int main() {
    int t, i;
    scanf("%d", &t);
    i = 0;
    while (i < t) {
        double valor;
        scanf("%lf", &valor);
        char resultado[1000] = "";
        converteValor(valor, resultado);
        printf("%s\n", resultado);
        i++;
    }
    return 0;
}
