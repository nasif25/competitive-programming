#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}

int main()
{
    long long ax,ay,bx,by,x,y,n,i,m;

    scanf("%lld",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%lld %lld %lld %lld",&ax,&ay,&bx,&by);

        x=fabs(ax-bx);
        y=fabs(ay-by);
        if(x==0)
        {
            printf("Case %lld: %lld\n",i,y+1);
            continue;
        }
        if(y==0)
        {
            printf("Case %lld: %lld\n",i,x+1);
            continue;
        }
        m=gcd(x,y);
        printf("Case %lld: %lld\n",i,m+1);
    }
    return 0;
}
