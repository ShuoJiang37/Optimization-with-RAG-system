#include<stdio.h>
struct a
{
    char ch;
    int num;
} s[36];
int main()
{
    struct a s1[36],s2[36],s3[36];
    int n,i,j,k,l,t,min,book;
    char x;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        for(i=0; i<n; i++)
        {
            scanf("%c%d",&s[i].ch,&s[i].num);
            getchar();
            s1[i].ch=s[i].ch;
            s2[i].ch=s[i].ch;
            s3[i].ch=s[i].ch;
            s1[i].num=s[i].num;
            s2[i].num=s[i].num;
            s3[i].num=s[i].num;
        }
        for(i=0; i<n-1; i++)
        {
            min=i;
            for(j=i+1; j<n; j++)
            {
                if(s1[j].num<s1[min].num)
                    min=j;
            }
            if(i!=min)
            {
                t=s1[i].num;
                s1[i].num=s1[min].num;
                s1[min].num=t;
                x=s1[i].ch;
                s1[i].ch=s1[min].ch;
                s1[min].ch=x;
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=n-1; j>i; j--)
            {
                if(s2[j].num<s2[j-1].num)
                {
                    t=s2[j].num;
                    s2[j].num=s2[j-1].num;
                    s2[j-1].num=t;
                    x=s2[j].ch;
                    s2[j].ch=s2[j-1].ch;
                    s2[j-1].ch=x;
                }
            }
        }
        for(i=0; i<n; i++)
        {
            printf("%c%d",s2[i].ch,s2[i].num);
            if(i!=n-1)
                printf(" ");
            else
                printf("\n");
        }
        book=0;
        for(i=0; i<n; i++)
        {
            if(book==1)
                break;
            for(j=0; j<n; j++)
            {
                if(s2[i].num==s[j].num)
                {
                    if(s2[i].ch!=s[j].ch)
                    {
                        book=1;
                        break;
                    }
                    else
                    {
                        s2[i].num=-1;
                        s[j].num=-2;
                        break;
                    }
                }
            }
        }
        if(book==0)
            printf("Stable\n");
        if(book==1)
            printf("Not stable\n");
        for(i=0; i<n; i++)
        {
            printf("%c%d",s1[i].ch,s1[i].num);
            if(i!=n-1)
                printf(" ");
            else
                printf("\n");
        }
        book=0;
        for(i=0; i<n; i++)
        {
            if(book==1)
                break;
            for(j=0; j<n; j++)
            {
                if(s1[i].num==s3[j].num)
                {
                    if(s1[i].ch!=s3[j].ch)
                    {
                        book=1;
                        break;
                    }
                    else
                    {
                        s1[i].num=-1;
                        s3[j].num=-2;
                        break;
                    }
                }
            }
        }
        if(book==0)
            printf("Stable\n");
        if(book==1)
            printf("Not stable\n");
    }
    return 0;
}

