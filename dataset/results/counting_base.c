#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;  // invalid input
    }

    if (n < 0) {
        return 0;  // invalid input
    }

    // Values are in [0, 10000]
    const int MAX_VAL = 10000;
    int *count = (int *)calloc(MAX_VAL + 1, sizeof(int));
    if (!count) {
        return 0;  // allocation failed
    }

    // Read and count
    for (int i = 0; i < n; ++i) {
        int x;
        if (scanf("%d", &x) != 1) {
            free(count);
            return 0;  // invalid input
        }
        if (x < 0 || x > MAX_VAL) {
            free(count);
            return 0;  // value out of allowed range
        }
        count[x]++;
    }

    // Output in non-decreasing order
    int printed = 0;
    for (int v = 0; v <= MAX_VAL; ++v) {
        while (count[v] > 0) {
            if (printed) {
                putchar(' ');
            }
            printf("%d", v);
            printed = 1;
            count[v]--;
        }
    }
    putchar('\n');

    free(count);
    return 0;
}
