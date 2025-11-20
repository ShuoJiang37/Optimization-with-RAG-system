#include<stdio.h>
#include<stdlib.h>

typedef struct {
  char M;
  int N;
} Card;

void swap(Card *a,Card *b){
  Card tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}
void BubbleSort(Card *s,int n){
  int j,i;
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(s[j].N<s[j-1].N) swap(&s[j],&s[j-1]);
    }
  }
}

void SelectionSort(Card *d,int n){
  int i,j,min;
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(d[j].N<d[min].N) min=j;
    }
    swap(&d[i],&d[min]);
  }
}

int Stable(Card *s,Card *d,int n){
  int i;
  for(i=0;i<n;i++){
    if(s[i].M!=d[i].M) return 0;
  }
  return 1;
}
	
	

int main(){
  int n,i;
  Card s[40],d[40];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&s[i].M,&s[i].N);
    d[i]=s[i];
  }
  BubbleSort(s,n);
  SelectionSort(d,n);
  for(i=0;i<n;i++){
    if(i) printf(" ");
    printf("%c%d",s[i].M,s[i].N);
  }
  printf("\nStable\n");
  for(i=0;i<n;i++){
    if(i) printf(" ");
    printf("%c%d",d[i].M,d[i].N);
  }
  if(Stable(s,d,n)) printf("\nStable\n");
  else printf("\nNot stable\n");
  return 0;
}
  

