#include <stdio.h>
#define N 101

int main() {
    int i, j, n, key, k;
    int arr[N];

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 1; i < n; i++) {

        k = 0;
        while(k < n-1){
            printf("%d ", arr[k]);
            k++;
        }
        printf("%d\n", arr[n-1]);

        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    k = 0;
    while(k < n-1){
        printf("%d ", arr[k]);
        k++;
    }
    printf("%d\n", arr[n-1]);

    return 0;
}