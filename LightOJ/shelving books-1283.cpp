#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[105], dp[105][105][105], n;

ll solve(ll i, ll j, ll p)
{
    if(p==n)
        return 0;

    if(dp[i][j][p]!=-1)
        return dp[i][j][p];

    ll x, y, z;
    x=y=z=0;
    if(a[p]>=a[i] && a[p]<=a[j])
    {
        x=solve(p,j,p+1)+1;
        y=solve(i,p,p+1)+1;
    }
    z=solve(i,j,p+1);
    return dp[i][j][p]=max(x,max(y,z));
}

int main()
{
    ll t, test, i, j, ans;

    scanf("%lld",&test);

    for(t=1; t<=test; t++)
    {
        scanf("%lld",&n);

        memset(dp,-1,sizeof(dp));
        a[0]=0;
        for(i=1; i<=n; i++)
            scanf("%lld",&a[i]);
        n++;
        a[n]=LLONG_MAX-100000;
        ans=solve(0,n,1);

        printf("Case %lld: %lld\n", t, ans);
    }
    return 0;
}
