// 1 BubbleSort(C, N)
// 2   for i = 0 to N-1
// 3     for j = N-1 downto i+1
// 4       if C[j].value < C[j-1].value
// 5         C[j] と C[j-1] を交換
// 6
// 7 SelectionSort(C, N)
// 8   for i = 0 to N-1
// 9     minj = i
// 10    for j = i to N-1
// 11      if C[j].value < C[minj].value
// 12        minj = j
// 13    C[i] と C[minj] を交換

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    char c[n];
    int pre;
    for (pre = 0; pre < n; pre++)
    {
        scanf(" %c%d", &c[pre], &a[pre]);
    }

    int aa[n];
    char cc[n];
    int pp;
    for (pp = 0; pp < n; pp++)
    {
        cc[pp] = c[pp];
        aa[pp] = a[pp];
    }

    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
            {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                char tempc = c[j];
                c[j] = c[j - 1];
                c[j - 1] = tempc;
            }
        }
    }
    for (pre = 0; pre < n; pre++)
    {
        printf("%c%d", c[pre], a[pre]);
        if (pre < n - 1)
        {
            printf(" ");
        }
    }
    printf("\nStable\n");

    for (i = 0; i < n; i++)
    {
        int minj = i;
        for (j = i; j < n; j++)
        {
            if (aa[j] < aa[minj])
            {
                minj = j;
            }
        }
        int temp = aa[i];
        aa[i] = aa[minj];
        aa[minj] = temp;
        char tempc = cc[i];
        cc[i] = cc[minj];
        cc[minj] = tempc;
    }

    int flag = 0;
    for (pre = 0; pre < n; pre++)
    {
        if (cc[pre] != c[pre])
        {
            flag = 1;
        }
        printf("%c%d", cc[pre], aa[pre]);
        if (pre < n - 1)
        {
            printf(" ");
        }
    }
    if (flag == 0)
    {
        printf("\nStable\n");
    }
    else
    {
        printf("\nNot stable\n");
    }
    return 0;
}
