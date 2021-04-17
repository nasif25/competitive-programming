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

vector<int>  mp[100005], mw[100005];

int par[100005], cost[100005], level[100005];
int sparse_ar[100005][17], sparse_min[100005][17], sparse_max[100005][17];

void dfs(int v, int p, int lvl)
{
    level[v]=lvl;

    int i, x;

    for(i=0; i<mp[v].size(); i++)
    {
        x=mp[v][i];
        if(level[x]==-1)
        {
            par[x]=v;
            cost[x]=mw[v][i];
            dfs(x, v, level[v]+1);
        }
    }
}

void build_sparse_table(int n)
{
    int i, j, x;

    for(i=1; i<=n; i++)
    {
        for(j=0; j<17; j++)
        {
            if(j)
            {
                sparse_ar[i][j]=-1;
                sparse_max[i][j]=-1;
                sparse_min[i][j]=inf;
            }
            else
            {
                sparse_ar[i][j]=par[i];

                sparse_max[i][j]=sparse_min[i][j]=cost[i];
            }
        }
    }

    for(j=1; (1<<j) <= n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(sparse_ar[i][j-1]!=-1)
            {
                sparse_ar[i][j]=sparse_ar[sparse_ar[i][j-1]][j-1];
                sparse_max[i][j]=max(sparse_max[i][j-1], sparse_max[sparse_ar[i][j-1]][j-1]);
                sparse_min[i][j]=min(sparse_min[i][j-1], sparse_min[sparse_ar[i][j-1]][j-1]);
            }
        }
    }

}

pii solve(int u, int v)
{
    if(level[u] < level[v])
    {
        swap(u, v);
    }

    int lg=log2(level[u]), i, j, mx=-1, mn=inf;

    for(i=lg; i>=0; i--)
    {
        if(level[u]-(1<<i)>=level[v])
        {
            mx=max(mx, sparse_max[u][i]);
            mn=min(mn, sparse_min[u][i]);

            u=sparse_ar[u][i];
        }
    }
    if(u==v)
    {
        return pll(mn, mx);
    }

    for(i=lg; i>=0; i--)
    {
        if(sparse_ar[u][i]!=-1 && sparse_ar[u][i]!=sparse_ar[v][i])
        {
            mx=max(mx, max(sparse_max[u][i], sparse_max[v][i]));
            mn=min(mn, min(sparse_min[u][i], sparse_min[v][i]));

            u=sparse_ar[u][i];
            v=sparse_ar[v][i];
        }
    }

    mx=max(mx, max(cost[u], cost[v]));
    mn=min(mn, min(cost[u], cost[v]));

    return pii(mn, mx);
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);

    int tc, test, n, i, j, u, v, w, q;
    pii x;

    scanf("%d", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%d", &n);

        for(i=1; i<n; i++)
        {
            scanf("%d %d %d", &u, &v, &w);

            mp[u].pb(v);
            mp[v].pb(u);
            mw[u].pb(w);
            mw[v].pb(w);
        }
        memset(par, -1, sizeof(par));
        memset(level, -1, sizeof(level));

        level[1]=0;
        cost[1]=0;

        dfs(1, -1, 0);

        build_sparse_table(n);

        scanf("%d", &q);

        printf("Case %d:\n", tc);

        while(q--)
        {
            scanf("%d %d", &u, &v);

            x=solve(u, v);

            printf("%d %d\n", x.uu, x.vv);
        }

        for(i=1; i<=n; i++)
        {
            mp[i].clear();
            mw[i].clear();
        }
    }

    return 0;
}
