#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

short z_strlen(char *str1);
short z_cmp(char *str1, char *str2);
void z_cpy(char *str3, char *str2);
void z_cat(char *str1, char *str2);

int main(void) {
    char str1[MAX], str2[MAX], str3[MAX];
    printf("Introduza a primeira string:");
    fscanf(stdin, "%s", str1);
    printf("Introduza a segunda string:");
    fscanf(stdin, "%s", str2);
    printf("\n");
    puts("Resultado:");
    printf("%d\n", z_strlen(str1));
    printf("%d\n", z_strlen(str2));
    printf("%d\n", z_cmp(str1, str2));
    z_cpy(str3, str2);
    printf("%s\n", str3);
    z_cat(str1, str2);
    printf("%s\n", str1);
    printf("%d\n", z_strlen(str1));
    printf("Pressione qualquer tecla para finalizar");
    getchar();
    return 0;
}

short z_strlen(char *str1) {
    int aux = 0;
    while (*(str1 + aux) != '\0') {
        aux++;
    }
    return (aux);
}
short z_cmp(char *str1, char *str2) {
    int aux = 0;
    while (*(str1 + aux) != '\0' || *(str2 + aux) != '\0') {
        if (*(str1 + aux) == *(str2 + aux)) {
            aux++;
            continue;
        }
        if (*(str1 + aux) > *(str2 + aux)) {
            return (1);
        }
        if (*(str1 + aux) < *(str2 + aux)) {
            return (-1);
        }
    }
    return 0;
}
void z_cpy(char *str3, char *str2) {
    int auxi = 0, aux = z_strlen(str2);
    while (auxi < aux) {
        *(str3 + auxi) = *(str2 + auxi);
        auxi++;
    }
    return;
}
void z_cat(char *str1, char *str2) {
    int aux = 0, auxi = z_strlen(str1);
    for (; *(str2 + aux) != '\0'; aux++, auxi++) {
        *(str1 + auxi) = *(str2 + aux);
    }
    return;
}