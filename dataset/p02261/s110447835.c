#include<stdio.h>

#define N 36

typedef struct{
  char iro;
  int num;
  int turn;
}data;

int main(){
  
  int i,j,n,flag=1,minj;
  data arr1[N],arr2[N],tmp;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    while(1){
      scanf("%c",&arr1[i].iro);
      if(arr1[i].iro!='S'&&arr1[i].iro!='H'&&arr1[i].iro!='C'&&arr1[i].iro!='D'){
	continue;
      }
      scanf("%d",&arr1[i].num);
      break;
    }
      arr1[i].turn=i+1;
      arr2[i]=arr1[i];
  }
  
  for(i=0;i<=n-1;i++){
    for(j=n-1;j>=i+1;j--){
      if(arr1[j].num<arr1[j-1].num){
	tmp = arr1[j];
	arr1[j] = arr1[j-1];
	arr1[j-1] = tmp;
      }}}
  
  for(j=0;j<n-1;j++){
    printf("%c%d ",arr1[j].iro,arr1[j].num);
  }

  printf("%c%d\n",arr1[n-1].iro,arr1[n-1].num);

  for(i=1;i<n;i++){
    if(arr1[i].num==arr1[i-1].num&&arr1[i].turn-arr1[i-1].turn<0){
      flag=0;
    }}
  if(flag==1)printf("Stable\n");
  else printf("Not stable\n");
  
  flag = 1;
  
  for(i=0;i<n-1;i++){
    minj = i;
    for(j=i;j<=n-1;j++){
      if(arr2[j].num<arr2[minj].num){
	minj = j;
      }
    }
    tmp = arr2[i];
    arr2[i] = arr2[minj];
    arr2[minj] = tmp;
  }
  
  for(i=0;i<n-1;i++){
    printf("%c%d ",arr2[i].iro,arr2[i].num);
  }
  
  printf("%c%d\n",arr2[n-1].iro,arr2[n-1].num);
  
  for(i=1;i<n;i++){
    if(arr2[i].num==arr2[i-1].num&&arr2[i].turn-arr2[i-1].turn<0){
      flag=0;
    }}
  if(flag==1)printf("Stable\n");
  else printf("Not stable\n");
  

  
  return 0;
}