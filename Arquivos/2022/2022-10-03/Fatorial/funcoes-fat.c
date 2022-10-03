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