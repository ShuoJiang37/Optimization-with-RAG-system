#include <stdio.h>
#include<stdlib.h>
#define Maxnumber 36

int N;

typedef struct{
  int value;
char C;
}Tra;
void isStable(Tra in[], Tra out[]);

int main(){
  int i,con=0,j,flag,minj;
 Tra C[36],tmp,kame1[36],kame2[36];
 char temps[128];
 scanf("%s",temps);

 N = atoi(temps);
 
 for (i = 0; i < N; i++){
   scanf("%s",temps);
   C[i].C = temps[0];
   C[i].value = atoi(&temps[1]);
   kame1[i] = C[i];
   kame2[i] = C[i];
  }

 // Bubble
  for (i = 0 ;i <= N-1;i++){
    for (j = N-1;  j >= i+1;j--){
      if (kame1[j].value < kame1[j-1].value){
	tmp = 	kame1[j];
	kame1[j] = kame1[j-1];
	kame1[j-1] =  tmp;
      }
    }
  }
  
  // Selection
  for (i = 0; i <= N-1;i++){
    minj = i;
       for (j = i;j <=  N-1;j++){
	 if (kame2[j].value < kame2[minj].value){
	   minj = j;
	 }
       }
	tmp = kame2[i];
	kame2[i] = kame2[minj];
	kame2[minj] = tmp;
  }
  
  for (i = 0; i < N-1;i++){
    printf("%c%d ",kame1[i].C,kame1[i].value);
  }
    printf("%c%d\n",kame1[N-1].C,kame1[N-1].value);
  
    isStable(C,kame1);

    for (i = 0; i < N-1;i++){
      printf("%c%d ",kame2[i].C,kame2[i].value);
    }
    printf("%c%d\n",kame2[N-1].C,kame2[N-1].value);
  
    isStable(C,kame2);
  

  
    return 0;
}
void isStable(Tra in[], Tra out[])
{
  int i,j,a,b;
  for (i = 0;i <= N-1;i++){
    for (j = i+1 ;j <= N-1; j++){
      for (a = 0;a <= N-1;a++){
	for (b = a+1;b <= N-1;b++){
	  if (in[i].value == in[j].value  &&
	      in[i].value == out[b].value &&
	      in[i].C == out[b].C &&
	      in[j].value == out[a].value &&
	      in[j].C == out[a].C){
	    printf("Not stable\n");
	    return;
	  }
	}
      }
    }
  }
  printf("Stable\n"); 
}
        
      