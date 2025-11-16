#include<stdio.h>
long int a[1000000];
//insertionSort
void insertion_sort(long int *a, long int g, long int n, long long int *cnt)
{
    int i, j;
    long int v;

    for(i=g;i<n;i++)
    {
        v=a[i];
        j=i-g;
        while(j>=0 && a[j]>v)
        {
            a[j+g]=a[j];
            j=j-g;
            (*cnt)++;
        }
        a[j+g]=v;
    }
}
int main(void)
{
    long int n;
    long int g[100], h;
    int i, j, m=0;
    long long int cnt=0;

    scanf("%ld", &n);
    for(i=0; i<n; i++)
        scanf("%ld", &a[i]);

    //shellSort
    h=1;
    for(i=0; h<=n; i++)
    {
        g[i]=h;
        m++;
        h=h*3+1;
    }
    for(j=m-1; j>=0; j--)
        insertion_sort(a, g[j], n, &cnt);

    printf("%d\n", m);
    for(i=m-1;i>0;i--)
        printf("%ld ", g[i]);
    printf("%ld\n", g[i]);
    printf("%lld\n", cnt);
    for(i=0;i<n;i++)
        printf("%ld\n", a[i]);

    return 0;
}