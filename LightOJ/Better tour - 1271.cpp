#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
#define uu first
#define vv second
#define pb push_back
vector<ll>  mp[50001];
ll  p[50001];
bool vis[50001];
deque <ll> q;
vector<ll> ans;

void bfs(ll src)
{
    vis[src]=1;
    p[src]=0;

    q.pb(src);

    ll i, z, k, top;

    while(!q.empty())
    {
        top=q.front();
        q.pop_front();
        z=mp[top].size();

        for(i=0; i<z; i++)
        {
            k=mp[top][i];
            if(vis[k]==0)
            {
                vis[k]=1;
                p[k]=top;
                q.pb(k);
            }
        }
    }
}

int main()
{
    ll t, test, i, j, u, v, n, x, y;

    scanf("%lld", &test);

    for(t=1; t<=test; t++)
    {
        scanf("%lld", &n);

        for(i=1; i<=n; i++)
        {
            scanf("%lld", &v);

            if(i>1)
            {
                mp[u].push_back(v);
                mp[v].push_back(u);
            }
            u=v;
            if(i==1)
                x=v;
            if(i==n)
                y=v;
        }
        for(i=1; i<=50000; i++)
            sort(mp[i].begin(), mp[i].end());

        bfs(x);

        i=0;

        while(y!=0)
        {
            ans.pb(y);
            y=p[y];
            i++;
        }

        printf("Case %lld:\n",t);

        for(i=i-1; i>0; i--)
            printf("%lld ", ans[i]);

        printf("%lld\n", ans[i]);

        memset(vis,0,sizeof(vis));
        for(i=0; i<=50001; i++)
        {
            mp[i].clear();
        }
        ans.clear();
    }
    return 0;
}

