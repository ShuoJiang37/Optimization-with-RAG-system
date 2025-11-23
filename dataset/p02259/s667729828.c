#include<stdio.h>
int main()
{
    int length,i,a[100],j,t,P;
    while(scanf("%d",&length)!=EOF)
    {
        P=0;
        for(i=0; i<length; i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0; i<length; i++)
        {
            for(j=0; j<length-i-1; j++)
            {

                if(a[j]>a[j+1])
                {
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                    P++;
                }
            }
        }
        for(i=0; i<length-1; i++)
        {
            printf("%d ",a[i]);
        }
        printf("%d\n",a[length-1]);
        printf("%d\n",P);
        return 0;

    }
}

