#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, *pa, **ppa;  // declaracao/definicao de variaveis

    printf("comandos:\n");
    printf("   int a,*pa,**ppa;\n\n");
    printf("Endereco das vars: &a:%li &pa:%li &ppa:%li\n", &a, &pa, &ppa);
    printf("Conteudo das vars: a:%li pa:%li ppa:%li\n\n", a, pa, ppa);

    a = 10;     // armazenar o valor 10 na variavel a
    pa = &a;    // pegue o endereco de memoria de a e armazene em pa
    ppa = &pa;  // pegue o endereco de memoria de pa e armazene em ppa
    printf("comandos:\n");
    printf("   a = 10;\n   pa = &a;\n   ppa = &pa;\n\n");
    printf("Conteudo das vars: a:%i pa:%li ppa:%li\n\n", a, pa, ppa);

    printf("sintaxe e semantica\n");
    printf("Conteudo das vars: a:%i *pa:%i **ppa:%i\n", a, *pa, **ppa);
    printf("Conteudo das vars: &a:%li pa:%li *ppa:%li\n", &a, pa, *ppa);
    printf("Conteudo das vars: ppa:%li\n\n", ppa);

    printf("Pressione enter/return para finalizar ...");
    getchar();
    return 0;
}
