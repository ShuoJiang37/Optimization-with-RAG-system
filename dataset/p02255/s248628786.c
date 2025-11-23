#include<stdio.h>
int main(){
 int n,i,j,k,temp;
 int A[101];

/*????´??????°?????\???*/
 scanf("%d",&n);

/*??????????????\???*/
 for(i=0;i<n;i++){
  
 if(i==n-1){
    scanf("%d",&A[n-1]);
   }else{
    scanf("%d ",&A[i]);
   }

 }

for(k=0;k<n;k++){
  
  if(k==n-1){
     printf("%d\n",A[n-1]);
    }else{
     printf("%d ",A[k]);
    }

  }





 for(i=1;i<n;i++){

  temp=A[i];
  
  for(j=i-1;j>=0;j--){

   if(temp<A[j]){
    A[j+1]=A[j];
    A[j]=temp;
   }

  }


  for(k=0;k<n;k++){
  
  if(k==n-1){
     printf("%d\n",A[n-1]);
    }else{
     printf("%d ",A[k]);
    }

  }

 }

return 0;
}