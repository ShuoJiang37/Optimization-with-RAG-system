#include <stdio.h>

#define arr_print_d0dn(a, n) for(int i=0;i<(n);++i)printf(i==(n)-1?"%d\n":"%d ",(a)[i])
#define arr_rprint_d0dn(a, n) for(int i=(n)-1;i>=0;--i)printf(i?"%d ":"%d\n", (a)[i])
#define arr_print_dndn(a, n) for(int i=0;i<(n);++i)printf("%d\n", (a)[i])

int insertion_sort(int *a, const int N, const int G) {
    int cnt = 0;
    for(int i = G; i < N; ++i) {
        int tmp = a[i];
        int j = i - G;
        while(j >= 0 && a[j] > tmp) {
            // G: gap
            a[j + G] = a[j];
            j -= G;
            cnt++;
        }
        a[j + G] = tmp;
    }
    return cnt;
}

void shell_sort(int *a, const int N) {
    int cnt = 0;
    // m: g-arr size
    int m = 0;
    int G[100] = {};
    // h: well known value (from Wikipedia)
    for(int h = 1; h <= N; h = 3 * h + 1) {
        G[m] = h;
        m++;
    }
    for(int i = m - 1; i >= 0; --i) {
        // insertion sort with G[i] gap
        cnt += insertion_sort(a, N, G[i]);
    }

    printf("%d\n", m);
    arr_rprint_d0dn(G, m);
    printf("%d\n", cnt);
    arr_print_dndn(a, N);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    shell_sort(a, n);
    return 0;
}

