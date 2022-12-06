#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define mensagem printf("\nPressione return/enter para finalizar ... ")
#define pula_linha printf("\n")

typedef enum Logico { Verdadeiro = 1,
                      Falso = 0 } logico;

int busca_bin(int *x, int n, int item, int ini, int fim) {
    // x: vetor, n: dimensao do vetor, item: item a ser localizado
    // ini e fim: verificar o vetor entre os indices ini e fim
    int meio, posicao;
    if (ini <= fim) {
        meio = (ini + fim) / 2;  // divisao inteira, isto eh, a parte fracionaria nao eh considerada
        printf("\nInicio: %d Meio: %d Fim: %d", ini, meio, fim);
        if (item == x[meio]) {
            posicao = meio;
        } else {
            if (item > x[meio]) {
                posicao = busca_bin(x, n, item, meio + 1, fim);
            } else {
                posicao = busca_bin(x, n, item, ini, meio - 1);
            }
        }
    } else {
        posicao = -1;
    }
    return posicao;
}

void pesquisa(int *x, int n) {
    int dado, pos;
    printf("Digite um valor para buscar no vetor: (0 para finalizar a busca) ");
    scanf("%d", &dado);
    while (dado != 0) {
        pos = busca_bin(x, n, dado, 0, n - 1);

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
    int n, *x, i;

    do {
        printf("Insira a dimensao do vetor: ");
        scanf("%d", &n);
        if (n <= 0 || n > MAX) {
            printf("Valor fora dos limites\n");
            continua = Verdadeiro;
        } else {
            continua = Falso;
            x = calloc(n, sizeof(int));
        }
    } while (continua);

    pula_linha;
    for (i = 0; i < n; i++) {
        x[i] = i * 2 + 2;
        printf("x[%3d] = %3d\n", i, x[i]);
    }

    pula_linha;
    pesquisa(x, n);

    free(x);

    getchar();
    mensagem;
    getchar();
    return 0;
}