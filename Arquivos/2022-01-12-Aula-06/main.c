// Codigo desenvolvido
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // No arquivo original nao ha stdbool biblioteca, ele inclui variaveis booleanos

#define TAMANHONOME 100  // 99 caracteres + '\0'

FILE *fileraw, *fileascii;

int main(void) {
    char nomeArquivoRaw[TAMANHONOME], nomeArquivoAscii[TAMANHONOME];
    char tipoPGM[3];
    char comentario[101];
    unsigned char pixel;
    int tamanhoEntradaNome, altura, largura, alturaCont, larguraCont, brilhoMaximo;
    bool erro = false;

    printf("Insira o nome do arquivo PGM em RAW: ");
    fgets(nomeArquivoRaw, TAMANHONOME, stdin);
    tamanhoEntradaNome = strlen(nomeArquivoRaw) - 1;
    nomeArquivoRaw[tamanhoEntradaNome] = '\0';

    printf("Insira o nome do arquivo PGM ASCII: ");
    fgets(nomeArquivoAscii, TAMANHONOME, stdin);        //"fgets" para obter o nome do arquivo
    tamanhoEntradaNome = strlen(nomeArquivoAscii) - 1;  //"strlen" para obter o tamanho do nome do arquivo que sera aberto
    nomeArquivoAscii[tamanhoEntradaNome] = '\0';        // define o indice do vetor para penultimo para o caractere nulo para fechar a string

    // Abertura do arquivo em RAW
    if ((fileraw = fopen(nomeArquivoRaw, "r")) == NULL) {
        printf("Erro na abertura do arquivo PGM RAW '%s'", nomeArquivoRaw);  // Caso nao consiga abrir ele retornara um erro
        exit(1);                                                             // Saida do programa
    }

    if ((fileascii = fopen(nomeArquivoAscii, "w")) == NULL) {                    // Abertura do arquivo em ASCII
        printf("Erro na abertura do arquivo PGM ASCII '%s'", nomeArquivoAscii);  // Caso nao consiga abrir ele retornara um erro
        exit(1);                                                                 // Saida do programa
    }

    // Parte do algoritmo para PGM
    fscanf(fileraw, "%s\n", tipoPGM);               // Leitura do cabecalho
    fscanf(fileraw, "%100[^\n]", comentario);       // Leitura de comentario, no maximo 100 caracteres, ate encontrar quebra de linha, formatacao de leitura
    fscanf(fileraw, "%i %i\n", &largura, &altura);  // Leitura da largura e altura
    fscanf(fileraw, "%i\n", &brilhoMaximo);         // Leitura do valor de brilho maximo de um pixel

    // Parte do algoritmo para arquivo ASCII
    fprintf(fileascii, "P2\n");                                            // Escrita do codigo P2 para PGM ASCII
    fprintf(fileascii, "Conversao de arquivo PGM para ASCII em ATP 2\n");  // Comentario opcional
    fprintf(fileascii, "%i %i\n", largura, altura);                        // Escrita da largura e altura
    fprintf(fileascii, "%i\n", brilhoMaximo);                              // Escrita do valor de brilho maximo de um pixel

    // Conversao do pixel para ASCII
    for (alturaCont = 0; alturaCont < altura; alturaCont++) {          // for para percorrer a linha
        for (larguraCont = 0; larguraCont < largura; larguraCont++) {  // for para percorrer a coluna
            fscanf(fileraw, "%c", &pixel);                             // Leitura de um pixel do arquivo PGM
            fprintf(fileascii, "%i\n", pixel);                         // Escrita em numero do pixel em arquivo ASCII
        }
    }

    // Fechamento do arquivo PGM RAW
    if (fclose(fileraw) != 0) {
        printf("Ocorreu um erro ao fechar o arquivo '%s'", nomeArquivoRaw);
        erro = true;  // caso ocorra um erro, no final o "if" ira ser verdadeiro e exibira uma mensagem
    }

    // Fechamento do arquivo PGM ASCII
    if (fclose(fileascii) != 0) {
        printf("Ocorreu um erro ao fechar o arquivo '%s'", nomeArquivoAscii);
        erro = true;  // caso ocorra um erro, no final o "if" ira ser verdadeiro e exibira uma mensagem
    }

    // Caso ocorra um ou mais erros durante o fechamento, ele mostrara essa mensagem
    // Possui uma variavel booleana
    if (erro) {
        printf("Houve erros durante o fechamento dos arquivos");
    }

    // Caso nao ocorra problemas, ele exibira essa mensagem
    else {
        printf("Conversao concluido com sucesso");
    }
}
