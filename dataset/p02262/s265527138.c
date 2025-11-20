#include<stdio.h>
#include<stdlib.h>
#define N 1000000
int cnt=0;
int n;
int l;
int A[N];
int *G;

void insertionSort(int A[], int n, int g){
int i,v,j;
  for(i=g;i<n;i++){
    v=A[i];
    j=i-g;
    while(j>=0&&A[j]>v){
      A[j+g]=A[j];
      j-=g;
      cnt++;
    }
    A[j+g]=v;
  }
}

void shellSort(int A[],int n){
  int i=0,h;

G=(int *)malloc(n * sizeof(int));
  
for(h=1; ; ){
if(h>n) break;
G[i]=h;
i++;
  h=3*h+1;
}
l=i;
  for(i=l-1;i>=0;i--){
    insertionSort(A,n,G[i]);
  }
}



int main(){
int i;
scanf("%d",&n);
for(i=0;i<n;i++) scanf("%d",&A[i]);
cnt=0;
  
shellSort(A,n);

printf("%d\n",l);

for(i=l-1;i>=0;i--){
printf("%d",G[i]);
if(i) printf(" ");
}
printf("\n");
printf("%d\n",cnt);
for(i=0;i<n;i++)printf("%d\n",A[i]);

 free(G);
  return 0;
}

