#include<stdio.h>
int main()
{
    struct card
    {
        char suit;
        int value;
    }in[36], out1[36], out2[36], temp;
    int n, i, j, min;
    char ch;

    scanf("%d", &n);
    ch=getchar();
    for(i=0; i<n; i++)
    {
        scanf("%c%d", &in[i].suit, &in[i].value);
		ch=getchar();
        out1[i]=out2[i]=in[i];
    }

    //BubbleSort
    for(i=0; i<n; i++)
    {
        for(j=n-1; j>=i+1; j--)
            if(out1[j].value<out1[j-1].value)
            {
                temp=out1[j];
                out1[j]=out1[j-1];
                out1[j-1]=temp;
            }
    }
    for(i=0; i<n-1; i++)
        printf("%c%d ", out1[i].suit, out1[i].value);
    printf("%c%d\nStable\n", out1[i].suit, out1[i].value);

    //SelectionSort
    for(i=0; i<n-1; i++)
    {
        min=i;
        for(j=i+1; j<n; j++)
            if(out2[j].value<out2[min].value) min=j;
        if(min!=i)
        {
            temp=out2[i];
            out2[i]=out2[min];
            out2[min]=temp;
        }
    }
    for(i=0; i<n-1; i++)
        printf("%c%d ", out2[i].suit, out2[i].value);
    printf("%c%d\n", out2[i].suit, out2[i].value);
    for(i=0; i<n; i++)
        if(out1[i].suit != out2[i].suit)
        {
            printf("Not stable\n");
            break;
        }
    if(i==n) printf("Stable\n");

    return 0;
}