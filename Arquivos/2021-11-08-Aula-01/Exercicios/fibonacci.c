#include <stdio.h>
#include <stdlib.h>

int fibonacci(int entrada){
    int primeiro = 0, segundo = 1, resultado;
    for(int quantidade = 2;quantidade<entrada;quantidade++){
        resultado = primeiro + segundo;
        primeiro = segundo;
        segundo = resultado;
    }
    return resultado;
    // printf("%i", resultado);
}

int main(void){
    int entrada;
    printf("Coloque o numero de elementos para calcular: ");
    scanf("%i",&entrada);
    printf("O resultado da sequencia %i equivale a %i",entrada, fibonacci(entrada));
    // fibonacci(entrada);
    return 0;
}