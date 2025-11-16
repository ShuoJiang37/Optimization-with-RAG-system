#include<stdio.h>
#include<string.h>
#define N 36

typedef struct{
  char rom;
  int value;
}card;

void Bsort(card ary[],int n){
  int i,j;
  card tmp;
for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(ary[j].value<ary[j-1].value){
        tmp=ary[j];
        ary[j]=ary[j-1];
        ary[j-1]=tmp;
      }
    }
  }
}

void Ssort(card ary[],int n){
  int i,j,minj;
  card tmp;
  for(i=0;i<n-1;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(ary[j].value<ary[minj].value){
	minj=j;
      }
    }
    tmp=ary[i];
    ary[i]=ary[minj];
    ary[minj]=tmp;
  }
}
void print(card ary[],int n){
  int i;
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%c%d",ary[i].rom,ary[i].value);
  }
  printf("\n");
}

int stable(card ary1[],card ary2[],int n){
  int i;
  for(i=0;i<n;i++){
    if(ary1[i].rom!=ary2[i].rom)return 0;
  }
  return 1;
}
int main(){
  char kuhaku;
  int i,n;
  card ary1[N],ary2[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%c%c%d",&kuhaku,&ary1[i].rom,&ary1[i].value);
  }
  for(i=0;i<n;i++){
    ary2[i]=ary1[i];
  } 
  Bsort(ary1,n);
  Ssort(ary2,n);
  
  print(ary1,n);
  printf("Stable\n");
  print(ary2,n);
  if(stable(ary1,ary2,n))printf("Stable\n");
  else printf("Not stable\n");
  
  return 0;
}

