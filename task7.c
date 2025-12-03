#include <stdio.h>
#include <stdlib.h>

int all_zero(int *row, int m) {
    for (int j = 0; j < m; ++j)
        if (row[j] != 0) return 0;
    return 1;
}

int all_distinct(int *row, int m) {
    for (int i = 0;  i< m; ++i)
        for (int j = i + 1; j < m; ++j)
            if (row[i] == row[j]) return 0;
    return 1;
}
int all_even(int *row, int m) {
    for (int j=0; j < m; ++j)
        if (row[j] % 2 != 0) return 0;
    return 1;
}

int is_monotonic(int *row, int m) {
    int nondec = 1, noninc = 1;
    for (int j= 1; j <m; ++j) {
        if (row[j]< row[j-1]) nondec=0;
        if (row[j] >row[j-1]) noninc =0;
    }
    return nondec || noninc;
}
int is_palindrome(int *row, int m) {
    for (int j = 0; j < m /2; ++j)
        if (row[j] != row[m-1-j]) return 0;
    return 1;
}
int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);

    int **a = malloc(n * sizeof(int *));
    for (int i =0; i < n; ++i)
        a[i] = malloc(m * sizeof(int));
    for (int i=0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);
    int **b = malloc(n * sizeof(int *));
    for (int i = 0; i<n; ++i)
        b[i] = calloc(5, sizeof(int));
    for (int i = 0; i < n; ++i) {
        b[i][0] = all_zero(a[i], m);
        b[i][1] = all_distinct(a[i], m);
        b[i][2] = all_even(a[i], m);
        b[i][3] = is_monotonic(a[i], m);
        b[i][4] = is_palindrome(a[i], m);
    }
    printf("Матрица b (n x 5):\n");
    for (int i =0; i< n; ++i) {
        for (int j= 0; j <5; ++j)
            printf("%d ", b[i][j]);
        printf("\n");
    }
    for (int i=0; i< n; ++i) {
        free(a[i]);
        free(b[i]);
    }
    free(a);
    free(b);
    return 0;
}
