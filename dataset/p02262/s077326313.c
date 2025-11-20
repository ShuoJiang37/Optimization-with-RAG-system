#include <stdio.h>
int cnt,m;
int gg[4096];
void insertionSort(int a[],int n,int g){
    int i,v,j;
    for(i=g;i<n;i++){
        v = a[i];
        j = i - g;
        while(j >= 0 && a[j] > v){
            a[j+g] = a[j];
            j = j - g;
            cnt++;
        }
        a[j+g] = v;
    }
}

void shellSort(int a[],int n){
    cnt=0;
    int i,x=1;
	m=0;
    for(i=0;;i++){
        gg[i]=x;
        x = 3*x+1;
        m++;
        if(x>=n){
            break;
        }
    }
    for(i=m-1;i>=0;i--){
        insertionSort(a, n, gg[i]);
    }
}
         
int main(void){
    int a[1000000];
	int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    shellSort(a,n);
    printf("%d\n",m);
    for(i=m-1;i>=0;i--){
        printf("%d",gg[i]);
        if(i!=0){
            printf(" ");
        }
    }
    printf("\n%d\n",cnt);
    for(i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}
