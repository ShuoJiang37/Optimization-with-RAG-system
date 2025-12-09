#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n <= 0) { printf("\n"); return 0; }

    int *a = malloc((size_t)n * sizeof(int));
    if (!a) return 1;

    int max = 0;
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &a[i]) != 1) a[i] = 0;
        if (a[i] > max) max = a[i];
    }

    size_t mlen = (size_t)max + 1;
    int *counts = malloc(mlen * sizeof(int));
    if (!counts) { free(a); return 1; }

    for (size_t i = 0; i < mlen; ++i) counts[i] = 0;

    for (int i = 0; i < n; ++i) ++counts[(size_t)a[i]];

    int printed = 0;
    for (int value = 0; value <= max && printed < n; ++value) {
        while (counts[value]-- > 0) {
            if (printed++) putchar(' ');
            printf("%d", value);
        }
    }
    putchar('\n');

    free(a);
    free(counts);
    return 0;
}
