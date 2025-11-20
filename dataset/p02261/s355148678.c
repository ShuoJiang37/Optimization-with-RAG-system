#include<stdio.h>
 
int main(){
 
  int K1[36],K2[36],n,temp1,temp2,flag=0;
  char temp3,M1[36],M2[36];
 
  //load N
  scanf("%d",&n);
  int i,j;
 
  //load number
  for(i=1;i<=n;i++){
    scanf(" %c%d",&M1[i],&K1[i]);
    K2[i]=K1[i];
    M2[i]=M1[i];
  }
 
 
 
  
  for(i=0;i<n;i++){
    for(j=n;j > i+1;j--){
      if(K1[j]<K1[j-1]){
        temp3=M1[j];
        M1[j]=M1[j-1];
        M1[j-1]=temp3;
        temp1=K1[j];
        K1[j]=K1[j-1];
        K1[j-1]=temp1;
    }
    }
  }
  for(i=1;i<=n;i++){
    printf("%c%d",M1[i],K1[i]);
    if(i!=n)printf(" ");
  }
    printf("\nStable\n");


  for(i=1;i<=n;i++){
    temp2=i;
    for(j=i;j<=n;j++){
      if(K2[j]<K2[temp2]){
        temp2=j;
      }
    }
     temp3=M2[i];
      M2[i]=M2[temp2];
      M2[temp2]=temp3;
      temp1=K2[i];
      K2[i]=K2[temp2];
      K2[temp2]=temp1;
  }
  for(i=1;i<=n;i++){
    printf("%c%d",M2[i],K2[i]);
    if(i!=n)printf(" ");
  }
  printf("\n");
flag=0;
  for(i=1;i<=n;i++){
    if(K2[i]!=K1[i]||M2[i]!=M1[i]){
      flag=1;
      printf("Not stable\n");
      break;
    }
  }
     if(flag==0) printf("Stable\n");
   return 0;
}
