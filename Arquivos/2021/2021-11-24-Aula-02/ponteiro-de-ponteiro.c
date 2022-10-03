#include<stdio.h>
#include<stdlib.h>

int main(){
    int a, *pa, **ppa;
    printf("Endereco das variaveis:\n&a:%i\n&pa:%i\n&ppa:%i\n",&a,&pa,&ppa);
    printf("\nConteudo das variaveis:\n&a:%i\n&pa:%i\n&ppa:%i\n",a,pa,ppa);

    a = 10;
    pa = &a;
    ppa = &pa;

    printf("\nConteudo das variaveis:\na:%i\npa:%i\nppa:%i\n",a,pa,ppa);
    printf("\nConteudo das variaveis:\na:%i\n*pa:%i\n**ppa:%i\n",a,*pa,**ppa);

    printf("\nConteudo das variaveis:\na:%i\npa:%i\n*ppa:%i\n",a,pa,*ppa);

    printf("\nPressione enter/return para finalizar...");
    getchar();

    return 0;
}