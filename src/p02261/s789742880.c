#include <stdio.h>

struct Card {
  char suit, value;
};


void swap(struct Card *A , int a, int b )
	  	
{
  struct Card temp ;	

  temp = A[a] ;    
  A[a] = A[b] ;	
  A[b] = temp ;
  
}

void bubble(struct Card *A, int N){

  int i,j;

  for(i=0; i<N; i++){
    for(j=N-1;j>=i;j--){
      if(A[j].value<A[j-1].value){

	swap(A,j,j-1);
      }
    }
  }
}

void selection(struct Card *A,int N){

  int i,j;

  for(i=0;i<N;i++){
    int minj=i;
    for(j=i;j<N;j++){
      if(A[j].value<A[minj].value) minj=j;
    }
    swap(A,i,minj);
  }
  
}



int isStable(struct Card *c1,struct Card *c2, int N){

  int i,j;

  for(i=0;i<N;i++){
    if(c1[i].suit!=c2[i].suit) return -1;
  }
  if(c1[i].suit==c2[i].suit)  return 1;
}

int main(){

  int i,j;

  struct Card c1[100],c2[100];
  int N;
  

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf(" %c%c",&c1[i].suit,&c1[i].value);
  }

  for(i=0;i<N;i++){
    c2[i]=c1[i];
  }

  bubble(c1,N);
  selection(c2,N);

  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%c%c", c1[i].suit, c1[i].value);
  }
  printf("\n");

  if(isStable(c1,c2,N)==1){
    printf("Stable");
  }
  else if(isStable(c1,c2,N)!=1){
    printf("Stable");
  }

  printf("\n");

  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%c%c", c2[i].suit, c2[i].value);
  }
  printf("\n");

  if(isStable(c1,c2,N)==1){
    printf("Stable");
  }
  else if(isStable(c1,c2,N)!=1){
    printf("Not stable");
  }

  printf("\n");

  return 0;
}

  

    
  



