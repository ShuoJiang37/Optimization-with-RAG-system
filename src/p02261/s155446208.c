#include <stdio.h>
#include <stdbool.h>
struct card{char suit, value;} ;
void bubblesort(struct card a[],int n){
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=i;j--){
            if(a[j].value<a[j-1].value){
               struct card t=a[j];a[j]=a[j-1];a[j-1]=t;
            }
        }
    }
}
void selection(struct card a[],int n){
    for(int i=0;i<n;i++){
        int minj=i;
        for(int j=i;j<n;j++){
            if(a[j].value<a[minj].value)
                minj=j;
    }
        struct card t=a[i];a[i]=a[minj];a[minj]=t;
}
}
void print(struct card a[],int n){
    for(int i=0;i<n;i++){
        if(i>0)printf(" ");
        printf("%c%c",a[i].suit,a[i].value);
    }
    printf("\n");
}

bool isstable(struct card c1[],struct card c2[],int n){
    for(int i=0;i<n;i++)
        if(c1[i].suit!=c2[i].suit)
            return false;
    return true;
}

int main(){
    struct card c1[100],c2[100];
    int n;
    int i;
    char copy,copy2;
   
    scanf("%d\n",&n);
  
    for(i=0;i<n;i++){
        scanf(" %c%c",&copy,&copy2);
        c1[i].suit=copy;
        c1[i].value=copy2;
       
    }
    for(i=0;i<n;i++)
        c2[i]=c1[i];
    bubblesort(c1,n);
    selection(c2,n);
    
    print(c1,n);
    printf("Stable\n");
    print(c2,n);
    if(isstable(c1,c2,n))
        printf("Stable\n");
    else
        printf("Not stable\n");
  
    }
       
        
    
