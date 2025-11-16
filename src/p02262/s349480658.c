#include <stdio.h>

#define m (100)

static const int MAXNUMOFINPUT = 1000000;
long long cnt;
int size;
int G[m];

int insertionSort(int A[], int n, int g);
int shellSort(int A[], int n);

int main()
{
    int i;
    int n;
    int A[MAXNUMOFINPUT];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    cnt = 0;

    shellSort(A, n);

    printf("%d\n", size);

    for (i = size - 1; i >= 0; i--)
    {
        printf("%d", G[i]);
        if(i)
        {
            printf(" ");
        }
    }
    printf("\n");
    printf("%lld\n", cnt);

    for (i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }

    return 0;
}

int insertionSort(int A[], int n, int g)
{
    int i, j;
    int v;

    for (i = g; i < n; i++)
    {
        v = A[i];
        j = i - g;
        while (j >= 0 && A[j] > v)
        {
            A[j + g] = A[j];
            j -= g;
            cnt++;
        }
        A[j + g] = v;
    }
}

int shellSort(int A[], int n)
{
    int i, j;
    int g = 1;

    for (i = 0; i < m; i++)
    {
        if(g > n || g > MAXNUMOFINPUT)
        {
            break;
        }
        G[i] = g;
        g = 3 * g + 1;
    }

    size = i;

    for (j = size - 1; j >= 0; j--)
    {
        insertionSort(A, n, G[j]);
    }

    return 0;
}

