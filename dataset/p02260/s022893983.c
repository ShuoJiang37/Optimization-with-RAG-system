#include <stdio.h>

int main(){
  int total;
  scanf("%d", &total);
  int A[total];
  int i, j;
  for(i=0; i<total; ++i){
	scanf("%d", &A[i]);
  }
  int count=0;
  int min, tmp, index;
  for(i=0; i<(total-1); ++i){
	min=A[i];
	tmp=A[i];
	for(j=(i+1); j<total; ++j){
	  if(min>A[j]){
		min=A[j];
		index=j;
	  }
	}
	if(min!=tmp){
	  ++count;
	  A[i]=min;
	  A[index]=tmp;
	}	  
	
  }

  for(i=0; i<total; ++i){
	printf("%d", A[i]);
	if(i<(total-1))
	  printf(" ");
  }
  printf("\n%d\n", count);
  return 0;
}

