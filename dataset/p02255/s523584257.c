#include<stdio.h>

int main()
{
    int a,k;
    int b[100];

    while(scanf("%d\n",&a)!=EOF)
    {

        for(int i=0;i<a;i++)
        {
            scanf("%d",&b[i]);
            i<a-1 ? printf("%d ",b[i]):printf("%d\n",b[i]);
        }
        for(int j=1;j<=a-1;j++)
        {
            int key=b[j];
            k=j-1;
            while(k>=0&&b[k]>key)
            {
                b[k+1]=b[k];
                k--;
            }
            b[k+1]=key;
            for(int m=0;m<a;m++)
                m<a-1? printf("%d ",b[m]):printf("%d\n",b[m]);
        }
    }
        return 0;

}


