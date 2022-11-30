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
    int a = 1, b = 2, c = 3, index = 0, tamanhoDaSequencia = 20, *vetor, dado;
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
    File = fopen("Resultado", "wb");
    fwrite(vetor, sizeof(int), tamanhoDaSequencia, File);
    fclose(File);

    File = fopen("Resultado", "rb");
    index = 0;
    while (!feof(File)) {
        fread(&dado, sizeof(int), 1, File);
        printf("Arquivo binario [%d]: %d\n", index, dado);
        index++;
    }
}
