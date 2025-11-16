#include<stdio.h>
typedef struct {
  char C[37];
  int A[37];
}Curd;
Curd curd[3];
void bubblesort(int n){
  int i,flag=1,temp1;
  char temp2;
  while(flag==1){
    flag=0;
    for(i=n-1;i>=1;i--){
      if(curd[1].A[i] < curd[1].A[i-1]){
        temp1=curd[1].A[i];
	temp2=curd[1].C[i];
        curd[1].A[i]=curd[1].A[i-1];
	curd[1].C[i]=curd[1].C[i-1];
        curd[1].A[i-1]=temp1;
	curd[1].C[i-1]=temp2;
        flag=1;
      }
    }
  }
}

void selectionsort(int n){
  int i,j,minj,temp1,flag;
  char temp2;
  for(i=0;i<n;i++){
    flag=0;
    minj=i;
    for(j=i;j<n;j++){
      if(curd[2].A[j] < curd[2].A[minj]){
        minj=j;
        flag++;
      }
    }
    if(flag!=0){
      temp1=curd[2].A[i];
      temp2=curd[2].C[i];
      curd[2].A[i]=curd[2].A[minj];
      curd[2].C[i]=curd[2].C[minj];
      curd[2].A[minj]=temp1;
      curd[2].C[minj]=temp2;

    }
  }
}

int main(){
  int i,j,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c",&curd[0].C[i]);
    scanf("%d",&curd[0].A[i]);
  }
  for(j=1;j<3;j++){
    for(i=0;i<n;i++){
      curd[j].C[i]=curd[0].C[i];
      curd[j].A[i]=curd[0].A[i];
}
}
  bubblesort(n);
  selectionsort(n);
  for(i=0;i<n;i++){
    printf("%c%d",curd[1].C[i],curd[1].A[i]);
    if(i!=n-1){
    printf(" ");
    }
}
  printf("\nStable\n");

  for(i=0;i<n;i++){
    printf("%c%d",curd[2].C[i],curd[2].A[i]);
    if(i!=n-1){
      printf(" ");
    }
  }
  j=0;
  for(i=0;i<n;i++){
    if((curd[1].A[i]==curd[2].A[i])&&(curd[1].C[i]==curd[2].C[i])){
      j++;
}
}
  if(j==n){
    printf("\nStable\n");
}
  else{
    printf("\nNot stable\n");
}
  return 0;
}

