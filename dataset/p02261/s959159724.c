#include<stdio.h>

void bubblesort(int,char *,char *);
void selectionsort(int,char *,char *);
void checkstable(int ,char *,char *,char *,char *);
void swap(char *,char *);

int main(){
  int i,n;
  scanf("%d",&n);
  char a[n],b[n],row[n][2],c[n],d[n];
  for(i=0;i<n;i++){
	scanf("%s",row[i]);
	a[i]=row[i][0];
	c[i]=row[i][0];
	b[i]=row[i][1];
	d[i]=row[i][1];
  }
 
  /*
  for(i=0;i<n;i++){
	if(i!=n-1)printf("%c%c ",a[i],b[i]);
	else printf("%c%c\n",a[i],b[i]);
	}*/
 
  bubblesort(n,&a[0],&b[0]);

  for(i=0;i<n;i++){
	if(i!=n-1) printf("%c%c ",a[i],b[i]);
	else printf("%c%c\n",a[i],b[i]);
  }
  printf("Stable\n");
 
  selectionsort(n,&c[0],&d[0]);
  for(i=0;i<n;i++){
	if(i!=n-1) printf("%c%c ",c[i],d[i]);
	else printf("%c%c\n",c[i],d[i]);
  }
  checkstable(n,&a[0],&b[0],&c[0],&d[0]);
  return 0;
}

void bubblesort(int n,char *a,char *b){
  int i,j;
  for(i=0;i<n-1;i++){
	for (j=n-1;j>=i+1;j--){
  	if (b[j] < b[j-1]){
    swap(&a[j],&a[j-1]);
    swap(&b[j],&b[j-1]);
  	}
	}
  }
}

void selectionsort(int n,char *a,char *b){
  int i,j;
  for(i=0;i<n;i++){
	int minj=i;
	for(j=i;j<n;j++){
  	if(b[j]<b[minj]){
    minj=j;
  	}
	}
	if(minj!=i){
  	swap(&a[i],&a[minj]);
  	swap(&b[i],&b[minj]);
	}
  }
}

void checkstable(int n,char *a,char *b,char *c,char *d){
  int i,f=0;
  for(i=0;i<n;i++){
	if(a[i]!=c[i] || b[i]!=d[i])f=1;
  }
  if(f==0)printf("Stable\n");
  else printf("Not stable\n");

}

void swap(char *a,char *b){
  char tmp = *a;
  *a = *b;
  *b = tmp;
}



