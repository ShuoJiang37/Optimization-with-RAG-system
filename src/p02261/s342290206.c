#include<stdio.h>
#define N 36


struct Card {
 char suit; int value;
};

void BubbleSort(struct Card A[], int n );
void SelectionSort(struct Card A[], int n );
int judge(struct Card A1[],struct Card A2[],int n);

int main(){
  int i,j,n,flag,a,b=0,m,minj,k;
  struct Card A1[100],A2[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&A1[i].suit,&A1[i].value);
   }for(j=0;j<n;j++){
    A2[j]=A1[j];
   }
  BubbleSort(A1,n);
  SelectionSort(A2,n);
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%c%d",A1[i].suit,A1[i].value);
   }printf("\n");
   printf("Stable\n");
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%c%d",A2[i].suit,A2[i].value);
  }printf("\n");
  if(judge(A1,A2,n)){
    printf("Stable\n");
   }else{
     printf("Not stable\n");
   } return 0;
  }

void BubbleSort(struct Card A[], int n ){
  int i,j;
  struct Card c;
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j].value<A[j-1].value){
        c=A[j];A[j]=A[j-1];A[j-1]=c;
      }
    }
  }
}

void SelectionSort(struct Card A[], int n ){
 int i,j,minj;
 struct Card c;
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(A[j].value<A[minj].value){
        minj=j;
      }
    }c=A[i];A[i]=A[minj];A[minj]=c;
  }
}

int judge(struct Card A1[],struct Card A2[],int n){
  int i;
  for(i=0;i<n;i++){
    if(A1[i].suit!=A2[i].suit){
      return 0;
    }
  }return 1;
}

