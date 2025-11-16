#include<stdio.h>
struct Card
	{
		char suit;
		int value;
	};
int main()
{
	int n,i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
		struct Card a[100],b1[100],b2[100],c;
		for(i=0;i<n*2;i++)
		{
			a[i].suit=getchar();
			scanf("%d",&a[i].value);
		}
		for(i=0,j=1;i<n;i++,j+=2)
		{
			b1[i]=a[j];
			b2[i]=a[j];
		}
		for(i=0;i<n;i++)    //冒泡排序
		{
			for(j=n-1;j>i;j--)
			{
				if(b1[j].value<b1[j-1].value)
				{
					c=b1[j];
					b1[j]=b1[j-1];
					b1[j-1]=c;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			if(i==n-1)
			{
				printf("%c%d",b1[i].suit,b1[i].value);
			}
			else
			{
				printf("%c%d ",b1[i].suit,b1[i].value);
			}
		}
		printf("\n");
		printf("Stable\n");

		for(i=0;i<n;i++)    //选择排序
		{
			k=i;
			for(j=i;j<n;j++)
			{
				if(b2[j].value<b2[k].value)
				{
					k=j;
				}
			}
				c=b2[k];
				b2[k]=b2[i];
				b2[i]=c;
		}
		for(i=0;i<n;i++)
		{
			if(i==n-1)
			{
				printf("%c%d",b2[i].suit,b2[i].value);
			}
			else
			{
				printf("%c%d ",b2[i].suit,b2[i].value);
			}
		}
		printf("\n");
		for(i=0,k=0;i<n;i++)
		{
			if(b1[i].suit!=b2[i].suit)
			{
				k++;
			}
		}
		if(k>0)
		{
			printf("Not stable\n");
		}
		else
		{
			printf("Stable\n");
		}
	}
	return 0;
}


