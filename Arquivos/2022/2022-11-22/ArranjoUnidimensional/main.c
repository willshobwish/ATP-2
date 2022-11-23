// Manipulação basica de um arranjo unidimensional

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // numero maximo de componentes do array

int main() {
    int i,       // indice para percorrer o array/vetor
        a[MAX];  // array/vetor para armazenar os elementos da sequencia

    // Associando valores aos elementos do vetor
    for (i = 0; i < MAX; i++) {
        a[i] = i * 2 + 10;
    }

    // Impressao dos valores associados ao array

    printf("Quarta Componente (primeiro indice eh 0) --> a[3] = %d", a[3]);
    printf("\n\n");
    // Impressao dos valores associados ao array usando indice da posicao
    for (i = 0; i < MAX; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    // ATENCAO - Acessando componente fora dos limites definidos
    // A Linguagem C  não faz verificação de limites. Isto eh responsabilidade do Programador

    printf("\n\n ATENCAO: a[8] fora dos limites do vetor declarado  --> %d", a[8]);
    printf("\n\n ATENCAO: a[38] fora dos limites do vetor declarado --> %d\n\n", a[38]);

    printf("Pressione enter/return para finalizar ...");
    getchar();
    return (0);
}  // main