#include<stdio.h>
#include<stdlib.h>

int main(void){
    float **A, temporario;
    int linha_A, coluna_A, i, j;

    printf("Quantidade de linhas na matriz A: ");
    scanf("%i",&linha_A);
    printf("Quantidade de colunas na matriz A: ");
    scanf("%i",&coluna_A);

    A = (float **)calloc(linha_A,sizeof(float *));
    for(i=0;i<coluna_A;i++){
        A[i] = (float *)calloc(coluna_A, sizeof(float));
    }

    for(i=0;i<linha_A;i++){
        for(j=0;j<coluna_A;j++){
            temporario=0;
            printf("Coloque o valor de A[%i][%i]:",i,j);
            scanf("%f",&temporario);
            A[i][j]=temporario;
        }
    }
    
        for(i=0;i<linha_A;i++){
        for(j=0;j<coluna_A;j++){
            printf("O valor de A[%i][%i]: %f\n",i,j,A[i][j]);
        }
    }
    return 0;
}