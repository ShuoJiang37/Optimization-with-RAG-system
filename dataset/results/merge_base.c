#include <stdio.h>
#include <stdlib.h>

#define MAX_N 500000

static int arr[MAX_N];
static int temp[MAX_N];

void merge(int a[], int temp[], int left, int mid, int right) {
    int i = left;      // index for left half
    int j = mid + 1;   // index for right half
    int k = left;      // index for temp

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= right) {
        temp[k++] = a[j++];
    }

    // copy back to original array
    for (i = left; i <= right; i++) {
        a[i] = temp[i];
    }
}

void mergesort(int a[], int temp[], int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergesort(a, temp, left, mid);
    mergesort(a, temp, mid + 1, right);
    merge(a, temp, left, mid, right);
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    if (n < 0 || n > MAX_N) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            return 0;
        }
    }

    if (n > 0) {
        mergesort(arr, temp, 0, n - 1);
    }

    for (int i = 0; i < n; i++) {
        if (i) putchar(' ');
        printf("%d", arr[i]);
    }
    putchar('\n');

    return 0;
}
