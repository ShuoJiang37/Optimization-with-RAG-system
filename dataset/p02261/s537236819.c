#include <stdio.h>

typedef struct
{
    char c;
    int number;
} card;

int main()
{
    int n, i, j, min, flag;
    card a[36], b[36], x;
    char w;

    scanf("%d\n", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%c%d%c", &a[i].c, &a[i].number, &w);
        b[i] = a[i];
    }

//BubbleSort
    for (j = 0; j < n; j++)
    {
        flag = 0;
        for (i = n - 1; i > j; i--)
        {
            if (a[i].number < a[i - 1].number)
            {
                x = a[i];
                a[i] = a[i - 1];
                a[i - 1] = x;
                flag = 1;
            }
        }
        if (flag == 0) break;
    }

//SelectionSort
    for (j = 0; j < n; j++)
    {
        min = j;
        for (i = j; i < n; i++)
        {
            if (b[i].number < b[min].number)
                min = i;
        }
        if (min != j)
        {
            x = b[j];
            b[j] = b[min];
            b[min] = x;
        }
    }


//Output
    for (i = 0; i < n - 1; i++)
        printf("%c%d ", a[i].c, a[i].number);
    printf("%c%d\n", a[n - 1].c, a[n - 1].number);

    printf("Stable\n");
    for (i = 0; i < n - 1; i++)
    {
        printf("%c%d ", b[i].c, b[i].number);
        if (a[i].c != b[i].c)
            flag = 2;
    }
    printf("%c%d\n", b[n - 1].c, b[n - 1].number);
    if (flag == 2)
        printf("Not stable\n");
    else
        printf("Stable\n");

    return 0;
}
