#include<stdio.h>
#include<string.h>
typedef struct{char c;int n;} card;
card B[36],S[36];
int bubble(card A[36],int N)
{
	int i,j,c=0,flag=1;
	card stock;
	while(flag)
	{
		flag=0;
		for(i=N-1;i>0;i--)
		{
			if(A[i].n<A[i-1].n)
			{
				stock=A[i];
				A[i]=A[i-1];
				A[i-1]=stock;
				flag=1;
				c++;
			}		
		}
	}
	return c;
}
int selection(card A[36],int N)
{
	int i,j,d,minj,c=0;
	card stock;
	for(i=0;i<N;i++)
	{
		minj=i;
		for(d=0,j=i;j<N;j++)
		{
			if(A[j].n<A[minj].n){minj=j;d=1;}
		}
		stock=A[i];
		A[i]=A[minj];
		A[minj]=stock;
		if(d)c++;
	}
	return c;
}
int main(void)
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf(" %c%d",&B[i].c,&B[i].n);}
	memcpy(S,B,sizeof(B));
	bubble(B,n);
	selection(S,n);
	for(i=0;i<n;i++)
	{
		printf("%c%d",B[i].c,B[i].n);
		if(i<n-1){printf(" ");}
		else{printf("\n");}
	}
	printf("Stable\n");
	for(i=0;i<n;i++)
	{
		printf("%c%d",S[i].c,S[i].n);
		if(i<n-1){printf(" ");}
		else{printf("\n");}
	}
	if(!memcmp(B,S,sizeof(B))){printf("Stable\n");}
	else{printf("Not stable\n");}

	return 0;
}