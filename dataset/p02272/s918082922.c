#include <stdio.h>
#define N 500000
#define INFTY 1000000001

int L[N],R[N],count;

void merge(int *A, int left, int mid, int right){
    int i,j,k,n1,n2;
    n1 = mid - left;
    n2 = right - mid;
    //L[0...n1], R[0...n2] を生成
    for(i=0;i<n1;i++)
        L[i] = A[left + i];
    for(i=0;i<n2;i++)
        R[i] = A[mid + i];
    L[n1] = INFTY;
    R[n2] = INFTY;
    i = 0;
    j = 0;
    for(k=left;k<right;k++){
        count++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int *A, int left, int right){
    if(left+1 < right){
        int mid = (left + right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(void){
    int n,i,A[N];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    mergeSort(A, 0, n);
    for(i=0;i<n-1;i++)
        printf("%d ",A[i]);
    printf("%d\n%d\n",A[i],count);
}



