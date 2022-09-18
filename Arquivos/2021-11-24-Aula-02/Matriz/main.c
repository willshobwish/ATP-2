#include<stdio.h>
#include<stdlib.h>

int main(void){
    // float A[2][3],B[3][2],C[2][2];
    float **A, **B, **C;
    float soma_acumulada;
    int i,j,k;
    int l=2,c=3,m=3,n=2;

    //Exercício para treino (não precisa entregar): alocação dinâmica da memória em função
    // A = caloca(l,c);
    // B = caloca(m,n);
    // C = caloca(l,n);

    //matrizes em C são linhas e colunas, respectivamente
    //matriz A[linha][coluna]
    //utilização dinamica da memória, porém o que define a quantidade de linhas e colunas são as variáveis l, c, m, n
    A = (float **)calloc(l,sizeof(float *)); //definição do "tamanho da memória" que as linhas da matriz irão ocupar

    //(float **) casting para o tamanho de memória de ponteiro de ponteiro de float
    //calloc(tamanho-do-vetor, tamanho-do-tipo) aloca memória com base no tamanho da quantidade do vetor e de quantos bytes o tipo ocupa

    for(i=0;i<l;i++){ //definição do tamanho do armazenamento dinamico do tamanho de colunas para cada linha da matriz
        A[i] = (float *)calloc(c,sizeof(float)); //definição do tamanho que vai ocupar na memória
    }

    B = (float **)calloc(m,sizeof(float *));//o mesmo que foi demonstrado acima serve para as matrizes subsequentes
    for(i=0;i<m;i++){
        B[i] = (float *)calloc(n,sizeof(float));
    }

    C = (float **)calloc(l,sizeof(float *));
    for(i=0;i<l;i++){
        C[i] = (float *)calloc(n,sizeof(float));
    }

    for(i=0;i<l;i++){ //primeiro for para as linhas
        for(j=0;j<c;j++){ //segundo for para as colunas
            A[i][j]=i+j+1; //esse seria os valores que coluna assume, isso depende da posição que está
        }
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            B[i][j]=i+j+2;
        }
    }

    for(i=0;i<l;i++){
        for(j=0;j<n;j++){
            soma_acumulada = 0;
            for(k=0;k<c;k++){
                soma_acumulada = soma_acumulada + A[i][k] * B[k][j];
                //formatação para exibição no printf, quatro seria o espaçamento, ".1" para especificar quantas casas decimais serão exibidos
                printf("%4.1f * %4.1f: %4.1f ||", A[i][k], B[k][j], A[i][k]*B[k][j]);
            }
            C[i][j] = soma_acumulada;
            printf(" = C[%1d][%1d]: %4.1f\n",i,j,C[i][j]);
        }
    }

    //Exercício para treino (não precisa entregar): liberação da memória em função
    // libera(l,A);
    // libera(m,B);
    // libera(l,C);

    //liberação de memória
    for(i=0;i<l;i++){ //liberação para cada linha
        free(A[i]);
    }
    free(A); //liberação da memória do A

    for(i=0;i<m;i++){
        free(B[i]);
    }
    free(B);

    for(i=0;i<l;i++){
        free(C[i]);
    }
    free(C);

    return 0;
}
