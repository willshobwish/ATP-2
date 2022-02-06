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
    time_t tempo;                                         // typedef /* unspecified */ time_t;
    srand((unsigned)time(&tempo));                        // void srand(unsigned int seed), precisa de uma "semente" para gerar numeros pseudoaleatorios
    for (int i = 0; i < dimensao; i++) {                  // for para percorrer o vetor e atribuir valores aos elementos do vetor
        *(ponteiro + i) = rand();                         // atribuicao em cada elemento
    }
    return;
}

void ImprimirValoresVetor(int *ponteiro, int dimensao) {
    for (int i = 0; i < dimensao; i++) {
        printf("[%d] = %d\n", i, *(ponteiro + i));
    }
}

// Exercicio
// Elaborar uma funcao de troca com apenas dois parametros
void Troca(int *posicao, int indice1, int indice2) {
    int auxiliar;
    auxiliar = *(posicao + indice1);
    *(posicao + indice1) = *(posicao + indice2);
    *(posicao + indice2) = auxiliar;
}

void OrdenacaoBolha(int *elemento, int dimensao) {
    int i = 1, j, limite;
    bool continuar = true;
    while ((i < dimensao) && (continuar)) {
        continuar = false;
        limite = dimensao - i;
        for (j = 0; j < limite; j++) {
            if (*(elemento + j) > *(elemento + j + 1)) {
                Troca(elemento, j, j + 1);
                continuar = true;
            }
        }
        i++;
    }
    return;
}

// Exercicio
// Elaborar e testar a varredura da direita para esquerda

int main() {
    int tamanhoVetor, vetor[TAMANHOMAXIMO];
    tamanhoVetor = LeituraDimensaoVetor();
    AssociarValoresVetor(vetor, tamanhoVetor);
    puts("Vetor original:");  //"puts()" eh semelhante a "printf()" porem coloca "\n" ao final automaticamente
    ImprimirValoresVetor(vetor, tamanhoVetor);
    OrdenacaoBolha(vetor, tamanhoVetor);
    puts("\nVetor Ordenado:");
    ImprimirValoresVetor(vetor, tamanhoVetor);
    puts("");
    printf("Pressione enter/return para finalizar...");
    fflush(stdin);
    getchar();
    return 0;
}
