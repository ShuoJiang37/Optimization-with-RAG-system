#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
  int i,j,minj,barray[37],sarray[37],n,box,flg;
  char bcarray[37][3],scarray[37][3],cbox;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",bcarray[i]);
    scarray[i][0] = bcarray[i][0];
    scarray[i][1] = bcarray[i][1];
    
    barray[i] = atoi(&bcarray[i][1]);
    sarray[i] = atoi(&scarray[i][1]);
  }
  
 

/*bubble sort*/

  
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(barray[j] < barray[j-1]){
	box = barray[j];
	barray[j] = barray[j-1];
	barray[j-1] = box;
	cbox = bcarray[j][0];
	bcarray[j][0] = bcarray[j-1][0];
	bcarray[j-1][0] = cbox;
	cbox = bcarray[j][1];
	bcarray[j][1] = bcarray[j-1][1];
	bcarray[j-1][1] = cbox;
      }
    }
  }
  for(i=0;i<n;i++){ 
   for(j=0;j<2;j++){ 
     printf("%c",bcarray[i][j]);
   }
    if( i == n-1) printf("\n");
    else printf(" ");
  }
  printf("Stable\n");
  
  /* selection sort*/
  
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++) if(sarray[j] < sarray[minj]) minj =j;
    if(i != minj){
      box = sarray[i];
      sarray[i] = sarray[minj];
      sarray[minj] = box;
      cbox = scarray[i][0];
      scarray[i][0] = scarray[minj][0];
      scarray[minj][0] = cbox; 
      cbox = scarray[i][1];
      scarray[i][1] = scarray[minj][1];
      scarray[minj][1] = cbox; 
    }
  }
  flg=0;
  for(i=0;i<n;i++){
    for(j=0;j<2;j++){ 
     printf("%c",scarray[i][j]);
    }
    if( i == n-1) printf("\n");
    else printf(" ");
    if(scarray[i][0] != bcarray[i][0] || scarray[i][1] != bcarray[i][1]) flg=1; 
  }
  
  if(flg == 0)  printf("Stable\n");
  else  printf("Not stable\n"); 
  return 0;
}