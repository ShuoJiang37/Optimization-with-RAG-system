#include<stdio.h>

typedef struct{
  char mark;
  int value;
} Card;

int main(){
  Card a[36],b[36],t;
  int i,j,N,mini,c=0;
  scanf("%d",&N);
  for(i=0;i<N;i++)scanf(" %c%d",&a[i].mark,&a[i].value);
  for(i=0;i<N;i++)b[i]=a[i];
  // for(i=0;i<N;i++) printf("%c%d ",a[i].mark,a[i].value);
  // printf("\n");
  //buble
 
  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(a[j].value<a[j-1].value){
         t=a[j];
	 a[j]=a[j-1];
	 a[j-1]=t;       
      }
    }
  }
  for(i=0;i<N-1;i++) printf("%c%d ",a[i].mark,a[i].value);
  printf("%c%d\n",a[N-1].mark,a[N-1].value);
  printf("Stable\n");
  //serection
   for(i=0;i<N-1;i++){
    mini=i;
    for(j=i;j<N;j++){
      if(b[j].value<b[mini].value)mini=j;
    }
    t=b[i];
    b[i]=b[mini];
    b[mini]=t;
  }
  
   for(i=0;i<N-1;i++) printf("%c%d ",b[i].mark,b[i].value);
   printf("%c%d\n",b[N-1].mark,b[N-1].value);
    //stable?
   for(i=0;i<N;i++){
     if(a[i].mark!=b[i].mark){
       printf("Not stable\n");
       return 0;
     }
   }
   printf("Stable\n");
   
   return 0;
}

