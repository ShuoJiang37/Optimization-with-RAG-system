#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void trace(int *a, int n)
{
     int i;
     for (i = 0; i < n - 1; i++)
         printf("%d ", a[i]);
     printf("%d\n", a[i]);
      
}

void insertion_sort(int *a, int n)
{
     int i, j, v;
     for (i = 1; i < n; i++) {
         v = a[i];
         j = i - 1;
         trace(a, n);
         while (j >= 0 && a[j] > v) {
               a[j+1] = a[j];
               j--;
         }
         a[j+1] = v;
     }
     trace(a, n);
}

int main(int argc, char *argv[])
{
	int i, n, a[MAX];

	scanf("%d", &n);
  
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    insertion_sort(a, n);

    return 0;
}
