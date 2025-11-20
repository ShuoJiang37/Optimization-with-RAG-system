#include <stdio.h>
#define N 36

typedef struct card
{
    char moji;
    char num;
}cards;

int main(){
  int n,i,j,flag,minj;
  cards A[N],B[N],temp;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%c",&A[i].moji,&A[i].num);
  }

  for(i=0;i<n;i++)B[i]=A[i];

      /*??????????????????*/
    for(i=0;i<n;i++){
      flag = 1;
      while(flag){
        flag = 0;
        for(j=n-1;1<=j;j--){
          if(B[j].num<B[j-1].num){
            temp = B[j-1];
            B[j-1] = B[j];
            B[j] = temp;
            flag = 1;
          }
        }
      }
    }

  for(i=0;i<n-1;i++)printf("%c%c ",B[i].moji,B[i].num);
    printf("%c%c",B[n-1].moji,B[n-1].num);
  printf("\nStable\n");

  /*?????¬????????§????????????*/
  for(i=0;i<n-1;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(A[j].num < A[minj].num){
        minj = j;
      }
    }
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
  }

  for(i=0;i<n-1;i++)printf("%c%c ",A[i].moji,A[i].num);
  printf("%c%c",A[n-1].moji,A[n-1].num);
    flag = 1;
  for(i=0;i<n;i++)if(A[i].moji!=B[i].moji) flag = 0;
    if(flag)printf("\nStable\n");
    else printf("\nNot stable\n");

  return 0;
}