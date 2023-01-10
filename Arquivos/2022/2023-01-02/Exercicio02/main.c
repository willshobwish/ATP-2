#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    char string1[MAX] = "abacate", string2[MAX] = "abacate2";
    printf("%d", z_strlenstr(string1, string2));
    return 0;
}

int z_strlenstr(char *str1, char *str2) {
    int aux1 = 0, aux2 = 0;
    while (*(str1 + aux1) != '\0') {
        aux1++;
    }
    while (*(str2 + aux2) != '\0') {
        aux2++;
    }
    if (aux1 == aux2) {
        return 0;
    } else if (aux1 > aux2) {
        return -1;
    } else if (aux1 < aux2) {
        return 1;
    }
}