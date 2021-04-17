#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define uu first
#define vv second
#define msz 4
#define cn 3
#define rn 3
#define mod 1000000009
#define inf 1000000000
#define limit 10001000
map <ll , vector<ll> > mp, mw;
ll lvl[105];
deque <ll> dq;

void bfs(ll src)
{
    lvl[src]=0;
    dq.pb(src);
    ll v,i,z;
    while(!dq.empty())
    {
        v=dq.front();

        dq.pop_front();
        z=mw[v].size();
//cout<<v<<" "<<z<<endl;
        for(i=0;i<z;i++)
        {
            //cout<<lvl[v]<<" "<<mp[v][i]<<" "<<lvl[mp[v][i]]<<endl;
            if(lvl[v]+mw[v][i]<lvl[mp[v][i]])
            {
                lvl[mp[v][i]]=lvl[v]+mw[v][i];
                dq.pb(mp[v][i]);
            }
        }
    }
}
int main()
{
    ll t, test, n, m, u, v, w, i;

    scanf("%lld",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%lld %lld", &n, &m);

        for(i=1;i<=m;i++)
        {
            scanf("%lld %lld %lld", &u, &v, &w);
            mp[u].pb(v);
            mw[u].pb(w);
            mp[v].pb(u);
            mw[v].pb(w);
        }

        for(i=1;i<=n;i++)
        {
            lvl[i]=LLONG_MAX;
        }

        bfs(1);
//        for(i=1;i<=n;i++)
//            cout<<i<<" "<<lvl[i]<<endl;
        if(lvl[n]==LLONG_MAX)
            printf("Case %lld: Impossible\n", t);
        else
            printf("Case %lld: %lld\n", t, lvl[n]);
        mp.clear();
        mw.clear();
    }
    return 0;
}


