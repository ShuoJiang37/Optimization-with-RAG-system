#include<stdio.h>
#include<math.h>
#include<time.h>
#include<assert.h>
#define MAX 1000000
int cnt,A[MAX];
void insertionSort(int *A,int n,int G){
  int i,j,v;
  for(i=G;i<n;i++){
    v=A[i];
    j = i - G;
    while( j >= 0 && A[j] > v ){
      A[j+G] = A[j];
      j = j - G;
      cnt++;
    }
    A[j+G] = v;
  }
}

void shellSort(int *A,int n){
  int i,m;
  cnt=0;
  m = pow(n,1.25);
  if(m>=100) m=100;
  int G[m];
  G[0]=1;
  for(i=1;i<m;i++){
    if((G[i]=3*G[i-1]+1)>n) break;
  }
  m=i;
  for(i=m-1;i>=0;i--){
    insertionSort(A,n,G[i]);
  }
  assert(cnt<=pow(n,1.5));
    printf("%d\n",m);
    for(i=m-1;i>0;i--) printf("%d ",G[i]);
    printf("%d\n",G[i]);
    printf("%d\n",cnt);
    for(i=0;i<n;i++) printf("%d\n",A[i]);
}

int main(){
  srand((unsigned int)time(NULL));
  int i,n,A[MAX];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  shellSort(A,n);
  return 0;
}