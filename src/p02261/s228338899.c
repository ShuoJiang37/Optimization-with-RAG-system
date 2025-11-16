#include <stdio.h>

typedef struct{
  char suit;
  int value;
} Card;

void BubbleSort(Card C[],int N)
{

  int i, j;
  Card a;
  
  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(C[j].value < C[j-1].value){
	a = C[j];
	C[j] = C[j-1];
	C[j-1] = a;
      }
    }
  }

}

void SelectionSort(Card C[],int N)
 {

   int i, j, minj;
   Card a;
   
   for(i=0;i<N;i++){
     minj = i;
     for(j=i;j<N;j++){
       if(C[j].value < C[minj].value){
	 minj = j;
       }
     }
     a = C[i];
     C[i] = C[minj];
     C[minj] = a;
   }
   
 }

int isStable(Card in[],Card out[],int N)
{

  int i, j, a, b;

  for(i=0;i<N;i++){
    for(j=i+1;j<N;j++){
      for(a=0;a<N;a++){
	for(b=a+1;b<N;b++){
	  if(in[i].value==in[j].value){
	    if(in[i].suit==out[b].suit && in[i].value==out[b].value){
	      if(in[j].suit==out[a].suit && in[j].value==out[a].value){
	    return 0;
	      }
	    }
	  }
	}
      }
    }
  }

  return 1;

}

int main()
{

  int N, i;
  
  scanf("%d",&N);
  Card C1[N], C2[N];
  
  for(i=0;i<N;i++){
    scanf(" %c%d",&C1[i].suit,&C1[i].value);
  }

  for(i=0;i<N;i++){
    C2[i] = C1[i];
  }

  BubbleSort(C1,N);
  SelectionSort(C2,N);

  for(i=0;i<N;i++){
    if(i!=N-1) printf("%c%d ",C1[i].suit,C1[i].value);
    else printf("%c%d\n",C1[i].suit,C1[i].value);
  }
  printf("Stable\n");

  for(i=0;i<N;i++){
    if(i!=N-1) printf("%c%d ",C2[i].suit,C2[i].value);
    else printf("%c%d\n",C2[i].suit,C2[i].value);
  }
  if(isStable(C1,C2,N)==1) printf("Stable\n");
  else printf("Not stable\n");

  return 0;

}

