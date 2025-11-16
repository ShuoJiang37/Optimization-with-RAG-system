/*
  安定なソート(ALDS1_2_C)
  2018/08/25
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int num;//カードの数
  char mark;//カードのマーク
  int input_num;//カードが入ってくる順番
} Card;

void Bubblesort(Card *,int);
void Selectionsort(Card *,int);
void Judge_stable(Card *,int);
void print(Card *,int);
  
int main(void){
  
  Card *a,*b;
  int i,n;

  scanf("%d ",&n);
  a = (Card*)calloc(n,sizeof(Card));
  b = (Card*)calloc(n,sizeof(Card));
  
  for(i=0;i<n;i++){
    scanf(" %c%d",&a[i].mark,&a[i].num);
    a[i].input_num = i;
    b[i] = a[i];  
  }
  
  Bubblesort(a,n);
  Selectionsort(b,n);
  
  free(a);
  free(b);
  
  return 0;
}


void Bubblesort(Card *C, int N)
{
  int i,j;
  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(C[j].num < C[j-1].num){
	Card temp = C[j];
	C[j] = C[j-1];
	C[j-1] = temp;
      }
    }
  }

  print(C,N);
  Judge_stable(C,N);
  
}

void Selectionsort(Card *C,int N)
{
  int i,j;
  int minj;
  for(i=0;i<N;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(C[j].num < C[minj].num)
	minj = j;
    }
    Card temp = C[i];
    C[i] = C[minj];
    C[minj] = temp;
  }

  print(C,N);
  Judge_stable(C,N);
}

void print(Card *c,int n)
{
  int i;
  for(i=0;i<n-1;i++)
    printf("%c%d ",c[i].mark,c[i].num);
  printf("%c%d\n",c[i].mark,c[i].num);
}


void Judge_stable(Card *c,int n)
{
  int i=0;
  int j;
  int flag = 1;
  while(i < n && flag == 1){
    j=i;
    while(j < n && flag == 1){
      if(c[i].num == c[j].num && c[j].input_num < c[i].input_num)
	flag = 0;
      j++;
    }
    i++;
  }

  if(flag == 1)
    printf("Stable\n");
  else
    printf("Not stable\n");
}
