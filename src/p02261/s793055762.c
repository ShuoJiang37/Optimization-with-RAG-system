#include<stdio.h>
#include<string.h>
#define N 36

typedef struct
{
  char pat;
  int value;
}card;


int main()
{
  int i,j,n,mini,a,b,jud;
  card C[N],A[N],B[N],temp;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf(" %c%d",&C[i].pat,&C[i].value);
      A[i] = B[i] = C[i];
    }

  for(i=0;i<n;i++)               //Bubble
    {    
      for(j=n-1;j>=i+1;j--)
	{     
	  if(A[j].value < A[j-1].value)
	    {
	      temp = A[j];
	      A[j] = A[j-1];
	      A[j-1] = temp;
	    }
	}
    }
  

   for(i=0;i<n;i++)
    {
      printf("%c%d",A[i].pat,A[i].value);
      if(i!=n-1)printf(" ");
      else printf("\n");
    }

      jud=0;
   for(i=0;i<n;i++)
     {
       for(j=i+1;j<n;j++)
	 {
	   for(a=0;a<n;a++)
	     {
	       for(b=a+1;b<n;b++)
		 {
		   if(A[i].value==A[j].value && (A[i].value==C[b].value && A[i].pat==C[b].pat) && (A[j].value==C[a].value && A[j].pat== C[a].pat))jud=1;
		 }
	     }
	 }
     }
   if(jud == 0)printf("Stable\n");
   else printf("Not stable\n");


  for(i=0;i<n;i++)               //Selection
    {
      mini = i;
      for(j=i;j<n;j++)
	{
	  if(B[j].value < B[mini].value)
	    {
	      mini = j;
	    }
	}
      temp = B[i];
      B[i] = B[mini];
      B[mini] = temp;
    }
  
    for(i=0;i<n;i++)
    {
      printf("%c%d",B[i].pat,B[i].value);
      if(i!=n-1)printf(" ");
      else printf("\n");
    }

        jud=0;
   for(i=0;i<n;i++)
     {
       for(j=i+1;j<n;j++)
	 {
	   for(a=0;a<n;a++)
	     {
	       for(b=a+1;b<n;b++)
		 {
		   if(B[i].value == B[j].value &&( B[i].value == C[b].value && B[i].pat == C[b].pat )&& (B[j].value == C[a].value &&B[j].pat==C[a].pat))jud=1;
		 }
	     }
	 }
     }
   if(jud == 0)printf("Stable\n");
   else printf("Not stable\n");


   
  return 0;
}








