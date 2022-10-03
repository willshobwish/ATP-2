void fatorialRecRef(int n, int *res) {
    int aux;
    if (n == 1 || n == 0) {
        // Criterio de parada, ou seja, quando ele "resolve" todas as recursoes
        aux = 1;
    } else {
        // Funcao recursiva
        fatorialRecRef(n - 1, &aux);
        aux = n * aux;
    }
    *res = aux;
}

int fatorialRecVal(int n) {
    int r = 1;
    if (n > 0) {
        r = n * fatorialRecVal(n - 1);
    }
    return r;
}

int fatorialNRecVal(int n) {
    int i, r = 1;
    for (i = 1; i <= n; i++) {
        r = r * i;
    }
    return r;
}