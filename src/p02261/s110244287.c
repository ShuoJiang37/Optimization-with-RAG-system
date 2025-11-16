#include "stdio.h"


struct card{
    char c;
    int n;
};

int main()
{
    struct card a[36], b[36],x[36];
    int n, j=0, i=0, mini;
    scanf("%d", &n);
    
    for (i = 0; i <= n - 1; i++){
        scanf(" %c%d", &a[i].c,&a[i].n);
        b[i].c = a[i].c;
        b[i].n = a[i].n;
       

    }
    /*bublle*/
    for (i = 0; i < n ; i++) {
        for (j = n - 1; j > i; j--) {
            if (a[j].n < a[j - 1].n) {
                x[j] = a[j];
                a[j] = a[j - 1];
                a[j - 1] = x[j];
            }
        }
    }
    /*selectsort*/

    for (i = 0; i < n ; i++) {
        mini = i;
        for (j = i; j < n; j++) {
            if (b[j].n < b[mini].n)
                mini = j;
        }
            x[i] = b[i];
            b[i] = b[mini];
            b[mini] = x[i];
        }
    
      
    j = 0;
    for (j = 0; j < n - 1; j++)
        printf("%c%d ", a[j].c, a[j].n);

    printf("%c%d\n", a[n - 1].c, a[n - 1].n);
    printf("Stable\n");
    
    j = 0;
    for (j = 0; j < n - 1; j++)
    printf("%c%d ", b[j].c,b[j].n);

    printf("%c%d\n", b[n - 1].c, b[n - 1].n);

    j = 0;
    for (j = 0; j < n ; j++) {
        if (a[j].c != b[j].c) {
            printf("Not stable\n");
            break;
        }
    }
    if(j==n)
        printf("Stable\n");

    return 0;
}