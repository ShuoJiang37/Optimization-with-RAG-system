#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  char moji;
  int value;
}Node;

void bubbleSort(Node *,int);
void selectionSort(Node *,int);

int cnt=0;

int main(){
  int i,n,flg=0;
  Node array[36],bubble[36],select[36];
  scanf("%d",&n);
  if(n<1 || n>100) exit(2);
  for(i=0;i<n;i++){
    scanf(" %c%d",&array[i].moji,&array[i].value);
    bubble[i] = select[i] = array[i];
  }
  selectionSort(select,n);
  bubbleSort(bubble,n);
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%c%d",bubble[i].moji,bubble[i].value);
  }
  printf("\nStable\n");
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%c%d",select[i].moji,select[i].value);
    if(select[i].moji != bubble[i].moji || select[i].value != bubble[i].value)flg=1;
  }
  if(flg==0) printf("\nStable\n");
  else printf("\nNot stable\n");
  return 0;
}

void bubbleSort(Node arr[],int n){
  int i,j,tmp;
  Node change;
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(arr[j-1].value > arr[j].value){
	change = arr[j];
	arr[j] = arr[j-1];
	arr[j-1] = change;
      }
    }
  }
}

void selectionSort(Node arr[],int n){
  int i,j,tmp,min;
  Node change;
  for(i=0;i<n-1;i++){
    min=i;
    for(j=i+1;j<n;j++){
      if(arr[min].value > arr[j].value) min=j;
    }
      change = arr[i];
      arr[i] = arr[min];
      arr[min] = change;
  }
}

