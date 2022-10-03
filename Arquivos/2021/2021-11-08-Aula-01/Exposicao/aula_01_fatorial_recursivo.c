#include<stdio.h>
#include<stdlib.h>

int fatorial_nRecursivo(int n){
    int i;
    int fat_nRecursivo = 1;
    for(i=n;i>1;i--){//for descrecente
        fat_nRecursivo = fat_nRecursivo * i;
    }
    return fat_nRecursivo;
}

int fatorial_recursivo(int n){
    int fat_recursivo;
    if(n==0){
        fat_recursivo = 1;
    }
    else{
        fat_recursivo = n * fatorial_recursivo(n-1);//chamada recursiva
    }
    return fat_recursivo;
}

int main(){
    int n,i;
    int fr,fnr;
    
    printf("Digite um numero para o calculo do fatorial: ");
    scanf("%i",&n);
    
    if(n<0){
        printf("O numero deve ser inteiro nao negativo\n");
    }

    else{
        fr = fatorial_recursivo(n);
        fnr = fatorial_nRecursivo(n);
        printf("Nao recursivo fat(%i) = %i\n",n,fnr);
        printf("Recursivo fat(%i) = %i\n",n,fr);
    }
    
    getchar();
    printf("Pressione enter/return para finalizar...");
    getchar();

    return 0;
}