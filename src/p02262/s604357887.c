/*
** シェルソート
*/
#include <stdio.h>

#define MAX 1000000


int insertionSort(int[], int, int);
int shellSort(int [], int);

int main() {
    int i;
    int array[MAX], n;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    shellSort(array, n);

    for (i = 0; i < n; i++) {
        printf("%d\n", array[i]);
    }
}

int shellSort(int array[], int n) {
    int i, m = 0, cnt = 0;
    int gap[MAX];

    for (i = n - 1; i > 1 ; i /= 2) {
        gap[m++] = i;
    }
    gap[m++] = 1;

    printf("%d\n", m);
    for (i = 0; i < m; i++) {
        printf("%d ", gap[i]);
    }
    printf("\n");

    for (i = 0; gap[i] > 0; i++) {
        cnt += insertionSort(array, n, gap[i]);
    }
    printf("%d\n", cnt);
    return cnt;
}

int insertionSort(int array[], int n, int gap) {
    int i, j, cnt = 0;
    int key;

    for (i = gap; i < n; i++) {
        key = array[i];
        j = i - gap;
        while (j >= 0 && key < array[j]) {
            array[j + gap] = array[j];
            j -= gap;
            cnt++;
        }
        array[j + gap] = key;
    }
    return cnt;
}

