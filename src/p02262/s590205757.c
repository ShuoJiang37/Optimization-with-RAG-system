#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int cnt;

void insertion_sort(int a[], int n, int gap) {
    int i, j, v;
    for (i = gap; i < n; i++) {
        v = a[i];
        j = i - gap;
        while (j >= 0 && a[j] > v) {
            a[j + gap] = a[j];
            j = j - gap;
            cnt++;
        }
        a[j + gap] = v;
    }
}

void shell_sort(int a[], int n) {
    int m, i;
    int gaps[100];
    gaps[0] = 0;
    for (i = 1; i <= n; i++) {
        gaps[i] = 3 * gaps[i-1] + 1;
        if (gaps[i] >= n / 3) {
            m = i;
            break;
        }
    }
    cnt = 0;
    printf("%d\n", m);
    for (i = 0; i < m; i++) {
        if (i == 0)
            printf("%d", gaps[m-i]);
        else
            printf(" %d", gaps[m-i]);
        insertion_sort(a, n, gaps[m-i]);
    }
    printf("\n");
    printf("%d\n", cnt);
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}

int main(void) {
    int n, i, j, key;
    int *a;
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    shell_sort(a, n);
    
    free(a);

    return 0;
}