#include<stdio.h>
#include<stdlib.h>
#define size 5

int main(){
    int *v, i;

    v = (int*) calloc(size,sizeof(int));
    printf("Tamanho em bytes de um inteiro: %i\n",sizeof(int));

    for(i=(size-1);i>=0;i--){
        printf("Endereco de v[%1i]: %i\n",i,(v+i));
    }

    printf("Endereco de v: %i\n",v);

    for(i=0;i<size;i++){
        *(v+i)=(i*5)+1; //v[i]
    }
    printf("\nConteudo da posicao v: %i\n",*v); //v[0]

    for(i=0;i<size;i++){
        printf("v[%1i] = %i\n",i,v[i]);
    }
}
