#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
#define uu first
#define vv second
#define inf 10000000000000000

map <ll, vector<ll> >mp,mw;
map <ll, map< ll, int> > mf;
deque <pll> q;
ll n, d, hi, dis[10001];

void dij (ll p)
{
    ll v, st, i, z, x;
    pll val;

    for(i=0;i<=n;i++)
        dis[i]=inf;

    dis[p]=0;
    q.push_back(pll(p,dis[p]));

    while(!q.empty())
    {
        val=q.front();
        v=val.uu;
        st=val.vv;
        z=mp[v].size();
        q.pop_front();
        cout<<v<<" "<<dis[v]<<endl;
        if(v==n-1 && dis[v]<hi)
            hi=dis[v];

        for(i=0;i<z;i++)
        {
            if(mf[v][mp[v][i]]==0 || mf[v][mp[v][i]]!=mw[v][i] )
                x=0;
            else
                x=1;

            if(mw[v][i]+dis[v]<dis[mp[v][i]] && st+x<=d)
            {
                dis[mp[v][i]]=mw[v][i]+dis[v];
                q.push_back(pll(mp[v][i], st+x));
            }
        }
    }
}

int main()
{
    ll t, test, m, k, i, j, u, v, w;

    scanf("%lld",&test);

    for(t=1; t<=test; t++)
    {
        scanf("%lld %lld %lld %lld",&n, &m, &k, &d);

        for(i=1; i<=m; i++)
        {
            scanf("%lld %lld %lld",&u, &v, &w);

            mp[u].push_back(v);
            mw[u].push_back(w);
            mf[u][v]=0;
        }

        hi=inf;
        dij(0);
        cout<<hi<<endl;
        for(i=1; i<=k; i++)
        {
            scanf("%lld %lld %lld",&u, &v, &w);

            mp[u].push_back(v);
            mw[u].push_back(w);
            mf[u][v]=w;
        }

        dij(0);

        printf("Case %lld: ",t);

        if(hi==inf)
            printf("Impossible\n");
        else
            printf("%lld\n",hi);

        mp.clear();
        mw.clear();
        mf.clear();
    }
    return 0;
}
