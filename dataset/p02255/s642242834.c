#include<stdio.h>
#define N 100

void output(int *,int);
void insertionSort(int *,int);

int main()
{
  int n,i;
  int a[N];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  output(a,n);
  insertionSort(a,n);

  return 0;
}

void output(int *a,int n)
{
  int i;
  for(i=0;i<n-1;i++){
      printf("%d ",a[i]);
    }
    printf("%d\n",a[n-1]);
}
void insertionSort(int *a,int n)
{
  int i,j,v;

  for(i=1;i<n;i++){
    v = a[i];
    j = i - 1;

    while( j >= 0 && a[j] > v ){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    
    output(a,n);
  }
}
      

    

