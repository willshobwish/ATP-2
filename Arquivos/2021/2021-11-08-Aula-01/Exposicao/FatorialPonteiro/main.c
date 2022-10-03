#include<stdio.h>
#include<stdlib.h>

void fatproc (int, int *);

int main(){
    int resultado_fatorial, num=5;
    fatproc(num,&resultado_fatorial);
    printf("Fatorial(%i) = %i\n",num,resultado_fatorial);
    printf("Pressione enter/return para finalizar...");
    getchar();
    return 0;
}

void fatproc(int n, int *ponteiro_fatorial){//fatorial de n, armazenamento em *ponteiro_fatorial
    int i, aux=1;
    for(i=2;i<=n;i++){
        aux = aux * i;
    }
    *ponteiro_fatorial = aux;
}
