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

vector <ll> ar;
ll dp[11][2][2][11], lim;
bool vis[11][2][2][11];

ll solve(ll pos, ll has_start, ll is_big, ll how_many)
{
    if(pos>lim)
    {
        return how_many;
    }

    if(vis[pos][has_start][is_big][how_many]==1)
        return dp[pos][has_start][is_big][how_many];

    vis[pos][has_start][is_big][how_many]=1;

    ll i, ans=0;

    if(has_start)
    {
        if(is_big)
        {
            for(i=0; i<=ar[pos]; i++)
            {
                ans+=solve(pos+1, has_start, ((i==ar[pos])?1:0), how_many+(i==0?1:0));
            }
        }
        else
        {
            for(i=0; i<=9; i++)
            {
                ans+=solve(pos+1, has_start, 0, how_many+(i==0?1:0));
            }
        }
    }
    else
    {
        if(is_big)
        {
            for(i=0; i<=ar[pos]; i++)
            {
                ans+=solve(pos+1, (i==0?0:1), (i==ar[pos]?1:0), how_many);
            }
        }
        else
        {
            for(i=0; i<=9; i++)
            {
                ans+=solve(pos+1, (i==0?0:1), 0, how_many);
            }
        }
    }

    return dp[pos][has_start][is_big][how_many]=ans;
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

    scanf("%lld",&test);

    for(t=1; t<=test; t++)
    {
        scanf("%lld %lld", &a, &b);

        memset(vis, 0, sizeof(vis));

        call(a-1);
        ansa=solve(0, 0, 1, 0);

        memset(vis, 0, sizeof(vis));
        call(b);
        ansb=solve(0, 0, 1, 0);

        if(a==0)
            ansa--;

        printf("Case %lld: %lld\n", t, ansb-ansa);
    }

    return 0;
}
