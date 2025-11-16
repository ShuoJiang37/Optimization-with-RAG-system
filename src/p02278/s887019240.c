#include <stdio.h>
#define N 10000
#define MAX 1000

int su,n;
int A[MAX],B[MAX],C[N+1],f[MAX];

int res();
void bubbleSort(int b);
int min(int a,int b);

int main(){
  int i,t,r;
  su=10000;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    su=min(su,A[i]);
  }

  r=res();

  printf("%d\n",r);

  return 0;
}

void  bubbleSort(int b){
  int i,j,t,f=1;
  i=0;
  while(f==1){
    f=0;
    for(j=b-1;j>=i+1;j--){
      if(B[j]<B[j-1]) {
	t=B[j];
	B[j]=B[j-1];
	B[j-1]=t;
	f=1;
      }
    }
    i++;
  }
}

int min(int a,int b){
  if(a<b) return a;
  else return b;
}

int res(){
  int r=0,i,c,s,m,a,v;

  for(i=0;i<n;i++){
    B[i]=A[i];
    f[i]=0;
  }

  bubbleSort(n);

  for(i=0;i<n;i++) C[B[i]]=i;
  for(i=0;i<n;i++){
    if(f[i]==1) continue;
    c=i;
    s=0;
    m=10000;
    a=0;
    while(1){
      f[c]=1;
      a++;
      v=A[c];
      m=min(m,v);
      s=s+v;
      c=C[v];
      if(f[c]==1)break;
    }

    r=r+min(s+(a-2)*m,m+s+(a+1)*su);
  }
  return r;
}


