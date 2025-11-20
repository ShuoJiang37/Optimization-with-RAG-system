#include<stdio.h>

struct Pai
{
	char h;
	int A;
}; 

void BubbleSort(struct Pai A[],int N);
void SelectionSort(struct Pai A[],int N);
void Show(struct Pai A[],int N);
int isStable(struct Pai pai1[],struct Pai pai2[],int N);

int isStable(struct Pai pai1[],struct Pai pai2[],int N)	//利用冒泡排序恒为稳定可得选择排序是否稳定 
{
	int i,flag=1;
	for(i=0;i<N;i++)
		if(pai1[i].h!=pai2[i].h)
		{
			flag=0;
			break;
		}
	return flag;
}

void BubbleSort(struct Pai A[],int N)
{
	int i,j; 
	for(i=0;i<N;i++)
		for(j=N-1;j>=i+1;j--)
			if(A[j].A<A[j-1].A)
			{
				struct Pai temp;
				temp=A[j];
				A[j]=A[j-1];
				A[j-1]=temp;
			} 
}

void SelectionSort(struct Pai A[],int N)
{
	int i,minj,j;
	for(i=0;i<N;i++)
	{
		minj=i;
		for(j=i+1;j<N;j++)
			if(A[j].A<A[minj].A)
				minj=j;
		if(minj!=i)
		{			
			struct Pai temp;
			temp=A[i];
			A[i]=A[minj];
			A[minj]=temp;	
		}			
	}
}

void Show(struct Pai A[],int N)
{
	int i;
	for(i=0;i<N;i++)
	{
		if(i>0)
		    printf(" ");
		printf("%c",A[i].h);    
		printf("%d",A[i].A);
	}
	printf("\n");
}

int main()
{
	struct Pai pai1[50],pai2[50];
	int N,i;
	scanf("%d",&N); 
	for(i=0;i<N;i++)
	{
		getchar(); 
		scanf("%c",&pai1[i].h);
		scanf("%d",&pai1[i].A);
		pai2[i].h=pai1[i].h;
		pai2[i].A=pai1[i].A;
	}
	BubbleSort(pai1,N);	
	Show(pai1,N);
	printf("Stable\n");		
	SelectionSort(pai2,N);
	Show(pai2,N);
	if(isStable(pai1,pai2,N))
		printf("Stable\n");
	else
		printf("Not stable\n");	
	return 0;
} 
