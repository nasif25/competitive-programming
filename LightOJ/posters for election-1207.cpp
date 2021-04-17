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
#define limit 200010
ll tc, tree[4*limit], col[limit];

void create(ll n, ll b, ll e)
{
    tree[n]=0;
    if(b==e)
    {
        return;
    }

    ll mid, left, right;

    mid=(b+e)/2;
    left=n*2;
    right=left+1;
    create(left, b, mid);
    create(right, mid+1, e);
}

void update(ll n, ll b, ll e, ll i, ll j, ll v)
{
    if(j<b || e<i)
        return;

    if(i<=b && e<=j)
    {
        tree[n]=v;
        return;
    }

    ll mid, left, right;

    mid=(b+e)/2;
    left=n*2;
    right=left+1;

    if(tree[n]!=0)
    {
        tree[left]=tree[n];
        tree[right]=tree[n];
        tree[n]=0;
    }
    update(left, b, mid, i, j, v);
    update(right, mid+1, e, i, j, v);
}

ll query(ll n, ll b, ll e, ll i, ll j)
{
    if(j<b || e<i)
        return 0;

    //cout<<i<<" "<<b<<" "<<e<<" "<<j<<" "<<n<<" "<<tree[n]<<endl;

    if(i<=b && e<=j && tree[n]!=0)
    {
        //cout<<tree[n]<<" "<<col[tree[n]]<<endl;
        if(col[tree[n]]!=tc)
        {
            col[tree[n]]=tc;
            return 1;
        }
        else
            return 0;
    }

    if(b==e)
        return 0;

    ll mid, left, right, p1, p2;

    mid=(b+e)/2;
    left=n*2;
    right=left+1;

    p1=query(left, b, mid, i, j);
    p2=query(right, mid+1, e, i, j);

    return p1+p2;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ll test, i, j, k, n, ans;

    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld", &n);

        create(1, 1, 2*n);

        //cout<<"ok1\n";

        for(k=1; k<=n; k++)
        {
            scanf("%lld %lld", &i, &j);

            update(1, 1, 2*n, i, j, k);
        }
//        cout<<"ok2\n";

//        for(k=1; k<=4*n; k++)
//            cout<<k<<" "<<tree[k]<<endl;

        ans=query(1, 1, 2*n, 1, 2*n);
//        cout<<"ok3\n";
        printf("Case %lld: %lld\n", tc, ans);
    }
    return 0;
}

