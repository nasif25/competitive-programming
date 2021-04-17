#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000000000000

ll n, a[3][1001], b[3][1001], dp[3][1001];

ll solve(ll l, ll i)
{
    if(i==n)
        return 0;

    if(dp[l][i]!=-1)
        return dp[l][i];

    ll s1=inf,s2=inf;

    s1=solve(l,i+1)+a[l][i];
//9cout<<l<<" "<<i<<" s1 "<<s1<<" "<<s1-a[l][i]<<endl;
    if(i<n)
        s2=solve((l+1)%2,i+1)+a[l][i]+b[l][i];
//cout<<l<<" "<<i<<" s2 "<<s2<<endl;
    dp[l][i]=min(s1,s2);
    //cout<<l<<" "<<i<<" "<<dp[l][i]<<" "<<s1<<" "<<s2<<" "<<endl;

    return dp[l][i];
}

int main()
{
    ll t, test, i, j, ans, s1, s2;

    scanf("%lld",&test);

    for(t=1; t<=test; t++)
    {
        scanf("%lld",&n);

        for(i=0; i<2; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%lld",&a[i][j]);
            }
        }
        for(i=0; i<2; i++)
        {
            for(j=0; j<n-1; j++)
            {
                scanf("%lld",&b[i][j]);
            }
        }
        memset(dp,-1,sizeof(dp));

        s1=solve(0,0);

        memset(dp,-1,sizeof(dp));

        s2=solve(1,0);

        ans=min(s1,s2);

        printf("Case %lld: %lld\n",t,ans);
    }
    return 0;
}

