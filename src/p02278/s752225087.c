#include<stdio.h>

void swap(int* a,int* b){
  int tmp=*a;
  *a=*b;
  *b=tmp;
}

int n,m;
int A[1000];
int B[1000];
int vd[1000];
int cnt,sum,mini;

int min(int x,int y){
  if(x<y)return x;
  else return y;
}

int search(int x){
  int i;
  for(i=0;i<n;i++){
    if(A[i]==x)return i;
  }
}

int main(){
  int i,j,ans,x;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    B[i]=A[i];
  }

  for(i=n-1;i>0;i--){
    for(j=0;j<i;j++){
      if(B[j]>B[j+1])swap(&B[j],&B[j+1]);
    }
  }

  m=B[0];
  ans=0;
  for(i=0;i<n;i++)vd[i]=0;

  for(i=0;i<n;i++){
    if(A[i]==B[i])continue;    
    x=i;
    cnt=sum=0;
    mini=(1<<24);
    while(vd[x]==0){
      vd[x]=1;
      cnt++;
      sum+=A[x];
      mini=min(mini,A[x]);
      x=search(B[x]);
    }

    if(cnt<2)continue;

    ans+=min(sum+m*(cnt+1)+mini,sum+mini*(cnt-2));

  }

  printf("%d\n",ans);
  return 0;
}