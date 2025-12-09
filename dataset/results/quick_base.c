#include <stdio.h>
#include <stdlib.h>

#define MAXN 2000000

static int arr[MAXN];

/* Iterative quicksort with median-of-three pivot and tail recursion elimination */

static void quicksort(int *a, int n) {
    /* Explicit stack for (left, right) ranges */
    int stack_l[64], stack_r[64];
    int top = 0;

    stack_l[top] = 0;
    stack_r[top] = n - 1;
    top++;

    while (top) {
        int l = stack_l[--top];
        int r = stack_r[top];

        while (l < r) {
            int i = l, j = r;
            /* Median-of-three pivot selection */
            int m = l + ((r - l) >> 1);
            int x = a[m];

            if (a[l] > a[m]) { int t = a[l]; a[l] = a[m]; a[m] = t; }
            if (a[m] > a[r]) { int t = a[m]; a[m] = a[r]; a[r] = t; }
            if (a[l] > a[m]) { int t = a[l]; a[l] = a[m]; a[m] = t; }
            x = a[m];

            /* Hoare partition */
            while (i <= j) {
                while (a[i] < x) i++;
                while (a[j] > x) j--;
                if (i <= j) {
                    int t = a[i]; a[i] = a[j]; a[j] = t;
                    i++; j--;
                }
            }

            /* Recurse on smaller part first (via stack) to keep depth small */
            if (j - l < r - i) {
                if (l < j) {
                    stack_l[top] = l;
                    stack_r[top] = j;
                    top++;
                }
                l = i;
            } else {
                if (i < r) {
                    stack_l[top] = i;
                    stack_r[top] = r;
                    top++;
                }
                r = j;
            }
        }
    }
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n < 0 || n > MAXN) return 0;

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) return 0;
    }

    if (n > 1)
        quicksort(arr, n);

    /* Output in one line, space-separated */
    for (int i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", arr[i]);
    }
    putchar('\n');

    return 0;
}
