#include <stdio.h>
#include <string.h>
int isStable(char in[36][3] ,char out[36][3]);
int N;
int main(void){
  int i, j,cnt = 0, minj;
  char CardB[36][3],Check[36][3],CardS[36][3],temp[36];
 
  scanf("%d",&N);


   
  for(i = 0;i < N;i++){
    scanf("%s",&CardB[i]);
    strcpy(Check[i],CardB[i]);
    strcpy(CardS[i],CardB[i]);
  }



  for(i = 0; i < N; i++ ) {
    for(j= N-1; j>i; j--) {
      if(CardB[j][1] < CardB[j-1][1]) {
         strcpy(temp,CardB[j]);
         strcpy(CardB[j],CardB[j-1]);
         strcpy(CardB[j-1],temp);
         
      }

    }
  }
  for(i=0;i<N-1;i++) 
    printf("%s ",CardB[i]);
    printf("%s\n",CardB[i]);
 

  if(isStable(Check,CardB)==1) {
  printf("Stable\n");
}
  else {
    printf("Not stable\n");
  }



for(i = 0; i < N; i++ ) {
    minj = i;
    for(j= i; j < N; j++)  {
      if(CardS[j][1] < CardS[minj][1]) {
         minj = j;
      }
    }
      if(CardS[minj][1] < CardS[i][1]) {
         strcpy(temp,CardS[i]);
         strcpy(CardS[i],CardS[minj]);
         strcpy(CardS[minj],temp);
      }
  }
  

for(i=0;i<N-1;i++) 
    printf("%s ",CardS[i]);
    printf("%s\n",CardS[i]);
  


  if(isStable(Check,CardS)==1) {
  printf("Stable\n");
}
  else {
    printf("Not stable\n");
  }
  return 0;
}

 int isStable(char Check[36][3] , char Solve[36][3]) {
    int i,j,k,l;

    for(i=0;i<N;i++){
      for(j=i+1;j<N;j++){
        for(k=0;k<N;k++){
          for(l=k+1;l<N;l++){
              if((Check[i][1]==Check[j][1])&&(strcmp(Check[i],Solve[l])==0)&&(strcmp(Check[j],Solve[k])==0)) {
                return 0;
              }
          }
        }
      }
    }

  return 1;
}
