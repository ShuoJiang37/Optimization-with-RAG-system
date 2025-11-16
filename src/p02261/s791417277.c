#include<string.h>
#include<stdio.h>


char bub[36][3];
char sel[36][3];
//入力数確認
int val;

void bubble(void){
  int s,i;
  char tmp[3];

  for(i = 0;i < val;i++){
    for(s = val-1;s > i;s--){
      if(bub[s][1]<bub[s-1][1]){
	strcpy(tmp,bub[s-1]);
	strcpy(bub[s-1],bub[s]);
	strcpy(bub[s],tmp);
      }
    }
  }
}

void select(void){
  int s,i,cmp;
  char tmp[3];
  
  for(i = 0;i < val;i++){
    cmp = i;
    for(s=i+1;s<val;s++){
      if(sel[s][1]<sel[cmp][1])
	cmp = s;
    }
    strcpy(tmp,sel[i]);
    strcpy(sel[i],sel[cmp]);
    strcpy(sel[cmp],tmp);
  }
}

int main(){
  
  //比較のフラグ
  int flg = 0;
  int j; 
  char scn[36][3];
  char kind[4];  

  scanf("%d",&val);
  
  for(j = 0;j < val;j++){
    scanf("%s",scn[j]);
    strcpy(bub[j],scn[j]);
    strcpy(sel[j],scn[j]);
  }

  //バブルソート
  bubble(); 
  for(j = 0;j < val - 1;j++)
    printf("%s ",bub[j]);
  printf("%s\n",bub[j]);
  //バブルソートは後ろから順番に並び替えられてゆき、同じ数字の時に順番が入れ替わらないので絶対に安定
  printf("Stable\n");
    
  //選択ソート
  select(); 
  for(j = 0;j < val - 1;j++)
    printf("%s ",sel[j]);
  printf("%s\n",sel[j]);

  //絶対安定のバブルソートと比較すれば良い
  for(j = 0;j < val;j++){
    if(strcmp(sel[j],bub[j]) != 0){
      flg = 1;
      break;
    }
  }
   
  if(flg == 0)printf("Stable\n");
  else printf("Not stable\n");
  
  return 0;
}