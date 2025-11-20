#include<stdio.h>
#include<stdlib.h>

#define N 36

typedef struct node{
  int num;
  char value;
}C;

C c_1[N];
C c_2[N];
int n;

void BubbleSort(){
  int i,j;
  C v;
  
  for(i = 0; i < n; i++){
    for(j = n - 1; i+1 <= j; j--){
      if(c_1[j].num < c_1[j-1].num){
        v = c_1[j];
        c_1[j] = c_1[j-1];
        c_1[j-1] = v;
      }
    }
  }
}

void SelectionSort(){
  int i,j,minj;
  C v;

  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(c_2[j].num < c_2[minj].num)minj = j;
    }
    v = c_2[i];
    c_2[i] = c_2[minj];
    c_2[minj] = v;
  }
  
}

int judgeStable(){
  int i;
  for(i = 0; i < n; i++){
    if(c_1[i].value != c_2[i].value)return 0;
  }

  return 1;
}

int main(){
  int i,num,stable;
  char val;

  scanf("%d",&n);
  
  for(i = 0; i < n; i++){
    scanf(" %c%d",&val,&num);
    c_1[i].value = c_2[i].value = val;
    c_1[i].num = c_2[i].num = num;
  }
  BubbleSort();
  SelectionSort();

  printf("%c%d",c_1[0].value,c_2[0].num);
  for(i = 1; i < n; i++)printf(" %c%d",c_1[i].value,c_1[i].num);
  printf("\n");
  printf("Stable\n");
  
  stable = judgeStable();
  printf("%c%d",c_2[0].value,c_2[0].num);
  for(i = 1; i < n; i++)printf(" %c%d",c_2[i].value,c_2[i].num);
  printf("\n");
  if(stable == 1)printf("Stable\n");
  else printf("Not stable\n");
}
