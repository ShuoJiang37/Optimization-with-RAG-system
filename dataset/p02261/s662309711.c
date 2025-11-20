#include<stdio.h>
#define MAX 36
#define True 1
#define False 0
  
typedef struct{
  char c;
  int num;
} card;
  
void cardsort(card []);
void select(card []);
int search(card [],card []); 
  
int number;
  
int main(){
  int i,j;
  card data[MAX];
  card data2[MAX];
    
    
  scanf("%d",&number);
  for(i=0;i<number;i++) {
    scanf(" %c%d",&data[i].c,&data[i].num);
  }
    
  for(i=0;i<number;i++) {
    data2[i] = data[i];
  }
    
  cardsort(data);
  select(data2);
  
    
  for(i=0;i<number-1;i++){
    printf("%c%d ",data[i].c,data[i].num);
  }
  printf("%c%d\n",data[number-1].c,data[number-1].num);
  printf("Stable\n");
  
    
  for(i=0;i<number-1;i++){
    printf("%c%d ",data2[i].c,data2[i].num);
  }
  printf("%c%d\n",data2[number-1].c,data2[number-1].num);
  
  if(search(data,data2)==1) printf("Stable\n");
  else printf("Not stable\n");
  return 0;
}
  
  
void cardsort (card n[]){
  int i,j,tmp;
  char tmpc;
  for(i=0;i<number;i++){
    for(j=number-1;j>i;j--){
      if(n[j].num<n[j-1].num){
    tmp=n[j].num;
    n[j].num=n[j-1].num;
    n[j-1].num=tmp;
  
    tmpc=n[j].c;
    n[j].c=n[j-1].c;
    n[j-1].c=tmpc;
      }
    }
  }
}
  
  
void select(card n[]){
  
  int min,i,j,tmp;
  char tmpc;
  for(i=0;i<number;i++){
    min=i;
    for(j=i;j<number;j++){
      if(n[j].num<n[min].num){
    min=j;
      }
    }
    if(min != i){
      tmp=n[i].num;
      n[i].num=n[min].num;
      n[min].num=tmp;
  
      tmpc=n[i].c;
      n[i].c=n[min].c;
      n[min].c=tmpc;
    }
  }
}
  
int search(card data[],card data2[]){
  int i,count=0;
    for(i=0;i<number;i++){
      if(data[i].c != data2[i].c || data[i].c != data2[i].c){
    return False;
      }
    }
    return True;
}

