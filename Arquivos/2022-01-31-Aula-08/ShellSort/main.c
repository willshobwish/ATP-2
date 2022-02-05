// Este algoritmo nao esta funcionando corretamente
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHOMAXIMO 40000

int LeituraDimensaoVetor() {  // funcao que define o tamatnho do vetor a partir da entrada do usuario
    int dimensao;
    bool continua = true;
    do {
        printf("Insira a quantidade de componentes no array (>= 1 e <= %d): ", TAMANHOMAXIMO);
        scanf("%d", &dimensao);
        if ((dimensao <= 0) && (dimensao > TAMANHOMAXIMO)) {  // caso a condicao nao esteja dentro dos parametros ira repetir o processo
            printf("0 < numero de componentes <= %d", TAMANHOMAXIMO);
        } else {
            continua = false;
        }
    } while (continua);
    return dimensao;
}

void AssociarValoresVetor(int *ponteiro, int dimensao) {  // funcao que gera valores pseudoaleatorios para preencher o vetor com elementos numericos
    time_t tempo;
    srand((unsigned)time(&tempo));        // void srand(unsigned int seed), precisa de uma "semente" para gerar numeros pseudoaleatorios
    for (int i = 0; i < dimensao; i++) {  // for para percorrer o vetor e atribuir valores aos elementos do vetor
        *(ponteiro + i) = rand();         // atribuicao em cada elemento
    }
    return;
}

void ImprimirValoresVetor(int *ponteiro, int dimensao) {
    for (int i = 0; i < dimensao; i++) {
        printf("[%d] = %d\n", i, *(ponteiro + i));
    }
}

void Troca(int *indice1, int *indice2) {  // funcao "troca" diferente dos demais, nao precisa da posicao, mas nao eh utilizado no codigo
    int auxiliar;
    auxiliar = *indice1;
    *indice1 = *indice2;
    *indice2 = auxiliar;
}

void ShellSort(int *ponteiro, int dimensao) {
    int i, j, x, salto;
    for (salto = dimensao / 2; salto > 0; salto /= 2) {  //"salto /= 2" equivale a "salto = salto / 2"
        for (i = salto; i < dimensao; i++) {
            x = *(ponteiro + i);
            for (j = i; (j >= salto) && (x < *(ponteiro + j - salto)); j = j - salto) {
                *(ponteiro + j) = *(ponteiro + j - salto);
                *(ponteiro + j) = x;
            }
        }
    }
    return;
}

int main() {
    int tamanhoVetor, vetor[TAMANHOMAXIMO];
    tamanhoVetor = LeituraDimensaoVetor();
    AssociarValoresVetor(vetor, tamanhoVetor);
    puts("Vetor original:");
    ImprimirValoresVetor(vetor, tamanhoVetor);
    ShellSort(vetor, tamanhoVetor);
    puts("\nVetor Ordenado:");
    ImprimirValoresVetor(vetor, tamanhoVetor);
    puts("");
    printf("Pressione enter/return para finalizar...");
    fflush(stdin);
    getchar();
    return 0;
}
