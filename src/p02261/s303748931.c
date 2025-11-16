#include<stdio.h>
#define MAX 36
typedef struct{
  char mark;
  int num;
}CARD;

void bubblesort(CARD*,int);
void selectionsort(CARD*,int);

int main()
{
  int n,flag=0,i;
  CARD A[101],B[101];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&A[i].mark,&A[i].num);
    
    B[i].mark=A[i].mark;
    B[i].num=A[i].num;
   
                  }
  bubblesort(A,n);
 for(i=0;i<n;i++){
    printf("%c%d",A[i].mark,A[i].num);
    
    if(i!=n-1) printf(" ");
  }
  printf("\n");
  printf("Stable\n");
  
  selectionsort(B,n);

  for(i=0;i<n;i++){
    printf("%c%d",B[i].mark,B[i].num);
    if(i!=n-1) printf(" ");
  }
  printf("\n");
  
  for(i=0;i<n;i++){
    if(A[i].mark!=B[i].mark)flag=1;
    else if(A[i].num!=B[i].num)flag=1;
  }
  if(flag==0)printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}

void bubblesort(CARD*A,int n)
{
  int i,j;
  CARD x;
  for(i=0;i<=n-1;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j].num<A[j-1].num){
	x=A[j];
	A[j]=A[j-1];
	A[j-1]=x;            }
	                 }
                    }
}

void selectionsort(CARD*B,int n)
{
  int i,j,mini;
  CARD x;
  for(i=0;i<=n-1;i++){
    mini=i;
    for(j=i;j<n;j++){
      if(B[j].num<B[mini].num)mini=j;
                   }
    x=B[i];
    B[i]=B[mini];
    B[mini]=x;
                    }
}


