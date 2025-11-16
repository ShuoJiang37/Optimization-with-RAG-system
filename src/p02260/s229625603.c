#include <stdio.h>
#define SIZE 100

int
selectionSort(int [], int);

void
print(int [], int);

int
main(void)
{
    int i, n, arr[SIZE], sw;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", arr + i);
    sw = selectionSort(arr, n);
    print(arr, n);
    printf("%d\n", sw);
    return 0;
}

int
selectionSort(int arr[], int n)
{
    int i, j, min, flag, v, sw;
    sw = 0;
    for (i = 0; i < n - 1; i++) {
        min = i;
        flag = 0;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min]) {
                min = j;
                flag = 1;
            }
        v = arr[i];
        arr[i] = arr[min];
        arr[min] = v;
        sw += flag;
    }
    return sw;
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
