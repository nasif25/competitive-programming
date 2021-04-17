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

ll a[101], c[101], taken[100001];
bool dp[100001];

int main()
{
    ll test, i, j, tc, n, m, k, ans;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld %lld", &n, &m);

        for(i=1; i<=n; i++)
        {
            scanf("%lld", &a[i]);
        }
        for(i=1; i<=n; i++)
        {
            scanf("%lld", &c[i]);
        }

        memset(dp, 0, sizeof(dp));

        dp[0]=1;

        for(i=1; i<=n; i++)
        {
            memset(taken, 0, sizeof(taken));

            for(j=a[i]; j<=m; j++)
            {
                if(dp[j]==0 && j-a[i]>=0)
                {
                    if(dp[j-a[i]]==1 && taken[j-a[i]]+1<=c[i])
                    {
                        //cout<<a[i]<<" "<<j-a[i]<<" "<<taken[j-a[i]]+1<<" "<<c[i]<<endl;
                        taken[j]=taken[j-a[i]]+1;
                        dp[j]=1;
                    }
                }
            }
        }
        ans=0;
        for(i=1;i<=m;i++)
        {
            if(dp[i]==1)
                {
                    //cout<<i<<endl;
                    ans++;
                }
        }

        printf("Case %lld: %lld\n", tc, ans);
    }
    return 0;
}

