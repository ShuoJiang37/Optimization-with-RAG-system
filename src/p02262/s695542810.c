#include<stdio.h>
#define N 1000000
#define MAXM 100
#define SPAN 4
int insertionSort(int[],int,int);
void shellSort(int[],int);
void printArray(int[],int);
int main(void)
{
  int i,n;//counter
  int arr[N];//array
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&arr[i]);
  shellSort(arr,n);
  return 0;
}
int insertionSort(int A[],int n,int g)
{
  int i,j;//counter
  int v;
  int cnt=0;
  for(i=g;i<n;i++)
    {
      v=A[i];
      j=i-g;
      while(j>=0&&A[j]>v)
        {
          A[j+g]=A[j];
          j=j-g;
          cnt++;
        }
      A[j+g]=v;
    }
  return cnt;
}
void shellSort(int A[],int n)
{
  int i;//counter
  int pow4=1;
  int cnt=0;
  int m;
  int G[MAXM];
  for(m=1;;m++)
    {
      pow4*=SPAN;
      if(pow4>n) break;
    }
  for(i=0;i<m;i++)
    {
      pow4/=SPAN;
      G[i]=pow4;
    }
  for(i=0;i<m;i++) cnt+=insertionSort(A,n,G[i]);
  //output is from here
  printf("%d\n",m);
  printArray(G,m);
  printf("%d\n",cnt);
  for(i=0;i<n;i++) printf("%d\n",A[i]);
}
void printArray(int arr[],int n)
{
  int i;
  for(i=0;i<n;i++)
    {
      if(i>0) printf(" ");
      printf("%d",arr[i]);
    }
  printf("\n");
}
