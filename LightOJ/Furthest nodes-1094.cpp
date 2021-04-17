#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
#define uu first
#define vv second
vector<ll>  mp[30001],weight[30001];
ll  vis[30001],lvl1[30001], lvl2[30001];
deque <ll> q;
ll save1,save1w;

void bfs(ll src,ll p)
{
    vis[src]=p+1;
    lvl1[src]=0;

    q.push_back(src);

    save1=save1w=0;
    ll i,z,k,top;

    while(!q.empty())
    {
        top=q.front();
        q.pop_front();
        z=mp[top].size();
        for(i=0; i<z; i++)
        {
            k=mp[top][i];
            if(vis[k]==p)
            {
                vis[k]=p+1;
                q.push_back(k);
                lvl1[k]=lvl1[top]+weight[top][i];
            }
        }
        if(lvl1[top]>save1w)
        {
            save1=top;
            save1w=lvl1[top];
        }
    }
}
void bfs1(ll src,ll p)
{
    vis[src]=p+1;
    lvl2[src]=0;

    q.push_back(src);

    save1=save1w=0;
    ll i,z,k,top;

    while(!q.empty())
    {
        top=q.front();
        q.pop_front();
        z=mp[top].size();
        for(i=0; i<z; i++)
        {
            k=mp[top][i];
            if(vis[k]==p)
            {
                vis[k]=p+1;
                q.push_back(k);
                lvl2[k]=lvl2[top]+weight[top][i];
            }
        }
        if(lvl2[top]>save1w)
        {
            save1=top;
            save1w=lvl2[top];
        }
    }
}

int main()
{
    ll t, test, i, j, k, u, v, w, n;

    scanf("%lld", &test);

    for(t=1; t<=test; t++)
    {
        scanf("%lld", &n);

        for(i=1; i<n; i++)
        {
            scanf("%lld %lld %lld", &u, &v, &w);
            weight[u].push_back(w);
            weight[v].push_back(w);
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        bfs(0,0);

        bfs(save1,1);
        //lvl2=lvl1;

        bfs1(save1,2);

        printf("Case %lld: %lld\n", t, save1w);

        memset(vis,0,sizeof(vis));
        memset(lvl1,0,sizeof(lvl1));
        memset(lvl2,0,sizeof(lvl2));
        for(i=0; i<30001; i++)
        {
            mp[i].clear();
            weight[i].clear();
        }
    }
    return 0;
}
