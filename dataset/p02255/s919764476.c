#include <stdio.h>

int main()
{
 int i, j, a, k;
 int temp;
 int r[100];

 scanf("%d", &a);
 for ( i = 0; i < a; ++i ) {
  scanf("%d", &r[i]);
 }

 for ( i = 0; i < a; i++ ) {
  j = i;
  while ( ( r[j] < r[j-1] ) && ( j > 0) ) {
   temp   = r[j];
   r[j]   = r[j-1];
   r[j-1] = temp;
   j--;
  }

   for ( k = 0; k < a-1; ++k ) {
    printf("%d ", r[k]);
   }
   printf("%d\n", r[a-1]);

 }

 return 0;
}

