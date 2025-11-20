#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef struct{
  char suit;
  char value;
} Card;

void bubble(Card*,int);
void selection(Card*,int);
int isStable(Card*,Card*,int);

Card C1[100],C2[100];

int main(){
  
  int n,i;
  char ch;
  char S[3];
  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("%s",S);
    C1[i].suit = S[0];
    C1[i].value = S[1];
  }
  for(i=0;i<n;i++) C2[i] = C1[i];

  bubble(C1,n);
  selection(C2,n);

  for(i=0;i<n-1;i++){
    S[0] = C1[i].suit;
    S[1] = C1[i].value;
    printf("%s ",S);
  }
  S[0] = C1[i].suit;
  S[1] = C1[i].value;
  printf("%s\n",S);
  printf("Stable\n");

  for(i=0;i<n-1;i++){
    S[0] = C2[i].suit;
    S[1] = C2[i].value;
    printf("%s ",S);
  }
  S[0] = C2[i].suit;
  S[1] = C2[i].value;
  printf("%s\n",S);
  if(isStable(C1,C2,n)) printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}

void bubble(Card *C,int n){
  int i,j;
  Card tmp;
  for(i=0;i<n;i++){
    for(j=n-1;j>=i;j--){
      if(C[j].value < C[j-1].value){
	tmp = C[j];
	C[j] = C[j-1];
	C[j-1] = tmp;
      }
    }
  }
}

void selection(Card *C,int n){
  int i,j,minj;
  Card tmp;
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(C[j].value < C[minj].value) minj = j; 
    }
    tmp = C[i];
    C[i] = C[minj];
    C[minj] = tmp;
  }
}

int isStable(Card *C1,Card *C2,int n){
  int i;
  for(i=0;i<n;i++){
    if(C1[i].suit != C2[i].suit) return FALSE;
  }
  return TRUE;
}