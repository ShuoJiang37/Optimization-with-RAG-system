#include<stdio.h>

struct Cards  //構造体
{
	char mark;
	int num;
} temp;


int main(void)
{
	int N;
	scanf("%d",&N);
	struct Cards array_b[N],array_s[N];
	int i,cnt1=0;
	for(i=0;i<N;i++)    			//入力
	{
		scanf(" %c%d",&array_b[i].mark,&array_b[i].num);
		array_s[i]=array_b[i];
	}
	
	for(int t=0;t<N-1;t++)		//バブルソート
	{
		for(int i=N-1;i>0;i--)
		{
			if(array_b[i].num<array_b[i-1].num)
			{
				temp=array_b[i];
				array_b[i]=array_b[i-1];
				array_b[i-1]=temp;
			}
	 	}
	}
	
	for(int i=0;i<N;i++)		//バブルソート表示
	{
		printf("%c%d",array_b[i].mark,array_b[i].num);
		if(i<N-1)
		{
			printf(" ");
		}
	}
	printf("\n");
	
	
	printf("Stable\n");

								//選択ソート
	for(int i=0;i<N-1;i++)
	{
		int minj=i;
		for(int j=i;j<N;j++)
		{	
			if(array_s[minj].num>array_s[j].num)
			{
				minj=j;
			}
		}
		temp=array_s[i];
		array_s[i]=array_s[minj];
		array_s[minj]=temp;
		
	}
	
	for(int i=0;i<N;i++)		//選択ソート表示
	{
		printf("%c%d",array_s[i].mark,array_s[i].num);
		if(i<N-1)
		{
			printf(" ");
		}
	}
	printf("\n");
	
	for(int i=0;i<N;i++)			//判定
	{
		if(array_b[i].mark!=array_s[i].mark)
		{
			printf("Not stable\n");
			cnt1++;
			break;
		}
	}
	if(cnt1==0)
	{
		printf("Stable\n");
	}

	return 0;
}









	
		
	
