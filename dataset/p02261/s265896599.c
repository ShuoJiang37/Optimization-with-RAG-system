#include<stdio.h>
#define MAX 37

typedef struct card{
 char mark;
 int num;
}card;


void swap(card C[],int x,int y){
card temp;
temp=C[x];
C[x]=C[y];
C[y]=temp;

return;
}



void bubble(card C[],int n){
 for(int i=0;i<n-1;i++){
  for(int j=n-1;j>=i+1;j--){
   if(C[j].num<C[j-1].num){swap(C,j,j-1);}
  }
 }
}


void selesort(card C[],int n){
 for(int i=0;i<n;i++){int minid=i;
  for(int j=i;j<n;j++){
   if(C[j].num<C[minid].num){minid=j;}
  }
  swap(C,i,minid);
 }
return;
}




int main(){
int n,i;
card C[MAX];
card D[MAX];


scanf("%d",&n);

for(i=0;i<n;i++){scanf(" %c%d",&C[i].mark,&C[i].num);D[i]=C[i];}


bubble(C,n);
selesort(D,n);


for(i=0;i<n-1;i++)printf("%c%d ",C[i].mark,C[i].num);printf("%c%d\n",C[n-1].mark,C[n-1].num);
printf("Stable\n");
for(i=0;i<n-1;i++)printf("%c%d ",D[i].mark,D[i].num);printf("%c%d\n",D[n-1].mark,D[n-1].num);


for(i=0;i<n;i++){
 if(C[i].num!=D[i].num||C[i].mark!=D[i].mark){printf("Not stable\n");break;}
 if(i==n-1){printf("Stable\n");}
}




return 0;
}
