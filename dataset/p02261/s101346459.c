//2020 4.17

#include <stdio.h>
#include <string.h>
#define N 36

typedef struct{
    char mark;
    int num;
}card;

void BubbleSort(card *,int);
void SelectionSort(card *,int);
void cmp(card *,card *,int);

int main()
{
    int i,j=0;
    int a;
    card A[N],B[N];
    char b; //空白を入れるためだけのもの

    scanf("%d",&a);
    scanf("%c",&b); //aの後の改行も文字に含まれるのでscanf。
    for(i=0;i<a;i++)
    {
    scanf("%c%d",&A[i].mark,&A[i].num);
    scanf("%c",&b);
    }

       for(i=0;i<a;i++)
    {
        B[i]=A[i];
    }

    BubbleSort(A,a);
    
    SelectionSort(B,a);

    cmp(A,B,a);

    return 0;
}

void BubbleSort(card *A,int a)
{
    int cnt1=0,cnt=0;
    card temp;
    int i,j;
 while(1)
    {
        j=a-1;
        if(cnt1==j) break;
        while(j>=1)
        {
        if( A[j].num < A[j-1].num)
        {
            temp = A[j];
            A[j] = A[j-1];
            A[j-1] = temp;
        }
        j--;
        }
        cnt1++;
    }
    for(i=0;i<a;i++)
    {
        if(i==0) printf("%c%d",A[i].mark,A[i].num);
        else printf(" %c%d",A[i].mark,A[i].num);
    }
    printf("\nStable");
    printf("\n");
return;
}

void SelectionSort(card *B,int a)
{
    int i,j;
    int min,temp,flag=0;
    card temp2;
    
    for(i=0;i<a;i++)
    {
        min = B[i].num;
    for(j=i+1;j<a;j++)
    {
        if(min>B[j].num) {min = B[j].num; temp = j; flag=1;}
    }

    if(flag==1)
    {
    temp2 = B[i];
    B[i].num = min;
    B[i].mark = B[temp].mark;
    B[temp] = temp2;
    flag=0;
    }
    }
    for(i=0;i<a;i++)
    {
        if(i==0) printf("%c%d",B[i].mark,B[i].num);
        else printf(" %c%d",B[i].mark,B[i].num);
    }
    printf("\n");
    return;
}

void cmp(card *A,card *B,int a)
{
    int res,flag=0;
    int i;
    for(i=0;i<a;i++)
    {
    if(A[i].mark==B[i].mark) flag=0;
    else {flag=1; break;}
    }
    if(flag==1) {printf("Not stable\n");
    }else {printf("Stable\n");}
    return;
}
