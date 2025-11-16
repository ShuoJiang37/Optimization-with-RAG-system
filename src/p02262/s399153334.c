#include<stdio.h>
 
int cnt=0;
void shellSort(int NUM[],int num){
  int i;
  int m_count=0;
  int recursion[1000];
   
  m_count=formula(num,recursion);
  
  printf("%d\n",m_count);
  for(i=0;i<m_count;i++){
    if(i!=0) printf(" ");
    printf("%d",recursion[i]);
  }
  printf("\n");
  for(i=0;i<m_count;i++){
    insertionSort(NUM,num,recursion[i]);
  }
}
void insertionSort(int NUM[],int num,int recursion){
  int i,j;
  int mask;
 
  for(i=recursion;i<num;i++){
    mask=NUM[i];
    j=i-recursion;
    while(j>=0&&NUM[j]>mask){
      NUM[j+recursion]=NUM[j];
      j=j-recursion;
      cnt++;
    }
    NUM[j+recursion]=mask;
  }
}
int formula(int num,int array[]){
  int i,j;
  int count=1;
  int mask[1000];
   
  mask[0]=1;
 
  while(1){
    mask[i+1]=3*mask[i]+1;
    if(mask[i+1]>num)break;
    count++;
    i++;
  }
  
  j=count-1;
  
  for(i=0;i<count;i++){
    array[j]=mask[i];
    j--;
  }
  return count;
}
int main(){
  int i;
  int num;
  int array[1000000];
  
  scanf("%d",&num);
  
  for(i=0;i<num;i++){
    scanf("%d",&array[i]);
  } 
 
  shellSort(array,num);
  printf("%d\n",cnt);
  for(i=0;i<num;i++){
    printf("%d\n",array[i]);
  } 
  return 0;
}