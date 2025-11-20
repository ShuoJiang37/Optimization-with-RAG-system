#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

  int i,j,n,minj,flag=0;
  char B[36][3],S[36][3],temp[3];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",B[i]);
    strcpy(S[i],B[i]);
  }
  //bubblesort
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(atoi(&B[j][1])<atoi(&B[j-1][1])){
	strcpy(temp,B[j]);
	strcpy(B[j],B[j-1]);
	strcpy(B[j-1],temp);
      }
    }
  }
  //selectionsort
  for(i=0;i<n-1;i++){
    minj=i;
    for(j=i+1;j<n;j++){
      if(atoi(&S[j][1])<atoi(&S[minj][1])){
	minj=j;
      }
    }
    if(i!=minj){
      strcpy(temp,S[i]);
      strcpy(S[i],S[minj]);
      strcpy(S[minj],temp);
    }
  }


  //print
  for(i=0;i<n;i++){
    printf("%s",B[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\nStable\n");

  for(i=0;i<n;i++){
    printf("%s",S[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n");

  //stable or not stable
  for(i=0;i<n;i++){
    if(strcmp(B[i],S[i])!=0)flag=1;
  }
  if(flag==1)printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}