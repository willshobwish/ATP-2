#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHONOMEARQUIVO 50  // define o tamanho maximo do nome do arquivo

FILE *arquivoOrigem, *arquivoDestino;  // define os ponteiros dos arquivos que serao abertos

int main(void) {
    char nomeArquivoOrigem[TAMANHONOMEARQUIVO];   // variavel do tipo char em string para definir o nome do arquivo do tipo texto para a origem
    char nomeArquivoDestino[TAMANHONOMEARQUIVO];  // variavel do tipo char em string para definir o nome do arquivo do tipo texto para o destino
    char ch;                                      // variavel do tipo char armazenar temporariamente os caracteres lidos
    int tamanho;                                  // tamanho do nome do arquivo do tipo texto
    bool fechamento = true;                       // sinal para definir se houve erros durante o fechamento

    printf("Insira o nome do arquivo de origem: ");
    fgets(nomeArquivoOrigem, TAMANHONOMEARQUIVO, stdin);
    tamanho = strlen(nomeArquivoOrigem) - 1;
    nomeArquivoOrigem[tamanho] = '\0';

    printf("Insira o nome do arquivo de destino: ");
    fgets(nomeArquivoDestino, TAMANHONOMEARQUIVO, stdin);
    tamanho = strlen(nomeArquivoDestino) - 1;
    nomeArquivoDestino[tamanho] = '\0';

    if ((arquivoOrigem = fopen(nomeArquivoOrigem, "r")) == NULL) {
        printf("Erro na abertura do arquivo de origem\nNome: '%s'", nomeArquivoOrigem);
        exit(1);
    }

    if ((arquivoDestino = fopen(nomeArquivoDestino, "w")) == NULL) {
        printf("Erro na abertura do arquivo de destino\nNome: '%s'", nomeArquivoDestino);
        exit(1);
    }

    while ((ch = fgetc(arquivoOrigem)) != EOF) {
        fputc(ch, arquivoDestino);
    }

    if (fclose(arquivoOrigem) != 0) {
        printf("Erro ao fechar o arquivo '%s'", nomeArquivoOrigem);
        fechamento = false;
    }

    if (fclose(arquivoDestino) != 0) {
        printf("Erro ao fehcar o arquivo '%s'", nomeArquivoDestino);
        fechamento = false;
    }

    if (fechamento) {
        printf("O arquivo '%s' foi copiado com exito para '%s'\n", nomeArquivoOrigem, nomeArquivoDestino);
    }

    printf("Pressione qualquer tecla para finalizar");

    getchar();
    return 0;
}
