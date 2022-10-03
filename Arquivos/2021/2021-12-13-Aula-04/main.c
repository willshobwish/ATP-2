#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pula_linha printf("\n");
#define separador printf("     - - - - - - - -");

typedef unsigned char Byte;
typedef char StringByte[9]; //8 caracteres mais '\0'

Byte valorBit(Byte N, int posicao){
    Byte c, c1;
    c1 = pow(2,posicao);
    if((N & c1) == 0){
        c = 0;
    }
    else{
        c = 1;
    }
    return c;
}

void printBits(Byte N){
    int i;
    printf("%3i: ",N);
    for(i=7;i>=0;i--){
        if(valorBit(N,i) == 0){
            printf("0 ");
        }
        else{
            printf("1 ");
        }
    }
    pula_linha;
}

void StrByte(Byte *N, char  *s){
    Byte b;
    *N = 0;
    for(int i = 7;i>=0;i--){
        if(s[i] == '1'){
            b = pow(2,i);
            *N = *N | b;
        }
    }
}

void ByteStr(Byte N, char *s){
    int i;
    for(i=7;i>=0;i--){
        if(valorBit(N,i) == 0){
            s[i] ='0';
        }
        else{
            s[i] ='1';
        }
    }
    s[8] = '\0';
}

int main(void)
{
    Byte A,B,C;
    StringByte s8;
    A = 195;
    B = 90;

    printf("A: %3i: ",A);
    ByteStr(A,s8);
    printf("%s\n",s8);
    StrByte(&A,s8);
    printf("A:%3i S8:%s\n",A,s8);
    pula_linha;

    C = A & B;
    printBits(A);
    printf("     &\n");
    printBits(B);
    separador;
    pula_linha;
    printBits(C);
    pula_linha;

    C = A ^ B;
    printBits(A);
    printf("     ^\n");
    printBits(B);
    separador;
    pula_linha;
    printBits(C);
    pula_linha;

    C = A ^ A;
    printBits(A);
    printf("     ^\n");
    printBits(A);
    separador;
    pula_linha;
    printBits(C);
    pula_linha;

    return 0;
}
