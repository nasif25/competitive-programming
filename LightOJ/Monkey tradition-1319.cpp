#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod (ll b, ll p, ll m)
{
    if(p==0)
        return 1;
    ll d=mod(b,p/2,m);

    if(p%2==0)
        d=(d*d)%m;
    else
        d=(b*(d*d)%m)%m;
    return d;
}
int main()
{
    ll test, t, n, r[13], p[13], m[13], M, i, ans;

    scanf("%lld",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%lld",&n);
        M=1;
        for(i=1;i<=n;i++)
        {
            scanf("%lld %lld",&p[i], &r[i]);
            M*=p[i];
        }
        ans=0;
        for(i=1;i<=n;i++)
        {
            m[i]=mod(M/p[i],p[i]-2,p[i]);

            ans= (ans%M + (((r[i]*m[i])%M)*(M/p[i]))%M)%M;
        }
        printf("Case %lld: %lld\n",t,ans);
    }
    return 0;
}
