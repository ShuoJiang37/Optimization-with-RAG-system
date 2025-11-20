#include<stdio.h>
#include<string.h>
struct{char s;int n;}C[40],T[40],P;
int N,i,j;

void B()
{
	int i,j;
	for(i=0;i<N;i++)
		for(j=N-1;j>=0;j--)
		{
			if(C[j].n<C[j-1].n)
			{
				P=C[j];
				C[j]=C[j-1];
				C[j-1]=P;
			}
		}
}

void S()
{
	int i,j,p;
	for(i=0;i<N;i++)
	{
		p=i;
		for(j=i;j<N;j++)
			if(T[j].n<T[p].n)
				p=j;
		P=T[p];
		T[p]=T[i];
		T[i]=P;
	}
}

int main()
{
	scanf("%d\n",&N);
	for(i=0;i<N;i++)
		scanf("%c%1d%*c",&C[i].s,&C[i].n);
	memcpy(T,C,sizeof(C));
	B();S();
	for(i=0;i<N;i++)
		printf("%c%d%s",C[i].s,C[i].n,i==N-1?"\n":" ");
	puts("Stable");
	for(i=0;i<N;i++)
		printf("%c%d%s",T[i].s,T[i].n,i==N-1?"\n":" ");
	puts(memcmp(C,T,sizeof(C))==0?"Stable":"Not stable");
	return 0;
}

