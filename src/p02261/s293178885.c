#include<stdio.h>
#define N 36

typedef struct{
  
  char suit;
  int number;
  
}Card;

main(){
  int i,j,n,mini;
  Card b[N],s[N],a1,a2;
  char S[3];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%s",&S);
    b[i].suit=S[0];
    b[i].number=S[1]-'0';
    //    scanf("%c&d",&b[i].suit,&b[i].number);
  }
  for(i=0;i<n;i++){
    s[i]=b[i];
  }

  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(b[j].number<b[j-1].number){
	a1=b[j];
	a2=b[j-1];
	b[j]=a2;
	b[j-1]=a1;
      }
    }
  }

  for(i=0;i<n;i++){
    mini=i;
    for(j=i+1;j<=n-1;j++){
      if(s[j].number<s[mini].number){
	mini=j;
      }
    }
    a1=s[i];
    a2=s[mini];
    s[i]=a2;
    s[mini]=a1;
  }

  for(i=0;i<n-1;i++){
    printf("%c%d ",b[i].suit,b[i].number);
  }
  printf("%c%d\n",b[n-1].suit,b[n-1].number);
  printf("Stable\n");

  for(i=0;i<n-1;i++){
    printf("%c%d ",s[i].suit,s[i].number);
  }
  printf("%c%d\n",s[n-1].suit,s[n-1].number);
  
  int flag=0;
  for(i=0;i<=n-1;i++){
    if(b[i].suit!=s[i].suit){
      flag=1;
    }
  }

  if(flag==1) printf("Not stable\n");
  else printf("Stable\n");

  return 0;
}