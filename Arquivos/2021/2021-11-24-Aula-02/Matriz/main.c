#include<stdio.h>
#include<stdlib.h>

int main(void){
    // float A[2][3],B[3][2],C[2][2];
    float **A, **B, **C;
    float soma_acumulada;
    int i,j,k;
    int l=2,c=3,m=3,n=2;

    //Exerc�cio para treino (n�o precisa entregar): aloca��o din�mica da mem�ria em fun��o
    // A = caloca(l,c);
    // B = caloca(m,n);
    // C = caloca(l,n);

    //matrizes em C s�o linhas e colunas, respectivamente
    //matriz A[linha][coluna]
    //utiliza��o dinamica da mem�ria, por�m o que define a quantidade de linhas e colunas s�o as vari�veis l, c, m, n
    A = (float **)calloc(l,sizeof(float *)); //defini��o do "tamanho da mem�ria" que as linhas da matriz ir�o ocupar

    //(float **) casting para o tamanho de mem�ria de ponteiro de ponteiro de float
    //calloc(tamanho-do-vetor, tamanho-do-tipo) aloca mem�ria com base no tamanho da quantidade do vetor e de quantos bytes o tipo ocupa

    for(i=0;i<l;i++){ //defini��o do tamanho do armazenamento dinamico do tamanho de colunas para cada linha da matriz
        A[i] = (float *)calloc(c,sizeof(float)); //defini��o do tamanho que vai ocupar na mem�ria
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
            A[i][j]=i+j+1; //esse seria os valores que coluna assume, isso depende da posi��o que est�
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
                //formata��o para exibi��o no printf, quatro seria o espa�amento, ".1" para especificar quantas casas decimais ser�o exibidos
                printf("%4.1f * %4.1f: %4.1f ||", A[i][k], B[k][j], A[i][k]*B[k][j]);
            }
            C[i][j] = soma_acumulada;
            printf(" = C[%1d][%1d]: %4.1f\n",i,j,C[i][j]);
        }
    }

    //Exerc�cio para treino (n�o precisa entregar): libera��o da mem�ria em fun��o
    // libera(l,A);
    // libera(m,B);
    // libera(l,C);

    //libera��o de mem�ria
    for(i=0;i<l;i++){ //libera��o para cada linha
        free(A[i]);
    }
    free(A); //libera��o da mem�ria do A

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
