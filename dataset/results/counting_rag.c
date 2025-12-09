#include <stdio.h>

#define MAX_N     10000      /* maximum number of input integers */
#define MAX_VALUE 10000      /* maximum value of each integer    */

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 0 || n > MAX_N) {
        return 0; /* invalid input; silently exit */
    }

    /* Frequency array for counting sort */
    int count[MAX_VALUE + 1] = {0};

    /* Read values and count frequencies */
    for (int i = 0; i < n; ++i) {
        int x;
        if (scanf("%d", &x) != 1) {
            return 0; /* malformed input */
        }
        if (x < 0 || x > MAX_VALUE) {
            return 0; /* out-of-range input */
        }
        ++count[x];
    }

    /* Output sorted values in non-decreasing order */
    int remaining = n;
    for (int value = 0; value <= MAX_VALUE && remaining > 0; ++value) {
        int freq = count[value];
        while (freq-- > 0) {
            /* print value and decide whether to print a trailing space */
            printf("%d", value);
            if (--remaining > 0) {
                putchar(' ');
            }
        }
    }
    putchar('\n');

    return 0;
}
