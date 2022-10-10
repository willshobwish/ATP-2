#include <stdio.h>
#include <stdlib.h>

#define pula_linha printf("\n")

int main() {
    int a;
    float *pa;  // pa eh ponteiro para o tipo int

    printf("Digite um valor para a: ");
    scanf("%i", &a);
    getchar();  // limpar o buffer de entrada
    printf("\na = %i (lido com &a em scanf)\n", a);
    pula_linha;

    pa = &a;  // agora, a e *pa sao a mesma coisa
    printf("a = %i (apos pa = &a)\n", *pa);
    pula_linha;

    printf("Digite outro valor para a: ");
    scanf("%i", pa);
    getchar();
    printf("\na = %i (lido com pa em scanf)\n", a);
    printf("a = %i (acesso com *pa em printf)\n", *pa);
    pula_linha;

    printf("Endereco de a (&a): %x (hexadecimal)\n", &a);
    printf("Conteudo de pa    : %x (hexadecimal)\n", pa);
    pula_linha;

    printf("Pressione enter/return para finalizar ...");
    getchar();
    return 0;
}
