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

ll ar[100005], par[100005], sparse_par[100005][17], level[100005];

void build_sparse_table(ll n)
{
    ll i, j;

    memset(sparse_par, -1, sizeof(sparse_par));

    for(i=0; i<n; i++)
    {
        sparse_par[i][0]=par[i];
        //cout<<i<<" "<<par[i]<<endl;
    }

    for(j=1; (1<<j) < n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(sparse_par[i][j-1]!=-1)
                sparse_par[i][j]=sparse_par[sparse_par[i][j-1]][j-1];
        }
    }
}

ll query(ll k, ll v)
{
    ll i, lg=log2(level[k])+1, x;


    for(i=lg; i>=0; i--)
    {
        x=sparse_par[k][i];

        //cout<<k<<" "<<i<<" "<<x<<endl;

        if(x!=-1 && ar[x]>=v)
        {
            k=x;
        }
    }
    return k;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);

    ll tc, test, n, q, i, u, v, ans;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld %lld", &n, &q);

        ar[0]=1;
        par[0]=-1;
        level[0]=0;

        for(i=1; i<n; i++)
        {
            scanf("%lld %lld", &u, &v);

            ar[i]=v;
            par[i]=u;
            level[i]=level[u]+1;
        }
        //cout<<"input\n";

        build_sparse_table(n);

        printf("Case %lld:\n", tc);

        while(q--)
        {
            scanf("%lld %lld", &u, &v);

            ans=query(u, v);

            printf("%lld\n", ans);
        }
    }

    return 0;
}

