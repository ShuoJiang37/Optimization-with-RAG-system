#include <stdio.h>

typedef struct node{
  char mark;
  int val;
} card;

int main(){
  card a[36],b[36],put;
  int n,i,j,minj,flag = 0;
  char putc;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf(" %c%d",&a[i].mark,&a[i].val);
    b[i] = a[i];
  }

  for(j = 0;j < n-1;j++){//bub
    for(i = n-1;i > j;i--){
      if(b[i-1].val > b[i].val){
	put = b[i];
	b[i] = b[i-1];
	b[i-1] = put;
      }
    }
  }

  for(i = 0;i < n;i++){
    if(i != 0) printf(" ");
    printf("%c%d",b[i].mark,b[i].val);
  }
  printf("\nStable\n");

  for(i = 0;i < n-1;i++){//cho
    minj = i;
    for(j = i+1;j < n;j++){
      if(a[j].val < a[minj].val){
	minj = j;
      }
    }
    put = a[i];
    a[i] = a[minj];
    a[minj] = put;
  }
  for(i = 0;i < n;i++){
    if(i != 0) printf(" ");
    printf("%c%d",a[i].mark,a[i].val);
    if(a[i].mark != b[i].mark) flag++;
  }
  printf("\n");
  if(flag > 0) printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}

