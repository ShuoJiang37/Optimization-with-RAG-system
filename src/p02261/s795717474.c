#include<stdio.h>
#define N 36
int main (){
  char T1[N],T2[N];
  int F1[N],F2[N];
  int n,i,j,f,minj,flag=0;
  char t,k;
  scanf("%d%c",&n,&k);
  for(i=0;i<n;i++){
    if(i!=n-1) scanf("%c%d ",&T1[i],&F1[i]);
    else scanf("%c%d",&T1[i],&F1[i]);
    T2[i]=T1[i];
    F2[i]=F1[i];
  }
  
  

  for(i=0;i<n;i++){
    for(j=n-1;j>0;j--){
      if(F1[j]<F1[j-1]){
	f=F1[j-1];
	F1[j-1]=F1[j];
	F1[j]=f;
	t=T1[j-1];
	T1[j-1]=T1[j];
	T1[j]=t;
      }
	}
  }
 for(i=0;i<n-1;i++) printf("%c%d ",T1[i],F1[i]);
  printf("%c%d\n",T1[n-1],F1[n-1]);
  printf("Stable\n");

  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(F2[j]<F2[minj]) minj = j;
    }
    f=F2[i];
    F2[i]=F2[minj];
    F2[minj]=f;
    t=T2[i];
    T2[i]=T2[minj];
    T2[minj]=t;
  }
  for(i=0;i<n-1;i++) {
    printf("%c%d ",T2[i],F2[i]);
    if(T2[i]!=T1[i]) flag=1;
  }
  printf("%c%d\n",T2[n-1],F2[n-1]);
  if(flag==1) printf("Not stable\n");
  else printf("Stable\n");
  
  
  return 0;
}

