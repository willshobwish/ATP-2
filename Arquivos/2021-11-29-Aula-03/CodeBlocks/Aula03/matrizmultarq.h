#ifndef MATRIZMULTARQ_H_INCLUDED
#define MATRIZMULTARQ_H_INCLUDED

float ** caloca(int lin, int col);
void libera(int lin, float **pm);
void multiplica(float **A, float **B, float **C, int c, int l, int n);

#endif // MATRIZMULTARQ_H_INCLUDED
