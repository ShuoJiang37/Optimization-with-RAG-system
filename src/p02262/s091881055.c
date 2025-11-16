#include <stdio.h>
int insertionSort(int A[], int n, int g);
int shellSort(int A[], int n);
int main(){
  int total;
  scanf("%d", &total);
  int A[total];
  int i, j;
  int cnt;
  for(i=0; i<total; ++i){
	scanf("%d", &A[i]);
  }
    cnt=shellSort(A, total);
	
  //出力
	printf("%d\n", cnt);
  for(i=0; i<total; ++i){
	printf("%d\n", A[i]);
  }

}
int insertionSort(int A[], int n, int g){
  int i, j;
  int v;
  int count=0;
  for(i=g; i<n; ++i){
	v=A[i];
	j=i-g;
	while((j>=0)&&(A[j]>v)){
	  A[j+g]=A[j];
	  j=j-g;
	  ++count;
	}
	A[j+g]=v;
  }
  return count;
}
int shellSort(int A[], int n){
  int index=1;
  int i=1, j;
  int cnt=0;
  while(i<=n){
	i=i*3+1;
	++index;
  }
  --index;
  int G[index];
  i=1;
  for(j=0; j<index; ++j){
	G[j]=i;
	i=i*3+1;
  }
  printf("%d\n", index);
  for(j=(index-1); j>=0; --j){
	printf("%d", G[j]);
  	cnt=cnt+insertionSort(A, n, G[j]);
	if(j>0)
	  printf(" ");
	else
	  printf("\n");
  }
  return cnt;
}

