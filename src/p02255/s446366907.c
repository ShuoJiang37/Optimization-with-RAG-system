#include <stdio.h>
int main()
{
  int i, j, k, work, N, A[1005];
  /* i,j,k are variables for loop count
     work is variable for save number
     N is variable for the length of series A
     A is array for save each elements needs for this program
  */

  scanf("%d", &N);
  //input for the length of series A

  for(i=0;i<N;i++){
    scanf("%d", &A[i]);
  }
  //input for each elements

  
  for(i=1;i<=N;i++){

    for(k=0; k<N; k++){
      printf("%d",A[k]);
      if(k<N-1) printf(" ");
    }
    printf("\n");
    //output every each step

    work=A[i];   
    j=i-1; 
    
    while(j>=0 && A[j]>work){
      A[j+1]=A[j];
      j--;
    }
    /*when j andover 0 and A[j] bigger than work,
      excange two elements*/

    A[j+1]=work;
  }
  return 0;
}