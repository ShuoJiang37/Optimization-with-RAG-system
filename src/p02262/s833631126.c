#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[1000010],n,cnt=0,G[110],p=1;
void createG()
{
	int i,h=1;
	G[1]=1;
	for(i=2;i<=100;i++)
	{
		h=h*3+1;
		if(h<=n)
			G[i]=h;
		else
			break;
		p++;
	}
	return;
}
void output()
{
	int i;
	printf("%d\n",p);
	for(i=p;i>=2;i--)
		printf("%d ",G[i]);
	printf("%d\n",G[1]);
	printf("%d\n",cnt);
	for(i=1;i<=n;i++)
		printf("%d\n",a[i]);
	return;
}
void shellsort(int g)
{
	int v,i,j;
	for(i=g+1;i<=n;i++)
	{
		v=a[i];
		j=i-g;
		while(j>=1 && a[j]>v)
		{
			a[j+g]=a[j];
			j-=g;
			cnt++;
		}
		a[j+g]=v;
	}
	return;
}
int main()
{
	int i;
	scanf("%d",&n);
	//我喜欢从1开始计数，就把a[0]给废掉了
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	createG();
	for(i=p;i>=1;i--)
		shellsort(G[i]);

	output();
	return 0;
}
