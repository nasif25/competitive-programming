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
#define mx 100001

struct node
{
    ll a[3], p;
} tree[mx * 3];

void create(ll n, ll b, ll e)
{
    if (b == e)
    {
        tree[n].a[0] = 1;
        tree[n].a[1] = tree[n].a[2] = tree[n].p=0;
        return;
    }

    ll Left = n * 2;
    ll Right = n* 2 + 1;
    ll mid = (b + e) / 2;

    create(Left, b, mid);
    create(Right, mid + 1, e);

    tree[n].a[0] = tree[Left].a[0]+tree[Right].a[0];
    tree[n].a[1] = tree[n].a[2] = tree[n].p = 0;
}

void swp(ll n, ll x)
{
    for(ll i=1; i<=x%3; i++)
    {
        swap(tree[n].a[0], tree[n].a[2]);
        swap(tree[n].a[1], tree[n].a[2]);
    }
}

void update(ll n, ll b, ll e, ll i, ll j, ll x)
{
    if (i > e || j < b)
    {
        swp(n, x-1);
        tree[n].p += x-1;
        return;
    }
    if (b >= i && e <= j) //নোডের রেঞ্জ আপডেটের রেঞ্জের ভিতরে
    {
        swp(n, x);
        tree[n].p += x; //নিচের নোডগুলোর সাথে x যোগ হবে
        return;
    }

    ll Left = n * 2;
    ll Right = (n * 2) + 1;
    ll mid = (b + e) / 2;
    update(Left, b, mid, i, j, x + tree[n].p);
    update(Right, mid + 1, e, i, j, x + tree[n].p);

    for(ll i=0; i<=2; i++)
    {
        tree[n].a[i] = tree[Left].a[i] + tree[Right].a[i];
    }
    tree[n].p = 0;
}

ll query(ll n, ll b, ll e, ll i, ll j, ll rem)
{
    if (i > e || j < b)
    {
        return 0;
    }
    if (b >= i && e <= j) //নোডের রেঞ্জ আপডেটের রেঞ্জের ভিতরে
    {
        return tree[n].a[(3-rem%3)%3];
    }

    ll Left = n * 2;
    ll Right = (n * 2) + 1;
    ll mid = (b + e) / 2;
    ll p1 = query(Left, b, mid, i, j, rem + tree[n].p);
    ll p2 = query(Right, mid + 1, e, i, j, rem + tree[n].p);

    return p1+p2;
}

int main()
{
    ll tc, test, n, q, i, j, ans, o;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld %lld", &n, &q);

        create(1, 0, n-1);
        printf("Case %lld:\n", tc);

        while(q--)
        {
            scanf("%lld %lld %lld", &o, &i, &j);

            if(o==0)
                update(1, 1, n, i+1, j+1, 1);
            else
                {
                    ans=query(1, 1, n, i+1, j+1, 0);
                    printf("%lld\n", ans);
                }
        }
    }
    return 0;
}
