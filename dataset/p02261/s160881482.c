#include<stdio.h>

#define N 36

char C[N],C_s[N];
int C2[N],C2_s[N];

void BubbleSort(int n){
  int i,j,flag;
  int x;
  char c;

  for(i=0;i<n-1;i++){
    flag = 1;
    while(flag){
      flag = 0;
      for(j=n-1;j>=i;j--){
	if(C2_s[j]<C2_s[j-1]){
	  x = C2_s[j];
	  c = C_s[j];
	  C2_s[j] = C2_s[j-1];
	  C_s[j] = C_s[j-1];
	  C2_s[j-1] = x;
	  C_s[j-1] = c;
	}
      }
    }
  }
}

void SelectionSort(int n){
  int i,j,minj;
  int x;
  char c;

  for(i=0;i<n-1;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(C2[j]<C2[minj]){
	minj = j;
      }
    }
    if(minj!=i){
      c = C[i];
      x = C2[i];
      C[i] = C[minj];
      C2[i] = C2[minj];
      C[minj] = c;
      C2[minj] = x;
    }
  }
}

int main(){

  int n,flag;
  int i,j,minj;
  int x;
  char c;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%c",&C[i]);
    if(C[i]!='D'&&C[i]!='C'&&C[i]!='H'&&C[i]!='S') scanf("%c",&C[i]);
    scanf("%d",&C2[i]);
  }


  for(i=0;i<n;i++){
    C_s[i] = C[i];
    C2_s[i] = C2[i];
  }

  BubbleSort(n);

  SelectionSort(n);
  

  for(i=0;i<n;i++){
    printf("%c%d",C_s[i],C2_s[i]);
    if(i<n-1) printf(" ");
  }
  printf("\nStable\n");
  
  for(i=0;i<n;i++){
    printf("%c%d",C[i],C2[i]);
    if(i<n-1) printf(" ");
  }

  flag = 0;
  for(i=0;i<n;i++){
    if(C2[i]!=C2_s[i] || C[i]!=C_s[i]){
      flag = 1;
      break;
    }
  }
  if(flag==0) printf("\nStable\n");
  else printf("\nNot stable\n");
  
  return 0;
}

