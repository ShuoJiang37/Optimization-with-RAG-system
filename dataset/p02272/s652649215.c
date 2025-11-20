#include<stdio.h>
#define MAX 500001
#define SENTINEL 2000000000

 int count=0;

 int merge(int S[],int left,int right,int mid){
         int n1,n2,i,L[MAX/2+2],R[MAX/2+2],j,k;
         n1=mid-left;
         n2=right-mid;
         for(i=0;i<n1;i++){L[i]=S[left+i];}
         for(i=0;i<n2;i++){R[i]=S[mid+i];}
         L[n1]=R[n2]=SENTINEL;
         i=0;
         j=0;
         for(k=left;k<right;k++){
                        count++;
                        if(L[i]<=R[j]){S[k]=L[i];
                                      i++;
                                      }
                        else {S[k]=R[j];
                              j++;
                              }
                        }
          }
                                   
                    

 int mergesort(int S[],int left,int right){
        if(right-left>1){
             int mid=(left+right)/2;
             mergesort(S,left,mid);
             mergesort(S,mid,right);
             merge(S,left,right,mid);
             }
        }

 int main(){
        int i,n;
        
        int S[MAX];
        scanf("%d",&n);
        for(i=0;i<n;i++){
                   scanf("%d",&S[i]);
                   }
        
        mergesort(S,0,n);
        for(i=0;i<n;i++){
                   printf("%d%c",S[i],(i==n-1)?'\n':' ');
                   }
        printf("%d\n",count);
        return 0;
        }


