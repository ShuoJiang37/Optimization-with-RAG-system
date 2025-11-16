#include<stdio.h>
int main(){
  char cm[36],sm[36],a,e[3];
  int n,i,j,c,m,d,f=0;
  int cn[36],sn[36];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",e);
    cm[i] = e[0];
    cn[i]  = e[1] - '0';
  }
  for(i=0;i<n;i++){
    sn[i]=cn[i];
    sm[i]=cm[i];
  }

  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(cn[j]<cn[j-1]){
	c=cn[j];
	cn[j]=cn[j-1];
	cn[j-1]=c;
	a=cm[j];
	cm[j]=cm[j-1];
	cm[j-1]=a;
      }
    }
  }
 
  for(i=0;i<n;i++){
    m=i;
    for(j=i;j<n;j++){
      if(sn[j]<sn[m]){
	m=j;
	d=1;
      }
    }
    if(d==1){
      c=sn[i];
      sn[i]=sn[m];
      sn[m]=c;
      a=sm[i];
      sm[i]=sm[m];
      sm[m]=a;
      d=0;
    }
  }
  for(i=0;i<n;i++){
    if(cm[i]!=sm[i]) f=1;
    if(cn[i]!=sn[i]) f=1;
  }

  for(i=0;i<n-1;i++){
    printf("%c%d ",cm[i],cn[i]);
  }
  printf("%c%d\n",cm[n-1],cn[n-1]);
  printf("Stable\n");
   
  
  for(i=0;i<n-1;i++){
    printf("%c%d ",sm[i],sn[i]);
  }
  printf("%c%d\n",sm[n-1],sn[n-1]);
  if(f==1) printf("Not stable\n");
  else printf("Stable\n");
  return 0;

 
}


