#include<stdio.h>

struct tramp
{
	char a[100];
	int value[100];
};

//static struct tramp A;
//static struct tramp B;

struct tramp bubbleSort(struct tramp A, int N);
struct tramp selectionSort(struct tramp A, int N);
int isStable(struct tramp in, struct tramp out, int N);

int main(void)
{
	int n=0, i=0, result=0;
	
	scanf("%d", &n);

	struct tramp A;	struct tramp B;
	struct tramp C; struct tramp D;
	
	for(i=0; i<n; i++)
	{
		scanf(" %c", &A.a[i]);
		scanf("%d", &A.value[i]);
	}
	
	for(i=0; i<n; i++)
	{
		B.a[i] = A.a[i];
		B.value[i] = A.value[i];
	}

	C = bubbleSort(A, n);
	
	printf("Stable\n");
	
	D = selectionSort(B, n);
	
	result = isStable(C, D, n);
	
	if(result == 1)
	{
		printf("Not stable\n");
	}
	else
	{
		printf("Stable\n");
	}
	
//	printf("\n");
	
	return 0;
}

struct tramp bubbleSort(struct tramp A, int N)
{
	int flag=1, i=0, j=0, temp1=0, temp2=0, c=0, c2=0;
	
	while(flag == 1)
	{
		flag = 0;
		
		for(j=N-1; j>=1; j--)
		{
			if(A.value[j] < A.value[j-1])
			{
				temp1 = A.a[j];
				temp2 = A.value[j];
				A.a[j] = A.a[j-1];
				A.value[j] = A.value[j-1];
				A.a[j-1] = temp1;
				A.value[j-1] = temp2;
				
				flag = 1;
				c++;
			}
			
			if(flag==1)
			{
				break;
			}
		}
	}
	
	for(i=0; i<N; i++)
	{
		if(i<N-1)
		{
			printf("%c%d ", A.a[i], A.value[i]);
		}
		else
		{
			printf("%c%d\n", A.a[i], A.value[i]);
		}
	}
	
	return A;
}

struct tramp selectionSort(struct tramp A, int N)
{
	int i=0, j=0, minj=0, temp1=0, temp2=0, c=0, c2=0;
	
	for(i=0; i<N; i++)
	{
		minj = i;
		
		for(j=i; j<N; j++)
		{
			if(A.value[j] < A.value[minj])
			{
				minj = j;
			}
		}
		
		if(i != minj)
		{
			c++;
		}
		temp1 = A.a[i];
		temp2 = A.value[i];
		A.a[i] = A.a[minj];
		A.value[i] = A.value[minj];
		A.a[minj] = temp1;
		A.value[minj] = temp2;
	}
	
	for(i=0; i<N; i++)
	{
		if(i<N-1)
		{
			printf("%c%d ", A.a[i], A.value[i]);
		}
		else
		{
			printf("%c%d\n", A.a[i], A.value[i]);
		}
	}
	
	return A;
}

int isStable(struct tramp in, struct tramp out, int N)
{
	int i, j;
	char a, b;

	for(i=0; i<N; i++)
	{
		if(in.a[i] != out.a[i])
		{
			return 1; //false
		}
	}
	
	return 0;	//true
}

