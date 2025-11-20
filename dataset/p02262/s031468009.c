#include <stdio.h>
#include <stdlib.h>

int cnt;
int G[100];

void insertionSort(int A[],int n,int g)
{
    int v,j;
    for(int i = g;i<n;i++)
    {
        v = A[i];
        j = i - g;
        while(j >= 0 && v < A[j])
        {
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void shellSort(int A[],int n)
{
    int m = 0,cnt = 0;
    G[0] = 1;
    while((3 * G[m] + 1) <= n)
    {
        m++;
        G[m] = 3 * G[m-1] + 1;
    }
    printf("%d\n", m+1);
    for(int i=m; i>0; i--){
        printf("%d ",G[i]);
    }
    printf("%d\n", G[0]);
    for(int i=m; i>=0; i--){
        insertionSort(A,n,G[i]);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int *A = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)    scanf("%d",&A[i]);
    shellSort(A,n);
    printf("%d\n",cnt);
    for(int i=0;i<n;i++)
    printf("%d\n",A[i]);
    free(A);
    return 0;
}
