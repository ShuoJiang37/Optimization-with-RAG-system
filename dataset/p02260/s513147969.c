#include<stdio.h>
int main(){
    int N,i,j,temp,mini;
    int c=0;
    scanf("%d",&N);
    int a[N];

    for(i=0;i<N;i++)
        scanf("%d",&a[i]);
 for(i=0;i<N;i++)
 {
           mini = i;
           if(mini != i)
           {

            temp=a[i];
            a[i]=a[mini];
            a[mini]=temp;

            c++;
           }
     for (j=i;j<N;j++)
     {
         if (a[j] < a[mini])
         {
            mini = j;
         }
     }
      if(mini != i)
           {

            temp=a[i];
            a[i]=a[mini];
            a[mini]=temp;

            c++;
           }
 }
   for(i=0;i<N-1;i++)
    printf("%d ",a[i]);
    printf("%d",a[N-1]);
    printf("\n%d\n",c);
    return 0;


}