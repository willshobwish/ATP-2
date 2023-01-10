#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXALUNOS 100

typedef char str50[51];
typedef enum Mes { janeiro = 1,
                   fevereiro,
                   marco,
                   abril,
                   junho,
                   julho,
                   agosto,
                   setembro,
                   outubro,
                   dezembro } MES;

typedef struct data {
    int dia;
    MES mes;
    int ano;
} DATA;

typedef struct Notas {
    float notaProva[5];
    float notaTrabalho[6];
    float mediaFinal;

} NOTAS;

typedef struct DadosPessoais {
    str50 nome;
    DATA dataNascimento;
    NOTAS notas;
} DADOSPESSOAIS;

float calculaMedia(DADOSPESSOAIS *dado, int quantidadeTrabalho, int quantidadeProvas) {
    float somaTrabalhos, somaProvas, mediaTrabalho, mediaProva, mediaFinal;
    for (int i = 0; i < quantidadeTrabalho; i++) {
        somaTrabalhos += dado->notas.notaTrabalho[i];
    }
    for (int i = 0; i < quantidadeProvas; i++) {
        somaProvas += dado->notas.notaProva[i];
    }
    mediaTrabalho = somaTrabalhos / quantidadeTrabalho;
    printf("Media dos trabalhos: %.2f\n", mediaTrabalho);
    mediaProva = somaProvas / quantidadeProvas;
    printf("Media das provas: %.2f\n", mediaProva);
    mediaFinal = (0.8 * mediaTrabalho) + (0.2 * mediaProva);
    return mediaFinal;
}

int main() {
    DADOSPESSOAIS alunos[MAXALUNOS];
    DADOSPESSOAIS aluno01, *ponteiro;
    MES m1 = fevereiro;
    FILE *file;
    file = fopen("teste.txt", "r");
    float numeroLido;
    int index = 0;
    MES mesNome;
    while (!feof(file)) {
        fscanf(file, "%s\n", alunos[index].nome);
        printf("Nome do aluno: %s\n", alunos[index].nome);
        fscanf(file, "%d\n", &(alunos[index].dataNascimento.dia));
        // fscanf(file, "%s\n", alunos[index].dataNascimento.mes);
        // fscanf(file, "%s\n", &mesNome);
        // alunos[index].dataNascimento.mes = mesNome;
        fscanf(file, "%d\n", alunos[index].dataNascimento.mes);
        fscanf(file, "%d\n", &(alunos[index].dataNascimento.ano));
        printf("Data de nascimento: %d de %s de %d\n", alunos[index].dataNascimento.dia, alunos[index].dataNascimento.mes, alunos[index].dataNascimento.ano);
        for (int i = 0; i < 6; i++) {
            fscanf(file, "%f\n", &alunos[index].notas.notaTrabalho[i]);
            printf("Nota do trabalho[%d]:%.2f\n", i, alunos[index].notas.notaTrabalho[i]);
        }
        for (int i = 0; i < 5; i++) {
            fscanf(file, "%f\n", &alunos[index].notas.notaProva[i]);
            printf("Nota da prova[%d]:%.2f\n", i, alunos[index].notas.notaProva[i]);
        }
        index++;
    }
    fclose(file);
    ponteiro = &alunos[0];
    float media = calculaMedia(&alunos[0], 6, 5);
    printf("Media: %.2f", media);
    return 0;
}
