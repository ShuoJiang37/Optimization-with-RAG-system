#include <stdio.h>

   typedef struct{
       char mark;
       int  num;
   }card;
   
   int main(void)
   {
    int N,i,j,min,x;
    char t;
    card a[36],b[36],change;

    scanf("%d\n",&N);

    for(i=0;i<N-1;i++){
     scanf("%c%d",&a[i].mark,&a[i].num);
     scanf("%c",&t);
    }
    scanf("%c%d",&a[N-1].mark,&a[N-1].num);
    
    for(i=0;i<N;i++)
     b[i]=a[i];

    for(i=0;i<N;i++){
     for(j=N-1;j>i;j--){
      if(a[j].num<a[j-1].num){
        change=a[j];
        a[j]=a[j-1];
        a[j-1]=change;
      }
     }
    }

    for(i=0;i<N-1;i++){
     printf("%c%d ",a[i].mark,a[i].num);
    }
    printf("%c%d\n",a[N-1].mark,a[N-1].num);
    printf("Stable\n");

    for(i=0;i<N;i++){

     min=i;
     for(j=i;j<N;j++){

      if(b[j].num<b[min].num){
       min=j;
      }
     }
     change=b[i];
     b[i]=b[min];
     b[min]=change;
    }

    for(i=0;i<N-1;i++){
     printf("%c%d ",b[i].mark,b[i].num);
    }
    printf("%c%d\n",b[N-1].mark,b[N-1].num);

    x=1;
    for(i=0;i<N;i++){
     if(a[i].mark!=b[i].mark){
      x=0;
     }
    }
     if(x==0){
      printf("Not stable\n");
     }else{
      printf("Stable\n");
     }

    return 0;

   }