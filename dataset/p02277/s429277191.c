#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

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
typedef struct Card {
    int n;
    char c;
} Card;

// retard desu LMAO
void merge(Card *first, Card *mid, Card *last) {
    const int N1 = (int)(mid - first);
    const int N2 = (int)(last - mid);
    Card left[N1 + 1];
    Card right[N2 + 1];
    memcpy(left, first, sizeof(Card) * (N1 + 1));
    memcpy(right, mid, sizeof(Card) * (N2 + 1));
    left[N1].n = right[N2].n = 1000000000;
    int i = 0, j = 0;
    for(Card *it = first; it != last; ++it) {
        *it = left[i].n <= right[j].n ? left[i++] : right[j++];
    }
}
void merge_sort(Card *first, Card *last) {
    const int N = (int)(last - first);
    if(N < 2) return;
    Card *mid = first + N / 2;
    merge_sort(first, mid);
    merge_sort(mid, last);
    merge(first, mid, last);
}
void *partition(Card *first, Card *last) {
    Card pivot = *(last - 1);
    Card *p = first - 1;
    for(Card *it = first; it != last - 1; ++it) {
        if(it->n <= pivot.n) {
            p++;
            Card tmp = *p;
            *p = *it;
            *it = tmp;
        }
    }
    Card tmp = *++p;
    *p = pivot;
    *(last - 1) = tmp;
    return p;
}
void quicksort(void *first, void *last, size_t N) {
    if(last - first <= N) return;
    void *mid = partition(first, last);
    quicksort(first, mid, N);
    quicksort(mid, last, N);
}

int main(int argc, char **argv) {
    int n = get_uint();
    Card a[n], b[n];
    for(int i = 0; i < n; ++i) {
        a[i].c = getchar_unlocked();
        getchar_unlocked();
        a[i].n = get_uint();
    }
    memcpy(b, a, n * sizeof(Card));
    quicksort(a, a + n, sizeof(Card));
    merge_sort(b, b + n);

    int flag = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i].c != b[i].c) flag |= 1;
    }
    puts(flag ? "Not stable" : "Stable");
    for(int i = 0; i < n; ++i) {
        putchar_unlocked(a[i].c), putchar_unlocked(' ');
        put_uint(a[i].n), putchar_unlocked('\n');
    }
    return 0;
}

