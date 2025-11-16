#include<stdio.h>
#include<string.h>
#define N 36
#define CHECKPOINT printf("CHECKPOINT\n");
void bubbleSort(int,char[],int[]);
void selectionSort(int,char[],int[]);
void printArray(int,char[],int[]);
int main(void)
{
  int i;//counter
  int n;//length of input
  char b1[N],s1[N];//array for bubble/selection sort
  int b2[N],s2[N];//array for bubble/selection sort
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf(" %c%d",&b1[i],&b2[i]);
      s1[i]=b1[i];
      s2[i]=b2[i];
    }
  bubbleSort(n,b1,b2);
  printArray(n,b1,b2);
  printf("Stable\n");
  selectionSort(n,s1,s2);
  printArray(n,s1,s2);
  for(i=0;i<n;i++)
    {
      if(s1[i]!=b1[i]||s2[i]!=b2[i]) break;
    }
  if(i==n) printf("Stable\n");
  else printf("Not stable\n");
  return 0;
}
void bubbleSort(int n,char a1[],int a2[])
{
  int i,j;//counter
  char tmpc;//temporary value for swapping
  int tmpi;
  for(i=0;i<n;i++)
    {
      for(j=n-1;j>i;j--)
	{
	  if(a2[j]<a2[j-1])
	    {
	      tmpc=a1[j];
	      a1[j]=a1[j-1];
	      a1[j-1]=tmpc;
	      tmpi=a2[j];
	      a2[j]=a2[j-1];
	      a2[j-1]=tmpi;
	    }
	}
    }
}
void selectionSort(int n,char a1[],int a2[])
{
  int i,j;//counter
  int mini;//valuable for min. index
  char tmpc;//temporary value for swapping
  int tmpi;
  for(i=0;i<n;i++)
    {
      mini=i;
      for(j=i+1;j<n;j++)
	{
	  if(a2[j]<a2[mini]) mini=j;
	}
      tmpc=a1[i];
      a1[i]=a1[mini];
      a1[mini]=tmpc;
      tmpi=a2[i];
      a2[i]=a2[mini];
      a2[mini]=tmpi;
    }
}
void printArray(int n,char a1[],int a2[])
{
  int i;//counter
  for(i=0;i<n;i++)
    {
      if(i>0) printf(" ");
      printf("%c%d",a1[i],a2[i]);
    }
  printf("\n");
}

