#include<stdio.h>

void insert(int a[], int n);

int main()
{
    int a[1000];
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int i, j;
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        insert(a, n);
    }
}
void insert(int a[], int n)
{
    int i, j;
    int k;
    int t;
    printf("%d", a[0]);
    for(t = 1; t < n ; t++)
        printf(" %d", a[t]);
    printf("\n");
    for(i = 1; i < n; i++)
    {
        k = a[i];
        j = i - 1;
        while(j >= 0&& a[j] > k)
        {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = k;
        printf("%d", a[0]);
        for(t = 1; t < n ; t++)
            printf(" %d", a[t]);
        printf("\n");
    }
}

