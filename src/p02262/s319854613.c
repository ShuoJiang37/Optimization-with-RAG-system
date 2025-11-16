#include <stdio.h>
#include <stdlib.h>
#define N 1000000
int count=0,n,m,C[N],*Q;

void insertionSort(int C[], int n, int e){
  int i,j,v;
  for(i=e;i<n;i++){
    v=C[i];
    j=i-e;
    while(j>=0&&C[j]>v){
      C[j+e]=C[j];
      j-=e;
      count++;
    }
    C[j+e]=v;
  }
}

void shellSort(int C[],int n){
  int i=0,k;

  Q=(int *)malloc(n * sizeof(int));
  for(k=1; ; ){
    if(k>n)
      break;
      Q[i]=k;
      i++;
      k=3*k+1;
    }
    m=i;
    for(i=m-1;i>=0;i--){
      insertionSort(C,n,Q[i]);
    }
  }

  int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&C[i]);
      count=0;
    }
    
    shellSort(C,n);

    printf("%d\n",m);

    for(i=m-1;i>=0;i--){
      printf("%d",Q[i]);
      if(i){
	printf(" ");
      }
    }
    printf("\n");
    printf("%d\n",count);
    for(i=0;i<n;i++){
      printf("%d\n",C[i]);
    }

      free(Q);
      return 0;
    }
      

