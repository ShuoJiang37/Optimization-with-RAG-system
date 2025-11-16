#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void BubbleSort(int*,int,char*);
void SelectionSort(int*,int,char*);
void judge(char*,char*);
void swap(int*,int*,char*,char*);
typedef struct{
	int *value; 
	char *kind;
}Arr;
	
int main(void){
	int i,num,*temp_int;
	char temp_chr,*temp;
	Arr arr;
	scanf("%d%c",&num,&temp_chr);
	arr.value = (int *)malloc(num * sizeof(int));
	arr.kind = (char *)malloc(num * sizeof(char));
	temp_int = (int *)malloc(num * sizeof(int));
	temp = (char *)malloc(num *sizeof(char));
	for(i=0;i<num;i++)scanf("%c%d%c",&arr.kind[i],&arr.value[i],&temp_chr);
	//for(i=0;i<num;i++)printf("%c%d \n",arr.kind[i],arr.value[i]);
	strcpy(temp,arr.kind);
	for(i=0;i<num;i++)temp_int[i] = arr.value[i];
	BubbleSort(arr.value,num,arr.kind);
	SelectionSort(temp_int,num,temp);
	judge(temp,arr.kind);
	free(temp_int);
	free(arr.value);
	free(arr.kind);
	free(temp);
	//judge(temp,arr.kind);
	return 0;
}	
void BubbleSort(int *arr,int num,char *chr){
	int i,j;
	for(i=0;i<num;i++){
		for(j=num-1;j>0;j--) if(arr[j] < arr[j-1]) swap(&arr[j],&arr[j-1],&chr[j],&chr[j-1]);
		}
	for(i=0;i<num;i++) i != num-1 ? printf("%c%d ",chr[i],arr[i]) : printf("%c%d\nStable\n",chr[i],arr[i]);
}	
void SelectionSort(int *arr,int num,char *chr){
  int i,j,min;
  for(i=0;i<num;i++){
    min = i;
    for(j=i;j<num;j++)if(arr[j]<arr[min]) min = j; 
    if(arr[min] != arr[i])swap(&arr[i],&arr[min],&chr[i],&chr[min]); 
 }
  for(i=0;i<num;i++) {
    i != num-1 ? printf("%c%d ",chr[i],arr[i]) : printf("%c%d\n",chr[i],arr[i]);
  }
}
	
void swap(int *arr,int *arr_arr,char *chr,char *chr_chr){
	int temp = 0;
	char temp_chr;
	temp = *arr;
	*arr = *arr_arr;
	*arr_arr = temp;
	temp_chr = *chr;
	*chr = *chr_chr;
	*chr_chr = temp_chr;
}	
void judge(char *temp,char *tmp){
  strcmp(temp,tmp)?printf("Not stable\n"):printf("Stable\n");
}