#include <stdio.h>

int converteParaMinutos(int h, int m) {
    return (h - 7) * 60 + m;
}

int main() {
    int n, i;
    scanf("%d", &n);

    int h[50], m[50], c[50];
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &h[i], &m[i], &c[i]);
    }

    int tempoAtendimento = 0;
    int pacientesCriticos = 0;

    for (i = 0; i < n; i++) {
        int chegada = converteParaMinutos(h[i], m[i]);
        int critico = chegada + c[i];

        if (chegada > tempoAtendimento) {
            tempoAtendimento = chegada;
        }

        if (tempoAtendimento % 30 != 0) {
            tempoAtendimento = ((tempoAtendimento / 30) + 1) * 30;
        }

        if (critico < tempoAtendimento) {
            pacientesCriticos++;
        }

        tempoAtendimento += 30;
    }

    printf("%d\n", pacientesCriticos);

    return 0;
}
