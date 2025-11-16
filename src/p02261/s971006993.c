#include <stdio.h>

struct card{
  char mark;
  int num;
};

int main(){
  int i, j, N, minj, a ,b, flag=1;
  struct card C[36], A[36], B[36], temp;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf(" %c%d",&C[i].mark,&C[i].num);
    A[i]=C[i];
    B[i]=C[i];
  }

  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
      if(C[j].num<C[j-1].num){
	temp=C[j];
	C[j]=C[j-1];
	C[j-1]=temp;
      }
    }
  }
  for(i=0;i<N-1;i++){
    printf("%c%d ",C[i].mark,C[i].num);
  }
  printf("%c%d\nStable\n",C[N-1].mark,C[N-1].num);
    
  for(i=0;i<N;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(A[j].num<A[minj].num)minj = j;
    }
    temp=A[i];
    A[i]=A[minj];
    A[minj]=temp;
  }
  
  for(i=0;i<N-1;i++){
    printf("%c%d ",A[i].mark,A[i].num);
  }
  printf("%c%d\n",A[N-1].mark,A[N-1].num);

  for(i=0;i<N;i++){
    for(j=i+1;j<N;j++){
      for(a=0;a<N;a++){
	for(b=a+1;b<N;b++){
	  if(B[i].num==B[j].num&&B[i].mark==A[b].mark&&B[j].mark==A[a].mark&&B[i].num==A[b].num&&B[j].num==A[a].num)flag=0;
	  break;
	}
      }
    }
  }
  if(flag==0)printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}