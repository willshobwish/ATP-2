#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main(void) {
    char str1[MAX], str2[MAX], str3[MAX];
    printf("Introduza a primeira string:");
    fscanf(stdin, "%s", str1);
    printf("Introduza a segunda string:");
    fscanf(stdin, "%s", str2);
    printf("\n");
    puts("Resultado:");
    printf("%d\n", strlen(str1));
    printf("%d\n", strlen(str2));
    printf("%d\n", strcmp(str1, str2));
    strcpy(str3, str2);
    printf("%s\n", str3);
    strcat(str1, str2);
    printf("%s\n", str1);
    printf("%d\n", strlen(str1));
    printf("Pressione qualquer tecla para finalizar");
    getchar();
    return 0;
}
