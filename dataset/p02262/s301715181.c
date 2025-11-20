#include <stdio.h>
void insertionSort(int A[],long N,long g);
void ShellSort(int A[],long N);
void trace(int A[],long N);
long long  cnt=0;
int main(void)
{
    long N;
    long i;
    int A[1000000]={0};
    
    scanf("%ld",&N);
    for (i=0;i<N;i++)scanf("%d",&A[i]);
    
	ShellSort(A,N);
	printf("%lld\n",cnt);
    trace(A,N);
    
    return 0;
}

void insertionSort(int A[],long N,long g)
{
    long i,j,temp;
    for(i=g;i<N;i++){
        j=i-g;
        temp=A[i];
        while(j>=0&&A[j]>temp){
            A[j+g]=A[j];
            j-=g;
            cnt++;
        }
        A[j+g]=temp;
    }
    
}

void trace(int A[],long N)
{
    int i;
    for (i=0;i<N;i++){
        printf("%d\n",A[i]);
    }
}

void ShellSort(int A[],long N)
{
    cnt=0;
    int h=0;
    int m=-1;
    int i;
    int G[30]={0};
    int ct;
    while(h<=N){
        h=3*h+1;
        m++;
    }
    printf("%d\n",m);
    for (i=0;i<m;i++){
		h=(h-1)/3;
		G[i]=h;
	}
		
    for (h=0;h<m;h++){
    	if (h>0)printf(" ");
    	printf("%d",G[h]);
    	insertionSort(A,N,G[h]);
	}
	printf("\n");
}