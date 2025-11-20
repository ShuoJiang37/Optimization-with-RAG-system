#include<stdio.h>
#define NN 36
void show(int *,char *,int);
int check(char*,char *,int);
int main(){
  
  int i,j,n,foo,N[NN],A[NN],minA,mini;

  
  char C[NN],B[NN],Che[NN],hoge;
  scanf("%d",&n);

  
  for(i=0;i<n;i++){
    scanf(" %c%d",&C[i],&N[i]);
  }

  
  for(i=0;i<n;i++){
    A[i]=N[i];
    B[i]=C[i];
  }
  
  for(i=0;i<n-1;i++){//BS
    for(j=n-1;j>i;j--){
      if(A[j]<A[j-1]){
	foo=A[j];
	A[j]=A[j-1];
	A[j-1]=foo;
	hoge=B[j];
	B[j]=B[j-1];
	B[j-1]=hoge;
    }
    }
  }
    show(A,B,n);//BS show
      printf("Stable\n");

  for(i=0;i<n;i++){
    Che[i]=B[i];
    A[i]=N[i];
    B[i]=C[i];
  }
    
    for(i=0;i<n-1;i++){//SS
    minA=A[i];
    mini=i;
    for(j=i+1;j<n;j++){
      if(minA>A[j]){
	minA=A[j];
	mini=j;
      }
    }
    if(i!=mini){
    A[mini]=A[i];
    A[i]=minA;
    hoge=B[mini];
    B[mini]=B[i];
    B[i]=hoge;
    }
  }
    show(A,B,n);//SS show
    if(check(B,Che,n)==1)
      printf("Stable\n");
    else
      printf("Not stable\n");
  return 0;
}
   void show(int A[],char B[],int n){
     int i;
for(i=0;i<n;i++){
      if(i!=0)
	printf(" ");
      printf("%c%d",B[i],A[i]);
    }
 printf("\n");
   }
int check(char B[],char Che[],int n){
  int i;
  for(i=0;i<n;i++){
    if(B[i]!=Che[i])
      return 0;
  }
  return 1;
    
}

