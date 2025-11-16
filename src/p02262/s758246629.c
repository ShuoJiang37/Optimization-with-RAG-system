#include <stdio.h>

#define MAXNUMS 1000000
#define MAXGAPS 13

long g_cnt = 0;

void ShellSort(long line[], const long n);
void InsertionSort(long line[], const long n, const int gap);

int main(void)
{
    int i;

    long n;
    scanf("%ld", &n);

    long line[MAXNUMS];
    for (i = 0; i < n; i++) {
        scanf(" %ld", &line[i]);
    }

    ShellSort(line, n);
    printf("%ld\n", g_cnt);
    for (i = 0; i < n; i++) {
        printf("%ld\n", line[i]);
    }

    return 0;
}

void ShellSort(long line[], const long n)
{
    int i;

    int gap[MAXGAPS];
    int m = 1;
    gap[0] = m;
    int gap_cnt = 1;
    for (i = 1; (m = 3 * m + 1) <= n; i++) {
        gap[i] = m;
        gap_cnt++;
    }

    printf("%d\n", gap_cnt);
    for (i = gap_cnt - 1; i >=  0; i--) {
        printf("%d", gap[i]);
        if (i != 0) {
            printf(" ");
        }
    }
    printf("\n");

    for (i = gap_cnt - 1; i >=  0; i--) {
        InsertionSort(line, n, gap[i]);
    }
}

void InsertionSort(long line[], const long n, const int gap)
{
    long i, j;

    for (i = gap; i < n; i++) {
        long key = line[i];
        for (j = i - gap; j >= 0 && line[j] > key; j -= gap) {
            line[j + gap] = line[j];
            g_cnt++;
        }
        line[j + gap] = key;
    }
}