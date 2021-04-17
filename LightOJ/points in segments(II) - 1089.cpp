#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define mod 1000000009
#define inf 1000000000
#define limit 10001000

map<ll,ll> rev;
vector<ll>qu;
vector<pll>r;
set<ll> s;
set<ll> ::iterator it;

#define mx 300005
ll arr[mx];
struct node
{
    ll prop, sum;
}tree[mx * 3];


void create(ll n, ll b, ll e)
{
    if (b == e) {
        tree[n].sum = tree[n].prop= 0;
        return;
    }
    ll Left = n * 2;
    ll Right = n * 2 + 1;
    ll mid = (b + e) / 2;
    create(Left, b, mid);
    create(Right, mid + 1, e);
    tree[n].prop=0;
    tree[n].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[n].prop;
    return;
}

void update(ll n, ll b, ll e, ll i, ll j, ll x)
{

    if (i > e || j < b)
        return;
    if (b >= i && e <= j) //নোডের রেঞ্জ আপডেটের রেঞ্জের ভিতরে
    {
        tree[n].sum += ((e - b + 1) * x); //নিচে নোড আছে e-b+1 টি, তাই e-b+1 বার x যোগ হবে এই রেঞ্জে
        tree[n].prop += x; //নিচের নোডগুলোর সাথে x যোগ হবে
        return;
    }
    ll Left = n * 2;
    ll Right = (n * 2) + 1;
    ll mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[n].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[n].prop;
    //cout<<n<<" "<<b<<" "<<e<<" "<<i<<" "<<" "<<j<<" "<<x<<" "<<tree[n].sum<<endl;

    return;
    //উপরে উঠার সময় পথের নোডগুলো আপডেট হবে
    //বাম আর ডান পাশের সাম ছাড়াও যোগ হবে নিচে অতিরিক্ত যোগ হওয়া মান
}

ll query(ll n, ll b, ll e, ll i, ll j, ll carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[n].sum + carry * (e - b + 1); //সাম এর সাথে যোগ হবে সেই রেঞ্জের সাথে অতিরিক্ত যত যোগ করতে বলেছে সেটা

    ll Left = n << 1;
    ll Right = (n << 1) + 1;
    ll mid = (b + e) >> 1;

    ll p1 = query(Left, b, mid, i, j, carry + tree[n].prop); //প্রপাগেট ভ্যালু বয়ে নিয়ে যাচ্ছে carry ভ্যারিয়েবল
    ll p2 = query(Right, mid + 1, e, i, j, carry + tree[n].prop);

    return p1 + p2;
}


int main()
{
    ll tc, test, n, i, j, u, v, q;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld %lld", &n, &q);
        //cout<<"a\n";
        for(i=0; i<n; i++)
        {
            scanf("%lld %lld", &u, &v);
            r.pb(pll(u, v));

            s.insert(u);
            s.insert(v);
        }
        //cout<<"b\n";
        for(i=0; i<q; i++)
        {
            scanf("%lld", &u);
            qu.pb(u);
            s.insert(u);
        }
        //cout<<"c\n";
        for(it=s.begin(),i=1; it!=s.end(); it++, i++)
        {
            rev[*it]=i;
        }
        //cout<<"d\n";
        u=i-1;
        create(1, 1, u);
        //cout<<"e\n"<<u<<endl;;
        for(i=0; i<n; i++)
        {
            //cout<<u<<" "<<rev[r[i].uu]<<" "<<rev[r[i].vv]<<endl;
            update(1, 1, u, rev[r[i].uu], rev[r[i].vv], 1);
        }
        //cout<<"f\n";
        printf("Case %lld:\n", tc);

        for(i=0; i<q; i++)
        {
            v=query(1, 1, u, rev[qu[i]], rev[qu[i]], 0);

            printf("%lld\n", v);
        }
        rev.clear();
        qu.clear();
        s.clear();
        r.clear();
    }
    return 0;
}

