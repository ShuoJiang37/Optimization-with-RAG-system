#include<stdio.h>

int main()
{
    int n, i, j, tmp, min,k,l,f=1;
    int a[36],b[36],s[36],t[36];
    char ch;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf(" %c%d ",&ch,&a[i]);
        s[i] = a[i];
        switch(ch){
            case 'S': b[i] = 1;t[i] = 1;break;
            case 'H': b[i] = 2;t[i] = 2;break;
            case 'D': b[i] = 3;t[i] = 3;break;
            case 'C': b[i] = 4;t[i] = 4;break;
            default : b[i] = 0;t[i] = 0;
        }
    }
    //bubble
    for(i = 0; i < n; i++)
    {
        for(j = n-1; j > i; j--)
        {
            if(a[j] < a[j-1])
            {
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                tmp = b[j];
                b[j] = b[j-1];
                b[j-1] = tmp;
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        switch(b[i]){
            case 1: printf("S");break;
            case 2: printf("H");break;
            case 3: printf("D");break;
            case 4: printf("C");break;
            default: printf("N");
        }
        printf("%d",a[i]);
        if(i != n-1) printf(" ");
        else printf("\n");
    }
    printf("Stable\n");
    //selsection
    for(i = 0; i < n; i++)
    {
        min = i;
        for(j = i; j < n; j++)
        {
            if(s[j] < s[min])
            {
                min = j;
            }
        }
        tmp = s[i];
        s[i] = s[min];
        s[min] = tmp;
        tmp = t[i];
        t[i] = t[min];
        t[min] = tmp;
    }
    for(i = 0; i < n; i++)
    {
        switch(t[i]){
            case 1: printf("S");break;
            case 2: printf("H");break;
            case 3: printf("D");break;
            case 4: printf("C");break;
            default : printf("N");
        }
        printf("%d",s[i]);
        if(i != n-1) printf(" ");
        else printf("\n");
    }
    for(i = 0; i < n; i++)
    {
        /*for(j = i+1; j < n; j++)
        {
            for(k = 0; k < n; k++)
            {
                for(l = k+1; l < n; l++)
                {
                    if(s[i] == s[j] && s[i] == a[l] && s[j] == a[k])
                    {
                        f = 0;
                    }
                }
            }
        }*/
        if(b[i] != t[i]) f = 0;
    }
    if(f) printf("Stable\n");
    else printf("Not stable\n");
    return 0;
}

