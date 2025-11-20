#include <stdio.h>

#define TRUE 1
#define FALSE -1
#define M 36

typedef struct{
  char mark;
  int value;
}TRUMP;

int isStable(TRUMP *, TRUMP *,int);

int main(){
  TRUMP C1[M],C2[M],in[M];
  char m;
  int i,j,v,minj,N;

  scanf("%d",&N);
 
  for(i=0;i<N;i++){
    scanf(" %c%d",&C1[i].mark,&C1[i].value);
    C2[i]=C1[i];
    in[i]=C1[i];
  }

  /*
  for(i=0;i<N;i++) printf("%c%d ",C1[i].mark,C1[i].value);
  printf("\n");
  for(i=0;i<N;i++) printf("%c%d ",C2[i].mark,C2[i].value);
  printf("\n");
  for(i=0;i<N;i++) printf("%c%d ",in[i].mark,in[i].value);
  printf("\n");
  */

  //BubbleSort(C,N)
  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(C1[j].value < C1[j-1].value){
	//swap_v(&C1[j].value,&C1[j-1].value);
	v=C1[j].value;
	C1[j].value=C1[j-1].value;
	C1[j-1].value=v;
	//swap(&C[j].mark,&C[j-1].mark);
	m=C1[j].mark;
	C1[j].mark=C1[j-1].mark;
	C1[j-1].mark=m;
      }
    }
  }
  
  for(i=0;i<N;i++){
    printf("%c%d",C1[i].mark,C1[i].value);
    if(i!=N-1) printf(" ");
  }
  printf("\n");
  if(isStable(in,C1,N)==TRUE) printf("Stable\n");
  else printf("Not stable\n");


	 
  //SelectionSort(C,N)
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(C2[j].value < C2[minj].value) minj=j;
    }
    //swap_v(&C2[i].value,&C2[minj].value);
    v=C2[i].value;
    C2[i].value=C2[minj].value;
    C2[minj].value=v;
    //swap(&C2[i].mark,&C2[minj].mark);
    m=C2[i].mark;
    C2[i].mark=C2[minj].mark;
    C2[minj].mark=m;
  }

  for(i=0;i<N;i++){
    printf("%c%d",C2[i].mark,C2[i].value);
    if(i!=N-1) printf(" ");
  }
  printf("\n");
  if(isStable(in,C2,N)==TRUE) printf("Stable\n");
  else printf("Not stable\n");

  
  return 0;
}

int isStable(TRUMP *in, TRUMP *out, int N){
  int i,j,a,b;
  for(i=0;i<N-1;i++){
    for(j=i+1;j<N-1;j++){
      for(a=0;a<N-1;a++){
	for(b=a+1;b<N-1;b++){
	  if(in[i].value==in[j].value && //in[i].mark==in[j].mark &&
	     in[i].value==out[b].value && in[i].mark==out[b].mark &&
	     in[j].value==out[a].value && in[j].mark==out[a].mark) return FALSE;
	}
      }
    }
  }
  return TRUE;
}

