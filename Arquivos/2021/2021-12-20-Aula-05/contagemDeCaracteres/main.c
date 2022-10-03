#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Biblioteca para classificacao de caracteres ASCII

#define TAMANHONOME 31

int contaCaracteres(char *nome, char Chara){
    // Conta as ocorrencias do caractere "ch" no arquivo "nome"
    FILE *file;
    int contagem = 0;
    char ch, ch1 = toupper(Chara);
    // Toupper eh uma funcao da biblioteca "ctype.h" que converte o caractere para maiuscula
    if((file = fopen(nome,"r")) == NULL){
        printf("Erro na abertura do arquivo %s", nome);
        exit(1);
    }
    printf("O que esta escrito no arquivo: ");
    while((ch = fgetc(file)) != EOF){
        printf("%c", ch);
        ch = toupper(ch);
        if(ch == ch1){
            contagem++;
        }
    }
    printf("\n");
    fclose(file);
    return(contagem);
}

int main(void){
    char nomeArquivo[TAMANHONOME], ch;
    int contagem = 0, tamanho;
    printf("Introduza o nome do arquivo: ");
    fgets(nomeArquivo,TAMANHONOME,stdin);
    tamanho = strlen(nomeArquivo) - 1;
    nomeArquivo[tamanho] = '\0';

    printf("Informe o caractere que deseja contar (nao ha diferencas entre maiusculas e minusculas): ");
    ch = fgetc(stdin);
    contagem = contaCaracteres(nomeArquivo, ch);

    printf("O numero de ocorrencias dessa letra '%c' no arquivo '%s' eh igual a: %d\n\n",ch,nomeArquivo,contagem);
    getchar();
    return 0;
}
