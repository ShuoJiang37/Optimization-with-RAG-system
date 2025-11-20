#include <stdio.h>
#include <time.h>
struct card
{
    char x;
    int num;
};
typedef struct card card;
void SelectionSort(card *p,int n);
void BubbleSort(card *p,int n);
int isStable(card *p,card *q,int n);
int main ()
{
    int number,i;
    card p[100],r[100],q[100];
    scanf("%d",&number);
    for(i = 0; i < number ; i++)
    {
        scanf(" %c%d",&p[i].x,&p[i].num);
    }
    for(i = 0;i < number;i++)
    {
        r[i] = p[i];
        q[i] = p[i];
    }
    BubbleSort(p,number);
    printf("Stable\n");
    SelectionSort(r,number);
    if(isStable(q,r,number))
    printf("Stable\n");
    else
    printf("Not stable\n");

    return 0;
}
void BubbleSort(card *p,int n)
{
    int i,j;
    card temp;
    for(i = 0;i < n - 1;i++)
    {
        for(j = n - 1;j > i;j--)
        {
            if(p[j].num<p[j-1].num)
            {
                temp = p[j];
                p[j] = p[j-1];
                p[j-1] = temp;

            }
        }
    }
    for(i = 0;i < n;i++)
    {
        if(i>0)printf(" ");
        printf("%c%d",p[i].x,p[i].num);
    }
    printf("\n");
}
void SelectionSort(card *p,int n)
{
    int i,j,k;
    card temp;
    for(i = 0;i < n - 1;i++)
    {
        k = i;
        for(j = i;j < n;j++)
        {
            if(p[j].num<p[k].num)
                k = j;
        }
        if(k!=i)
        {
            temp = p[k];
            p[k] = p[i];
            p[i] = temp;
        }
    }
    for(i = 0;i < n;i++)
    {
        if(i>0)printf(" ");
        printf("%c%d",p[i].x,p[i].num);
    }
    printf("\n");
}
int isStable(card *p,card *q,int n)
{


    int i, j ,a ,b;
     for(i=0;i < n;i++)
        for(j = i+1;j < n;j++)
            for(a = 0;a < n;a++)
                for(b = a+1;b < n;b++)
                if(p[i].num == p[j].num&&p[i].x==q[b].x&&p[j].x==q[a].x&&p[i].num==q[b].num&&p[i].num==q[b].num)
                 return 0;
    return 1;

}

