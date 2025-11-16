#include<stdio.h>
#include<string.h>

struct card{
	char mark;
	int number;
};
int main(void)
{
	int i,j,m,c=0, n;
	scanf("%d",&n);
	struct card a[n];
	struct card b[n];
	struct card d;
	for(i=0; i<n; i++){
	scanf(" %c%d",&a[i].mark, &a[i].number);
		b[i]=a[i];
	}
	
	for(i=0; i<n; i++){
		for(j=n-1; j>i; j--){
			if(a[j-1].number>a[j].number)
			{
				d=a[j];
				a[j]=a[j-1];
				a[j-1]=d;
			}
		}
	}
	for(i=0;i<n-1; i++){
		printf("%c%d ",a[i].mark,a[i].number);
	}
	printf("%c%d\n",a[n-1].mark,a[n-1].number);
		
	printf("Stable\n");
	
	for(i=0; i<n; i++){
		m=i;
		for(j=i; j<n; j++){
			if(b[j].number<b[m].number){
				m=j;
			}

		}
				if(b[i].number!=b[m].number)
			{
				d=b[m];
				b[m]=b[i];
				b[i]=d;
			}
	}
	for(i=0;i<n-1; i++){
		printf("%c%d ",b[i].mark,b[i].number);
		if(b[i].mark!=a[i].mark){
			c++;
		}
	}
		printf("%c%d\n",b[n-1].mark,b[n-1].number);
			if(b[n-1].mark!=a[n-1].mark){
			c++;
			}
		if(c==0){printf("Stable");}
				else{printf("Not stable");}
	printf("\n");
	return 0;
}
