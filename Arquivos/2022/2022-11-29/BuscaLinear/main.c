/*
  Eh gerada uma sequencia pseudoaleatoria, x[index+1] = (a*x[index] + b)%c, que eh armazenada em um vetor. A dimensao do vetor, ou seja,
  o tamanho da sequencia, eh fornecido pelo usuario. O limite para o tamanho da sequencia eh MAX.
  Os parametros a, b e c sao fixados no codigo, e a semente eh fornecida pelo usuario.
  A sequencia gerada eh gravada, todos os elementos de uma vez, em um arquivo binario.
  Do arquivo binario gravado, eh lida, elemento a elemento, a sequencia.
  Sao feitos impressoes (printf) para a conferencia do que eh gravado e lido.
  A funcao busca verifica se um valor esta armazenado em um vetor.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

FILE *File;

int main() {
    // char nomeArquivo[] = "Resultado";
    // int x0, xi, a, b, c, resultado, *array, *dado;
    // // O array pode ser criado estaticamente
    // array = (int *)calloc(MAX, sizeof(float));
    // printf("Coloque os numeros de x0,a,b e c:\n");
    // scanf("%d %d %d %d", &x0, &a, &b, &c);
    // printf("\nx0:%d\na:%d\nb:%d\nc:%d\n", x0, a, b, c);
    // if ((File = fopen("Resultado.dat", "wb")) == NULL) {
    //     printf("Erro na abertura do arquivo 'Resultado.txt'\n");
    //     exit(1);
    // } else {
    //     printf("Arquivo aberto com sucesso\n");
    // }
    // for (int xi = 1; xi <= MAX; xi++) {
    //     if (xi != 1) {
    //         resultado = (a * x0 + b) % c;
    //     } else {
    //         resultado = x0;
    //     }
    //     printf("Numero gerado na posicao %d: %d\n", xi, resultado);
    //     fwrite(resultado, sizeof(int), 1, File);
    //     // fprintf(File, "%d\n", resultado);
    //     array[xi] = resultado;
    //     x0 = resultado;
    //     printf("Array[%d]: %d\n", xi, array[xi]);
    // }
    // if (fclose(File) != 0) {
    //     printf("Erro no fechamento do arquivo\n");
    // } else {
    //     printf("Arquivo fechado com sucesso\n");
    // }
    // if ((File = fopen("Resultado", "rb")) == NULL) {
    //     printf("Erro na abertura do arquivo\n");
    // } else {
    //     while (!feof(File)) {
    //         fread(dado, sizeof(int), 1, File);
    //         printf("Dado: %d\n", dado);
    //     }
    // }
    int a = 1, b = 2, c = 3, index = 0, tamanhoDaSequencia = 20, *vetor;
    printf("Insira o tamanho da sequencia: ");
    scanf("%d", &tamanhoDaSequencia);
    fflush(stdin);
    vetor = calloc(tamanhoDaSequencia, sizeof(int));

    printf("Insira os valores de a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);
    fflush(stdin);

    printf("Insira um valor para a semente: ");
    scanf("%d", &vetor[index]);
    fflush(stdin);

    for (index = 1; index < tamanhoDaSequencia; index++) {
        vetor[index] = (vetor[index - 1] * a + b) % c;
        printf("%d\n", vetor[index]);
    }
}
