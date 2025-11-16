#include <stdio.h>
void quicksort(int ,int );
int n,W[1000];
int main(void){
  int i,cost1,cost2,total_cost=0,now,S,min,x=10000,rate;//S is sum
  int Copy[1000],Element[10001],Bool[1000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&W[i]);
    Copy[i]=W[i];
    Bool[i]=0;
    if(x>W[i])x=W[i];
  }

  quicksort(0,n-1);
  //calculate cost
  i=0;
  while(i<n){
    Element[W[i]]=i;
    i++;
  }
  
  i=0;
  while(i<n){
    if(Bool[i]==0){
      now=i;
      S=0;
      min=10000;
      rate=0;
      while(1){
        Bool[now]=1;
        rate++;
        if(min>Copy[now])
          min=Copy[now];
        S+=Copy[now];
        now=Element[Copy[now]];
        if(Bool[now]==1)break;
      }
      cost1=S+(rate-2)*min;
      cost2=S+min+(rate+1)*x;
      if(cost1<cost2)
        total_cost+=cost1;
      else total_cost+=cost2;
    }
    i++;
  }
  //finish calculate cost

  printf("%d\n",total_cost);
  return 0;
}
//quicksort include partition
void quicksort(int head,int last){
  int element;
  if(last-head>0){
    element=partition(head,last);
    quicksort(head,element-1);
    quicksort(element+1,last);
  }
}
int partition(int head,int last){
  int i,temp,last_number;
  last_number=W[last];
  for(i=head;i<last;i++){
    if(W[i]<=last_number){
      temp=W[head];
      W[head++]=W[i];
      W[i]=temp;
    }
  }
  temp=W[head];
  W[head]=W[last];
  W[last]=temp;
  return head;
}
