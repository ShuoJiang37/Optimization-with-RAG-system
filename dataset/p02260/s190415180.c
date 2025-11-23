#include<stdio.h>
int main(){
 int n,i,j,k,num,kou=0,min;
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
min=101;
 for(j=i;j<n;j++){
  if(A[j]<min){
   min=A[j];
   num=j;
   }
 }

 if(num!=i){
  A[num]=A[i];
  A[i]=min;
  kou+=1;
 }

 }






/*??¨???*/
 for(k=0;k<n-1;k++){
  printf("%d ",A[k]);
 }
  printf("%d\n",A[n-1]);
  printf("%d\n",kou);


return 0;
}