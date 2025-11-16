#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int *a;
    int n;
    int i, j;
    int v;
    
    if ((a = (int *)malloc(sizeof(int) * n)) == NULL) {
        exit(EXIT_FAILURE);
    }
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (i = 0; i < n; i++) {
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        
        for (j = 0; j < n; j++) {
            printf("%d", a[j]);
            if (j != n-1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
    
    return 0;
}

