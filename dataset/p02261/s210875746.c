#include <stdio.h>

void selection_sort(int *a, int *a_str, int n) {
    int i, j, tmp1, tmp2, mini;

    for (i=0;i<n;i++) {
        mini=i;
        for (j=i;j<n;j++) {
            if (a[j]<a[mini]) {
                mini=j;
            }
        }
        tmp1=a[i];
        a[i]=a[mini];
        a[mini]=tmp1;
        tmp2=a_str[i];
        a_str[i]=a_str[mini];
        a_str[mini]=tmp2;
        // if (i!=mini) count++;
    }
    // return count;
}

void bubble_sort(int *a, int *a_str, int m) {
    int i, j, tmp1, tmp2;

    for (i=0;i<m;i++) {
        for (j=m-1; j>i; j--) {
            if (a[j]<a[j-1]) {
                tmp1=a[j];
                tmp2=a_str[j];
                a[j]=a[j-1];
                a_str[j]=a_str[j-1];
                a[j-1]=tmp1;
                a_str[j-1]=tmp2;
                // n++;
            }
        }
    }

    // return n;
}

void stable(int *a_str, int *a, int *b_str, int *b, int n) {
    int i, check=1;

    for (i=0; i<n; i++) {
            if (a[i]==b[i] && a_str[i]!=b_str[i]) check=0;
    }

    for (i=0;i<n;i++) {
        printf("%c%c", b_str[i], b[i]);
        if (i<n-1) printf(" ");
    }
    printf("\n");
    if (check==1) printf("Stable\n");
    else printf("Not stable\n");
}

int main(void) {
    int i, n, B_str[36], B[36], S_str[36], S[36];
    char str[3]={'\0'};

    scanf("%d", &n);
    for (i=0;i<n;i++) {
        scanf("%s", str);
        // printf("%s\n", str);
        B_str[i]=str[0];
        S_str[i]=str[0];
        B[i]=str[1];
        S[i]=str[1];
    }
    bubble_sort(B, B_str, n);
    selection_sort(S, S_str, n);
    stable(B_str, B, B_str, B, n);
    stable(B_str, B, S_str, S, n);

    return 0;
}

