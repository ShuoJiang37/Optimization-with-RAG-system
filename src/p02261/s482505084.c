#include<stdio.h>
struct card
{
    char suit;
    int num;
    int idx;
};
typedef struct card Card;

void bubblesort(Card C[], int N);
void selectionsort(Card C[], int N);

int main()
{
    int N,i;
    Card C1[36], C2[36];

    scanf("%d",&N);
    for(i=0; i<N; i++)
    {
        scanf(" %c%d", &C1[i].suit, &C1[i].num);
        C1[i].idx=i;
        C2[i]=C1[i];
    }
    bubblesort(C1, N);
    selectionsort(C2, N);
    return 0;
}

void bubblesort(Card C[], int N)
{
    Card temp;
    int stable,i,j;
    for(i=0; i < N-1; i++)
    {
        for(j=N-1; j>i; j--)
        {
            if(C[j].num<C[j-1].num)
            {
                temp=C[j];
                C[j]=C[j-1];
                C[j-1]=temp;
            }
        }
    }
    stable=1;
    for(i=0; i<N; i++)
    {
        printf("%c%d%c",C[i].suit,C[i].num," \n"[i==N-1]);
        if(i>0 && C[i].num==C[i-1].num && C[i].idx<C[i-1].idx)
        {
            stable=0;
        }
    }
    puts(stable ? "Stable" : "Not stable");
}
void selectionsort(Card C[], int N)
{
    Card temp;
    int mini;
    int stable;
    int i, j;
    for(i = 0; i < N; i++)
    {
        mini = i;
        for(j = i; j < N; j++)
        {
            if(C[j].num < C[mini].num)
                mini = j;
        }
        temp = C[i];
        C[i] = C[mini];
        C[mini] = temp;
    }
    stable = 1;
    for(i = 0; i < N; i++)
    {
        printf("%c%d%c", C[i].suit, C[i].num, " \n"[i==N-1]);
        if(i > 0 && C[i].num == C[i-1].num && C[i].idx < C[i-1].idx)
            stable = 0;
    }
    puts(stable ? "Stable" : "Not stable");
}

