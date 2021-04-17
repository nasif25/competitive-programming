#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pi acos(-1.0)
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define mod 1000000009
#define inf 1000000000
#define limit 10001000
#define mx 100005
#define sl(n) scanf("%lld", &n)

ll a[100005], mp[100005], arr[50005], loc[100005], tree[mx * 4];

struct node
{
    ll x, y, in;
}qr[50005];

bool comp(node a, node b)
{
    if(a.x<b.x)
        return true;
    else
        return false;
}

void create(ll n, ll b, ll e)
{
 //   cout << n << " " << b << " " << e << endl;

    if (b == e)
    {
        tree[n] = a[b];
        return ;
    }

    ll l, r, m;
    l = 2*n;
    r = l + 1;
    m = (b+e)/2;
    create(l, b, m);
    create(r, m + 1, e);
    tree[n] = tree[l] + tree[r];

 //   cout << n << " " << b << " " << e << " " << tree[n] << " " << tree[l] << " " << tree[r] << endl;
}

ll query(ll n, ll b, ll e, ll i, ll j)
{
  //  cout << n << " " << b << " " << e << " " << i << " " << j << endl;
    if (j < b || e < i)
        return 0;


    if (i <= b && e <= j)
    {
        return tree[n];
    }

    ll l, r, m, ab, cd;
    l = 2*n;
    r = l + 1;
    m = (b+e)/2;

    ab = query(l, b, m, i, j);
    cd = query(r, m + 1, e, i, j);
 //   cout << n << " " << b << " " << e << " " << m << " " << ab << " " << cd << endl;
    return (ab + cd);
}

void update(ll n, ll b, ll e, ll i, ll x)
{
    if (i < b || e < i)
        return ;

    if (i <= b && e <= i)
    {
        tree[n] = x;
        return ;
    }

    ll l, r, m;
    l = 2*n;
    r = l + 1;
    m = (b+e)/2;

    update(l, b, m, i, x);
    update(r, m + 1, e, i, x);

    tree[n] = tree[l] + tree[r];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll tc, test, n, q, i, x;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld %lld", &n, &q);
        for(i=0; i<=mx; i++)
        {
            a[i] = mp[i] = loc[i] = 0;
        }

        for(i=1; i<=n; i++)
        {
            scanf("%lld", &x);
            if(mp[x]==0)
            {
                mp[x]=i;
                a[i]=1;
            }
            else
            {
                loc[mp[x]]=i;
                mp[x]=i;
                a[i] = 0;
            }
        }

        create(1, 1, n);

        for(i=0; i<q; i++)
        {
            scanf("%lld %lld", &qr[i].x, &qr[i].y);
            qr[i].in=i;
        }

        sort(qr, qr+q, comp);

        ll p=1;
        for(i=0; i<q; i++)
        {
            while(p<qr[i].x)
            {
                if(loc[p]!=0)
                {
                    update(1, 1, n, loc[p], 1);
                }
                p++;
            }
            arr[qr[i].in]=query(1, 1, n, qr[i].x, qr[i].y);
        }

        printf("Case %lld:\n", tc);

        for(i=0; i<q; i++)
            printf("%lld\n", arr[i]);
    }
    return 0;
}

