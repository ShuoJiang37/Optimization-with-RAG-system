#include<stdio.h>

int n;
int A[1000], B[1000], data[1000];
int cnt,sum,minimam;

void swap(int* a,int* b){
  int tmp=*a;
  *a = *b;
  *b = tmp;
}

int min(int x,int y){
  if(x < y){
    return x;
  }else{
    return y;
  }
}

int search(int x){
  int i;
  for(i = 0 ; i < n ; i++){
    if(A[i] == x){
      return i;
    }
  }
}

int main(){
  int i, j;
  int answer, x;

  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
    B[i]=A[i];
  }

  for(i = n - 1 ; i > 0 ; i--){
    for(j = 0 ; j < i ; j++){
      if(B[j] > B[j + 1])swap(&B[j],&B[j+1]);
    }
  }

  answer = 0;
  for(i = 0 ; i < n ; i++)data[i]=0;

  for(i = 0 ; i < n ; i++){
    x = i;
    cnt=sum=0;
    minimam=(1<<24);
    while(data[x] == 0){
      data[x]=1;
      cnt++;
      sum+=A[x];
      minimam = min(minimam,A[x]);
      x = search(B[x]);
    }
    if(cnt<2){
      continue;
    }
    answer+=min(sum+B[0]*(cnt+1)+minimam,sum+minimam*(cnt-2));
  }

  printf("%d\n",answer);
  return 0;
}

