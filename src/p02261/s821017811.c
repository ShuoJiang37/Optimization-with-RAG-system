#include<stdio.h>
#include<string.h>
 
int main()
{
 
  int i,j,minj,n,flag=1,cmp,hantei=0;
  char b[36][3],s[36][3],sw[36][3];
   
 
  /*??\???*/
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
 
    scanf("%s",b[i]);
 
    strcpy(s[i],b[i]);
     
      }
   
  i=0;
  while(flag){
    flag = 0;
for (j = n - 1; j >= i+1; j--) {
      if (b[j - 1][1] > b[j][1]) { 
    strcpy(sw[j],b[j]);        
    strcpy( b[j],b[j - 1]);
    strcpy( b[j - 1],sw[j]);
    flag = 1;
      }
 }
    i++;
  }
   
 
  for(i=0;i<n;i++){
 
    minj = i;
 
    for(j=i;j<n;j++){
      if(s[j][1] < s[minj][1]){
    minj = j;
      }
    }
    if(i != minj){
    
    strcpy(sw[i] ,s[i]);
    strcpy(s[i],s[minj]);
    strcpy(s[minj],sw[i]);
    }
  }
 
  /*BS??????*/
  for(i=0;i<n-1;i++){
 
    printf("%s ",b[i]);
  }
    printf("%s",b[i]);
   
 
  printf("\n");
  printf("Stable\n");
  /*SS??????*/
  for(j=0;j<n-1;j++){
 
    printf("%s ",s[j]);
 
  }
  printf("%s",s[j]);
  printf("\n");
  flag = 1;
  for(i=0;i<n;i++){
 
 
    if(strcmp(&b[i][0],&s[i][0])!=0 && hantei==0){
      printf("Not stable\n");
      flag=0;
      hantei++;
    }
  }
  if(flag==1){
    printf("Stable\n");
  }
 return 0;
}