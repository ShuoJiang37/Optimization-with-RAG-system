#include<stdio.h>

#define N 36

struct Card{
  char suit;
  char value;
};

void BubbleSort(struct Card * ,int);
void SelectionSort(struct Card * ,int);
void HKK();

int main(){
  struct Card C1[101], C2[101],trnp[N];
  int n, i,hantei=0;
  char ch;
  
  scanf("%d%c", &n, &ch);
  for ( i = 0; i < n; i++ ){
    scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
  }
 for(i=0;i<n;i++){
    C2[i]=C1[i];
  }
  BubbleSort(C1,n);

  SelectionSort(C2,n);
  
  for(i=0;i<n;i++){
    if(C2[i].suit != C1[i].suit){
      hantei=1;
      break;
    } 
  }
  if(hantei==0)printf("Stable\n");
  else printf("Not stable\n");
  
  return 0;
}

void BubbleSort(struct Card A[],int n){
  int i,j,m;
  char key1,key2;
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j].value<A[j-1].value){
	key1=A[j].value;
	A[j].value=A[j-1].value;
	A[j-1].value=key1;
	key2=A[j].suit;
	A[j].suit=A[j-1].suit;
	A[j-1].suit=key2;
      }
    }
  }
  for ( m = 0; m <n; m++ ){
    if ( m > 0 ) printf(" ");
    printf("%c%c",A[m].suit,A[m].value);
  }
  printf("\nStable\n");
}

void SelectionSort(struct Card A[],int n){
  int i,j,m,mini,X;
  char key1,key2;
  for(i=0;i<n;i++){
    mini=i;
    X=0;
    for(j=i;j<n;j++){
      if(A[j].value<A[mini].value){
	mini=j;
	X=1;
      }
    }
    if(X==1){
      key1=A[i].value;
      A[i].value=A[mini].value;
      A[mini].value=key1;
      key2=A[i].suit;
      A[i].suit=A[mini].suit;
      A[mini].suit=key2;
    }
  }
  for ( m = 0; m <n; m++ ){
    if ( m > 0 ) printf(" ");  
    printf("%c%c", A[m].suit,A[m].value);
    
  }
  printf("\n");
}