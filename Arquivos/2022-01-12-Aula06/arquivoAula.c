//Codigo fonte exibido em aula
//Conversao de PGM raw para PGM ascii

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 51  // 50 caracteres + '\0'

FILE *fraw, *fascii;

int main(void) {
 char nome_raw[TAM_NOME], nome_ascii[TAM_NOME];
 char tipoPGM[3]; // P2: ascii P5: raw; 2 caracteres '\0'
 char comentario[101]; // linha de comentario no arquivo, ate 100 caracteres + '\0'
 unsigned char pixel; // variavel para o pixel em PGM raw, 1 byte (unsigned char: 0..255, sem sinal)
 int tam,alt,larg,altura,largura,brilhomax; // veja o uso das variaveis no codigo

 printf("\n Introduza o nome do arquivo PGM raw: ");
 fgets(nome_raw,TAM_NOME,stdin); // stdin: entrada padrao: teclado
 tam = strlen(nome_raw) - 1; // primeira posicao apos o ultimo caracter digitado
 nome_raw[tam] = '\0'; // final de string

 printf("\n Introduza o nome do arquivo PGM ascii: ");
 fgets(nome_ascii,TAM_NOME,stdin); // stdin: entrada padrao: teclado
 tam = strlen(nome_ascii) - 1; // primeira posicao apos o ultimo caracter digitado
 nome_ascii[tam] = '\0'; // final de string

 if ( (fraw=fopen(nome_raw,"r")) == NULL ) { // abertura de arquivo texto para leitura
    printf("Erro na abertura do arquivo PGM raw %s", nome_raw);
    exit(1);
    }

 if ( ( fascii=fopen(nome_ascii,"w") ) == NULL ) { // abertura de arquivo texto para escrita
    printf("Erro na abertura do arquivo PGM ascii %s", nome_ascii);
    exit(1);
    }

  // leitura das 4 linhas do cabecalho do PGM raw, como do exemplo de aula
  // linha de comentario eh opcional
  fscanf(fraw,"%s\n",tipoPGM); // lendo P5
  fscanf(fraw,"%100[^\n]",comentario); // lendo a linha de comentarios ate encontrar '\n', maximo de 100 caracteres
  fscanf(fraw,"%i %i\n",&largura,&altura); // lendo largura (nro de colunas) e altura (nro de linhas)
  fscanf(fraw,"%i\n",&brilhomax); // lendo o valor de brilho maximo para um pixel

  // gerando o cabecalho do arquivo PGM ascii
  fprintf(fascii,"P2\n"); // escrita direta do codigo P2 para PGM ascii
  fprintf(fascii,"# Arquivo convertido em ATP II\n"); // insercao de comentario, opcional
  fprintf(fascii,"%i %i\n",largura,altura); // copiando a largura e a altura
  fprintf(fascii,"%i\n",brilhomax); // copiando o valor de brilho maximo para um pixel

  // convertendo o pixel de raw (byte, binario) para ascii (texto)
  for (alt=0;alt<altura;alt++) { // percorrendo as linhas
    for (larg=0;larg<largura;larg++) { // percorrendo as colunas
        fscanf(fraw,"%c",&pixel); // lendo um byte (caracter), 1 pixel em PGM raw
        fprintf(fascii,"%i\n",pixel); // escrita com conversao para texto "legivel", 1 pixel por linha
    }
  }

  if ( fclose(fraw) != 0 )
   printf("\n Erro ao fechar o arquivo %s ",nome_raw);

  if ( fclose(fascii) != 0 )
   printf("\n Erro ao fechar o arquivo %s ",nome_ascii);

 printf("\nO arquivo RAW %s foi convertido com sucesso para ASCII %s !!! ",nome_raw,nome_ascii);

 fputs("\n\n\nPressione uma tecla para finalizar",stdout);
 getchar();
 return(0);

}
