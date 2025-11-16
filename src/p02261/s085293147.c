#include<stdio.h>
#define N 36

struct card{
  char mark;
  int value;
};

int n;

int isStable(struct card in[],struct card out[]){
  int i,j,a,b;
  for(i = 0; i < n; i++){
    for(j = i+1; j < n; j++){
      for(a = 0; a < n; a++){
	for(b = a+1; b < n; b++){
	  if((in[i].value == in[j].value) && ((in[i].value == out[b].value && in[i].mark == out[b].mark) && (in[j].value == out[a].value && in[j].mark == out[a].mark))) return 0;
	}
      }
    }
  }
  return 1;
}


void bubbleSort(struct card A[],int n){
  int i,j;
  int flag;
  struct card swap;
  flag = 1;
    i = 0;
    while(flag){
       flag = 0;
       for(j = n - 1; j >= i + 1; j--){
           if(A[j].value < A[j - 1].value){
	   swap = A[j];
	   A[j] = A[j - 1];
	   A[j - 1] = swap;
	   flag = 1;
           }
       }
       i++; 
    }
}

void selectionSort(struct card A[],int n){
  int i,j,minj;
  struct card swap;

  for(i = 0; i <= n - 1; i++){
    minj = i;
    for(j = i; j <= n - 1; j++){
      if(A[j].value < A[minj].value) {
	minj = j;
      }
    }
    swap = A[i];
    A[i] = A[minj];
    A[minj] = swap;
  }
}

int main(){
  int i;
  struct card C[N];
  struct card D[N];
  
  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf(" %c",&C[i].mark);
    scanf("%d",&C[i].value);
    D[i] = C[i];
  }
 
  
  bubbleSort(C,n);
  for(i = 0; i < n; i++){
    if(i == n - 1) printf("%c%d",C[i].mark,C[i].value);
    else
    printf("%c%d ",C[i].mark,C[i].value);
  }
  printf("\nStable\n");

  selectionSort(D,n);
  for(i = 0; i < n; i++){
    if(i == n - 1) printf("%c%d",D[i].mark,D[i].value);
    else
    printf("%c%d ",D[i].mark,D[i].value);
  }
  if(isStable(C,D) == 1) printf("\nStable\n");
  else printf("\nNot stable\n");

  return 0;
}



