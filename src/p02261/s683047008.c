#include<stdio.h>
typedef struct Card{
  char suit;
  int value;
  int id;
}card;
void bubblesort(card c[],int n);
void selectionsort(card c[],int n);
void sorns(card c[],int n);
int main(){
  int N,i;
  scanf("%d",&N);
  card c1[N];
  card c2[N];
  for(i=0;i<N;i++){
    scanf(" %c%d",&c1[i].suit,&c1[i].value);
    c1[i].id=i;
    c2[i]=c1[i];
  }  
  bubblesort(c1,N);
  selectionsort(c2,N);
  /*bubble sort*/
  for(i=0;i<N;i++){
    printf("%c%d",c1[i].suit,c1[i].value);
    if(i<N-1){
      printf(" ");
    }
  }
  printf("\n");
  sorns(c1,N);
  /*selectionsort*/
  for(i=0;i<N;i++){
    printf("%c%d",c2[i].suit,c2[i].value);
    if(i<N-1){
      printf(" ");
    }
  }
  printf("\n");
  sorns(c2,N);
  return 0;
}
void bubblesort(card c[],int n){
  int i,j;
  card temp;
  for(i=0;i<=n-1;i++){
    for(j=n-1;j>=i+1;j--){
      if(c[j].value<c[j-1].value){
	temp = c[j];
	c[j] = c[j-1];
	c[j-1] = temp;
      }
    }
  }
}
void selectionsort(card c[],int n){
  int i,j,minj;
  card temp;
  for(i = 0;i<=n-1;i++){
    minj = i;
    for(j = i;j<=n-1;j++){
      if(c[j].value < c[minj].value){
	minj = j;
      }
    }
    temp = c[i];
    c[i] = c[minj];
    c[minj] = temp;
  }
}
void sorns(card c[],int n){
  int stable=1,i;
  for(i=1;i<n;i++){
    if(c[i-1].value == c[i].value && c[i-1].id > c[i].id) stable=0;
  }
  if(stable==1)printf("Stable\n");
  else printf("Not stable\n");
}
