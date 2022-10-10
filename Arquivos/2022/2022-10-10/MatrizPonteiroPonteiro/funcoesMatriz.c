float **caloca(int lin, int col) {
    int i;
    float **pm;
    pm = (float **)calloc(lin, sizeof(float *));
    for (i = 0; i < lin; i++) {
        pm[i] = (float *)calloc(col, sizeof(float));
    }
    return (pm);
}

void clibera(int lin, float **pm) {
    int i;
    for (i = 0; i < lin; i++) {
        free(pm[i]);
    }
    return (pm);
}

void somaMatrizes(float **m1, float **m2, float **m3, int l, int c) {
    int i, j;
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void multiplicaMatrizes(int lin, int col, float **m1,float **m2,float **m3){
if(lin==col){
    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            **m3[i][j] = **m2[i][j] *
        }
    }
}
}
