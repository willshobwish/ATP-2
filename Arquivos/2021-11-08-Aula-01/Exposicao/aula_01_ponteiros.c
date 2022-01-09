#include <stdio.h>
#include <stdlib.h>

int main(){
    int a;
    int *pa;
    pa = &a;

    printf("Digite um valor para a: ");
    scanf("%i",&a);
    getchar();
    printf("a = %i\n",a);

    printf("Endereco de memoria: %i\n",&a);
    printf("Valor do ponteiro: %i\n",*pa);

    printf("Digite outro valor: ");
    scanf("%i",pa);
    getchar();
    
    printf("a = %i\n",a);
    printf("a = %i\n",*pa);

    printf("Pressione enter/return para finalizar...");
    getchar();
    return 0;
}