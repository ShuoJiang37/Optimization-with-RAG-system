#include<stdio.h>

typedef struct{

  char m;
  int v;

}card;

int main(){

  int i, j, n, min, flag = 1, f = 0;

  card m1[36], m2[36], tmp; 

  scanf("%d",&n);
 
  for( i = 0; i < n; i++){

    scanf(" %c%d", &m1[i].m, &m1[i].v);
    m2[i].m = m1[i].m;
    m2[i].v = m1[i].v;

  }
  //bubblesort
  while(flag){

    flag = 0;

    for( i = n-1; i >= 1; i--){

      if( m1[i].v < m1[i-1].v){

	tmp = m1[i];
	m1[i] = m1[i-1];
	m1[i-1] = tmp;
	flag = 1;

      }
    }
  }

  for( i = 0; i < n; i++) {

    printf("%c%d", m1[i].m, m1[i].v);
    if(i != n-1)printf(" ");

  }
  printf("\n");

  printf("Stable\n");
  //???????????§

  //selectionsort
  for( i = 0; i < n; i++){

    min = i;

    for(j = i; j < n; j++){

      if(m2[j].v < m2[min].v){
	min = j;
      }
    }

    if( i != min){//????°??????????????????????????????????????????????

      tmp = m2[i];
      m2[i] = m2[min];
      m2[min] = tmp;

    }
  }
 
  for( i = 0; i < n; i++){

    printf("%c%d", m2[i].m, m2[i].v);

    if(i != n - 1)
      printf(" ");
  }

  printf("\n");
  //???????????§
  //bubblesort??¨??????????????????
  for( i = 0; i < n; i++){

    if( m1[i].m != m2[i].m) {

      printf("Not stable\n");
      f = 1;
      break;
    }

  }
  if(f != 1)
    printf("Stable\n");

  return 0;
}