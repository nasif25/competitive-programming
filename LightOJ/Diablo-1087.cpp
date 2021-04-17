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
#define limit (100010+50000)

ll tc, tree[4*limit], ar[limit], num;

void create(ll n, ll b, ll e)
{
    if(b==e)
    {
        tree[n] = (b<=num);
        return;
    }

    ll mid, left, right;

    mid=(b+e)/2;
    left=n*2;
    right=left+1;
    create(left, b, mid);
    create(right, mid+1, e);
    tree[n]=tree[left]+tree[right];
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

    update(left, b, mid, i, j, v);
    update(right, mid+1, e, i, j, v);

    tree[n]=tree[left]+tree[right];
}

ll query1(ll n, ll b, ll e, ll v)
{
    //cout<<i<<" "<<b<<" "<<e<<" "<<j<<" "<<n<<" "<<tree[n]<<endl;
    if(tree[n]<v)
    {
        //cout<<n<<" "<<tree[n]<<" "<<v<<endl;
        return 0;
    }

    if(b==e)
        return b;

    ll mid, left, right, p1, p2;

    mid=(b+e)/2;
    left=n*2;
    right=left+1;

    if(tree[left]>=v)
        p1=query1(left, b, mid, v);
    else
        p1=query1(right, mid+1, e, v-tree[left]);

    return p1;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ll tc, test, n, i, v, q, k, ans;
    char c;
    scanf("%lld", &test);

    for(tc=1; tc<=test; tc++)
    {
        scanf("%lld %lld", &n, &q);

        num=k=n;

        for(i=1; i<=n; i++)
        {
            scanf("%lld", &ar[i]);
        }

        create(1, 1, n+q);

        printf("Case %lld:\n", tc);

        for(i=0; i<q; i++)
        {
            scanf(" %c %lld", &c, &v);

            if(c=='a')
            {
                ar[++k]=v;
                update(1, 1, n+q, k, k, 1);
            }
            else
            {
                ans=query1(1, 1, n+q, v);

                if(ans==0)
                    printf("none\n");
                else
                {
                    update(1, 1, n+q, ans, ans, 0);
                    printf("%lld\n", ar[ans]);
                }
            }
        }
    }

    return 0;
}

