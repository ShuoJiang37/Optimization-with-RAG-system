#include<stdio.h>
int main(){
 int n,i,j,k,temp,kou=0;
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




/*?????????*/
 for(i=0;i<n-1;i++){

  for(j=n-2;j>=i;j--){
   temp=A[j+1];
   if(temp<A[j]){
    A[j+1]=A[j];
    A[j]=temp;
    kou+=1;
   }
}
 }

 for(k=0;k<n-1;k++){
  printf("%d ",A[k]);
 }
  printf("%d\n",A[n-1]);
  printf("%d\n",kou);


return 0;
}