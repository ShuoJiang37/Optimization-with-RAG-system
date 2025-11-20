#include<stdio.h>
#define N 36

typedef struct{
  char chara;
  int num;
  int no;
} trump;

int main(){

  int i,j,n,flag=1,minj;
  trump T1[N],T2[N],tmp;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    while(1){
      scanf("%c",&T1[i].chara);
      if(T1[i].chara != 'S' && T1[i].chara != 'H' && T1[i].chara != 'C' && T1[i].c\
hara != 'D') continue;
      scanf("%d",&T1[i].num);
      break;
    }
    T1[i].no=i+1;
    T2[i]=T1[i];
  }
  
    for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(T1[j].num<T1[j-1].num){
        tmp = T1[j];
        T1[j] = T1[j-1];
        T1[j-1] = tmp;
      }
    }
  }

  for(i=0;i<n;i++){
    if(i != n-1)printf("%c%d ",T1[i].chara,T1[i].num);
    else printf("%c%d\nStable\n",T1[i].chara,T1[i].num);
  }
  
   for(i=0;i<n-1;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(T2[j].num<T2[minj].num){
        minj = j;
      }
    }
    tmp = T2[i];
    T2[i] = T2[minj];
    T2[minj] = tmp;
  }

  for(i=0;i<n;i++){
    if(i != n-1 ) printf("%c%d ",T2[i].chara,T2[i].num);
    else printf("%c%d\n",T2[i].chara,T2[i].num);
  }

  for(i=1;i<n;i++){
    if(T2[i].num == T2[i-1].num && T2[i].no - T2[i-1].no < 0){
      flag = 0;
    }
  }
   if(flag == 1)printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}

  
