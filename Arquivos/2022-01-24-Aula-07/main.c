#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// time.h para funcao time()
#include <stdbool.h>
// stdbool.h para variaveis booleanos

// numero maximo de numeros aleatorios
#define NUMEROMAX 400000

int LeituraDimensaoArray(void) {
    int dimensao;
    bool continuar;
    do {
        fflush(stdin);
        printf("Insira o numero de componentes do array (>=1 && <= %d): ", NUMEROMAX);
        scanf("%d", &dimensao);
        if ((dimensao <= 0) || (dimensao > NUMEROMAX)) {
            printf("0 < numero de componentes <= %d\n", NUMEROMAX);
            continuar = true;
        } else {
            continuar = false;
        }
    } while (continuar);
    return (dimensao);
}

void AssociaValoresArray(int *ponteiro, int dim) {
    int i = 0;
    srand((unsigned)time(NULL));
    // geracao de numeros aleatorios para matriz
    // srand
    for (int i = 0; i < dim; i++) {
        *(ponteiro + i) = rand();
    }
    return;
}

void ImpressaoValoresArray(int *ponteiro, int dim) {
    for (int i = 0; i < dim; i++) {
        // for para percorrer array
        printf("\n[%d] = %d", i, *(ponteiro + i));
    }
}

void troca(int *s, int indice1, int indice2) {
    int auxiliar;
    auxiliar = *(s + indice1);
    *(s + indice1) = *(s + indice2);
    *(s + indice2) = auxiliar;
}

void SelectionSort(int *ponteiro, int dim) {
    int i, j, limite = dim - 1;
    for (i = 0; i < limite; i++) {
        for (j = i + 1; j < dim; j++) {
            if (*(ponteiro + j) < *(ponteiro + i))
                troca(ponteiro, i, j);
        }
    }
}

int main(void) {
    int tamanhoArray;
    // tamanho real do array vetor 1

    int vetor1[NUMEROMAX];
    // array vetor 1 para armazenar os elementos
    // um vetor eh ponteiro

    tamanhoArray = LeituraDimensaoArray();
    // chamada de funcao com retorno
    // a funcao verifica se esta correto ou nao

    AssociaValoresArray(vetor1, tamanhoArray);
    // void AssociaValoresArray(int *ponteiro, int dim)
    // funcao para associar valores ao vetor

    ImpressaoValoresArray(vetor1, tamanhoArray);
    // void ImpressaoValoresArray(int *ponteiro, int dim)
}
