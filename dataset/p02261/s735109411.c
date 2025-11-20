#include<stdio.h>
#include<stdbool.h>
 struct TC{
   char s;
   char v;
 };
 void bubble(struct TC A[],int N){
  int i,j;
   for(i=0;i<N;i++){
     for(j=N-1;j>=i+1;j--){
       if(A[j].v<A[j-1].v){
        struct TC t=A[j];
         A[j]=A[j-1];
         A[j-1]=t;
       }
     }
   }
 }
void selection(struct TC A[],int N){
int i,j;
  for(i=0;i<N;i++){
    int minj=i;
    for(j=i;j<N;j++){
      if(A[j].v<A[minj].v)minj=j;
    }
struct TC t=A[i];
A[i]=A[minj];
A[minj]=t;
  }
}
void print(struct TC A[],int N){
int i;
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%c%c",A[i].s,A[i].v);
  }
printf("\n");
}
bool isS(struct TC c1[],struct TC c2[],int N){
int i;
for(i=0;i<N;i++){
  if(c1[i].s != c2[i].s)return false;
}
return true;
}
int main(){
  struct TC c1[100],c2[100];
  int N,i;
  char ch;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf(" %c %c",&c1[i].s,&c1[i].v);
  }
for(i=0;i<N;i++)c2[i]=c1[i];
bubble(c1,N);
selection(c2,N);
print(c1,N);
printf("Stable\n");
print(c2,N);
if(isS(c1,c2,N)){
  printf("Stable\n");
}
else{
  printf("Not stable\n");
}
return 0;
}

