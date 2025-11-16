#include <stdio.h>
int bubbleSort(int a[],int n,char c[]){
    int flag =1,i,tmp,ct =0;
    char tmpc;
    while(flag ==1){
        flag = 0;
        for(i = n-1;i>0;i--){
            if(a[i] < a[i-1]){
                tmp = a[i];
                a[i] = a[i-1];
                a[i-1] = tmp;
                tmpc = c[i];
                c[i] = c[i-1];
                c[i-1] = tmpc;
                flag = 1;
                ct++;
            }
        }
    }
    return ct;
}
int selectionSort(int a[],int n,char c[]){
    int ct=0,i,j,min_index,tmp;
    char tmpc;
    for(i = 0;i<n-1;i++){
        min_index = i;
        for(j =i;j<n;j++){
            if(a[min_index]>a[j]){
                min_index = j;
            }
        }
        if(i != min_index){
        tmp = a[i];
        a[i] = a[min_index];
        a[min_index]=tmp;
        tmpc = c[i];
        c[i] = c[min_index];
        c[min_index] = tmpc;
        ct++;
        }
    }
    return ct;
}
int stable_or_not(char c[],char cc[],int a[],int aa[],int num){
    int i,j,k,l;
    for(i = 0;i<num;i++){
        for(j=i+1;j<num;j++){
            if(a[i]==a[j]){
                for(k=0;k<num;k++){
                    for(l = k+1;l<num;l++){
                        if(a[i]==aa[k] && c[i]==cc[l] && a[j]==aa[l] && c[j] ==cc[k]){
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 1;
}
void display(char c[],int a[],int n){
    int i ;
    for(i=0;i<n-1;i++){
        printf("%c%d ",c[i],a[i]);
    }
    printf("%c%d\n",c[n-1],a[n-1]);
}
int main(){
    int a[36],aa[36];
    char c[36],cc[36];
    int n,i,ct;
    scanf("%d",&n);
    getchar();
    for(i = 0;i<n;i++){
        scanf(" %c%d",&c[i],&a[i]);
    }
    for(i=0;i<n;i++){
        aa[i]=a[i];
        cc[i]=c[i];
    }
    bubbleSort(aa,n,cc);
    display(cc,aa,n);
    if(stable_or_not(c,cc,a,aa,n)==0){
        printf("Not stable\n");
    }else{
        printf("Stable\n");
    }
    for(i=0;i<n;i++){
        aa[i]=a[i];
        cc[i]=c[i];
    }
    selectionSort(aa,n,cc);
    display(cc,aa,n);
    if(stable_or_not(c,cc,a,aa,n)==0){
        printf("Not stable\n");
    }else{
        printf("Stable\n");
    }
    
    return 0;
}
