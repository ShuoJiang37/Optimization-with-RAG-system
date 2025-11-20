#include<stdio.h>
#include<stdlib.h>
main(){

  int i, j, N, flag, nbuf, nbuf2;
  char copy[37][2], bub[37][2], sel[37][2], str[3], cbuf, cbuf2, mini;

  scanf("%d",&N);

  for(i = 1; i <= N; i++){
    scanf("%s",str);
    copy[i][0] = str[0];
    copy[i][1] = atoi(&str[1]);
    sel[i][0] = str[0];
    sel[i][1] = atoi(&str[1]);
    bub[i][0] = str[0];
    bub[i][1] = atoi(&str[1]);
  }

  for(i = 1; i <= N; i++)
    for(j = N; j > i; j--)
      if(bub[j-1][1] > bub[j][1]){
        nbuf2 = bub[j][0];
        cbuf = bub[j][1];
        bub[j][0] = bub[j-1][0];
        bub[j][1] = bub[j-1][1];
        bub[j-1][0] = nbuf2;
        bub[j-1][1] = cbuf;
      }

  for(i = 1; i < N; i++){
    mini = i;
    for(j = i; j <= N; j++)
      if(sel[j][1] < sel[mini][1])
        mini = j;
     
    if(sel[i][1] > sel[mini][1]){
      nbuf = sel[i][0];
      cbuf2 = sel[i][1];
      sel[i][0] = sel[mini][0];
      sel[i][1] = sel[mini][1];
      sel[mini][0] = nbuf;
      sel[mini][1] = cbuf2;
    }
  }
 
  flag = 1;
  for(i = 1; i < N; i++){
    printf("%c%d ",bub[i][0],bub[i][1]);
    if(flag == 1 && i > 0 && bub[i-1][1] == bub[i][1])
      for(j = 1; j <= N; j++){
    if(copy[j][0] == bub[i-1][0] && bub[i-1][1] == copy[j][1])
          break;
        if(copy[j][1] == bub[i][1] && copy[j][0] == bub[i][0]){
          flag = 0;
      break;
        }
      }
  }

  if(i == N)
    printf("%c%d",bub[i][0],bub[i][1]);
  printf("\n");
  if(flag == 1)
    printf("Stable\n");
  if(flag == 0)
    printf("Not stable\n");

  flag = 1;
  for(i = 1; i < N; i++){
    printf("%c%d ",sel[i][0],sel[i][1]);
    if(flag == 1 && i > 0 && sel[i-1][1] == sel[i][1])
      for(j = 1; j <= N; j++){
        if(copy[j][0] == sel[i-1][0] && sel[i-1][1] == copy[j][1])
          break;
        if(copy[j][1] == sel[i][1] && copy[j][0] == sel[i][0]){
      flag = 0;
      break;
        }
      }
  }

  if(i == N)
    printf("%c%d",sel[i][0],sel[i][1]);
  printf("\n");
  if(flag == 1)
    printf("Stable\n");
  if(flag == 0)
    printf("Not stable\n");

  return 0;
}