#include<stdio.h>

typedef struct{

  char alf;
  int num;
 
}Roll;

int isStable(Roll  A[],Roll B[],int N){
  
  int i,j,a,b;

  // printf("%d\n", N);
  for(i=0;i<N;i++){

    // printf("%d %d\n",A[i].num,B[i].num);
    
    for(j=i+1;j<N;j++){
      for(a=0;a<N;a++){
	for(b=a+1;b<N;b++){
	  if(A[i].num==A[j].num&&A[i].alf==B[b].alf&&A[j].alf==B[a].alf&&A[i].num==B[b].num&&A[j].num==B[a].num) {
	    //printf("%d %d %d %d\n", i, j, a, b);
	    return 0;
	  }
	}
      }
    }
  }


  return 1;

}


int main( ){

  int N,i,j,minj,w;
  Roll C[36],D[36],c;

  scanf("%d%*c",&N);

  for(i=0;i<N;i++){

    scanf("%c%d%*c",&C[i].alf,&C[i].num);

    D[i]= C[i];

  }

  //Bubble
  
  for(i=0;i<N;i++){
    for(j=N-1;i<j;j--){

      if(C[j].num<C[j-1].num){

        c.num=C[j].num;
	c.alf=C[j].alf;
	C[j].num=C[j-1].num;
	C[j].alf=C[j-1].alf;
       	C[j-1].num=c.num;
	C[j-1].alf=c.alf;

      }
    }
  }


  for(i=0;i<N;i++){

    if(i==N-1)printf("%c%d\n",C[i].alf,C[i].num);
    else printf("%c%d ",C[i].alf,C[i].num);

  }

  
  w=isStable(D,C,N);

  if(w==0) printf("Not stable\n");
  else printf("Stable\n");
  

  for(i=0;i<N;i++){
  
    C[i]=D[i];
  }

 

  
  //SelectionSort

  for(i=0;i<N;i++){

    minj=i;

    for(j=i;j<N;j++){

      if(C[j].num<C[minj].num) minj=j;
    }


    //if(minj != i){
    //printf("minj=%d\n",minj);
    c=C[i];
    C[i]=C[minj];
    C[minj]=c;
    //}

    
    //for(k=0;k<N;k++){
    // printf("%c%d ",C[k].alf,C[k].num);
    // }
    // printf("\n");
    
    
    
  }

 
   
  for(i=0;i<N;i++){

    if(i==N-1)printf("%c%d\n",C[i].alf,C[i].num);
    else printf("%c%d ",C[i].alf,C[i].num);

  }

  
  w=isStable(D,C,N);

  if(w==0) printf("Not stable\n");
  else printf("Stable\n");
  
  

  return 0;
}