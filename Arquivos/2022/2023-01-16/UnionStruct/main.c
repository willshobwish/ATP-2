#include <stdio.h>
#include <stdlib.h>

#define pula_2linhas printf("\n\n");

typedef union Numero { // os três campos se sobrepoem
    int inum;
    float fnum;
    double dnum;
} NUMERO;

typedef struct NroComplexo {  // Real e Imaginaria podem ser
                              // ou int, ou float, ou double
    NUMERO parteReal;
    NUMERO parteImaginaria;
} COMPLEXO;

void somaNroComplexo_double(COMPLEXO nc1, COMPLEXO nc2, COMPLEXO *nc3) {
    nc3->parteReal.dnum = nc1.parteReal.dnum + nc2.parteReal.dnum;
    nc3->parteImaginaria.dnum = nc1.parteImaginaria.dnum + nc2.parteImaginaria.dnum;
}

void formataNroComplexo_double (COMPLEXO nc, char *c) {
    sprintf(c,"%7.2lf + %7.2lfi",nc.parteReal.dnum,nc.parteImaginaria.dnum);
}

void formataNroComplexoDouble_int (COMPLEXO nc, char *c) {
    sprintf(c,"%5d + %5di",nc.parteReal.inum,nc.parteImaginaria.inum);
}

void formataNroComplexoDouble_float (COMPLEXO nc, char *c) {
    sprintf(c,"%7.2f + %7.2fi",nc.parteReal.fnum,nc.parteImaginaria.fnum);
}

// EXERCICIO: testar com inum e fnum, outros campos de union NUMERO

int main()
{
    COMPLEXO nc1,nc2,nc3;
    char ncs[10];

    printf("Tamanhos: int %d bytes   float %d bytes   double %d bytes\n",sizeof(int),sizeof(float),sizeof(double));
    printf("tamanho de union NUMERO: %d bytes  [union NUMERO tem int, float, double]\n",sizeof(NUMERO));

    pula_2linhas;

    nc1.parteReal.dnum = 10.5;
    nc1.parteImaginaria.dnum = 20.6;

    nc2.parteReal.dnum =0;
    nc2.parteImaginaria.dnum = 0;

    formataNroComplexo_double(nc1,ncs);
    printf("nc1: %s\n",ncs);

    pula_2linhas;

    formataNroComplexo_double(nc2,ncs);
    printf("nc2: %s\n",ncs);

    pula_2linhas;

    somaNroComplexo_double(nc1,nc2,&nc3);
    printf("nc3 (nc1 + nc2) %7.2lf + %7.2lfi\n",nc3.parteReal.dnum,nc3.parteImaginaria.dnum);

    nc2.parteReal.dnum =5.1;
    nc2.parteImaginaria.dnum = 4.1;

    pula_2linhas;

    formataNroComplexo_double(nc2,ncs);
    printf("nc2 (novo): %s\n",ncs);

    pula_2linhas;

    somaNroComplexo_double(nc1,nc2,&nc3);
    formataNroComplexo_double(nc3,ncs);
    printf("nc3 (nc1 + nc2): %s\n",ncs);

    pula_2linhas;

    printf("   \nLembre-se. EXERCICIO: testar com inum e fnum, outros campos de union NUMERO");
    printf("       Erro de interpretacao: parte real de nc1 %d (int) ou %f (float)\n",nc1.parteReal.inum,nc1.parteReal.fnum);
    printf("Pressione uma tecla para continuar");

    getchar();
    return 0;
}
