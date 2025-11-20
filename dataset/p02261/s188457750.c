#include<stdio.h>

struct tra {
  char name;
  int no;
	
};

void sort2(struct tra *su, int);
void sort(struct tra *su, int);
void ire(int*,int*);
void ire2 (char*,char*);
void s(int*,int*);
void s2 (char*,char*);
int ha(struct tra *su,struct tra *su0,int);

int main(){
  int s=0,i,j;
  struct tra su0[36];
  struct tra su[36];
  struct tra su2[36];
  scanf("%d",&s);  
  for(i=0;i<s;i++){
   
    scanf(" %c%d",&su0[i].name,&su0[i].no);
    su[i].name=su0[i].name;
    su[i].no=su0[i].no;
    su2[i].name=su0[i].name;
    su2[i].no=su0[i].no;
  }
  
  sort(su,s); 
  sort2(su2,s);

  for (i=0; i < s; i++) {
    printf("%c%d",su[i].name,su[i].no);
    if(i!=s-1)printf(" ");
  }
  printf("\n");
  printf("Stable\n");
 
  for (i = 0; i < s; i++){
    printf("%c%d", su2[i].name,su2[i].no);
    if(i!=s-1)printf(" ");}
  printf("\n");

 j= ha(su2,su,s);
 if(j==2)printf("Not stable\n");
 else  printf("Stable\n");

  return 0;
}

void sort (struct tra *su, int size) {
  int i, j;
  
  for (i = 0; i < size - 1; i++){
    for (j = size - 1; j >= i + 1; j--){
      if (su[j].no < su[j-1].no){
	ire(&su[j].no,&su[j-1].no);
	ire2(&su[j].name,&su[j-1].name);

      }
    }
  }
}
void ire (int *x, int *y){
  char temp;    
  temp = *x;
  *x = *y;
  *y = temp;
}
void ire2 (char *x, char *y){
  char temp;    
  temp = *x;
  *x = *y;
  *y = temp;
}
void sort2 (struct tra *su, int size) {
  int i, j, in;

  for (i = 0; i < size-1; i++) {
    in = i;   
    for (j = i + 1; j < size; j++) {
      if (su[j].no <su[in].no){in = j; }   
    }
   
    s2(&su[in].name, &su[i].name);
    s(&su[in].no, &su[i].no);
  }
}void s (int *x, int *y){
  char temp;    
  temp = *x;
  *x = *y;
  *y = temp;
}
void s2 (char *x, char *y){
  char temp;    
  temp = *x;
  *x = *y;
  *y = temp;
}
int ha (struct tra *su,struct tra *su0,int s) {
  int i,c=0;
  for(i=0;i<s;i++){

    if(su[i].name != su0[i].name){c=1;}


  }

  if(c==1) return 2;
  else return 1;
  
}

