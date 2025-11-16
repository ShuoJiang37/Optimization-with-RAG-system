#include<stdio.h>
#include<string.h>


struct card{
	char kind;
	int value;
};

void bubble_sort(int n, struct card c[])
{
	struct card temp;

	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(c[j].value>c[j+1].value)
			{

				temp = c[j];

				c[j]=c[j+1];

				c[j+1]=temp;

			}
		}
	}
}

void selection_sort(int n,struct card c[])
{
	int min;
	struct card temp;
	for(int i=0;i<n;i++)
	{
		min=i;
		for(int j=i;j<n;j++)
		{
			if(c[j].value<c[min].value)
			{
				min = j;
			}
		}
		temp = c[min];

		c[min]=c[i];

		c[i]=temp;
	}
}
int stable(int n,struct card a[],struct card b[])
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int c=0;c<n;c++)
			{
				for(int d=c+1;d<n;d++)
				{
					if(a[i].value==a[j].value&&a[i].kind==b[d].kind&&a[j].kind==b[c].kind&&
					a[i].value==b[d].value&&a[j].value==b[c].value)
					{
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int main(void)
{
  int n;
  scanf("%d",&n);
  struct card a[n];
	struct card b[n];
	struct card c[n];
	for(int i=0;i<n;i++)
	{
    	scanf(" %c%d",&a[i].kind,&a[i].value);
	}
	for(int i=0;i<n;i++)
	{
		b[i]=a[i];
		c[i]=a[i];
	}
	bubble_sort(n, b);
	 printf("%c%d",b[0].kind,b[0].value);
	for(int i=1;i<n;i++)
	{
   		 printf(" %c%d",b[i].kind,b[i].value);
	}
	printf("\n");
	if(stable(n,a,b)==0)
	{
		printf("Stable\n");
	}
	else if(stable(n,a,b)==1)
	{
		printf("Not stable\n");
	}
	selection_sort(n,c);
	printf("%c%d",c[0].kind,c[0].value);
	for(int i=1;i<n;i++)
	{
   		 printf(" %c%d",c[i].kind,c[i].value);
	}
	printf("\n");
	if(stable(n,a,c)==0)
	{
		printf("Stable\n");
	}
	else if(stable(n,a,c)==1)
	{
		printf("Not stable\n");
	}
  return 0;
}

