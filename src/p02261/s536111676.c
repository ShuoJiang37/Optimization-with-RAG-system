#include<stdio.h>
#include<string.h>
int henkan(char);
void bubbleSort(char *,char *,int);
void selectionSort(char *,char *,int);

int main(){
  char A1[40],A2[40];
  char B1[40],B2[40];
  char C[2];
  int N;
  int i;
  int flag=1;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%s",C);
    A1[i]=B1[i]=C[0];
    A2[i]=B2[i]=C[1];
  }
  bubbleSort(A1,A2,N);
  for(i=0;i<N;i++){
    printf("%c%c",A1[i],A2[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n");
  printf("Stable\n");
  selectionSort(B1,B2,N);
  for(i=0;i<N;i++){
    printf("%c%c",B1[i],B2[i]);
    if(i!=N-1) printf(" ");
    if(A1[i]!=B1[i] || A2[i]!=B2[i]) flag=0;
    }
  printf("\n");
  if(flag) printf("Stable");
  else printf("Not stable");
  printf("\n");

  return 0;
  
}
int henkann(char c){
  return c-48;
}
void bubbleSort(char A1[],char A2[],int N){
  int flag=1;
  int j;
  char tmp1,tmp2;
  while(flag){
    flag=0;
    for(j=N-1;j>0;j--){
      if(henkann(A2[j])<henkann(A2[j-1])){
	tmp2=A2[j];
	tmp1=A1[j];
	A2[j]=A2[j-1];
	A1[j]=A1[j-1];
	A2[j-1]=tmp2;
	A1[j-1]=tmp1;
	flag=1;
      }
    }
  }
}

void selectionSort(char A1[],char A2[],int N){
  int i,j,minj;
  char tmp1,tmp2;
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A2[minj]>A2[j]){
	minj=j;
      }
    }
    tmp2=A2[i];
    tmp1=A1[i];
    A2[i]=A2[minj];
    A1[i]=A1[minj];
    A2[minj]=tmp2;
    A1[minj]=tmp1;
  }
}
