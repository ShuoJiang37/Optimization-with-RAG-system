#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int N;


typedef struct{
  int num;
  char s;
}card;



void stable_judge(char **ans,card *A){
  int i;
  int a;
  int number[10]={};
  for(i=0;i<N;i++){
    a=A[i].num;
    if(ans[a][number[a]]!=A[i].s){
      printf("\nNot stable\n");
      break;
    }
    number[a]+=1;
  }
  if(i==N) printf("\nStable\n");
} 
  

int main(){

  int i,j;
  card *bub,*sel;
  char **ans;//正解の並び
  ans=malloc(10*sizeof(char *));
  for(i=0;i<=9;i++) ans[i]=malloc(4*sizeof(char));
  int  number[10]={};//ansのi行に何個数字が入っているかを表す配列
  
  scanf("%d",&N);
  bub=malloc(N*sizeof(card));
  sel=malloc(N*sizeof(card));
  for(i=0;i<N;i++) scanf("%*[^HCDS]%c%d",&bub[i].s,&bub[i].num);//読み飛ばしを行う。
  for(i=0;i<N;i++){
    sel[i].num=bub[i].num;
    sel[i].s=bub[i].s;
  }//入力完了

  
  int a;
  for(i=0;i<N;i++){
    a=bub[i].num;
    ans[a][number[a]]=bub[i].s;
    number[a]+=1;
  }//正解（安定性）を判断するためのans完成

  int b;
  int check;
  char ss;
  for(i=0;i<N-1;i++){
    check=0;
    for(j=N-1;j>=i+1;j--){
      if(bub[j].num < bub[j-1].num){
        b=bub[j].num;
        ss=bub[j].s;
        bub[j].num=bub[j-1].num;
        bub[j].s=bub[j-1].s;
        bub[j-1].num=b;
        bub[j-1].s=ss;
        check=1;
      }//スワップ
    }
    if(check==0) break;//交換無しなら終了
  }//バブルソート
  

  int mini;
  for(i=0;i<N-1;i++){
    mini=i;
    for(j=i+1;j<N;j++){
      if(sel[j].num < sel[mini].num) mini=j;
    }
    if(i!=mini){
        b=sel[mini].num;
        ss=sel[mini].s;
        sel[mini].num=sel[i].num;
        sel[mini].s=sel[i].s;
        sel[i].num=b;
        sel[i].s=ss;
    }//スワップ
  }//バブルソート

  printf("%c%d",bub[0].s,bub[0].num);
  for(i=1;i<N;i++) printf(" %c%d",bub[i].s,bub[i].num);
  stable_judge(ans,bub);//バブルソートに関する出力

  printf("%c%d",sel[0].s,sel[0].num);
  for(i=1;i<N;i++) printf(" %c%d",sel[i].s,sel[i].num);
  stable_judge(ans,sel);//選択ソートに関する出力
  
  return 0;
}



//配列の初期化は={}
//文字列は初期化しなくてもokかも？
