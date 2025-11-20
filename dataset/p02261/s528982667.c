#include<stdio.h>
typedef struct{
  char sign;
  int value;
}Card;
void BubbleSort(Card*,int);
void SelectionSort(Card*,int);
int isStable(Card*,Card*,int);
void output(Card*,int,int);
 
int main()
{
  Card a[36],b[36];
  int i,j,n;
 
  scanf("%d",&n);
  for(i=0; i<n; i++) {
    scanf(" %c%d",&a[i].sign,&a[i].value);
    b[i] = a[i];
  }
 
  BubbleSort(a,n);
  SelectionSort(b,n);
  output(a,n,0);
  output(b,n,isStable(b,a,n));
 
  return 0;
}
   
void BubbleSort(Card a[],int n)
{
  int i,j;
  Card tmp;
 
  for(i=0; i<n; i++) 
    for(j=n-1; j>i; j--) 
      if(a[j].value < a[j-1].value){
    tmp = a[j];
    a[j] = a[j-1];
    a[j-1] = tmp;
      }
}
 
void SelectionSort(Card b[],int n)
{
  int i,j,minj;
  Card tmp;
 
  for(i=0; i<n-1; i++) {
    minj = i;
    for(j=i; j<n; j++) 
      if(b[j].value < b[minj].value) minj = j;
    if(minj != i) {
      tmp = b[i];
      b[i] = b[minj];
      b[minj] = tmp;
    }
  }
}
 
int isStable(Card in[],Card out[],int n) 
{
  int i,j,a,b;
  for(i=0; i<n; i++) 
    for(j=i+1; j<n; j++)
      for(a=0; a<n; a++)
    for(b=a+1; b<n; b++)
      if(in[i].value == in[j].value && in[i].sign == out[b].sign && in[j].sign == out[a].sign && in[i].value == out[b].value && in[j].value == out[a].value)
        return 1;
  return 0;
}
 
void output(Card a[], int n,int result)
{
  int i;
   
  for(i=0; i<n; i++) {
    printf("%c%d",a[i].sign,a[i].value);
    if(i<n-1) printf(" ");
  }
  if(!result) printf("\nStable\n");
  else printf("\nNot stable\n");
}