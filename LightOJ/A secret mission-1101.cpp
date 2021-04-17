
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pi acos(-1.0)
#define pb push_back
#define ppf pop_front
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define mod 1000000009
#define inf 1000000000
#define limit 10001000

struct node
{
    ll u, v, w;

    node();
    node(ll a, ll b, ll c)
    {
        u=a;
        v=b;
        w=c;
    }
};

ll par[50005], level[50005], dis[50005];
ll sparse_par[50005][17], sparse_max[50005][17];
map<ll, vector<ll> > mp, cost;
vector<node> edge;

bool comp(node a, node b)
{
    if(a.w<b.w)
        return 1;

    return 0;
}

ll find_par(ll u)
{
    if(par[u]==u)
        return u;

    return par[u]=find_par(par[u]);
}

void mst(ll n)
{
    sort(edge.begin(), edge.end(), comp);

    ll i, cnt=0, u, v, w;

    for(i=1; i<=n; i++)
    {
        par[i]=i;
        mp[i].clear();
        cost[i].clear();
    }

    for(i=0; i<edge.size(); i++)
    {
        u=find_par(edge[i].u);
        v=find_par(edge[i].v);

        if(u!=v)
        {
            par[v]=u;

            mp[u].pb(edge[i].v);
            mp[v].pb(edge[i].u);
            cost[u].pb(edge[i].w);
            cost[v].pb(edge[i].w);

            cnt++;
            if(cnt==n-1)
                break;
        }
    }
}

void dfs(ll u, ll p, ll cnt)
{
    level[u]=cnt;
    par[u]=p;

    for(ll i=0; i<mp[u].size(); i++)
    {
        ll v=mp[u][i];

        if(level[v]==-1)
        {
            dis[v]=cost[u][i];
            dfs(v, u, cnt+1);
        }
    }
}

void sparse_table(ll n)
{
    memset(sparse_par, -1, sizeof(sparse_par));

    ll i, j;

    for(i=1; i<=n; i++)
    {
        sparse_par[i][0]=par[i];
        sparse_max[i][0]=dis[i];
    }

    for(i=1; (1<<i) <=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(sparse_par[j][i-1]!=-1)
            {
                sparse_par[j][i]=sparse_par[sparse_par[j][i-1]][i-1];
                sparse_max[j][i]=max(sparse_max[j][i-1],sparse_max[sparse_par[j][i-1]][i-1]);
            }
        }
    }
}

ll query(ll u, ll v)
{
    if(level[u]<level[v])
    {
        swap(u, v);
    }

    ll i, lg=log2(level[u]), ans=0;

    for(i=lg; i>=0; i--)
    {
        if(level[u]-(1<<i)>=level[v])
        {
            ans=max(ans, sparse_max[u][i]);
            u=sparse_par[u][i];
        }
    }

    if(u==v)
        return ans;

    for(i=lg; i>=0; i--)
    {
        if(sparse_par[u][i]!=-1 && sparse_par[u][i]!=sparse_par[v][i])
        {
            ans=max(ans, max(sparse_max[u][i], sparse_max[v][i]));

            u=sparse_par[u][i];
            v=sparse_par[v][i];
        }
    }

    ans=max(ans, max(dis[u], dis[v]));

    return ans;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);

    ll test, tc, i, j, u, v, w, n, m, q;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld %lld", &n, &m);

        for(i=0; i<m; i++)
        {
            scanf("%lld %lld %lld", &u, &v, &w);

            edge.pb(node(u, v, w));
        }

        mst(n);
        //cout<<"mst\n";

        memset(level, -1, sizeof(level));

        dis[1]=0;

        dfs(1, 1, 0);
        //cout<<"dfs\n";

        sparse_table(n);

        scanf("%lld", &q);

        printf("Case %lld:\n", tc);

        while(q--)
        {
            scanf("%lld %lld", &u, &v);

            printf("%lld\n", query(u, v));
        }

        edge.clear();
    }

    return 0;
}
