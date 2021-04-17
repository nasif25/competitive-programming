#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b)
{
    if(a%b==0)
        return b;

    return gcd(b,a%b);
}

int main()
{
    ll t, test, n, i, v, x, sum, g, neg;

    scanf("%lld",&test);

    for(t=1; t<=test; t++)
    {
        scanf("%lld",&n);
        neg=sum=0;
        for(i=1; i<=n; i++)
        {
            scanf("%lld",&v);

            if(v<0)
            {
                neg++;
                sum-=v;
            }
            else
                sum+=v;
        }

        x=n-neg;
        if(x<=0)
        {
            printf("Case %lld: inf\n",t);
            continue;
        }
        g=gcd(sum,x);

        sum/=g;
        x/=g;

        printf("Case %lld: %lld/%lld\n",t,sum,x);
    }
    return 0;
}
