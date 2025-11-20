#include<stdio.h>

typedef struct {
  char suit ;
  int num ;
  int idx ;
} card ;

void bubble_sort( card bubble[], int n )
{
  int i, j, s ;
  card tmp ;
  for( i = 0 ; i < n-1 ; i++ ){ // iは未ソート部の先頭
    for( j = n-1 ; j > i ; j-- ){
      if( bubble[j-1].num > bubble[j].num ){
        tmp = bubble[j-1] ;
        bubble[j-1] = bubble[j] ;
        bubble[j] = tmp ;
      }
    }
  }
  for( i = 0 ; i < n ; i++ ){
    if( i < n-1 ){
      printf("%c%d ", bubble[i].suit, bubble[i].num) ;
    }else{
      printf("%c%d\n", bubble[i].suit, bubble[i].num) ;
    }
  }
  s = 1 ;
  for ( i = 0; i < n ; i++) {
    if(i>0 && bubble[i].num==bubble[i-1].num && bubble[i].idx<bubble[i-1].idx){
      s = 0 ;
    }
  }
  if(s){
    printf("Stable\n") ;
  }else{
    printf("Not Stable\n");
  }
}

void select_sort( card select[], int n )
{
  int i, j, min_i, s ;
  card tmp ;
  // select_sort( n, select ) ;
  for( i = 0 ; i < n ; ++i ){  // i = 未ソート部分の先頭
    min_i = i ;
    for( j = i ; j < n ; ++j ){
      if( select[min_i].num > select[j].num ){
        min_i = j ;
      }
    }
    if( i != min_i ){
      tmp = select[i] ;
      select[i] = select[min_i] ;
      select[min_i] = tmp ;
    }
  }
  for( i = 0 ; i < n ; i++ ){
    if( i < n-1 ){
      printf("%c%d ", select[i].suit, select[i].num) ;
    }else{
      printf("%c%d\n", select[i].suit, select[i].num) ;
    }
  }
  s = 1 ;
  for( i = 0 ; i < n ; i++ ){
    if( i>0 && select[i].num==select[i-1].num && select[i].idx<select[i-1].idx){
      s = 0 ;
    }
  }
  if(s){
    printf("Stable\n") ;
  }else{
    printf("Not stable\n") ;
  }
}

int main()
{
  int n ;
  card bubble[37], select[37], tmp ;
  scanf("%d", &n) ;

  int i ;
  for( i = 0 ; i < n ; i++ ){
    scanf(" %c%d", &bubble[i].suit, &bubble[i].num) ;
    bubble[i].idx  = i ;
    select[i] = bubble[i] ;
  }

  bubble_sort( bubble, n ) ;
  select_sort( select, n ) ;

  return 0 ;
}

