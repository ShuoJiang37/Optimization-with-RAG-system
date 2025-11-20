#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define M 10000
void shell_sort(int a[],int n);
void insertionSort(int a[], int num,int g ,int *cnt);
int main(){
	int n,i;
	scanf("%d",&n);
	int *a;
	a = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	shell_sort(a,n);
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	free(a);

	return 0;
}
void insertionSort(int a[], int num,int g,int *cnt)
{
    int v, i, j;
    for (i = 1; i < num; i++)
    {
        v = a[i];
        j = i - g;
        while (j >= 0 && a[j] > v)
        {
            a[j + g] = a[j];
            j -=g ;
			*cnt=*cnt+1;
        }
        a[j + g] = v;
    }
	
}
void shell_sort(int a[],int n){
	int cnt = 0;
	int *g;
	int i,tmp;
	for(i =1;i<M;i++){
		if((pow(3,i)-1)/2>n){
			tmp = i;
			break;
		}
	}
	g = (int *)malloc(sizeof(int)*(tmp-1));
	printf("%d\n",tmp-1);
	for(i =0;i<tmp-1;i++){
		if(i !=0){printf(" ");}
		g[i] = (pow(3,tmp-i-1)-1)/2;
		printf("%d",g[i]);
		}
		printf("\n");
	
	for(i =0;i<tmp-1;i++){
		insertionSort(a,n,g[i], &cnt);
	}
	free(g);
	printf("%d\n",cnt);
}
