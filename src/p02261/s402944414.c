#include<stdio.h>

#define TRUE 1
#define FALSE 0
typedef struct {
  int num;
  char attribute;
}CARD;

void bubbleSort(CARD*,int);
void selectionSort(CARD*,int);
void print(CARD*,int);
int judgeStable(CARD*,CARD*,int);


int main(){
  CARD c1[100],c2[100];
  int i,N;
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf(" %c%d",&c1[i].attribute,&c1[i].num);
    c2[i] = c1[i];
  }

 

  bubbleSort(c1,N);
  selectionSort(c2,N);
  print(c1,N);
  printf("Stable\n");
  print(c2,N);
  if(judgeStable(c1,c2,N)!=FALSE){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }

  return 0;
}
  

void bubbleSort(CARD *c,int N){
  int i,j;
  CARD temp;
  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
      if(c[j].num < c[j-1].num){
	temp = c[j];
	c[j] = c[j-1];
	c[j-1] = temp;
      }
    }
  }
}

void selectionSort(CARD *c,int N){
  int i,j,min;
  CARD temp;
  for(i = 0;i<N;i++){
    min = i;
    for (j = i;j<N;j++){
      if(c[j].num < c[min].num){
	min = j;
      }
    }
    temp = c[i];
    c[i] = c[min];
    c[min] = temp;
  }
}

void print(CARD *c,int N){
  int i;
  for(i = 0;i<N;i++){
    printf("%c%d",c[i].attribute,c[i].num);
    if(i!=N-1)printf(" ");
  }
  printf("\n");
}

int judgeStable(CARD *c1,CARD *c2,int N){
  int i;
  for(i=0;i<N;i++){
    if(c1[i].attribute != c2[i].attribute)return FALSE;
  }
  return TRUE;
}

