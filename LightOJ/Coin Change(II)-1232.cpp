#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define msz 4
#define cn 3
#define rn 3
#define mod 100000007
#define inf 1000000000
#define limit 10001000

ll a[101], dp[10001];

int main()
{
    ll test, i, j, tc, n, k, ans;

    scanf("%lld", &test);

    for(tc=1;tc<=test;tc++)
    {
        scanf("%lld %lld", &n, &k);

        for(i=1;i<=n;i++)
        {
            scanf("%lld", &a[i]);
        }

        memset(dp, 0, sizeof(dp));

        dp[0]=1;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=k;j++)
            {
                if(j-a[i]>=0)
                    dp[j]=(dp[j-a[i]]+dp[j])%mod;
            }
        }

        printf("Case %lld: %lld\n", tc, dp[k]);
    }
    return 0;
}

