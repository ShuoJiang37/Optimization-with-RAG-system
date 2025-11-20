#include<stdio.h>
#include<string.h>
#define N 100

void BubbleSort(char (*)[3],int);
void SelectionSort(char (*)[3],int);

int main(){
  int i,j,n,temp,cnt=0,minj;
  char A[N][3],B[N][3],S[N][3];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",A[i]);
    strcpy(B[i],A[i]);
    strcpy(S[i],A[i]);
  }
  BubbleSort(B,n);
  SelectionSort(S,n);

  int check=0;
  for(i=0;i<n;i++){
    if(strcmp(B[i],S[i])!=0)check=1;
  }
  if(check==0) printf("Stable\n");
  else printf("Not stable\n");
  return 0;
}
void BubbleSort(char A[N][3],int n){
  int i,j;
  char temp[3];
      for(i=0;i<n;i++){
	for(j=n-1;j>i;j--){
	  if(A[j][1]<A[j-1][1]){
	  strcpy(temp,A[j]);
	  strcpy(A[j],A[j-1]);
	  strcpy(A[j-1],temp);
	  }
	}
      }
      for(i=0;i<n-1;i++){
	printf("%s ",A[i]);
      }
     printf("%s\n",A[n-1]);
     printf("Stable\n");
}
void SelectionSort(char A[N][3],int n){
  int i,j,minj;
  char temp[3];
    for(i=0;i<n;i++){
      minj=i;
      for(j=i;j<n;j++){
	if(A[j][1]<A[minj][1])minj=j;
      }
      strcpy(temp,A[i]);
      strcpy(A[i],A[minj]);
      strcpy(A[minj],temp);
    }
  for(i=0;i<n-1;i++){
  printf("%s ",A[i]);
  }
  printf("%s\n",A[n-1]);
}



