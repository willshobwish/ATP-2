#include <stdio.h>
#include <stdlib.h>

int PowRecursivo(int base, int elevado) {
    if (elevado != 0) {
        return (base * pow(base, elevado - 1));
    } else {
        return 1;
    }
}

int pownRecursivo(int base, int elevado) {
    int aux = base;

    for (int i = 1; i < elevado; i++) {
        aux = aux * base;
    }
    if (elevado == 0) {
        aux = 1;
    }
    return aux;
}
int main() {
    int base = 2, elevado = 3, resultado, resultado2;
    resultado = pow(base, elevado);
    resultado2 = pownRecursivo(base, elevado);
    printf("Potencia Recursiva: %d\n", resultado);
    printf("Potencia nao recursiva: %d", resultado2);
}
