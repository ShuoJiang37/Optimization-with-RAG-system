#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
#define WMAX 10000
#define miner(x, y) ((x) < (y) ? (x) : (y))
#define swap(x, y, type) do {type t = x; x = y; y = t;} while(0)
void qsort1(int, int, int*);
int mcsort(int, int, int*);
main()
{
        int i, n, min = WMAX, *w;
        scanf("%d", &n);
        w = (int*)malloc(sizeof(int) * n);
        for (i = 0; i < n; i++) {
                scanf("%d", &w[i]);
                min = miner(w[i], min);
        }
        printf("%d\n", mcsort(min, n, w));
        free(w);
}
void qsort1(int left, int right, int *s){
        int pivot = s[(left + right) / 2], i = left, j = right;
    if (left >= right) return;
    do {
        while (s[i] < pivot) i++;
        while (s[j] > pivot) j--;
        if (i <= j) {
            swap(s[i], s[j], int);
            i++;
            j--;
        }
    }while (i <= j);
    qsort1(left, j, s);
    qsort1(i, right, s);
}
int mcsort(int min, int n, int *w)
{
        int i, ans = 0, s[n], f[n], p[WMAX + 1];
        for (i = 0; i < n; i++) {
                s[i] = w[i];
                f[i] = 0;
        }
        qsort1(0, n - 1, s);
        for (i = 0; i < n; i++) {
        p[s[i]] = i;
    }
        for (i = 0; i < n; i++) {
                int cur = i, m = WMAX, sum = 0, cn = 0;
                if(f[i]) continue;
                while (!f[cur]) {
                        f[cur] = 1;
                        cn++;
                        m = miner(w[cur], m);
                        sum += w[cur];
                        cur = p[w[cur]];
                }
                ans += miner(sum + (cn - 2) * m, sum + m + (cn + 1) * min);
    }
        return ans;
}
