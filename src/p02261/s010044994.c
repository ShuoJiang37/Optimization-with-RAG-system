#include<stdio.h>
typedef struct{
  char M[36];
  int F[36];
}pre;
int main(){
  int i,j,N,s,mini;
  char c;
  pre inp,oup1,oup2;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf(" %c%d",&c,&s);
    inp.M[i]=c;
    inp.F[i]=s;
  }
  oup1=inp;
  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(oup1.F[j]<oup1.F[j-1]){
        c=oup1.M[j];
        oup1.M[j]=oup1.M[j-1];
        oup1.M[j-1]=c;

        s=oup1.F[j];
        oup1.F[j]=oup1.F[j-1];
        oup1.F[j-1]=s;
      }
    }
  }

  for(j=0;j<N;j++)if(j!=N-1)printf("%c%d ",oup1.M[j],oup1.F[j]);else printf("%c%d\n",oup1.M[j],oup1.F[j]);
  printf("Stable\n");

  oup2=inp;
  for(i=0;i<N;i++){
    mini=i;
    for(j=i;j<N;j++){
      if(oup2.F[j] < oup2.F[mini]){
	mini=j;
      }
    }
    s=oup2.F[i];
      oup2.F[i]=oup2.F[mini];
      oup2.F[mini]=s;

      c=oup2.M[i];
      oup2.M[i]=oup2.M[mini];
      oup2.M[mini]=c;
  }

    for(j=0;j<N;j++)if(j!=N-1)printf("%c%d ",oup2.M[j],oup2.F[j]);else printf("%c%d\n",oup2.M[j],oup2.F[j]);
    
    for(i=0;i<N;i++)if(oup1.M[i]!=oup2.M[i])goto NS;
    
    printf("Stable\n");
    goto S;
 NS:
    printf("Not stable\n");
 S:
    
  return 0;
}

