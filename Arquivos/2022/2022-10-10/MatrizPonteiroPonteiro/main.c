#include <stdio.h>
#include <stdlib.h>

float **caloca(int lin, int col) {
}

void clibera(int lin, float **pm) {
}

void somaMatrizes(float **m1, float **m2, float **m3, int l, int c) {
}

int main() {
    float **A, **B, **C;  // definindo ponteiro de ponteiro
    int i, j;
    int l = 3, c = 3, m = 3, n = 3;
    // alocacao dinamica de ponteiros
    A = caloca(l, c);
    B = caloca(m, n);
    C = caloca(l, n);
    // inicializando a matriz A[l][c]
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            A[i][j] = i + j + 1;
        }
    }
    // inicializando a matriz B[m][n]
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            B[i][j] = i + j + 2;
        }
    }

    if ((l == m) && (c == n)) {
        somaMatrizes(A, B, C, l, c);
        // pode ser somaMatrizes(A,B,C,m,n)
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("C[%i][%i] = A[%i][%i] + B[%i][%i] = %f + %f = %f\n", i, j, i, j, i, j, A[i][j], B[i][j], C[i][j]);
            }
        }
    } else {
        printf("Dimensoes incompativeis para a soma\n");
    }
    // liberacao do espaco alocado dinamicamente
    clibera(l, A);
    clibera(m, B);
    clibera(l, C);

    printf("Pressione return/enter para finalizar... ");
    getchar();
    return 0;
}
