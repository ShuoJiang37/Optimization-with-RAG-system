#include <stdio.h>

typedef struct{
  char egara;
  int value;
} card;

int main()
{
  int i,j,N,minj,judge=0;
  card C[36],C2[36],c;


  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf(" %c%d",&C[i].egara,&C[i].value);
  }
  for(i=0;i<N;i++){
    C2[i]=C[i];
  }


  /* BubbleSort */
  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(C[j].value < C[j-1].value){
	c = C[j];
	C[j] = C[j-1];
	C[j-1]=c;
      }
    }
  }


  /* SelectionSort */
  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(C2[j].value < C2[minj].value){
	minj = j;
      }
    }
    if(minj!=i){
      c = C2[i];
      C2[i] = C2[minj];
      C2[minj]=c;
    }
  }

  for(i=0;i<N-1;i++){
    printf("%c%d ",C[i].egara,C[i].value);
  }
  printf("%c%d\n",C[i].egara,C[i].value);

  printf("Stable\n");

  for(i=0;i<N-1;i++){
    printf("%c%d ",C2[i].egara,C2[i].value);
  }
  printf("%c%d\n",C2[i].egara,C2[i].value);

  /* 比較 */
  for(i=0;i<N;i++){
    if(C2[i].egara!=C[i].egara){
      judge=1;
      break; 
    }
  }
  if(judge==1) printf("Not stable\n");
  else printf("Stable\n");
  return 0;
}