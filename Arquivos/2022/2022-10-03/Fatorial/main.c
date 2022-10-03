#include <stdio.h>
#include <stdlib.h>
#include "funcoes-fat.c"

int main() {
    int n, r;
    printf("Digite um numero, 0 <= n <= 19, para o calculo de seu Fatorial: ");
    scanf("%i", &n);
    getchar();  // limpando o buffer de entrada
    if (n < 0 || n > 19) {
        printf("O numero deve ser 0 <= n <= 19\n");
    } else {
        fatorialRecRef(n, &r);
        printf("O Fatorial [recursivo, retorna em parametro] de %i eh %i\n", n, r);
        r = fatorialRecVal(n);
        printf("O Fatorial [recursivo, retorna valor] de %i eh %i\n", n, r);
        r = fatorialNRecVal(n);
        printf("O Fatorial [nao recursivo, retorna valor] de %i eh %i\n", n, r);
    }

    printf("Pressione enter/return para finalizar ");
    getchar();
    return 0;
}
