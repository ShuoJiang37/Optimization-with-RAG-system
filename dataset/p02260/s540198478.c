#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void show_array(int *a, int n)
{
     int i;
     
     for (i = 0; i < n; i++) {
         if (i > 0) printf(" ");
         printf("%d", a[i]);    
     }
     printf("\n");
}

selection_sort(int *a, int n)
{
    int i, j, cnt = 0;
    int minj = 0, minv;
    int t;
    
    for (i = 0; i < n; i++) {
        minv = a[i];
        minj = i;
        for (j = i; j < n; j++) {
            if (a[j] < minv) {
                minv = a[j];
                minj = j;
            }
        }
        if (minj != i) {
            t = a[i];
            a[i] = a[minj];
            a[minj] = t;  
            cnt++;  
        }
    }
    
    show_array(a, n);
    printf("%d\n", cnt);
}

int main(int argc, char *argv[])
{
	int i, n, a[MAX];

	scanf("%d", &n);
  
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
  
        selection_sort(a, n);
  	
	return 0;
}
