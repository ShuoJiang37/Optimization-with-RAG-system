#include <stdio.h>
#define MAX 40
int N;
char C1[MAX],C2[MAX];
int D1[MAX],D2[MAX];
void Printf1(void){
  int i;
  for(i=0;i<N-1;i++){
    printf("%c%d ",C1[i],D1[i]);
  }
  printf("%c%d",C1[N-1],D1[N-1]);

}
void Printf2(void){
  int i;
  for(i=0;i<N-1;i++){
    printf("%c%d ",C2[i],D2[i]);
  }
  printf("%c%d",C2[N-1],D2[N-1]);

}
void BubbleSort(void){
  int i,j,c;
  char m;
  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(D1[j]<D1[j-1]){
	c=D1[j-1];
	D1[j-1]=D1[j];
	D1[j]=c;
	m=C1[j-1];
        C1[j-1]=C1[j];
        C1[j]=m;

      }

    }
  }
  Printf1();
  printf("\nStable\n");
}
void SelectionSort(void){
  int x=0,i,miji,j;
  char m;
  for(i=0;i<N;i++){
    miji=i;
    for(j=i;j<N;j++){
      if(D2[j]<D2[miji])miji=j;
    }
    x=D2[i];
    D2[i]=D2[miji];
    D2[miji]=x;
    m=C2[i];
    C2[i]=C2[miji];
    C2[miji]=m;
  }
  Printf2();
  for(i=0;i<N;i++){
    if(C1[i]!=C2[i]||D2[i]!=D1[i]){
      printf("\nNot stable\n");
      return;
    }
  }
  
 printf("\nStable\n");
  
}
int main(){
  int x,i;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf(" %c%d",&C1[i],&D1[i]);
    D2[i]=D1[i];
    C2[i]=C1[i];
}
BubbleSort();
 SelectionSort();

  return 0;
}

