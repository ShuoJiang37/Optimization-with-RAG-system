#include<stdio.h>

typedef struct{
  char suit;
  int num;
}CARD;

int main(){


  int i,j,a,b,n,minj,flag=1;
  CARD A[36],B[36],temp;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf(" %c%d",&A[i].suit,&A[i].num);
    B[i].suit=A[i].suit;
    B[i].num=A[i].num;
  }


  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j].num < A[j-1].num){
	temp.suit=A[j].suit;
	temp.num=A[j].num;
	
	A[j].suit=A[j-1].suit;
	A[j].num=A[j-1].num;
	A[j-1].suit=temp.suit;
	A[j-1].num=temp.num;

      }
    }
  }



  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(B[j].num < B[minj].num){
	minj=j;
      }
    }
    temp.suit=B[i].suit;
    temp.num=B[i].num;
    B[i].suit=B[minj].suit;
    B[i].num=B[minj].num;
    B[minj].suit=temp.suit;
    B[minj].num=temp.num;
  }


  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      for(a=0;a<n;a++){
	for(b=a+1;b<n;b++){
	  if((A[i].num==A[j].num)&&(A[i].suit==B[b].suit)&&(A[i].num==B[b].num)&&(A[j].suit==B[a].suit)&&(A[j].num==B[a].num)){
	    flag=0;
	  }
	}
      }
    }
  }


  for(i=0;i<n-1;i++){
    printf("%c%d ",A[i].suit,A[i].num);
  }
  printf("%c%d\n",A[n-1].suit,A[n-1].num);
  printf("Stable\n");

  for(i=0;i<n-1;i++){
    printf("%c%d ",B[i].suit,B[i].num);
  }
  printf("%c%d\n",B[n-1].suit,B[n-1].num);
  if(flag==1){
    printf("Stable\n");
  }
  else printf("Not stable\n");


  return 0;
}

