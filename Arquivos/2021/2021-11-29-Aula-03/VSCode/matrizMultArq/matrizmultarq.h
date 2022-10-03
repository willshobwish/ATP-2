#ifndef MATRIZMULTARQ_H_INCLUDED
#define MATRIZMULTARQ_H_INCLUDED

float ** caloca(int linhas, int colunas);
void libera(int linhas, float **matriz);
void multiplica(float **matrizA, float **matrizB, float **matrizC, int c, int l, int n);

#endif