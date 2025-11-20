#include <stdio.h>
#include <string.h>

typedef struct
{
    char a;
    int num;
} data;

//バブルソートと比較し安定か安定じゃないか確かめる

int main()
{
    data data[36], data1[36], data2[36], tmp_data;
    int i, j, n, minj, s = 0, flag = 0, flag2 = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf(" %c %d", &data[i].a, &data[i].num);
        // printf("",data[i].a,data[i].num);
        data1[i] = data[i];
        data2[i] = data[i];
    }

    //for(i=0;i<n;i++)printf("%c%d  i=%d\n",data[i].a,data[i].num,i);

    //バブルソート
    flag = 1;
    while (flag)
    {
        flag = 0;
        for (j = n - 1; j > s; j--)
        {
            //printf("hoge1\n");
            if (data1[j - 1].num > data1[j].num)
            {
                tmp_data = data1[j - 1];
                data1[j - 1] = data1[j];
                data1[j] = tmp_data;
                flag = 1;
            }
        }
        s++;
    }

    for (i = 0; i < n; i++)
    {
        printf("%c%d", data1[i].a, data1[i].num);
        if (i != n - 1)
            printf(" ");
    }
    printf("\nStable\n");

    //セレクションソート
    for (i = 0; i < n; i++)
    {
        minj = i;
        for (j = i; j < n; j++)
        { //printf("hoge2\n");
            if (data2[j].num < data2[minj].num)
            {
                minj = j;
            }
        }
        //printf("hoge3\n");
        tmp_data = data2[i];
        data2[i] = data2[minj];
        data2[minj] = tmp_data;
    }

    for (i = 0; i < n; i++)
    {
        printf("%c%d", data2[i].a, data2[i].num);
        if (i != n - 1)
            printf(" ");
        if (data1[i].a != data2[i].a)
            flag2 = 1;
    }
    printf("\n");

    if (flag2 == 0)
        printf("Stable\n");
    else
        printf("Not stable\n");
    return 0;
}

