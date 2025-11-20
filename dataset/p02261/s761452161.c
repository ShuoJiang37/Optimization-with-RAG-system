#include<stdio.h>
#define N 36

struct card {
  int no;
  char mk;
};

int main(void)
{
  int n,i,j,mini,sf=0;
  struct card c[N],c1,c2[N],c3;
  scanf("%d",&n);
  for(i = 0; i < n; i++){ /* 入力 */
    scanf(" %c",&c[i].mk);
    scanf("%d",&c[i].no);
    c2[i] = c[i];
  }
  for(i = 0; i < n; i++){
    for(j = n-1; i < j; j--){
      if(c[j].no < c[j-1].no){ 
	c1 = c[j];
	c[j] = c[j-1];  /* バブルソート並び換え部分 */
	c[j-1] = c1;
      }
    }
  }


  for(i = 0; i < n-1; i++){ /* 出力 */
    printf("%c%d ",c[i].mk,c[i].no);
  }
  printf("%c%d\n",c[n-1].mk,c[n-1].no);
  printf("Stable\n");



  for(i = 0; i < n; i++){
    mini = i;
    for(j = i; j < n; j++){
      if(c2[j].no < c2[mini].no){ /* 選択ソート並び換え部分 */
	mini = j;
      }
    }
    if(mini != i){
	c3 = c2[i];
	c2[i] = c2[mini];
	c2[mini] = c3;
    }
  }

  for(i = 0; i < n-1; i++){ /* 出力 */
    printf("%c%d ",c2[i].mk,c2[i].no);
    if((c[i].mk != c2[i].mk))sf =1;
  }
  printf("%c%d\n",c2[n-1].mk,c2[n-1].no);
  if(sf == 0)printf("Stable\n");
  else printf("Not stable\n");
  return 0;
}