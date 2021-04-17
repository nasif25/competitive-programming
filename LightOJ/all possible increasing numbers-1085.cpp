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
#define mod 1000000007
#define inf 1000000000
#define limit 100100

ll a[limit+5], b[limit+5], tree[4*(limit+5)];

void create(ll n, ll b, ll e)
{
    tree[n]=0;
    if(b==e)
    {
        return;
    }

    ll l, r, m;

    l=2*n;
    r=l+1;
    m=(b+e)/2;

    create(l, b, m);
    create(r, m+1, e);
}

ll get(ll n, ll b, ll e, ll i, ll j)
{
    if(b>j || e<i)
        return 0;

    if(i<=b && e<=j)
    {
        return tree[n];
    }

    ll l, r, m, p1, p2;

    l=2*n;
    r=l+1;
    m=(b+e)/2;

    p1=get(l, b, m, i, j);
    p2=get(r, m+1, e, i, j);

    return (p1+p2)%mod;
}

void update(ll n, ll b, ll e, ll i, ll j, ll v)
{
    if(b>j || e<i)
        return;

    if(b==e)
    {
        tree[n]=(tree[n]+v)%mod;
        return;
    }

    ll l, r, m, p1, p2;

    l=2*n;
    r=l+1;
    m=(b+e)/2;

    update(l, b, m, i, j, v);
    update(r, m+1, e, i, j, v);

    tree[n]=(tree[l]+tree[r])%mod;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ll tc, test, i, j, n, res, x;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld", &n);

        for(i=1; i<=n; i++)
        {
            scanf("%lld", &a[i]);
            b[i]=a[i];
        }

        sort(b+1, b+n+1);

        create(1, 1, n);

        for(i=1; i<=n; i++)
        {
            x=lower_bound(b+1, b+n+n, a[i])-(b+1);

            if(x>0)
            {
                res=(get(1, 1, n, 1, x)+1)%mod;

                update(1, 1, n, x+1, x+1, res);
            }
            else
            {
                res=1;
                update(1, 1, n, 1, 1, 1);
            }
            //cout<<x<<" "<<res-1<<" "<<tree[1]<<endl;
        }
        printf("Case %lld: %lld\n", tc, tree[1]);
    }
    return 0;
}

