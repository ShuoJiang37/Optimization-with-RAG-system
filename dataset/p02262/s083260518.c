#include <stdio.h>
int insertionSort(int A[], int n, int g);
int ShellSort(int A[], int n);
int main(){
  char line[100];
  int total;
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%d", &total);
  int A[total];
  int i, j;
  int cnt;
  for(i=0; i<total; ++i){
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &A[i]);
  }
  cnt=ShellSort(A, total);

  printf("%d\n", cnt);
  for(i=0; i<total; ++i){
	printf("%d\n", A[i]);
  }
  return 0;
}
int insertionSort(int A[], int n, int g){
  int i, j;
  int cnt=0;
  int v;
  for(i=g; i<n; ++i){
	v=A[i];
	j=i-g;
	while((j>=0)&&(A[j]>v)){
	  A[j+g]=A[j];
	  ++cnt;
	  j=j-g;
	}
	A[j+g]=v;
  }
  return cnt;
}
int ShellSort(int A[], int n){
  int m, cnt=0;
  int i, j;
  i=1;
  m=1;
  while(i<=n){
	i=i*3+1;
	++m;
  }
  --m;
  int G[m];
  i=1;
  printf("%d\n", m);
  fflush(stdout);
  for(j=0; j<m; ++j){
	G[j]=i;
	i=i*3+1;
  }

  for(j=(m-1); j>=0; --j){
	cnt+=insertionSort(A, n, G[j]);
	printf("%d", G[j]);
	if(j>0)
	  printf(" ");
	else 
	  printf("\n");
  }

  return cnt;
}

