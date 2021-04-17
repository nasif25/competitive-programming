#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ps push
#define pll pair<ll,ll>
#define uu first
#define vv second
#define LIMIT 100000000000
ll fw[10005], bw[10005];
map <ll, vector<ll> > mfw, mbw, mfc, mbc;
priority_queue <pll, vector<pll>, greater<pll> > pq;

void dij1(ll src)
{
    ll fv, fs, z, i, in, tem;
    pll val;
    pq.ps(pll(src,0));
    fw[src]=0;
    while(!pq.empty())
    {
        val=pq.top();
        fv=val.uu;
        fs=val.vv;
        pq.pop();
        z=mfw[fv].size();

        for(i=0;i<z;i++)
        {
            tem=mfc[fv][i];
            in=mfw[fv][i];
            if(fs+tem<fw[in])
            {
                fw[in]=fs+tem;
                pq.ps(pll(in,fs+tem));
            }
        }
    }
}
void dij2(ll src)
{
    ll fv, fs, z, i, in, tem;
    pll val;
    pq.ps(pll(src,0));
    bw[src]=0;
    while(!pq.empty())
    {
        val=pq.top();
        fv=val.uu;
        fs=val.vv;
        pq.pop();
        z=mbw[fv].size();

        for(i=0;i<z;i++)
        {
            tem=mbc[fv][i];
            in=mbw[fv][i];
            if(fs+tem<bw[in])
            {
                bw[in]=fs+tem;
                pq.ps(pll(in,fs+tem));
            }
        }
    }
}
int main()
{
    ll cs, test, n, m, s, t, u, v, c, p, i, j, in, tem, ans, z;

    scanf("%lld",&test);

    for(cs=1;cs<=test;cs++)
    {
        scanf("%lld %lld %lld %lld %lld", &n, &m, &s, &t, &p);
        for(i=0;i<m;i++)
        {
            scanf("%lld %lld %lld", &u, &v, &c);

            mfw[u].pb(v);
            mfc[u].pb(c);
            mbw[v].pb(u);
            mbc[v].pb(c);
        }

        for(i=0;i<=n;i++)
        {
            fw[i]=bw[i]=LIMIT;
        }

        dij1(s);
        dij2(t);
        ans=0;
        for(i=1;i<=n;i++)
        {
            z=mfw[i].size();
            for(j=0;j<z;j++)
            {
                in=mfw[i][j];
                if(fw[i]!=LIMIT && bw[in]!=LIMIT && fw[i]+bw[in]+mfc[i][j]<=p)
                {
                    if(mfc[i][j]>ans)
                        ans=mfc[i][j];
                }
            }
        }
        printf("Case %lld: ",cs);
        if(ans==0)
            printf("-1\n");
        else
            printf("%lld\n",ans);

        mfw.clear();
        mbw.clear();
        mfc.clear();
        mbc.clear();
    }
    return 0;
}

