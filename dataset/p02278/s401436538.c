#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define MAX 2010
#define Ai 10000
int A[MAX],B[MAX],C[Ai+10]={0},book[MAX];
int n;
void swap(int x,int y)
{
	int t=A[x];
	A[x]=A[y];
	A[y]=t;
	return;
}
void countingsort()
{
	int i;
	for(i=1;i<=n;i++)
		C[A[i]]++;
	for(i=1;i<=Ai;i++)
		C[i]=C[i]+C[i-1];
	for(i=n;i>=1;i--)
	{
		B[C[A[i]]]=A[i];
		book[i]=C[A[i]];
		C[A[i]]--;
	}
	return;
}
int circlecost(int start,int rn)//start是圆的起始点(可以是圆中的任意点),rn是圆中的点数
{
	if(rn==1)
		return 0;
	if(rn==2)
		return A[start]+A[book[start]];

	//初始化
	int min=start,minA=1,i,h,j,cnt1=0,cnt2=0,k;
	int a[MAX];
	for(i=1;i<=n;i++)
		a[i]=A[i];
	j=1;
	for(i=start;;i=book[i])
	{
		if(j>rn)
			break;
		if(A[min]>A[i])
			min=i;
		j++;
	}
	//情况1:不借元素
	j=1;
	for(i=start;j<=rn-1;i=book[i])
	{
		for(k=1;k<=n;k++)
			if(book[k]==min)
			{
				h=k;
				break;
			}
		swap(min,h);
		if(min!=h)
			cnt1=cnt1+A[min]+A[h];
		min=h;
		j++;
	}
	//还原
	for(i=1;i<=n;i++)
		A[i]=a[i];
	j=1;
	for(i=start;;i=book[i])
	{
		if(j>rn)
			break;
		if(A[min]>A[i])
			min=i;
		j++;
	}
	for(i=1;i<=n;i++)
		if(A[minA]>A[i])
			minA=i;
	//情况2:借整体最小元素
	if(min!=minA)
	{
		swap(min,minA);
		if(min!=minA)
			cnt2=cnt2+A[min]+A[minA];
		j=1;
		for(i=start;j<=rn-1;i=book[i])
		{
			for(k=1;k<=n;k++)
				if(book[k]==min)
				{
					h=k;
					break;
				}
			swap(min,h);
			if(min!=h)
				cnt2=cnt2+A[min]+A[h];
			min=h;
			j++;
		}
		swap(min,minA);
		if(min!=minA)
			cnt2=cnt2+A[min]+A[minA];
	}
	else
		cnt2=cnt1+1;
	//比较
	if(cnt1<cnt2)
		return cnt1;
	return cnt2;
}
int mincost()
{
	countingsort();


	int book2[MAX]={0},i,t,j,circlen,cnt=0;
	for(i=1;i<=n;i++)
		if(book2[i]==0)
		{
			circlen=1;
			for(j=i;;)
			{
				book2[j]=1;
				j=book[j];
				if(j==i)
					break;
				circlen++;
			}
			cnt+=circlecost(i,circlen);
		}
	return cnt;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&A[i]);
	printf("%d\n",mincost());
	return 0;
}
