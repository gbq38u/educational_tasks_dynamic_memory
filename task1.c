#include <stdio.h>
#include <stdlib.h>

int *merge(const int *a, int n, const int *b, int m, int *res_n) {
    int *c = (int *)malloc((n + m) * sizeof(int));
    if (!c) return NULL;
    int i = 0, j =0, k = 0;
    while (i <n && j<m) {
        if (a[i] <=b[j])
            c[k++] = a[i++];
        else
            c[k++]= b[j++];
    }
    while (i < n)c[k++] = a[i++];
    while (j < m) c[k++]=b[j++];

    *res_n =n + m;
    return c;
}

int main(void) {
    int n, m;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    scanf("%d", &m);
    int *b = malloc(m * sizeof(int));
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
    int k;
    int *c = merge(a, n, b, m, &k);
    for (int i = 0; i < k; ++i)
        printf("%d ", c[i]);
    printf("\n");

    free(a);
    free(b);
    free(c);
    return 0;
}
