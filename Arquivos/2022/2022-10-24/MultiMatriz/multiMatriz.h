#ifndef MULTIMATRIZ_H_INCLUDED
#define MULTIMATRIZ_H_INCLUDED

float **caloca(int lin, int col);
void clibera(int lin, float **pm);
void multiplica(float **A, float **B, float **C, int colAlinB, int linA, int colB);

#endif  // MULTIMATRIZ_H_INCLUDED
