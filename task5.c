#include <stdio.h>
#include <stdlib.h>
float **alloc_matrix(int n, int m) {
    float **mat = malloc(n * sizeof(float *));
    if (!mat) return NULL;
    for (int i=0; i <n; ++i) {
        mat[i] = malloc(m * sizeof(float));
        if (!mat[i]) return NULL;
    }
    return mat;
}
int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);
    float **mat =alloc_matrix(n, m);
    if (!mat) return 1;
    for (int i = 0; i< n; ++i)
        for (int j = 0; j< m; ++j)
            scanf("%f", &mat[i][j]);
    for (int i=0; i <n; ++i) {
        for (int j =0; j < m; ++j) {
            printf("mat[%d][%d] addr=%p value=%g\n",
                   i, j, (void*)&mat[i][j], mat[i][j]);
        }
    }
    for (int i=0; i< n; ++i) free(mat[i]);
    free(mat);
    return 0;
}
