#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int  second[MAX],count[MAX];
int num;

void CountingSort(short first[],short con){
  int i,j;
  //初期化
  for(i=0;i<=con;i++){
    count[i]=0;
  }
  for(j=1;j<=num;j++){
    count[first[j]]++;
  }
  for(i=1;i<=con;i++){
    count[i]=count[i]+count[i-1];
  }
  for(j=num;j>=1;j--){
    second[count[first[j]]]=first[j];
    count[first[j]]--;
  }
  //出力
  for(i=1;i<num;i++){
    printf("%d ",second[i]);
  }
  printf("%d\n",second[num]);
}

int main(){
  short first[MAX];
  int i;
  short conv=0;

  scanf("%d", &num);
  //firstは入力配列でsecondは出力配列
  for(i=1;i<=num;i++){
    scanf("%hd",&first[i]);
    if(conv<first[i]){
      conv=first[i];
    }
  }

  CountingSort(first,conv);
  return 0;
}

