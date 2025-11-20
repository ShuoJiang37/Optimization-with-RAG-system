#include<stdio.h>
#include<string.h>
#define N 36
typedef struct{
  int value;
  char c;
}Record;

void bubble(Record A[],int n){
  int i,j;
  Record s;
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1; j--){
      if(A[j].value < A[j-1].value){
	s= A[j];
	A[j] = A[j-1];
	A[j-1] = s;
      }
    }
  }
}

void selection(Record S[],int n){
  int i,j,minj;
  Record s;
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j < n; j++){
      if(S[j].value < S[minj].value)minj = j;
    }
    s = S[i];
    S[i]= S[minj];
    S[minj] = s;
  }
}

int hantei(Record A[],Record S[],int n){
  int i,flag;
  for(i=0; i<n; i++){
    if(A[i].c==S[i].c)flag = 0;
    else return -1;
  }
  return flag;
}


int main(){
  Record A[N],S[N];
  int n,i,j,judge;
  char c;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&A[i].c,&A[i].value);
    S[i]=A[i];
  }
  //デバッグ用
  /*
  printf("デバッグ用\n");
  for(i=0;i<n-1;i++){
   printf("%c%d ",A[i].c,A[i].value);
 }
 printf("%c%d\n",A[n-1].c,A[n-1].value);
 for(i=0;i<n-1;i++){
  printf("%c%d ",S[i].c,S[i].value);
 }
 printf("%c%d\n",S[n-1].c,S[n-1].value);
  printf("ここまで\n");
  //ここまで
  */
  
    
    
    bubble(A,n);
  selection(S,n);

  for(i=0;i<n-1;i++){
  printf("%c%d ",A[i].c,A[i].value);
    }
  printf("%c%d\n",A[n-1].c,A[n-1].value);
  printf("Stable\n");
  
  for(i=0;i<n-1;i++){
  printf("%c%d ",S[i].c,S[i].value);
    }
  printf("%c%d\n",S[n-1].c,S[n-1].value);
  judge = hantei(A,S,n);
  if(judge==0)printf("Stable\n");
  else printf("Not stable\n");
  
  return 0;
}

