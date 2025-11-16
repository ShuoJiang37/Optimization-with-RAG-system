#include<stdio.h>
#include<stdlib.h>
#define INFTY 1000000000
void merges(int*,int,int,int);
void mergesorts(int*,int,int);
int count=0;
int n;
int main(){
  int mid;
  int right;
  int left;
  int *list;
  scanf("%d",&n);
  list=(int *)malloc(n*sizeof(int));
  mid=(n-1)/2;
  left=0;
  right=n;
  int i;
  for(i=0;i<n;i++)scanf("%d",&list[i]);
  mergesorts(list,left,right);
  for(i=0;i<n;i++)printf("%d%c",list[i],((i<n-1)?' ':'\n'));
  printf("%d\n",count);
  free(list);
  return 0;
}
void merges(int* list,int left,int mid,int right){
  int i;
  int j;
  int k;
  int m1;
  int m2;
  int *n1;
  int *n2;
  m1=mid-left;
  m2=right-mid;
  n1=(int *)malloc((m1+1)*sizeof(int));
  n2=(int *)malloc((m2+1)*sizeof(int));
  for(i=0;i<m1;i++)n1[i]=list[left+i];
  for(i=0;i<m2;i++)n2[i]=list[mid+i];
  n1[m1]=INFTY;
  n2[m2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(n1[i]<=n2[j]){
      list[k]=n1[i];
      i++;
    }
    else{
      list[k]=n2[j];
      j++;
    }
    count++;
  }
  free(n1);
  free(n2);
}
void mergesorts(int *list,int left,int right){
int mid;
if(left+1<right){
mid=(left+right)/2;
mergesorts(list,left,mid);
mergesorts(list,mid,right);
merges(list,left,mid,right);
}
}

