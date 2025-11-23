#include <stdio.h>
#include <stdlib.h>

void insert_sort(int *a,int l,int r){
    for(int i = l;i < r;i++){
        int temp = a[i];
        int j = i-1;
        while(j >= l&&a[j] > temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
        for(int k = l;k < r;k++){
            if(k != r-1)
                printf("%d ",a[k]);
            else
                printf("%d\n",a[k]);
        }
    }
}

int main()
{
    int a[110],N;
    scanf("%d",&N);
    for(int i = 0;i < N;i++)
        scanf("%d",&a[i]);
    insert_sort(a,0,N);

    return 0;
}

