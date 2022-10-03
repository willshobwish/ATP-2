#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x,y,r;
    printf("Digite dois valores x e y >= 0, para o calculo de x^y: ");
    scanf("%i %i",&x,&y);
    getchar(); // esvaziando o buffer de entrada
    if (x < 0 || y < 0) {
        printf("Os valores x e y >= 0\n");
    }
    else {
        potenciaRecRef(x,y,&r);
        printf("A Potencia [recursivo, retorna em parametro]  %i^%i = %i\n",x,y,r);
        r = potenciaRecVal(x,y);
        printf("A Potencia [recursivo, retorna valor]  %i^%i = %i\n",x,y,r);
        r = potenciaNRecVal(x,y);
        printf("A Potencia [nao recursivo, retorna valor]  %i^%i = %i\n",x,y,r);
    }

    printf("Pressione enter/return para finalizar ");
    getchar();
    return 0;
}
