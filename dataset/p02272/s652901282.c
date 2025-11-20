#include<stdio.h>
#define inf 2000000000

int count=0;

void merge(int A[],int left,int mid,int right){
    int i;
    int n1=mid-left;
    int n2=right-mid;
    int L[n1+1],R[n2+1];
    for(i=0;i<=n1-1;i++){
        L[i]=A[left+i];
    }
    for(i=0;i<=n2-1;i++){
        R[i]=A[mid+i];
    }
    L[n1]=inf;
    R[n2]=inf;
    i=0;
    int j=0,s;
    for(s=left;s<=right-1;s++){
        if(L[i]<=R[j]){
            A[s]=L[i];
            i++;
            }
        else{
            A[s]=R[j];
            j++;
            
        }
        count++;
    }
}

void mergeSort(int A[],int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}


int main(){
    int num;
    scanf("%d",&num);
    int A[num];
    int i;
    for(i=0;i<=num-1;i++)scanf("%d",&A[i]);
    
    mergeSort(A,0,num);
    
    for(i=0;i<=num-2;i++){
        printf("%d ",A[i]);
    }
    printf("%d\n",A[num-1]);
    printf("%d\n",count);
    
    return 0;
}

