#include <stdio.h>
typedef struct {
  char c;
  int i;
} Point;
void X(Point*,int);
void Y(Point*,int);  
int main ()
{
  int i,n,judge=0;
  char hi[3];
  Point data[36],data2[36];
  scanf ("%d",&n);
  for(i=0;i<n;i++){
    scanf ("%s",hi);
    data[i].c=hi[0];
    data[i].i=hi[1]-'0';
    data2[i]=data[i];
  }
  X(data,n);
  for (i=0;i<n;i++){
    printf ("%c%d",data[i].c,data[i].i);
    if (i==n-1)break;
    printf (" ");
  }
  printf ("\n");
  printf ("Stable\n");

  Y(data2,n);

  for (i=0;i<n;i++){
    printf ("%c%d",data2[i].c,data2[i].i);
    if (data2[i].c!=data[i].c)
      judge=1;
    if (i==n-1)break; 
    printf(" ");
  }
  printf ("\n");
  if (judge==1)
    printf("Not stable\n");
  else  printf("Stable\n");
  return 0;
}
void X (Point* A,int N){
  int j;
  Point p;
  int flag;
  flag=1;
  while (flag==1){
    flag=0;
    for (j=N-1;j>=1;j--){
      if (A[j].i<A[j-1].i){
	/*交換*/
	p=A[j];
	A[j]=A[j-1];
	A[j-1]=p;
	flag=1;
      }   
    }
  } 
}


void  Y (Point* A,int N){
  int i,j,minj;
  Point p;
  for (i=0;i<=N-1;i++){
    minj=i;
    for (j=i;j<=N-1;j++){
      if (A[j].i<A[minj].i){
	minj=j;
      }
    }
    /*交換*/
    if(i!=minj){
      p=A[i];
      A[i]=A[minj];
      A[minj]=p; 
    }
  }
 
}

