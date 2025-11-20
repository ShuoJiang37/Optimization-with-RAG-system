#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void bubbleSort(char [][3],int);
void selectionSort(char [][3],int);
//void copyArray(char [][3], char [][], int);
int isStable(char [][3],char [][3], int);

int main() {
  int n,i;
  char a[36][3],b[100][3],s[100][3];
  
  // input data
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%s",a[i]);
  
  // sort
  for(i=0;i<n;i++) strcpy(b[i],a[i]);
  bubbleSort(b,n);

  for(i=0;i<n;i++) strcpy(s[i],a[i]);
  selectionSort(s,n);
  
  // output sorted data
  for(i=0;i<n-1;i++) printf("%s ",b[i]);
  printf("%s\n",b[n-1]);
  if( isStable(a,b,n) ) printf("Stable\n");
  else printf("Not stable\n");

  for(i=0;i<n-1;i++) printf("%s ",s[i]);
  printf("%s\n",s[n-1]);
  if( isStable(a,s,n) ) printf("Stable\n");
  else printf("Not stable\n");

  return 0;
}

// Sort by bubble sort and asc.
void bubbleSort(char a[][3], int n) {
  int j,flag=1;
  char tmp[3];
  
  while(flag) {
    flag = 0 ;
    for(j=n-1;j>0;j--) {
      if( a[j][1] < a[j-1][1] ) {
	strcpy(tmp,a[j]);
	strcpy(a[j],a[j-1]);
	strcpy(a[j-1],tmp);
	flag = 1;
      }
    }
  }
  

}

// Sort by selection sort and asc.
void selectionSort(char a[][3], int n) {
  
  int i,j,cnt=0,minj,bef;
  char tmp[3];
  
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++) {
      if( a[j][1] < a[minj][1] ) {
	minj = j;
      }
    }
    if(a[i][1] != a[minj][1]){
      strcpy(tmp,a[i]);
      strcpy(a[i],a[minj]);
      strcpy(a[minj],tmp);
    }
  }
  
  
  
}



// check whether out is stable
int isStable(char in[][3],char out[][3], int n){
  int i,j,a,b;

  for(i=0;i<n;i++) {
    for(j=i+1;j<n;j++) {
      for(a=0;a<n;a++) {
	for(b=a+1;b<n;b++) {
	  if( in[i][1] == in[j][1] && in[i][0] == out[b][0] && in[i][1] == out[b][1] && in[j][0] == out[a][0] && in[j][1] == out[a][1] ){ return 0;}
	}
      }
    }
  }
  
  return 1;
}