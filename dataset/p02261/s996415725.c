#include<stdio.h>
#include<string.h>
#define N 36

typedef struct{
    char c;
    int value;
}sort;


int main()
{
  int i,j,n,flag=0,minj;
  sort C1[N],C2[N],a;
  char emp;
    
  scanf("%d\n",&n);
  for(i=0;i<n;i++){
      scanf("%c%d%c",&C1[i].c, &C1[i].value,&emp);
      C2[i]=C1[i];
}
    
    
//bubble sort
    for(i=0;i<n;i++){
        for(j=n-1;j>i;j--){
             if(C1[j].value < C1[j-1].value){
               a=C1[j];
             C1[j] = C1[j-1];
            C1[j-1] =a;
             
            }
        }
    }
// bubble fin

    
//selection sort
    for(i=0;i<n;i++){
        minj=i;
        for(j=i;j<n;j++){
            if(C2[j].value <C2[minj].value ) minj=j;
        }
        if(minj != j){
                a=C2[i];
                C2[i]=C2[minj];
                C2[minj]=a;
        }
        }
  // selection fin
    
    
    for(j=0;j<n-1;j++){
        printf("%c%d ",C1[j].c,C1[j].value);
    }
    printf("%c%d\n",C1[n-1].c,C1[n-1].value);
    printf("Stable\n");
    
for(j=0;j<n-1;j++){
    printf("%c%d ",C2[j].c,C2[j].value );
    if(C1[j].c!=C2[j].c) flag=1;
}
printf("%c%d\n",C2[n-1].c,C2[n-1].value);
  if(C1[n-1].c!=C2[n-1].c) flag=1;
    
    if(flag==1) printf("Not stable\n");
    else printf("Stable\n");
 
    return 0;
    
}
