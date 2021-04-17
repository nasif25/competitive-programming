#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define mod 1000000009
#define inf 1000000000
#define limit 10001000

ll a[102][102], vis[102];
map<ll, vector<ll> > mp;
deque <pll> dq;

ll dfs(ll src, ll in, ll cs)
{
    pll top;
    ll i, j, z, u, p, sum;

    vis[mp[src][in]]=cs;
    sum=a[src][mp[src][in]];

    dq.pb(pll(mp[src][in],src));

    while(!dq.empty())
    {
        top=dq.front();
        dq.pop_front();

        u=top.uu;
        p=top.vv;

        //cout<<u<<" "<<p<<" "<<sum<<endl;

        for(i=0; i<mp[u].size(); i++)
        {
            if(mp[u][i]!=p && vis[mp[u][i]]!=cs)
            {
                vis[mp[u][i]]=cs;
                dq.pb(pll(mp[u][i], u));
                sum+=a[u][mp[u][i]];
            }
        }
    }
    return sum;
}
int main()
{
    ll test, u, v, c, n, i, cs, tc, ans;

    scanf("%lld", &test);
    cs=0;

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld", &n);

        for(i=0; i<n; i++)
        {
            scanf("%lld %lld %lld", &u, &v, &c);

            //cout<<u<<" "<<v<<endl;
            mp[u].pb(v);
            mp[v].pb(u);
            a[u][v]=0;
            a[v][u]=c;
        }

        ans=LLONG_MAX;
        cs++;
        ans=min(ans, dfs(1, 0, cs));
        cs++;
        ans=min(ans, dfs(1, 1, cs));

        printf("Case %lld: %lld\n", tc, ans);
        mp.clear();
    }
    return 0;
}

