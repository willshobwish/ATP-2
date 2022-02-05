#include <stdbool.h>  // stdbool.h para variaveis booleanos
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // time.h para funcao time()

#define NUMEROMAX 400000  // numero maximo de numeros aleatorios

int LeituraDimensaoArray(void) {  // funcao para definir o tamanho do array dentro de limitacoes
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
    } while (continuar);  // enquanto "continuar" possui o valor verdadeiro continuara repetindo, ate que entre com os valores dentro dos parametros
    return (dimensao);
}

void AssociaValoresArray(int *ponteiro, int dim) {  // funcao para associar os valores pseudoaleatorios no vetor gerado
    int i = 0;
    srand((unsigned)time(NULL));     // geracao de numeros aleatorios para matriz
    for (int i = 0; i < dim; i++) {  // cada vez ira percorrer o vetor e inserindo inteiros pseudoaleatorios
        *(ponteiro + i) = rand();    //*(ponteiro + i) == ponteiro[i]
    }
    return;
}

void ImpressaoValoresArray(int *ponteiro, int dim) {  // funcao para impressao dos valores contidos no vetor no console
    for (int i = 0; i < dim; i++) {                   // for para percorrer o vetor
        printf("\n[%d] = %d", i, *(ponteiro + i));    // cada vez que percorre, imprime no console o valor
    }
}

void troca(int *s, int indice1, int indice2) {  // funcao para trocar os elementos dos vetores para ordenacao
    int auxiliar;
    auxiliar = *(s + indice1);
    *(s + indice1) = *(s + indice2);
    *(s + indice2) = auxiliar;
}

void SelectionSort(int *ponteiro, int dim) {  // funcao para ordenacao do tipo "selection sort" sem indice
    int i, j, limite = dim - 1;
    for (i = 0; i < limite; i++) {
        for (j = i + 1; j < dim; j++) {
            if (*(ponteiro + j) < *(ponteiro + i))
                troca(ponteiro, i, j);
        }
    }
}

int main(void) {
    int tamanhoArray;                             // tamanho real do array vetor 1
    int vetor1[NUMEROMAX];                        // array vetor 1 para armazenar os elementos, um vetor eh ponteiro
    tamanhoArray = LeituraDimensaoArray();        // chamada de funcao com retorno,  a funcao verifica se esta correto ou nao
    AssociaValoresArray(vetor1, tamanhoArray);    // void AssociaValoresArray(int *ponteiro, int dim), funcao para associar valores ao vetor
    ImpressaoValoresArray(vetor1, tamanhoArray);  // void ImpressaoValoresArray(int *ponteiro, int dim)
}
