#include <stdio.h>
#include <string.h>

//함수의 인수를 int **array로 했을때 실행이 안되었었다. 하지만 int array[][2] 라던지 int order[][36]로 했더니 실행이 되고 답이됨..
//처음 정의를 할때 동적메모리로 정희하지 않았기에 메모리수가 정해진 배열이기 떄문에 그런건가? 아직 정확하게 이해가지않음.
int BubbleSort(int array[][2], int len);
int SelectionSort(int array[][2], int len);
int Check(int a[][2],int order[][36],int n);

int main()
{
    int i,j,n;
    scanf("%d%*c",&n);

    int a[36][2], copy[36][2], order[37][36], count[37] = {0}; // 37인 이유는 1~36의 숫자를 그래도 index로 사용할 것이기 떄문.
    for (i=0;i<n;i++)
    {
        scanf("%c%d%*c",&a[i][1],&a[i][0]);
        order[a[i][0]][count[a[i][0]]] = a[i][1];
        count[a[i][0]]++;
    }
    memcpy(copy,a,sizeof(a));
    int cntb,cnts;
    cntb = BubbleSort(a,n);
    for (i=0;i<n;i++)
    {
        printf("%c%d",a[i][1],a[i][0]);
        if (i < n-1) printf(" ");
    }
    printf("\n");
    if (Check(a,order,n) == -1) printf("Not stable\n");
    else printf("Stable\n");

    memcpy(a,copy,sizeof(copy));
    cnts = SelectionSort(a,n);
    for (i=0;i<n;i++)
    {
        printf("%c%d",a[i][1],a[i][0]);
        if (i<n-1) printf(" ");
    }
    printf("\n");
    if (Check(a,order,n) == -1) printf("Not stable\n");
    else printf("Stable\n");

    return 0;
}

int BubbleSort(int array[][2], int len)
{
    int i,j,cnt;
    int tmp;
    cnt = 0;
    for (i=0;i<len;i++)
    {
        for (j=(len-1);j>i;j--)
        {
            if (array[j][0] < array[j-1][0])
                {
        tmp = array[j-1][0];
        array[j-1][0] = array[j][0];
        array[j][0] = tmp;
        int buf;
        buf = array[j-1][1];
        array[j-1][1] = array[j][1];
        array[j][1] = buf;

                    cnt += 1;
                }
        }
    }
    return cnt;
}
int SelectionSort(int array[][2], int len)
{
    int i,j,tmp,cnt,mini;
    cnt = 0;
    for (i=0;i<len;i++)
    {
        mini = i;
        for (j=i;j<len;j++)
        {
            if (array[j][0] < array[mini][0])
            {
                mini = j;
            }
        }
        tmp = array[i][0];
        array[i][0] = array[mini][0];
        array[mini][0] = tmp;
        int buf;
        buf = array[i][1];
        array[i][1] = array[mini][1];
        array[mini][1] = buf;

        if (i != mini) cnt += 1;
    }
    return cnt;
}

int Check(int a[][2],int order[][36],int n)
{
    int count[37] = {0};
    int i,j;
    for (i=0;i<n;i++)
    {
        if (a[i][1] != order[a[i][0]][count[a[i][0]]]) return -1;
        count[a[i][0]]++;
    }
    return 0;
}
