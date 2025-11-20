#include <stdio.h>
#include <string.h>
#define N 10000
typedef struct aa{
  int value;
  char egara;
}Card;
void BubbleSort(int);
void SelectionSort(int);
void copy();
Card  a[N],b[N],c[N];
int flag1=0;
int main(){
  int num,i,j,judge,flag=0,k=0;
  char d[N];
  scanf("%d",&num);
  for(i =1;i<=num;i++){
    scanf(" %c%d",&a[i].egara,&a[i].value);
  }
  copy(num);
  BubbleSort(num);
  SelectionSort(num);


  for(i = 1;i<=num;i++){
    for(j =1;j<=num;j++){
      if(i!=j && a[j].value ==a[i].value){
	flag=1;
	d[k] = a[i].egara;
	k++;
      }
    }
  }
  k=0;
  for(i = 1;i<=num;i++){
    if(a[i].value == c[i].value){
      if(d[k] !=c[i].egara){
	flag1 = 1;
      }
      k++;
    }
  }
  
  for(i = 1;i<=num;i++){
    if(i == num){
      printf("%c%d\n",b[i].egara,b[i].value);
      printf("Stable\n");
    }
     else printf("%c%d ",b[i].egara,b[i].value);
  }

  for(i = 1;i<=num;i++){
    if(i == num){
      printf("%c%d\n",c[i].egara,c[i].value);
      if(flag ==1 && flag1==1){
	printf("Not stable\n");
      }
      else printf("Stable\n");
    }
    else   printf("%c%d ",c[i].egara,c[i].value);
  } 
    return 0;
  }
void copy(int n){
  int i;
  for(i =1;i<=n;i++){
    b[i].value = a[i].value;
    c[i].value = a[i].value;
    b[i].egara = a[i].egara;
    c[i].egara = a[i].egara;
  }
}
void BubbleSort(int n){
  int i,j,tmp;
  char tmp1;
  for(i = 1;i<=n;i++){
    for(j = n;j>=i+1;j--){
      if(b[j].value <b[j-1].value){
	tmp = b[j].value;
	b[j].value = b[j-1].value;
	b[j-1].value = tmp;
	tmp1 = b[j].egara;
	b[j].egara = b[j-1].egara;
	b[j-1].egara = tmp1;
      }
    }
  }
}
	
void SelectionSort(int n){
  int minj,i,tmp,j,flag=0;
  char tmp1;
  for(i = 1;i<=n;i++){
    minj = i;
    for(j=i;j<=n;j++){
      if(c[j].value <c[minj].value){
	minj =j;
      }
    }
    tmp = c[i].value;
    c[i].value = c[minj].value;
    c[minj].value = tmp;
    tmp1 = c[i].egara;
    c[i].egara = c[minj].egara;
    c[minj].egara = tmp1;
  }
}

