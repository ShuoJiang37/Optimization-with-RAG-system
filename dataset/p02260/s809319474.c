#include <stdio.h>

int minsearch(int a[], int number, int size){
  int minnum = number;
  for ( int i = number; i < size; i++ ){
    if ( a[minnum] > a[i] ){
      minnum = i;
    }
  }
  return minnum;
}

int main()
{
 int a, i;
 int min, temp;
 int r[100];
 int num = 0;

 scanf("%d", &a);
 for ( i = 0; i < a; i++ ) {
  scanf("%d", &r[i]);
 }

 for ( i = 0; i < a; i++ ) {
  min = minsearch( r, i, a );
  if ( r[min] < r[i] ){
    temp   = r[min];
    r[min] = r[i];
    r[i]   = temp;
    num++;
  }
 }

 for ( i = 0; i < a-1; i++) {
  printf("%d ", r[i]);
 }
 printf("%d\n%d\n", r[a-1], num);

 return 0;
}
