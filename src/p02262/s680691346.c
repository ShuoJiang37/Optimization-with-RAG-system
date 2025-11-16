    #include<stdio.h>

    #define NUM 100


    int cnt,mcnt=0;

    void insertionSort(int *A,int num,int g)
    {
      int i,j,v;
      for(i=g;i<num;i++)
        {
        v=A[i];
        j=i-g;
        while(j>=0 && A[j]>v)
          {
          A[j+g]=A[j];
          j=j-g;
          cnt++;
        }
        A[j+g]=v;
      }
    }

    void shellSort(int *A,int num)
    {
      int m,i,j;

      int G[NUM];

      cnt=0;
      m=NUM-1;

      for(i=m;i>=0;i--)
        {
        G[i]=(m-i)*6+1;
        if(G[i]<=num)mcnt++;
      }


      for(i=0;i<m+1;i++) insertionSort(A,num,G[i]);

      printf("%d\n",mcnt);

      for(i=m-mcnt+1;i<m;i++) printf("%d ",G[i]);

      printf("%d\n%d\n",G[i],cnt);
    }



    int main(void)
    {
      int i,N;

      int A[2000000];

      scanf("%d",&N);
      for(i=0;i<N;i++) scanf("%d",&A[i]);

      shellSort(A,N);

      for(i=0;i<N;i++)printf("%d\n",A[i]);

      return 0;
    }

