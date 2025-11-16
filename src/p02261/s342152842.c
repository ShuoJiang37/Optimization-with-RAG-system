/* Stability */
#include<stdio.h>
int A[37];
char C[37];
int n;
void BubbleSort();
void SelectionSort();
int IsStable(char *, int *);
main(){
  char g;
  int i;
  
  scanf("%d%*d",&n);     /* This n is length of array.*/
  if(n<1||n>36)return 0; /* Constraints: 1<= n <= 36 */
  for(i=1;i<=n;i++){
    scanf("%c%d%*c",&C[i],&A[i]);
  }
  BubbleSort();
  SelectionSort();
  return 0;
}

void BubbleSort(){
  int i,j,temp1;
  char c[37], temp2;
  int a[37];

  for(i=1;i<=n;i++){
    a[i]=A[i];
    c[i]=C[i];
  }

  for(i=1;i<=n;i++){
    for(j=n;j>i;j--){
      if(a[j]<a[j-1]){
	temp1=a[j];
	a[j]=a[j-1];
	a[j-1]=temp1;
	temp2=c[j];
	c[j]=c[j-1];
	c[j-1]=temp2;
      }
    }
  }
  for(i=1;i<n;i++){
    printf("%c%d ",c[i],a[i]);
  }
  printf("%c%d\n",c[i],a[i]);
  IsStable(c,a);
}


void  SelectionSort(){
  int i,j,temp1,mini;
  char c[37], temp2;
  int a[37];
  
  for(i=1;i<=n;i++){
    a[i]=A[i];
    c[i]=C[i];
  }

  for(i=1;i<=n;i++){
    mini=i;
    for(j=i;j<=n;j++){
      if(a[j]<a[mini])mini=j;
    }
    temp1=a[i];
    a[i]=a[mini];
    a[mini]=temp1;
    temp2=c[i];
    c[i]=c[mini];
    c[mini]=temp2;
  }
  for(i=1;i<n;i++){
    printf("%c%d ",c[i],a[i]);
  }
  printf("%c%d\n",c[i],a[i]);
  IsStable(c,a);
}

int IsStable(char *sC, int *sA){
  int i,j,temp1,temp2;
  char c[37];
  int a[37];

  for(i=1;i<=n;i++){
    a[i]=sA[i];
    c[i]=sC[i];
  }
  for(i=1;i<n;){
    if(a[i]==a[i+1]){
      for(j=1;j<=n;j++){
	if(a[i]==A[j]&&c[i]==C[j])temp1=j;
	if(a[i+1]==A[j]&&c[i+1]==C[j])temp2=j;
      }
      if(temp1>temp2){
	printf("Not stable\n");
	return 0;
      }
      i++;
    }
    else i++;
  }
  if(i==n){
    printf("Stable\n"); 
    return 0;
  }
}
      