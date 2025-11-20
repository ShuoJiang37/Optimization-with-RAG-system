#include<stdio.h>

typedef struct{
  char M[36];
  int N[36];
}Card;

int main(){
  int i,j,m,n,minj,F=0;
  char l;
  Card card1,card2;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%*c%c%d",&card1.M[i],&card1.N[i]);
  }

  card2=card1;
  
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(card1.N[j]<card1.N[j-1]){
	m=card1.N[j];
	card1.N[j]=card1.N[j-1];
	card1.N[j-1]=m;

	l=card1.M[j];
	card1.M[j]=card1.M[j-1];
	card1.M[j-1]=l;
      }
    }
  }

  for(i=0;i<n-1;i++){
    printf("%c%d ",card1.M[i],card1.N[i]);
  }
  printf("%c%d\n",card1.M[i],card1.N[i]);
  printf("Stable\n");

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(card2.N[j]<card2.N[minj]){
	minj=j;
      }
    }
    if(minj!=i){
      m=card2.N[i];
      card2.N[i]=card2.N[minj];
      card2.N[minj]=m;
      
      l=card2.M[i];
      card2.M[i]=card2.M[minj];
      card2.M[minj]=l;
    }
  }

  for(i=0;i<n-1;i++){
    printf("%c%d ",card2.M[i],card2.N[i]);
  }
  printf("%c%d\n",card2.M[i],card2.N[i]);

  for(i=0;i<n;i++){
    if(card1.M[i]!=card2.M[i]) F=1;
  }

  if(F==0) printf("Stable\n");
  else if(F==1) printf("Not stable\n");
  
  return 0;
}

