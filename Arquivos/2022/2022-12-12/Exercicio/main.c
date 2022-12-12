#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 11
#define LIN 2
#define COL 10

int fatorial(int n) {
    int i, r = 1;
    for (i = 1; i <= n; i++) {
        r = r * i;
    }
    return r;
}

void printArray(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Vetor[%d]: %d\n", i, vetor[i]);
    }
}

void printNewLine() {
    printf("\n");
}

void printArrayFactorial(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Array[%d]: %d\nFatorial: %d\n\n", i, array[i], fatorial(array[i]));
    }
}
int main() {
    printf("%s\n", setlocale(LC_ALL, ""));
    int *vetor1, *vetor2, a = 1, b = 2, c = 10, *vetorResultado;
    char resultadoMatriz[] = "ResultadoMatriz.txt", ResultadoVetor[] = "ResultadoBinarioVetor1", ResultadoVetor2[] = "ResultadoBinarioVetor2", ResultadoVetor3[] = "ResultadoDoisVetores";
    vetor1 = calloc(MAX, sizeof(int));
    vetor2 = calloc(MAX, sizeof(int));
    vetorResultado = calloc(MAX, sizeof(int));
    vetor1[0] = 3;
    vetor2[0] = 3;
    for (int index = 1; index < MAX; index++) {
        vetor1[index + 1] = (a * vetor1[index] + b) % c;
    }
    printf("Vetor 1\n");
    printArray(vetor1, MAX);
    printNewLine();
    a = 2;
    b = 3;
    c = 10;
    for (int index = 1; index < MAX; index++) {
        vetor2[index + 1] = (a * vetor1[index] + b) % c;
    }
    printf("Vetor 2\n");
    printArray(vetor2, MAX);
    printNewLine();

    int **matriz;
    matriz = (int **)calloc(LIN, sizeof(int *));

    for (int j = 0; j <= COL; j++) {
        matriz[j] = (int *)calloc(1, sizeof(int));
    }

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j <= COL; j++) {
            matriz[i][j] = vetor1[j];
        }
    }

    FILE *file;
    file = fopen(resultadoMatriz, "w");
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            fprintf(file, "%d\n", matriz[i][j]);
        }
    }
    fclose(file);

    file = fopen(resultadoMatriz, "r");
    int numeroLido, index = 0;
    printf("Resultado matriz:\n");
    while (!feof(file)) {
        fscanf(file, "%d\n", &numeroLido);
        printf("Numero lido [%d]: %d\nFatorial: %d\n\n", index, numeroLido, fatorial(numeroLido));
        index++;
    }
    fclose(file);

    file = fopen(ResultadoVetor, "wb");
    fwrite(vetor1, sizeof(int), MAX, file);
    fclose(file);

    file = fopen(ResultadoVetor, "rb");
    int dado, i = 0;

    file = fopen(ResultadoVetor2, "wb");
    fwrite(vetor2, sizeof(int), MAX, file);
    fclose(file);
    file = fopen(ResultadoVetor2, "rb");
    i = 0;
    printf("\n");
    fread(vetorResultado, sizeof(int), MAX, file);
    fclose(file);

    file = fopen(ResultadoVetor3, "wb");
    fwrite(vetor1, sizeof(int), MAX, file);
    fwrite(vetor2, sizeof(int), MAX, file);
    fclose(file);

    file = fopen(ResultadoVetor3, "rb");
    fread(vetorResultado, sizeof(int), MAX, file);
    printf("Vetor 1\n");
    printArrayFactorial(vetorResultado, MAX);

    fread(vetorResultado, sizeof(int), MAX, file);
    printf("Vetor 2\n");
    printArrayFactorial(vetorResultado, MAX);
    return 0;
}
