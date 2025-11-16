#include<stdio.h>
typedef struct{
  int value;
  char moji;
}card;
 
int main(){
  int i,j,n,minj;
 
  card num[36],suit[36],temp;
  
  scanf("%d",&n);
for(i=0;i<n;i++){
  scanf(" %c%d",&num[i].moji,&num[i].value);
  suit[i].moji = num[i].moji;
 suit[i].value = num[i].value;
  }
 
/*bubble sort */
 for(i=0;i<n;i++){
   for(j = n-1;j>i;j--){
     if(num[j].value < num[j-1].value){
       temp = num[j];
       num[j] = num[j-1];
       num[j-1] = temp;
    }
   }
 }

for(i=0;i<n-1;i++){
   printf("%c%d ",num[i].moji,num[i].value);
 }
 printf("%c%d\nStable\n",num[i].moji,num[i].value);

/* selection sort */

 for(i=0;i<n-1;i++){
   minj = i;
   for(j=i;j<=n-1;j++){
     if(suit[j].value < suit[minj].value) minj = j;
   }
     temp = suit[i];
     suit[i]=suit[minj];
     suit[minj]=temp;
 }

 for(i=0;i<n-1;i++){
   printf("%c%d ",suit[i].moji,suit[i].value);
 }
 printf("%c%d\n",suit[i].moji,suit[i].value);
 
 for(i=0;i<n;i++){
   if(suit[i].moji != num[i].moji) {
    printf("Not stable\n");
     break;}
 }
 if(i == n)printf("Stable\n");
  return 0;
}