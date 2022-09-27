#include <stdio.h>
#include <stdlib.h>

int PotenciaRecursivo(int base, int elevado) {
    if (elevado != 0) {
        return (base * pow(base, elevado - 1));
    } else {
        return 1;
    }
}

int PotenciaNRecursivo(int base, int elevado) {
    int aux = base;
    for (int i = 1; i < elevado; i++) {
        aux = aux * base;
    }
    if (elevado == 0) {
        aux = 1;
    }
    return aux;
}

void PotenciaRecursivaPonteiro(int *base, int *elevado) {
    int aux = *base;
    for (int i = 1; i < *elevado; i++) {
        *base = aux * *base;
    }
    if (*elevado == 0) {
        aux = 1;
    }
}
int main() {
    int base = 2, elevado = 3, resultado, resultado2;
    resultado = PotenciaRecursivo(base, elevado);
    resultado2 = PotenciaNRecursivo(base, elevado);
    PotenciaRecursivaPonteiro(&base, &elevado);
    printf("Potencia Recursiva: %d\n", resultado);
    printf("Potencia nao recursiva: %d\n", resultado2);
    printf("Potencia recursiva por ponteiro: %d", base);
}
