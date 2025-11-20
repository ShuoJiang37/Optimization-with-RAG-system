#include <stdio.h>
int input[101]={};
int n;

int main(void)
{
    scanf("%d",&n);
    int i,j;

    for(i=0;i<n;i++)
    {
        scanf("%d",&input[i]);
    }

    int flag=1;
    int count=0,compare=0;

    for(i=0;i<n;i++)
    {
        for(j=1;j<n-i;j++)
        {
            compare++;
            if(input[j-1]>input[j])
            {
                int c;
                c=input[j-1];
                input[j-1]=input[j];
                input[j]=c;
                count++;
            }
        }
    }

//    printf("%d\n%d\n",compare,count);
    for(i=0;i<n;i++)
    {
        printf("%d",input[i]);
        if(i<n-1)printf(" ");
    }
    printf("\n%d\n",count);


    return 0;
}