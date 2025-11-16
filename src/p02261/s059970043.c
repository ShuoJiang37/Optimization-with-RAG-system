#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
  int n;
  char c;
}member;

void selectionSort(member *,int);
void bubbleSort(member *,int);
void swap(member *,member *);
int main(){
  int i,n,flag=0;
  member *buble,*selection;
  scanf("%d",&n);
  buble = (member *)malloc(n * sizeof(member));
  selection = (member *)malloc(n * sizeof(member));
  for(i=0;i<n;i++){
    scanf(" %c",&buble[i].c);
    scanf("%d",&buble[i].n);
  }
  for(i=0;i<n;i++){
    selection[i]=buble[i];
  }
  bubbleSort(buble,n);
  for(i=0;i<n;i++){
    printf("%c%d",buble[i].c,buble[i].n);
    if(i!=n-1){
      printf(" ");
    }
    else printf("\n");
  }
  printf("Stable\n");

  selectionSort(selection,n);
  for(i=0;i<n;i++){
    printf("%c%d",selection[i].c,selection[i].n);
    if(i!=n-1){
      printf(" ");
    }
    else printf("\n");
  }
  for(i=0;i<n;i++){
    if(buble[i].n==selection[i].n && buble[i].c!=selection[i].c){
      flag=1;
      break;
    }
  }
  if(flag==0)printf("Stable\n");
  else printf("Not stable\n");


  
  return 0;
}

void bubbleSort(member *m,int n){
  int flag=1,i;
  while(flag){
    flag=0;
    for(i=n-1;i>0;i--){
      if(m[i].n < m[i-1].n){
        swap(&m[i],&m[i-1]);
        flag=1;
      }
    }
  }
}

void selectionSort(member *m,int n){
  int i,j,minj;
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(m[j].n < m[minj].n){
        minj = j;
      }
    }
    if(minj!=i){
      swap(&m[minj],&m[i]);
    }
  }
}

void swap(member *x,member *y){
  member r;
  r=*x;
  *x=*y;
  *y=r;
}

