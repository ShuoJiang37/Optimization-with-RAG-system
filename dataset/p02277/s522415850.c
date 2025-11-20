#include<stdio.h>
#define MAX 100001
#define INI 2000000000

 struct Card{
           char gara;
           int value;
           };

 int merge(struct Card card1[],int n,int left,int right,int mid){
          int i,n1,n2,j,k;
          struct Card L[MAX/2+2],R[MAX/2+2];
          n1=(mid-left);
          n2=(right-mid);
          for(i=0;i<n1;i++){L[i]=card1[left+i];}
          for(j=0;j<n2;j++){R[j]=card1[mid+j];}
          L[n1].value=INI;
          R[n2].value=INI;
          
          i=0;j=0;
          for(k=left;k<right;k++){
                      if(L[i].value<=R[j].value){card1[k]=L[i];i++;}
                      else {card1[k]=R[j];j++;}
                      }
          }
          

 int mergesort(struct Card card1[],int n,int left,int right){
          int mid;
          if(right-left>1){
                    mid=(left+right)/2;
                    mergesort(card1,n,left,mid);
                    mergesort(card1,n,mid,right);
                    merge(card1,n,left,right,mid);
                    }
           }

 int part(struct Card card2[],int n,int left,int right){
      struct Card tmp,key;
      key=card2[right];
      int i,j;
      
      i=left-1;
      for(j=left;j<right;j++){
               if(card2[j].value<=key.value){
                                i++;
                                tmp=card2[i];card2[i]=card2[j];card2[j]=tmp;
                                }
               }
       i++;
       tmp=card2[i];card2[i]=card2[right];card2[right]=tmp;
       return i;
       }
   

 int quick(struct Card card2[],int n,int left,int right){
      int q;
      if(left<right){
          q=part(card2,n,left,right);
          quick(card2,n,left,q-1);
          quick(card2,n,q+1,right);
          }
       }

 int main(){
        int n,v,flag=1,i;
        struct Card card1[MAX];
        struct Card card2[MAX];
        char c[10];
        scanf("%d",&n);
        for(i=0;i<n;i++){
                  scanf("%s%d",&c,&v);
                  card2[i].gara=card1[i].gara=c[0];
                  card2[i].value=card1[i].value=v;
                  }

        mergesort(card1,n,0,n);
        quick(card2,n,0,n-1);

        for(i=0;i<n;i++){
                  if(card1[i].gara!=card2[i].gara)flag=0;
                  }
        if(flag==1){printf("Stable\n");}
        else {printf("Not stable\n");}

        for(i=0;i<n;i++){printf("%c %d\n",card2[i].gara,card2[i].value);}
        return 0;
        }




