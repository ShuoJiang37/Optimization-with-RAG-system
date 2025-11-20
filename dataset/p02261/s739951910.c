#include<stdio.h>
#define N 36

typedef struct{
  int Num;
  char Role;
}Tramp;


int main(){
  Tramp tr[N],mp[N],temp;
  int loop;
  int i,j,min,count=0;
  int flag=1;
  
  scanf("%d",&loop);
  for(i=0;i<loop;i++){
    scanf(" %c%d",&tr[i].Role,&tr[i].Num);
    mp[i]=tr[i];
  }
  
  while(1){
    if(flag==0)break;
    flag=0;
    for(j=loop-1;j>0;j--){
      if(tr[j].Num<tr[j-1].Num){
	temp=tr[j];
	tr[j]=tr[j-1];
	tr[j-1]=temp;
	flag=1;
      }
    }
  }

  for(i=0;i<loop-1;i++){
    min=i;
    for(j=i;j<loop;j++){
      if(mp[j].Num<mp[min].Num){
	min=j;
      }
    }
    temp=mp[i];
    mp[i]=mp[min];
    mp[min]=temp;
  }

  for(i=0;i<loop-1;i++){
    printf("%c%d ",tr[i].Role,tr[i].Num);
  }
  
  printf("%c%d\n",tr[loop-1].Role,tr[loop-1].Num);
  printf("Stable\n");
  
  for(i=0;i<loop-1;i++){
    printf("%c%d ",mp[i].Role,mp[i].Num);
  }
  
  printf("%c%d\n",mp[loop-1].Role,mp[loop-1].Num);

  flag=0;
  while(count<loop){
    if(tr[count].Role!=mp[count].Role){
      flag=1;
      count++;
    }
    count++;
  }

  if(flag==1) printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}


