#include <stdio.h>
#include <stdlib.h>

#define pula_linha printf("\n")

int main()
{
    float v1[] = {10.0,20.5,30.6}, v2[3];
    int *v3,i;

    //alocacao dinamica
    v3 = (int *) calloc(3,sizeof(int)); // zera os valores
    //v3 = (int *) malloc(3 * sizeof(int));
    v3[0]=v3[1]=v3[2]=100;

    for(i=0;i<3;i++) {
        *(v2 + i) = v1[i] * 5; // v2[i] = v1[i] * 5
    }

    for(i=0;i<3;i++) {
        printf("v1[%2u] = %06.2f ",i,v1[i]);
        printf("v2[%2u] = %06.2f ",i,v2[i]);
        printf("v3[%2u] = %03d\n",i,v3[i]);
        pula_linha;
    }
    pula_linha;

    printf("Enderecos de memoria\n");
    printf("  v1   : %li (endereco de v1)\n",v1);
    printf("  v1[0]: %li (endereco de v1[0])\n",&v1[0]);
    printf("  v1[1]: %li (endereco de v1[1])\n",&v1[1]);
    printf("  v2   : %li (endereco de v2)\n",v2);
    pula_linha;
    printf("  v3[0] e v3[1]: %li %li\n",&v3[0],&v3[1]);
    pula_linha;
    printf("Tamanhos de float e int: %i %i\n",sizeof(float),sizeof(int));
    pula_linha;

    free(v3); // liberacao do espaco alocado dinamicamente

    printf("Pressione enter/return para finalizar ...");
    getchar();
    return 0;
}
