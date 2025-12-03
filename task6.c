#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);
    int **a = malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i)
        a[i] = malloc(m * sizeof(int));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);

    int **b = NULL;
    int good_rows = 0;
    for (int i = 0; i < n; ++i) {
        int ok = 1;
        for (int j = 0; j < m; ++j)
            if (a[i][j] < 0) { ok = 0; break; }

        if (ok) {
            b = realloc(b, (good_rows + 1) * sizeof(int *));
            b[good_rows] = malloc(m * sizeof(int));
            for (int j = 0; j < m; ++j)
                b[good_rows][j] = a[i][j];
            good_rows++;
        }
    }
    printf("Новая матрица (%d x %d):\n", good_rows, m);
    for (int i = 0; i < good_rows; ++i) {
        for (int j = 0; j < m; ++j)
            printf("%d ", b[i][j]);
        printf("\n");
    }
    for (int i = 0; i < n; ++i) free(a[i]);
    free(a);
    for (int i = 0; i < good_rows; ++i) free(b[i]);
    free(b);
    return 0;
}
