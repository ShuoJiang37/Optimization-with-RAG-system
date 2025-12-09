#include <stdio.h>
#include <stdlib.h>

/*
 * Quicksort for up to 2,000,000 integers.
 * - Iterative, not recursive (avoids deep recursion).
 * - Median-of-three pivot selection.
 * - Hoare partition scheme.
 * - Switches to insertion sort for small subarrays.
 */

#define CUTOFF 16  /* threshold for using insertion sort */

static void insertion_sort(int *a, int left, int right) {
    int i, j, key;
    for (i = left + 1; i <= right; ++i) {
        key = a[i];
        j = i - 1;
        while (j >= left && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
}

static void quicksort(int *a, int n) {
    if (n <= 1) return;

    /* Manual stack for ranges [l, r] */
    struct Range { int l, r; };
    struct Range stack[64]; /* enough for n up to 2,000,000 */
    int top = 0;

    stack[top].l = 0;
    stack[top].r = n - 1;

    while (top >= 0) {
        int left  = stack[top].l;
        int right = stack[top].r;
        --top;

        while (right - left + 1 > CUTOFF) {
            /* Median-of-three pivot selection */
            int mid = left + ((right - left) >> 1);
            int x = a[left], y = a[mid], z = a[right];
            int pivot_index;

            if (x < y) {
                if (y < z)      pivot_index = mid;
                else if (x < z) pivot_index = right;
                else            pivot_index = left;
            } else {
                if (x < z)      pivot_index = left;
                else if (y < z) pivot_index = right;
                else            pivot_index = mid;
            }

            int pivot = a[pivot_index];
            /* Move pivot to left for Hoare partition */
            {
                int tmp = a[left];
                a[left] = a[pivot_index];
                a[pivot_index] = tmp;
            }

            /* Hoare partition */
            int i = left - 1;
            int j = right + 1;
            for (;;) {
                do { ++i; } while (a[i] < pivot);
                do { --j; } while (a[j] > pivot);
                if (i >= j) break;
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }

            /* Now [left..j] and [j+1..right] are partitions */
            int left_size  = j - left + 1;
            int right_size = right - (j + 1) + 1;

            /* Tail recursion elimination: sort larger part later (push) */
            if (left_size < right_size) {
                /* Push larger right part */
                if (j + 1 < right) {
                    ++top;
                    stack[top].l = j + 1;
                    stack[top].r = right;
                }
                /* Continue loop with smaller left part */
                right = j;
            } else {
                /* Push larger left part */
                if (left < j) {
                    ++top;
                    stack[top].l = left;
                    stack[top].r = j;
                }
                /* Continue loop with smaller right part */
                left = j + 1;
            }
        }

        /* Small segment: use insertion sort */
        if (left < right) {
            insertion_sort(a, left, right);
        }
    }
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    if (n < 0) return 0;

    int *a = (int *)malloc((size_t)n * sizeof(int));
    if (!a) {
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &a[i]) != 1) {
            free(a);
            return 0;
        }
    }

    quicksort(a, n);

    if (n > 0) {
        printf("%d", a[0]);
        for (int i = 1; i < n; ++i) {
            printf(" %d", a[i]);
        }
    }
    printf("\n");

    free(a);
    return 0;
}
