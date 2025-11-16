#include<stdio.h>

main(){
int arr[100],N;
int i,sw;

scanf("%d",&N);
for(i=0;i<N;i++)scanf("%d",&arr[i]);

sw=Sort(arr,N);

for(i=0;i<N;i++){
if(i>0)printf(" ");
printf("%d",arr[i]);
}
printf("\n");
printf("%d\n",sw);

return 0;
}

int Sort(int arr[],int N){
int i,j;
int k,sw=0;
int minj;

for(i=0;i<N-1;i++){
minj=i;
for(j=i;j<N;j++){
if(arr[j]<arr[minj])minj=j;
}
k=arr[i];
arr[i]=arr[minj];
arr[minj]=k;
if(i!=minj)sw++;
}
return sw;
}