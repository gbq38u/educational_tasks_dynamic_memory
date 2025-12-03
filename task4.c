#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);
    //Вариант 1: 
    int **a = malloc(n * sizeof(int *));
    int *data = malloc(n * m * sizeof(int));
    for (int i =0; i <n; ++i)
        a[i] = data + i * m;


    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);

    printf("Вариант 1:\n");
    for (int i = 0; i <n; ++i) {
        for (int j = 0; j <m; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    free(data);
    free(a);





    // вариант 2:
    int **b = malloc(n *sizeof(int *));
    for (int i = 0; i < n; ++i)
        b[i] = malloc(m * sizeof(int));

    for (int i = 0; i <n; ++i)
        for (int j =0; j<m; ++j)
            scanf("%d", &b[i][j]);
    printf("Вариант 2:\n");
    for (int i = 0; i <n; ++i) {
        for (int j =0; j < m; ++j)
            printf("%d ", b[i][j]);
        printf("\n");
    }
    for (int i = 0; i < n; ++i) free(b[i]);
    free(b);

    return 0;
}
