#include <stdio.h>
#include <string.h>

int main(void){
    int n=0;
    scanf("%d",&n);
    int i;
    int j;
    int m=0;
    int num=0;
    int f=1;
    char a[50][50];
    char b[50][50];
    char c[50];
    for(i=0;i<n;i++){
        scanf("%s",a[i]);
        strcpy(b[i],a[i]);
    }
    int k;
    int l;
    for(k=0;k<n-1;k++){
        for(l=0;l<n-k-1;l++){
            if(a[l][1]>a[l+1][1]){
                strcpy(c,a[l]);
                strcpy(a[l],a[l+1]);
                strcpy(a[l+1],c);
            }
        }
    }

    for(i=0;i<n;i++){
      if(i!=n-1){printf("%s ",a[i]);}
              else{
            printf("%s\n",a[i]);
        }
    }
    printf("Stable\n");

    for(i=0;i<n-1;i++){
        m = b[i][1];
        num = i;
        for(j=i+1;j<n;j++){
            if(m>b[j][1]){
                m = b[j][1];
                num = j;
            }
        }
        if(num!=i){
            strcpy(c,b[i]);
            strcpy(b[i],b[num]);
            strcpy(b[num],c);
        }
    }
    for(i=0;i<n;i++){
      if(i!=n-1){printf("%s ",b[i]);}
      else{printf("%s\n",b[i]);}

    }
    int d=0;
    for(d=0;d<n;d++){
        if(strcmp(a[d],b[d])!=0){
            printf("Not stable\n");
            f = 2;
            break;
        }
    }
    if(f==1){
        printf("Stable\n");
    }

    return 0;
}

