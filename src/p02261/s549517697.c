#include<stdio.h>
#include<string.h>


void swap(char c1[],char c2[])
{
	char tmp[3];
	strcpy(tmp,c1);
	strcpy(c1,c2);
	strcpy(c2,tmp);
}

void BubbleSort(char A[][3],int n)
{
	int i,j;

	for(i=0;i<n;i++)
	{
		for(j=n-1;j>=i+1;j--)
		{
			if(A[j][1]<A[j-1][1])
			{
				swap(A[j],A[j-1]);
			}
		}
	}
}

void SelectionSort(char A[][3],int n)
{
	int i,j,minj;
	for(i=0;i<n;i++)
	{
		minj=i;
		
		for(j=i;j<n;j++)
		{
			if(A[j][1]<A[minj][1])
			{
				minj=j;
				
			}
		}
	
	if(A[minj]!=A[i])
	{
		swap(A[i],A[minj]);
	}
}
}
int main(void)
{
	int i,n;
	int count=0;
	scanf("%d",&n);
	
	char A[n][3],B[n][3];
	
	for(i=0;i<n;i++)
	{
		scanf("%s",&A[i]);
		strcpy(B[i],A[i]);
	}
	
	BubbleSort(A,n);
	for(i=0;i<n-1;i++)
	{
		printf("%s ",A[i]);
	}

	printf("%s\n",A[n-1]);
	printf("Stable\n");
	
	SelectionSort(B,n);
	
	for(i=0;i<n-1;i++)
	{
		printf("%s ",B[i]);
	}
	printf("%s\n",B[n-1]);
	for(i=0;i<n;i++)
	{
		
		if(strcmp(A[i],B[i])==0)
		{
			count=0;
		}
		else
		{
			count=1;
			break;
		}
	}
		

	
	if(count==1)
	{
		printf("Not stable\n");
	}
	if(count==0)
	{
		printf("Stable\n");
	}
	
	return 0;
}
	
