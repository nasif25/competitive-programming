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
ll lim, k, dp[11][2][82][82];
bool vis[11][2][82][82];
vector <ll> ar;

ll solve(ll pos, ll is_big, ll num_rem, ll sum_rem)
{
    if(pos>lim)
    {
        if(num_rem%k==0 && sum_rem%k==0)
            return 1;

        return 0;
    }

    if(vis[pos][is_big][num_rem][sum_rem]==1)
        return dp[pos][is_big][num_rem][sum_rem];

    vis[pos][is_big][num_rem][sum_rem]=1;

    ll i, ans=0;


    if(is_big)
    {
        for(i=0; i<=ar[pos]; i++)
        {
            ans+=solve(pos+1, (i==ar[pos]?1:0), (num_rem*10+i)%k, (sum_rem+i)%k);
        }
    }
    else
    {
        for(i=0; i<=9; i++)
        {
            ans+=solve(pos+1, 0, (num_rem*10+i)%k, (sum_rem+i)%k);
        }
    }
    return dp[pos][is_big][num_rem][sum_rem]=ans;
}

void call(ll x)
{
    ar.clear();
    lim=-1;

    if(x<=0)
        return;

    while(x)
    {
        ar.pb(x%10);
        x/=10;
        lim++;
    }
    reverse(ar.begin(),ar.end());
}

int main()
{
    ll t, test, a, b, ansa, ansb;

    scanf("%lld", &test);

    for(t=1; t<=test; t++)
    {
        scanf("%lld %lld %lld", &a, &b, &k);

        memset(vis, 0, sizeof(vis));
        call(a-1);
        ansa=solve(0, 1, 0, 0);

        memset(vis, 0, sizeof(vis));
        call(b);
        ansb=solve(0, 1, 0, 0);

        printf("Case %lld: %lld\n",t, ansb-ansa);
    }
    return 0;
}


