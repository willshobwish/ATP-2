#include <stdio.h>
#include <stdlib.h>

int FatorialNRecursivo(int n) {
    int i;
    int FatNRecursivo = 1;
    for (i = n; i > 1; i--) {
        FatNRecursivo = FatNRecursivo * i;
    }
    return FatNRecursivo;
}

int FatorialRecursivo(int n) {
    int FatRecursivo;
    if (n == 0) {
        FatRecursivo = 1;
    } else {
        FatRecursivo = n * FatorialRecursivo(n - 1);
    }
    return FatRecursivo;
}

int FatorialRecursivoPonteiro(int *n) {
    int i;
    int FatNRecursivo = 1;
    for (i = *n; i > 1; i--) {
        FatNRecursivo = FatNRecursivo * i;
    }
    *n = FatNRecursivo;
}

int main() {
    int n, i;
    int fr, fnr, frp;

    printf("Digite um numero para o calculo do fatorial: ");
    scanf("%i", &n);

    if (n < 0) {
        printf("O numero deve ser inteiro nao negativo\n");
    }

    else {
        frp = n;
        fr = FatorialRecursivo(n);
        fnr = FatorialNRecursivo(n);
        FatorialRecursivoPonteiro(&frp);
        printf("Nao recursivo fat(%i) = %i\n", n, fnr);
        printf("Recursivo fat(%i) = %i\n", n, fr);
        printf("Nao recursivo por ponteiro: %i\n", frp);
    }

    getchar();
    printf("Pressione enter/return para finalizar...");
    getchar();

    return 0;
}
