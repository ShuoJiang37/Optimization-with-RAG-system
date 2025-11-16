#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
void selection(int n, char data[][5],char sdata[],char sample[][5]){
  int min,flag = 0 ;
  int tmp,key,counter = 0;
  char tmp2[3];
  char cop[36][5];
  memcpy(cop,sample,sizeof(cop));
  
  /*
  for (int i = 0; i < n ; i ++){
    printf("%s ",data[i]);
  }
  */
  //i-nまでのminを探索
  //i:既ソートの右端index
  //j:未ソートの左端index
  for (int i = 0; i < n ; i ++ ){ //未ソートの右端でループ
    min = sdata[i];//既ソートの左端の値をminの初期値に
    key = i; // keyの初期化
    for (int j = i; j < n; j ++ ){
      //最小値とそのindexの探索
      if (sdata[j]< min){
        min = sdata[j];
        key = j;
      }
    }
    //既ソートのminが未ソートの右端よりも小さい場合にswap
    if (sdata[i] > min){
    //data[i]にminを、data[j]にdata[i]を代入
      tmp = sdata[i];
      sdata[i] = min;
      sdata[key] = tmp;
      counter += 1; 
      //dataのソート
      strcpy(tmp2,data[i]);
      strcpy(data[i],data[key]);
      strcpy(data[key],tmp2);   
    }
  }
  //結果の出力
  
  for (int i = 0; i < n ; i ++ ){
    if (i > 0) printf(" ");
    printf("%s",data[i]);
  }
  printf("\n");
  //printf("%d\n",counter);
  for (int i = 0; i < n; i ++){
    if (strcmp(cop[i],data[i])){
      printf("Not stable\n");
      flag = 1;
    break;
    }
  }
  if (flag == 0) printf("Stable\n");
  flag = 1;
}

void sort(int n,char data[][5],char sdata[]){
  int flag = 0;
  char cop[36][5];
  int counter = 0;
  char tmp,tmp2[2];
  char ans[n];
  //strcpy(cop,data);
  while (1==1){
    flag = 0;
    for (int i = 0; i < n-1; i ++ ){
      //sdataでソート
      if (sdata[i] > sdata[i+1]){
        counter += 1;
        tmp = sdata[i];
        sdata[i] = sdata[i+1];
        sdata[i+1] = tmp;
        //dataのソート
        strcpy(tmp2,data[i]);
        strcpy(data[i],data[i+1]);
        strcpy(data[i+1],tmp2);
        flag = 1;
      }
    }
    if (flag == 0){
      for (int i = 0; i < n ; i ++){
        if ( i > 0 ) printf(" ");
        printf("%s",data[i]);
      }
      printf("\n");
      //printf("%d\n",counter);
      break;
    }
  }
  // dataの文字を配列に格納
  printf("Stable\n");
  
}


int main(){
  //入力を文字列として配列に格納
  //文字列の配列は2次元配列
  char data[36][5];
  char sdata[36];
  int stable;
  int n;
  char mem[36][5];
  char smem[36];
  scanf("%d",&n);
  for (int i = 0; i < n; i ++){
    scanf("%s",data[i]);
  }
 //dataから数値を抽出した配列の生成
 for (int i = 0 ; i < n ;i ++){
   sdata[i] = (data[i][1]);
 }
// stableかの判定

memcpy(mem,data,sizeof(data));
memcpy(smem,sdata,sizeof(sdata));
sort(n,data,sdata);

selection(n,mem,smem,data);
}


