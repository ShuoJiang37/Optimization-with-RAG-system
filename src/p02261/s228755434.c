#include <stdio.h>
#include <string.h>

void BubbleSort();
void SelectionSort();

int N;
char a1[36][2];
char a2[36][2];

int main(){
  int i,j,n,flag=0;
  char A[36][2];
  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%s",A[i]);
  for(i=0;i<N;i++)
    {
      a1[i][0]=A[i][0];
      a1[i][1]=A[i][1];
      a2[i][0]=A[i][0];
      a2[i][1]=A[i][1];
    }
  
  BubbleSort();
  SelectionSort();

  for(i=0;i<N;i++){
    printf("%c%c",a1[i][0],a1[i][1]);
    if(i<N-1)
      printf(" ");
  }
  printf("\n");
  printf("Stable\n");
  
  for(i=0;i<N;i++){
    printf("%c%c",a2[i][0],a2[i][1]);
    if(i<N-1)
      printf(" ");
  }
  printf("\n");
  for(i=0;i<N;i++)
    if(a1[i][0]!=a2[i][0])
      flag=1;
  if(flag==1)
    printf("Not stable\n");
  else
    printf("Stable\n");
  
  return 0;
}

void BubbleSort(){
  int i,j,B[N],n;
  char keep[2];
  for(i=0;i<N;i++)
    B[i]=a1[i][1]-48;
  for(j=0;j<N;j++){
    for(i=N-1;i>0;i--){
      if(B[i]<B[i-1]){
	n=B[i];
	B[i]=B[i-1];
	B[i-1]=n;
	keep[0]=a1[i][0];
	a1[i][0]=a1[i-1][0];
	a1[i-1][0]=keep[0];
	keep[1]=a1[i][1];
	a1[i][1]=a1[i-1][1];
	a1[i-1][1]=keep[1];
      }
    }
  }
}

void SelectionSort(){
  int i,j,B[N],n,minj;
  char keep[2];
  for(i=0;i<N;i++)
    B[i]=a2[i][1]-48;
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(B[j]<B[minj]){
	minj=j;
      }
    }
    if(i!=minj){
      n=B[i];
      B[i]=B[minj];
      B[minj]=n;
      keep[0]=a2[i][0];
      a2[i][0]=a2[minj][0];
      a2[minj][0]=keep[0];
      keep[1]=a2[i][1];
      a2[i][1]=a2[minj][1];
      a2[minj][1]=keep[1];
    }
  }
}