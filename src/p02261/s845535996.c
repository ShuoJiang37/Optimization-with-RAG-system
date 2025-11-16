#include <stdio.h>
#include <stdio.h>

int main(){
  char aaa[37], tc, a2[37];
  int n, i, j, bbb[37], b2[37], tn, flag=0, min, k;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c",&aaa[i]);
    scanf(" %c",&tc);
    bbb[i] = tc-'0';
  }

  for(i=0;i<n;i++){
    a2[i]=aaa[i];
    b2[i]=bbb[i];
  }

  for(i=0;i<n;i++){
    for(j=n-1;i<j;j--){
      if(bbb[j-1]>bbb[j]){
	tn=bbb[j-1];
	bbb[j-1]=bbb[j];
	bbb[j]=tn;
	tc=aaa[j-1];
	aaa[j-1]=aaa[j];
	aaa[j]=tc;
      }
    }
  }

  for(i=0;i<n-1;i++){
    printf("%c%d ",aaa[i],bbb[i]);
  }
  printf("%c%d\nStable\n",aaa[n-1],bbb[n-1]);

  for(i=0;i<n;i++){
    min=10;
    for(j=i;j<n;j++){
      if(b2[j]<min){
	min=b2[j];
	k=j;
      }
    }
    if(k!=i){
      tn=b2[k];
      b2[k]=b2[i];
      b2[i]=tn;
      tc=a2[k];
      a2[k]=a2[i];
      a2[i]=tc;
    }
  }
  for(i=0;i<n-1;i++){
    printf("%c%d ",a2[i],b2[i]);
  }
  printf("%c%d\n",a2[n-1],b2[n-1]);
  for(i=0;i<n;i++){
    if(aaa[i]!=a2[i]){
      flag=1;
      break;
    }
  }
  if(flag==0)printf("Stable\n");
  else if(flag==1) printf("Not stable\n");

  return 0;
}

