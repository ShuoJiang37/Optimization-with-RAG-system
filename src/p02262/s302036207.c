#include<stdio.h>

#define MAX 1000000

void insertSort(int *, int, int);
void shellSort(int *, int);

int cnt=0;

int main(){
  int len;
  int i;
  int array[MAX];
  
  scanf("%d", &len);
  for(i=0;i<len;i++) scanf("%d", &array[i]);
  shellSort(array,len);
  for(i=0;i<len;i++) printf("%d\n",array[i]);
  return 0;
}

void shellSort(int *A,int n){//warning
  int i=0,j;
  int G[MAX];
  
  G[0]=1;
  while(G[i]<=n){
    i++;
    G[i]=(3*G[i-1]+1);
  }  
  for(j=i-1;j>=0;j--) insertSort(A,n,G[j]);//大きい方から 
  printf("%d\n",i);//1 line 
  for(j=i-1;j>=0;j--){
    if(j==0) printf("%d\n",G[j]);    
    else printf("%d ",G[j]);
  }
  printf("%d\n",cnt);//3 line
}

void insertSort(int *A, int n, int g){
  int v;
  int i, j;

  for(i=g;i<n;i++){
    v=A[i];
    j=i-g;
    while(j>=0&&A[j]>v){
      A[j+g]=A[j];
      j-=g;
      cnt++;
    }
    A[j+g]=v;
  }
}

