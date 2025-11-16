#include<stdio.h>
void swap(int *xp,int *yp);
int selectionsort(int a[],int n);
void printArray(int arr[], int size);
int main()
{
    int a[110];
    int  n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    j=selectionsort(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
        if(i<n-1)
            printf(" ");

    }
    printf("\n%d\n",j);
    return 0;


}
int selectionsort(int a[],int n)
{
    int l,p,q,min,c=0;
    for(l=0;l<n-1;l++)
    {   int flag=0;
        min=l;
        for(p=l+1;p<n;p++)
        {
        if(a[p]<a[min])
        {
            min=p;
            flag=1;
        }
        }
         if(flag==1)
            {
            swap(&a[min],&a[l]);
            c++;
            }
    }
    return c;

}
void swap(int *xp ,int *yp)
{
    int  temp=*xp;
    *xp=*yp;
    *yp=temp;
}