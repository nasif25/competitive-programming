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
}ar[12005];

ll par[102];

bool comp1(node x, node y)
{
    if(x.w<y.w)
        return true;
    else
        return false;
}
bool comp2(node x, node y)
{
    if(x.w>y.w)
        return true;
    else
        return false;
}

ll find_par(ll x)
{
    if(par[x]==x)
        return x;

    return par[x]=find_par(par[x]);
}

ll mst(ll k, ll n)
{
    ll i, j, x, y, cnt=0, sum=0;

    for(i=0; i<k; i++)
    {
        x=find_par(ar[i].u);
        y=find_par(ar[i].v);

        if(x!=y)
        {
            par[y]=x;
            sum+=ar[i].w;
            cnt++;
        }
        if(cnt==n)
            break;
    }
    return sum;
}

ll gcd(ll a, ll b)
{
    if(a%b==0)
        return b;

    return gcd(b,a%b);
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//      ios_base::sync_with_stdio(0);
    ll i, p, q, u, v, w, tc, test, n, k, hi, lo;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld", &n);

        k=0;

        while(scanf("%lld %lld %lld", &u, &v, &w)==3)
        {
            if(u==0 && v==0 && w==0)
                break;

            ar[k].u=u;
            ar[k].v=v;
            ar[k].w=w;
            k++;
        }

        for(i=0; i<=n; i++)
            par[i]=i;

        sort(ar, ar+k, comp1);

        lo=mst(k, n);

        for(i=0; i<=n; i++)
            par[i]=i;

        sort(ar, ar+k, comp2);

        hi=mst(k, n);

        p=(hi+lo);
        q=2;
        if(p%2==0)
        {
            p/=2;
            q=1;
        }

        if(q==1)
            printf("Case %lld: %lld\n", tc, p);
        else
            printf("Case %lld: %lld/%lld\n", tc, p, q);
    }

    return 0;
}

