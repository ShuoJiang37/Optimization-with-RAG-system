#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<math.h>
 
int_fast32_t insertion_sort(int_fast32_t *a, int_fast32_t n, int_fast32_t g)
{
    int_fast32_t cnt = 0;
    for(int_fast32_t i=g; i<n; ++i){
        int_fast32_t v = a[i];
        int_fast32_t j = i - g;
        while(j >= 0 && a[j] > v){
            a[j+g] = a[j];
            j -= g;
            ++cnt;
        }
        a[j+g] = v;
    }
    return cnt;
}
 
void shell_sort(int_fast32_t *a, int_fast32_t n)
{
    int_fast32_t cnt = 0;
    int_fast32_t m   = log(2.0*n+1.0)/log(3.0);
    int_fast32_t g[m];
    g[m-1] = 1;
    for(int_fast32_t i=1; i<m; ++i)
        g[m-i-1] = g[m-i]*3+1;
 
    for(int_fast32_t i=0; i<m; ++i)
        cnt += insertion_sort(a, n, g[i]);
 
    printf("%"PRIdFAST32"\n", m);
    printf("%"PRIdFAST32, g[0]);
    for(int_fast32_t i=1; i<m; ++i)
        printf(" %"PRIdFAST32, g[i]);
    printf("\n");
    printf("%"PRIdFAST32"\n", cnt);
}
 
int main(void)
{
    int_fast32_t n;
    scanf("%"SCNdFAST32, &n);
 
    int_fast32_t a[n];
    for(uint_fast32_t i=0; i<n; ++i)
        scanf("%"SCNdFAST32, &a[i]);
 
    shell_sort(a, n);
 
    for(uint_fast32_t i=0; i<n; ++i)
        printf("%"PRIdFAST32"\n", a[i]);
 
    return 0;
}