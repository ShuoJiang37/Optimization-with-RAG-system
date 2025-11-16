#include<stdio.h>

typedef struct {
	char mark;
	int number;
} Card;

void print(Card C[], int N)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("%c%d",C[i].mark,C[i].number);
		if(i != N-1)
		{
			printf(" ");
		}
		else
		{
			printf("\n");
		}
	} 
}

void BubbleSort(Card C[],int N)
{
	
	Card tmp;
	
	for(int i=0;i<N;i++)
	{
		for(int j=N-1;j>i;j--)
		{
			
			if(C[j].number <C[j-1].number)
			{
				tmp = C[j];
				C[j] = C[j-1];
				C[j-1] = tmp;
				/*print(C,N);*/
			}
		}
	}
	print(C,N);
	printf("Stable\n");
}
	
void SelectionSort(Card C[], int N)
{
	int min;
	Card tmp;
		
	for(int i=0;i<N;i++)
	 {
 		 min = i;
 		 for(int j=i;j<N;j++)
	     {
			if(C[j].number < C[min].number)
			{
				min = j;
			}
		 } 
		
		
			tmp =C[i];
			C[i]=C[min];
			C[min]=tmp;
	 }
	print(C,N);
	
}


int main(void)
{
	int N,i;
	int flag = 1;
	Card C[36],C2[36];
	
	scanf("%d",&N);
	
	/*printf("N=%d\n",N);*/
		for(i=0;i<N;i++)
		{
			scanf(" %c%d",&C[i].mark,&C[i].number);
			/*printf("i=%d\n",i);
			printf("mark0=%c\n",C[i].mark[0]);
			printf("mark1=%c\n",C[i].mark[1]);*/
			/*C[i].number=C[i].mark[1]-'0';*/
			C2[i]=C[i];
			//printf(" %s", C2[i].mark);
			//printf("%d", C2[i].number);
		}
	
	//printf("\n");
	
	/*
		print(C,N);
	printf("\n");*/
		BubbleSort(C,N);
		SelectionSort(C2,N);
		
		for(i=0;i<N;i++)
		{
			if(C[i].mark != C2[i].mark)
			{
				flag = 0;
				break;
			}
		}
		
		if(flag)
		{
			printf("Stable\n");
		}
		else 
		{
			printf("Not stable\n");
		}
	
	return 0;
}
