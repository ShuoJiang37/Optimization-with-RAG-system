#include <stdio.h>
#include <string.h>
#define M 36

int N;

typedef struct {
  char suit;
  int value;
}Card;

Card C[M],S[M];


void bubblesort(Card *C,int N){
  int i,j;
  Card tmp;
  
  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(C[j].value<C[j-1].value){
	tmp=C[j-1];
	C[j-1]=C[j];
	C[j]=tmp;
    }
  }
}
}

void selectionsort(Card *C,int N){
  int i,j,minj;
  Card tmp;
  
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(C[j].value<C[minj].value){
	minj=j;
      }
    }
    tmp=C[minj];
    C[minj]=C[i];
    C[i]=tmp;
  }
}


int isStable(Card *in,Card *out,int N){
  int a=0,b=0,i;
  
  for(i=0;i<N;i++){
    if(strcmp(&in[i].suit,&out[i].suit)==0) a++;
  }
  for(i=0;i<N;i++){
    if(in[i].value==out[i].value) b++;
  }
 
  if(a!=b) return 0;

  else return 1;
}
    
 

int main(){
  int N,i;
  
  

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf(" %c%d",&C[i].suit,&C[i].value);
    S[i]=C[i];
  }
  
  

  bubblesort(C,N);
  
  for(i=0;i<N-1;i++){
  printf("%c%d ",C[i].suit,C[i].value);
  }
  printf("%c%d\n",C[N-1].suit,C[N-1].value);
  

  printf("Stable\n");

  selectionsort(S,N);
   for(i=0;i<N-1;i++){
  printf("%c%d ",S[i].suit,S[i].value);
  }
  printf("%c%d\n",S[N-1].suit,S[N-1].value);
  


  if(isStable(C,S,N)==0){
    printf("Not stable\n");
}
  else printf("Stable\n");
  

  return 0;
}
