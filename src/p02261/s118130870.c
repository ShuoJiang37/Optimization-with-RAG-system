#include <stdio.h>
#include <string.h>

void bubble(char [],int [],int);
void selection(char [],int [],int);

int main()
{
  int number[36],Number[36];
  char array[36],Array[36];
  char blak;
  int i,n,flag=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%c%c%d",&blak,&array[i],&number[i]);
    Number[i]=number[i];
    Array[i]=array[i];
  }


  bubble(array,number,n);
  selection(Array,Number,n);

  for(i=0;i<n;i++)
    {
      if(array[i]!=Array[i]) {
      printf("Not stable\n");
      flag=1;
      break;
      }
    }
  if(flag==0) printf("Stable\n");
  return 0;
}

void bubble(char array[],int number[],int n)
{
  int i,j;
  int temp;
  char Temp;

  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(number[j]<number[j-1]){
	temp=number[j];
	Temp=array[j];
	number[j]=number[j-1];
	array[j]=array[j-1];
	number[j-1]=temp;
	array[j-1]=Temp;
      }
    }
  }
  for(i=0;i<n-1;i++){
    printf("%c%d ",array[i],number[i]);
  }
  printf("%c%d\n",array[i],number[i]);
  printf("Stable\n");

}


void selection(char array[],int number[],int n)
{
  int i,j,min;
  int temp;
  char Temp;

  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(number[j]<number[min]){
	min=j;
      }
    }
	temp=number[i];
	Temp=array[i];
	number[i]=number[min];
	array[i]=array[min];
	number[min]=temp;
	array[min]=Temp;
  }

  for(i=0;i<n-1;i++){
    printf("%c%d ",array[i],number[i]);
  }
  printf("%c%d\n",array[i],number[i]);    
}