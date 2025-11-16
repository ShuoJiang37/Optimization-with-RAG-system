#include<stdio.h>

 int count=0;
 int m=0;
 int G[1000001]={};

 int insertion(int A[],int n,int g){
         int i,j,tmp,v;
         for(i=g;i<=n-1;i++){
                 v=A[i];
                 j=i-g;

                 while(j>=0&&A[j]>v){
                        A[j+g]=A[j];
                        j-=g;
                        count++;
                        A[j+g]=v;
                        }
                 }
         }


 int shell(int A[],int n){
          int i;
          G[0]=1;
          for(m=1;3*G[m-1]+1<=n;m++){
                   G[m]=3*G[m-1]+1;
                   }
          for(i=m-1;i>=0;i--){
                   insertion(A,n,G[i]);
                   }
           }

 int main(){
     int i,j,n,A[1000001];
     scanf("%d",&n);
     for(i=0;i<n;i++){
            scanf("%d",&A[i]);
            }

     shell(A,n);

     printf("%d\n",m);
     for(i=m-1;i>=0;i--){
              printf("%d",G[i]);
              if(i==0)printf("\n");
              else printf(" ");
              }

     printf("%d\n",count);

     for(i=0;i<n;i++){
               printf("%d\n",A[i]);
               }
     return 0;
     }



     
