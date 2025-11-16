#include<math.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
struct card
{
	char suit;
	int value;
};
int n;
struct card a[110],A[110],C[110];
int isstable()
{
	int i;
	for(i=1;i<=n;i++)
		if(a[i].suit!=A[i].suit)
			return 1;
	return 0;
}
struct card a[110],A[110],C[110];
void swap(int x,int y,char z)
{
	struct card t;
	if(z=='a')
	{
		t=a[x];
		a[x]=a[y];
		a[y]=t;
	}
	if(z=='A')
	{
		t=A[x];
		A[x]=A[y];
		A[y]=t;
	}
	return;
}
void bubblesort()
{
	int i,j;
	for(i=1;i<=n-1;i++)
		for(j=n;j>=i+1;j--)
			if(a[j].value<a[j-1].value)
				swap(j-1,j,'a');
	return;
}
void selectionsort()
{
	int i,j,min;
	for(i=1;i<=n;i++)
	{
		min=i;
		for(j=i;j<=n;j++)
			if(A[j].value<A[min].value)
				min=j;
		if(i!=min)
			swap(i,min,'A');
	}
	return;
}
int main()
{
	int i;
	 
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		getchar();
		scanf("%c%d",&a[i].suit,&a[i].value);
		A[i]=a[i];
		C[i]=a[i];
	}

	bubblesort();
	for(i=1;i<=n-1;i++)
		printf("%c%d ",a[i].suit,a[i].value);
	printf("%c%d\n",a[i].suit,a[i].value);
	printf("Stable\n");

	selectionsort();
	for(i=1;i<=n-1;i++)
		printf("%c%d ",A[i].suit,A[i].value);
	printf("%c%d\n",A[i].suit,A[i].value);
	if(isstable())
		printf("Not stable\n");
	else
		printf("Stable\n");
	return 0;
}
