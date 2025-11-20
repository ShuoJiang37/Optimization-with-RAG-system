#include<stdio.h>

typedef struct{
  char kind;
  int value;
}array;

int main(){
  int i,j,minj,a,b,N,flag_S=1,flag_B=1;
  array C[36],B[36],S[36],temp;
  scanf("%d",&N);
  for(i=0;i < N;i++){
    scanf(" %c",&C[i].kind);
    scanf("%d",&C[i].value);

    B[i] = S[i] = C[i];
  }
  
  //Bubble
  for(i=0;i < N;i++){
    for(j=N-1;j > i;j--){
      if(B[j].value < B[j-1].value){
	temp = B[j];
	B[j] = B[j-1];
	B[j-1] = temp;
      }
    }
  }
  //Select
  for(i=0;i < N;i++){
    minj = i;
    for(j=i;j < N;j++){
      if(S[j].value < S[minj].value){
	minj = j;
      }
    }

    temp = S[i];
    S[i] = S[minj];
    S[minj] =temp;
  }
  //judge of B
  for(i=0;i < N;i++){
    for(j=i+1;j < N;j++){
      for(a=0;a < N;a++){
	for(b=a+1;b < N;b++){
          if(C[i].value == C[j].value){
	    if(C[i].value == B[b].value && C[i].kind == B[b].kind){
	      if (C[j].value == B[a].value && C[j].kind == B[a].kind){
		flag_B = 0;
	      }
	    }
	  }
	}
      }
    }
  }
  //judge of S
  for(i=0;i < N;i++){
    for(j=i+1;j < N;j++){
      for(a=0;a < N;a++){
	for(b=a+1;b < N;b++){
           if(C[i].value == C[j].value){
	    if(C[i].value == S[b].value && C[i].kind == S[b].kind){
	      if (C[j].value == S[a].value && C[j].kind == S[a].kind){
		flag_S = 0;
	      }
	    }
	  }
	}
      }
    }
  }
  
  for(i=0;i<N;i++){
    if(i != 0) printf(" ");
    printf("%c%d",B[i].kind,B[i].value);
  }
  if(flag_B==1) printf("\nStable\n");
  else printf("\nNot stable\n");
  
  for(i=0;i < N;i++){
    if(i != 0) printf(" ");
    printf("%c%d",S[i].kind,S[i].value);
  }
  if(flag_S==1) printf("\nStable\n");
  else printf("\nNot stable\n");
  
  return 0;
}

