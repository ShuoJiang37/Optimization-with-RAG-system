#include<stdio.h>

typedef struct card
{
	char a;
	int b;
}card_in;

void BubbleSort(card_in C[],int N)
{
	int i,j;
	card_in temp[N];
	
	for(i=0;i<N;i++)
	{
		for(j=N-1;j>=i+1;j--)
		{
			if(C[j].b<C[j-1].b)
			{
				temp[j]=C[j];
				C[j]=C[j-1];
				C[j-1]=temp[j];
			}
		}
	}
}

void SelectionSort(card_in C[],int N)
{
	int i,minj,j;
	card_in temp[N];
	
	for(i=0;i<N;i++)
	{
		minj=i;
		for(j=i;j<N;j++)
		{
			if(C[j].b<C[minj].b)
			{
				minj=j;
			}
		}
		temp[i]=C[i];
		C[i]=C[minj];
		C[minj]=temp[i];
	}
}

void isStable(card_in in[],card_in out[],int N)
{
	int i,j,a,b;
	int c=0;
	
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			for(a=0;a<N;a++)
			{
				for(b=a+1;b<N;b++)
				{
					if((in[i].b==in[j].b)&&(in[i].a==out[b].a)&&(in[i].b==out[b].b)&&(in[j].a==out[a].a)&&(in[j].b==out[a].b))
					{
					    if(c>=1)
						{
							break;
						}
						 printf("Not stable\n");
						c++;
						break;
					}
				}
			}
		}
	}
	if(c==0) printf("Stable\n");
}

int main(void)
{
	int n;
	int i;
	
	scanf("%d",&n);
	
	card_in C1[n];
	card_in C2[n];
	card_in C3[n];
	
	for(i=0;i<n;i++)
	{
		scanf(" %c%d",&C1[i].a,&C1[i].b);
	}
	for(i=0;i<n;i++)
	{
		C2[i]=C1[i];
		C3[i]=C1[i];
	}
	
	BubbleSort(C1,n);
	for(i=0;i<n;i++)
	{
		if(i!=0)
		{
			printf(" ");
		}
		printf("%c%d",C1[i].a,C1[i].b);
	}printf("\n");
	
	isStable(C1,C3,n);
	
	SelectionSort(C2,n);
	for(i=0;i<n;i++)
	{
		if(i!=0)
		{
			printf(" ");
		}
		printf("%c%d",C2[i].a,C2[i].b);
	}printf("\n");
		
	isStable(C2,C3,n);
	
	return 0;
}
