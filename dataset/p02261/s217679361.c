#include<stdio.h>

int n;
char stable;

void print_array(char s[],int d[],char sorteds[],int sortedd[],int freq[]){
    int i,j,cnt;
    stable='1';
    for(i=0;i<n;i++){
        if(freq[sortedd[i]]>1 && stable=='1'){
            cnt = freq[sortedd[i]];
            j=0;
            while(cnt--){
               if(stable=='1'){
                   while(d[j]!=sortedd[i]) j++;
                   if(s[j]!=sorteds[i]) stable='0';
                   j++;
               }
               if(i>0) printf(" ");
               printf("%c%d",sorteds[i],sortedd[i]);
               if(cnt>0) i++;
            }
        }
        else{
            if(i>0) printf(" ");
            printf("%c%d",sorteds[i],sortedd[i]);
        }
    }
    printf("\n");
    if(stable=='1') printf("Stable\n");
    else printf("Not stable\n");
}

void bubble_sort(char bs[],int bd[]){
    int i,j,dkey;
    char skey;

    for(i=0;i<n;i++){
        for(j=n-1;j>=i+1;j--){
            if(bd[j]<bd[j-1]){
                dkey = bd[j];
                bd[j] = bd[j-1];
                bd[j-1] = dkey;

                skey = bs[j];
                bs[j] = bs[j-1];
                bs[j-1] = skey;
            }
        }
    }
}

void selection_sort(char ss[],int sd[]){
    int i,j,mini,dkey;
    char skey;

    for(i=0;i<n;i++){
        mini=i;
        for(j=i;j<n;j++){
            if(sd[j]<sd[mini]){
                mini = j;
            }
        }
        if(mini!=i){
            dkey = sd[i];
            sd[i] = sd[mini];
            sd[mini] = dkey;

            skey = ss[i];
            ss[i] = ss[mini];
            ss[mini] = skey;
        }
    }
}

int main(){
    char str[3],s[36],bs[36],ss[36];
    int freq[10],d[36],bd[36],sd[36];
    int i;

    scanf("%d",&n);
    for(i=0;i<10;i++) freq[i]=0;
    for(i=0;i<n;i++){
        scanf("%s",&str);
        s[i] = str[0];
        d[i] = str[1]-'0';
        freq[d[i]]++;
        bs[i] = ss[i] = s[i];
        bd[i] = sd[i] = d[i];
    }

    bubble_sort(bs,bd);
    print_array(s,d,bs,bd,freq);

    selection_sort(ss,sd);
    print_array(s,d,ss,sd,freq);

    return 0;
}