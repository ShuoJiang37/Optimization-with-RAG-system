#include <stdio.h>
#define N 36

typedef struct{
  char mark;
  int number;
} trump;

void bubbleSort(trump *,int );
void selectionSort(trump *, int );
int isStable(trump *, trump *,int);

int main(){

  int i,n;  
  trump tin[N],tout[N];
  
  scanf("%d",&n);
  
  for(i = 0; i < n ; i++){
    scanf(" %c%d",&tin[i].mark,&tin[i].number);
    tout[i] = tin[i];
  }
  bubbleSort(tin,n);
  printf("Stable\n");
 
 selectionSort(tout,n);
 if(isStable(tin,tout,n) == 1)printf("Stable\n");
 else printf("Not stable\n");
 
 return 0;
}

void bubbleSort(trump a[],int n){
  int i,j;
  trump tmp[1];

  for(i = 0; i < n ; i++){
    for(j = n-1 ; j >= i+1 ; j--){
      if(a[j].number < a[j-1].number){
	tmp[0] = a[j];
	a[j] = a[j-1];
	a[j-1] = tmp[0];
      }
    }
  }
   for(i = 0 ; i < n-1 ; i++){
  printf("%c%d ",a[i].mark,a[i].number);
   }
   printf("%c%d\n",a[i].mark,a[i].number);
  }

void selectionSort(trump *a, int n){
  int i,j,minj;
  trump tmp[1];
  
  for(i = 0; i < n ; i++){
    minj = i;
    for(j = i ; j < n; j++){
      if(a[j].number < a[minj].number){
	 minj = j;
       }
     }
    tmp[0] = a[i];
    a[i] = a[minj];
    a[minj] = tmp[0];
   }
   for(i = 0 ; i < n-1 ; i++){
     printf("%c%d ",a[i].mark,a[i].number);
   }
   printf("%c%d\n",a[i].mark,a[i].number);
 }

 int isStable(trump *in,trump *out,int n){
   int i;

     for(i = 0; i < n; i++){
       if(in[i].mark != out[i].mark)return 0;
     }
   return 1;
 }
  


