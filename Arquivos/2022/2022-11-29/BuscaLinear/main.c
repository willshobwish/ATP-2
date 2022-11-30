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
typedef enum Logico { verdadeiro = 1,
                      falso = 0 } logico;
FILE *File;

int main() {
    int a = 1, b = 2, c = 3, index = 0, tamanhoDaSequencia = 20, *vetor, dado;
    printf("Insira o tamanho da sequencia: ");
    scanf("%d", &tamanhoDaSequencia);
    // Acredito que nao seja necessario o fflush, porem coloquei por via das duvidas
    fflush(stdin);

    // Precisa alocar o vetor na memoria antes de utilizar ou alocar em algum indice do vetor
    vetor = calloc(tamanhoDaSequencia, sizeof(int));

    printf("Insira os valores de a, b, c: ");
    // 2, 3 e 100 sao bons valores de a, b e c
    scanf("%d %d %d", &a, &b, &c);
    fflush(stdin);

    printf("Insira um valor para a semente: ");
    scanf("%d", &vetor[index]);
    fflush(stdin);

    for (index = 1; index < tamanhoDaSequencia; index++) {
        vetor[index] = (vetor[index - 1] * a + b) % c;
        printf("%d\n", vetor[index]);
    }
    // Abrimos o arquivo de formato binario para escrever o conteudo
    File = fopen("Resultado", "wb");
    // fwrite(endereco do conteudo a ser gravado, tamanho do tipo de dado do conteudo, a quantidade de conteudo, ponteiro do arquivo)
    fwrite(vetor, sizeof(int), tamanhoDaSequencia, File);
    fclose(File);
    // Abrimos o arquivo de formato binario em modo de leitura
    File = fopen("Resultado", "rb");
    index = 0;
    // Enquanto nao chegou no final do arquivo, continuara sendo lido o conteudo
    while (!feof(File)) {
        // fread (endereco de destino do dado lido, tamanho do tipo de dado lido, quantidade de dados, ponteiro de arquivo)
        fread(&dado, sizeof(int), 1, File);
        printf("Arquivo binario [%d]: %d\n", index, dado);
        index++;
    }
    busca(vetor, tamanhoDaSequencia);
}

void busca(int *x, int n) {
    int dado, i;
    logico encontrou;
    printf("Digite um valor para realizar a busca no vetor: ");
    scanf("%d", &dado);
    while (dado != 0) {
        encontrou = falso;
        i = 0;
        while (i < n && !encontrou) {
            // while (i < n) {
            if (x[i] == dado) {
                encontrou = verdadeiro;

            } else {
                i++;
            }
        }
        if (encontrou) {
            printf("Valor %d encontrado na posicao %d\n", dado, i);

        } else {
            printf("Valor %d nao encontrado\n", dado);
        }
        printf("Digite um outro valor para encontrar no vetor (digite 0 para encerrar): ");
        scanf("%d", &dado);
    }
}