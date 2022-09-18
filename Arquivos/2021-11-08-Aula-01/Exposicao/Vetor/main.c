#include <stdio.h>
#include <stdlib.h>

int main(){
    float v1[]={10.0,25.0,30.6}, v2[3];
    int v3[3], i;

    v3[0]=v3[1]=v3[2]=100;

    for(i=0;i<3;i++){
        *(v2+i)=v1[i] * 5; //v2[i]=v1[i]*5
    }

    for(i=0;i<3;i++){
        printf("v1[%2u] = %06.2f",i,v1[i]);
        printf(" v2[%2u] = %06.2f",i,v2[i]);
        printf(" v3[%2u] = %03d\n",i,v3[i]);
    }

    printf("Pressione enter/return para finalizar...");
    getchar();
    return 0;
}
