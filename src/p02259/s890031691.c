#include<stdio.h>
//A is array and N is count
int bubble_sort(int array[],int size){
  int count=0,tmp,i,j;
  for(i=0;i<size;i++){
    for(j=size-1;j>i;j--){
      if(array[j]<array[j-1]){
        tmp=array[j];
        array[j]=array[j-1];
        array[j-1]=tmp;
        count++;
      }
    }
  }
  return count;
}

//int bubble_sort(int array[],int size){
//  int flag=1,count,j,tmp;
//  while(1){
//    flag=0;
//    for(j=size-1;j>=1;j--){
//      if(array[j]<array[j-1]){
//        tmp=array[j];
//        array[j]=array[j-1];
//        array[j-1]=tmp;
//        count++;
//        flag=1;
//      }
//    }
//    if(flag==0) break;
//  }
//  return count;
//}
int main(void){
  int i,size,array[100000],count;
  scanf("%d",&size);
  for(i=0;i<size;i++){
    scanf("%d",&array[i]);
  }
  count = bubble_sort(array,size);
  for(i=0;i<size;i++){
    if(i>0) printf(" ");
    printf("%d",array[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}