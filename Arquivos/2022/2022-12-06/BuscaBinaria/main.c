#include <stdio.h>
#include <stdlib.h>

#define MAvetor 100
#define mensagem printf("\nPressione return/enter para finalizar ... ")
#define pula_linha printf("\n")

typedef enum Logico { Verdadeiro = 1,
                      Falso = 0 } logico;

int busca_bin(int *vetor, int n, int item, int ini, int fim) {
    // vetor: vetor, n: dimensao do vetor, item: item a ser localizado
    // ini e fim: verificar o vetor entre os indices ini e fim
    int meio, posicao;
    if (ini <= fim) {
        meio = (ini + fim) / 2;  // divisao inteira, isto eh, a parte fracionaria nao eh considerada
        printf("\nInicio: %d Meio: %d Fim: %d", ini, meio, fim);
        if (item == vetor[meio]) {
            posicao = meio;
        } else {
            if (item > vetor[meio]) {
                posicao = busca_bin(vetor, n, item, meio + 1, fim);
            } else {
                posicao = busca_bin(vetor, n, item, ini, meio - 1);
            }
        }
    } else {
        posicao = -1;
    }
    return posicao;
}

void pesquisa(int *vetor, int n) {
    int dado, pos;
    printf("Digite um valor para buscar no vetor: (0 para finalizar a busca) ");
    scanf("%d", &dado);
    while (dado != 0) {
        pos = busca_bin(vetor, n, dado, 0, n - 1);

        if (pos != -1) {
            printf("Valor %d encontrado na posicao %d\n", dado, pos);
        } else {
            printf("Valor %d nao encontrado\n", dado);
        }
        printf("Digite um valor para buscar no vetor: (0 para finalizar a busca) ");
        scanf("%d", &dado);
    }
}

int main() {
    logico continua;
    int n, *vetor, i;

    do {
        printf("Insira a dimensao do vetor: ");
        scanf("%d", &n);
        if (n <= 0 || n > MAvetor) {
            printf("Valor fora dos limites\n");
            continua = Verdadeiro;
        } else {
            continua = Falso;
            vetor = calloc(n, sizeof(int));
        }
    } while (continua);

    pula_linha;
    for (i = 0; i < n; i++) {
        vetor[i] = i * 2 + 2;
        printf("vetor[%3d] = %3d\n", i, vetor[i]);
    }

    pula_linha;
    pesquisa(vetor, n);

    free(vetor);

    getchar();
    mensagem;
    getchar();
    return 0;
}