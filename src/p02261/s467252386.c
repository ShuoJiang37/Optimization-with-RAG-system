#include<stdio.h>
struct card
{  char suit,value;
};
void bubble(struct card c[],int n)//默认冒泡排序为稳定排序 
{  int i,j,t,flag;
   flag=1;
   j=0;
   while(flag)
   {  flag=0;
      for(i=n-1;i>0;i--)
        if(c[i].value<c[i-1].value) //不符合条件的两两交换 直到所有的都满足条件使flag不等于1 
         {  t=c[i].value;
            c[i].value=c[i-1].value;
            c[i-1].value=t;
            t=c[i].suit;
            c[i].suit=c[i-1].suit;
            c[i-1].suit=t;
            j++;
            flag=1;
         }
   }
}
void selection(struct card c[],int n) 
{  int i,t,j,k=0,minnumber;
   for(i=0;i<n;i++)
   {  minnumber=i;
      for(j=i;j<n;j++)
      if(c[j].value<c[minnumber].value)  minnumber=j;//找出未排序的最小值序号 
      if(minnumber!=i)
	  {  t=c[i].value;
         c[i].value=c[minnumber].value;
         c[minnumber].value=t;
         t=c[i].suit;
         c[i].suit=c[minnumber].suit;
         c[minnumber].suit=t;
         k++;
      }
   }
}
int isstable(struct card c1[],struct card c2[],int n)//以冒泡排序为参照判断相应的排序方法是否稳定 
{  int i,t;
   for(i=0;i<n;i++)
     if(c1[i].suit!=c2[i].suit)  
	 {  t=1;
	    break;
	 }
	 else t=0;
	 return t;
}
int main()
{  int i,n,t;
   struct card c1[100],c2[100];
   scanf("%d",&n);
   for(i=0;i<n;i++)
     scanf(" %c%c",&c1[i].suit,&c1[i].value);
   for(i=0;i<n;i++)
     c2[i]=c1[i];
   bubble(c1,n);
   for(i=0;i<n;i++)
   {  if(i>0)  printf(" ");
      printf("%c%c",c1[i].suit,c1[i].value);
   }
   printf("\n");
   printf("Stable\n");
   selection(c2,n);
   for(i=0;i<n;i++)
   {  if(i>0)  printf(" ");
      printf("%c%c",c2[i].suit,c2[i].value);
   }
   printf("\n");
   if(isstable(c1,c2,n))   printf("Not stable\n"); else printf("Stable\n");
}
