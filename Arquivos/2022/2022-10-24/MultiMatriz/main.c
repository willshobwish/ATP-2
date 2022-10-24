#include <stdio.h>
#include <stdlib.h>

#include "multiMatriz.h"

int main() {
    float **A;  // matriz A: ponteiro de ponteiro
    float **B;  // matriz B
    float **C;  // matriz C
    int linA = 2, colA = 3, linB = 3, colB = 2;
    int i, j, k;
    // Alocando dinamicamente as matrizes
    A = caloca(linA, colA);
    B = caloca(linB, colB);
    C = caloca(linA, colB);
    // Inicializacao das matrizes A e B
    for (i = 0; i < linA; i++) {
        for (j = 0; j < colA; j++) {
            A[i][j] = i + j + 1.0;
            printf("%4.1f ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < linB; i++) {
        for (j = 0; j < colB; j++) {
            B[i][j] = i + j + 2.0;
            printf("%4.1f ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    if (colA == linB) {                         // eh possivel realizar a multiplicacao? SIM
        multiplica(A, B, C, colA, linA, colB);  // pode ser linB no lugar de colA
        // mostrando a matriz C = A * B, resultado da multiplicacao
        for (i = 0; i < linA; i++) {
            for (j = 0; j < colB; j++) {
                for (k = 0; k < colA; k++) {
                    printf("%4.1f * %4.1f:%4.1f  ", A[i][k], B[k][j], A[i][k] * B[k][j]);
                }
                printf(" = C[%1d][%1d]: %4.1f\n\n", i, j, C[i][j]);
            }
        }
        // liberacao do espaco alocado dinamicamente
        clibera(linA, A);
        clibera(linB, B);
        clibera(linA, C);
    } else {  // NAO eh possivel realizar a multiplicacao
        printf("Nao eh possivel realizar a multiplicacao\n");
    }

    printf("\nPressione return/enter para finalizar ... ");
    getchar();
    return 0;
}
