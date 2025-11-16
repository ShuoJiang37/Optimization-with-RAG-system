#include <stdio.h>
#include <math.h>
#define ll long long
#define rep(i, n) for ((i)=0;(i)<(n);(i)++)
int G[1000000] = {};
int cnt = 0;
int generateInterval(int n) {
    int i = 0;
    do {
        G[i] = (pow(3, i+1)-1)/2;
        i++;
    } while ((pow(3, i+1)-1)/2 < n);
    return i;
}

int insertionSort(ll *a, int n, int g) {
    int i, j;
    ll v;
    for (i = g; i < n; i++) {
        v = a[i];
        j = i - g;
        while (j >= 0 && a[j] > v) {
            a[j + g] = a[j];
            j = j - g;
            cnt++;
        }
        a[j+g] = v;
    }
    return 0;
}

int shellSort(ll *a, int n) {
    int idx;
    int m = generateInterval(n);
    for (idx = m - 1; idx >= 0; idx--) insertionSort(a, n, G[idx]);
    return m;
}

int main (void) {
    int n, index, ans;
    scanf("%d", &n);
    ll A[n];
    
    rep(index, n) scanf("%lld", &A[index]);
    
    ans = shellSort(A, n);
    
    printf("%d\n", ans);

    for (index = ans - 1; index >= 0; index--) {
        printf("%d", G[index]);
        if (index > 0)  printf(" ");
    }
    printf("\n");
    printf("%d\n", cnt);

    rep(index, n) printf("%lld\n", A[index]);

    return 0;
}
