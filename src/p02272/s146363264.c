#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 2000000000
int count;
void Merge(int arr[],int left,int mid,int right)
{
	int l=mid-left,r=right-mid,i,j,k;
	int *A1=(int *)malloc(sizeof(int)*(l+1));
	int *A2=(int *)malloc(sizeof(int)*(r+1));
	for(i=0;i<l;i++)
	A1[i]=arr[left+i];
	for(i=0;i<r;i++)
	A2[i]=arr[mid+i];
	A1[l]=A2[r]=MAXSIZE;
	i=j=0;
	for(k=left;k<right;k++)	
	{
	if(A1[i]>A2[j])
	arr[k]=A2[j++];
	else
	arr[k]=A1[i++];
	count++;
	}
	
	
}
void MergeSort(int arr[],int left,int right)
{
	if(left+1<right)
	{
		int mid=(left+right)/2;
		MergeSort(arr,left,mid);
		MergeSort(arr,mid,right);
		Merge(arr,left,mid,right);
	}	
}
int main(int argc, char *argv[])
{
	int arr[500000];
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	MergeSort(arr,0,n);
	for(i=0;i<n;i++)
	if(i+1==n)
	printf("%d\n",arr[i]);
	else
	printf("%d ",arr[i]);
	printf("%d\n",count);
}
