#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 20
#define MAXFILENAMESIZE 50

FILE *File;

int main() {
    int x0, xi, a, b, c, resultado;
    printf("Coloque os numeros de x0,a,b e c:\n");
    scanf("%d %d %d %d", &x0, &a, &b, &c);
    printf("\nx0:%d\na:%d\nb:%d\nc:%d\n", x0, a, b, c);

    // printf("Coloque o nome do arquivo para gravar os numeros: ");
    // fflush(stdin);
    // fgets(FileName, MAXFILENAMESIZE, stdin);
    // FileNameSize = strlen(FileName) - 1;
    // FileName[FileNameSize] = '\0';

    if ((File = fopen("Resultado.txt", "w")) == NULL) {
        printf("Erro na abertura do arquivo 'Resultado.txt'\n");
        exit(1);
    } else {
        printf("Arquivo aberto com sucesso\n");
    }
    for (int xi = 1; xi <= MAX; xi++) {
        if (xi != 1) {
            resultado = (a * x0 + b) % c;
        } else {
            resultado = x0;
        }
        printf("Numero gerado na posicao %d: %d\n", xi, resultado);
        fprintf(File, "Número gerado na posição %d: %d\n", xi, resultado);
        x0 = resultado;
    }
    if (fclose(File) != 0) {
        printf("Erro no fechamento do arquivo: %s\n", File);
    } else {
        printf("Arquivo fechado com sucesso\n");
    }
}
