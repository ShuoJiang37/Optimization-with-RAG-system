//2020.1.18
//s1270188 xxxmk2
//alds1_06d

#include<stdio.h>
#define N 1000
#define MAX 10000

//prototype
int partition(int,int);
void q_sort(int,int);
int cnt(void);

//global
int data[N], B[N], num, min=MAX; 

int main(){
  int i;

  //input
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&data[i]);
    if(min>data[i]) min=data[i];
  }
  
  //output
  printf("%d\n",cnt());
  
  return 0;
}

int cnt(void){
  int cnt=0;
  int V[N], T[MAX];
  int i, cur, S, m, an, v;
  int a, b;

  for(i=0;i<num;i++){
    B[i]=data[i];
    V[i]=0;
  }

  q_sort(0,num-1);

  for(i=0;i<num;i++) T[B[i]]=i;
  
  for(i=0;i<num;i++){
    if(V[i]==1) continue;
    
    cur=i;
    S=an=0;
    m=MAX;
    while(1){
      V[cur]=1;
      an++;
      v=data[cur];
      if(v<m) m=v;
      S+=v;
      cur=T[v];
      if(V[cur]) break;
    }
    a=S+(an-2)*m;
    b=m+S+(an+1)*min;
    if(a<b) cnt+=a;
    else cnt+=b;
  }

  return cnt;
}



int partition(int l,int r){
  int i, j, tmp;

  for(i=l-1,j=l;j<r;j++){
    if(B[j]<=B[r]){
      i++;
      tmp=B[i];
      B[i]=B[j];
      B[j]=tmp;
    }
  }
  tmp=B[i+1];
  B[i+1]=B[r];
  B[r]=tmp;
  
  return i+1;
}
  
void q_sort(int l,int r){
  int m;
  if(l<r){
    m=partition(l,r);
    q_sort(l,m-1);
    q_sort(m+1,r);
  }
}

