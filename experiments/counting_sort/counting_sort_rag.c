#include <stdio.h>
#include <stdlib.h>

static int read_int(void) {
    int c = getchar();
    while (c != EOF && (c < '0' || c > '9')) c = getchar();
    if (c == EOF) return 0;
    int x = 0;
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x;
}

static void write_int(int x) {
    char buf[12];
    int i = 0;
    if (x == 0) { putchar('0'); return; }
    while (x > 0) {
        buf[i++] = '0' + (x % 10);
        x /= 10;
    }
    while (i--) putchar(buf[i]);
}

int main(void) {
    int n = read_int();
    if (n <= 0) { putchar('\n'); return 0; }

    int *a = (int *)malloc((size_t)n * sizeof(int));
    if (!a) return 1;

    int maxv = 0;
    for (int i = 0; i < n; ++i) {
        int v = read_int();
        a[i] = v;
        if (v > maxv) maxv = v;
    }

    /* allocate counts based on observed maximum value */
    int *cnt = (int *)malloc((size_t)(maxv + 1) * sizeof(int));
    if (!cnt) { free(a); return 1; }

    for (int i = 0; i <= maxv; ++i) cnt[i] = 0;
    for (int i = 0; i < n; ++i) ++cnt[a[i]];

    int printed = 0;
    for (int v = 0; v <= maxv; ++v) {
        int c = cnt[v];
        while (c--) {
            if (printed) putchar(' ');
            write_int(v);
            printed = 1;
        }
    }
    putchar('\n');

    free(a);
    free(cnt);
    return 0;
}
