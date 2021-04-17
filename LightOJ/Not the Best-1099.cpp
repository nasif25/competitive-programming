#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <utility>
using namespace std;
#define pb push_back
#define pf push_forward
#define ll long long
#define pll pair<ll,ll>
#define uu first
#define vv second
ll n, r, srt[5005],srt2[5005];
map<ll,vector<ll> > mp, mw;
priority_queue< pll, vector<pll>, greater<pll> > pq;

void dij(ll src)
{
    ll i, j, z, x, v;
    pll u;
    for(i=0; i<=n; i++)
        srt[i]=srt2[i]=LLONG_MAX;
    srt[1]=srt[1]=0;
    pq.push(pll(0,src));
    while(!pq.empty())
    {
        u=pq.top();
        pq.pop();
        v=u.vv;
        x=u.uu;
        z=mp[v].size();
        for(i=0; i<z; i++)
        {
            if(x+mw[v][i]<srt[mp[v][i]])
            {
                srt2[mp[v][i]]=srt[mp[v][i]];
                srt[mp[v][i]]=x+mw[v][i];
                pq.push(pll(srt[mp[v][i]],mp[v][i]));
            }
            if(x+mw[v][i]<srt2[mp[v][i]] && x+mw[v][i]>srt[mp[v][i]])
            {
                srt2[mp[v][i]]=x+mw[v][i];
                pq.push(pll(srt2[mp[v][i]],mp[v][i]));
            }
            //cout<<v<<" "<<srt[v]<<" "<<srt2[v]<<endl;
        }
    }
}

int main()
{
    ll test, t, i, j, u, v, w;

    scanf("%lld",&test);

    for(t=1; t<=test; t++)
    {
        scanf("%lld %lld",&n,&r);

        for(i=1; i<=r; i++)
        {
            scanf("%lld %lld %lld",&u,&v,&w);
            mp[u].pb(v);
            mp[v].pb(u);
            mw[u].pb(w);
            mw[v].pb(w);
        }
        dij(1);
        printf("Case %lld: %lld\n",t,srt2[n]);
        mp.clear();
        mw.clear();
    }
    return 0;
}
