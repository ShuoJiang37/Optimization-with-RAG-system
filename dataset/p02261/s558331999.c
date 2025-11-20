#include<stdio.h>
#include<string.h>
#define N 36
 
int main(void){
  int n,i,j,min,k,f;
  char a[N][3],ba[N][3],ch[N][3],sw[1][4];
 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",a[i]);
  }
 
  for(i=0;i<n;i++){
    strcpy(ba[i],a[i]);
  }
  for(i=0;i<n;i++){
    strcpy(ch[i],a[i]);
  }
 
  //バブルソート開始
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(ba[j][1]<ba[j-1][1]){
    strncpy(sw[0],ba[j],3);
    strncpy(ba[j],ba[j-1],3);
    strncpy(ba[j-1],sw[0],3);
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%s",ba[i]);
    if(i!=n-1){
      printf(" ");
    }
  }
  printf("\n");
  //バブルソート終了
 
  //判定
    printf("Stable\n");
  //判定終了
 
 
  //選択ソート開始
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++)if(ch[j][1]<ch[min][1])min=j;
    if(min!=i){
      strncpy(sw[0],ch[min],3);
      strncpy(ch[min],ch[i],3);
      strncpy(ch[i],sw[0],3);
    }
  }
  for(i=0;i<n;i++){
    printf("%s",ch[i]);
    if(i!=n-1){
      printf(" ");
    }
  }
  printf("\n");
  //選択ソート終了
 
  //判定
  f=0;
  for(i=0;i<n;i++){
    if(ba[i][1]==ch[i][1]&&ba[i][0]!=ch[i][0]){
        printf("Not stable\n");
        f=1;
		break;
      }
    }
  if(f==0){
    printf("Stable\n");
  }
  //判定終了
 
  return 0;
   
}