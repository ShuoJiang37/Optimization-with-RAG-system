#include <stdio.h>
void print(int A[], int length){
  int i;
  for(i=0; i<length; ++i){
	printf("%d", A[i]);
	if(i<(length-1))
	  printf(" ");
  }
  printf("\n");
}

int main(){
  int length;
  int i, j;
  int key;

  scanf("%d", &length);
  int A[length];

  for(i=0; i<length; ++i){
	scanf("%d", &A[i]);
  }  
  print(A, length);
  for(j=1; j<length; ++j){
	key=A[j];
	i=j-1;
	while((i>=0)&&(A[i]>key)){
	  A[i+1]=A[i];
	  --i;
}
	A[i+1]=key;
	print(A, length);
}
  return 0;
}

