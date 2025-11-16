#include<stdio.h>
//A is array and N is count
int selection_sort(int array[],int size){
  int count=0,min,min_index,tmp,i,j;
  for(i=0;i<size;i++){
    min_index=i;
    for(j=i;j<size;j++){
      if(array[j]<array[min_index]){
        min=array[j];
        min_index=j;
      }
    }
    if(i!=min_index) count++;
    tmp=array[i];
    array[i]=min;
    array[min_index]=tmp;
  }
  return count;
}

int main(void){
  int i,size,array[100000],count;
  scanf("%d",&size);
  for(i=0;i<size;i++){
    scanf("%d",&array[i]);
  }
  count = selection_sort(array,size);
  for(i=0;i<size;i++){
    if(i>0) printf(" ");
    printf("%d",array[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}