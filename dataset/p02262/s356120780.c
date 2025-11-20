#include<stdio.h>
#include<stdlib.h>
void ssort(int*, int);
main()
{
    int *a, n, i;
    scanf("%d", &n);
    a = (int*)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    ssort(a, n);
    for(i = 0; i < n; i++){
        printf("%d\n", a[i]);
    }
    free(a);
}
void ssort(int *a, int n)
{
    int i,j, temp, gap[100] = {1}, size = 0, cnt = 0;
    do{
        gap[size + 1] = gap[size] * 3 + 1;
        size++;
    }while(gap[size] < n);
    printf("%d\n", size);
    for(i = size - 1; i >= 1; i--){
        printf("%d ", gap[i]);
    }
    printf("%d\n", gap[i]);
    do{
        size--;
        for(i = gap[size]; i < n; i++){
            temp = a[i];
            j = i - gap[size];
            while(j >= 0 && a[j] > temp){
                a[j + gap[size]] = a[j];
                j -= gap[size];
                cnt++;
            }
            a[j + gap[size]] = temp;
        }
    }while(size);
    printf("%d\n", cnt);
}