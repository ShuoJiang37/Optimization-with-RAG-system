#include<stdio.h>

int n, g[1000],top = 1,cnt=0;

void add()
{
	while(g[top]*3+1<n)
	{
		top++;
		g[top]=g[top-1]*3+1;
	}
}

void sort(int a[], int g)
{
	int i,j,v;
	
	for (i = g+1;i<= n;i++)
	{
		v = a[i];
		
        j = i - g;
		
		while (j >= 1 && a[j] > v)
		{
			
              a[j+g] = a[j];
              j-= g;
              cnt++;
			  
		}
		a[j+g]=v;
	}
}


int main(void){
    int i;
    scanf("%d",&n);
	int a[n];
    g[1]=1;
	
    for(i=1;i<=n;i++)
        scanf("%d ",&a[i]);
    add();
	
    for(i=top;i>=1;i--)
        sort(a,g[i]);
    printf("%d\n",top);
	
    for(i=top;i>=1;i--)
        printf("%d ",g[i]);
    	printf("\n");
    	printf("%d\n",cnt);
	
    for(i=1;i<=n;i++)
        printf("%d\n",a[i]);
	
    return 0;
}

