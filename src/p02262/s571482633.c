#include<stdlib.h>
#include<stdio.h>

long long cnt = 0;
int count = 0;
int a[1000000];
int g[100];

void insertSort(int a[], int n, int g)
{
    for (int i = g; i < n; i++)
    {
        int v = a[i];
        int j = i - g;

        while (j >= 0 && a[j] > v)
        {
            a[j + g] = a[j];
            j = j - g;
            cnt++;
        }
        a[j + g] = v;
    }
}

void shellSort(int a[], int n)
{
    int h = 1;
    g[count] = 1;

    while ((3 * h + 1) <= n)
    {
        h = 3 * h + 1;
        count++;
        g[count] = h;
    }

    for (int i = count; i >= 0; i--)
    {
        insertSort(a, n, g[i]);
    }       
}

int main()
{
    int n;

    
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    shellSort(a, n);

    printf("%d\n", count + 1);
    for (int i = count; i >= 0; i--)
    {
        printf("%d", g[i]);
        if (i > 0)
        {
            printf(" ");
        }
    }
    printf("\n");

    printf("%d\n", cnt);

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    
    return 0;
}
