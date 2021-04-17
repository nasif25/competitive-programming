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
#define mxn 30005

int val[mxn], st[mxn<<1], en[mxn<<1], nval[mxn<<1], cur;
vector<int> graph[mxn];
int par[mxn], par1[mxn][19];

int tree[mxn*5], lvl[mxn];

void dfs(int u, int p)
{
    st[u]=++cur;
    //id[cur]=u;
    nval[cur]=val[u];

    int v;

    for(int i=0; i<graph[u].size(); i++)
    {
        v=graph[u][i];
        if(v!=p)
        {
            par[v]=u;
            lvl[v]=lvl[u]+1;
            dfs(v, u);
        }
    }

    en[u]=++cur;
    //id[cur]=u;
    nval[cur]=-val[u];
}

void lca_init(int n)
{
    int i, j;

    for(i=0; i<n; i++)
        {
            par1[i][0]=par[i];
            for(j=1; j<=18; j++)
            {
                par1[i][j]=-1;
            }
        }

    for(j=1; (1<<j) <n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(par1[i][j-1]!=-1)
            par1[i][j]=par1[par1[i][j-1]][j-1];
        }
    }
}

int lca_find(int u, int v)
{   int i;

    if(lvl[u]>lvl[v])
        swap(u, v);

    for(i=18; i>=0; i--)
    {
        if(lvl[v]-(1<<i)>=lvl[u])
            v=par1[v][i];
    }

    if(v!=u)
    {for(i=18; i>=0; i--)
    {
        if(par1[u][i]!=-1 && par1[u][i]!=par1[v][i])
        {
            u=par1[u][i];
            v=par1[v][i];
        }
    }}
    if(v!=u)
        return max(par[u], 0);
    else
        return v;
}

void create(int n, int b, int e)
{
    if(b==e)
    {
        tree[n]=nval[b];
        return;
    }

    int left, right, mid;

    left=n*2;
    right=left+1;
    mid=(b+e)/2;

    create(left, b, mid);
    create(right, mid+1, e);

    tree[n]=tree[left]+tree[right];
}

void update(int n, int b, int e, int i, int j, int v)
{
    if(j<b || i>e)
        return;

    if(i<=b && e<=j)
    {
        tree[n]=v;
        return;
    }

    int left, right, mid;

    left=n*2;
    right=left+1;
    mid=(b+e)/2;

    update(left, b, mid, i, j, v);
    update(right, mid+1, e, i, j, v);

    tree[n]=tree[left]+tree[right];
}

int query(int n, int b, int e, int i, int j)
{
    if(j<b || i>e)
        return 0;

    if(i<=b && e<=j)
        return tree[n];

    int left, right, mid, l, r;

    left=n*2;
    right=left+1;
    mid=(b+e)/2;

    l=query(left, b, mid, i, j);
    r=query(right, mid+1, e, i, j);

    return l+r;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);

    int tc, test, n, q, o, u, v, i, lca, x, y, ans;

    scanf("%d", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf(" %d", &n);

        for(i=0; i<n; i++)
        {
            scanf("%d", &val[i]);
        }

        for(i=1; i<n; i++)
        {
            scanf("%d %d", &u, &v);

            graph[u].pb(v);
            graph[v].pb(u);
        }

        cur=0;
        lvl[0]=0;
        par[0]=-1;
        dfs(0, -1);

        //for(i=1; i<=cur; i++)
        //cout<<i<<" "<<nval[i]<<endl;

        lca_init(n);

        create(1, 1, cur);

        scanf("%d", &q);
        printf("Case %d:\n", tc);

        while(q--)
        {
            scanf("%d %d %d", &o, &u, &v);

            if(o)
            {
                val[u]=v;
                update(1, 1, cur, st[u], st[u], v);
                update(1, 1, cur, en[u], en[u], -v);
            }
            else
            {
                lca=lca_find(u, v);

                ans=0;

                x=query(1, 1, cur, st[lca], st[u]);
                y=query(1, 1, cur, st[lca], st[v]);

//                cout<<lca<<" "<<x<<" "<<y<<" "<<val[lca]<<endl;

                ans=x+y-val[lca];
                printf("%d\n", ans);
            }
        }
        for(i=0; i<n; i++)
        {
            graph[i].clear();
        }
    }
    return 0;
}

