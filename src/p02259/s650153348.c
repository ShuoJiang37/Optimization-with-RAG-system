#include <stdio.h>
#define MAX 100

int
bubbleSort(int [], int);

void
print(int [], int);

int
main(void)
{
    int arr[MAX], n, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int cnt = bubbleSort(arr, n);

    print(arr, n);
    printf("%d\n", cnt);

    return 0;
}

int
bubbleSort(int arr[], int n)
{
    int i, j, v, cnt;
    cnt = 0;

    for (i = 0; i < n; i++)
        for (j = n - 1; j > i; j--)
            if (arr[j] < arr[j - 1]) {
                v = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = v;
                cnt++;
            }
    return cnt;
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
