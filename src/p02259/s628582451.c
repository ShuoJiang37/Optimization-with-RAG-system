#include <stdio.h>
#define MAX 100

typedef struct{
  int A[MAX];
  int chenge;
}data;

void BubbleSort(data *,int);

int main(void){

  int i,len;
  data a;

  scanf("%d",&len);

  for(i=0;i<len;i++)
    scanf("%d",&a.A[i]);

  BubbleSort(&a,len);

  for(i=1;i<len;i++)
    printf("%d ",a.A[i-1]);
  printf("%d\n",a.A[i-1]);

  printf("%d\n",a.chenge);
  return 0;
}


void BubbleSort(data *p,int len){
  
  int i,j,key;
  
  p->chenge=0;
  
  for(j=1;j<len;j++){
    key = p->A[j];
    i = j - 1;
    while(i >= 0 && p->A[i] > key){
      p->A[i+1] = p->A[i];
      i = i - 1;
      p->A[i+1] = key;
      p->chenge++;
    }
  }
}