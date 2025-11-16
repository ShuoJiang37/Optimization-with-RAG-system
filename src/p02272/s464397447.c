#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define arr_print_d0dn(a, n) for(int i=0;i<(n)-1;++i)printf("%d ",(a)[i]);printf("%d\n",(a)[(n)-1])
#define arr_rprint_d0dn(a, n) for(int i=(n)-1;i>0;--i)printf("%d ",(a)[i]);printf("%d\n",(a)[0])
#define arr_print_dndn(a, n) for(int i=0;i<(n);++i)printf("%d\n",(a)[i])
#define arr_rprint_dndn(a, n) for(int i=(n)-1;i>=0;--i)printf("%d\n",(a)[i])

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
int cnt;
void merge(int *first, int *mid, int *last) {
    const int N1 = (int)(mid - first);
    const int N2 = (int)(last - mid);
    int *left = malloc(sizeof(int) * (N1 + 1));
    int *right = malloc(sizeof(int) * (N2 + 1));
    memcpy(left, first, sizeof(int) * (N1 + 1));
    memcpy(right, mid, sizeof(int) * (N2 + 1));
    left[N1] = right[N2] = 1000000000;
    for(int *it = first, i = 0, j = 0; it != last; ++it) {
        *it = left[i] <= right[j] ? left[i++] : right[j++];
    }
    free(left);
    free(right);
}
void merge_sort(int *first, int *last) {
    const int N = (int)(last - first);
    if(N < 2) return;
    int *mid = first + N / 2;
    merge_sort(first, mid);
    merge_sort(mid, last);
    merge(first, mid, last);
    cnt += N;
}
int main(int argc, char **argv) {
    int n = get_uint();
    int s[500001];
    for(int i = 0; i < n; ++i) s[i] = get_uint();
    merge_sort(s, s + n);
    arr_print_d0dn(s, n);
    printf("%d\n", cnt);
    return 0;
}

