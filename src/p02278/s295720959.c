#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif
int in()
{
    int n = 0, c = gc();
    do n = 10*n + (c & 0xf), c = gc(); while (c >= '0');
    return n;
}
 
int cmp(int *a, int *b) { return *a - *b; }
int min_cost_sort(int n, int *w, int min, int max)
{
    int i, s, t, t1, t2, m, an, cur, ans;
    int *a, *v;
    char *f;
 
    a = malloc(n<<2), f = malloc(n), v = malloc((max+1)<<2);
    memcpy(a, w, n<<2), memset(f, 0, n);
 
    qsort(a, n, sizeof(int), cmp);
    for (i = 0; i < n; i++) v[a[i]] = i;
 
    ans = 0;
    for (i = 0; i < n; i++) {
        if (f[i]) continue;
        cur = i, s = 0, m = max, an = 0;
        while (1) {
            f[cur] = 1, an++, t = w[cur];
            if (t < m) m = t;
            s += t, cur = v[t];
            if (f[cur]) break;
        }
        t1 = s+(an-2)*m, t2 = m+s+(an+1)*min;
        ans += (t1 < t2)? t1: t2;
    }
    free(a), free(f), free(v);
    return ans;
}
 
int w[1002];
 
int main()
{
    int n, i, _w, min, max;
 
    n = in();
    min =  0x10101010;
    max = -0x10101010;
    for (i = 0; i < n; i++) {
        w[i] = _w = in();
        if (_w < min) min = _w;
        if (_w > max) max = _w;
    }
    printf("%d\n", min_cost_sort(n, w, min, max));
    return 0;
}

