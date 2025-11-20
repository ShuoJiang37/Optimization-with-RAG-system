#include <stdio.h>
#define N 36

typedef struct{
  char gara[N];
  int num[N];
}Trump;

Trump bubble(Trump, int);
Trump select(Trump,int);

int main(){
  int n = 0, flag = 0;
  int i = 0;
  Trump tru, tru2, tru3;

  scanf("%d",&n);

  for(i = 0; i < n; i++){/*scan*/
    scanf(" %c%d",&tru.gara[i],&tru.num[i]);
  }
  
  /*call def*/
  tru2 = bubble(tru, n);
  tru3 = select(tru, n);

  /*select stable check*/
  for(i = 0; i < n; i++){
    if(tru2.gara[i] != tru3.gara[i])flag = 1;
  }
  
  if(flag == 1)printf("Not stable\n");
  else printf("Stable\n");
  
  return 0;
}

Trump bubble(Trump tru, int n){
  int i = 0, j = 0, key = 0;
  char key2;

  for(i = 0; i < n; i++){
    for(j = n-1; j > i; j--){
      if(tru.num[j] < tru.num[j-1]){
	key2 = tru.gara[j-1];
	key = tru.num[j-1];
	tru.gara[j-1] = tru.gara[j];
	tru.num[j-1] = tru.num[j];
	tru.gara[j] = key2;
	tru.num[j] = key;
      }
    }
  }
  for(i = 0; i < n; i++){/*print*/
    printf("%c%d",tru.gara[i],tru.num[i]);
    if(i == n-1)printf("\n");
    else printf(" ");
  }
  printf("Stable\n");

  return tru;
}

Trump select(Trump tru, int n){
  int i = 0, j = 0, key = 0, minj = 0;
  char key2;
  
  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(tru.num[j] < tru.num[minj]){
	minj = j;
      }
    }
    key2 = tru.gara[minj];
    key = tru.num[minj];
    tru.gara[minj] = tru.gara[i];
    tru.num[minj] = tru.num[i];
    tru.gara[i] = key2;
    tru.num[i] = key;
  }
  
  for(i = 0; i < n; i++){/*print*/
    printf("%c%d",tru.gara[i],tru.num[i]);
    if(i == n-1)printf("\n");
    else printf(" ");
  }

  return tru;
}


