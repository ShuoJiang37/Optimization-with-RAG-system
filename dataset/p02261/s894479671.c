#include<stdio.h>

typedef struct{
  char suit;
  char value;
} Card;

void bubble(int,Card []);
void selection(int,Card []);
void isStable(int,Card [] ,Card []);

int main(){
  Card C1[101], C2[101];
  int n, i;
  char ch;

  scanf("%d%c", &n, &ch);
  for ( i = 0; i < n; i++ ){
    scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
    C2[i]=C1[i];
  }
  bubble(n,C1);
  selection(n,C2);
  isStable(n,C1,C2);
  return 0;
}

void bubble(int n,Card c1[]){
  int i,j;
  Card a;
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(c1[j].value < c1[j-1].value){
	a=c1[j-1];
	c1[j-1]=c1[j];
	c1[j]=a;
      }     
    }
  }
  for(i=0;i<n;i++){
    printf("%c%c",c1[i].suit,c1[i].value);
    if(i<n-1){
      printf(" ");
    }
  }
  printf("\nStable\n");
}

void selection(int n,Card c2[]){
  int i,j,mini=0;
  Card a;
  for(i=0;i<n;i++){
    mini=i;
    for(j=i;j<n;j++){
      if(c2[j].value<c2[mini].value){
	mini=j;
      }
    }
    if(c2[i].value != c2[mini].value){ 
      a=c2[i];
      c2[i]=c2[mini];
      c2[mini]=a;
    }
  }
  for(i=0;i<n;i++){
    printf("%c%c",c2[i].suit,c2[i].value);
    if(i<n-1){
      printf(" ");
    }
  }
  printf("\n");
}

void isStable(int n,Card c1[],Card c2[]){
  int i,m=0;

  for(i=0;i<n;i++){
    if(c1[i].suit==c2[i].suit){
      m++;
    } else {
      break;
    }
  }
  if(m==n){
    printf("Stable\n");
  } else {
    printf("Not stable\n");
  }
}