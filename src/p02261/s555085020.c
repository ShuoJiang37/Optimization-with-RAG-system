#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void BubbleSort(char (*A)[3],int n);
void SelectionSort(char (*A)[3],int n);
int  judge(char (*A)[3],char (*B)[3],int n);
int main(){
  int n,i;
  char A[36][3],B[36][3],C[36][3];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s ",A[i]);
  }
  for(i=0;i<n;i++){
    strcpy(B[i],A[i]);
    strcpy(C[i],A[i]);
  }
  BubbleSort(B,n);
  judge(A,B,n);
  SelectionSort(C,n);
  judge(A,C,n);
  return 0;
}
void BubbleSort(char (*B)[3],int n){
  int i,j;
  char c[3];
  for(i=0;i<n;i++){
    for(j=n-1;i<j;j--){
      if(B[j][1]<B[j-1][1]){
      	strcpy(c,B[j]);
	strcpy(B[j],B[j-1]);
	strcpy(B[j-1],c);
      }
    }
  }
  printf("%s",B[0]);
  for(i=1;i<n;i++){
    printf(" %s",B[i]);
  }
  printf("\n");
}
void SelectionSort(char (*C)[3],int n){
  int i,j,minj;
  char c[3];
  for(i=0;i<n;i++){
    minj=i;
    for(j=i+1;j<n;j++){
      if(C[j][1]<C[minj][1]){
	minj=j;
      }
    }
    strcpy(c,C[i]);
    strcpy(C[i],C[minj]);
    strcpy(C[minj],c);
  }
  printf("%s",C[0]);
  for(i=1;i<n;i++){
    printf(" %s",C[i]);
	}
	printf("\n");
}
int judge(char (*A)[3],char (*B)[3],int n){
  int i,j,k,minj,flag=0;
  char c[2][3];
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      //printf("A[%d][1]:%c A[%d][1]:%c\n",i,A[i][1],j,A[j][1]);
      if(A[i][1]==A[j][1]){
	//printf("A[%d][1]:%c == A[%d][1]:%c\n",i,A[i][1],j,A[j][1]);
	strcpy(c[0],A[i]);
	strcpy(c[1],A[j]);
	for(k=0;k<n-1;k++){
	  // printf("c[0]:%s B[%d]:%s\n",c[0],j,B[k]);
	  if(c[0][1]==B[k][1]&&c[0][0]==B[k][0]){
	    //printf("c[0]:%s == B[%d]:%s\n",c[0],j,B[k]);
	    if(c[1][1]!=B[k+1][1]||c[1][0]!=B[k+1][0]){
	      //printf("c[1][1]:%c !=B[%d][1]:%c || c[1][0]:%c !=B[%d][1]:%c\n"  ,c[1][1],k+1,B[k+1][1],c[1][0],k+1,B[k+1][0]);
	      //printf("flag=1\n");
	      flag=1;
	    }
	  }
	}
	break;
      }
    }
  }
  if(flag==1){
    printf("Not stable\n");
  }
  if(flag==0){
    printf("Stable\n");
    }
}

