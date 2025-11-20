#include <stdio.h>

#define  N  36

typedef struct{
  char x;
  int y;
}Tru;


  main(){
   
    int i,j,minj,n,z;
    Tru C[N],D[N],tmp1,tmp2;

    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf(" %c%d",&C[i].x,&C[i].y);
      D[i] = C[i];
    }

    for(i=0;i<n-1;i++){
      for(j=n-1;j>i;j--){
        if(C[j].y<C[j-1].y){
          tmp1 =C[j];
	  C[j]=C[j-1];
	  C[j-1]=tmp1;
	}
      }
    }

    for(i=0;i<n-1;i++){
      printf("%c%d ",C[i].x,C[i].y);
    }
    printf("%c%d\n",C[n-1].x,C[n-1].y);
    printf("Stable\n");

    for(i=0;i<n;i++){
      minj = i;
      for(j=i;j<n;j++){
	if(D[j].y<D[minj].y){
	  minj = j;
	}
      }
      if(i!=minj){
	tmp2 =D[i];
	D[i]=D[minj];
	D[minj]=tmp2;
      }
    }

    for(i=0;i<n-1;i++){
      printf("%c%d ",D[i].x,D[i].y);
    }
    printf("%c%d\n",D[n-1].x,D[n-1].y);
    for(i=0;i<n;i++){
      if(C[i].x!=D[i].x){
        z=0;	break;
      }
      else if(C[i].x==D[i].x)   z=1;
    }

    if(z==0)   printf("Not stable\n");
    else if(z==1)  printf("Stable\n");
    return 0;
}