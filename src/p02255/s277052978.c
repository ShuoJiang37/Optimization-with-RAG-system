#include <stdio.h>


int main(){
    int N,i,j,num[1001],v,x;
    
    scanf("%d",&N);
    for (i=0; i<N; i++) {
        scanf("%d",&num[i]);
    }
    
    for (i=1; i<N; i++) {
        for (x=0; x<N-1;x++) {
          printf("%d ",num[x]);
        }
         printf("%d\n",num[N-1]);
        v=num[i];
        j=i-1;
        while (j>=0 && num[j]>v) {
            num[j+1]=num[j];
            j--;
        }
        
        num[j+1]=v;

    }
    for (x=0; x<N-1;x++) {
      printf("%d ",num[x]);
    }
    printf("%d\n",num[N-1]);
    
    return(0);
}

