#include<stdio.h>

typedef struct Card{
  char name;
  int number;
}card;

void bubbleSort(card [],int);
void selection(card [],int);
void phyouzi(card [],int);
int isStable(card [],card [],int);

int main(){
  card c1[100],c2[100];
  int i,n;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf(" %c%d",&c1[i].name,&c1[i].number);
    c2[i]=c1[i];
  }
  
  bubbleSort(c1,n);
  selection(c2,n);

  
  for(i=0;i<n;i++){

    if(i==n-1){
      printf("%c%d",c1[i].name,c1[i].number);
    }
    else{
      printf("%c%d ",c1[i].name,c1[i].number);
    }

  }
  printf("\n");

  printf("Stable\n");
  
  for(i=0;i<n;i++){
    
    if(i==n-1){
      printf("%c%d",c2[i].name,c2[i].number);
    }
    else{
      printf("%c%d ",c2[i].name,c2[i].number);
    }
  }
  printf("\n");

  if(isStable(c1,c2,n)){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }
  return 0;
}

void bubbleSort(card x[],int n){
  int i,j;
  card tmp;
  
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(x[j].number<x[j-1].number){
	tmp=x[j];
	x[j]=x[j-1];
	x[j-1]=tmp;
      }
    }
  }
}

void selection(card x[],int n){
  int i,j,minj;
  card tmp;
  
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(x[j].number<x[minj].number) minj=j;
    }
    tmp=x[i];
    x[i]=x[minj];
    x[minj]=tmp;
  }
}
void phyouzi(card x[],int n){
  int i;

  for(i=0;i<n;i++){
    if(i>0){
      printf(" ");
    }
    printf("%c%d",x[i].name,x[i].number);
  }
  printf("\n");
}

int isStable(card c1[],card c2[],int n){
  int i;
  for(i=0;i<n;i++){
    if(c1[i].name != c2[i].name)
      return 0;
  }
  return 1;
}


