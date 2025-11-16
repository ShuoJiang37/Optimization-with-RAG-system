#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
  int n, cnt = 0, i, j;
  scanf("%d", &n);
  typedef struct dat{
    char in[4];
    char mrk;
    int num;
    int odr;
  }T_dat;
  T_dat *dat1, *dat2;
  dat1 = (T_dat *)malloc(sizeof(T_dat) * n);
  dat2 = (T_dat *)malloc(sizeof(T_dat) * n);
  for(i = 0; i < n; i++)
    scanf("%s", dat1[i].in);
  for(i = 0; i < n; i++){
    if(dat1[i].in[0] == 'J' & dat1[i].in[0] == 'K'){
      dat1[i].mrk = 'J';
      dat1[i].num = 0;
    }
    else if(dat1[i].in[0] == 'S' | dat1[i].in[0] == 'H' | dat1[i].in[0] == 'D' | dat1[i].in[0] == 'C')
      dat1[i].mrk = dat1[i].in[0];
    else
      dat1[i].mrk = '-';
    if(strlen(dat1[i].in) < 3){
      if(dat1[i].in[1] >= '1' & dat1[i].in[1] <= '9')
	dat1[i].num = dat1[i].in[1] - '0';
      else if(dat1[i].in[1] == 'J' | dat1[i].in[1] == 'j')
	dat1[i].num = 11;
      else if(dat1[i].in[1] == 'Q' | dat1[i].in[1] == 'q')
	dat1[i].num = 12;
      else if(dat1[i].in[1] == 'K' | dat1[i].in[1] == 'k')
	dat1[i].num = 13;
      else if(dat1[i].in[1] == 'A' | dat1[i].in[1] == 'a')
	dat1[i].num = 1;
      else
	dat1[i].num = 0;
    }
    else if(dat1[i].in[1] == '1' & dat1[i].in[2] >= 0 & dat1[i].in[2] <= 3)
      dat1[i].num = 10 + dat1[i].in[2] - '0';
    else
      dat1[i].num = 0;
    dat1[i].odr = i;
    dat2[i] = dat1[i];
  }
  for(i = 0; i < n - 1; i++)
    for(j = n - 1; j > i; j--)
      if(dat1[j - 1].num > dat1[j].num){
	T_dat tmp = dat1[j - 1];
	dat1[j - 1] = dat1[j];
	dat1[j] = tmp;
	//	cnt++;
      }
  for(i = 0; i < n - 1; i++){
    int jmin = i;
    for(j = i + 1; j < n; j++){
      if(dat2[j].num < dat2[jmin].num)
	jmin = j;
    }
    if(jmin != i){
      T_dat tmp = dat2[i];
      dat2[i] = dat2[jmin];
      dat2[jmin] = tmp;
      //      cnt++;
    }
  }
  int P = 0;
  int P_apr[13];
  for(i = 0; i < 13; i++)
    P_apr[i] = 0;
  printf("%c%d", dat1[0].mrk, dat1[0].num);
  P_apr[dat1[0].num - 1] = 1;
  for(i = 1; i < n; i++){
    printf(" %c%d", dat1[i].mrk, dat1[i].num);
    if(P_apr[dat1[i].num - 1]){
      for(j = 0; j < i; j++)
	if(dat1[i].num == dat1[j].num & dat1[j].odr > dat1[i].odr)
	  P = 1;
    }
    else
      P_apr[dat1[i].num - 1] = 1;
  }
  printf("\n");
  if(!P)
    printf("Stable\n");
  else
    printf("Not stable\n");
  P = 0;
  for(i = 0; i < 13; i++)
    P_apr[i] = 0;
  printf("%c%d", dat2[0].mrk, dat2[0].num);
  P_apr[dat2[0].num - 1] = 1;
  for(i = 1; i < n; i++){
    printf(" %c%d", dat2[i].mrk, dat2[i].num);
    if(P_apr[dat2[i].num - 1]){
      for(j = 0; j < i; j++)
	if(dat1[i].num == dat1[j].num & dat2[j].odr > dat2[i].odr)
	  P = 1;
    }
    else
      P_apr[dat2[i].num - 1] = 1;
  }
  printf("\n");
  if(!P)
    printf("Stable\n");
  else
    printf("Not stable\n");
  //  printf("%d\n", cnt);
  return 0;
}