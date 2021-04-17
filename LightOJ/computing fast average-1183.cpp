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
#define limit 100100
ll ar[limit];
struct node
{
    ll sum, pr;
}tree[limit*4];

void create(ll n, ll b, ll e)
{
    if(b==e)
    {
        tree[n].sum=0;
        tree[n].pr=-1;
        return;
    }

    ll l, r, mid;

    l=2*n;
    r=l+1;
    mid=(b+e)/2;

    create(l, b, mid);
    create(r, mid+1, e);

    tree[n].sum=tree[n].pr=0;
}

void update(ll n, ll b, ll e, ll i, ll j, ll v)
{
    if(j<b || e<i)
        return;
    if(i<=b && e<=j)
    {
        tree[n].sum=v*(e-b+1);
        tree[n].pr=v;
        return;
    }
//    cout<<n<<" "<<b<<" "<<e<<" "<<i<<" "<<j<<endl;
    ll l, r, mid;

    l=2*n;
    r=l+1;
    mid=(b+e)/2;

    if(tree[n].pr!=-1)
    {
        tree[l].sum=tree[n].pr*(mid-b+1);
        tree[l].pr=tree[n].pr;
        tree[r].sum=tree[n].pr*(e-(mid+1)+1);
        tree[r].pr=tree[n].pr;
        tree[n].pr=-1;
    }

    update(l, b, mid, i, j, v);
    update(r, mid+1, e, i, j, v);

    tree[n].sum=tree[l].sum+tree[r].sum;
}

ll query(ll n, ll b, ll e, ll i, ll j)
{
    if(j<b || e<i)
        return 0;
    if(i<=b && e<=j)
    {
        return tree[n].sum;
    }

    ll l, r, mid, p1, p2;

    l=2*n;
    r=l+1;
    mid=(b+e)/2;

    if(tree[n].pr!=-1)
    {
        tree[l].sum=tree[n].pr*(mid-b+1);
        tree[l].pr=tree[n].pr;
        tree[r].sum=tree[n].pr*(e-(mid+1)+1);
        tree[r].pr=tree[n].pr;
        tree[n].pr=-1;
    }

    p1=query(l, b, mid, i, j);
    p2=query(r, mid+1, e, i, j);

    tree[n].sum=tree[l].sum+tree[r].sum;

    return p1+p2;
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

    ll tc, test, i, j, v, o, x, qu, p, q, g, n;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld %lld", &n, &qu);

        create(1, 1, n);

//        cout<<"ok1\n";

        printf("Case %lld:\n", tc);

        while(qu--)
        {
            scanf("%lld", &o);

            if(o==1)
            {
                scanf("%lld %lld %lld", &i, &j, &v);

                update(1, 1, n, i+1, j+1, v);

//                cout<<"ok2\n";
            }
            else
            {
                scanf("%lld %lld", &i, &j);

                p=query(1, 1, n, i+1, j+1);

//                cout<<"ok3\n";

                q=j-i+1;

                g=gcd(p,q);

                p/=g;
                q/=g;

                if(q==1)
                    printf("%lld\n", p);
                else
                    printf("%lld/%lld\n", p, q);
            }
        }
    }
    return 0;
}

