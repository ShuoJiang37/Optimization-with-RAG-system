#include <stdio.h>
#define arr_print_d0dn(a,n) for(int i=0;i<(n)-1;++i)put_uint((a)[i]),putchar_unlocked(' ');put_uint((a)[(n)-1]),putchar_unlocked('\n')
#define arr_rprint_d0dn(a,n) for(int i=(n)-1;i>0;--i)put_uint((a)[i]),putchar_unlocked(' ');put_uint(*(a)),putchar_unlocked('\n')
#define arr_print_dndn(a,n) for(int i=0;i<(n);++i)put_uint((a)[i]),putchar_unlocked('\n')
#define arr_rprint_dndn(a,n) for(int i=(n)-1;i>=0;--i)put_uint((a)[i]),putchar_unlocked('\n')


void put_uint(int n) {
    if(!n) {
        putchar_unlocked('0');
        return;
    }
    char buf[11];
    int i = 0;
    while(n) buf[i++] = (char)(n % 10 + '0'), n /= 10;
    while(i--)putchar_unlocked(buf[i]);
}
int get_uint() {
    int n = 0;
    int c = getchar_unlocked();
    if(c < 48 || 57 < c) return c;
    while(47 < c && c < 58) {
        n = 10 * n + (c & 0xf);
        c = getchar_unlocked();
    }
    return n;
}

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

    put_uint(m);
    putchar_unlocked('\n');
    arr_rprint_d0dn(G, m);
    put_uint(cnt);
    putchar_unlocked('\n');
    arr_print_dndn(a, N);
}

int main() {
    int n = get_uint();
    int a[n];
    for(int i = 0; i < n; ++i) {
        a[i] = get_uint();
    }
    shell_sort(a, n);
    return 0;
}

