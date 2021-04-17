#include <bits/stdc++.h>
using namespace std;
bool prime[10000001];
long long p[1000001];
#define LIMIT 1000001

void isprime()
{
    unsigned long long i,j,k,sq;

    prime[0]=prime[1]=1;
    sq=(long long)ceil(sqrt((double)LIMIT));
    for(i=2,k=0; i<LIMIT; i+=2)
    {
        while(prime[i]==1 && i<LIMIT)
            i+=2;

        if(prime[i]==0)
        {
            p[k++]=i;
            if(i<=sq)
            {
                for(j=i; i*j<LIMIT; j++)
                    prime[i*j]=1;
            }
        }
        if(i==2)
            i--;
    }
}

int main()
{
    int i=1,t;

    long long n,sum,mark,a,j,flag;
    isprime();

    scanf("%d",&t);

    while(i<=t)
    {
       scanf("%lld",&n);
       sum=1;
       mark=(long long)sqrt((double)n);
       for(j=0;p[j]<=mark;j++)
       {
           a=flag=1;
           while(n%p[j]==0)
           {
               a++;
               flag=0;
               n/=p[j];

               if(n==1)
               {
                   sum*=a;
                   flag=2;
               }
           }
           if(flag==2)
            break;
           if(flag==0)
               sum*=a;
       }
       if(n!=1)
        sum*=2;
       printf("Case %d: %lld\n",i,sum-1);

       i++;
    }
    return 0;
}
