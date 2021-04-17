#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define pll pair<ll,ll>
#define inf 1000000000000000
#define uu first
#define vv second
map <ll, vector<ll> >mp,mw;
priority_queue <pll, vector<pll> , greater<pll> >pq;
ll dis[505],n;
void dij(ll src)
{
    ll v, i, z;
    pll u;
    for(i=0;i<n;i++)
        dis[i]=inf;

    dis[src]=0;
    pq.push(pll(0,src));

    while(!pq.empty())
    {
        u=pq.top();
        pq.pop();
        v=u.vv;
        z=mp[v].size();

        for(i=0;i<z;i++)
        {
            if(max(dis[v],mw[v][i])<dis[mp[v][i]])
                {
                    dis[mp[v][i]]=max(dis[v],mw[v][i]);
                    pq.push(pll(dis[mp[v][i]],mp[v][i]));
                }
        }
    }
}
int main()
{
    ll t, test, i, u, v, w, m;

    scanf("%lld",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%lld %lld",&n,&m);

        for(i=0;i<m;i++)
        {
            scanf("%lld %lld %lld",&u,&v,&w);

            mp[u].pb(v);
            mp[v].pb(u);
            mw[u].pb(w);
            mw[v].pb(w);
        }
        scanf("%lld",&v);

        dij(v);
        printf("Case %lld:\n",t);

        for(i=0;i<n;i++)
        {
            if(dis[i]==inf)
                printf("Impossible\n");
            else
                printf("%lld\n",dis[i]);
        }
        mp.clear();
        mw.clear();
    }
    return 0;
}
