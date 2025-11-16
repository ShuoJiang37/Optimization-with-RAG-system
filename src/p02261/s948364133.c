#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
  char c;
  int n;
}Card;

int main(){
  int n,num,i,j,min;
  Card a[110],b[110],v;
  int flag;
  char c;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%c%c%d",&c,&a[i].c,&a[i].n);
    b[i]=a[i];
  }

  flag = 1;
  while(flag){
    flag =0;
    for(j = n - 1; j > 0; j--){
      if(a[j].n < a[j-1].n){
        v = a[j];
        a[j] = a[j-1];
        a[j-1] = v;
        flag = 1;
      }
    }
  }
  for(j = 0; j < n; j++){
    if(j)printf(" ");
      printf("%c%d",a[j].c,a[j].n);
  }
  printf("\n");
  printf("Stable\n");



  for(i = 0; i < n-1; i++){
    min =i;
    for(j = i; j < n; j++){
      if(b[j].n < b[min].n) min = j;
    }
    v = b[i];
    b[i] = b[min];
    b[min] = v;
  }
  for(j = 0; j < n; j++){
    if(j)printf(" ");
      printf("%c%d",b[j].c,b[j].n);
  }
  printf("\n");

  for(i=0;i<n;i++){
    if(a[i].c!=b[i].c){
      printf("Not stable\n");
      break;
    }
  }
  if(i == n) printf("Stable\n");
  return 0;
}

