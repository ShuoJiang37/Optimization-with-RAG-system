#include <stdio.h>
#define N 36
typedef struct
{
	int value;
	char mark;	
}card;

void BubbleSort(card *c,int n)
{
	int i=n-1,j,flag=1;
	card cc;
	while(i>0&&flag==1)	
	{
		flag=0;
		for(j=0;j<i;j++)
		if(c[j].value>c[j+1].value)
		{
			cc=c[j];
			c[j]=c[j+1];
			c[j+1]=cc;
			flag=1;
		}
	}
	for(i=0;i<n;i++)
	{
	printf("%c%d",c[i].mark,c[i].value);	
	if(i+1!=n)
	printf(" ");
	}
	printf("\nStable\n");	
}

void SelectionSort(card *c,int n)
{
	int i,j,min;
	card cc;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		if(c[j].value<c[min].value)
		min=j;
		if(min!=i)
		{
			cc=c[min];
			c[min]=c[i];
			c[i]=cc;
		}
	}
	for(i=0;i<n;i++)
	{
	printf("%c%d",c[i].mark,c[i].value);	
	if(i+1!=n)
	printf(" ");
	}
}

int main(int argc, char *argv[])
{
	card c1[N],c2[N];
	int n,i,flag=1;
	char ch;
	scanf("%d%c",&n,&ch);
	for(i=0;i<n;i++)
	scanf("%c%d%c",&c1[i].mark,&c1[i].value,&ch);
	for(i=0;i<n;i++)
	c2[i]=c1[i];
	BubbleSort(c1,n);
	SelectionSort(c2,n);
	/***********************/
	for(i=0;i<n;i++)
	if(c1[i].mark!=c2[i].mark)
	{
		flag=0;
		break;
	}
	if(flag==0)
	printf("\nNot stable\n");
	else
	printf("\nStable\n");
	return 0;
}