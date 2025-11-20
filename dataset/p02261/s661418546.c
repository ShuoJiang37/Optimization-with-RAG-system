#include<stdio.h>
#include<string.h>
#include<stdlib.h>
static const int N = 36;

int isStable(char [N][3],char [N][3]);
int n;

int main(){
  int i,j,a,b,stable[2];
  char A[N][3];
  char B[N][3];
  char C[N][3];
  char swap[3];
  int minj;

  scanf("%d",&n); /*Input an integer n, the number of elements in sequence*/

  for(i=0;i<n;i++){
    scanf("%s",A[i]);/* Input N elements of the sequence*/
  }
  for(i=0;i<n;i++){
    strcpy(B[i],A[i]);
    strcpy(C[i],A[i]);
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(B[j][1]<B[j-1][1]){
	strcpy(swap,B[j]);
        strcpy(B[j],B[j-1]);
        strcpy(B[j-1],swap);
      }
     }
    }
  for(i=0;i<n;i++){
      if(i<n-1) printf("%s ",B[i]);/*Output the sorted sequence*/
      else printf("%s\n",B[i]);
    }
  
  stable[0]=isStable(A,B);
  if(stable[0]==1) printf("Not stable\n");
  else printf("Stable\n");

  for(i=0;i<n;i++){
      minj = i;
     for(j=i;j<n;j++){
       if(C[j][1]<C[minj][1])
	minj = j;
     }
     if(i!=minj){
        strcpy(swap,C[i]);
        strcpy(C[i],C[minj]);
        strcpy(C[minj],swap);
       }
      }
    for(i=0;i<n;i++){
      if(i<n-1) printf("%s ",C[i]);/*Output the sorted sequence*/
      else printf("%s\n",C[i]);
    }
     stable[1]=isStable(A,C);
     if(stable[1]==1) printf("Not stable\n");
     else printf("Stable\n");

    return 0;
   } 

int isStable(char in[N][3], char out[N][3]){
  int i,j,a,b;
   for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      for(a=0;a<n;a++){
	for(b=a+1;b<n;b++){
	  if((in[i][1]== in[j][1]) && (strcmp(in[i],out[b])==0)&& (strcmp(in[j],out[a])==0)) return 1;
          
	}
       }
      }
     }
      return 0;
}