#include <stdio.h>

void bubbleSort(char B[],int n);
void selectionSort(char A[],int n);

int main(){

  char A[72],B[72];
  int n,i,j,c=0;
  
  while(1){
    scanf("%d",&n);
    if(1<=n&&n<=36){
      for(i=0;i<2*n;i=i+2){
	scanf("%s", &A[i]);
      }
      break;
    }
  }

  for(i=0;i<2*n;i=i+2){
    B[i]=A[i];
    B[i+1]=A[i+1];
  }

  bubbleSort(B,n);
  selectionSort(A,n);

  for(i=0;i<2*n;i=i+2){
    if(i>0) printf(" ");
    printf("%c%c",B[i],B[i+1]);
  }
  printf("\n");
  printf("Stable\n");

  for(i=0;i<2*n;i=i+2){
    if(i>0) printf(" ");
    printf("%c%c",A[i],A[i+1]);
  }
  printf("\n");
  for(i=0;i<2*n;i=i+2){
    if(A[i]==B[i]&&A[i+1]==B[i+1]) c++;
    else {
      printf("Not stable\n");
      break;
    }

  }
  if(c==n) printf("Stable\n");
  return 0;
}

void selectionSort(char A[],int n){
  int i,j,min;
  char t,c;
  for(i=1;i<2*n;i=i+2){
    min=i;
    for(j=i;j<2*n;j++){
      if(A[min]>A[j]) min=j;
    }
    if(A[min]!=A[i]){
      t=A[i];
      c=A[i-1];
      A[i]=A[min];
      A[i-1]=A[min-1];
      A[min]=t;
      A[min-1]=c;
    }
  }
}

void bubbleSort(char B[],int n){
  int i,j;
  char c,t;
  for(i=1;i<2*n;i=i+2){
    for(j=2*n-1;j>=i;j=j-2){
      if(B[j]<B[j-2]) {
	t=B[j];
	c=B[j-1];
	B[j]=B[j-2];
	B[j-2]=t;
	B[j-1]=B[j-3];
	B[j-3]=c;
      }
    }
  }
}

