#include<stdio.h>
#include<stdlib.h>
int n,i,A[1000000],tmp,k,cnt=0,j,m=0,h=1;

// InsersionSort
void insersionSort(int A[], int n, int g){
  for(i=g;i<=n-1;i++){
    tmp=A[i];
    k=i-g;
    while(k>=0&&A[k]>tmp){
      A[k+g]=A[k];
      k=k-g;
      cnt++;
    }
    A[k+g]=tmp;
  }
}

// ShellSort
void shellSort(int A[], int n){
  int *T=(int *)malloc(sizeof(int)*n);
  while(h<=n){
    T[m] = h;
    h = h*3+1;
    m++;
  }
  int *G=(int *)malloc(sizeof(int)*m);
  for(i=0;i<=m-1;i++){
    G[i] = T[i];
  }
  for(j=m-1;j>=0;j--){
    insersionSort(A, n, G[j]);
  }
  printf("%d\n",m);
  for(i=m-1;i>=0;i--){
    if(i<m-1)printf(" ");
    printf("%d",G[i]);
  }
  free(T);
  free(G);
}

int main(){
  scanf("%d", &n);
  for(i=0;i<=n-1;i++)scanf("%d",&A[i]);
  shellSort(A, n);
  printf("\n");
  printf("%d\n",cnt);
  for(i=0;i<=n-1;i++)printf("%d\n",A[i]);
  return 0;
}