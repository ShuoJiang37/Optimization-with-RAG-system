#include<stdio.h>
int main()
{
     int n,i,j,cnt=0,temp;
     while(scanf("%d",&n)==1)
     {
          int array[n];
          for(i=0;i<n;i++)
               scanf("%d",&array[i]);
          for(i=0;i<n;i++)
               for(j=n-1;j>=i+1;j--)
          {
               if(array[j]<array[j-1])
               {
                    temp=array[j];
                    array[j]=array[j-1];
                    array[j-1]=temp;
          cnt++;
               }
          }
          for(i=0;i<n;i++)
               {
                    if(i>0)
                       printf(" ");
                    printf("%d",array[i]);
               }
               printf("\n");
               printf("%d\n",cnt);
          for(i=0;i<n;i++)
               array[i]=0;
               cnt=0;
     }
     return 0;
}