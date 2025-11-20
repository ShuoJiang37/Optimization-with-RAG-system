#include <stdio.h>

#define arr_print_d0dn(a, n) for(int i=0;i<(n)-1;++i)write_uint((a)[i]),*_o++=' ';write_uint((a)[(n)-1]),*_o++='\n'

#define INPUT__LENGTH (20000000)
char _in[INPUT__LENGTH];
char *_i = _in;
int read_uint() {
    int n = 0;
    while(47 < *_i && *_i < 58) n = 10 * n + (*_i++ & 0xf);
    _i++;
    return n;
}
#define OUTPUT__LENGTH (20000000)
char _out[OUTPUT__LENGTH];
char *_o = _out;
void write_uint(int n) {
    if(!n) {
        *_o++ = '0';
        return;
    }
    char buf[11];
    int i = 0;
    while(n) buf[i++] = (n % 10 + '0'), n /= 10;
    while(i--) *_o++ = buf[i];
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
    fread_unlocked(_in, 1, INPUT__LENGTH, stdin);
    int n = read_uint();
    int a[n], b[n];
    for(int i = 0; i < n; ++i) a[i] = read_uint();
    counting_sort(b, a, n, 10000);
    arr_print_d0dn(b, n);
    fwrite_unlocked(_out, 1, _o - _out, stdout);
    return 0;
}

