#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int cnt;

void InsertionSort(int a[], int n, int g) {
    int i, j, v;
    
    for (i = g; i < n; i++) {
        v = a[i];
        j = i - g;
        while (j >= 0 && a[j] > v) {
            a[j + g] = a[j];
            j = j - g;
            cnt++;
        }
        a[j + g] = v;
    }
}

void ShellSort(int a[], int n) {
    int m, i;
    int gs[100];
    
    gs[0] = 0;
    for (i = 1; i <= n; i++) {
        gs[i] = 3 * gs[i-1] + 1;
        if (gs[i] >= n / 3) {
            m = i;
            break;
        }
    }
    cnt = 0;
    printf("%d\n", m);
    for (i = 0; i < m; i++) {
        if (i == 0)
            printf("%d", gs[m-i]);
        else
            printf(" %d", gs[m-i]);
        InsertionSort(a, n, gs[m-i]);
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

    ShellSort(a, n);
    
    free(a);

    return 0;
}

