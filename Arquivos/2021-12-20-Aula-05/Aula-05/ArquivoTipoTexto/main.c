#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Biblioteca para verificar strings

#define TAM_NOME 31

FILE *f1;

int main (void){
    char nome_arq[TAM_NOME], ch;
    int cont = 0, tam = 0;
    printf("\n Introduza o nome do arquivo: ");
    //gets(nome_arq);
    //Nao utilizaremos o "gets" pois "warning: this program uses gets(), which is unsafe" pode ocorrer problema de BUFFER OVERFLOW se mais caracteres que o maximo esperado for digitado
    //(TAM_NOME - 1 para o nome de arquivo, neste caso)
    //controlando a quantidade maxima de caracteres
    //inserir o "\0" ao final de nome_arq

    fgets(nome_arq,TAM_NOME,stdin);
    //stdin: entrada padrao seria o teclado
    tam = strlen(nome_arq) - 1;
    nome_arq[tam] = '\0';
    //para fechar a string?

    if((f1 = fopen(nome_arq,"r"))==NULL){
        printf("Erro na abertura do arquivo %s", nome_arq);
    }

    while((ch = fgetc(f1)) != EOF){
        //enquanto o arquivo possuir caracteres ele continuara lendo
        if(ch == '\n'){
            printf("\nCaracter \\n encontrado, seu codigo: %02d %02d",ch, '\n');
            //print de "ch" em decimal que deve ser igual a '\n'
            cont++;
        }
    }

    if(cont!=0){
        cont++;
        //ultima linha do arquivo EOF/CTRL-Z
        //se cont == 0, entao o arquivo esta vazio, "while" nao foi executado
    }

    printf("\n\nCaracter EOF encontrado, seu codigo: %02d %02d",ch,EOF);
    //print de "ch" em decimal que deve ser igual ao EOF
    if ( fclose(f1) != 0 )
    printf("\n Erro ao fechar o arquivo %s ",nome_arq);

    printf("\n\nO numero de linhas do arquivo %s e igual a %d",nome_arq, cont);

    fputs("\n\n\n",stdout); // stdout: saida padrao, tela do computador
    getchar(); // aguarda uma tecla ser pressionada; system("Pause") funciona no Windows
    return(0);
}