#include <stdio.h>
struct card{
    char pattern;
    int value;
  };

struct card* bubbleSort(struct card* );
struct card* selectionSort(struct card*);
int isStable(struct card* , struct card*);

int N;
  
int main(){

  int i,j;
  struct card A[36],B[36],C[36];

  scanf("%d",&N);
  for(i=0;i<N;i++) scanf(" %c%d",&A[i].pattern,&A[i].value);

  for(i=0;i<N;i++){
    B[i]=A[i];
    C[i]=A[i];
  }

  bubbleSort(B);
  
  for(j=0;j<N-1;j++) printf("%c%d ",B[j].pattern,B[j].value);
  printf("%c%d\n",B[N-1].pattern,B[N-1].value);
  
  if(isStable(A,B)==0) printf("Not stable\n");
  else printf("Stable\n");
  
  selectionSort(C);
  
  for(j=0;j<N-1;j++) printf("%c%d ",C[j].pattern,C[j].value);
  printf("%c%d\n",C[N-1].pattern,C[N-1].value);

  if(isStable(A,C)==0) printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}

struct card* bubbleSort(struct card *C){
  int i=0,j;
  struct card tmp;

  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
      if(C[j].value < C[j-1].value){
	tmp=C[j];
	C[j]=C[j-1];
	C[j-1]=tmp;
      }
    }
  }
  return C;
}

struct card* selectionSort(struct card *C){
  int i,j,minj=0;
  struct card tmp;

  for(i=0;i<N;i++){
    minj=i;
    for(j=i+1;j<N;j++){
      if(C[j].value < C[minj].value){
	minj=j;
      }
    }
	tmp=C[i];
	C[i]=C[minj];
	C[minj]=tmp;
  } 
  return C;
}

int isStable(struct card *in, struct card *out){

  int i,j,a,b;

  for(i=0;i<N;i++){
    for(j=i+1;j<N;j++){
      for(a=0;a<N;a++){
	for(b=a+1;b<N;b++){
	  if(in[i].value==in[j].value
	     && in[i].pattern == out[b].pattern && in[i].value == out[b].value
	     && in[j].pattern == out[a].pattern && in[j].value == out[a].value)
	    return 0;
	}
      }
    }
  }
  return 1;
}

