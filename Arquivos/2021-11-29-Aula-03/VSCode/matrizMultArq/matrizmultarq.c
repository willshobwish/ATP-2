#include<stdio.h>
#include<stdlib.h>
#include "matrizmultarq.h"

float ** caloca(int linhas, int colunas){
    int i;
    float **matriz;
    matriz = (float **) calloc(linhas, sizeof(float *));
    for(i=0;i<0;i++){
        matriz[i]=(float *) calloc(colunas, sizeof(float));
    }
    return (matriz);
}

void libera(int linhas, float **matriz){
    int i;
    for(i=0;i<linhas;i++){
        free(matriz[i]);
    }
    free(matriz);
}

void multiplica(float **matrizA, float **matrizB, float **matrizC, int c, int l, int n){
    int i,j,k;
    float soma_acumulada;
    for(i=0;i<l;i++){
        for(j=0;j<n;j++){
            soma_acumulada=0;
            for(k=0;k<c;k++){
                soma_acumulada=soma_acumulada+(matrizA[i][k]*matrizB[k][j]);
            }

        }
    }
}