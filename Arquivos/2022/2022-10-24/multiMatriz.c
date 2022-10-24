#include "multiMatriz.h"

#include <stdlib.h>

float **caloca(int lin, int col) {
    int i;
    float **pm;
    pm = (float **)calloc(lin, sizeof(float *));
    for (i = 0; i < lin; i++) {
        pm[i] = (float *)calloc(col, sizeof(float));
    }
    return pm;
}

void clibera(int lin, float **pm) {
    int i;
    for (i = 0; i < lin; i++) {
        free(pm[i]);
    }
    free(pm);
}

void multiplica(float **A, float **B, float **C, int colAlinB, int linA, int colB) {
    int i, j, k;
    float soma_acumulada;
    for (i = 0; i < linA; i++) {
        for (j = 0; j < colB; j++) {
            soma_acumulada = 0;
            for (k = 0; k < colAlinB; k++) {
                soma_acumulada += A[i][k] * B[k][j];
            }
            C[i][j] = soma_acumulada;
        }
    }
}