#include <stdio.h>
#define N 36

typedef struct{
  int suji;
  char moji;
}card;

main(){
  int n, i, j, minj, hantei = 1;
  card a[N], d[N], b, c;

  scanf("%d", &n);
  for(i = 0;i < n;i++){
    scanf(" %c%d", &a[i].moji, &a[i].suji);
  }
  for(i = 0;i < n;i++){
    d[i] = a[i];
  }
  for(i = 0;i < n-1;i++){ 
     for(j = n-1;j > i;j--){ 
       if(a[j].suji < a[j-1].suji){ 
   	b = a[j]; 
   	c = a[j-1]; 
   	a[j] = c; 
   	a[j-1] = b; 
       } 
     } 
   }
  for(i = 0;i < n;i++){
    minj = i;
    for(j = i;j < n;j++){
      if(d[j].suji < d[minj].suji){
	minj = j;
      }
    }
    b = d[i];
    c = d[minj];
    d[i] = c;
    d[minj] = b;
  }
  for(i = 0;i < n-1;i++){
    printf("%c%d ", a[i].moji, a[i].suji);
  }
  printf("%c%d\n", a[n-1].moji, a[n-1].suji);
  printf("Stable\n");
  for(i = 0;i < n-1;i++){
    printf("%c%d ", d[i].moji, d[i].suji);
  }
  printf("%c%d\n", d[n-1].moji, d[n-1].suji);
  for(i = 0;i < n;i++){
    if(a[i].moji != d[i].moji){
      hantei = 0;
      break;
    }
  }
  if(hantei == 1){
    printf("Stable\n");
  }
  else printf("Not stable\n");
  return 0;
}