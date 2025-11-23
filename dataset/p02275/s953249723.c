#include <stdio.h>

#define arr_print_d0dn(a, n) for(int i=0;i<(n)-1;++i)put_uint((a)[i]),putchar_unlocked(' ');put_uint((a)[(n)-1]),putchar_unlocked('\n')
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
void counting_sort(int *dst, const int *src, const int N, const int max) {
    // 'int c[max+1] = {}' cannot initialize
    int c[10001] = {};
    for(int i = 0; i < N; ++i) c[src[i]]++;
    for(int i = 1; i < max; ++i) c[i] += c[i - 1];
    for(int i = N - 1; i >= 0; --i) {
        int x = src[i];
        int y = c[x];
        dst[c[src[i]]-- - 1] = src[i];
    }
}
int main(int argc, char **argv) {
    int n = get_uint();
    int a[n], b[n];
    for(int i = 0; i < n; ++i) a[i] = get_uint();
    counting_sort(b, a, n, 10000);
    arr_print_d0dn(b, n);
    return 0;
}

