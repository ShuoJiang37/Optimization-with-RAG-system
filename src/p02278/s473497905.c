#include<stdio.h>
#include<stdlib.h>
#define CHECK printf("check\n");
void countingSort(int*,int*,int,int);
int countMinimumCost(int*,int*,int);
void printArray(int*,int);
int main(void)
{
  int i;//counter
  int n;//length of array
  int wholeMax=0;//maximum value of array
  int *arr;//array sorted by minimum cost sort
  int *sortedArr;//array sorted by counting sort
  int cost;
  scanf("%d",&n);
  arr=(int*)malloc(sizeof(int)*n);
  sortedArr=(int*)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&arr[i]);
      if(wholeMax<arr[i]) wholeMax=arr[i];
    }
  countingSort(arr,sortedArr,n,wholeMax);
  cost=countMinimumCost(arr,sortedArr,n);
  printf("%d\n",cost);
  return 0;
}
void countingSort(int *arr,int *sortedArr,int n,int max)
{
  int i;//counter
  int *countArr=(int*)malloc(sizeof(int)*(max+1));
  for(i=0;i<max+1;i++) countArr[i]=0;
  for(i=0;i<n;i++) countArr[arr[i]]++;
  for(i=1;i<max+1;i++) countArr[i]+=countArr[i-1];
  for(i=n-1;i>=0;i--)
    {
      sortedArr[countArr[arr[i]]-1]=arr[i];
      countArr[arr[i]]--;
    }
}
int countMinimumCost(int *arr,int *sortedArr,int n)
{
  int i;//counter
  int *isSortedArr=(int*)malloc(sizeof(int)*n);
  int begin;//first index that is not sorted yet
  int index;//index pointing now
  int count;//length of loop
  int sum;//sum of loop
  int min;//minimum value among loop
  int wholeMin;//minimum value in the array
  int currentCost[2];//2 pattern of sorting cost in one loop
  int sumCost=0;//sum of whole cost;
  //init isSortedArr
  wholeMin=arr[0];
  begin=n;
  for(i=0;i<n;i++)
    {
      if(arr[i]==sortedArr[i]) isSortedArr[i]=1;
      else isSortedArr[i]=0;
      if(wholeMin>arr[i]) wholeMin=arr[i];
      if(isSortedArr[i]==0&&begin==n) begin=i;
    }
  
  for(;begin<n;begin++)
    {
      if(isSortedArr[begin]==0)
	{
	  index=begin;
	  sum=0;
	  min=arr[index];
	  for(count=1;;count++)
	    {
	      isSortedArr[index]=1;
	      sum+=arr[index];
	      if(min>arr[index]) min=arr[index];
	      for(i=begin+1;i<n;i++)
		{
		  if(arr[i]==sortedArr[index]&&isSortedArr[i]==0) break;
		}
	      if(i==n) break;
	      index=i;
	    }
	  currentCost[0]=sum-min+min*(count-1);
	  currentCost[1]=(wholeMin+min)*2+(sum-min+wholeMin*(count-1));
	  if(currentCost[0]<currentCost[1]) sumCost+=currentCost[0];
	  else sumCost+=currentCost[1];
	}
    }
  return sumCost;
}
void printArray(int *arr,int n)
{
  int i;//counter
  for(i=0;i<n;i++)
    {
      if(i>0) printf(" ");
      printf("%d",arr[i]);
    }
  printf("\n");
}

