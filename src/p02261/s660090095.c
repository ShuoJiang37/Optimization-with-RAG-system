#include <stdio.h>
typedef struct
{
    char *suit;
	int value;
}card;
int main (void)
{
	int i,j,k,n,m,count;
	scanf("%d",&n);
	card A[36], B[36];
	card z;
	
	card y;
	j=n;
	for(i=0;i<n;i++)
	{
		scanf(" %c%d",&A[i].suit, &A[i].value);
		B[i] =A[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>=i+1;j--)
		{
			if(A[j].value<A[j-1].value)
			{
				z=A[j-1];
				A[j-1]=A[j];
				A[j]=z;
			}
		}
	}
	for(k=0;k<n;k++)
			{
				printf("%c%d",A[k].suit, A[k].value);
				if(k==n-1)
				{
					printf("\n");
					break;
				}
				printf(" ");
			}
		printf("Stable\n");

for(i=0;i<n;i++)
	{
		m=i;
		for(j=i;j<n;j++)
		{
			if(B[j].value<B[m].value)
			{
				m=j;
			}
		}
		if(B[i].value!=B[m].value)
		{
		y=B[i];
		B[i]=B[m];
		B[m]=y;
		}
	}
	for(k=0;k<n;k++)
		{
			printf("%c%d",B[k].suit,B[k].value);
			if(k==n-1)
			{
				printf("\n");
				break;
			}
			printf(" ");
		}
	for(k=0;k<n;k++)	
		{
		if(A[k].suit==B[k].suit)
			{
				count++;
			}
		}
	if(count==k)
	{
		printf("Stable\n");
	}
	else
	{
		printf("Not stable\n");
	}

}

