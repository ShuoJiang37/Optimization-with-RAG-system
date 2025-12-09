#include <stdio.h>
#include <stdlib.h>

#define MAX_N 500000

/* 
 * Top-down mergesort with a single auxiliary buffer.
 * Uses indices [left, right) (right is exclusive).
 */

static void merge(int *a, int *aux, int left, int mid, int right) {
    int i = left;  /* index into left half   */
    int j = mid;   /* index into right half  */
    int k = left;  /* index into aux buffer  */

    /* Merge into aux */
    while (i < mid && j < right) {
        if (a[i] <= a[j]) {
            aux[k++] = a[i++];
        } else {
            aux[k++] = a[j++];
        }
    }
    while (i < mid) {
        aux[k++] = a[i++];
    }
    while (j < right) {
        aux[k++] = a[j++];
    }

    /* Copy back to original array */
    for (i = left; i < right; ++i) {
        a[i] = aux[i];
    }
}

static void mergesort(int *a, int *aux, int left, int right) {
    if (right - left <= 1) {
        return; /* already sorted */
    }
    int mid = left + (right - left) / 2;
    mergesort(a, aux, left, mid);
    mergesort(a, aux, mid, right);
    merge(a, aux, left, mid, right);
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0; /* invalid input */
    }
    if (n < 0 || n > MAX_N) {
        return 0; /* out of spec */
    }

    int *a = (int *)malloc((size_t)n * sizeof(int));
    if (!a) {
        return 0; /* allocation failure */
    }

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &a[i]) != 1) {
            free(a);
            return 0;
        }
    }

    int *aux = (int *)malloc((size_t)n * sizeof(int));
    if (!aux) {
        free(a);
        return 0;
    }

    mergesort(a, aux, 0, n);

    /* Output on one line, space-separated */
    if (n > 0) {
        printf("%d", a[0]);
        for (int i = 1; i < n; ++i) {
            printf(" %d", a[i]);
        }
    }
    putchar('\n');

    free(aux);
    free(a);
    return 0;
}
