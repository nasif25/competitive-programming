#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pi acos(-1.0)
#define pb push_back
#define ppf pop_front
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define mod 1000000009
#define inf 1000000000
#define limit 10001000

ll ar1[60], ar2[60];
ll dp[1001][1001], n;

ll solve(ll i, ll j)
{
    if(i==n || j==n)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    ll p1=0, p2=0;

    if(ar1[i]>ar2[j])
    {
        p1=solve(i+1, j+1)+2;
    }

    if(ar1[i]==ar2[j])
    {
        p1=solve(i+1, j+1)+1;
        p2=solve(i+1, j);
    }

    if(ar1[i]<ar2[j])
    {
        p1=solve(i+1, j);
    }

    return dp[i][j]=max(p1, p2);
}


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);

    ll tc, test, i, j, ans1;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld", &n);

        for(i=0; i<n; i++)
        {
            scanf("%lld", &ar1[i]);
        }

        for(i=0; i<n; i++)
        {
            scanf("%lld", &ar2[i]);
        }

        sort(ar1, ar1+n);
        sort(ar2, ar2+n);

        ans1=0;

        memset(dp, -1, sizeof(dp));

        ans1=solve(0, 0);

        printf("Case %lld: %lld\n", tc, ans1);
    }

    return 0;
}

