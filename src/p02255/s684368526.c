#include <stdio.h>

int main()
{
  int i,j,key,n,m;
  int l[100];

  scanf("%d",&n);/* 要素の数の格納 */

  for(i=0;i<n;i++){
    scanf("%d",&l[i]);/* 配列の格納 */
  }
  for(i=0;i<n;i++){
    printf("%d",l[i]);/* 変換前の配列の表示 */
    if(i<n-1)printf(" ");/* 空白の表示 */
  }
  printf("\n");/* 改行の表示 */

  for(i=1;i<n;i++){
    key = l[i];/* 位置の変換のために後続の値を入れる変数 */
    j = i - 1;
    while(l[j]>key && j>=0){/* 位置の変換の条件 */
      l[j+1] = l[j];/* 位置の変換 */
      j--;
    }
    l[j+1] = key;/* 位置の変換 */
    for(m=0;m<n;m++){
      printf("%d",l[m]);/* 変換後の配列の表示 */
      if(m<n-1)printf(" ");/* 空白の表示 */
    }
  printf("\n");/* 改行の表示 */
  } 
   return 0;
}


