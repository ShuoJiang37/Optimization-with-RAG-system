#include<stdio.h>
#include<string.h>

void swap(char x[], char y[]){
	char tmp[3];
	strcpy(tmp,x);
	strcpy(x,y);
	strcpy(y,tmp);
}

void bubbleSort(char a[][3], int n){
  int i,j;

  for(i=0; i<n; i++){
    for(j=n-1; j>i; j--){
      if(a[j][1]<a[j-1][1]){
        swap(a[j],a[j-1]);
      }
    }
  }
  for(i = 0; i<n-1; i++){
    printf("%s ",a[i]);
  }
  printf("%s\n",a[n-1]);
}



void selectionSort(char a[][3], int n){

  int i,j,minj;

  for(i=0; i<n; i++){
    minj = i;
    for(j=i+1; j<n; j++){
      if(a[j][1]<a[minj][1]){
        minj=j;
      }
    }
    if(a[i]!=a[minj]){
      swap(a[i],a[minj]);
    }
  }
  for(i=0; i<n-1; i++){
    printf("%s ",a[i]);
  }
  printf("%s\n",a[n-1]);


}


int main(void){
  int i,n;

  scanf("%d",&n);

  char a[n][3];
  char b[n][3];



  for(i = 0; i<n; i++){
    scanf("%s",&a[i]);
  	strcpy(b[i],a[i]);
  }

 	bubbleSort(a,n);
	printf("Stable\n");

	int k=0;
	selectionSort(b,n);
	for(i=0; i<n; i++){
		if(strcmp(a[i],b[i])==0){
			k=0;
		}else{
			k=1;
			break;
		}
	}
	if(k==0){
		printf("Stable\n");
	}
	if(k==1){
		printf("Not stable\n");
	}

  return 0;
}

