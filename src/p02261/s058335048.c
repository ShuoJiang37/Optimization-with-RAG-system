#include <stdio.h>
#include <string.h>
    void bubbleSort(char a[][3],int n);
    void selectSort(char a[][3],int n);
 
    void sw(char a[],char b[]);
 
    char A[200][3];
    char B[200][3];
 
int main()
{
 
    int n ;
    scanf("%d",&n);
    for(int i= 0;i<n;i++){
        scanf("%s",A[i]);
        strcpy(B[i],A[i]);
    }
 
 
    for(int i= 0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(A[j][1] < A[j-1][1]){
                sw(A[j],A[j-1]);
            }
        }
    }
 
    for(int i = 0;i<n-1;i++){
        int ss = i;
        for(int j=i+1;j<n;j++){
            if(B[j][1]<B[ss][1]){
                ss = j;
            }
        }
        if(ss != i){
            sw(B[ss],B[i]);
        }
    }
 
 
 
 
        for(int i= 0;i<n;i++){
            printf("%s%s",A[i],(i == n-1)? "\n": " ");
            //if(i == n-1) printf("\n");
        }
        printf("Stable\n");
 
        for(int i= 0;i<n;i++){
            printf("%s%s",B[i],(i == n-1)? "\n": " ");
            //if(i == n-1) printf("\n");
        }
 
        int stable = 1;
        for(int i= 0;i<n;i++){
            if(strcmp(A[i],B[i])){
                stable = 0;
            }
        }
        printf("%s\n",stable?"Stable":"Not stable");
 
    return 0;
}
 
    void sw(char a[],char b[]){
        char tmp[3] = "";
        strcpy(tmp,a);
        strcpy(a,b);
        strcpy(b,tmp);
    }
 
 
    void selectSort(char a[][3],int n){
 
    }

