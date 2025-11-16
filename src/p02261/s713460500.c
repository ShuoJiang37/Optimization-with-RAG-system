#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct {
  char suit;
  int value;
} Card;

void BubbleSort(Card *,int);
void SelectionSort(Card *,int);
int isStable(Card *,Card *,int);
void print(Card *,int);
void swap(Card *,Card *);

int main(){
  int i,N;
  Card C1[36],C2[36];


  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf(" %c%d",&C1[i].suit,&C1[i].value);
     }

  for(i=0;i<N;i++)C2[i] = C1[i];

  BubbleSort(C1,N);
  SelectionSort(C2,N);

  print(C1,N);
  if( isStable(C1,C1,N) )printf("Stable\n");
  else printf("Not stable\n");

  print(C2,N);
  if( isStable(C1,C2,N) )printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}

void BubbleSort(Card C[],int N){
  int i,j,flag;

  flag = 1;

  while(flag){
    flag = 0;
    for(i=0;i < N;i++){
for(j=N-1;j >= i+1;j--){

        if( C[j].value < C[j-1].value ){
          swap(&C[j],&C[j-1]);

          flag = 1;

        }
      }
    }
  }
}

void SelectionSort(Card C[],int N){
  int i,j,minj;


  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j < N;j++){
      if( C[j].value < C[minj].value){
        minj = j;
      }
    }
        swap(&C[i],&C[minj]);
    }
}



int isStable(Card in[],Card out[],int N){
  int i,j,a,b;

  for(i=0;i<N;i++){

    for(j=i+1;j<N;j++){

      for(a=0;a<N;a++){

        for(b=a+1;b<N;b++){
           if( (in[i].value == in[j].value) && (in[i].value == out[b].value) &&  (in[i].suit == out[b].suit) && (in[j].val\
ue == out[a].value) && (in[j].suit  == out[a].suit)){
            return FALSE;
          }

        }

      }

    }

 }

  return TRUE;
}

void print(Card C[],int N){
  int i;

  for(i=0;i<N;i++){
    if(i>0)printf(" ");

    printf("%c%d",C[i].suit,C[i].value);
  }
  printf("\n");
}

void swap(Card *in,Card *out){
  Card temp;

  temp = *in;
  *in = *out;
  *out = temp;
}

