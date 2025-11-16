#include<stdio.h>
#include<string.h>

void judge(int n,char[36] [3],char[36][3]);

int main(){
  int i, j, n, minj;
  char temp[36];
  char C_B[36][3], C_S[36][3];

  scanf("%d",&n);

  for( i=0 ; i<n ; i++){
    scanf("%s",C_B[i]);
    strcpy(C_S[i],C_B[i]);
  }
  
//バブルソート開始
  for( i=0 ; i<n ; i++){
    for( j=n-1 ; j>=i+1 ; j--){
      if(C_B[j][1] < C_B[j-1][1]){
	       strcpy(temp,C_B[j-1]);
	       strcpy(C_B[j-1],C_B[j]);
	       strcpy(C_B[j],temp);
      }
    }
    printf("%s",C_B[i]);
    if( i<n-1 ){
      printf(" ");
    }
  }
  printf("\n");
  printf("Stable\n");
  
  //選択ソート開始なう
  for( i=0 ; i<n ; i++){
    minj = i;
    for( j=i ; j<=n-1 ; j++){
      if(C_S[j][1] < C_S[minj][1]){
        minj = j;
      }
    }
    strcpy(temp,C_S[i]);
    strcpy(C_S[i],C_S[minj]);
    strcpy(C_S[minj],temp); 

    printf("%s", C_S[i]);
    if( i<n-1 ){
      printf(" ");
    }
  }
  printf("\n");

  judge(n,C_B,C_S);

  return 0; 
}

void judge(int n,char C_B[36][3],char C_S[36][3]){
  int i;
  int count=0;

  for( i=0 ; i<n ; i++){
    if(strcmp(C_B[i],C_S[i]) == 0){
      count++;
    }
  }
  if(count == n){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }
}

