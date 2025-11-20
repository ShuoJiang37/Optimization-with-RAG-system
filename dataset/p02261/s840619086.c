#include<stdio.h>                                                                                   
#define N 36                                                                                        
typedef struct{                                                                                     
  char c;                                                                                           
  int num;                                                                                          
}toranp;                                                                                            
int isStable(toranp *,toranp *,int);                                                                
                                                                                                    
int main(){                                                                                         
  int n,i,j,l=1,a,b;                                                                                
  toranp t[N],t1[N],t2[N],v;                                                                        
                                                                                                    
  scanf("%d ",&n);                                                                                  
                                                                                                    
  for(i=0;i<n-1;i++)scanf("%c%d ",&t[i].c,&t[i].num);                                               
  scanf("%c%d",&t[n-1].c,&t[n-1].num);                                                              
                                                                                                    
                                                                                                    
  for(i=0;i<n;i++){                                                                                 
    t1[i]=t[i];                                                                                     
    t2[i]=t[i];                                                                                     
  }                                                                                                 
  i=0;                                                                                              
  while(l){                                                                                         
    l=0;                                                                                            
    for(j=1;j<n;j++){                                                                               
      if(t1[j].num<t1[j-1].num){                                                                    
        v=t1[j];                                                                                    
        t1[j]=t1[j-1];                                                                              
        t1[j-1]=v;                                                                                  
        l++;                                                                                        
        i++;                                                                                        
      }                                                                                             
    }                                                                                               
  }                                                                                                 
                                                                                                    
  for(i=0;i<n;i++){                                                                                 
    l=i;                                                                                            
    for(j=i;j<n;j++){                                                                               
      if(t2[j].num<t2[l].num)l=j;                                                                   
    }                                                                                               
    v=t2[i];                                                                                        
    t2[i]=t2[l];                                                                                    
    t2[l]=v;                                                                                        
  }                                                                                                 
                                                                                                    
                                                                                                    
  for(i=0;i<n-1;i++)printf("%c%d ",t1[i].c,t1[i].num);                                              
  printf("%c%d\n",t1[n-1].c,t1[n-1].num);                                                           
  printf("Stable\n");                                                                               
                                                                                                                       
  for(i=0;i<n-1;i++)printf("%c%d ",t2[i].c,t2[i].num);                                              
  printf("%c%d\n",t2[n-1].c,t2[n-1].num);                                                           
  if(isStable(t1,t2,n)==1)printf("Stable\n");                                                       
  else printf("Not stable\n");                                                                      
                                                                                                    
  return 0;                                                                                         
}                                                                                                   
                                                                                                    
int isStable(toranp * t,toranp *t1,int n){                                                          
                                                                                                    
  int i;                                                                                      
                                                                                                    
  for(i=0;i<n;i++){     
        if(t[i].c!=t1[i].c)return 0;                                                                    
  }                                                                                                 
  return 1;                                                                                         
}     
