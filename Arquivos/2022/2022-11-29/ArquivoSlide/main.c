#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef enum Logico { Verdadeiro = 1,
                      Falso = 0 } logico;

int main(void) {
    logico continua;
    int tamanhoDaSequencia, *vetor, a = 2, b = 3, c = 100, i, dado;
    char nomeArquivoBinario[] = "binario.dat";
    char nomeArquivoTexto[] = "texto.txt";
    FILE *filePointer;
    do {
        printf("Insira o tamanho da sequencia: ");
        scanf("%d", &tamanhoDaSequencia);
        if (tamanhoDaSequencia <= 0 || tamanhoDaSequencia > MAX) {
            printf("Valor fora dos limites\n");
            continua = Verdadeiro;

        } else {
            continua = Falso;
            vetor = calloc(tamanhoDaSequencia, sizeof(int));
        }
    } while (continua);
    printf("Insira um valor para a semente: ");
    // Define o primeiro valor do vetor para a semente
    scanf("%d", &vetor[0]);
    for (i = 1; i < tamanhoDaSequencia; i++) {
        // Como esta comecando por 1, a semente ainda esta no indice 0
        // Pegamos o valor anterior
        vetor[i] = (vetor[i - 1] * a + b) % c;
    }
    filePointer = fopen(nomeArquivoTexto, "w");
    for (i = 0; i < tamanhoDaSequencia; i++) {
        printf("=> vetor[%d] = %d\n", i, vetor[i]);
        fprintf(filePointer, "%d\n", vetor[i]);
    }
    fclose(filePointer);
    // fopen precisa ter o parametro "wb" porque esta abrindo um arquivo do tipo binario
    // utiliza-se somente o "w" quando eh arquivo do tipo texto
    filePointer = fopen(nomeArquivoBinario, "wb");
    // fwrite(ponteiro da variavel, tamanho dos dados a serem gravados, quantidade que ira gravar, ponteiro do arquivo)
    // Neste caso sera gravado todo o vetor, portanto, precisams indicar qual eh o seu tamanho
    fwrite(vetor, sizeof(int), tamanhoDaSequencia, filePointer);
    // Fechamento do arquivo binario
    fclose(filePointer);

    filePointer = fopen(nomeArquivoBinario, "rb");
    // fread(ponteiro da variavel, tamanho dos dados a serem lidos, quantidade que ira ler, ponteiro do arquivo)
    // Neste caso, o bloco de informacoes lido sera armazenado na variavel (precisamos indicar com o endereco da variavel), porem lemos somente um bloco por vez
    fread(&dado, sizeof(int), 1, filePointer);
    i = 0;
    // Enquanto nao estivermos no final do arquivo, ele continuara lendo
    while (!feof(filePointer)) {
        printf("=> vetor[%d] = %d e lido do binario[%d] = %d sao iguais\n", i, vetor[i], i, dado);
        fread(&dado, sizeof(int), 1, filePointer);
        i++;
    }
    printf("=> Foram lidos %d elementos\nIndices: %d e %d\n", i, 0, (i - 1));
    fclose(filePointer);
    free(vetor);
    getchar();
}