#include <stdio.h>
#include <string.h>
int main(){
  char line[100000];
  int N;
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%d", &N);
  char *str_ptr;
  int i, j;
  int A[100];
  int count=0;
  fgets(line, sizeof(line), stdin);
  str_ptr=strtok(line, " ");
  sscanf(str_ptr, "%d", &A[0]);
  for(i=1; i<N; ++i){
	str_ptr=strtok(NULL, " ");
	sscanf(str_ptr, "%d", &A[i]);
  }
  //ソート
  int tmp;
  for(i=0; i<(N-1); ++i){
	for(j=(N-1); j>=i+1; --j){
	  if(A[j]<A[j-1]){
		tmp=A[j];
		A[j]=A[j-1];
		A[j-1]=tmp;
		++count;
	  }
	}
  }
  //
  for(i=0; i<N; ++i){
	printf("%d", A[i]);
	if(i<(N-1))
	  printf(" ");
  }
  printf("\n");
  printf("%d\n", count);
  return 0;
}

