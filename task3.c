#include <stdio.h>

int main(void) {
    int arr[2][3];
    int (*p)[3] = arr; 
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j)
            scanf("%d", &p[i][j]);

    printf("sizeof(*p) = %zu (байт в одной строке)\n", sizeof(*p));
    printf("Адрес p      = %p\n", (void*)p);
    printf("Адрес p+1    = %p (смещение на одну строку)\n", (void*)(p+ 1));
    for (int i =0; i < 2; ++i) {
        for (int j =0; j <3; ++j)
            printf("%d ", p[i][j]);
        printf("\n");
    }
    return 0;
}
