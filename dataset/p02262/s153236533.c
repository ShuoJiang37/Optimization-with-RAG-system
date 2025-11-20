#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cnt;
int array[1000000];
int G[100];

void insertionSort(int array[], int n, int g) {
    int i, j, v;
    i = 0;
    
    for (i = g; i < n; i++) {
        v = array[i];
        j = i - g;

        while (j >= 0 && array[j] > v) {
            array[j + g] = array[j];
            j = j - g;
            cnt++;
        }

        array[j + g] = v;
    }
}

void shellSort(int array[], int n) {
    cnt = 0;
    int h;
    int i = 0;
    for (h = 1; ; ) {
        if (h > n) break;
        G[i] = h;
        i++;
        h = 3 * h + 1; 
    }

    int m = i;
    if (m > 100) m = 100;

    printf("%d\n", m);

    i = 0;
    for (i = m-1; i >= 0; i--) {
        printf("%d ", G[i]);
        insertionSort(array, n, G[i]);
    }

    printf("\n%d\n", cnt);

    for (i = 0; i < n; i++) {
        printf("%d\n", array[i]);
    }
}

int main() {

    int n, key;
    scanf("%d", &n);
    key = n;
    
    int i = 0;
    while ( key-- ) {
        scanf("%d", &array[i]);
        i++;
    }

    shellSort(array, n);

    return 0;
}

