#include <stdio.h>
#include <string.h>

int main(){
  int n,flag,i,j,min;
  char a[37][3],b[37][3],kari[3];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%s",a[i]);
    strcpy(b[i],a[i]);
  }

  flag=1; /* 1==安定(バブルソートは常に安定) */
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if( (int)(a[j][1]-a[j-1][1])<0){ 
	strcpy(kari,a[j]);
	strcpy(a[j],a[j-1]);
	strcpy(a[j-1],kari);
      }
    }
  }

  for(i=0;i<n;i++){
    printf("%s",a[i]);
    if(i!=n-1) printf(" ");
  }
  if(flag) printf("\nStable\n");
  else printf("\nNot stable\n");

  /* 選択ソート */
  flag=1;
  for(i=0;i<n-1;i++){
    min=i;
    for(j=i+1;j<n;j++){
      if( (int)b[min][1]>(int)b[j][1]) min=j;
    }

    strcpy(kari,b[i]);
    strcpy(b[i],b[min]);
    strcpy(b[min],kari);
  }

  /* 安定かのチェック+出力 */
  for(i=0;i<n;i++){
    printf("%s",b[i]);
    if(i!=n-1) printf(" ");
    
    if(strcmp(a[i],b[i]) ) flag=0;
	
  }

  if(flag) printf("\nStable\n");
  else printf("\nNot stable\n");
      
  return 0;
}
  

