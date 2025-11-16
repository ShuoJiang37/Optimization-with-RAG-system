#include <stdio.h>
#define SIZE 100

void
print(int [], int);

void
insertionSort(int [], int);

int
main(void)
{
    int arr[SIZE];
    int i, n;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", arr + i);
    
    insertionSort(arr, n);
}

void
insertionSort(int arr[], int n)
{
    int i, j, tmp;
    print(arr, n);
    for (i = 1; i < n; i++) {
        tmp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = tmp;
        print(arr, n);
    }
}

void
print(int arr[], int n)
{
    int i = 0;
    printf("%d", arr[i++]);
    for ( ; i < n; i++)
        printf(" %d", arr[i]);
    putchar('\n');
}
