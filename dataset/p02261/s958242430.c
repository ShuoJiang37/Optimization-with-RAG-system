#include <stdio.h>

#define N 36

typedef struct{
  char mark;
  int number;
  int order;
}trump;

int main()
{
  int i, j, num, mj, flag=1;
  trump array1[N], array2[N], tmp;

  scanf("%d", &num);

  for( i=0; i<num; i++){
    while(1){
      scanf("%c", &array1[i].mark);
      if( array1[i].mark != 'D' && array1[i].mark != 'C' && array1[i].mark != 'S' && array1[i].mark != 'H')continue;
      scanf("%d", &array1[i].number);
      break;
    }
    array1[i].order = i+1;
    array2[i] = array1[i];
  }

  for( i=0; i<num; i++){
    for( j=num-1; j>=i+1; j--){
      if( array1[j].number < array1[j-1].number ){
	tmp = array1[j];
	array1[j] = array1[j-1];
	array1[j-1] = tmp;
      }
    }
  }

  for( i=0; i<num-1; i++){
    printf("%c%d ", array1[i].mark, array1[i].number);
  }

  printf("%c%d\n", array1[i].mark, array1[i].number);

  for( i=1; i<num; i++){
    if( array1[i].number == array1[i-1].number && array1[i].order - array1[i-1].order < 0 )flag =0;
  }

  if( flag == 1 ) printf("Stable\n");
  else printf("Not stable\n");

  flag = 1;

  for( i=0; i<num; i++){
    mj = i;

    for( j=i; j<num; j++){
      if( array2[j].number < array2[mj].number )mj = j;
    }
      tmp = array2[i];
      array2[i] = array2[mj];
      array2[mj] = tmp;
    }

  for( i=0; i<num-1; i++){
    printf("%c%d ", array2[i].mark, array2[i].number);
  }

  printf("%c%d\n", array2[i].mark, array2[i].number);

  for( i=1; i<num; i++){
    if( array2[i].number == array2[i-1].number && array2[i].order - array2[i-1].order < 0 )flag =0;
  }

  if( flag == 1 ) printf("Stable\n");
  else printf("Not stable\n");
    
  return 0;
}