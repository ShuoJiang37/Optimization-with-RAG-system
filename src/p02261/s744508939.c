#include<stdio.h>
#include<string.h>
void judge(char bubble[][3],char selection[][3],int n);

int main(){
  int n;
  int i,k,minj;
  char a[36][3],b[36][3],temp[3];
 

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",a[i]);
    strcpy(b[i],a[i]);
  }

  
  for(i=0;i<n;i++){
    for(k=n-1;k>i;k--){
      if(a[k][1]<a[k-1][1]){
	strcpy(temp,a[k]);
	strcpy(a[k],a[k-1]);
	strcpy(a[k-1],temp);
      }
    }
  }
  
  for(i=0;i<n;i++){
    printf("%s",a[i]);
    if(i!=n-1) printf(" ");
    else printf("\n");
  }
  
  printf("Stable\n");

  
  for(i=0;i<n;i++){
    minj = i;
    for(k=i;k<n;k++){
      if(b[k][1]<b[minj][1]) minj = k;
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



