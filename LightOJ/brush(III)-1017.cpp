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
#define mod 1000000009
#define inf 1000000000
#define limit 10001000

ll tc, n, w, a[101];
ll dp[101][101],vis[101][101];

ll solve(ll pos, ll move_rem)
{
    if(pos>=n || move_rem==0)
        return 0;

    if(vis[pos][move_rem]==tc)
        return dp[pos][move_rem];

    vis[pos][move_rem]=tc;

    ll i, fin, t1=0, t2;
    fin=a[pos]+w;

    for(i=pos;i<n && a[i]<=fin;i++)
    {
        t1++;
    }

    t1+=solve(i, move_rem-1);

    t2=solve(pos+1, move_rem);

    return dp[pos][move_rem]=max(t1, t2);
}

int main()
{
    ll test, x, k, i, ans;

    scanf("%lld", &test);

    for(tc=1;tc<=test;tc++)
    {
        scanf("%lld %lld %lld", &n, &w, &k);

        for(i=0;i<n;i++)
        {
            scanf("%lld %lld", &x, &a[i]);
        }
        sort(a, a+n);

        ans=solve(0, k);

        printf("Case %lld: %lld\n", tc, ans);
    }

    return 0;
}

