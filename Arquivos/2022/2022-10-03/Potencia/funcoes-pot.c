void potenciaRecRef(int x, int y, int *r) {
    int aux = 1;
    if (y != 0) {
        for (int i = 0; i < y; i++) {
            aux = aux * x;
        }
        *r = aux;
    } else {
        *r = 1;
    }
}

int potenciaRecVal(int x, int y) {
    if (y != 0) {
        return (x * potenciaRecVal(x, y - 1));
    } else {
        return 1;
    }
}

int potenciaNRecVal(int x, int y) {
    int aux = 1;
    if (y != 0) {
        for (int i = 0; i < y; i++) {
            aux = aux * x;
        }
        return aux;
    } else {
        return 1;
    }
}
