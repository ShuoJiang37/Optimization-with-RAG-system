#include<stdio.h>
#include<string.h>
void judge(char bubble[][3],char selection[][3],int n);

int main(){
  int n;
  int i,j,minj;
  char a[36][3],b[36][3],temp[3];
 

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",a[i]);
    strcpy(b[i],a[i]);
  }

  /* BubbleSort */
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(a[j][1]<a[j-1][1]){
	strcpy(temp,a[j]);
	strcpy(a[j],a[j-1]);
	strcpy(a[j-1],temp);
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%s",a[i]);
    if(i!=n-1) printf(" ");
    else printf("\n");
  }
  printf("Stable\n");

  /* SelectionSort */
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(b[j][1]<b[minj][1]) minj = j;
    }
    if(minj != i){
	strcpy(temp,b[i]);
	strcpy(b[i],b[minj]);
	strcpy(b[minj],temp);
    }
  }
    for(i=0;i<n;i++){
    printf("%s",b[i]);
    if(i!=n-1) printf(" ");
    else printf("\n");
  }
    judge(a,b,n);
  
  return 0;
}

void judge(char bubble[][3],char selection[][3],int n){
  int i,count=0;
  for(i=0;i<n;i++)
    if(strcmp(bubble[i],selection[i])!=0) count++;
    if(count==0) printf("Stable\n");
    else printf("Not stable\n");
}


