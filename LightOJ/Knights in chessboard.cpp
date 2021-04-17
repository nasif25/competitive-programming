#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long i=1,t,m,n,ans,mark1,mark2;

    scanf("%lld",&t);

    while(i<=t)
    {
        scanf("%lld %lld",&m,&n);

        if(m==1 || n==1)
            ans=m*n;
        else if(m==2 || n==2)
        {
            if(n>m)
                n=n+m-(m=n);

            mark1=m/4;
            mark1*=4;
            mark2=m%4;

            if(mark2!=0)
            {
                if(mark2==1)
                    ans=mark1+2;
                else
                    ans=mark1+4;
            }
        }
        else
            ans=(long long)ceil((double)m*(double)n/2.0);

        printf("Case %lld: %lld\n",i,ans);

        i++;
    }
    return 0;
}
