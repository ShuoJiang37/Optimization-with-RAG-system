        #include<stdio.h>

        #define N 1000


        int n,A[N],B[N],C[N],con,res,min;

        int small(int a,int b)
        {
          if(a<b)return a;
          else return b;
        }

        int search(int a)
        {
          int i;
          for(i=0; i<n; i++){
            if(A[i]==a)return i;
          }
        }

        int main()
        {
          int i,j,sum=0,p;

          scanf("%d",&n);

          for(i=0; i<n; i++){
            scanf("%d",&A[i]);
            B[i]=A[i];
          }

          for(i=n-1; i>0; i--){
            for(j=0; j<i; j++){
              if(B[j]>B[j+1]){
                int tmp;
                tmp=B[j];
                B[j]=B[j+1];
                B[j+1]=tmp;
              }
            }
          }

          for(i=0; i<n; i++)C[i]=0;

          for(i=0; i<n; i++){
            p=i;
            con=res=0;
            min=(1<<24);

            while(C[p]==0){
              C[p]=1;
              con++;
              res+=A[p];
              min=small(min,A[p]);
              p=search(B[p]);
            }

            if(con<2)continue;
            sum+=small(res+B[0]*(con+1)+min,res+min*(con-2));
          }

          printf("%d\n",sum);

          return 0;
        }

