#include<stdio.h>
#include<string.h>
struct card{
	    char b;
		char a;	
	};
int check(struct card a[],struct card b[],int n){
	int i,t=0;
	for(i=0;i<n;i++){
		if(a[i].a==b[i].a&&a[i].b==b[i].b)
		t++;
	}
	if(t==n)
	return 1;
	else
	return 0;
}
void out(struct card A[],int n){
	int i;
	for(i=0;i<n;i++){
		if(i>0)
		printf(" ");
		printf("%c%c",A[i].b,A[i].a);
	}
	printf("\n");
}
int main(){
	int n,i,j,min;
	char ch;
	scanf("%d",&n);
	getchar();
	struct card pai[n],mid,copy[n];
	for(i=0;i<n;i++){
		pai[i].b=getchar();
		pai[i].a=getchar();
		if(i!=n-1)
		ch=getchar();
		}
	for(i=0;i<n;i++)
	copy[i]=pai[i];
	for(i=0;i<n;i++){
	for(j=n-1;j>i;j--){
		if(pai[j].a<pai[j-1].a){
			mid=pai[j];
			pai[j]=pai[j-1];
			pai[j-1]=mid;
		}
	}}
	out(pai,n);
	printf("Stable\n");
	for(i=0;i<n;i++){
		min=i;
		for(j=i;j<n;j++){
			if(copy[j].a<copy[min].a)
			min=j;
		}
		mid=copy[min];
		copy[min]=copy[i];
		copy[i]=mid;
	}
	out(copy,n);
	if(check(pai,copy,n))
	printf("Stable\n");
	else
	printf("Not stable\n");
	return 0;
}
