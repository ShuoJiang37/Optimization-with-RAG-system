#include <stdio.h>
#include <memory.h>

#define MIN(x, y) ((x) <= (y) ? (x) : (y))
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
void *partition(int *first, int *last) {
    int pivot = *(last - 1);
    int *p = first - 1;
    for(int *it = first; it != last - 1; ++it) {
        if(*it <= pivot) {
            p++;
            int tmp = *p;
            *p = *it;
            *it = tmp;
        }
    }
    int tmp = *++p;
    *p = pivot;
    *(last - 1) = tmp;
    return p;
}
void quick_sort(void *first, void *last, size_t N) {
    if(last - first <= N) return;
    void *mid = partition(first, last);
    quick_sort(first, mid, N);
    quick_sort(mid, last, N);
}
int mincost_sort(const int *a, const int N, const int minw) {
    int cnt = 0;
    int b[N];
    memcpy(b, a, N * sizeof(int));
    quick_sort(b, b + N, sizeof(int));
    int pos[10001];
    for(int i = 0; i < N; ++i) pos[b[i]] = i;
    int flag[1001] = {};
    for(int i = 0; i < N; ++i) {
        if(flag[i]) continue;
        int cur = i;
        int sum = 0;
        int num = 0;
        int mina = 1 << 29;
        while(!flag[cur]) {
            flag[cur] = 1;
            num++;
            sum += a[cur];
            mina = MIN(mina, a[cur]);
            cur = pos[a[cur]];
        }
        // [ sum + (num-2)*mina + 2(mina+minw) - (num-1)*(mina-minw) ] -> [ sum + mina + (n+1)*minw ]
        cnt += MIN(sum + (num - 2) * mina, sum + mina + (num + 1) * minw);
    }
    return cnt;
}
int main(int argc, char **argv) {
    int n = get_uint();
    int w[n];
    int minw = 1 << 29;
    for(int i = 0; i < n; ++i) {
        w[i] = get_uint();
        minw = MIN(minw, w[i]);
    }
    put_uint(mincost_sort(w, n, minw));
    putchar_unlocked('\n');
    return 0;
}

