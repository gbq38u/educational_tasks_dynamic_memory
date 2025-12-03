#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    for (int i= 0; i < n; ++i) scanf("%d", &a[i]);
    int best_sum = a[0], cur_sum = a[0];
    int best_l = 0, best_r = 0;
    int cur_l = 0;

    for (int i =1; i <n; ++i) {
        if (cur_sum + a[i] < a[i]) {
            cur_sum= a[i];
            cur_l = i;
        } else {
            cur_sum += a[i];
        }
        if (cur_sum > best_sum) {
            best_sum =cur_sum;
            best_l = cur_l;
            best_r =i;
        }
    }
    int len = best_r - best_l + 1;
    a = realloc(a,(n + len) * sizeof(int));
    if (!a) return 1;
    for (int i = 0; i < len; ++i)
        a[n + i] = a[best_l + i];
    int new_n = n + len;
    for (int i = 0; i< new_n; ++i)
        printf("%d ", a[i]);
    printf("\n");
    free(a);
    return 0;
}
