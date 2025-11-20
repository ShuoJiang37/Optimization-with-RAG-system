#include <stdio.h>

typedef struct DATA{
  int x;
  char c;
} CARD;

void bubble(int,CARD *);
void selection(int,CARD *);

int main (){
  CARD bub[36],sel[36];
  int n,i,flag=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&bub[i].c,&bub[i].x);
    sel[i].c=bub[i].c;
    sel[i].x=bub[i].x;
  }
  bubble(n,bub);
  selection(n,sel);
  for(i=0;i<n;i++){
    if(i){
      printf(" ");
    }
    printf("%c%d",bub[i].c,bub[i].x);
  }
  printf("\nStable\n");
  for(i=0;i<n;i++){
    if(i){
      printf(" ");
    }
    printf("%c%d",sel[i].c,sel[i].x);
    if(bub[i].c!=sel[i].c){
      flag=1;
    }
  }
  if(flag){
    printf("\nNot stable\n");
  }
  else{
    printf("\nStable\n");
  }
  return 0;
}

void bubble(int n,CARD *x){
  int i,j,flag=0,tmp_x;
  char tmp_c;
  flag=1; 
  while(flag){
    flag=0;
    for(j=1;j<=n-1;j++){
      if(x[j].x<x[j-1].x){
	tmp_x=x[j].x;
	tmp_c=x[j].c;
	x[j].x=x[j-1].x;
       	x[j].c=x[j-1].c;
	x[j-1].x=tmp_x;
	x[j-1].c=tmp_c;
	flag=1;
      }
    }
  }
}

void selection(int n,CARD *x){
  int i,j,flag=0,tmp_x,min;
  char tmp_c;
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(x[j].x<x[min].x){
	min=j;
      }
    }
    tmp_x=x[i].x;
    tmp_c=x[i].c;
    x[i].x=x[min].x;
    x[i].c=x[min].c;
    x[min].x=tmp_x;
    x[min].c=tmp_c;
  }
}

